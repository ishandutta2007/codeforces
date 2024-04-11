import java.io.*;
import java.util.*;

public class E {

	final String filename = new String("E").toLowerCase();

	boolean[][] matrix = new boolean[3][3];
	final int MOD = 777_777_777;

	class SegmentTree {
		int size;

		int[][] tree;

		public SegmentTree(int size) {
			this.size = size;
			tree = new int[4 * size][9];
			build(0, size, 0);
		}

		void build(int l, int r, int i) {
			if (l + 1 == r) {
				tree[i][0] = tree[i][4] = tree[i][8] = 1;
				return;
			}
			int mid = (l + r) >> 1;
			build(l, mid, 2 * i + 1);
			build(mid, r, 2 * i + 2);
			merge(i);
		}

		private void merge(int v) {
			int v1 = 2 * v + 1;
			int v2 = 2 * v + 2;
			int[] tv = tree[v];
			int[] tv1 = tree[v1];
			int[] tv2 = tree[v2];

			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					long s = 0;
					for (int k = 0; k < 3; k++) {
						for (int l = 0; l < 3; l++) {
							if (matrix[k][l]) {
								s += (long) tv1[i * 3 + k]
										* (long) tv2[l * 3 + j];
							}
						}
					}
					tv[i * 3 + j] = (int) (s % MOD);
				}
			}
		}

		public void set(int id, int val) {
			set(0, size, id, val, 0);
		}

		private void set(int l, int r, int id, int val, int v) {
			if (l == r - 1) {
				Arrays.fill(tree[v], 0);

				if (val == 0) {
					tree[v][0] = tree[v][4] = tree[v][8] = 1;
				} else {
					tree[v][(val - 1) * 3 + (val - 1)] = 1;
				}
				return;
			}

			int mid = (l + r) >> 1;
			if (id < mid) {
				set(l, mid, id, val, 2 * v + 1);
			} else {
				set(mid, r, id, val, 2 * v + 2);
			}

			merge(v);
		}

		public long getAns() {
			long res = 0;
			for (int i = 0; i < 9; i++) {
				res += tree[0][i];
			}
			return res % MOD;
		}
	}

	void solve() throws Exception {
		int n = nextInt(), m = nextInt();
//		int n = 77777, m = 77777;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				matrix[i][j] = nextInt() == 1;
//				matrix[i][j] = true;
			}
		}
		SegmentTree tree = new SegmentTree(n);
//		Random rng = new Random();
		for (int i = 0; i < m; i++) {
			int ind = nextInt() - 1;
			int val = nextInt();
			tree.set(ind, val);
//			tree.set(rng.nextInt(n), rng.nextInt(4));
			out.println(tree.getAns());
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
		new E().run();
	}

}