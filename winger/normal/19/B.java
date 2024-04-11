import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	void solve() throws IOException {
		int n = nextInt();
		long[] d = new long[n + 1];
		Arrays.fill(d, Long.MAX_VALUE);
		d[0] = 0;
		for (int i = 0; i < n; ++i) {
			int t = nextInt();
			int c = nextInt();
			for (int j = n; j >= 0; --j) {
				if (d[j] == Long.MAX_VALUE) {
					continue;
				}
				int k = Math.min(n, j + t + 1);
				d[k] = Math.min(d[k], d[j] + c);
			}
		}
		out.println(d[n]);
	}

	Solution() throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		
		eat("");
		
		solve();
		
		in.close();
		out.close();
	}
	
	private void eat(String str) {
		st = new StringTokenizer(str);
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
		new Solution();
	}
}