import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      boolean asdf = false;
      int x = n/1234567;
      int y = n/123456;

      for (int i=0;i<=x;i++){
         for (int j=0;j<=y;j++){
            int z = n-(i*1234567)-(j*123456);
            if(z>=0 && z%1234==0) {
               asdf=true;
               break;
            }
         }
      }
      if(asdf) System.out.println("YES");
      
      else System.out.println("NO");
   }
}