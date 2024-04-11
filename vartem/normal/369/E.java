import java.io.*;
import java.util.*;

public class E {

	public void solve() {
		int n = in.nextInt(), m = in.nextInt();
		int[] l = new int[n], r = new int[n];

		int[][] pts = new int[m][];
		for (int i = 0; i < n; i++) {
			l[i] = in.nextInt() - 1;
			r[i] = in.nextInt() - 1;
		}

		int sum = 2 * n;
		for (int j = 0; j < m; j++) {
			int cnt = in.nextInt();
			pts[j] = new int[cnt + 1];
			pts[j][0] = -1;
			for (int k = 0; k < cnt; k++) {
				pts[j][k + 1] = in.nextInt() - 1;
			}
			sum += cnt;
		}

		int[] ptr = new int[m];

		int tmp = 0;
		Event[] events = new Event[sum];
		for (int i = 0; i < n; i++) {
			events[tmp++] = new Event(0, l[i], i);
			events[tmp++] = new Event(2, r[i], i);
		}
		for (int j = 0; j < m; j++) {
			for (int k = 1; k < pts[j].length; k++) {
				events[tmp++] = new Event(1, pts[j][k], j);
			}
		}
		Arrays.sort(events);
//		System.err.println(Arrays.toString(events));
		BIT tree = new BIT(MAX);
		int[] ans = new int[m];

		for (int IT = 0; IT < events.length; IT++) {
			Event e = events[IT];

			if (e.type == 0) {
				tree.add(l[e.id], 1);
			} else if (e.type == 2) {
				tree.add(l[e.id], -1);
			} else {
				int from = pts[e.id][ptr[e.id]] + 1;
				ans[e.id] += tree.get(from, MAX - 1);
				ptr[e.id]++;
			}
		}

		for (int i : ans) {
			out.println(i);
		}
	}

	class BIT {
		int[] tree;

		public BIT(int n) {
			tree = new int[n];
		}

		void add(int pos, int val) {
			while (pos < tree.length) {
				tree[pos] += val;
				pos |= pos + 1;
			}
		}

		int get(int l, int r) {
			int res = get(r);
			if (l > 0) {
				res -= get(l - 1);
			}
			return res;
		}

		int get(int t) {
			int res = 0;
			while (t >= 0) {
				res += tree[t];
				t = (t & (t + 1)) - 1;
			}
			return res;
		}
	}

	final int MAX = (int) 1e6;

	class Event implements Comparable<Event> {
		int type, x;
		int id;

		public Event(int type, int x, int id) {
			super();
			this.type = type;
			this.x = x;
			this.id = id;
		}

		@Override
		public int compareTo(Event o) {
			if (x != o.x) {
				return x - o.x;
			}
			return type - o.type;
		}

		@Override
		public String toString() {
			return "Event [type=" + type + ", x=" + x + ", id=" + id + "]";
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
		new E().run();
	}
}