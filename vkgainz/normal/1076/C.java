import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int [] cases  = new int[n];
      for(int i=0;i<n;i++) cases[i] = sc.nextInt();
      for(int i=0;i<n;i++){
         int d = cases[i];
         if(d==0 || d>3) {
         double add = (d+Math.sqrt(d*d-4*d))/2;
         double sub = (d-Math.sqrt(d*d-4*d))/2;
         System.out.println("Y" + " "+add + " "+sub);
         }
         else System.out.println("N");
      }
   }
}