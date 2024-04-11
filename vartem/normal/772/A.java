import java.util.*;
import java.io.*;

public class A {

	void solve() {
		int n = in.nextInt(), p = in.nextInt();
		int[] a = new int[n], b = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
			b[i] = in.nextInt();
		}
		
		double l = 0, r = 1e13;
		boolean fail = false;
		for (int IT = 0; IT < 200; IT++) {
			double m = (l + r) / 2;
			long coefM = 0, coef1 = 0;
			for (int i = 0; i < n; i++) {
				if (a[i] * m > b[i]) {
					coefM += a[i];
					coef1 -= b[i];
				}
			}
			if (p >= coefM || m <= 1.0 * coef1 / (p - coefM)) {
				l = m;
			} else {
				fail = true;
				r = m;
			}
		}
		
		if (!fail) {
			out.println(-1);
		} else {
			out.println((l + r) / 2);
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
		new A().run();
	}
}