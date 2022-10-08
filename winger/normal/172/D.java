import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	long sum(long n) {
		return n * (n + 1) / 2;
	}

	public void solve() throws IOException {
		int a = nextInt();
		int n = nextInt();
		int sq = 0;
		while (sq * sq < a + n - 1) {
			++sq;
		}
		long ans = 0;
		long[] d = new long[sq + 1];
		for (int i = sq; i > 0; --i) {
			d[i] = i * i * (sum((a + n - 1) / (i * i)) - sum((a - 1) / (i * i)));
			for (int j = 2 * i; j <= sq; j += i) {
				d[i] -= d[j];
			}
			ans += d[i] / (i * i);
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