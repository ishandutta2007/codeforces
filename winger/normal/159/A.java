import java.io.*;
import java.util.*;

public class Solution {

	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;

	HashMap<String, Integer> map = new HashMap<String, Integer>();
	ArrayList<String> names = new ArrayList<String>();
	
	int f(String s) {
		if (!map.containsKey(s)) {
			map.put(s, map.size());
			names.add(s);
		}
		return map.get(s);
	}
	
	public void solve() throws IOException {
		int m = nextInt();
		int d = nextInt();
		int[] u = new int[m];
		int[] v = new int[m];
		int[] t = new int[m];
		for (int i = 0; i < m; ++i) {
			u[i] = f(next());
			v[i] = f(next());
			t[i] = nextInt();
		}
		int n = map.size();
		boolean[][] g = new boolean[n][n];
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < m; ++j) {
				if (u[i] == v[j] && u[j] == v[i] && t[i] < t[j] && t[j] <= t[i] + d) {
					g[u[i]][v[i]] = true;
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (g[i][j] || g[j][i]) {
					ans++;
				}
			}
		}
		out.println(ans);
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (g[i][j] || g[j][i]) {
					out.println(names.get(i) + " " + names.get(j));
				}
			}
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