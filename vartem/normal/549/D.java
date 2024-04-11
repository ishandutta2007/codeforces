import java.io.*;
import java.util.*;

public class D {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt(), m = in.nextInt();

		int[][] cnt = new int[n][m];
		for (int i = 0; i < n; i++) {
			String s = in.nextToken();
			for (int j = 0; j < m; j++) {
				if (s.charAt(j) == 'W') {
					cnt[i][j] = 1;
				} else {
					cnt[i][j] = -1;
				}
			}
		}

		int ans = 0;
		while (true) {
			int ni = -1, nj = -1;
			for (int i = n - 1; i >= 0; i--) {
				for (int j = m - 1; j >= 0; j--) {
					if (cnt[i][j] != 0) {
						ni = i;
						nj = j;
						break;
					}
				}
				if (ni != -1) {
					break;
				}
			}
			if (ni == -1) {
				break;
			}
			ans++;
			int val = cnt[ni][nj];
			
			for (int i = 0; i <= ni; i++) {
				for (int j = 0; j <= nj; j++) {
					cnt[i][j] -= val;
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
		new D().run();
	}
}