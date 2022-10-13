
import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc= new Scanner(System.in);
      int n= sc.nextInt();
      int [] chess =new int[n/2];
      for(int i=0;i<n/2;i++) chess[i] = sc.nextInt();
      Arrays.sort(chess);
      int oSum=0;
      int eSum=0;
      for(int i=0;i<n/2;i++){
         eSum+=Math.abs(2*(i+1)-chess[i]);
         oSum+=Math.abs((2*i+1)-chess[i]);
      }
      // System.out.println(eSum);
      // System.out.println(oSum);
      System.out.println(Math.min(eSum,oSum));
   }
}