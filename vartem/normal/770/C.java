import java.util.*;
import java.io.*;

public class C {

	int[] color;
	List<Integer>[] graph;
	boolean cycle = false;
	List<Integer> order = new ArrayList<>();

	void dfs(int u) {
		color[u] = 1;
		for (int t = 0; t < graph[u].size(); t++) {
			int v = graph[u].get(t);
			if (color[v] == 1) {
				cycle = true;
			} else if (color[v] == 0) {
				dfs(v);
			}
		}
		color[u] = 2;
		order.add(u);
	}

	void solve() {
		int n = in.nextInt(), k = in.nextInt();
		graph = new List[n + 1];
		for (int i = 0; i <= n; i++) {
			graph[i] = new ArrayList<>();
		}
		for (int i = 0; i < k; i++) {
			graph[n].add(in.nextInt() - 1);
		}
		for (int i = 0; i < n; i++) {
			int d = in.nextInt();
			for (int j = 0; j < d; j++) {
				graph[i].add(in.nextInt() - 1);
			}
		}
		color = new int[n + 1];
		dfs(n);
		if (cycle) {
			out.println(-1);
		} else {
			out.println(order.size() - 1);
			for (int i : order) {
				if (i == n) {
					continue;
				}
				out.print((i + 1) + " ");
			}
		}
	}

	FastScanner in;
	PrintWriter out;

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
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		public String nextToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
				}
			}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(nextToken());
		}

		public long nextLong() {
			return Long.parseLong(nextToken());
		}

		public double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new C().run();
	}
}