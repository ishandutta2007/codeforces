import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	void solve() throws IOException {
		long a = nextLong();
		long b = nextLong();
		long c = nextLong();
		long d = nextLong();
		char[] ops = new char[3];
		for (int i = 0; i < ops.length; ++i) {
			ops[i] = next().charAt(0);
		}
		out.println(rec(new long[] {a, b, c, d}, ops));
	}
	
	long rec(long[] a, char[] ops) {
//		System.err.println(Arrays.toString(a) + " " + Arrays.toString(ops));
		if (a.length == 1) {
			return a[0];
		}
		long ret = Long.MAX_VALUE;
		for (int i = 0; i < a.length; ++i) {
			for (int j = i + 1; j < a.length; ++j) {
				long[] b = new long[a.length - 1];
				for (int t = 0, tt = 0; t < a.length; ++t) {
					if (t != j) {
						b[tt++] = a[t];
						if (t == i) {
							if (ops[0] == '+') {
								b[tt - 1] = a[i] + a[j];
							} else {
								b[tt - 1] = a[i] * a[j];
							}
						}
					}
				}
				ret = Math.min(ret, rec(b, Arrays.copyOfRange(ops, 1, ops.length)));
			}
		}
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