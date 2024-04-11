import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	void solve() throws IOException {
		int n = nextInt();
		long ans = 0;
		for (int i = 0; i < n; ++i) {
			long x = nextLong();
			long m = nextLong();
			ans ^= xorUpto(x - 1) ^ xorUpto(x + m - 1);
		}
		out.println(ans == 0 ? "bolik" : "tolik");
	}
	
	long xorUpto(long x) {
		long ret = 0;
		if (((x ^ (x >> 1)) & 1) != 0) {
			ret |= 1;
		}
		for (int i = 1; i < 64; ++i) {
			if ((x & (1L << i)) != 0 && (x & 1) == 0) {
				ret |= 1L << i;
			}
		}
//		long ret2 = 0;
//		for (long i = 1; i <= x; ++i) {
//			ret2 ^= i;
//		}
		return ret;
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