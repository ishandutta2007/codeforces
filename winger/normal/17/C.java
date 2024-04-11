import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;
	
	int mod = 51123987;

	void solve() throws IOException {
		int n = nextInt();
		String s = next();
//		String s = "";
//		Random rnd = new Random();
//		for (int i = 0; i < n; ++i) {
//			s = s + (char)(rnd.nextInt(3) + 'a');
//		}
		int m = (n + 2) / 3;
		int[][][][] d = new int[3][m + 1][m + 1][m + 1];
		int[][][][] pool = new int[3][m + 1][m + 1][m + 1];
		pool[0][0][0][0] = pool[1][0][0][0] = pool[2][0][0][0] = 1;
		for (char c : s.toCharArray()) {
//			System.out.print(c);
			if (c == 'a') {
				for (int v = 0; v <= m; ++v) {
					for (int w = 0; w <= m; ++w) {
						int t = 0;
						for (int u = 0; u <= m; ++u) {
							d[0][u][v][w] = mod(d[0][u][v][w] + t);
							pool[1][u][v][w] = mod(pool[1][u][v][w] + t);
							pool[2][u][v][w] = mod(pool[2][u][v][w] + t);
							t = mod(t + pool[0][u][v][w]);
							pool[0][u][v][w] = 0;
						}
					}
				}
			} else if (c == 'b') {
				for (int u = 0; u <= m; ++u) {
					for (int w = 0; w <= m; ++w) {
						int t = 0;
						for (int v = 0; v <= m; ++v) {
							d[1][u][v][w] = mod(d[1][u][v][w] + t);
							pool[0][u][v][w] = mod(pool[0][u][v][w] + t);
							pool[2][u][v][w] = mod(pool[2][u][v][w] + t);
							t = mod(t + pool[1][u][v][w]);
							pool[1][u][v][w] = 0;
						}
					}
				}
			} else if (c == 'c') {
				for (int u = 0; u <= m; ++u) {
					for (int v = 0; v <= m; ++v) {
						int t = 0;
						for (int w = 0; w <= m; ++w) {
							d[2][u][v][w] = mod(d[2][u][v][w] + t);
							pool[0][u][v][w] = mod(pool[0][u][v][w] + t);
							pool[1][u][v][w] = mod(pool[1][u][v][w] + t);
							t = mod(t + pool[2][u][v][w]);
							pool[2][u][v][w] = 0;
						}
					}
				}
			} else {
				throw new AssertionError();
			}
		}
		int ans = 0;
		for (int u = 0; u <= n; ++u) {
			for (int v = 0; v <= n; ++v) {
				for (int w = 0; w <= n; ++w) {
					if (u + v + w == n && Math.abs(u - v) <= 1 && Math.abs(u - w) <= 1 && Math.abs(v - w) <= 1) {
						for (int t = 0; t < 3; ++t) {
							ans = (ans + d[t][u][v][w]) % mod;
						}
					}
				}
			}
		}
		out.println(ans);
	}

	private int mod(int i) {
		while (i >= mod) {
			i -= mod;
		}
		return i;
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