import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      long n = sc.nextLong();
      if(n%2==1){
         //n-i
         System.out.println((n-smallestOddPrime(n)+2)/2);
      }
      else {
         System.out.println(n/2);
      }
   }
   public static long smallestOddPrime(long n){
      for (long i=3;i<=Math.sqrt(n);i+=2){
         if(n%i==0) return i;
      }
      return n;
   }
}