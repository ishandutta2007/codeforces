import java.util.*;

public class susbus{
 public static void main(String[] args){
  Scanner sc = new Scanner(System.in);
  int n = sc.nextInt();
  int[][] in = new int[n][3];
  for(int i = 0; i < n; i++){
  in[i][0] = sc.nextInt();
  in[i][1] = sc.nextInt();
  in[i][2] = sc.nextInt();
  }
  int sumx=0;
  for (int i=0;i<n;i++){
   sumx+=in[i][0];
  }
  int sumy=0;
  for (int i=0;i<n;i++){
   sumy+=in[i][1];
  }
  int sumz=0;
  for (int i=0;i<n;i++){
   sumz+=in[i][2];
  }
  if (sumx==0 && sumy==0 && sumz==0) {
	  System.out.println("YES");
  }
  else {
	  System.out.println("NO");
  }
  
  
 }
}