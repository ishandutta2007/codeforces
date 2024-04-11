import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      if(n==5) System.out.println(1);
      else{
      if(n%3==2) System.out.println(3);
      else
      System.out.println((n+1)%3);
      }
   }
}