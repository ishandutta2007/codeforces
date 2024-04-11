import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;

	public void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int[][] a = new int[n][m];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				a[i][j] = nextInt();
			}
		}
		int[][] sumh = new int[n][m + 1];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				sumh[i][j + 1] = sumh[i][j] + a[i][j];
			}
		}
		int[][] sumv = new int[n + 1][m];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				sumv[i + 1][j] = sumv[i][j] + a[i][j];
			}
		}
		int ans = -1000000000;
		int[][] d1 = a;
		int[][] d2 = new int[n - 2][m - 2];
		for (int i = 0; i + 3 <= n; ++i) {
			for (int j = 0; j + 3 <= m; ++j) {
				d2[i][j] = sumh[i][j + 3] - sumh[i][j] + sumh[i + 2][j + 3] - sumh[i + 2][j] + a[i + 1][j + 2];
				ans = Math.max(ans, d2[i][j]);
			}
		}
		for (int k = 5; k <= n && k <= m; k += 2) {
			int[][] t = new int[n - k + 1][m - k + 1];
			for (int i = 0; i < t.length; ++i) {
				for (int j = 0; j < t[0].length; ++j) {
					int h1 = sumh[i][j + k] - sumh[i][j];
					int h2 = sumh[i + k - 1][j + k] - sumh[i + k - 1][j];
					int v1 = sumv[i + k - 1][j + k - 1] - sumv[i + 1][j + k - 1];
					int v2 = sumv[i + k - 1][j] - sumv[i + 2][j];
					t[i][j] = d1[i + 2][j + 2] + h1 + h2 + v1 + v2 + a[i + 2][j + 1];
					ans = Math.max(ans, t[i][j]);
				}
			}
			d1 = d2;
			d2 = t;
		}
		out.println(ans);
	}

	public void run() throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		eat("");
		
		solve();
		
		out.close();
	}
	
	void eat(String s) {
		st = new StringTokenizer(s);
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			eat(line);
		}
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}
	
	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Solution().run();
	}
	
}