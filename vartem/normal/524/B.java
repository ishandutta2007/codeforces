import java.io.*;
import java.util.*;

public class B {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int[] w = new int[n], h = new int[n];
		for (int i = 0; i < n; i++) {
			w[i] = in.nextInt();
			h[i] = in.nextInt();
		}
		int[][] dp = new int[n + 1][2000];
		for (int[] i : dp) {
			Arrays.fill(i, Integer.MAX_VALUE);
		}

		dp[0][0] = 0;
		for (int i = 0; i < n; i++) {
			for (int curH = 0; curH < 2000; curH++) {
				if (dp[i][curH] == Integer.MAX_VALUE) {
					continue;
				}

				{
					int w1 = w[i], h1 = h[i];
					dp[i + 1][Math.max(curH, h1)] = Math.min(
							dp[i + 1][Math.max(curH, h1)], dp[i][curH] + w1);
				}
				{
					int w1 = h[i], h1 = w[i];
					dp[i + 1][Math.max(curH, h1)] = Math.min(
							dp[i + 1][Math.max(curH, h1)], dp[i][curH] + w1);
				}
			}
		}
		
		long ans = Long.MAX_VALUE;
		for (int i = 1; i < 2000; i++) {
			ans = Math.min(ans, 1L * i * dp[n][i]);
		}
		out.println(ans);
	}

	void run() {
		in = new FastScanner();
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new B().run();
	}
}