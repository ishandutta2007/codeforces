import java.util.*;
import java.io.*;

public class F {
	
	int mod;

	long pow(long a, long b, long mod) {
		long res = 1 % mod;
		while (b > 0) {
			if ((b & 1) == 1) {
				res = res * a % mod;
			}
			a = a * a % mod;
			b >>>= 1;
		}
		return res;
	}
	
	long inv(long a, long mod) {
		return pow(a, mod - 2, mod);
	}
	
	void solve() {
		int n = in.nextInt(), m = in.nextInt();
		long a = in.nextInt(), q = in.nextInt();
		a %= q;
		
		mod = 1;
		long cur = a;
		while (cur != 1) {
			mod++;
			cur = cur * a % q;
		}
		
		long[] choose = new long[n];
		choose[0] = 1 % mod;
		for (int i = 1; i < n && i <= m; i++) {
			choose[i] = choose[i - 1] * (m - i + 1) % mod;
			choose[i] = choose[i] * inv(i, mod) % mod;
		}
		
		for (int i = 1; i < n; i++) {
			choose[i] += choose[i - 1];
			choose[i] %= mod;
		}
		for (int i = n - 1; i >= 0; i--) {
			out.print(pow(a, choose[i], q) + " ");
		}
		out.println();
	}

	FastScanner in;
	PrintWriter out;

	void run() {
		in = new FastScanner();
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		public String nextToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
				}
			}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(nextToken());
		}

		public long nextLong() {
			return Long.parseLong(nextToken());
		}

		public double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new F().run();
	}
}