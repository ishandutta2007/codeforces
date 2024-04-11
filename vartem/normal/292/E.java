import java.io.*;
import java.util.*;

public class E {

	FastScanner in;
	PrintWriter out;
	final String fileName = "E".toLowerCase();
	
	class SegmentTree {
		int[] tree;
		int[] set;
		int size;
		
		public SegmentTree(int n) {
			this.size = n;
			this.tree = new int[4 * n];
			this.set = new int[4 * n];
		}
		
		public void set(int l, int r, int value) {
			set(0, size, l, r, value, 0);
		}
		
		void set(int left, int right, int l, int r, int value, int i) {
			if (l <= left && right <= r) {
				tree[i] = value;
				set[i] = value;
				return;
			}
			
			if (right <= l || r <= left) {
				return;
			}
			
			give(i);
			int mid = (left + right) >> 1;
			set(left, mid, l, r, value, 2 * i + 1);
			set(mid, right, l, r, value, 2 * i + 2);
		}

		private void give(int i) {
			if (set[i] == 0) {
				return;
			}
			set[2 * i + 1] = set[2 * i + 2] = set[i];
			tree[2 * i + 1] = tree[2 * i + 2] = set[i];
			set[i] = 0;
		}
		
		int get(int pos) {
			return get(0, size, pos, 0);
		}
		
		int get(int left, int right, int pos, int i) {
			if (left == right - 1) {
				set[i] = 0;
				return tree[i];
			}
			
			give(i);
			int mid = (left + right) >> 1;
			if (pos < mid) {
				return get(left, mid, pos, 2 * i + 1);
			} else {
				return get(mid, right, pos, 2 * i + 2);
			}
		}
	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int[] a = new int[n], b = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		for (int i = 0; i < n; i++) {
			b[i] = in.nextInt();
		}
		
		SegmentTree tree = new SegmentTree(n);
		int[] x = new int[m + 1], y = new int[m + 1], k = new int[m + 1];
		for (int i = 1; i <= m; i++) {
			int type = in.nextInt();
			if (type == 1) {
				x[i] = in.nextInt() - 1;
				y[i] = in.nextInt() - 1;
				k[i] = in.nextInt();
				
				tree.set(y[i], y[i] + k[i], i);
			} else {
				int pos = in.nextInt() - 1;
				int query = tree.get(pos);
				if (query == 0) {
					out.println(b[pos]);
				} else {
					pos = (pos - y[query]) + x[query];
					out.println(a[pos]);
				}
			}
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
		new E().run();
	}
}