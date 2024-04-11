import java.util.*;
import java.io.*;

public class D {

	char[] c;
	int i;

	char[][] parse() {
		if (i == c.length || c[i] == ']') {
			return create(1, 3);
		}
		i++;
		char[][] result = enclose(parse());
		i++;
		result = concat(result, parse());
		return result;
	}

	char[][] enclose(char[][] a) {
		int n = a.length + 2, m = a[0].length + 2;
		char[][] result = create(n, m);
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[0].length; j++) {
				result[i + 1][j + 1] = a[i][j];
			}
		}

		result[0][0] = result[n - 1][0] = result[0][m - 1] = result[n - 1][m - 1] = '+';
		result[0][1] = result[n - 1][1] = result[0][m - 2] = result[n - 1][m - 2] = '-';
		for (int i = 1; i + 1 < n; i++) {
			result[i][0] = result[i][m - 1] = '|';
		}
		return result;
	}

	char[][] concat(char[][] a, char[][] b) {
		if (a.length == 1) {
			return b;
		}
		if (b.length == 1) {
			return a;
		}
		int n1 = a.length, n2 = b.length;
		int m1 = a[0].length, m2 = b[0].length;

		int n = Math.max(n1, n2), m = m1 + m2;
		char[][] result = create(n, m);

		for (int j = 0; j < m1; j++) {
			int half = n1 / 2;

			for (int i = 0; i < half; i++) {
				result[i][j] = a[i][j];
			}
			for (int i = half; i < n - half; i++) {
				result[i][j] = a[half][j];
			}
			for (int i = n - half; i < n; i++) {
				result[i][j] = a[n1 - (n - i)][j];
			}
		}

		for (int j = 0; j < m2; j++) {
			int half = n2 / 2;

			for (int i = 0; i < half; i++) {
				result[i][j + m1] = b[i][j];
			}

			for (int i = half; i < n - half; i++) {
				result[i][j + m1] = b[half][j];
			}
			for (int i = n - half; i < n; i++) {
				result[i][j + m1] = b[n2 - (n - i)][j];
			}
		}
		return result;
	}

	private char[][] create(int n, int m) {
		char[][] result = new char[n][m];
		for (int i = 0; i < result.length; i++) {
			for (int j = 0; j < result[0].length; j++) {
				result[i][j] = ' ';
			}
		}
		return result;
	}

	void solve() {
		in.nextInt();
		this.c = in.nextToken().toCharArray();
		this.i = 0;
		char[][] result = parse();
		for (int i = 0; i < result.length; i++) {
			out.println(new String(result[i]));
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
		new D().run();
	}
}