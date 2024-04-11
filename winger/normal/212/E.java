import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;

	int n;
	List<Integer>[] edges;
	private boolean[] ans;
	private int[] size;
	private boolean[] d;

	public void solve() throws IOException {
		n = nextInt();
		edges = new List[n];
		for (int i = 0; i < n; ++i) {
			edges[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < n - 1; ++i) {
			int u = nextInt() - 1;
			int v = nextInt() - 1;
			edges[u].add(v);
			edges[v].add(u);
		}
		ans = new boolean[n];
		size = new int[n];
		d = new boolean[n];
		dfs(0, -1);
		int count = 0;
		for (int i = 1; i < n - 1; ++i) {
			if (ans[i]) {
				count++;
			}
		}
		out.println(count);
		for (int i = 1; i < n - 1; ++i) {
			if (ans[i]) {
				out.println(i + " " + (n - 1 - i));
			}
		}
	}

	private void dfs(int i, int p) {
		size[i] = 1;
		for (int j : edges[i]) {
			if (j == p) {
				continue;
			}
			dfs(j, i);
			size[i] += size[j];
		}
		Arrays.fill(d, false);
		d[0] = true;
		for (int j : edges[i]) {
			int s = j == p ? edges.length - size[i] : size[j];
			for (int t = d.length - 1; t >= s; --t) {
				d[t] |= d[t - s];
			}
		}
		for (int t = 0; t < d.length; ++t) {
			ans[t] |= d[t];
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