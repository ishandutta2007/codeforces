import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;

	public void solve() throws IOException {
		int n = nextInt();
		double len = nextDouble();
		double v1 = nextDouble();
		double v2 = nextDouble();
		double l1 = v2 / (v1 + v2) / 2.;
		double[] a = new double[2 * n];
		for (int i = 0; i < n; ++i) {
			a[i] = nextDouble() / len / 2.;
			a[n + i] = a[i] + 1.;
		}
		double pos = 0.;
		int l = 0, r = 0;
		final double EPS = 1e-12;
		while (r < 2 * n && a[r] <= l1 + EPS) {
			++r;
		}
		while (l < 2 * n && a[l] < EPS) {
			++l;
		}
//		System.err.println(Arrays.toString(a) + " " + len + " " + l1);
		double[] ans = new double[n + 1];
		while (pos < 1. - EPS) {
			double next = 1.;
			if (l < 2 * n && a[l] > pos + EPS) {
				next = Math.min(next, a[l]);
			}
//			System.err.println(pos + " " + next + " " + l + " " + r);
			if (r < 2 * n && a[r] - l1 > pos + EPS) {
				next = Math.min(next, a[r] - l1);
			}
			ans[r - l] += next - pos;
			pos = next;
			while (l < 2 * n && a[l] < pos + EPS) {
				l++;
			}
			while (r < 2 * n && a[r] <= pos + l1 + EPS) {
				r++;
			}
		}
		for (int i = 0; i <= n; ++i) {
			out.println(ans[i]);
		}
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