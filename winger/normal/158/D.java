import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;

	public void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; ++i) {
			a[i] = nextInt();
		}
		int[] b = new int[n];
		int ans = -1000000000;
		for (int d = 1; 3 * d <= n; ++d) {
			if (n % d != 0) {
				continue;
			}
			for (int i = 0; i < d; ++i) {
				b[i] = 0;
			}
			for (int i = 0, j = 0; i < n; ++i, ++j) {
				if (j == d) {
					j = 0;
				}
				b[j] += a[i];
			}
			for (int i = 0; i < d; ++i) {
				ans = Math.max(ans, b[i]);
			}
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