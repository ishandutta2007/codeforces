import java.io.*;
import java.util.*;

public class D {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt(), k = in.nextInt();
		int[] p = new int[n];
		int LOG = 22;

		char[] a = in.nextToken().toCharArray();

		for (int i = 1; i < a.length; i++) {
			int t = p[i - 1];
			while (t > 0 && a[t] != a[i]) {
				t = p[t - 1];
			}
			if (a[t] == a[i]) {
				t++;
			}
			p[i] = t;
		}

		int[][] pr = new int[LOG][n];
		pr[0] = p;
		for (int j = 1; j < LOG; j++) {
			for (int i = 0; i < n; i++) {
				int t = pr[j - 1][i];
				if (t == 0) {
					pr[j][i] = 0;
				} else {
					pr[j][i] = pr[j - 1][t - 1];
				}
			}
		}

		// A is not empty
		char[] ans = new char[n];
		Arrays.fill(ans, '0');
		for (int i = 0; i < n; i++) {
			int len = i + 1;
			int cur = len;
			for (int j = LOG - 1; j >= 0; j--) {
				if (cur == 0) {
					continue;
				}
				int nxt = pr[j][cur - 1];
				if ((len - 1) / (len - nxt) >= k) {
					cur = nxt;
				}
			}

			if (cur != len && (len - 1) / (len - cur) == k) {
				ans[i] = '1';
			}
		}
		// A is empty
		for (int i = 0; i < n; i++) {
			int len = i + 1;
			int cur = len;
			for (int j = LOG - 1; j >= 0; j--) {
				if (cur == 0) {
					continue;
				}
				int nxt = pr[j][cur - 1];
				if (len / (len - nxt) >= k) {
					cur = nxt;
				}
			}

			if (cur != len && len == 1L * (len - cur) * k) {
				ans[i] = '1';
			}
		}
		out.println(new String(ans));
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
		new D().run();
	}
}