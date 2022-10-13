import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int [] balloons = new int[n];
      for(int i=0;i<n;i++){
         balloons[i] = sc.nextInt();
      }
      if(n==1) System.out.println(-1);
     else if(n==2 && balloons[0]==balloons[1]) System.out.println(-1);
      
      else {
         System.out.println(1);
         System.out.println(determineMin(balloons)+1);
      }
      
   }
   public static int determineMin(int [] nums){
      int pos = 0;
      for(int i=0;i<nums.length;i++) {
         if(nums[i]<nums[pos]) pos=i;
         }
      return pos;
   }
   
}