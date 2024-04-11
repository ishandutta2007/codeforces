import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	static abstract class ITree {
		abstract int zero();
		
		abstract int compose(int a, int b);
		
		int[] vals;
		int[] ps;
		int size;
		
		ITree(int[] ps) {
			size = 1;
			while (size < ps.length) {
				size *= 2;
			}
			this.ps = new int[size + 1];
			for (int i = 0; i < ps.length; ++i) {
				this.ps[i] = ps[i];
			}
			for (int i = ps.length; i <= size; ++i) {
				this.ps[i] = 2000000005;
			}
			vals = new int[2 * size - 1];
			Arrays.fill(vals, zero());
		}
		
		void set(int i, int val) {
			set(0, 0, size - 1, i, val);
		}
		
		void set(int n, int nl, int nr, int i, int val) {
			if (nl == nr) {
				if (i != ps[nl]) {
					throw new AssertionError();
				}
				vals[n] = compose(vals[n], val);
				return;
			}
			int mid = (nl + nr) / 2;
			if (i <= ps[mid]) {
				set(2 * n + 1, nl, mid, i, val);
			} else {
				set(2 * n + 2, mid + 1, nr, i, val);
			}
			vals[n] = compose(vals[2 * n + 1], vals[2 * n + 2]);
		}
		
		int get(int l, int r) {
			return get(0, 0, size - 1, l, r);
		}
		
		int get(int n, int nl, int nr, int l, int r) {
			if (l <= ps[nl] && ps[nr] <= r) {
				return vals[n];
			}
			if (nl == nr || r < ps[nl] || ps[nr] < l) {
				return zero();
			}
			int mid = (nl + nr) / 2;
			return compose(
				get(2 * n + 1, nl, mid, l, r),
				get(2 * n + 2, mid + 1, nr, l, r)
			);
		}
	}
	
	static class STree extends ITree {
		STree(int[] ps) {
			super(ps);
		}

		@Override
		int compose(int a, int b) {
			return a + b;
		}

		@Override
		int zero() {
			return 0;
		}
	}
	
	static class MTree extends ITree {
		MTree(int[] ps) {
			super(ps);
		}

		@Override
		int compose(int a, int b) {
			return Math.max(a, b);
		}

		@Override
		int zero() {
			return -1;
		}
	}
	
	int[] unique(int[] a) {
		int[] b = new int[a.length];
		int j = 0;
		for (int i = 0; i < a.length; ++i) {
			if (i == 0 || a[i] != a[i - 1]) {
				b[j++] = a[i];
			}
		}
		return Arrays.copyOf(b, j);
	}
	
	static class Event implements Comparable<Event> {
		int r, t, id;
		int u, v;
		
		@Override
		public int compareTo(Event o) {
			if (r == o.r) {
				return t - o.t;
			}
			return o.r - r;
		}
	}

	public void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		final int[] r = new int[n];
		final int[] a = new int[n];
		for (int i = 0; i < n; ++i) {
			r[i] = nextInt();
		}
		for (int i = 0; i < n; ++i) {
			a[i] = nextInt();
		}
		int[] as = a.clone();
		Arrays.sort(as);
		as = unique(as);
		Integer[] ids = new Integer[n];
		for (int i = 0; i < n; ++i) {
			ids[i] = i;
		}
		Arrays.sort(ids, new Comparator<Integer>() {
			public int compare(Integer u, Integer v) {
				return r[u] - r[v];
			}
		});
		int[] size = new int[n];
		STree stree = new STree(as);
		for (int i = 0; i < n; ) {
			int j = i;
			while (j < n && r[ids[i]] == r[ids[j]]) {
				stree.set(a[ids[j++]], 1);
			}
			for (int t = i; t < j; ++t) {
				size[ids[t]] = stree.get(a[ids[t]] - k, a[ids[t]] + k);
			}
			i = j;
		}
		//System.err.println(Arrays.toString(size));
		int qs = nextInt();
		Event[] evs = new Event[n + qs];
		for (int i = 0; i < n; ++i) {
			evs[i] = new Event();
			evs[i].r = r[i];
			evs[i].id = i;
		}
		for (int i = 0; i < qs; ++i) {
			evs[n + i] = new Event();
			int u = nextInt() - 1;
			int v = nextInt() - 1;
			evs[n + i].t = 1;
			evs[n + i].r = Math.max(r[u], r[v]);
			evs[n + i].id = i;
			evs[n + i].u = Math.max(a[u], a[v]) - k;
			evs[n + i].v = Math.min(a[u], a[v]) + k;
		}
		Arrays.sort(evs);
		int[] ans = new int[qs];
		Arrays.fill(ans, -2);
		MTree mtree = new MTree(as);
		for (Event e : evs) {
			if (e.t == 0) {
				mtree.set(a[e.id], size[e.id]);
			} else {
				ans[e.id] = mtree.get(e.u, e.v);
			}
		}
		for (int i = 0; i < qs; ++i) {
			out.println(ans[i]);
		}
	}

	public void run() throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		eat("");
		
		solve();
		
		out.close();
	}
	
	void eat(String s) {
		st = new StringTokenizer(s);
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
		Locale.setDefault(Locale.US);
		new Solution().run();
	}
	
}