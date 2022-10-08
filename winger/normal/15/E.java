import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	final long mod = 1000000009;
	
	void solve() throws IOException {
		int n = nextInt();
		long ans = 1;
		long[] a = new long[n / 2 - 1];
		long tmp = 1;
		for (int i = 0; i < n / 2 - 1; ++i) {
			if (i == 0) {
				a[i] = tmp;
			} else {
				a[i] = (a[i - 1] + tmp * 2) % mod;
			}
			tmp = (tmp * 2) % mod;
		}
		long one = 2;
		tmp = 1;
		for (int i = 0; i < n / 2 - 1; ++i) {
			tmp = (tmp * a[i]) % mod;
			one = (one + tmp * 4) % mod;
		}
		ans = (ans + one * one) % mod;
		out.println((ans * 2) % mod);
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