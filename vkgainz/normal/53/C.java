import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      for (int i=1;i<=n;i++){
         if(i%2==1) System.out.println((i+1)/2);
         else System.out.println(n+1-i/2);
      }
   }
}