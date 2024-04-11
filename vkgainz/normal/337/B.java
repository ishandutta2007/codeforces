import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int a = sc.nextInt();
      int b = sc.nextInt();
      int c = sc.nextInt();
      int d = sc.nextInt();
      int x = Math.abs(a*d-b*c);
      int y = Math.max(a*d,b*c);
      int z = gcd(x,y);
      int newx = x/z;
      int newy = y/z;
      if(x==0) System.out.println(""+0+"/"+1);
      else {
      System.out.println(""+newx+"/"+newy);
      }
   }
   public static int gcd(int x,int y){
      for (int i=Math.min(x,y);i>0;i--){
         if(x%i==0 && y%i==0) return i;
      }
      return 1;
   }
   
}