import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	void solve() throws IOException {
		int n = nextInt();
		double v = nextDouble();
		double sum = 0.;
		double[] a = new double[n];
		double[] b = new double[n];
		for (int i = 0; i < n; ++i) {
			a[i] = nextDouble();
			sum += a[i];
		}
		for (int i = 0; i < n; ++i) {
			b[i] = nextDouble();
		}
		double ans = v;
		for (int i = 0; i < n; ++i) {
			ans = Math.min(ans, b[i] / a[i] * sum);
		}
		out.println(ans);
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