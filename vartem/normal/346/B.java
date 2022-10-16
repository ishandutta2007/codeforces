import java.io.*;
import java.util.*;

public class B {

	FastScanner in;
	PrintWriter out;

	void solve() {
		char[] s = in.nextToken().toCharArray(), t = in.nextToken()
				.toCharArray();
		String virus = in.nextToken();

		int[][] next = prefix(virus);

		int n = s.length, m = t.length, k = virus.length();
		int[][][] dp = new int[n + 1][m + 1][k];
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				Arrays.fill(dp[i][j], -1);
			}
		}

		int[][][] prev1 = new int[n + 1][m + 1][k + 1], prev2 = new int[n + 1][m + 1][k + 1], prev3 = new int[n + 1][m + 1][k + 1];

		for (int i = 0; i <= n; i++) {
			dp[i][0][0] = 0;
		}

		for (int j = 0; j <= m; j++) {
			dp[0][j][0] = 0;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int p = 0; p < k; p++) {
					
					if (dp[i][j][p] == -1) {
						continue;
					}
					int val = dp[i][j][p];
					
					
					if (dp[i + 1][j][p] < val) {
						dp[i + 1][j][p] = val;
						prev1[i + 1][j][p] = i;
						prev2[i + 1][j][p] = j;
						prev3[i + 1][j][p] = p;
					}

					if (dp[i][j + 1][p] < val) {
						dp[i][j + 1][p] = val;
						prev1[i][j + 1][p] = i;
						prev2[i][j + 1][p] = j;
						prev3[i][j + 1][p] = p;
					}

					if (s[i] == t[j]) {
						int code = s[i] - 'A';
						int nextP = next[code][p];
						if (nextP != k && dp[i + 1][j + 1][nextP] < val + 1) {
							dp[i + 1][j + 1][nextP] = val + 1;
							prev1[i + 1][j + 1][nextP] = i;
							prev2[i + 1][j + 1][nextP] = j;
							prev3[i + 1][j + 1][nextP] = p;
						}
					}
				}
			}
		}

		StringBuilder sb = new StringBuilder();
		int max = 0;
		int curI = 0, curJ = 0, curP = 0;

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				for (int p = 0; p < k; p++) {
					if (dp[i][j][p] > max) {
						max = dp[i][j][p];
						curI = i;
						curJ = j;
						curP= p;
					}
				}
			}
		}
		
		if (max == 0) {
			out.println(0);
			return;
		}
		
		while (max > 0) {
			int prevI = prev1[curI][curJ][curP];
			int prevJ = prev2[curI][curJ][curP];
			int prevP = prev3[curI][curJ][curP];

			if (Math.abs(curI - prevI) + Math.abs(curJ - prevJ) == 1) {
			} else {
				char c = s[curI - 1];
				sb.append(c);
				max--;
			}
			curI = prevI;
			curJ = prevJ;
			curP = prevP;
		}

		out.println(sb.reverse().toString());
	}

	private int[][] prefix(String s) {
		int n = s.length();
		int[] p = new int[n];
		for (int i = 1; i < n; i++) {
			int k = p[i - 1];
			while (k > 0 && (s.charAt(k) != s.charAt(i))) {
				k = p[k - 1];
			}
			if (s.charAt(k) == s.charAt(i)) {
				k++;
			}
			p[i] = k;
		}
		int[][] next = new int[26][n];
		for (int i = 0; i < 26; i++) {
			char c = (char) ('A' + i);

			if (c == s.charAt(0)) {
				next[i][0] = 1;
			} else {
				next[i][0] = 0;
			}

			for (int j = 1; j < n; j++) {
				if (s.charAt(j) == c) {
					next[i][j] = j + 1;
				} else {
					next[i][j] = next[i][p[j - 1]];
				}
			}
		}
		return next;
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

		String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
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