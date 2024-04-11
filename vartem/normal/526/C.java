import java.io.*;
import java.util.*;

public class C {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int MAX = 1000;
		int c = in.nextInt(), hr = in.nextInt(), hb = in.nextInt();
		int wr = in.nextInt(), wb = in.nextInt();
		
		if (wr > wb) {
			int tmp = wr;
			wr = wb;
			wb = tmp;
			
			tmp = hr;
			hr = hb;	
			hb = tmp;
		}
		
		// wr <= wb

		long ans = 0;
		
		if (wb > MAX) {
			for (int i = 0; 1L * i * wb <= c; i++) {
				int rmn = (c - i * wb) / wr;
				ans = Math.max(ans, 1L * i * hb + 1L * rmn * hr);
			}
			
		} else {
			long[] dp = new long[6 * wr * wb + 1];
			dp[0] = 0;
			for (int i = 1; i < dp.length; i++) {
				if (i >= wr) {
					dp[i] = Math.max(dp[i], dp[i - wr] + hr);
				}
				if (i >= wb) {
					dp[i] = Math.max(dp[i], dp[i - wb] + hb);
				}
			}

			for (int i = 1; i < dp.length; i++) {
				long rem = c / i;
				ans = Math.max(ans, dp[c % i] + rem * dp[i]); 
			}
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
		new C().run();
	}
}