import java.io.*;
import java.util.*;

public class D {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		char[][] a = new char[n][n];
		for (int i = 0; i < n; i++){
			a[i] = in.nextToken().toCharArray();
		}

		char[][] ans = new char[2 * n - 1][2 * n - 1];
		for (char[] c : ans) {
			Arrays.fill(c, '.');
		}

		for (int dx = -n + 1; dx <= n - 1; dx++) {
			for (int dy = -n + 1; dy <= n - 1; dy++) {
				if (dx == 0 && dy == 0) {
					ans[n - 1 + dx][n - 1 + dy] = 'o';
					continue;
				}
				boolean can = true;

				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						int ni = i + dx, nj = j + dy;
						if (0 <= ni && ni < n && 0 <= nj && nj < n) {
							if (a[i][j] == 'o' && a[ni][nj] == '.') {
								can = false;
							}
						}
					}
				}
				if (can) {
					ans[n - 1 + dx][n - 1 + dy] = 'x';
				}
			}
		}

		char[][] b = new char[n][n];
		for (char[] c : b) {
			Arrays.fill(c, '.');
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 'o') {
					b[i][j] = 'o';
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 'o') {
					for (int dx = -n + 1; dx <= n - 1; dx++) {
						for (int dy = -n + 1; dy <= n - 1; dy++) {
							if (ans[n - 1 + dx][n - 1 + dy] != 'x') {
								continue;
							}

							int ni = i + dx, nj = j + dy;
							if (0 <= ni && ni < n && 0 <= nj && nj < n) {
								if (b[ni][nj] == '.') {
									b[ni][nj] = 'x';
								}
							}
						}
					}
				}
			}
		}

		if (Arrays.deepEquals(a, b)) {
			out.println("YES");
			for (char[] c : ans) {
				out.println(new String(c));
			}
		} else {
			out.println("NO");
		}
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
		new D().run();
	}
}