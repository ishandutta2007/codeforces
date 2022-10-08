import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;
	
	static class Vector implements Comparable<Vector> {
		long x, y;
		
		Vector(long x, long y) {
			this.x = x;
			this.y = y;
		}

		public int compareTo(Vector o) {
			return Long.signum(x - o.x);
		}
	}
	
	long or(Vector a, Vector b, Vector c) {
		return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		Vector[] a = new Vector[n];
		for (int i = 0; i < n; ++i) {
			a[i] = new Vector(nextLong(), nextLong());
		}
		Arrays.sort(a);
		Vector[] b = new Vector[m];
		for (int i = 0; i < m; ++i) {
			b[i] = new Vector(nextLong(), nextLong());
		}
		int[][] vm = new int[n][n];
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				for (int k = 0; k < m; ++k) {
					if (a[i].x <= b[k].x && b[k].x < a[j].x && or(b[k], a[i], a[j]) < 0) {
						vm[i][j]++;
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				for (int k = j + 1; k < n; ++k) {
					if (vm[i][j] + vm[j][k] == vm[i][k]) {
						ans++;
					}
				}
			}
		}
		out.println(ans);
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