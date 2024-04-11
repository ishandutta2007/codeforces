import java.util.*;

public class GeorgeAnDAccomodation {
 public static void main(String[] args){
  Scanner sc = new Scanner(System.in);
  int n = sc.nextInt();
  int[][] in = new int[n][2];
  for(int i = 0; i < n; i++){
  in[i][0] = sc.nextInt();
  in[i][1] = sc.nextInt();
  }
  int count =0;
  for (int i=0;i<n;i++){
   if (in[i][1]-in[i][0] >=2){
    count++;
   }
  }
  System.out.println(count);
 }
}