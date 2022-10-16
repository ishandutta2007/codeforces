import java.io.*;
import java.util.*;

public class A {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int m = in.nextInt(), n = in.nextInt();
		char[][] a = new char[n][m];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextToken().toCharArray();
		}

		a = rotateCW(a);
		a = reflectHor(a);

		for (int i = 0; i < 2 * a.length; i++) {
			for (int j = 0; j < 2 * a[i / 2].length; j++) {
				out.print(a[i / 2][j / 2]);
			}
			out.println();
		}
	}

	char[][] rotateCW(char[][] a) {
		char[][] b = new char[a[0].length][a.length];
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[i].length; j++) {
				b[j][a.length - 1 - i] = a[i][j];
			}
		}
		return b;
	}

	char[][] reflectHor(char[][] a) {
		for (int i = 0; i < a.length; i++) {
			for (int l = 0, r = a[0].length - 1; l < r; l++, r--) {
				char tmp = a[i][l];
				a[i][l] = a[i][r];
				a[i][r] = tmp;
			}
		}
		return a;
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