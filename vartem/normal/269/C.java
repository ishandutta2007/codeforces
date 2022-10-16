import java.io.*;
import java.util.*;

public class C {

	FastScanner in;
	PrintWriter out;
	final String fileName = "C".toLowerCase();

	class Edge {
		int from, to, flow, id;
		int dir;

		public Edge(int from, int to, int flow, int id, int dir) {
			super();
			this.from = from;
			this.to = to;
			this.flow = flow;
			this.id = id;
			this.dir = dir;
		}

	}

	List<Edge>[] graph;

	class Vertex implements Comparable<Vertex> {
		int v;
		long value;

		public Vertex(int v, long value) {
			super();
			this.v = v;
			this.value = value;
		}

		@Override
		public int compareTo(Vertex o) {
			int t = Long.compare(value, o.value);
			if (t == 0) {
				return v - o.v;
			}
			return t;
		}
	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int[] a = new int[m], b = new int[m], c = new int[m];
		graph = new List[n];
		for (int i = 0; i < n; i++) {
			graph[i] = new ArrayList<>();
		}
		long[] sum = new long[n];
		for (int i = 0; i < m; i++) {
			a[i] = in.nextInt() - 1;
			b[i] = in.nextInt() - 1;
			c[i] = in.nextInt();
			graph[a[i]].add(new Edge(a[i], b[i], c[i], i, 1));
			graph[b[i]].add(new Edge(b[i], a[i], c[i], i, -1));
			sum[a[i]] += c[i];
			sum[b[i]] += c[i];
		}

		int[] ans = new int[m];
		Arrays.fill(ans, -1);
		TreeSet<Vertex> q = new TreeSet<>();
		q.add(new Vertex(0, sum[0]));
		boolean[] used = new boolean[n];
		while (!q.isEmpty()) {
			Vertex cur = q.pollFirst();
			System.err.println(cur.v + " " + cur.value);
			used[cur.v] = true;
			for (Edge e : graph[cur.v]) {
				if (!used[e.to]) {
					Vertex next = new Vertex(e.to, sum[e.to]);
					q.remove(next);
					next.value -= 2 * e.flow;
					sum[e.to] -= 2 * e.flow;
					if (e.dir == 1) {
						ans[e.id] = 0;
					} else {
						ans[e.id] = 1;
					}
					if (e.to != n - 1) {
						q.add(next);
					}
				}
			}
		}

		for (int i : ans) {
			out.println(i);
		}
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
		new C().run();
	}
}