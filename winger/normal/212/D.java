import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;


	public void solve() throws IOException {
		int n = nextInt();
//		Random rnd = new Random();
		long[] a = new long[n + 1];
		for (int i = 0; i < n; ++i) {
			a[i] = nextLong();
//			a[i] = rnd.nextInt(n) + 1;
		}
		int[] rooml = new int[n];
		int[] roomr = new int[n];
		int[] stack = new int[n + 2];
		int stp = 1;
		stack[0] = n;
		for (int i = n - 1; i >= 0; --i) {
			while (a[stack[stp - 1]] >= a[i]) {
				stp--;
			}
			roomr[i] = stack[stp - 1] - i;
			stack[stp++] = i;
		}
		stp = 1;
		for (int i = 0; i < n; ++i) {
			while (a[stack[stp - 1]] > a[i]) {
				stp--;
			}
			rooml[i] = i - (stack[stp - 1] == n ? -1 : stack[stp - 1]);
			stack[stp++] = i;
		}
		long[] ans = new long[n + 2];
		long[] d2t = new long[n + 2];
		for (int i = 0; i < n; ++i) {
			d2t[0] += a[i];
			d2t[rooml[i]] -= a[i];
			d2t[roomr[i]] -= a[i];
			d2t[rooml[i] + roomr[i]] += a[i];
		}
		long dt = 0;
		for (int i = 0; i <= n; ++i) {
			dt += d2t[i];
			ans[i + 1] = ans[i] + dt;
		}
		if (ans[n + 1] != 0) {
			throw new AssertionError();
		}
		int m = nextInt();
		for (int i = 0; i < m; ++i) {
			int q = nextInt();
			out.println((double)ans[q] / (n - q + 1));
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