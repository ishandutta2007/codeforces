import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int m = sc.nextInt();
      if(2*m>n && 2*n>m) {
      System.out.println((m+n)/3);
      }
      else System.out.println(Math.min(m,n));
   }
}