import java.util.Scanner;

public class garland {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int [] vals = new int[n];
		boolean [] seen = new boolean[n+1];
		for(int i=0;i<n;i++) {
			vals[i] = sc.nextInt();
			seen[vals[i]] = true;
		}
		int numOne =0;
		int numZero =0;
		for(int i=1;i<=n;i++) {
			if(!seen[i]) {
				if(i%2==0) {
					numZero++;
				}
				else {
					numOne++;
				}
			}

		}
		int [][][][] dp = new int[n+1][numZero+1][numOne+1][2];
		for(int j=0;j<numZero+1;j++) {
			for(int k=0;k<numOne+1;k++) {
				if(j!=0 || k!=0) {
					dp[0][j][k][0] = n+1;
					dp[0][j][k][1] = n+1;
				}
			}
		}
		for(int i=1;i<n+1;i++) {
			for(int j=0;j<numZero+1;j++) {
				for(int k=0;k<numOne+1;k++) {
					dp[i][j][k][0] = n+1;
					dp[i][j][k][1] = n+1;
					if(vals[i-1]>0) {
						if(vals[i-1]%2==0) {
							dp[i][j][k][0] = Math.min(dp[i][j][k][0],dp[i-1][j][k][0]);
							dp[i][j][k][0] = Math.min(dp[i][j][k][0],dp[i-1][j][k][1]+1);
						}
						else {
							dp[i][j][k][1] = Math.min(dp[i][j][k][1],dp[i-1][j][k][1]);
							dp[i][j][k][1] = Math.min(dp[i][j][k][1],dp[i-1][j][k][0]+1);
						}
					}
					else {
						if(j>=1) {
							dp[i][j][k][0] = Math.min(dp[i][j][k][0],Math.min(dp[i-1][j-1][k][1]+1,dp[i-1][j-1][k][0]));
						}
						if(k>=1) {
							dp[i][j][k][1] = Math.min(dp[i][j][k][1],Math.min(dp[i-1][j][k-1][1],dp[i-1][j][k-1][0]+1));
						}
					}
				}
			}
		}
		System.out.println(Math.min(dp[n][numZero][numOne][0],dp[n][numZero][numOne][1]));
	}
}