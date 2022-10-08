import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();
		long[] px = new long[n];
		long[] py = new long[n];
		for (int i = 0; i < n; ++i) {
			px[i] = nextInt();
			py[i] = nextInt();
		}
		long[] r = new long[m];
		long[] cx = new long[m];
		long[] cy = new long[m];
		for (int i = 0; i < m; ++i) {
			r[i] = nextInt();
			cx[i] = nextInt();
			cy[i] = nextInt();
		}
		int mm = (m + 31) / 32;
		int[][] ar = new int[n][mm];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if ((px[i] - cx[j]) * (px[i] - cx[j]) + (py[i] - cy[j]) * (py[i] - cy[j]) < r[j] * r[j]) {
					ar[i][j >> 5] |= 1 << (j & 31);
				}
			}
		}
		for (int i = 0; i < k; ++i) {
			int u = nextInt() - 1;
			int v = nextInt() - 1;
			int ans = 0;
			for (int t = 0; t < mm; ++t) {
				ans += Integer.bitCount(ar[u][t] ^ ar[v][t]);
			}
			out.println(ans);
		}
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