/* May 14 2019
   5 Kg Load Cell HX711 Module Interface with Arduino Nano to measure weight in Kgs
   Arduino  pin  2 -> HX711 CLK 3 -> DOUT 5V -> VCC GND -> GND
*/

#include "HX711.h"  // HX711 library
#define DOUT  3
#define CLK  2

HX711 scale;

float calibration_factor = -576; // calibration depends on the loadcell
const int SW = 8;


void setup() {

 
  pinMode(SW, INPUT_PULLUP);
  
  scale.begin(DOUT, CLK); // start connection HX711
  scale.set_scale(-576); // todo => calibration factor for loadcell => strongly dependent on individual setup
  scale.tare(); // set back to zero
}

void loop() {
  
  int x = digitalRead(SW);
  if (x == LOW)

  {

    scale.tare();
  }
}
