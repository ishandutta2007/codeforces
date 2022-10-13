import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int h = sc.nextInt();
      for (int i=1;i<=n-1;i++){
         double bayus = i/(1.0*n);
         double gayus = Math.sqrt(bayus);
         double anus = h*gayus;
         System.out.println(anus);
      }
   }
}