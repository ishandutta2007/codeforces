import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc =new Scanner(System.in);
      int n = sc.nextInt();
      int k = sc.nextInt();
      int [] vals = new int[n];
      int [] times = new int[n];
      for(int i=0;i<n;i++){
         vals[i] = sc.nextInt();
      }
      for(int i=0;i<n;i++){
         times[i] = sc.nextInt();
      }
      int sum = 0;
      for(int i=0;i<n;i++){
         sum+=times[i]*vals[i];
      }
      int [] prefix = new int[n+1];
      for(int i=0;i<n;i++){
         if(times[i]==0){
            prefix[i+1]=prefix[i]+vals[i];
         }
         else{
            prefix[i+1]=prefix[i];
         }
      }
      // for(int i=0;i<n+1;i++){
      //    System.out.println(prefix[i]);
      // }
      int max = 0;
      for(int i=k;i<n+1;i++){
         max = Math.max(max,prefix[i]-prefix[i-k]);
      }
      System.out.println(max+sum);
   }
}