import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	final static long mod = 1000000007;

	static class KQueue {
		long[] ar;
		int size = 0, p = 0;
		long sum = 0;
		
		KQueue(int k) {
			ar = new long[k];
		}
		
		void add(long x) {
			if (size == ar.length) {
				sum = (sum + mod - ar[p]) % mod;
			} else {
				size++;
			}
			ar[p] = x;
			sum = (sum + x) % mod;
			p = (p + 1) % ar.length;
		}
		
		long last() {
			return size < ar.length ? 0 : ar[p];
		}
		
		void clear() {
			sum = 0L;
			size = 0;
			p = 0;
		}
		
		@Override
		public String toString() {
			StringBuilder sb = new StringBuilder();
			sb.append("[");
			for (int i = 0; i < size; ++i) {
				sb.append(ar[(p + i) % ar.length] + ",");
			}
			sb.append(":").append(sum);
			sb.append("]");
			return sb.toString();
		}
	}

	public void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		String s = next();
		long ans = 0L;
		KQueue q1 = new KQueue(k);
		KQueue q2 = new KQueue(k);
		q1.add(1L);
		for (int i = 0; i < n; ++i) {
			if (s.charAt(i) == 'B') {
				long s1 = (q1.last() + q2.sum) % mod;
				q2.clear();
				q2.add(s1);
				q1.add(0L);
			} else if (s.charAt(i) == 'W') {
				ans = (ans + q2.last()) % mod;
				q2.add(0L);
				long s0 = q1.sum;
				q1.clear();
				q1.add(s0);
			} else {
				ans = (2 * ans + q2.last()) % mod;
				long s1 = (q1.last() + q2.sum) % mod;
				long s0 = q1.sum;
				q2.add(s1);
				q1.add(s0);
			}
//			System.err.println(q1 + " " + q2 + " " + ans);
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
	
	static boolean failed = false;
	
	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Solution().run();
	}
	
}