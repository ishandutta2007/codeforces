import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int a = sc.nextInt();
      int x = sc.nextInt();
      int y = sc.nextInt();
      int end = interval(y,a);
      int beg = end-1;
      if(y>0 && y<2*a){
         if(x<=(a-1)/2 && x>=-(a-1)/2 && y != a)
         System.out.println(end);
         else 
         System.out.println(-1);
      }
      else if(end%2==0) // means theres only one block{
         if(x<a/2 && x>-a/2 && y<end*a && y>beg*a){
            System.out.println(3*end/2-1);
         }
         else {
            System.out.println(-1);
         }
      else {
         if(x<a && x>0 && y<end*a && y> beg*a){
            System.out.println(3*end/2);
         }
         else if(x>-a && x<0 && y<end*a && y>beg*a){
            System.out.println(3*end/2-1);
         }
         else {
            System.out.println(-1);
         }
      }   
    //failed on 2 0 2  
   }
   public static int interval(int y, int a){
      int result=0;
      while(a*result<y) result++;
      
      return result;
   }
}