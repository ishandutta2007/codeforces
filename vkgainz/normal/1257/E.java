import java.util.Scanner;

public class E {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int k1 = sc.nextInt();
		int k2 = sc.nextInt();
		int k3 = sc.nextInt();
		int n = k1+k2+k3;
		int [] color = new int[n];
		
		for(int i=0;i<k1;i++) {
			color[sc.nextInt()-1] = 1;
		}
		for(int i=0;i<k2;i++) {
			color[sc.nextInt()-1] = 2;
		}
		for(int i=0;i<k3;i++) {
			color[sc.nextInt()-1] = 3;
		}
		int [][] dp = new int[n][3];
		if(color[0]==1) {
			dp[0][0] = 1;
		}
		if(color[0]==2) {
			dp[0][1] = 1;
		}
		if(color[0] ==3) {
			dp[0][2] = 1;
		}
		dp[0][1] = Math.max(dp[0][0],dp[0][1]);
		dp[0][2] = Math.max(dp[0][2],dp[0][1]);
		for(int i=1;i<n;i++) {
			if(color[i]==1) {
				dp[i][0] = 1;
			}
			dp[i][0]+=dp[i-1][0];
		}
		for(int i=1;i<n;i++) {
			for(int j=1;j<=2;j++) {
				if(color[i]==(j+1)) {
					dp[i][j] = Math.max(dp[i][j-1],1+dp[i-1][j]);
				}
				else {
					dp[i][j] = Math.max(dp[i][j-1],dp[i-1][j]);
				}
			}
		}
		System.out.println(n-dp[n-1][2]);
	}
}