import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
 
      String o = sc.next();
      String c = sc.next();
      // int o = Integer.parseInt(sc.next());
      // int c = Integer.parseInt(sc.next());
       int [] original = new int[o.length()];
      int [] compare = new int[c.length()];
      for(int i=0;i<original.length;i++){
         original[i] = Integer.parseInt(o.substring(i,i+1));
         
      }
      for(int i=0;i<compare.length;i++){
         compare[i] = Integer.parseInt(c.substring(i,i+1));
      }
      int sum =0;
      for(int i=0;i<n;i++){
         int a= Math.abs(compare[i]-original[i]);
         sum+=(Math.min(a,10-a));
      }
      System.out.println(sum);
   }
   public static int numDigits(int n){
      int count=0;
      while(n>0){
         n=n/10;
         count++;
      }
      return count;
   }
}