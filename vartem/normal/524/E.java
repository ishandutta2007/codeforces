import java.io.*;
import java.util.*;

public class E {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt(), m = in.nextInt(), k = in.nextInt(), q = in
				.nextInt();
		int[] x = new int[k], y = new int[k];
		for (int i = 0; i < k; i++) {
			x[i] = in.nextInt() - 1;
			y[i] = in.nextInt() - 1;
		}
		int[] x1 = new int[q], x2 = new int[q], y1 = new int[q], y2 = new int[q];
		for (int i = 0; i < q; i++) {
			x1[i] = in.nextInt() - 1;
			y1[i] = in.nextInt() - 1;
			x2[i] = in.nextInt() - 1;
			y2[i] = in.nextInt() - 1;
		}
		boolean[] ans = new boolean[q];
		for (int rot = 0; rot < 2; rot++) {
			List<Event> events = new ArrayList<>();

			for (int i = 0; i < k; i++) {
				events.add(new Event(x[i], 0, i));
			}
			for (int i = 0; i < q; i++) {
				events.add(new Event(x2[i], 1, i));
			}
			Collections.sort(events);

			SegmentTree st = new SegmentTree(m);
			for (Event e : events) {
				if (e.type == 0) {
					st.set(y[e.id], x[e.id]);
				} else {
					int from = y1[e.id], to = y2[e.id];
					int min = st.get(from, to);
					if (min >= x1[e.id]) {
						ans[e.id] = true;
					}
				}
			}

			for (int i = 0; i < k; i++) {
				int tmp = x[i];
				x[i] = y[i];
				y[i] = tmp;
			}
			for (int i = 0; i < q; i++) {
				int tmp = x1[i];
				x1[i] = y1[i];
				y1[i] = tmp;

				tmp = x2[i];
				x2[i] = y2[i];
				y2[i] = tmp;
			}
			
			int tmp = n;
			n = m;
			m = tmp;
		}

		for (int i = 0; i < q; i++) {
			out.println(ans[i] ? "YES" : "NO");
		}
	}

	class Event implements Comparable<Event> {
		int pos, type;
		int id;

		public Event(int pos, int type, int id) {
			super();
			this.pos = pos;
			this.type = type;
			this.id = id;
		}

		@Override
		public int compareTo(Event o) {
			int t = Integer.compare(pos, o.pos);
			if (t == 0) {
				return Integer.compare(type, o.type);
			}
			return t;
		}
	}

	class SegmentTree {
		int[] min;
		int size;

		public SegmentTree(int n) {
			min = new int[4 * n];
			Arrays.fill(min, -1);
			size = n;
		}

		void set(int pos, int val) {
			set(0, size, pos, val, 0);
		}

		void set(int left, int right, int pos, int val, int i) {
			if (left + 1 == right) {
				min[i] = val;
				return;
			}
			int mid = (left + right) >> 1;
			if (pos < mid) {
				set(left, mid, pos, val, 2 * i + 1);
			} else {
				set(mid, right, pos, val, 2 * i + 2);
			}
			min[i] = Math.min(min[2 * i + 1], min[2 * i + 2]);
		}

		int get(int l, int r) {
			return get(0, size, l, r + 1, 0);
		}

		int get(int left, int right, int l, int r, int i) {
			if (l <= left && right <= r) {
				return min[i];
			}
			if (right <= l || r <= left) {
				return Integer.MAX_VALUE;
			}
			int mid = (left + right) >> 1;
			int ans1 = get(left, mid, l, r, 2 * i + 1);
			int ans2 = get(mid, right, l, r, 2 * i + 2);
			return Math.min(ans1, ans2);
		}
	}

	class BIT {
		int[] tree;

		public BIT(int n) {
			tree = new int[n];
		}

		int get(int from, int to) {
			int res = get(to);
			if (from > 0) {
				res -= get(from - 1);
			}
			return res;
		}

		int get(int pos) {
			int res = 0;
			while (pos >= 0) {
				res += tree[pos];
				pos = (pos & (pos + 1)) - 1;
			}
			return res;
		}

		void add(int pos) {
			while (pos < tree.length) {
				tree[pos]++;
				pos |= pos + 1;
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

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
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
		new E().run();
	}
}