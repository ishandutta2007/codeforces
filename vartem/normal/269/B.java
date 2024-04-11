import java.io.*;
import java.util.*;

public class B {

	FastScanner in;
	PrintWriter out;
	final String fileName = "B".toLowerCase();

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int[] a = new int[n + 1];
		for (int i = 0; i < n; i++) {
			a[i + 1] = in.nextInt();
			in.next();
		}

		int[] dp = new int[n + 1];
		int max = 0;
		for (int i = 1; i <= n; i++) {
			dp[i] = 1;
			for (int j = 1; j < i; j++) {
				if (a[i] >= a[j]) {
					dp[i] = Math.max(dp[i], dp[j] + 1);
				}
			}
			max = Math.max(max, dp[i]);
		}
		
		out.println(n-  max);
		
	}

	void run() {
		try {
			in = new FastScanner();
			out = new PrintWriter(System.out);
			solve();
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
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
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new B().run();
	}
}