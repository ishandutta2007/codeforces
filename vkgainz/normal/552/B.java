import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      long n = sc.nextLong();
      long k=n;
      int numDigit = 0;
      while(k>0){
         k=k/10;
         numDigit++;
      }
      long sum=0;
      for (int i=0;i<numDigit-1;i++){
         sum+=(long) (i+1)*Math.pow(10,i)*9;
      }
      sum+=(long) (n-Math.pow(10,numDigit-1)+1)*(numDigit);
      System.out.println(sum);
   }
}