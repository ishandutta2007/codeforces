import java.util.*;
import java.io.*;

public class B {

	void solve() {
		
		int n = in.nextInt();
		long p = in.nextLong(), q = in.nextLong(), r = in.nextLong();
		long[] a = new long[n];
		long[] pref = new long[n], suf = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextLong();
		}
		
		for (int i = 0; i < n; i++) {
			pref[i] = p * a[i];
			if (i > 0) {
				pref[i] = Math.max(pref[i], pref[i - 1]);
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			suf[i] = r * a[i];
			if (i + 1 < n) {
				suf[i] = Math.max(suf[i], suf[i + 1]);
			}
		}
		long best=  Long.MIN_VALUE;
		for (int i = 0; i < n; i++) {
			best = Math.max(best, q * a[i] + pref[i] + suf[i]);
		}
		out.println(best);
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