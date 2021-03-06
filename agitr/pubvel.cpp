// This program pub l ishes randomly−generated v e l o c i t y
// messages for tu r t les im .

#include <ros/ros.h>
#include <geometry_msgs/Twist.h> // For geometry_msgs : : Twi
#include <stdlib.h> // For rand() and RAND_MAX

int main ( int argc , char **argv ) {
// I n i t i a l i z e the ROS system and become a node .

ros :: init (argc,argv,"publish_velocity");
ros :: NodeHandle nh;

// Create a pub l ishe r ob jec t .
ros :: Publisher pub = nh.advertise <geometry_msgs::Twist >("turtle1/cmd_vel" , 1000) ;

// Seed the random number generator .

srand (time(0)); 

// Loop at 2Hz un t i l the node i s shut down .

ros :: Rate rate (2) ;
while(ros :: ok()) {
// Create and f i l l in the message . The other four
// f i e l d s , which are ignored by turt lesim , d e fau l t to 0
    geometry_msgs :: Twist msg ;
    msg.linear.x = double(rand())/double(RAND_MAX) ;
    msg.angular.z = 2*double(rand())/double(RAND_MAX)-1;

    // Pub lish the message .
    pub.publish(msg) ;// Send a message to rosout with the d e t a i l s .
    ROS_INFO_STREAM("Sending␣random␣velocity␣command : "
    << "␣linear=" << msg.linear.x
    << "␣angular=" << msg.angular.z) ;
    // Wait un t i l i t ' s time for another i t e ra t ion .
    rate.sleep ();
    }   
}
