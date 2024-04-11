import java.util.*;

public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n=sc.nextInt();
      int[] bayus = new int[n];
      for (int i=0;i<n;i++) bayus[i]= sc.nextInt();
      boolean isArithmetic=true;
      for (int i=0;i<n-1;i++) {
    	  if(bayus[i+1]-bayus[i] != bayus[1]-bayus[0]) {
    		  isArithmetic=false;
      break;
    	  }
    	  else isArithmetic=true;
      }
      if(isArithmetic) System.out.println(bayus[n-1]+bayus[1]-bayus[0]);
      else System.out.println(bayus[n-1]);
      
   }
   
}