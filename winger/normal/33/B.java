import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	void solve() throws IOException {
		String a = next();
		String b = next();
		if (a.length() != b.length()) {
			out.println(-1);
			return;
		}
		int n = nextInt();
		int[][] c = new int[26][26];
		for (int[] ar : c) {
			Arrays.fill(ar, 1000000000);
		}
		for (int i = 0; i < n; ++i) {
			int u = next().charAt(0) - 'a';
			int v = next().charAt(0) - 'a';
			int w = nextInt();
			c[u][v] = Math.min(c[u][v], w);
		}
		for (int k = 0; k < 26; ++k) {
			for (int i = 0; i < 26; ++i) {
				for (int j = 0; j < 26; ++j) {
					c[i][j] = Math.min(c[i][j], c[i][k] + c[k][j]);
				}
			}
		}
		int[][] d = new int[26][26];
		char[][] e = new char[26][26];
		for (int i = 0; i < 26; ++i) {
			for (int j = 0; j < 26; ++j) {
				d[i][j] = Math.min(c[i][j], c[j][i]);
				if (c[i][j] < c[j][i]) {
					e[i][j] = (char) (j + 'a');
				} else {
					e[i][j] = (char) (i + 'a');
				}
				for (int k = 0; k < 26; ++k) {
					if (d[i][j] > c[i][k] + c[j][k]) {
						d[i][j] = c[i][k] + c[j][k];
						e[i][j] = (char) (k + 'a');
					}
				}
				if (i == j) {
					d[i][j] = 0;
					e[i][i] = (char) (i + 'a');
				}
			}
		}
		char[] ansv = new char[a.length()];
		int ans = 0;
		for (int i = 0; i < a.length(); ++i) {
			int u = a.charAt(i) - 'a';
			int v = b.charAt(i) - 'a';
			if (d[u][v] == 1000000000) {
				out.println(-1);
				return;
			}
			ansv[i] = e[u][v];
			ans += d[u][v];
		}
		out.println(ans);
		out.println(ansv);
	}

	Solution() throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		
		eat("");
		
		solve();
		
		in.close();
		out.close();
	}
	
	private void eat(String str) {
		st = new StringTokenizer(str);
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
		new Solution();
	}
}