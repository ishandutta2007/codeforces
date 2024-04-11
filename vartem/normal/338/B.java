import java.io.*;
import java.util.*;

public class B {

	FastScanner in;
	PrintWriter out;
	final String fileName = "B".toLowerCase();

	List<Integer>[] graph;
	boolean[] isMark;
	int[] deepmost;
	int ans = 0;
	int d;

	void dfs0(int u, int p) {
		deepmost[u] = Integer.MIN_VALUE;
		if (isMark[u]) {
			deepmost[u] = 0;
		}
		for (int v : graph[u]) {
			if (v == p) {
				continue;
			}
			dfs0(v, u);
			deepmost[u] = Math.max(deepmost[u], deepmost[v] + 1);
		}
	}

	void dfs1(int u, int p, int maxUp) {
		if (isMark[u]) {
			maxUp = Math.max(maxUp, 0);
		}
		int max1 = -1, max2 = -1;
		for (int v : graph[u]) {
			if (v == p) {
				continue;
			}
			if (max1 == -1 || deepmost[v] > deepmost[max1]) {
				max2 = max1;
				max1 = v;
			} else if (max2 == -1 || deepmost[v] > deepmost[max2]) {
				max2 = v;
			}
		}

		int dist = maxUp;
		if (max1 != -1) {
			dist = Math.max(dist, deepmost[max1] + 1);
		}
		if (dist <= d) {
			ans++;
		}

		for (int v : graph[u]) {
			if (v == p) {
				continue;
			}

			int maxDown = maxUp + 1;
			if (max1 == v) {
				if (max2 != -1) {
					maxDown = Math.max(maxDown, deepmost[max2] + 2);
				}
			} else {
				maxDown = Math.max(maxDown, deepmost[max1] + 2);
			}
			dfs1(v, u, maxDown);
		}

	}

	void solve() {
		int n = in.nextInt(), m = in.nextInt();
		d = in.nextInt();
		graph = new List[n];
		for (int i = 0; i < n; i++) {
			graph[i] = new ArrayList<>();
		}
		isMark = new boolean[n];
		for (int i = 0; i < m; i++) {
			isMark[in.nextInt() - 1] = true;
		}

		for (int i = 0; i < n - 1; i++) {
			int a = in.nextInt() - 1, b = in.nextInt() - 1;
			graph[a].add(b);
			graph[b].add(a);
		}

		deepmost = new int[n];
		dfs0(0, -1);
		dfs1(0, -1, Integer.MIN_VALUE);
		out.println(ans);
	}

	void run() {
		try {
			in = new FastScanner();
			out = new PrintWriter(System.out);
			solve();
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new B().run();
	}
}