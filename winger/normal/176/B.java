import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	long mod = 1000000007;
	
	long count(int start, int n, int k) {
		long cur = start;
		long pow = 1;
		for (int i = 0; i < k; ++i) {
			cur = (pow + mod - cur) % mod;
			pow = (pow * (n - 1)) % mod;
		}
		return cur;
	}

	public void solve() throws IOException {
		String a = next();
		String b = next();
		int k = nextInt();
		long c0 = count(0, a.length(), k);
		long c1 = count(1, a.length(), k);
		long ans = a.equals(b) ? c1 : 0;
		for (int i = 1; i < a.length(); ++i) {
			if (a.equals(b.substring(i) + b.substring(0, i))) {
				ans = (ans + c0) % mod;
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