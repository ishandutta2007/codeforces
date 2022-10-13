import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int[] bayus = new int[n];
      for (int i=0;i<n;i++) bayus[i] = sc.nextInt();
      
      int count=0;
      for (int i=0;i<n;i++){
         if(bayus[i] == 0) count++;
      }
      if(count>=n) System.out.println("EASY");
      
      else System.out.println("HARD");
   }
}