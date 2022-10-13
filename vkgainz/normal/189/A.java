import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int a = sc.nextInt();
      int b=sc.nextInt();
      int c = sc.nextInt();
      int pieces=0;
      for (int i=0;i*a<=n;i++){
         for (int j=0;j*b+i*a<=n;j++){
            int k=(n-i*a-j*b)/c;
            if(i*a+j*b+k*c==n)
            pieces=Math.max(i+j+k,pieces);
         }
         
      }
      System.out.println(pieces);
      
      
   }
}