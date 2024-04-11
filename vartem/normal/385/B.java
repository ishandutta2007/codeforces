import java.io.*;
import java.util.*;

public class B {

	FastScanner in;
	PrintWriter out;

	void solve() {
		String s = in.nextToken();
		int ans = 0;
		String bear = "bear";
		for (int i = 0; i < s.length(); i++) {
			boolean ok = false;
			int pos = 0;
			for (int j = i; j < s.length(); j++) {
				while (pos > 0 && s.charAt(j) != bear.charAt(pos)) {
					pos--;
				}
				if (bear.charAt(pos) == s.charAt(j)) {
					pos++;
				}
				if (pos == 4) {
					ok = true;
					pos = 0;
				}
				if (ok) {
					ans++;
				}
			}
		}
		out.println(ans);
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
		new B().run();
	}
}