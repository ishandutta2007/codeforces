import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int m=sc.nextInt();
      int [] benches = new int[n];
      for(int i=0;i<n;i++) benches[i] = sc.nextInt();
      Arrays.sort(benches);
      int maxNum = benches[benches.length-1]+m;
      
      
      
      // for(int i=0;i<n;i++) System.out.println(benches[i]);
      
     int max = benches[benches.length-1];
      for(int i=0;i<benches.length;i++){
         m+=benches[i]-max;
      }
      // System.out.println(m);
    changeArray(benches);

      int minNum=benches.length;
      if(m<=0) {
        minNum = benches[benches.length-1];
      }
      else {
         minNum = detMin(benches,m);
      }
      System.out.println(minNum + " " + maxNum);
   }
   public static int changeM(int m,int [] nums){
      int max = nums[nums.length-1];
      for(int i=0;i<nums.length;i++){
         m+=nums[i]-max;
      }
      return m;
   }
   public static int[] changeArray(int[] nums){
      int max = nums[nums.length-1];
      for(int i=0;i<nums.length;i++){
         nums[i]=max;
         // m-=max-nums[i];
      }
      return nums;
   }
   public static int detMin(int [] nums, int k) {
      int num = nums[0];
      num+=(k-1)/nums.length+1;
      return num;
      
   }//k>0
}