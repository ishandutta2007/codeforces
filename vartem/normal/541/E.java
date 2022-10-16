import java.io.*;
import java.util.*;

public class E {

	FastScanner in;
	PrintWriter out;

	List<Integer>[] graph;

	int[] color;
	boolean ok = true;

	void dfs(int u, int c) {
		color[u] = c;
		for (int t = 0; t < graph[u].size(); t++) {
			int v = graph[u].get(t);
			if (color[v] == color[u]) {
				ok = false;
			} else if (color[v] == -1) {
				dfs(v, 1 - c);
			}
		}
	}

	void solve() {
		int n = in.nextInt();
		graph = new List[n];
		for (int i = 0; i < n; i++) {
			graph[i] = new ArrayList<>();
		}
		int m = in.nextInt();
		for (int i = 0; i < m; i++) {
			int from = in.nextInt() - 1, to = in.nextInt() - 1;
			graph[from].add(to);
			graph[to].add(from);
		}
		color = new int[n];
		Arrays.fill(color, -1);
		for (int i = 0; i < n; i++) {
			if (color[i] == -1) {
				dfs(i, 0);
			}
		}

		if (!ok) {
			out.println("-1");
			return;
		}

		int ans = 0;

		Arrays.fill(color, -1);
		int[] dist = new int[n];
		int[] queue = new int[n];
		int head, tail;
		for (int i = 0; i < n; i++) {
			if (color[i] == -1) {
				dfs(i, 0);
				int mx = 0;
				for (int j = 0; j < n; j++) {
					if (color[j] == 0 || color[j] == 1) {
						Arrays.fill(dist, -1);
						dist[j] = 0;
						head = 0;
						tail = 1;
						queue[0] = j;
						while (head < tail) {
							int cur = queue[head++];
							for (int t = 0; t < graph[cur].size(); t++) {
								int next = graph[cur].get(t);
								if (dist[next] == -1) {
									dist[next] = dist[cur] + 1;
									queue[tail++] = next;
								}
							}
						}
						mx = Math.max(mx, dist[queue[tail - 1]]);
						
						color[j] = 2;
					}
				}
				ans += mx;
			}
		}
		out.println(ans);
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