
import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;

	public void solve() throws IOException {
		String a = next();
		String b = next();
		int n = a.length();
		int m = b.length();
		final int mod = 1000000007;
		int[][] d = new int[n + 1][m + 1];
		int ans = 0;
		for (int i = 0; i <= n; ++i) {
			d[i][0] = 1;
			for (int j = 0; j < m; ++j) {
				d[i][j + 1] = (d[i][j + 1] + d[i][j]) % mod;
				if (i < n && a.charAt(i) == b.charAt(j)) {
					d[i + 1][j + 1] = (d[i + 1][j + 1] + d[i][j]) % mod;
				}
			}
			ans = (ans + d[i][m]) % mod;
		}
		ans = (ans + mod - n - 1) % mod;
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