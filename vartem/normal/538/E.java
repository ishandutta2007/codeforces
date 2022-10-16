import java.io.*;
import java.util.*;

public class E {

	FastScanner in;
	PrintWriter out;

	int[] leaves;
	List<Integer>[] graph;
	int[] ans;

	void dfs(int u, int p) {
		boolean isLeaf = true;
		for (int t = 0; t < graph[u].size(); t++) {
			int v = graph[u].get(t);
			if (v == p) {
				continue;
			}
			isLeaf = false;
			dfs2(v, u);
			leaves[u] += leaves[v];
		}
		if (isLeaf) {
			leaves[u] = 1;
			return;
		}

		int sumLower = 0;
		int deg = 0;
		for (int t = 0; t < graph[u].size(); t++) {
			int v = graph[u].get(t);
			if (v == p) {
				continue;
			}
			deg++;
			sumLower += leaves[v] - 1 - ans[v];
		}
		ans[u] = sumLower + deg - 1;
	}

	void dfs2(int u, int p) {
		boolean isLeaf = true;
		for (int t = 0; t < graph[u].size(); t++) {
			int v = graph[u].get(t);
			if (v == p) {
				continue;
			}
			isLeaf = false;
			dfs(v, u);
			leaves[u] += leaves[v];
		}
		if (isLeaf) {
			leaves[u] = 1;
			return;
		}

		int min = Integer.MIN_VALUE;
		for (int t = 0; t < graph[u].size(); t++) {
			int v = graph[u].get(t);
			if (v == p) {
				continue;
			}
			min = Math.max(min, -ans[v]);

		}
		ans[u] = leaves[u] - 1 + min;
	}

	void solve() {
		int n = in.nextInt();
		graph = new List[n];
		for (int i = 0; i < n; i++) {
			graph[i] = new ArrayList<Integer>();
		}

		for (int i = 0; i < n - 1; i++) {
			int u = in.nextInt() - 1, v = in.nextInt() - 1;
			graph[u].add(v);
			graph[v].add(u);
		}

		leaves = new int[n];
		ans = new int[n];
		dfs2(0, -1);
		out.print(ans[0] + 1);
		out.print(' ');

		leaves = new int[n];
		ans = new int[n];
		dfs(0, -1);
		out.println(ans[0] + 1);
	}

	void run() {
		in = new FastScanner();
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new E().run();
	}
}