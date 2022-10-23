import java.io.*;
import java.util.*;

public class B {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt(), k = in.nextInt();
		final int MOD = (int) (1e9 + 7);
		int[][] dp = new int[k + 1][n + 1];
		dp[0][1] = 1;
		for (int i = 0; i < k; i++) {
			int[] prevDp = dp[i], newDp = dp[i + 1];
			for (int j = 0; j <= n; j++) {
				int val = prevDp[j];
				if (val == 0) {
					continue;
				}

				for (int t = j; t <= n; t += j) {
					if ((newDp[t] += val) >= MOD) {
						newDp[t] -= MOD;
					}
				}
			}
		}

		int ans = 0;
		for (int i = 0; i <= n; i++) {
			ans = (ans + dp[k][i]) % MOD;
		}
		out.println(ans);
	}

	void run() {
		try {
			in = new FastScanner();
			out = new PrintWriter(System.out);
			solve();
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		public String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(nextToken());
		}

		public long nextLong() {
			return Long.parseLong(nextToken());
		}

		public double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new B().run();
	}
}