import java.util.Scanner;

public class clearthestring {
	static int [][] dp;
	static String s;
	public static void main(String[] args) {
		Scanner sc =new Scanner(System.in);
		int n = sc.nextInt();
		 s = sc.next();
		dp = new int[n][n];
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(i==j) {
					dp[i][j]=1;
				}
			}
		}
		
		for(int diff = 1;diff<n;diff++) {
			for(int i=0;i<n-diff;i++) {
				dp[i][i+diff] = determine(i,i+diff);
			}
		}
//		for(int i=0;i<n;i++) {
//			for(int j=0;j<n;j++) {
//				System.out.print(dp[i][j]);
//			}
//			System.out.println();
//		}
		System.out.println(dp[0][n-1]);
		
	}
	private static int determine(int i, int j) {
		// TODO Auto-generated method stub
		int min =Integer.MAX_VALUE;
		for(int a=j-1;a>=i;a--) {
			if(s.charAt(j)==s.charAt(a)) {
//				System.out.println(i + " " + j + " " + a);
				min = Math.min(min,dp[a+1][j-1]+dp[i][a]);
			}
		}
		return Math.min(min,1+dp[i][j-1]);
	}
}