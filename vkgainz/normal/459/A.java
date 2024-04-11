import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc= new Scanner(System.in);
      int x1=sc.nextInt();
      int y1=sc.nextInt();
      int x2=sc.nextInt();
      int y2=sc.nextInt();
      if((x1 != x2 && y1 != y2) && Math.abs(x2-x1) == Math.abs(y2-y1)) {
         System.out.println(x2);
         System.out.println(y1);
         System.out.println(x1);
         System.out.println(y2);
      }
      else if(y1==y2) {
         System.out.println(x1);
         System.out.println(y1+x2-x1);
         System.out.println(x2);
         System.out.println(y2+x2-x1);
         
      }
      else if(x1==x2) {
         System.out.println(x1+y2-y1);
         System.out.println(y1);
         System.out.println(x2+y2-y1);
         System.out.println(y2);
      }
      else {
         System.out.println(-1);
      }
   }
   
}