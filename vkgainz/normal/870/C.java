import java.util.*;
public class susbus{
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      for(int i=0;i<n;i++){
         int a = sc.nextInt();
         if(a<4) System.out.println(-1);
         else if(a%2==0) {
            System.out.println(a/4);
         }
         else {
            if(a==9){
               System.out.println(1);
            }
            else if(a<13) {
               System.out.println(-1);
            }
            else {
               System.out.println(1+(a-9)/4);
            }
         }
      }
      
   }
}