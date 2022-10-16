import java.io.*;
import java.util.*;

public class A {

	FastScanner in;
	PrintWriter out;

	void solve() {
		String s = in.nextToken();
		for (int i = 0; i < s.length(); i++) {
			for (int j = i; j <= s.length(); j++) {
				String a = s.substring(0, i) + s.substring(j);
				if (a.equals("CODEFORCES")) {
					out.println("YES");
					return;
				}
			}
		}
		out.println("NO");
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