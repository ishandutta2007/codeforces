import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n  = sc.nextInt();
      int dig = 0;
      while(n>0){
         n=n/2;
         dig++;
      }
      System.out.println(dig);
   }
}