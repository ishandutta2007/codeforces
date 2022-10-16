import java.io.*;
import java.util.*;

public class D {

	class Edge {
		int from, to;
		int l, r;
		int id;

		public Edge(int from, int to, int l, int r, int id) {
			super();
			this.from = from;
			this.to = to;
			this.l = l;
			this.r = r;
			this.id = id;
		}

		@Override
		public String toString() {
			return "Edge [from=" + from + ", to=" + to + ", l=" + l + ", r="
					+ r + ", id=" + id + "]";
		}
	}

	int n, m;

	public void solve() {
		int n = in.nextInt(), m = in.nextInt();
		this.n = n;
		this.m = m;
		Edge[] edges = new Edge[m];
		for (int i = 0; i < m; i++) {
			int from = in.nextInt() - 1, to = in.nextInt() - 1;
			int l = in.nextInt(), r = in.nextInt();

			edges[i] = new Edge(from, to, l, r, i);
		}

		Edge[] byLeft = edges.clone(), byRight = edges.clone();

		Arrays.sort(byLeft, new Comparator<Edge>() {
			@Override
			public int compare(Edge o1, Edge o2) {
				return o1.l - o2.l;
			}
		});
		Arrays.sort(byRight, new Comparator<Edge>() {
			@Override
			public int compare(Edge o1, Edge o2) {
				return o1.r - o2.r;
			}
		});

		array = new Edge[3 * m];
		pair = new int[3 * m];

		boolean[] isOn = new boolean[m];
		int[] pos = new int[m];

		int left = 0, right = (int) 1e6 + 1;
		while (left < right - 1) {
			int mid = (left + right) / 2;
			Arrays.fill(isOn, false);
			this.size = 0;

			int j = 0;
			for (int i = 0; i < m;) {
				int curL = byLeft[i].l;
				int curR = curL + mid - 1;

				while (j < m && byRight[j].r < curR) {
					int remId = byRight[j].id;
					if (isOn[remId]) {
						isOn[remId] = false;

						array[size] = byRight[j];
						pair[size] = pos[remId];
						pair[pos[remId]] = size;

						size++;
					}
					j++;
				}

				while (i < m && byLeft[i].l == curL) {
					int addId = byLeft[i].id;
					if (byLeft[i].r >= curR) {
						isOn[addId] = true;

						array[size] = byLeft[i];
						pos[addId] = size;
						size++;
					}
					i++;
				}

				array[size++] = null;
			}

			while (j < m) {
				int remId = byRight[j].id;
				if (isOn[remId]) {
					isOn[remId] = false;

					array[size] = byRight[j];
					pair[size] = pos[remId];
					pair[pos[remId]] = size;

					size++;
				}
				j++;
			}

			if (solveDynCon()) {
				left = mid;
			} else {
				right = mid;
			}
		}

		if (left == 0) {
			out.println("Nice work, Dima!");
		} else {
			out.println(left);
		}
	}

	Edge[] array;
	int[] pair;
	int size;

	DSU dsu;
	boolean ans;

	boolean solveDynCon() {
		if (size == 0) {
			return false;
		}
		ans = false;
		this.dsu = new DSU(n);
		solve(0, size);
		return ans;
	}

	void solve(int left, int right) {
		if (left + 1 >= right) {
			if (array[left] == null) {
				ans |= dsu.get(0) == dsu.get(n - 1);
			}
			return;
		}

		int mid = (left + right) >> 1;
		int revision = dsu.ops;

		for (int i = mid; i < right; i++) {
			if (pair[i] < left) {
				Edge e = array[i];
				if (e != null) {
					dsu.union(e.from, e.to);
				}
			}
		}

		solve(left, mid);
		dsu.rollBack(revision);

		for (int i = left; i < mid; i++) {
			if (pair[i] >= right) {
				Edge e = array[i];
				if (e != null) {
					dsu.union(e.from, e.to);
				}
			}
		}
		solve(mid, right);
		dsu.rollBack(revision);
	}

	class DSU {
		int[] parent, rank;

		int[] stack;
		int ops;

		public DSU(int n) {
			parent = new int[n];
			rank = new int[n];

			for (int i = 0; i < n; i++) {
				parent[i] = i;
			}

			stack = new int[6000];
		}

		int get(int n) {
			while (n != parent[n]) {
				n = parent[n];
			}
			return n;
		}

		void union(int a, int b) {
			a = get(a);
			b = get(b);

			if (a == b) {
				return;
			}

			if (rank[a] == rank[b]) {
				rank[a]++;
				stack[ops++] = -(a + 1);
			}

			if (rank[a] > rank[b]) {
				parent[b] = a;
				stack[ops++] = b;
			} else {
				parent[a] = b;
				stack[ops++] = a;
			}
		}

		void rollBack(int size) {
			while (ops > size) {
				ops--;
				int op = stack[ops];
				if (op >= 0) {
					parent[op] = op;
				} else {
					rank[-op - 1]--;
				}
			}
		}
	}

	FastScanner in;
	PrintWriter out;

	public void run() {
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

		public FastScanner(String name) {
			try {
				br = new BufferedReader(new FileReader(name));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
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
		new D().run();
	}
}