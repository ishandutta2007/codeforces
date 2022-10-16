import java.io.*;
import java.util.*;

public class A {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n =in.nextInt();
		int[] a = new int[n];
		int[] pos = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt() - 1;
			pos[a[i]] = i;
		}
		
		int[] dp = new int[n];
		int max = 0;
		for (int i = 0; i < n; i++) {
			if (i > 0) {
				if (pos[i - 1] < pos[i]) {
					dp[i] = dp[i - 1] + 1;
				} else {
					dp[i] = 0;
				}
			}
			max = Math.max(max, dp[i]);
		}
		out.println(n - max - 1);
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
		new A().run();
	}
}