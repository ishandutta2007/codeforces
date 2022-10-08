import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;
	private static int[] p;
	private static int[] r;
	private Tree[] tree;
	private static int[] qa;
	private static int[] qb;
	private static int[] qans;
	private static Tree[] root;
	
	static class Edge implements Comparable<Edge> {
		int a, b, len;
		
		Edge(int a, int b, int len) {
			this.a = a;
			this.b = b;
			this.len = len;
		}

		public int compareTo(Edge o) {
			return len - o.len;
		}
	}
	
	static class Tree {
		Tree l, r;
		int id;
		int len;
		ArrayList<Integer> qs = new ArrayList<Integer>();
		
		Tree(Tree l, Tree r, int id, int len) {
			this.l = l;
			this.r = r;
			this.id = id;
			this.len = len;
		}

		public int dfs() {
			if (id != -1) {
				for (int q : qs) {
					int o = qa[q] + qb[q] - id;
					if (root[get(o)] != null) {
						qans[q] = root[get(o)].len;
					}
				}
				return id;
			}
			int x = l.dfs();
			root[get(x)] = this;
			return unite(x, r.dfs());
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		p = new int[n];
		r = new int[n];
		for (int i = 0; i < n; ++i) {
			p[i] = i;
		}
		Edge[] es = new Edge[m];
		for (int i = 0; i < m; ++i) {
			es[i] = new Edge(nextInt() - 1, nextInt() - 1, nextInt());
		}
		Arrays.sort(es);
		boolean[] mst = new boolean[m];
		int comps = n;
		long sum = 0;
		for (int i = 0; i < m; ++i) {
			if (get(es[i].a) != get(es[i].b)) {
				mst[i] = true;
				unite(es[i].a, es[i].b);
				comps--;
				sum += es[i].len;
			}
		}
		if (comps > 2) {
			int qs = nextInt();
			for (int i = 0; i < qs; ++i) {
				out.println(-1);
			}
			return;
		}
		if (comps == 2) {
			int qs = nextInt();
			for (int i = 0; i < qs; ++i) {
				out.println(get(nextInt() - 1) == get(nextInt() - 1) ? -1 : sum);
			}
			return;
		}
		tree = new Tree[n];
		for (int i = 0; i < n; ++i) {
			p[i] = i;
			r[i] = 0;
			tree[i] = new Tree(null, null, i, -1);
		}
		int qs = nextInt();
		qa = new int[qs];
		qb = new int[qs];
		qans = new int[qs];
		Arrays.fill(qans, -1);
		for (int i = 0; i < qs; ++i) {
			qa[i] = nextInt() - 1;
			qb[i] = nextInt() - 1;
			tree[qa[i]].qs.add(i);
			tree[qb[i]].qs.add(i);
			while (qa[i] == qb[i]);
		}
		for (int i = 0; i < m; ++i) {
			if (mst[i]) {
				Tree t = new Tree(tree[get(es[i].a)], tree[get(es[i].b)], -1, es[i].len);
				tree[unite(es[i].a, es[i].b)] = t;
			}
		}
		int rr = get(0);
		for (int i = 0; i < n; ++i) {
			p[i] = i;
			r[i] = 0;
		}
		root = new Tree[n];
		tree[rr].dfs();
		for (int i = 0; i < qs; ++i) {
			if (qans[i] == -1) {
				throw new AssertionError();
			}
			out.println(sum - qans[i]);
		}
	}

	private static int unite(int i, int j) {
		i = get(i);
		j = get(j);
		if (r[i] < r[j]) {
			p[i] = j;
		} else {
			p[j] = i;
		}
		if (r[i] == r[j]) {
			++r[i];
		}
		return get(i);
	}

	private static int get(int i) {
		if (p[i] != i) {
			p[i] = get(p[i]);
		}
		return p[i];
	}

	Solution() throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		
		eat("");
		
//		Random rnd = new Random(42);
//		while (rnd != null) {
//			int n = 2;
//			int m = 1;
//			StringBuilder sb = new StringBuilder();
//			sb.append(n + " " + m + "\n");
//			for (int i = 0; i < m; ++i) {
//				int u, v;
//				do {
//					u = rnd.nextInt(n) + 1;
//					v = rnd.nextInt(n) + 1;
//				} while (u == v);
//				sb.append(u + " " + v + " " + rnd.nextInt(10) + "\n");
//			}
//			sb.append(n * (n - 1) / 2 + "\n");
//			for (int i = 0; i < n; ++i) {
//				for (int j = i + 1; j < n; ++j) {
//					sb.append((i + 1) + " " + (j + 1) + "\n");
//				}
//			}
//			st = new StringTokenizer(sb.toString());
//			System.err.println(sb);
//			solve();
//		}
		solve();
		
		in.close();
		out.close();
	}
	
	private void eat(String str) {
		st = new StringTokenizer(str);
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			eat(line);
		}
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	public static void main(String[] args) throws IOException {
		new Solution();
	}
}