import java.io.*;
import java.util.*;

public class C {

	final String filename = new String("C").toLowerCase();

	ArrayList<Edge>[] graph;

	class Edge {
		int from, to, w;

		public Edge(int from, int to, int w) {
			this.from = from;
			this.to = to;
			this.w = w;
		}
	}
	
	int gcd(int a, int b) {
		if (a == 0) {
			return b;
		}
		return gcd(b % a, a);
	}
	
	void dfs(int u, int[] color, boolean[] used, int c) {
		used[u] = true;
		color[u] = c;
		for (Edge e : graph[u]) {
			if (!used[e.to]) {
				dfs(e.to, color, used, c + e.w);
			}
		}
	}

	void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		graph = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			graph[i] = new ArrayList<Edge>();
		}
		Edge[] edges = new Edge[m];
		for (int i = 0; i < m; i++) {
			int x = nextInt() - 1;
			int y = nextInt() - 1;
			graph[x].add(new Edge(x, y, 1));
			graph[y].add(new Edge(y, x, -1));
		}

		int[] color = new int[n];
		boolean[] used = new boolean[n];
		for (int i = 0; i < n; i++) {
			if (!used[i]) {
				dfs(i, color, used, 0);
			}
		}
		
		int ans = -1;
		for (int i = 0; i < n; i++) {
			for (Edge e : graph[i]) {
				int c1 = color[e.from];
				int c2 = color[e.to];
				if (c1 + e.w != c2) {
					int res = Math.abs(c2 - c1 - e.w);
					if (ans == -1) {
						ans = res;
					} else {
						ans = gcd(ans, res);
					}
				}
			}
		}
		if (ans == -1) {
			out.println(n);
		} else {
			out.println(ans);
		}
	}

	void run() {
		try {
//			in = new BufferedReader(new FileReader(filename + ".in"));
//			out = new PrintWriter(filename + ".out");
			 in = new BufferedReader(new InputStreamReader(System.in));
			 out = new PrintWriter(System.out);

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
		new C().run();
	}

}