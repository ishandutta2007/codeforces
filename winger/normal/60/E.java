import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;
	
	int p;
	
	long[][] pow(long[][] x, long pow) {
		long[][] r = new long[x.length][x.length];
		for (int i = 0; i < x.length; ++i) {
			r[i][i] = 1;
		}
		while (pow > 0) {
			if (pow % 2 == 1) {
				r = mul(r, x);
			}
			pow /= 2;
			x = mul(x, x);
		}
		return r;
	}
	
	long[][] mul(long[][] a, long[][] b) {
		long[][] c = new long[a.length][a.length];
		for (int i = 0; i < a.length; ++i) {
			for (int j = 0; j < a.length; ++j) {
				for (int k = 0; k < a.length; ++k) {
					c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % p;
				}
			}
		}
		return c;
	}

	void solve() throws IOException {
		int n = nextInt();
		long x = nextLong();
		long y = nextLong();
		p = nextInt();
		long[] a = new long[n];
		long sum = 0;
		for (int i = 0; i < n; ++i) {
			a[i] = nextInt() % p;
			sum = (sum + a[i]) % p;
		}
		if (n == 1) {
			out.println(sum);
			return;
		}
		long[][] m1 = new long[][] {{3, p - 1}, {0, 1}};
		m1 = pow(m1, x);
		long sum1 = (m1[0][0] * sum + m1[0][1] * (a[0] + a[n - 1])) % p;
		long[][] f = new long[][] {{0, 1}, {1, 1}};
		f = pow(f, x);
		long ka = f[0][1];
		long kb = f[1][1];
		long[][] m2 = new long[][] {{3, p - 1}, {0, 1}};
		m2 = pow(m2, y);
		long sum2 = (m2[0][0] * sum1 + m2[0][1] * ((a[0] + ka * a[n - 2] + kb * a[n - 1]) % p)) % p;
		out.println(sum2);
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