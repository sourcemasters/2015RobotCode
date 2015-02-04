// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "Chassis.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "../Commands/DriveWithJoysticks.h"
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

#include <iostream>

Chassis::Chassis() : Subsystem("Chassis") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	m_leftMotor = RobotMap::chassisleftMotor;
	m_rightMotor = RobotMap::chassisrightMotor;

	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	drive = new RobotDrive(m_leftMotor, m_rightMotor);
	drive->SetSafetyEnabled(false);
	drive->SetExpiration(0.1);
	drive->SetSensitivity(0.5);
	drive->SetMaxOutput(1.0);
}

Chassis::~Chassis() {
	if(m_leftMotor) {delete(m_leftMotor);}
	if(m_rightMotor) {delete(m_rightMotor);}
	if(drive) {delete(drive);}
}

void Chassis::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new DriveWithJoysticks());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void Chassis::tankDrive(float leftValue, float rightValue) {
	if(TESTERBOT)
	{
		std::cout << "L: " << leftValue << " R: " << rightValue << std::endl;
		drive->TankDrive(-leftValue, -rightValue);
	} else {
		drive->TankDrive(leftValue, rightValue);
	}
}
