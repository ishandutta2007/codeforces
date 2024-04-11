import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int x = sc.nextInt();
      int y = sc.nextInt();
      int a = sc.nextInt();
      int b = sc.nextInt();
      int lcmxy = x*y/gcd(x,y);
      int s = b/lcmxy;
      int t = (a-1)/lcmxy;
      System.out.println(s-t);
   }
   public static int gcd(int x, int y){
      int result=0;
      for (int i=1;i<=Math.min(x,y);i++){
         if(x%i==0 && y%i==0){
            result=i;
         }
      }
      return result;
   }
}