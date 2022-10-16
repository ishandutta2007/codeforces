import java.io.*;
import java.util.*;

public class A {

	FastScanner in;
	PrintWriter out;

	void solve() {
		long a = in.nextLong(), b = in.nextLong(), c = in.nextLong();
		long l = in.nextLong();
		long[] as = new long[] {a, b, c, a, b};
		long ans = 0;
		for (long  i = 0; i <= l; i++) {
			ans += (i + 2) * (i + 1) / 2;
		}
		for (int pos = 0; pos < 3; pos++) {
			for (long add = 0; add <= l; add++) {
				long cur = as[pos] + add;
				if (as[pos + 1] + as[pos + 2] > cur) {
					continue;
				}
				
				long maxAdd = Math.min(l - add, cur - as[pos + 1] - as[pos + 2]);
				ans -= (maxAdd + 1) * (maxAdd + 2) / 2;
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
		new A().run();
	}
}