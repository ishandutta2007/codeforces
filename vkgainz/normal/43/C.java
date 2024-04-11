import java.util.*;
public class susbus{
   public static void main(String[] args) {
      Scanner sc =new Scanner(System.in);
      int t=sc.nextInt();
      int one=0;
      int two=0;
      int zero=0;
      for(int i=0;i<t;i++){
         int n = sc.nextInt();
         if(n%3==0) {
            zero++;
         }
         else if(n%3==1) {
            one++;
         }
         else {
            two++;
         }
      }
      System.out.println(Math.min(two,one)+zero/2);
   }
}