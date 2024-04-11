import java.util.*;
import java.io.*;

public class C {

	void solve() {
		int n = in.nextInt();
		int cur = 0;

		int max = Integer.MAX_VALUE / 2, min = Integer.MIN_VALUE / 2;
		for (int i = 0; i < n; i++) {
			int delta = in.nextInt();
			if (in.nextInt() == 1) {
				min = Math.max(min, 1900 - cur);
			} else {
				max = Math.min(max, 1899 - cur);
			}
			cur += delta;
		}
		if (min > max) {
			out.println("Impossible");
		} else if (max == Integer.MAX_VALUE / 2) {
			out.println("Infinity");
		} else {
			out.println(max + cur);
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
		new C().run();
	}
}