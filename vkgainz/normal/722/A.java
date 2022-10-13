import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      String s = sc.next();
      String a = s.substring(0,1);
      String b = s.substring(1,2);
      String c = s.substring(3,4);
      String d = s.substring(4);
      int w = Integer.parseInt(a);
      int x = Integer.parseInt(b);
      int y = Integer.parseInt(c);
      int z = Integer.parseInt(d);
      
      int sum=0;
      if(n==12){
         if(10*w+x>12 && x != 0){
            w=0;
         }
         else if(10*w+x==0){
            w=1;
         }
         else if(10*w+x>12 && x==0) w=1;
         
         if(10*y+z>59) y=3;
      }
      else if(n==24){
         if(10*w+x>23) w=1;
         
         if(10*y+z>59) y=3;
      
      }
      System.out.println(""+w+x+":"+y+z);

   }
}