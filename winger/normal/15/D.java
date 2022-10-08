import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;
	
	static class MinQueue {
		long[] a;
		int[] inds;
		int s, t;
		
		MinQueue(int n) {
			a = new long[n];
			inds = new int[n];
		}
		
		long min() {
			if (s == t) {
				throw new AssertionError();
			}
			return a[s];
		}
		
		void push(int i, long val) {
			while (s < t && a[t - 1] >= val) {
				--t;
			}
			a[t] = val;
			inds[t] = i;
			++t;
		}
		
		void pop(int i) {
			if (inds[s] == i) {
				++s;
			}
		}
	}
	
	static class Pos implements Comparable<Pos> {
		int x, y;
		long val;

		public Pos(int x, int y, long val) {
			this.x = x;
			this.y = y;
			this.val = val;
		}

		public int compareTo(Pos o) {
			if (val == o.val) {
				if (x == o.x) {
					return y - o.y;
				}
				return x - o.x;
			}
			return Long.signum(val - o.val);
		}
		
		
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int u = nextInt();
		int v = nextInt();
		long[][] a = new long[n][m];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				a[i][j] = nextInt();
			}
		}
		long[][] mins = new long[n - u + 1][m];
		for (int j = 0; j < m; ++j) {
			MinQueue q = new MinQueue(n);
			for (int i = 0; i < u - 1; ++i) {
				q.push(i, a[i][j]);
			}
			for (int i = u - 1; i < n; ++i) {
				q.push(i, a[i][j]);
				mins[i - u + 1][j] = q.min();
				q.pop(i - u + 1);
			}
		}
		for (int i = 0; i < n - u + 1; ++i) {
			long[] tmp = new long[m - v + 1];
			MinQueue q = new MinQueue(m);
			for (int j = 0; j < v - 1; ++j) {
				q.push(j, mins[i][j]);
			}
			for (int j = v - 1; j < m; ++j) {
				q.push(j, mins[i][j]);
				tmp[j - v + 1] = q.min();
				q.pop(j - v + 1);
			}
			mins[i] = tmp;
		}
		long[][] sums = new long[n - u + 1][m];
		for (int j = 0; j < m; ++j) {
			long q = 0;
			for (int i = 0; i < u - 1; ++i) {
				q += a[i][j];
			}
			for (int i = u - 1; i < n; ++i) {
				q += a[i][j];
				sums[i - u + 1][j] = q;
				q -= a[i - u + 1][j];
			}
		}
		for (int i = 0; i < n - u + 1; ++i) {
			long[] tmp = new long[m - v + 1];
			long q = 0;
			for (int j = 0; j < v - 1; ++j) {
				q += sums[i][j];
			}
			for (int j = v - 1; j < m; ++j) {
				q += sums[i][j];
				tmp[j - v + 1] = q;
				q -= sums[i][j - v + 1];
			}
			sums[i] = tmp;
		}
		ArrayList<Pos> ps = new ArrayList<Pos>();
		for (int i = 0; i < n - u + 1; ++i) {
			for (int j = 0; j < m - v + 1; ++j) {
				ps.add(new Pos(i, j, sums[i][j] - mins[i][j] * u * v));
			}
		}
		Collections.sort(ps);
		boolean[][] bad = new boolean[n - u + 1][m - v + 1];
		ArrayList<Pos> ans = new ArrayList<Pos>();
		for (Pos p : ps) {
			if (!bad[p.x][p.y]) {
				ans.add(p);
				for (int i = -u + 1; i < u; ++i) {
					for (int j = -v + 1; j < v; ++j) {
						if (p.x + i >= 0 && p.x + i < n - u + 1 &&
							p.y + j >= 0 && p.y + j < m - v + 1) {
							bad[p.x + i][p.y + j] = true;
						}
					}
				}
			}
		}
		out.println(ans.size());
		for (Pos p : ans) {
			out.println((p.x + 1) + " " + (p.y + 1) + " " + p.val);
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