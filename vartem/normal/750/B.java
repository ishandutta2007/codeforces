import java.util.*;
import java.io.*;

public class B {

	void solve() {
		int n = in.nextInt();
		int cur = 10000;
		for (int i = 0; i < n; i++) {
			int val = in.nextInt();
			String dir = in.nextToken();
			if (cur == 10000) {
				if (!dir.equals("South")) {
					out.println("NO");
					return;
				}
			}
			if (cur == -10000) {
				if (!dir.equals("North")) {
					out.println("NO");
					return;
				}
			}
			if (dir.equals("North")) {
				cur += val;
			} else if (dir.equals("South")) {
				cur -= val;
			}

			if (cur < -10000 || cur > 10000) {
				out.println("NO");
				return;
			}
		}
		out.println(cur == 10000 ? "YES" : "NO");
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