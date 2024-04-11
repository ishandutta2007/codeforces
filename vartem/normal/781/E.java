import java.util.*;
import java.io.*;

public class E {

	long MOD = 1_000_000_007;

	int h, w, n;
	int[] u, l, r, s;

	class Segment implements Comparable<Segment> {
		int u, l, r, s;

		public Segment(int u, int l, int r, int s) {
			super();
			this.u = u;
			this.l = l;
			this.r = r;
			this.s = s;
		}

		@Override
		public int compareTo(Segment o) {
			return Integer.compare(u, o.u);
		}
	}

	class Event implements Comparable<Event> {
		int val, i, type;

		public Event(int val, int i, int type) {
			this.val = val;
			this.i = i;
			this.type = type;
		}

		@Override
		public int compareTo(Event o) {
			if (val != o.val) {
				return val - o.val;
			}
			return type - o.type;
		}
	}

	Comparator<Integer> comp = new Comparator<Integer>() {

		@Override
		public int compare(Integer o1, Integer o2) {
			return u[o1] - u[o2];
		}
	};

	class SegmentTree {
		TreeSet<Integer>[] tree;
		int size;

		public SegmentTree(int n) {
			size = n;
			tree = new TreeSet[4 * n];
		}

		void add(int l, int r, int ind) {
			add(0, size, l, r, ind, 0);
		}

		void add(int left, int right, int l, int r, int ind, int i) {
			if (l <= left && right <= r) {
				if (tree[i] == null) {
					tree[i] = new TreeSet<>(comp);
				}
				tree[i].add(ind);
				return;
			} else if (r <= left || right <= l) {
				return;
			} else {
				int mid = (left + right) >>> 1;
				add(left, mid, l, r, ind, 2 * i + 1);
				add(mid, right, l, r, ind, 2 * i + 2);
			}
		}

		void rem(int l, int r, int ind) {
			rem(0, size, l, r, ind, 0);
		}

		void rem(int left, int right, int l, int r, int ind, int i) {
			if (l <= left && right <= r) {
				tree[i].remove(ind);
				return;
			} else if (r <= left || right <= l) {
				return;
			} else {
				int mid = (left + right) >>> 1;
				rem(left, mid, l, r, ind, 2 * i + 1);
				rem(mid, right, l, r, ind, 2 * i + 2);
			}
		}

		int get(int pos) {
			return get(0, size, pos, 0);
		}

		int get(int left, int right, int pos, int i) {
			if (left + 1 == right) {
				if (tree[i] == null || tree[i].size() == 0) {
					return -1;
				}
				return tree[i].last();
			}
			int cur = (tree[i] == null || tree[i].size() == 0) ? -1 : tree[i].last();
			int mid = (left + right) >>> 1;
			int cur2;
			if (pos < mid) {
				cur2 = get(left, mid, pos, 2 * i + 1);
			} else {
				cur2 = get(mid, right, pos, 2 * i + 2);
			}
			return better(cur, cur2);
		}

		int better(int a, int b) {
			if (a == -1)
				return b;
			if (b == -1) {
				return a;
			}
			return u[a] > u[b] ? a : b;
		}
	}

	void solve() {
		h = in.nextInt();
		w = in.nextInt();
		n = in.nextInt();
		u = new int[n];
		l = new int[n];
		r = new int[n];
		s = new int[n];
		Segment[] seg = new Segment[n];
		for (int i = 0; i < n; i++) {
			seg[i] = new Segment(in.nextInt() - 1, in.nextInt() - 1, in.nextInt() - 1, in.nextInt());
		}
		Arrays.sort(seg);

		for (int i = 0; i < n; i++) {
			u[i] = seg[i].u;
			l[i] = seg[i].l;
			r[i] = seg[i].r;
			s[i] = seg[i].s;
		}
		int[] next = new int[2 * n];
		Arrays.fill(next, -1);
		List<Event> events = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			events.add(new Event(u[i], i, 1));
			events.add(new Event(u[i] + s[i] + 1, i, -1));
		}
		Collections.sort(events);
		SegmentTree st = new SegmentTree(w);

		for (Event e : events) {
			int id = e.i;
			if (e.val > h) {
				break;
			}
			if (e.type == 1) {
				int lft = l[id] == 0 ? r[id] + 1 : l[id] - 1;
				int rgt = r[id] + 1 == w ? l[id] - 1 : r[id] + 1;

				next[id * 2] = st.get(lft);
				next[id * 2 + 1] = st.get(rgt);

				st.add(l[id], r[id] + 1, id);
			} else {
				st.rem(l[id], r[id] + 1, id);
			}
		}

		long[] dp = new long[n];
		long result = 0;

		for (int i = 0; i < w; i++) {
			int id = st.get(i);
			if (id == -1) {
				result++;
			} else {
				dp[id]++;
			}
		}

		for (int i = n - 1; i >= 0; i--) {
			long val = dp[i];
			for (int k = 0; k < 2; k++) {
				if (next[2 * i + k] == -1) {
					result += val;
				} else {
					dp[next[2 * i + k]] += val;
					if (dp[next[2 * i + k]] >= MOD) {
						dp[next[2 * i + k]] -= MOD;
					}
				}
			}
		}
		out.println(result % MOD);
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