import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Table {

	final String filename = new String("Table").toLowerCase();

	final long mod = 1000000007;
	BigInteger bigmod = BigInteger.valueOf(mod);

	void solve() throws Exception {
		int n = nextInt();
		long m = nextLong();
		int k = nextInt();

		long[] count = new long[n];
		Arrays.fill(count, m / n);
		for (int i = 0; i < m % n; i++) {
			count[i]++;
		}
		
		long pow1 = m / n;
		long pow2 = pow1 + 1;
		
		long[][] c1 = new long[n + 1][n + 1], c2 = new long[n + 1][n + 1];
		c1[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			c1[i][0] = 1;
			for (int j = 1; j <= n; j++) {
				c1[i][j] = (c1[i - 1][j - 1] + c1[i - 1][j]) % mod;
			}
		}
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				c2[i][j] = c1[i][j];
				
				c1[i][j] = pow(c1[i][j], pow1);
				c2[i][j] = pow(c2[i][j], pow2);
			}
		}

		long[][] dp = new long[n + 1][k + 1];
		dp[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			long[][] table = c1;
			if (count[i - 1] == pow2) {
				table = c2;
			}
			for (int j = 0; j <= k; j++) {
				for (int s = 0; s <= n && s <= j; s++) {
					dp[i][j] = (dp[i][j] + dp[i - 1][j - s] * table[n][s]) % mod;
				}
			}
		}

		out.println(dp[n][k]);
	}

	private long pow(long b, long e) {
		long a = b, res = 1;
		while (e > 0) {
			if ((e & 1) != 0) {
				res = (res * a) % mod;
			}
			a = (a * a) % mod;
			e >>= 1;
		}
		return res;
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			// in = new BufferedReader(new FileReader("input.txt"));
			// out = new PrintWriter("output.txt");
			
//			long time = System.currentTimeMillis();
			solve();
//			System.err.println(System.currentTimeMillis() - time);

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	BufferedReader in;
	StringTokenizer st;
	PrintWriter out;

	String nextToken() throws Exception {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}

	public static void main(String[] args) {
		new Table().run();
	}

}