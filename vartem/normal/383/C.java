import java.io.*;
import java.util.*;

public class C {

	List<Integer>[] graph;
	List<Pair>[] changes;
	List<Integer>[] queries;

	long[] ans;

	class Pair {
		int val, time;

		public Pair(int x, int y) {
			super();
			this.val = x;
			this.time = y;
		}
	}
	
	void go(int u, int parent, BIT even, BIT odd) {
		for (int i = 0; i < changes[u].size(); i++) {
			Pair p = changes[u].get(i);
			even.add(p.time, p.val);
		}
		
		for (int i = 0; i < queries[u].size(); i++) {
			int q = queries[u].get(i);
			long sum = even.get(q) - odd.get(q);
			ans[q] = sum;
		}
		
		for (int i = 0; i < graph[u].size(); i++) {
			int v = graph[u].get(i);
			if (v != parent) {
				go(v, u, odd, even);
			}
		}
		for (int i = 0; i < changes[u].size(); i++) {
			Pair p = changes[u].get(i);
			even.add(p.time, -p.val);
		}
	}

	public void solve() {
		int n = in.nextInt(), m = in.nextInt();
		graph = new List[n];
		changes = new List[n];
		queries = new List[n];
		for (int i = 0; i < n; i++) {
			graph[i] = new ArrayList<>();
			changes[i] = new ArrayList<>();
			queries[i] = new ArrayList<>();
		}

		int[] init = new int[n];
		for (int i = 0; i < n; i++) {
			init[i] = in.nextInt();
		}

		for (int i = 0; i < n - 1; i++) {
			int from = in.nextInt() - 1, to = in.nextInt() - 1;
			graph[from].add(to);
			graph[to].add(from);
		}
		ans = new long[m];
		Arrays.fill(ans, Long.MIN_VALUE);

		int[] qs = new int[m];
		for (int i = 0; i < m; i++) {
			int t = in.nextInt();
			if (t == 1) {
				int x = in.nextInt() - 1, val = in.nextInt();
				changes[x].add(new Pair(val, i));
			} else {
				int x = in.nextInt() - 1;
				qs[i] = x;
				queries[x].add(i);
			}
		} 
		
		go(0, -1, new BIT(m), new BIT(m));
		for (int i = 0; i < m; i++) {
			if (ans[i] != Long.MIN_VALUE) {
				out.println(ans[i] + init[qs[i]]);
			}
		}
	}

	class BIT {
		long[] tree;

		public BIT(int n) {
			tree = new long[n];
		}

		long get(int pos) {
			long res = 0;
			while (pos >= 0) {
				res += tree[pos];
				pos = (pos & (pos + 1)) - 1;
			}
			return res;
		}

		void add(int pos, long val) {
			while (pos < tree.length) {
				tree[pos] += val;
				pos |= pos + 1;
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
		new C().run();
	}
}