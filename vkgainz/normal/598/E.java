import java.util.Scanner;

public class ChocolateBar {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int [][][] dp = new int[31][31][51];
		for(int i=0;i<31;i++) {
			for(int j=0;j<31;j++) {
				for(int k=1;k<51;k++) {
					dp[i][j][k] = (int) Math.pow(10,7);
				}
			}
		}
		for(int i=1;i<31;i++) {
			for(int j=1;j<31;j++) {
				for(int k=1;k<51;k++) {
					if(i*j == k) {
						dp[i][j][k] = 0;
					}
					int t1,t2=(int) Math.pow(10,7);
					for(int a=1;a<i;a++) {
						 t1 = j*j + dp[i-a][j][k];
						if(a*j<=k)
						 t2 = j*j+ dp[i-a][j][k-a*j];
						dp[i][j][k] =Math.min(t1,Math.min(dp[i][j][k],t2)) ;
					}
					for(int a=1;a<j;a++) {
						t1 = i*i + dp[i][j-a][k];
						if(a*i<=k) {
							t2 = i*i+dp[i][j-a][k-a*i];
						}
						dp[i][j][k] = Math.min(t1,Math.min(dp[i][j][k],t2));
					}
				}
			}
		}
		int t = sc.nextInt();

		for(int i=0;i<t;i++) {
			System.out.println(dp[sc.nextInt()][sc.nextInt()][sc.nextInt()]);
		}
	}
}