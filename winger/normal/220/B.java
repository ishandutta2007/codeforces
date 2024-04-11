import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;

	public void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int[] a = new int[n];
		int[] cs = new int[n + 1];
		for (int i = 0; i < n; ++i) {
			a[i] = nextInt();
			if (a[i] <= n) {
				cs[a[i]]++;
			}
		}
		int[] l = new int[m];
		int[] r = new int[m];
		for (int i = 0; i < m; ++i) {
			l[i] = nextInt() - 1;
			r[i] = nextInt() - 1;
		}
		int[] ans = new int[m];
		int[] c = new int[n + 1];
		for (int x = 1; x <= n; ++x) {
			if (cs[x] < x) {
				continue;
			}
			for (int i = 0; i < n; ++i) {
				c[i + 1] = c[i] + (a[i] == x ? 1 : 0);
			}
			for (int i = 0; i < m; ++i) {
				if (c[r[i] + 1] - c[l[i]] == x) {
					ans[i]++;
				}
			}
		}
		for (int i = 0; i < m; ++i) {
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