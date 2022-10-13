import java.util.*;
public class susbus{
   public static void main(String[] args){
     Scanner in = new Scanner (System.in);

    	    int a = in.nextInt();
    	       int b = in.nextInt();


    	       if(Math.floor(Math.hypot(a,b))==Math.hypot(a,b))
    	       	 System.out.print("black");

    	       	 else if(a*b>0){

    	       	 	double d=Math.hypot(a,b);

    	       	 	if(Math.floor(d)%2==1)
    	       	 		System.out.print("white");


    	       	 	else if(Math.floor(d)%2==0)
                     	System.out.print("black");

    	       	 }

    	       	 else if(a*b<0){

    	       	 		double d=Math.hypot(a,b);

    	       	 	if(Math.floor(d)%2==0)
    	       	 		System.out.print("white");


    	       	 	else if(Math.floor(d)%2==1)
                     	System.out.print("black");
      }
      }
   
}