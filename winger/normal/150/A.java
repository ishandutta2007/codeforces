
import java.io.*;
import java.util.*;
import java.util.regex.Pattern;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;


	public void solve() throws IOException {
		long n = nextLong();
		ArrayList<Long> primeDivs = new ArrayList<Long>();
		for (long x = 2; x * x <= n; ++x) {
			while (n % x == 0) {
				primeDivs.add(x);
				n /= x;
			}
		}
		if (n > 1) {
			primeDivs.add(n);
		}
		if (primeDivs.size() <= 1) {
			out.println("1\n0");
			return;
		}
		if (primeDivs.size() == 2) {
			out.println("2");
			return;
		}
		out.println("1");
		out.println(primeDivs.get(0) * primeDivs.get(1));
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