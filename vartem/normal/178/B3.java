import java.io.*;
import java.util.*;

public class B {

	final String filename = new String("B").toLowerCase();

	class Edge {
		int from, to, id;

		public Edge(int from, int to, int id) {
			this.from = from;
			this.to = to;
			this.id = id;
		}

	}

	ArrayList<Edge>[] graph;
	Stack<Integer> stack;
	int[] color, ret, enter;
	int time;
	int[] comp;
	int curComp;

	void dfs(int v, int parent) {
		color[v] = 1;
		stack.push(v);
		ret[v] = enter[v] = time++;
		for (Edge u : graph[v]) {
			if (color[u.to] == 0) {
				dfs(u.to, v);
				ret[v] = Math.min(ret[v], ret[u.to]);
				if (ret[u.to] > enter[v]) {
					while (stack.peek() != u.to) {
						int tmp = stack.pop();
						comp[tmp] = curComp;
					}
					comp[stack.pop()] = curComp;
					curComp++;
				}
			} else {
				if (u.to == parent)
					continue;
				ret[v] = Math.min(ret[v], enter[u.to]);
			}
		}
	}

	ArrayList<Integer>[] newGraph;
	List<Integer> eulerPath;
	int[] depth;

	class SegmentTree {
		int[] tree;
		int size;
		List<Integer> seq;
		int[] depth;

		public SegmentTree(int n, int[] depth, List<Integer> eulerPath) {
			this.seq = eulerPath;
			this.depth = depth;
			this.size = eulerPath.size();
			this.tree = new int[4 * size];
			buildTree(0, size, 0);
		}

		private void buildTree(int left, int right, int i) {
			if (left + 1 == right) {
				tree[i] = eulerPath.get(left);
				return;
			}

			int mid = (left + right) >> 1;
			buildTree(left, mid, 2 * i + 1);
			buildTree(mid, right, 2 * i + 2);
			if (depth[tree[2 * i + 1]] < depth[tree[2 * i + 2]]) {
				tree[i] = tree[2 * i + 1];
			} else {
				tree[i] = tree[2 * i + 2];
			}
		}

		public int getMin(int l, int r) {
			return getMin(0, size, l, r + 1, 0);
		}

		private int getMin(int left, int right, int l, int r, int i) {
			if (l <= left && right <= r) {
				return tree[i];
			}
			int mid = (left + right) >> 1;
			if (r <= mid) {
				return getMin(left, mid, l, r, 2 * i + 1);
			}
			if (l >= mid) {
				return getMin(mid, right, l, r, 2 * i + 2);
			}
			int ans1 = getMin(left, mid, l, mid, 2 * i + 1);
			int ans2 = getMin(mid, right, mid, r, 2 * i + 2);
			if (depth[ans1] < depth[ans2]) {
				return ans1;
			} else {
				return ans2;
			}
		}
	}

	void dfs2(int u, int parent, int d) {
		depth[u] = d;
		enter[u] = time++;
		eulerPath.add(u);
		for (int v : newGraph[u]) {
			if (v != parent) {
				dfs2(v, u, d + 1);
				eulerPath.add(u);
				time++; 	
			}
		}
	}

	void solve() throws Exception {
		int n = nextInt();
		graph = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			graph[i] = new ArrayList<Edge>();
		}

		int m = nextInt();
		for (int i = 0; i < m; i++) {
			int x = nextInt() - 1;
			int y = nextInt() - 1;
			graph[x].add(new Edge(x, y, i));
			graph[y].add(new Edge(y, x, i));
		}

		time = 0;
		ret = new int[n];
		color = new int[n];
		enter = new int[n];
		comp = new int[n];
		stack = new Stack<Integer>();
		curComp = 0;
		for (int i = 0; i < n; i++) {
			if (color[i] == 0) {
				dfs(i, -1);
				while (!stack.isEmpty()) {
					int tmp = stack.pop();
					comp[tmp] = curComp;
				}
				curComp++;
			}
		}
		int countComps = curComp;
		newGraph = new ArrayList[countComps];
		for (int i = 0; i < countComps; i++) {
			newGraph[i] = new ArrayList<Integer>();
		}

		for (int i = 0; i < n; i++) {
			for (Edge e : graph[i]) {
				int st = comp[e.from];
				int fin = comp[e.to];
				if (st != fin) {
					newGraph[st].add(fin);
				}
			}
		}
		depth = new int[countComps];
		eulerPath = new ArrayList<Integer>();
		time = 0;
		enter = new int[countComps];
		dfs2(0, -1, 0);

		SegmentTree rmq = new SegmentTree(countComps, depth, eulerPath);
		int k = nextInt();
		for (int i = 0; i < k; i++) {
			int x = comp[nextInt() - 1];
			int y = comp[nextInt() - 1];
			int left = Math.min(enter[x], enter[y]);
			int right = Math.max(enter[x], enter[y]);
			int lca = rmq.getMin(left, right);
			out.println(depth[x] + depth[y] - 2 * depth[lca]);
		}
	}


	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			// in = new BufferedReader(new FileReader("input.txt"));
			// out = new PrintWriter("output.txt");

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
		new B().run();
	}

}