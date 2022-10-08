import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;
	private char[][][] f;

	void solve() throws IOException {
		int k = nextInt();
		int n = nextInt();
		int m = nextInt();
		f = new char[k][n][];
		for (int i = 0; i < k; ++i) {
			for (int j = 0; j < n; ++j) {
				f[i][j] = next().toCharArray();
			}
		}
		int x = nextInt() - 1;
		int y = nextInt() - 1;
		out.println(dfs(0, x, y, new boolean[k][n][m]));
	}

	private int dfs(int i, int j, int k, boolean[][][] col) {
		if (i < 0 || i >= f.length || j < 0 || j >= f[0].length || k < 0 || k >= f[0][0].length || f[i][j][k] == '#' || col[i][j][k]) {
			return 0;
		}
		col[i][j][k] = true;
		final int[] dx = {-1, 1, 0, 0, 0, 0};
		final int[] dy = {0, 0, -1, 1, 0, 0};
		final int[] dz = {0, 0, 0, 0, -1, 1};
		int r = 1;
		for (int d = 0; d < 6; ++d) {
			r += dfs(i + dx[d], j + dy[d], k + dz[d], col);
		}
		return r;
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