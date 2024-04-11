import java.io.*;
import java.util.*;

public class B {

	FastScanner in;
	PrintWriter out;
	final String fileName = "B".toLowerCase();

	void solve() {
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}

		List<Integer>[] divisors = new List[n];
		for (int i = 0; i < n; i++) {
			divisors[i] = new ArrayList<>();
			int b = a[i];
			for (int j = 2; j * j <= b; j++) {
				if (b % j == 0) {
					divisors[i].add(j);
					while (b % j == 0) {
						b /= j;
					}
				}
			}
			if (b > 1) {
				divisors[i].add(b);
			}
		}

		final int MAX = 100000;
		int[] dp = new int[MAX + 1];

		for (int i = 0; i < n; i++) {
			int curMax = 0;
			for (int j : divisors[i]) {
				curMax = Math.max(curMax, dp[j] + 1);
			}
			for (int j : divisors[i]) {
				dp[j] = Math.max(dp[j], curMax);
			}
		}

		int maxDp = 1;
		for (int i : dp) {
			maxDp = Math.max(maxDp, i);
		}

		out.println(maxDp);
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