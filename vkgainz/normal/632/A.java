import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int p = sc.nextInt();
      String [] nibbas = new String[n];
      for (int i=0;i<n;i++) nibbas[i] = sc.next();
      String [] chibbas =new String[n];
      for (int i=0;i<n;i++) chibbas[i] = nibbas[n-i-1];
      
      long numApples =0;
      long price=0;
      for (int i=0;i<n;i++){
         if(chibbas[i].charAt(chibbas[i].length()-1) == 's') {
            numApples=numApples*2+1;
            price-=p/2;
         }
         else numApples*=2;
      }
      price+=numApples*p;
      System.out.println(price);
   }
}