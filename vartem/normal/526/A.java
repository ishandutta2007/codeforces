import java.io.*;
import java.util.*;

public class A {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		char[] a = in.nextToken().toCharArray();

		for (int step = 1; step < n; step++) {
			for (int i = 0; i < n; i++) {
				boolean ok = true;
				for (int t = 0; t < 5; t++) {
					int j = i + step * t;
					if (j < n && a[j] == '*') {

					} else {
						ok = false;
					}
				}
				if (ok) {
					out.println("yes");
					return;
				}

			}
		}
		out.println("no");

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