import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int[] xcor = new int[n];
      int []ycor = new int[n];
      int [][] bayus = new int[n][2];
      for (int i=0;i<n;i++){
         bayus[i][0] = sc.nextInt();
         xcor[i] = bayus[i][0];
         bayus[i][1] = sc.nextInt();
         ycor[i] = bayus[i][1];
      }
      Arrays.sort(xcor);
      Arrays.sort(ycor);
      long k = Math.max((ycor[n-1]-ycor[0]),(xcor[n-1]-xcor[0]));
      System.out.println(k*k);
      //sidjoiasdj
   }
}