import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	ArrayList<Integer>[] edges;
	
	boolean dfs(int i, int t, int[] col, List<Integer> u, List<Integer> v) {
		if (col[i] != 0) {
			return col[i] == t;
		}
		col[i] = t;
		u.add(i);
		for (int j : edges[i]) {
			if (!dfs(j, 3 - t, col, v, u)) {
				return false;
			}
		}
		return true;
	}

	public void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		edges = new ArrayList[n];
		for (int i = 0; i < n; ++i) {
			edges[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < m; ++i) {
			int u = nextInt() - 1;
			int v = nextInt() - 1;
			edges[u].add(v);
			edges[v].add(u);
		}
		List<Integer> u, v;
		u = new ArrayList<Integer>();
		v = new ArrayList<Integer>();
		int[] col0 = new int[n];
		for (int i = 0; i < n; ++i) {
			if (col0[i] == 0) {
				if (!dfs(i, 1, col0, u, v)) {
//					return;
					throw new AssertionError();
				}
			}
		}
		int[] ans = new int[n];
		Arrays.fill(ans, -1);
		if (u.size() % 3 == 0) {
			fill(ans, u);
			fill(ans, v);
			print(ans);
			return;
		}
		if (u.size() % 3 == 2) {
			List<Integer> tmp = u;
			u = v;
			v = tmp;
		}
		List<Integer>[] corr = new ArrayList[n];
		for (int i = 0; i < n; ++i) {
			corr[i] = new ArrayList<Integer>();
		}
		int allv = 0;
		for (int i : v) {
			allv ^= i;
		}
		for (int us : u) {
			if (edges[us].size() <= v.size() - 2) {
				boolean[] col = new boolean[n];
				for (int j : edges[us]) {
					col[j] = true;
				}
				int vs1 = -1, vs2 = -1;
				for (int j : v) {
					if (!col[j]) {
						if (vs1 == -1) {
							vs1 = j;
						} else {
							vs2 = j;
						}
					}
				}
				if (vs2 == -1) {
					throw new AssertionError();
				}
				ans[us] = ans[vs1] = ans[vs2] = 0;
				fill(ans, u);
				fill(ans, v);
				print(ans);
				return;
			}
			if (edges[us].size() == v.size() - 1) {
				int vs = allv;
				for (int j : edges[us]) {
					vs ^= j;
				}
				corr[vs].add(us);
			}
		}
		int ts = 0;
		for (int vs : v) {
			if (corr[vs].size() >= 2) {
				ans[vs] = ans[corr[vs].get(0)] = ans[corr[vs].get(1)] = ts++;
			}
			if (ts == 2) {
				break;
			}
		}
		if (ts < 2) {
			out.println("NO");
			return;
		}
		fill(ans, u);
		fill(ans, v);
		print(ans);
	}

	private void fill(int[] ans, List<Integer> u) {
		int cur = -1;
		for (int i : ans) {
			cur = Math.max(cur, i);
		}
		cur++;
		int curc = 0;
		for (int i : u) {
			if (ans[i] != -1) {
				continue;
			}
			ans[i] = cur;
			curc++;
			if (curc == 3) {
				curc = 0;
				cur++;
			}
		}
		if (curc != 0) {
			throw new AssertionError();
		}
	}

	private void print(int[] ans) {
//		int[] count = new int[ans.length / 3];
//		for (int i = 0; i < ans.length; ++i) {
//			count[ans[i]]++;
//			for (int j : edges[i]) {
//				if (ans[i] == ans[j]) {
//					throw new AssertionError();
//				}
//			}
//		}
//		for (int i : count) {
//			if (i != 3) {
//				throw new AssertionError();
//			}
//		}
		out.println("YES");
		for (int i : ans) {
			out.print((i + 1) + " ");
		}
		out.println();
	}

	public void run() throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		eat("");
		
//		Random rnd = new Random();
//		while (rnd != null) {
//			int n = (rnd.nextInt(10) + 1) * 3;
//			int m = rnd.nextInt(n * (n - 1) / 2);
//			StringBuilder sb = new StringBuilder();
//			sb.append(n + " " + m + "\n");
//			boolean[][] e = new boolean[n][n];
//			for (int i = 0; i < m; ++i) {
//				int u, v;
//				do {
//					u = rnd.nextInt(n);
//					v = rnd.nextInt(n);
//				} while (u == v || e[u][v]);
//				e[u][v] = e[v][u] = true;
//				sb.append((u + 1) + " " + (v + 1) + "\n");
//			}
//			eat(sb.toString());
//			System.err.print(".");
//			solve();
//		}
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