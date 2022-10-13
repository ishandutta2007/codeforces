import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int a= sc.nextInt();
      int b = sc.nextInt();
      int c = sc.nextInt();
      int d = sc.nextInt();
      double p = a*1.0/b;
      double q = c*1.0/d;
      double bayus = p/(p+q-p*q);
      System.out.println(bayus);
   }
}