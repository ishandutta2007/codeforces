import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      long n = sc.nextLong();
      String s = String.valueOf(n);
//      System.out.println(s);
      long a = largestnine(n);
      long b = n-a;
//     System.out.println(a + " " + b);
      System.out.println(sumDigits(a)+sumDigits(b));
   }
   public static long largestnine(long n){
      int count=0;
      while((Math.pow(10,count+1)-1)<=n) count++;
      return (long) (Math.pow(10,count)-1);
   }
   public static int sumDigits(long n){
      String s=  String.valueOf(n);
      int sum=0;
      for(int i=0;i<s.length();i++){
         sum+=Integer.parseInt(s.substring(i, i+1));
      }
      return sum;
   }
}