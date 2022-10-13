import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n= sc.nextInt();
      int b = sc.nextInt();
      int [] bayus = new int[n];
      int sum=0;
      for (int i=0;i<n;i++) {
         bayus[i] = sc.nextInt();
         sum+=bayus[i];
      }
      if((sum+b)/n < detMax(bayus)) System.out.println(-1);
      
      else{
         for (int i=0;i<n;i++){
            System.out.println((sum+b)*1.0/n-bayus[i]);
         }
      }
      
   }
   public static int detMax(int [] nums){
      int max=0;
      for (int i=0;i<nums.length;i++){
         max=Math.max(nums[i],max);
      }
      return max;
   }
   
}