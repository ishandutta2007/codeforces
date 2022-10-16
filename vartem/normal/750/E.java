import java.util.*;
import java.io.*;

public class E {
	int INF = Integer.MAX_VALUE / 3;
	int[][] tmp = new int[5][5];

	void combine(int[][] a, int[][] b, int[][] dest) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				tmp[i][j] = INF;
				for (int k = 0; k < 5; k++) {
					tmp[i][j] = Math.min(tmp[i][j], a[i][k] + b[k][j]);
				}
			}
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				dest[i][j] = tmp[i][j];
			}
		}
	}

	int[][][] graphs = new int[10][5][5];

	class SegmentTree {
		int[][][] tree;
		int size;

		public SegmentTree(String s) {
			size = s.length();
			tree = new int[4 * size][5][5];
			build(0, size, s, 0);
		}

		void build(int l, int r, String s, int i) {
			if (l + 1 == r) {
				tree[i] = graphs[s.charAt(l) - '0'];
				return;
			}
			int m = (l + r) >>> 1;
			build(l, m, s, 2 * i + 1);
			build(m, r, s, 2 * i + 2);
			combine(tree[2 * i + 1], tree[2 * i + 2], tree[i]);
		}

		void get(int l, int r, int[][] graph) {
			get(0, size, l, r, graph, 0);
		}

		void get(int left, int right, int l, int r, int[][] graph, int i) {
			if (l <= left && right <= r) {
				combine(graph, tree[i], graph);
				return;
			} else if (r <= left || right <= l) {
				return;
			} else {
				int mid = (left + right) >>> 1;
				get(left, mid, l, r, graph, 2 * i + 1);
				get(mid, right, l, r, graph, 2 * i + 2);
			}
		}
	}

	void prepare() {
		for (int digit = 0; digit < 10; digit++) {
			int[][] g = graphs[digit];
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					g[i][j] = INF;
				}
			}

			for (int i = 0; i < 5; i++) {
				if (i == 0 && digit == 2 || i == 1 && digit == 0 || i == 2 && digit == 1) {
					g[i][i] = 1;
					g[i][i + 1] = 0;
				} else if (i == 3 && digit == 7) {
					g[i][i] = 1;
					g[i][i + 1] = 0;
				} else if (i == 3 && digit == 6) {
					g[i][i] = 1;
				} else if (i == 4 && digit == 6) {
					g[i][i] = 1;
				} else {
					g[i][i] = 0;
				}
			}
		}
	}

	void solve() {
		prepare();
		int n = in.nextInt(), q = in.nextInt();
		String s = in.nextToken();
		SegmentTree st = new SegmentTree(s);
		int[][] result = new int[5][5];
		for (int I = 0; I < q; I++) {
			for (int i = 0; i < 5; i++ ){
				for (int j = 0; j < 5; j++) {
					result[i][j] = INF;
				}
			}
			result[0][0] = 0;
			st.get(in.nextInt() - 1, in.nextInt(), result);
			int r = result[0][4];
			if (r == INF) {
				r = -1;
			}
			out.println(r);
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
		new E().run();
	}
}