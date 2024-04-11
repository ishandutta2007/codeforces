import java.io.*;
import java.util.*;

public class A {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt(), m = in.nextInt();
		int ans = 0;
		char[][] a = new char[n][m];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextToken().toCharArray();
		}

		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m - 1; j++) {
				String s = "" + a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1];
				char[] c = s.toCharArray();
				Arrays.sort(c);
				
				if (new String(c).equals("acef")) {
					ans++;
				}
			}
		}
		out.println(ans);
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