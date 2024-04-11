import java.util.*;
import java.io.*;

public class D2 {

	class Edge {
		int to, type;

		public Edge(int to, int type) {
			super();
			this.to = to;
			this.type = type;
		}

	}

	void solve() {
		int n = in.nextInt(), m = in.nextInt();
		List<Edge>[] graph = new List[n];
		for (int i = 0; i < n; i++) {
			graph[i] = new ArrayList<>();
		}

		for (int i = 0; i < m; i++) {
			int from = in.nextInt() - 1, to = in.nextInt() - 1, type = in.nextInt();
			graph[from].add(new Edge(to, type));
		}

		int MAX = 62;
		BitSet[][] can = new BitSet[2][n];
		BitSet[][] newCan = new BitSet[2][n];
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				can[i][j] = new BitSet(n);
				newCan[i][j] = new BitSet(n);
				
			}
		}
		for (int i = 0; i < n; i++) {
			for (Edge e : graph[i]) {
				can[e.type][i].set(e.to, true);
			}
		}
		long[][] longest = new long[2][n];
		long[][] newLongest = new long[2][n];
		for (int i = 0; i < n; i++) {
			for (Edge e : graph[i]) {
				longest[e.type][i] = 1;
				newLongest[e.type][i] = 1;
			}
		}
		for (int layer = 0; layer < MAX - 1; layer++) {
			long len = 1L << layer;
			for (int type = 0; type < 2; type++) {
				for (int i = 0; i < n; i++) {
					for (int mid = 0; mid < n; mid++) {
						if (!can[type][i].get(mid)) {
							continue;
						}
						newLongest[type][i] = Math.max(newLongest[type][i], len + longest[1 - type][mid]);
						newCan[type][i].or(can[1 - type][mid]);
					}
				}
			}
			for (int type = 0; type < 2; type++) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						can[type][i].set(j, newCan[type][i].get(j));
					}
					newCan[type][i].clear();
					longest[type][i] = newLongest[type][i];
				}
			}
		}

		long max = 0;
		for (int i = 0; i < n; i++) {
			max = Math.max(max, longest[0][i]);
		}
		if (max > 1000000_000000_000000L) {
			max = -1;
		}
		out.println(max);
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
		new D2().run();
	}
}