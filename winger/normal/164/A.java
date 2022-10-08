import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	int[] f;
	
	void dfs1(int i, boolean[] col, List<Integer>[] edges) {
		if (col[i]) {
			return;
		}
		col[i] = true;
		for (int j : edges[i]) {
			if (f[j] != 1) {
				dfs1(j, col, edges);
			}
		}
	}
	
	void dfs2(int i, boolean[] col, List<Integer>[] edges) {
		if (col[i]) {
			return;
		}
		col[i] = true;
		for (int j : edges[i]) {
			if (f[j] == 0) {
				dfs2(j, col, edges);
			}
			if (f[j] == 1) {
				col[j] = true;
			}
		}
	}

	public void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		f = new int[n];
		for (int i = 0; i < n; ++i) {
			f[i] = nextInt();
		}
		ArrayList<Integer>[] edges = new ArrayList[n];
		ArrayList<Integer>[] redges = new ArrayList[n];
		for (int i = 0; i < n; ++i) {
			edges[i] = new ArrayList<Integer>();
			redges[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < m; ++i) {
			int u = nextInt() - 1;
			int v = nextInt() - 1;
			edges[u].add(v);
			redges[v].add(u);
		}
		boolean[] col1 = new boolean[n];
		for (int i = 0; i < n; ++i) {
			if (f[i] == 1) {
				dfs1(i, col1, edges);
			}
		}
		boolean[] col2 = new boolean[n];
		for (int i = 0; i < n; ++i) {
			if (f[i] == 2) {
				dfs2(i, col2, redges);
			}
		}
		for (int i = 0; i < n; ++i) {
			out.println(col1[i] & col2[i] ? 1 : 0);
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