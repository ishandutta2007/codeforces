import java.util.Scanner;

public class barcode {
	static int[][][] dp;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int x = sc.nextInt();
		int y = sc.nextInt();
		int [][] grid = new int[n][m];
		for(int i=0;i<n;i++) {
			String s = sc.next();
			for(int j=0;j<m;j++) {
				if(s.charAt(j)==('#'))
				grid[i][j] =1;
			}
		}
		
		int[] a = new int[m];
		for(int j=0;j<m;j++) {
			for(int i=0;i<n;i++) {
				a[j] += grid[i][j];
			}
		}
		int [] b = new int[m];
		for(int i=0;i<m;i++) {
			b[i] = n-a[i];
		}
		int [] ap = new int[m+1];
		int [] bp = new int[m+1];
		for(int i=1;i<m+1;i++) {
			ap[i] = ap[i-1]+a[i-1];
			bp[i] = bp[i-1]+b[i-1];
		}
		State[] dp = new State[m];
		for(int i=0;i<m;i++) {
			dp[i] = new State((int) Math.pow(10,7),(int) Math.pow(10,7));
		}
		for(int i=x-1;i<Math.min(y,m);i++) {
			dp[i] = new State(ap[i+1],bp[i+1]);
		}
		for(int i=x;i<m;i++) {
			for(int j=i-y+1;j<=i-x+1;j++) {
				if(j>=1) {
					int nextb = dp[j-1].a+bp[i+1]-bp[j];
					int nexta = dp[j-1].b+ap[i+1]-ap[j];
					dp[i] = new State(Math.min(dp[i].a,nexta),Math.min(dp[i].b,nextb));
				}
			}
		}
//		for(int i=0;i<m;i++) {
//			System.out.println(dp[i].a + " " + dp[i].b);
//		}
		System.out.println(Math.min(dp[m-1].a,dp[m-1].b));
	}
	static class State{
		int a;
		int b;
		public State(int x,int y) {
			a=x;
			b=y;
		}
	}
}