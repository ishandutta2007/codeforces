import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	void solve() throws IOException {
		double a = nextDouble();
		double v = nextDouble();
		double l = nextDouble();
		double d = nextDouble();
		double w = nextDouble();
		if (w > v) {
			w = v;
		}
		double ans1 = 0.;
		double v1;
		{
			double l_ = 0., r_ = 1e+9;
			for (int it = 0; it < 100; ++it) {
				double mid = (l_ + r_) / 2.;
				double V = a * mid;
				double t1 = (V + w) / 2. / a;
				double t2 = mid - t1;
				t1 = Math.min(t1, v / a);
				t2 = Math.min(t2, (v - w) / a);
				if (V < w) {
					t1 = mid;
					t2 = 0.;
				}
				double dist = t1 * t1 * a / 2. + t2 * (w + t2 * a / 2.) + v * (mid - t1 - t2);
				if (dist < d) {
					l_ = mid;
				} else {
					r_ = mid;
				}
			}
			ans1 = (l_ + r_) / 2.;
			v1 = Math.min(ans1 * a, w);
		}
		double ans2 = 0.;
		{
			double tSp = (v - v1)  / a;
			double l_ = 0., r_ = 1e+9;
			for (int it = 0; it < 100; ++it) {
				double mid = (l_ + r_) / 2.;
				double dist = Math.min(tSp, mid) * (v1 + Math.min(tSp, mid) * a / 2.);
				dist += (mid - Math.min(tSp, mid)) * v;
				if (dist < l - d) {
					l_ = mid;
				} else {
					r_ = mid;
				}
			}
			ans2 = (l_ + r_) / 2.;
		}
		out.println(ans1 + ans2);
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