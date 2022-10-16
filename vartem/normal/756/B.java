import java.util.*;
import java.io.*;

public class B {

	void solve() {
		int n = in.nextInt();
		int[] t = new int[n];
		for (int i = 0; i < n; i++) {
			t[i] = in.nextInt();
		}
		
		int[] dp = new int[n + 1];
		dp[0] = 0;
		int ptr90 = 0, ptr1440 = 0;
		for (int i = 1; i <= n; i++) {
			dp[i] = Integer.MAX_VALUE;
			dp[i] = Math.min(dp[i], dp[i - 1] + 20);
			
			while (t[i - 1] - t[ptr90] >= 90) {
				ptr90++;
			}
			dp[i] = Math.min(dp[i], dp[ptr90] + 50);
			
			while (t[i - 1] - t[ptr1440] >= 1440) {
				ptr1440++;
			}
			dp[i] = Math.min(dp[i], dp[ptr1440] + 120);
			out.println(dp[i] - dp[i - 1]);
		}
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
		new B().run();
	}
}