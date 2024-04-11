import java.util.*;
import java.io.*;

public class C {

	List<Integer>[] graph;
	boolean[] vis;

	void go(int u) {
		vis[u] = true;
		addVertex(u);
		for (int t = 0; t < graph[u].size(); t++) {
			int v = graph[u].get(t);
			if (!vis[v]) {
				go(v);
				addVertex(u);
			}
		}
	}

	private void addVertex(int u) {
		result[lastClone].add(u);
		if (result[lastClone].size() == max) {
			lastClone++;
		}
	}
	
	List<Integer>[] result;
	int lastClone = 0;
	int max;
	
	void solve() {
		int n = in.nextInt();
		graph = new List[n];
		for (int i = 0; i < n; i++) {
			graph[i] = new ArrayList<>();
		}
		int m = in.nextInt();
		int k = in.nextInt();
		for (int i = 0; i < m; i++) {
			int from = in.nextInt() - 1, to = in.nextInt() - 1;
			graph[from].add(to);
			graph[to].add(from);
		}
		max = (2 * n  + k - 1) / k;
		vis = new boolean[n];
		result = new List[k];
		for (int i = 0; i < k; i++) {
			result[i] = new ArrayList<>();
		}
		go(0);
		for (int i = 0; i < result.length; i++) {
			if (result[i].size() == 0) {
				result[i].add(0);
			}
			out.print(result[i].size());
			for (int t : result[i]) {
				out.print(" " + (t + 1));
			}
			out.println();
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