import java.util.*;
import java.io.*;

public class D {

	int MOD = 1_000_000_007;

	void solve() {
		int initN = in.nextInt();

		String s = in.nextToken();
		String t = "";
		for (int i = 0; i < s.length(); i++) {
			if (i == 0 || s.charAt(i) != s.charAt(i - 1)) {
				t += s.charAt(i);
			}
		}
		s = t;
		int n = s.length();

		int[] last = new int[26];
		Arrays.fill(last, -1);
		int[] prev = new int[n];
		for (int i = 0; i < n; i++) {
			prev[i] = last[s.charAt(i) - 'a'];
			last[s.charAt(i) - 'a'] = i;
		}

		int[][] dp = new int[n + 1][n + 1];
		int[] sum = new int[n + 1];
		dp[0][0] = 1;
		sum[0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= n; j++) {
				if (prev[i] != -1) {
					dp[i + 1][j] = sum[j - 1] - dp[prev[i] + 1][j - 1];
					if (dp[i + 1][j] < 0) {
						dp[i + 1][j] += MOD;
					}
				} else {
					dp[i + 1][j] = sum[j - 1];
				}
			}

			for (int j = 0; j <= n; j++) {
				if (prev[i] != -1) {
					sum[j] += dp[i + 1][j] - dp[prev[i] + 1][j];
					if (sum[j] >= MOD) {
						sum[j] -= MOD;
					}
					if (sum[j] < 0) {
						sum[j] += MOD;
					}
				} else {
					sum[j] += dp[i + 1][j];
					if (sum[j] >= MOD) {
						sum[j] -= MOD;
					}
				}
			}
		}

		int[] choose = new int[initN + 1];
		int[] tmp = new int[initN + 1];
		choose[0] = 1;
		for (int i = 1; i < initN; i++) {
			tmp[0] = 1;
			for (int j = 1; j <= i; j++) {
				tmp[j] = choose[j - 1] + choose[j];
				if (tmp[j] >= MOD) {
					tmp[j] -= MOD;
				}
			}
			System.arraycopy(tmp, 0, choose, 0, choose.length);
		}

		long result = 0;
		for (int cnt = 1; cnt <= n; cnt++) {
			result += 1L * sum[cnt] * choose[cnt - 1] % MOD;
			// choose (initN - 1, cnt - 1)

		}
		out.println(result % MOD);
	}

	FastScanner in;
	PrintWriter out;

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
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		public String nextToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
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
		new D().run();
	}
}