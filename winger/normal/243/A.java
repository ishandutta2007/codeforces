import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;

	public void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; ++i) {
			a[i] = nextInt();
		}
		int[][] next = new int[n + 1][20];
		Arrays.fill(next[n], n);
		for (int i = n - 1; i >= 0; --i) {
			for (int j = 0; j < 20; ++j) {
				next[i][j] = next[i + 1][j];
				if ((a[i] & (1 << j)) != 0) {
					next[i][j] = i;
				}
			}
		}
		boolean[] col = new boolean[1 << 20];
		for (int i = 0; i < n; ++i) {
			int mask = 0;
			int j = i;
			while (j < n) {
//				System.err.println(mask + " " + i + " " + j);
				mask |= a[j];
				col[mask] = true;
				int k = n;
				for (int t = 0; t < 20; ++t) {
					if ((mask & (1 << t)) == 0) {
						k = Math.min(k, next[j + 1][t]);
					}
				}
				j = k;
			}
		}
		int ans = 0;
		for (int i = 0; i < col.length; ++i) {
			ans += col[i] ? 1 : 0;
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