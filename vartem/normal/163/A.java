import java.io.*;
import java.util.*;

public class Test {

	final String filename = new String("Test").toLowerCase();

	final int mod = 1000 * 1000 * 1000 + 7;
	
	void solve() throws Exception {
		String s1 = nextToken();
		String s2 = nextToken();
		int n = s1.length();
		int m = s2.length();
		int[][] dp = new int[n + 1][m + 1];
		dp[0][0] = 0;
		long ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
					dp[i][j] = 1 + dp[i - 1][j - 1];
				}
				dp[i][j] += dp[i][j - 1];
				dp[i][j] %= mod;
			}
		}
		for (int i = 0; i <= n; i++) {
			ans += dp[i][m];
			ans %= mod;
		}
		out.println(ans);
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			//			in = new BufferedReader(new FileReader("input.txt"));
			//			out = new PrintWriter("output.txt");

			solve();

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	BufferedReader in;
	StringTokenizer st;
	PrintWriter out;

	String nextToken() throws Exception {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}

	public static void main(String[] args) {
		new Test().run();
	}

}