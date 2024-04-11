import java.io.*;
import java.util.*;

public class Solution implements Runnable {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	private void solve() throws IOException {
		int n = nextInt();
		double[] p = new double[n];
		for (int i = 0; i < n; ++i) {
			long l = nextLong();
			long r = nextLong();
			long count1 = 0;
			long count = r - l + 1;
			if (r == 1000000000000000000L) {
				count1++;
				r--;
			}
			long pow10 = 1;
			for (int len = 1; len <= 18; ++len, pow10 *= 10) {
				long ll = pow10;
				long rr = 2 * pow10 - 1;
				if (rr >= l && r >= ll) {
					count1 += Math.min(r, rr) - Math.max(l, ll) + 1;
				}
			}
			p[i] = count1 / (double)count;
		}
		int k = nextInt();
		k = (k * n + 99) / 100;
		double[][] d = new double[n + 1][n + 1];
		d[0][0] = 1.;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= i; ++j) {
				d[i + 1][j] += d[i][j] * (1 - p[i]);
				d[i + 1][j + 1] += d[i][j] * p[i];
			}
		}
		double ans = 0.;
		for (int i = k; i <= n; ++i) {
			ans += d[n][i];
		}
		out.println(ans);
	}

	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			eat("");
			
			solve();
			
			in.close();
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(-1);
		}
	}

	private void eat(String line) {
		st = new StringTokenizer(line);
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

	public static void main(String[] args) {
		new Thread(new Solution()).start();
	}

}