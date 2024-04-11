import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      for(int i=1;i<=n;i++){
         for(int j=i;j<=n;j++){
            if(j%i==0 && j*i>n){
               System.out.println(j + " " +i);
               return;
            }
         }
      }
      System.out.println(-1);
   }
}