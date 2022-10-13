import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n=sc.nextInt();
      int m = sc.nextInt();
      int a = sc.nextInt();
      int b = sc.nextInt();
      int num = (n)/m;
      if(b*1.0/m<=a)
      System.out.println(Math.min(num*b+n%m*a,(num+1)*b));
      else
      System.out.println(n*a);
   }
}