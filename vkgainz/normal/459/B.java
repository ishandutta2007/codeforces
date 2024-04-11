import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc= new Scanner(System.in);
      int n = sc.nextInt();
      int [] bayus = new int[n];
      for (int i=0;i<n;i++) {
      bayus[i]=sc.nextInt();
      }
      Arrays.sort(bayus);
      if(bayus[n-1] !=bayus[0]) {
      System.out.println(bayus[n-1]-bayus[0]);
      System.out.println(numOccur(bayus,bayus[0])*numOccur(bayus,bayus[bayus.length-1]));
      }
      else {
         System.out.println(0);
         System.out.println(numOccur(bayus,bayus[0])*(numOccur(bayus,bayus[0])-1)/2);
      }
   }
   public static long numOccur(int[] nums, int n){
      int count=0;
      for (int i=0;i<nums.length;i++){
         if(nums[i]==n) {
            count++;
         }
         
      }
      return count;
   }
}