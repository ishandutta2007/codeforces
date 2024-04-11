import java.util.*;
import java.io.*;

public class C {

	class SegmentTree {
		int[] max, add;
		int size;
		public SegmentTree(int n) {
			max = new int[4 * n];
			add = new int[4 * n];
			size = n;
		}
		
		void add(int l, int r, int val) {
			add(0, size, l, r + 1, val, 0);
		}
		
		void add(int left, int right, int l, int r, int val, int i) {
			if (l <= left && right <= r) {
				max[i] += val;
				add[i] += val;
				return;
			} else if (right <= l || r <= left) {
				return;
			} else {
				push(i);
				int mid = (left + right) >>> 1;
				add(left, mid, l, r, val, 2 * i + 1);
				add(mid, right, l, r, val, 2 * i + 2);
				max[i] = Math.max(max[2 * i + 1], max[2 * i + 2]);
			}
		}
		
		void push(int i) {
			if (add[i] != 0) {
				add[2 * i + 1] += add[i];
				max[2 * i + 1] += add[i];
				add[2 * i + 2] += add[i];
				max[2 * i + 2] += add[i];
			}
			add[i] = 0;
		}
		
		int getFirst() {
			return get(0, size, 0);
		}
		
		int get(int left, int right, int i) {
			if (left + 1 == right) {
				return left;
			}
			push(i);
			int mid = (left + right) >>> 1;
			int res;
			if (max[2 * i + 1] > 0) {
				res = get(left, mid, 2 * i + 1);
			} else {
				res = get(mid, right, 2 * i + 2);
			}
			max[i] = Math.max(max[2 * i + 1], max[2 * i + 2]);
			return res;
		}
	}
	
	void solve() {
		int m = in.nextInt();
		SegmentTree st = new SegmentTree(m);
		int[] vals = new int[m];
		for (int i = 0; i < m; i++) {
			int pos = in.nextInt() - 1;
			int type = in.nextInt();
			if (type == 1) {
				vals[pos] = in.nextInt();
				st.add(m - pos - 1, m - 1, 1);
			} else {
				st.add(m - pos - 1, m - 1, -1);
			}
			if (st.max[0] > 0) {
				out.println(vals[m - 1 - st.getFirst()]);
			} else {
				out.println(-1);
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
		new C().run();
	}
}