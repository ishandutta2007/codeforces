import java.util.*;
import java.io.*;

public class F {

	final int[] id = new int[] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	static long[] tmpSum = new long[10];
	static int[] tmpPerm = new int[10];

	class SegmentTree {
		long[][] sum;
		int[][] perm;
		int size;

		public SegmentTree(int[] a) {
			size = a.length;
			sum = new long[4 * size][10];
			perm = new int[4 * size][10];
			build(0, size, a, 0);
		}

		void collect(int i) {
			for (int j = 0; j < 10; j++) {
				sum[i][j] = sum[2 * i + 1][j] + sum[2 * i + 2][j];
			}
		}

		void build(int l, int r, int[] a, int i) {
			perm[i] = id.clone();
			if (l + 1 == r) {
				int cur = a[l];
				long pow10 = 1;
				while (cur != 0) {
					int rem = cur % 10;
					cur /= 10;
					sum[i][rem] += pow10;
					pow10 *= 10;
				}
				return;
			}
			int m = (l + r) / 2;
			build(l, m, a, 2 * i + 1);
			build(m, r, a, 2 * i + 2);
			collect(i);
		}

		void push(int i) {
			int[] t = perm[i];
			apply(2 * i + 1, t);
			apply(2 * i + 2, t);
			for (int j = 0; j < 10; j++) {
				t[j] = j;
			}
		}

		void apply(int pos, int[] t) {
			long[] sum = this.sum[pos];
			int[] perm = this.perm[pos];

			for (int i = 0; i < 10; i++) {
				tmpSum[i] = 0;
			}
			for (int i = 0; i < 10; i++) {
				tmpPerm[i] = t[perm[i]];
				tmpSum[t[i]] += sum[i];
			}
			for (int i = 0; i < 10; i++) {
				sum[i] = tmpSum[i];
				perm[i] = tmpPerm[i];
			}
		}

		void updateOne(int pos, int from, int to) {
			long[] sum = this.sum[pos];
			int[] perm = this.perm[pos];

			long sumFrom = 0;
			for (int i = 0; i < 10; i++) {
				if (perm[i] == from) {
					sumFrom += sum[i];
					perm[i] = to;
					sum[i] = 0;
				}
			}
			sum[to] = sumFrom;
		}

		void change(int l, int r, int from, int to) {
			change(0, size, l, r + 1, from, to, 0);
		}

		void change(int left, int right, int l, int r, int from, int to, int i) {
			if (l <= left && right <= r) {
//				updateOne(i, from, to);
				apply(i, swap);
				return;
			} else if (right <= l || r <= left) {
				return;
			} else {
				push(i);
				int mid = (left + right) >>> 1;
				change(left, mid, l, r, from, to, 2 * i + 1);
				change(mid, right, l, r, from, to, 2 * i + 2);
				collect(i);
			}
		}

		long get(int l, int r) {
			return get(0, size, l, r + 1, 0);
		}

		long get(int left, int right, int l, int r, int i) {
			if (l <= left && right <= r) {
				long result = 0;
				for (int j = 0; j < 10; j++) {
					result += j * sum[i][j];
				}
				return result;
			} else if (right <= l || r <= left) {
				return 0;
			} else {
				push(i);
				int mid = (left + right) >>> 1;
				long result = get(left, mid, l, r, 2 * i + 1) + get(mid, right, l, r, 2 * i + 2);
				collect(i);
				return result;
			}
		}
	}
	int[] swap;
	
	void solve() {
		int n = in.nextInt(), q = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		SegmentTree st = new SegmentTree(a);
		for (int i = 0; i < q; i++) {
			int type = in.nextInt();
			if (type == 1) {
				int l = in.nextInt() - 1, r = in.nextInt() - 1;
				int x = in.nextInt(), y = in.nextInt();
				swap = id.clone();
				swap[x] = y;
				st.change(l, r, x, y);
			} else {
				int l = in.nextInt() - 1, r = in.nextInt() - 1;
				out.println(st.get(l, r));
			}
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
		new F().run();
	}
}