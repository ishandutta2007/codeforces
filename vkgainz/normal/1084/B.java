import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      long s=sc.nextLong();
      long sum=0;
      int [] drinks = new int[n];
      for(int i=0;i<n;i++){
         drinks[i]=sc.nextInt();
         sum+=drinks[i];
      }
      if(sum<s) {
         System.out.println(-1);
         return;
      }
//      System.out.println(sum);
      Arrays.sort(drinks);
      for(int i=0;i<n;i++){
         s-=drinks[n-i-1]-drinks[0];
         drinks[n-i-1]=drinks[0];
      }
      if(s<=0) {
         System.out.println(drinks[0]);
         return;
      }
//      System.out.println(s);
      System.out.println(makeEqual(drinks,s));
   }
   public static long makeEqual(int [] nums, long distribute){
      //precondition everything is equal
      long x = (long) (distribute-1)/nums.length+1;
      return nums[0]-x;
   }
}