import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	int[] time;
	int times = 0;
	private List<Integer>[] edges, qs;
	
	static class DJS {
		int[] p;
		int[] r;
		
		DJS(int n) {
			p = new int[n];
			r = new int[n];
			for (int i = 0; i < n; ++i) {
				p[i] = i;
			}
		}
		
		int get(int i) {
			if (p[i] != i) {
				p[i] = get(p[i]);
			}
			return p[i];
		}
		
		int unite(int i, int j) {
			i = get(i);
			j = get(j);
			if (i == j) {
				return i;
			}
			if (r[i] < r[j]) {
				p[i] = j;
			} else {
				p[j] = i;
			}
			if (r[i] == r[j]) {
				r[i]++;
			}
			return get(i);
		}
	}
	
	DJS comps, sets;

	int compDfs(int i, int p) {
		if (time[i] != -1) {
			return time[i];
		}
		time[i] = times++;
		int ret = time[i];
		for (int j : edges[i]) {
			if (j != p) {
				int val = compDfs(j, i);
				if (val <= time[i]) {
					comps.unite(i, j);
				}
				ret = Math.min(ret, val);
			}
		}
		return ret;
	}
	
	int[] root;
	int[] ans, u, v;
	int[] depth;
	
	void ansDfs(int i, int d) {
		if (depth[i] != -1) {
			throw new AssertionError();
		}
		depth[i] = d;
		for (int j : edges[i]) {
			if (depth[j] == -1) {
				ansDfs(j, d + (comps.get(i) == comps.get(j) ? 0 : 1));
				root[sets.unite(i, j)] = i;
			}
		}
		for (int j : qs[i]) {
			ans[j] += d;
			int o = u[j];
			if (depth[o] != -1) {
				ans[j] = root[sets.get(o)];
			} else {
				throw new AssertionError();
			}
		}
	}

	public void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		edges = new List[n];
		for (int i = 0; i < n; ++i) {
			edges[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < m; ++i) {
			int u = nextInt() - 1;
			int v = nextInt() - 1;
			edges[u].add(v);
			edges[v].add(u);
		}
		time = new int[n];
		Arrays.fill(time, -1);
		comps = new DJS(n);
		compDfs(0, -1);
		qs = new List[n];
		for (int i = 0; i < n; ++i) {
			qs[i] = new ArrayList<Integer>();
		}
		int k = nextInt();
		u = new int[k];
		v = new int[k];
		ans = new int[k];
		Arrays.fill(ans, -1);
		for (int i = 0; i < k; ++i) {
			u[i] = nextInt() - 1;
			v[i] = nextInt() - 1;
			if (time[u[i]] > time[v[i]]) {
				int tmp = u[i];
				u[i] = v[i];
				v[i] = tmp;
			}
			qs[v[i]].add(i);
		}
		sets = new DJS(n);
		root = new int[n];
		depth = new int[n];
		Arrays.fill(depth, -1);
		for (int i = 0; i < n; ++i) {
			root[i] = i;
		}
		ansDfs(0, 0);
//		System.err.println(Arrays.toString(depth));
//		System.err.println(Arrays.toString(ans));
		for (int i = 0; i < k; ++i) {
			out.println(depth[u[i]] + depth[v[i]] - 2 * depth[ans[i]]);
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
	
	static boolean failed = false;
	
	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Solution().run();
	}
	
}