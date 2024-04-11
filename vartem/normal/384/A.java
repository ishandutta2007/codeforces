import java.io.*;
import java.util.*;

public class A {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		out.println((n * n + 1) / 2);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				out.print("C.".charAt((i + j) % 2));
			}
			out.println();
		}
	}

	void run() {
		try {
			in = new FastScanner();
			out = new PrintWriter(System.out);
			solve();
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		public String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
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