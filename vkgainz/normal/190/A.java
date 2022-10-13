import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int m = sc.nextInt();
      if(n==0 && m!=0) System.out.println("Impossible");
      
      else {
         System.out.println(n+m-Math.min(m,n));
         System.out.println(m+n-Math.min(1,m));
      }
   }
}