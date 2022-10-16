import java.io.*;
import java.util.*;

public class B {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt(), k = in.nextInt();
		Integer[] a = new Integer[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		Arrays.sort(a);
		
		long INF = Long.MAX_VALUE / 2;
		int small = n / k, big = (n + k - 1) / k;
		int cntBig = n % k, cntSmall = k - cntBig;
		long[][] dp = new long[cntSmall + 1][cntBig + 1];
		for (long[] i : dp) {
			Arrays.fill(i, INF);
		}
		dp[0][0] = 0;
		
		for (int i = 0; i <= cntSmall; i++) {
			for (int j = 0; j <= cntBig; j++) {
				if (dp[i][j] == INF) {
					continue;
				}
				
				int pos = i * small + j * big;
				if (i < cntSmall) {
					dp[i + 1][j] = Math.min(dp[i + 1][j], dp[i][j] + a[pos + small - 1] - a[pos]);
				}
				if (j < cntBig) {
					dp[i][j + 1] = Math.min(dp[i][j + 1], dp[i][j] + a[pos + big - 1] - a[pos]);
				}
			}
		}
		
		out.println(dp[cntSmall][cntBig]);
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