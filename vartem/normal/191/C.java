import java.io.*;
import java.util.*;

public class C {

	final String filename = new String("C").toLowerCase();

	ArrayList<Edge>[] graph;

	class Edge {
		int from, to, id;

		public Edge(int from, int to, int id) {
			super();
			this.from = from;
			this.to = to;
			this.id = id;
		}
	}

	List<Integer>[] queries;
	int[] ans;
	boolean[] used;
	
	Set<Integer> dfs(int u) {
		used[u] = true;
		Set<Integer> currentQs = new HashSet<Integer>(queries[u]);
		for (Edge e : graph[u]) {
			if (!used[e.to]) {
				Set<Integer> newQs = dfs(e.to);
				ans[e.id] = newQs.size();
				if (newQs.size() > currentQs.size()) {
					Set<Integer> tmp = newQs;
					newQs = currentQs;
					currentQs = tmp;
				}
				for (int i : newQs) {
					if (currentQs.contains(i)) {
						currentQs.remove(i);
					} else {
						currentQs.add(i);
					}
				}
			}
		}
		return currentQs;
	}

	void solve() throws Exception {
		int n = nextInt();
		graph = new ArrayList[n];
		queries = new List[n];
		for (int i = 0; i < n; i++) {
			graph[i] = new ArrayList<Edge>();
			queries[i] = new ArrayList<Integer>();
		}
		used = new boolean[n];
		for (int i = 0; i < n - 1; i++) {
			int x = nextInt() - 1;
			int y = nextInt() - 1;
			graph[x].add(new Edge(x, y, i));
			graph[y].add(new Edge(y, x, i));
		}
		int k = nextInt();
		for (int i = 0; i < k; i++) {
			int x = nextInt() - 1;
			int y = nextInt() - 1;
			if (x == y) {
				continue;
			}
			queries[x].add(i);
			queries[y].add(i);
		}
		ans = new int[n - 1];
		
		dfs(0);
		for (int i = 0; i < n - 1; i++) {
			out.print(ans[i] + " ");
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