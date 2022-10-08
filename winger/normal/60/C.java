import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int u = -1, v = -1;
		HashSet<Integer> ps = new HashSet<Integer>();
		int[][] gcds = new int[n][n];
		int[][] lcms = new int[n][n];
		for (int i = 0; i < m; ++i) {
			u = nextInt() - 1;
			v = nextInt() - 1;
			int gcd = nextInt();
			int lcm = nextInt();
			gcds[u][v] = gcds[v][u] = gcd;
			lcms[u][v] = lcms[v][u] = lcm;
			for (int p = 2; p * p <= lcm; ++p) {
				if (lcm % p == 0) {
					int min = 0, max = 0;
					while (gcd % p == 0) {
						gcd /= p;
						min++;
					}
					while (lcm % p == 0) {
						lcm /= p;
						max++;
					}
					if (min > max) {
						out.println("NO");
						return;
					}
					ps.add(p);
				}
			}
			if (lcm > 1) {
				int p = lcm;
				int min = 0, max = 0;
				while (gcd % p == 0) {
					gcd /= p;
					min++;
				}
				while (lcm % p == 0) {
					lcm /= p;
					max++;
				}
				if (min > max) {
					out.println("NO");
					return;
				}
				ps.add(p);
			}
			if (gcd > 1) {
				out.println("NO");
				return;
			}
		}
//		System.err.println(ps);
		int[] ans = new int[n];
		Arrays.fill(ans, 1);
		int[][] min = new int[n][n];
		int[][] max = new int[n][n];
		for (int p : ps) {
			int[] c = new int[n];
			Arrays.fill(c, -1);
			for (int i = 0; i < n; ++i) {
				min[i][i] = -1;
				for (int j = i + 1; j < n; ++j) {
					if (gcds[i][j] == 0) {
						min[i][j] = min[j][i] = -1;
					} else {
						min[i][j] = min[j][i] = d(gcds[i][j], p);
						max[i][j] = max[j][i] = d(lcms[i][j], p);
					}
				}
			}
			for (int i = 0; i < n; ++i) {
				if (c[i] == -1) {
					 for (int t = 0; t <= 20; ++t) {
						 if (!dfs(i, t, c, min, max, p)) {
							 cleanDfs(i, c, min);
						 } else {
							 break;
						 }
					 }
					 if (c[i] == -1) {
						 out.println("NO");
						 return;
					 }
				}
			}
			for (int i = 0; i < n; ++i) {
				for (int t = 0; t < c[i]; ++t) {
					ans[i] *= p;
				}
			}
		}
		out.println("YES");
		for (int i = 0; i < n; ++i) {
			out.print(ans[i] + " ");
		}
	}
	
	private void cleanDfs(int i, int[] c, int[][] min) {
		if (c[i] == -1) {
			return;
		}
		c[i] = -1;
		for (int j = 0; j < min.length; ++j) {
			if (min[i][j] != -1) {
				cleanDfs(j, c, min);
			}
		}
	}

	int d(int x, int p) {
		int r = 0;
		while (x % p == 0) {
			r++;
			x /= p;
		}
		return r;
	}

	private boolean dfs(int i, int t, int[] c, int[][] min, int[][] max, int p) {
		if (c[i] != -1) {
			return c[i] == t;
		}
		c[i] = t;
		for (int j = 0; j < min.length; ++j) {
			if (min[i][j] != -1) {
				if (t != min[i][j] && t != max[i][j]) {
					return false;
				}
				if (!dfs(j, t == min[i][j] ? max[i][j] : min[i][j], c, min, max, p)) {
					return false;
				}
			}
		}
		return true;
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