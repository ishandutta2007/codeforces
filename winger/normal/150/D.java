
import java.io.*;
import java.util.*;
import java.util.regex.Pattern;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;


	public void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n + 1];
		for (int i = 1; i <= n; ++i) {
			a[i] = nextInt();
		}
		String s = next();
		int[][][] d = new int[n][n][n + 1];
		for (int[][] arr : d) {
			for (int[] ar : arr) {
				Arrays.fill(ar, -1000000000);
			}
		}
		for (int i = 0; i < n; ++i) {
			d[i][i][1] = 0;
		}
		for (int i = 0; i < n - 1; ++i) {
			if (s.charAt(i) == s.charAt(i + 1)) {
				d[i][i + 1][2] = 0;
			}
		}
		for (int l = 1; l <= n; ++l) {
			for (int i = 0; i + l <= n; ++i) {
				int j = i + l - 1;
				if (l > 2 && s.charAt(i) == s.charAt(j)) {
					for (int t = 0; t <= l - 2; ++t) {
						if (d[i + 1][j - 1][t] >= 0) {
							d[i][j][t + 2] = Math.max(d[i][j][t + 2], d[i + 1][j - 1][t]);
						}
					}
				}
				for (int k = i; k <= j; ++k) {
					if (k < j && d[i][k][0] >= 0) {
						for (int t = 0; t <= l; ++t) {
							d[i][j][t] = Math.max(d[i][j][t], d[k + 1][j][t] + d[i][k][0]);
						}
					}
					if (i < k && d[k][j][0] >= 0) {
						for (int t = 0; t <= l; ++t) {
							d[i][j][t] = Math.max(d[i][j][t], d[i][k - 1][t] + d[k][j][0]);
						}
					}
				}
				for (int t = 1; t <= l; ++t) {
					if (a[t] != -1) {
						d[i][j][0] = Math.max(d[i][j][0], d[i][j][t] + a[t]);
					}
				}
			}
		}
		int[] ans = new int[n + 1];
		for (int i = 0; i < n; ++i) {
			for (int j = i; j < n; ++j) {
				ans[j + 1] = Math.max(ans[j + 1], ans[i] + d[i][j][0]);
			}
			ans[i + 1] = Math.max(ans[i + 1], ans[i]);
		}
		out.println(ans[n]);
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
	
	static boolean failed = false;
	
	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Solution().run();
	}
	
}