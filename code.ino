#include <Wire.h>
#include <Adafruit_ADS1015.h>

// Create an instance of the ADC
Adafruit_ADS1115 ads;  // Use this for the ADS1115

// Define the sensor's input channel on the ADC
const int heartRateSensorChannel = 0;  // Analog input A0

void setup(void) {
  Serial.begin(9600);
  Serial.println("Heart Rate Sensor Test");

  // Initialize the ADC
  ads.begin();

  Serial.println("ADC initialized");
}

void loop(void) {
  // Read the raw analog value from the sensor
  int16_t rawValue = ads.readADC_SingleEnded(heartRateSensorChannel);

  // Print the raw analog value to the Serial monitor
  Serial.print("Raw Value: ");
  Serial.println(rawValue);

  // Calculate heart rate based on the raw value (adjust the calculation based on your sensor's characteristics)
  int heartRate = map(rawValue, 0, 1023, 40, 220);  // Assuming 0-1023 raw range corresponds to 40-220 bpm range

  // Print the calculated heart rate to the Serial monitor
  Serial.print("Heart Rate: ");
  Serial.print(heartRate);
  Serial.println(" bpm");

  delay(1000); // Delay for stability
}
