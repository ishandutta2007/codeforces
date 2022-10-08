import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;

	public void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		int[] l = new int[n];
		int[] r = new int[n];
		int[] c = new int[n];
		for (int i = 0; i < n; ++i) {
			l[i] = nextInt();
			r[i] = l[i] + nextInt();
			c[i] = nextInt();
		}
		int gn = 2 * n + 2;
		int[][] cap = new int[gn][gn];
		int[][] cost = new int[gn][gn];
		int s = gn - 2;
		int t = gn - 1;
		for (int i = 0; i < n; ++i) {
			cap[s][2 * i + 0] = cap[2 * i + 0][2 * i + 1] = cap[2 * i + 1][t] = 1;
			cost[2 * i + 0][2 * i + 1] = -c[i];
			cost[2 * i + 1][2 * i + 0] = +c[i];
			for (int j = 0; j < n; ++j) {
				if (r[i] <= l[j]) {
					cap[2 * i + 1][2 * j + 0] = 1;
				}
			}
		}
		int[] phi = new int[gn];
		for (int i = 0; i < n; ++i) {
			phi[t] -= c[i];
			for (int j = 0; j < n; ++j) {
				if (r[j] <= l[i]) {
					phi[2 * i + 0] -= c[j];
				}
			}
			phi[2 * i + 1] = phi[2 * i + 0] - c[i];
		}
		for (int i = 0; i < gn; ++i) {
			for (int j = 0; j < gn; ++j) {
				if (cap[i][j] > 0 && cost[i][j] + phi[i] - phi[j] < 0) {
					throw new AssertionError();
				}
			}
		}
		int[] d = new int[gn];
		int[] p = new int[gn];
		boolean[] col = new boolean[gn];
		for (int it = 0; it < k; ++it) {
			Arrays.fill(d, 1000000000);
			d[s] = 0;
			Arrays.fill(col, false);
			while (true) {
				int min = -1;
				for (int i = 0; i < gn; ++i) {
					if (!col[i] && d[i] < 1000000000 && (min == -1 || d[min] > d[i])) {
						min = i;
					}
				}
				if (min == -1) {
					break;
				}
				col[min] = true;
				for (int i = 0; i < gn; ++i) {
					int len = cost[min][i] + phi[min] - phi[i];
					if (cap[min][i] > 0 && d[i] > d[min] + len) {
						if (len < 0) {
							throw new AssertionError();
						}
						d[i] = d[min] + len;
						p[i] = min;
					}
				}
			}
			if (!col[t]) {
				break;
			}
			for (int i = t; i != s; i = p[i]) {
				cap[p[i]][i]--;
				cap[i][p[i]]++;
			}
			for (int i = 0; i < gn; ++i) {
				if (col[i]) {
					phi[i] += d[i];
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			out.print(cap[2 * i + 1][2 * i + 0] + " ");
		}
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