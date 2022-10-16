import java.io.*;
import java.util.*;

public class D {

	FastScanner in;
	PrintWriter out;
	final String fileName = "D".toLowerCase();

	void solve() {
		String s = in.next().toLowerCase();
		int num = in.nextInt();
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) < 97 + num) {
				out.print(Character.toUpperCase(s.charAt(i)));
			} else {
				out.print(s.charAt(i));
			}
		}
		out.println();
	}

	void run() {
		try {
			in = new FastScanner();
			out = new PrintWriter(System.out);
			solve();
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new D().run();
	}
}