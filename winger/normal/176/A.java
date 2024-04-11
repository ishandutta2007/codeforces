import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;

	class Pair implements Comparable<Pair> {
		int count, cost;

		public Pair(int cost, int count) {
			this.cost = cost;
			this.count = count;
		}

		@Override
		public int compareTo(Pair o) {
			return o.cost - cost;
		}
	}
	
	public void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();
		int[][] a = new int[n][m];
		int[][] b = new int[n][m];
		int[][] c = new int[n][m];
		for (int i = 0; i < n; ++i) {
			next();
			for (int j = 0; j < m; ++j) {
				a[i][j] = nextInt();
				b[i][j] = nextInt();
				c[i][j] = nextInt();
			}
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				Pair[] ps = new Pair[m];
				for (int t = 0; t < m; ++t) {
					ps[t] = new Pair(b[j][t] - a[i][t], c[i][t]);
				}
				Arrays.sort(ps);
				int count = k;
				int val = 0;
				for (Pair p : ps) {
					if (p.cost > 0) {
						int cc = Math.min(count, p.count);
						val += cc * p.cost;
						count -= cc;
					}
				}
				ans = Math.max(ans, val);
			}
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