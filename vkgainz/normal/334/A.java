import java.util.*;

public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int[][] bayus = new int[n][n];
      for (int r=0;r<n;r++){
         for (int l=0;l<n;l++){
            if(l%2==1)
            bayus[r][l]=l*n+1+r;
            else 
            bayus[r][l]=(l+1)*n-r;
         }
      }
      for (int r=0;r<n;r++){
         for (int l=0;l<n;l++)
         System.out.println(bayus[r][l]);
      }
   }
}