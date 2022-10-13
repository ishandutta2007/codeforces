import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      long p = n*n*6-6*n+1;
      System.out.println(p);
   }
}