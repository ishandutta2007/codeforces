import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int sum=0;
      int n= sc.nextInt();
      int [] bayus = new int[n];
      for (int i=0;i<n;i++){
         bayus[i] = sc.nextInt();
         sum+=bayus[i];
      } 
      Arrays.sort(bayus);
      if(sum%2==1) System.out.println(sum);
      else {
         if(determineSmallestOdd(bayus) == -1)System.out.println(0);
         else System.out.println(sum-determineSmallestOdd(bayus));
      }
   }
   public static int determineSmallestOdd(int[] nums){
      for (int i=0;i<nums.length;i++){
         if(nums[i] %2==1) return nums[i];
      }
      return -1;
   }
   
}