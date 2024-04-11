import java.io.*;
import java.util.*;

public class B {

	int n, m;
	ArrayList<Integer>[] g;
	int k;
	int[] s;
	boolean[] used;

	void dfs(int v) {
		used[v] = true;

		for (int j : g[v]) {
			if (!used[j]) {
				dfs(j);
			}
		}

	}

	void solve() throws Exception {
		n = nextInt();
		m = nextInt();
		if (n != m) {
			out.println("NO");
			out.close();
			System.exit(0);
		}
		k = 0;
		s = new int[n];
		used = new boolean[n];
		g = new ArrayList[n];
		for (int i = 0; i < n; i++)
			g[i] = new ArrayList<Integer>();
		for (int i = 0; i < m; i++) {
			int x = nextInt() - 1;
			int y = nextInt() - 1;
			g[x].add(y);
			g[y].add(x);
		}
		dfs(0);
		for (int i = 0; i < n; i++)
			if (!used[i]) {
				out.println("NO");
				out.close();
				System.exit(0);
			};
		out.println("FHTAGN!");
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			// in = new BufferedReader(new FileReader(filename + ".in"));
			// out = new PrintWriter(filename + ".out");

			solve();

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	BufferedReader in;
	StringTokenizer st;
	PrintWriter out;
	final String filename = new String("B").toLowerCase();

	String nextToken() throws Exception {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}

	public static void main(String[] args) {
		new B().run();
	}

}