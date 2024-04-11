import java.util.*;
public class susbus{
   private static int[] sticks;
   public static void main(String[] args){
      Scanner sc =new Scanner(System.in);
      int n = sc.nextInt();
      sticks = new int[n];
      for(int i=0;i<n;i++){
         sticks[i] = sc.nextInt();
      }
      Arrays.sort(sticks);
      int min=300000;
      int index=0;
      for(int t=1;t<=100;t++){
         if(numChange(t)<min){
            min = numChange(t);
            index=t;
         }
      }
      System.out.println(index + " " + min);
   }
   public static int numChange(int t){
      int count=0;
      for(int i=0;i<sticks.length;i++){
         if(sticks[i]<t){
            count+=t-1-sticks[i];
         }
         else if(sticks[i]==t){
            continue;
         }
         else {
            count+=sticks[i]-t-1;
         }
      }
      return count;
   }
}