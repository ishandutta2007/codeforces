import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;

	public void solve() throws IOException {
		int n = nextInt();
		String u = next();
		String v = next();
		int ans1 = 0;
		int ans2 = 0;
		final String s = "RSP";
		int m = u.length() * v.length();
		for (int it = 0, i = 0, j = 0; it < m; ++it, i++, j++) {
			if (i == u.length()) {
				i = 0;
			}
			if (j == v.length()) {
				j = 0;
			}
			int val = (n + m - it - 1) / m;
			int a = s.indexOf(u.charAt(i));
			int b = s.indexOf(v.charAt(j));
			if ((a + 1) % 3 == b) {
				ans2 += val;
			}
			if ((b + 1) % 3 == a) {
				ans1 += val;
			}
		}
		out.println(ans1 + " " + ans2);
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