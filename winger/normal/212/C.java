import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;


	public void solve() throws IOException {
		String s = next();
		BigInteger ans = BigInteger.ZERO;
		for (int last = 0; last < 3; ++last) {
			BigInteger u = last == 0 ? BigInteger.ONE : BigInteger.ZERO;
			BigInteger v = last == 1 ? BigInteger.ONE : BigInteger.ZERO;
			BigInteger w = last == 2 ? BigInteger.ONE : BigInteger.ZERO;
			for (int i = 0; i < s.length(); ++i) {
				BigInteger nu = s.charAt(i) == 'A' ? u.add(w) : BigInteger.ZERO;
				BigInteger nv = s.charAt(i) == 'B' ? u.add(w) : BigInteger.ZERO;
				BigInteger nw = s.charAt(i) == 'A' ? v : w;
				u = nu;
				v = nv;
				w = nw;
			}
			ans = ans.add(last == 0 ? u : last == 1 ? v : w);
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