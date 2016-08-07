//created by SAYANTIKA BANIK
//team=HACKDEVS
//socioHack
//hackerearth
/*the hack facilitates the terrain transportation ,espicailly the hair pin bends
 * Libraries used
 * <LiquidCrystal.h>
 * funtions used- pulseIn() 
 *                lcd.setCursor ()
 * components used- Arduino mega/uno               
 *                  Ultrasonic Sensor
 *                  LCD pannels to display
 *                   
 */
 
 



#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
# define trigpin 8
# define echopin 7

void setup() 
{
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  Serial.begin(9600);
  Serial.println("LCD test with PWM contrast adjustment");
  pinMode(13,OUTPUT);
  //analogWrite(6,Contrast);
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("ALERT!");
}

void loop() 
{
  
   double duration,distance,val;
   digitalWrite(13,LOW);
   delay(1000);
   digitalWrite(13,HIGH);
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  
  delay(1000);
  digitalWrite(trigpin,LOW);
  delayMicroseconds(3);
  digitalWrite(trigpin,HIGH);
   delayMicroseconds(1);
 
  duration=pulseIn(echopin,HIGH, 50000);
  distance=(duration*.034)/2; //distance in cms
  lcd.setCursor(0, 2);
 lcd.print(distance);
//to display the duration
 lcd.setCursor(9,2);
 lcd.print(duration);
  Serial.println(distance);
  //to disp. distance on to the serial monitor
  Serial.println(duration);
  //to disp. duration on to the serial monitor
if (duration>185&&duration<350){
  Serial.println("BREAK!");
  delay(100);
}
  else
  { 
  Serial.println ("SAFE");
  delay(100);
  }
}
 






