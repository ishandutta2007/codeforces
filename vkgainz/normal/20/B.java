import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      long a = sc.nextLong();
      long b = sc.nextLong();
      long c = sc.nextLong();
      if(a==0 && b==0 && c==0){
         System.out.println(-1);
      }
      else if(a==0 && b==0){

         System.out.println(0);
      }
      else if(a==0){
         System.out.println(1);
      System.out.println(-c*1.0/b);
      }
      else{
         
         if(b*b-4*a*c>0){
            double asdf =Math.sqrt(b*b-4*a*c);
            double sol1 = (-b+asdf)*1.0/(2*a);
            double sol2 = (-b-asdf)*1.0/(2*a);
            System.out.println(2);
            System.out.println(Math.min(sol1,sol2));
            System.out.println(Math.max(sol1,sol2));
         }
         if(b*b-4*a*c==0){
            double sol1 = -b*1.0/(2*a);
            System.out.println(1);
            System.out.println(sol1);
            
         }
         if(b*b-4*a*c<0) {
            System.out.println(0);
         }
      }
   }
}