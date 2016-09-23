#include "Arduino.h"

const int LED_PINS[5] = { 9, 10, 11, 12, 13 };
int LED_STATE[5] = { LOW, LOW, LOW, LOW, LOW };
const int INCREMENT_BUTTON = 3;
const int DECREMENT_BUTTON = 2;

void LedWrite() { // Writes the array LED_STATE to the pins.
	for (int i = 0; i < sizeof(LED_PINS) / sizeof(int); ++i) {
		digitalWrite(LED_PINS[i], LED_STATE[i]);
	}
}

void Setup() {
  init();
  // serial monitor
  Serial.begin(9600);

  for (int i = 0; i < sizeof(LED_PINS)/sizeof(int); ++i) { // Sets pins to OUTPUT mode.
    pinMode(LED_PINS[i], OUTPUT);
  }

  LedWrite(); // Calls LedWrite function.

  // button setup
  pinMode(INCREMENT_BUTTON, INPUT_PULLUP);
  pinMode(DECREMENT_BUTTON, INPUT_PULLUP);
}

 // ButtonPressed function
bool ButtonPressed(int button_pin) {
  return digitalRead(button_pin) == LOW;
}


int main() {
	Setup();


	while (true) {
		if (ButtonPressed(INCREMENT_BUTTON)) { // What happens when we press the upper button
			delay(300);
			for (int i = 0; i < sizeof(LED_PINS) / sizeof(int); ++i) { // Checks if an LED is LOW and if so sets is to HIGH then breaks.
				if (LED_STATE[i] == LOW) {
					LED_STATE[i] = HIGH;
					break;
				}
				else { // State is HIGH and so sets is to LOW then breaks.
					LED_STATE[i] = LOW;
				}
			}
		LedWrite();
		}
		if (ButtonPressed(DECREMENT_BUTTON)) { // What happens when we press the lower button
			delay(300);
			for (int i = 0; i < sizeof(LED_PINS) / sizeof(int); ++i) { // Checks if an LED is HIGH and if so sets is to LOW then breaks.
				if (LED_STATE[i] == HIGH) {
					LED_STATE[i] = LOW;
					break;
				}
				else { // State is LOW and so sets is to HIGH then breaks.
					LED_STATE[i] = HIGH;
				}
			}
		LedWrite();  // Calls LedWrite function.
		}
	}

	return 0;
}
