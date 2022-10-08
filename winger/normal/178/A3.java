import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;

	int[] a;
	int[] d;
	
	long dfs(int i, int last, int dd) {
		if (dd >= d[i]) {
			return 0;
		}
		long ret = (long)(d[i] - dd) * a[i];
		d[i] = dd;
		for (int j = 1; j <= i && j < last; j *= 2) {
			ret += dfs(i - j, j, dd + 1);
		}
		return ret;
	}

	public void solve() throws IOException {
		int n = nextInt();
		a = new int[n];
		d = new int[n];
		for (int i = 0; i < n; ++i) {
			a[i] = nextInt();
		}
		Arrays.fill(d, 1000000000);
		d[n - 1] = 0;
		long[] ans = new long[n];
		for (int i = n - 1; i >= 0; --i) {
			for (int j = 1; j <= i; j *= 2) {
				d[i - j] = Math.min(d[i - j], d[i] + 1);
			}
			ans[n - 1] += (long)a[i] * d[i]; 
		}
		for (int t = n - 2; t > 0; --t) {
			ans[t] = ans[t + 1] - dfs(t, t + 1, 0);
		}
		for (int i = 1; i < n; ++i) {
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
	
	static boolean failed = false;
	
	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Solution().run();
	}
	
}