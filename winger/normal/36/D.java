import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	void solve() throws IOException {
		int t = nextInt();
		int k = nextInt();
		for (int i = 0; i < t; ++i) {
			int n = nextInt() - 1;
			int m = nextInt() - 1;
			if (solve(n, m, k)) {
				out.println("+");
			} else {
				out.println("-");
			}
		}
//		int k = nextInt();
//		int n = 10, m = 10;
//		boolean[][] d = new boolean[n][m];
//		for (int i = 0; i < n; ++i) {
//			for (int j = 0; j < m; ++j) {
//				if (i > 0 && !d[i - 1][j] ||
//					j > 0 && !d[i][j - 1] ||
//					i >= k && j >= k && !d[i - k][j - k]) {
//					d[i][j] = true;
//				}
//				System.out.print(d[i][j] ? "+" : "-");
//				if (d[i][j] != solve(i, j, k)) {
//					throw new AssertionError();
//				}
//			}
//			System.out.println();
//		}
	}

	private boolean solve(int n, int m, int k) {
		return (n + m + (k > 1 ? Math.min(n, m) / (k + 1) : 0)) % 2 == 1 || Math.min(n, m) % (k + 1) == k;
	}

	Solution() throws IOException {
		in = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
		
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