import java.util.Scanner;

public class zuma {
	public static void main(String [] args) {
		Scanner sc =new Scanner(System.in);
		int n = sc.nextInt();
		int [] vals = new int[n];
		for(int i=0;i<n;i++) {
			vals[i] = sc.nextInt();
		}
		int [][] dp = new int[n+1][n+1];
		for(int i=1;i<=n;i++) {
			dp[i][i] = 1;
			
		}
		for(int i=1;i<=n-1;i++) {
			dp[i][i+1] = 2;
			if(vals[i-1]==vals[i]) {
				dp[i][i+1]--;
			}
		}
		for(int len=3;len<=n;len++) {
			for(int i=1;i<=n-len+1;i++) {
				int j=i+len-1;
				dp[i][j] = n;
				if(vals[i-1]==vals[j-1]) {
					dp[i][j] = dp[i+1][j-1];
				}
				for(int k=j;k>i;k--) {
					if(vals[k-1]==vals[j-1]) {
						dp[i][j] = Math.min(dp[i][j],dp[k][j]+dp[i][k-1]);
					}
				}
				
				
			}
		}
//		for(int i=1;i<n+1;i++) {
//			for(int j=1;j<n+1;j++) {
//				System.out.print(dp[i][j] + " ");
//			}
//			System.out.println();
//		}
		System.out.println(dp[1][n]);
		
	}
}