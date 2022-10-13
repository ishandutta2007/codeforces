import java.util.Scanner;

public class checkout {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int [] c = new int[n];
		int [] t = new int[n];
		for(int i=0;i<n;i++) {
			t[i] = sc.nextInt()+1;
			c[i] = sc.nextInt();
		}
		long [][] dp = new long[n+1][2001];
		for(int i=0;i<n+1;i++) {
			for(int j=0;j<2001;j++) {
				dp[i][j] = (long) Math.pow(10,13);
			}
		}
		dp[0][0] = 0;
		for(int i=1;i<n+1;i++) {
			dp[i][0] = 0;
		}
		
		for(int i=1;i<n+1;i++) {
			for(int j=1;j<2001;j++) {
				
				
					dp[i][j] = Math.min(dp[i-1][Math.max(j-t[i-1],0)]+c[i-1],dp[i-1][j]);
				
			}
		}
//		for(int i=0;i<n+1;i++) {
//			for(int j=0;j<10;j++) {
//				System.out.print(dp[i][j] + " ");
//			}
//			System.out.println();
//		}
		System.out.println(dp[n][n]);
		
	}
}