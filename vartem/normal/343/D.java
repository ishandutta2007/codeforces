import java.io.*;
import java.util.*;

public class D {

	FastScanner in;
	PrintWriter out;

	List<Integer>[] graph;

	class SegmentTree {
		int[] tree;
		int[] set;
		int size;

		public SegmentTree(int n) {
			this.size = n;
			tree = new int[4 * size];
			set = new int[4 * size];
			Arrays.fill(set, -1);
		}

		public void set(int l, int r, int val) {
			set(0, size, l, r + 1, val, 0);
		}

		void set(int left, int right, int l, int r, int val, int i) {
			give(i, left, right);
			if (l <= left && right <= r) {
				setValue(i, left, right, val);
			} else if (r <= left || right <= l) {
				return;
			} else {
				int mid = (left + right) >> 1;
				set(left, mid, l, r, val, 2 * i + 1);
				set(mid, right, l, r, val, 2 * i + 2);
				gather(i, left, right);
			}
		}

		private void gather(int i, int left, int right) {
			tree[i] = Math.max(tree[2 * i + 1], tree[2 * i + 2]);
		}

		private void setValue(int i, int left, int right, int val) {
			tree[i] = val;
			set[i] = val;
		}

		private void give(int i, int left, int right) {
			if (set[i] == -1) {
				return;
			}
			
			int mid = (left + right) >> 1;
			if (left + 1 != right) {
				setValue(2 * i + 1, left, mid, set[i]);
				setValue(2 * i + 2, mid, right, set[i]);
			}
			set[i] = -1;
		}
		
		public int max(int l, int r) {
			return max(0, size, l, r + 1, 0);
		}

		int max(int left, int right, int l, int r, int i) {
			give(i, left, right);
			if (l <= left && right <= r) {
				return tree[i];
			} else if (r <= left || right <= l) {
				return 0;
			} else {
				int mid = (left + right) >> 1;
				int max1 = max(left, mid, l, r, 2 * i + 1);
				int max2 = max(mid, right, l, r, 2 * i + 2);
				gather(i, left, right);
				return Math.max(max1, max2);
			}
		}
	}

	int time;
	int[] inTime, outTime;

	void dfs(int u, int p) {
		time++;
		inTime[u] = time;
		for (int v : graph[u]) {
			if (v == p) {
				continue;
			}
			dfs(v, u);
		}

		outTime[u] = time;
	}

	void solve() {
		int n = in.nextInt();
		graph = new List[n];
		for (int i = 0; i < n; i++) {
			graph[i] = new ArrayList<>();
		}

		for (int i = 0; i < n - 1; i++) {
			int a = in.nextInt() - 1, b = in.nextInt() - 1;
			graph[a].add(b);
			graph[b].add(a);
		}
		
		time = -1;
		inTime = new int[n];
		outTime = new int[n];
		dfs(0, -1);

		int q = in.nextInt();
		SegmentTree treeSubTree = new SegmentTree(n),
					treeParent = new SegmentTree(n);
		
		int[] c = new int[q + 1], v = new int[q + 1];
		
		for (int i = 1; i <= q; i++) {
			c[i] = in.nextInt();
			v[i] = in.nextInt() - 1;
			
			int from = inTime[v[i]], to = outTime[v[i]];
			if (c[i] == 1) {
				treeSubTree.set(from, to, i);
			} else if (c[i] == 2) {
				treeParent.set(from, from, i);
			} else {
				int maxQ1 = treeSubTree.max(from, from);
				int maxQ2 = treeParent.max(from, to);
				int maxQ = Math.max(maxQ1, maxQ2);
				if (maxQ == 0 || c[maxQ] == 2) {
					out.println(0);
				} else {
					out.println(1);
				}
			}
		}
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

		String nextToken() {
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
		new D().run();
	}
}