import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;

	public void solve() throws IOException {
		int n = nextInt();
		ArrayList<Integer>[][] ls = new ArrayList[n][26];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 26; ++j) {
				ls[i][j] = new ArrayList<Integer>();
			}
			String s = next();
			for (int j = 0; j < s.length(); ++j) {
				ls[i][s.charAt(j) - 'a'].add(j);
			}
		}
		int m = nextInt();
		int[] ids = new int[m];
		for (int i = 0; i < m; ++i) {
			ids[i] = nextInt() - 1;
		}
		String s = next();
		n = s.length();
		int[] x = new int[n + 1];
		Arrays.fill(x, m);
		int[] y = new int[n + 1];
		x[0] = 0;
		for (char c : s.toCharArray()) {
			for (int i = n - 1; i >= 0; --i) {
				if (x[i] == m) {
					continue;
				}
				int u = x[i];
				int v = y[i];
				do {
					int pos = Collections.binarySearch(ls[ids[u]][c - 'a'], v);
					if (pos < 0) {
						pos = -pos - 1;
					}
					if (pos == ls[ids[u]][c - 'a'].size()) {
						u++;
						v = 0;
					} else {
						v = ls[ids[u]][c - 'a'].get(pos) + 1;
						break;
					}
				} while (u < m && u <= x[i + 1]);
				if (u != m && (u < x[i + 1] || u == x[i + 1] && v < y[i + 1])) {
					x[i + 1] = u;
					y[i + 1] = v;
				}
			}
		}
		int ans = n;
		while (x[ans]  == m) {
			--ans;
		}
		out.println(ans);
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