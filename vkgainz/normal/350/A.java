import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int m = sc.nextInt();
      int[] bayus = new int[n];
      for (int i=0;i<n;i++){
         bayus[i] = sc.nextInt();
         
      }
      int[] gayus = new int[m];
      for (int i=0;i<m;i++){
         gayus[i] = sc.nextInt();
      }
      Arrays.sort(bayus);
      Arrays.sort(gayus);
      int k = Math.max(2*bayus[0],bayus[n-1]);
      if(k>=gayus[0]) System.out.println(-1);
      else System.out.println(k);
   }
}