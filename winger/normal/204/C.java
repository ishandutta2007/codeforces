import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;


	public void solve() throws IOException {
		int n = nextInt();
		String a = next();
		String b = next();
		double sum = 0.;
		double[] s = new double[26];
		for (int i = 0; i < n; ++i) {
			s[a.charAt(i) - 'A'] += (i + 1);
			sum += s[b.charAt(i) - 'A'] * (n - i);
		}
		Arrays.fill(s, 0.);
		for (int i = n - 1; i >= 0; --i) {
			sum += s[b.charAt(i) - 'A'] * (i + 1);
			s[a.charAt(i) - 'A'] += (n - i);
		}
		
		double total = 0.;
		for (long i = 1; i <= n; ++i) {
			total += i * i;
		}
		out.println(sum / total);
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