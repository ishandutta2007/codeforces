import java.io.*;
import java.util.*;

public class E {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt(), q = in.nextInt();

		long[] a = new long[n];
		long[] sum = new long[n + 1];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextLong();
			sum[i + 1] = sum[i] + a[i];
		}

		int INF = n;
		int[] dpCount = new int[n + 1];
		long[] dpRem = new long[n + 1];
		for (int Q = 0; Q < q; Q++) {
			long b = in.nextLong();

			Arrays.fill(dpCount, INF);
			Arrays.fill(dpRem, 0);
			for (int i = 0; i <= n; i++) {
				if (sum[i] <= b) {
					dpCount[i] = 1;
					dpRem[i] = b - sum[i];
				}
			}

			int l = 0;
			for (int r = 1; r <= n; r++) {
				if (dpCount[r] != INF) {
					continue;
				}
				while (sum[r] - sum[l] > b) {
					l++;
				}

				dpCount[r] = dpCount[l] + 1;
				dpRem[r] = dpRem[l];
			}

			int ans = dpCount[n];
			for (int i = n; i >= 0; i--) {
				long suf = sum[n] - sum[i];
				if (dpRem[i] >= suf) {
					ans = Math.min(ans, dpCount[i]);
				}
			}
			out.println(ans);
		}
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
		new E().run();
	}
}