import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class A2 {

	void solve() {
		int T = in.nextInt();
		while (T-- > 0) {
			solveOne();
		}
	}
	
	int gcd(int a, int b) {
		if (a == 0) {
			return b;
		}
		return gcd(b % a, a);
	}

	private void solveOne() {
		int x = in.nextInt(), y = in.nextInt(), p = in.nextInt(), q = in.nextInt();
//		int g2 = gcd(p, q);
//		p /= g2;
//		q /= g2;
		if (1L * x * q == 1L * y * p) {
			out.println(0);
			return;
		}
		if (p == 0 || p == q) {
			out.println(-1);
			return;
		}
		
		long ans = 0;
		long add = 0;
		if (y % q != 0) {
			add = q - y % q;
			y += add;
			ans += add;
		}
		
		
		long minK = 0;
		minK = Math.max(minK, ceil(x, p) - y / q);
		minK = Math.max(minK, ceil(y / q * p - x - add, q - p));
		ans += minK * q;
		out.println(ans);
	}
	
	long ceil(long a, long b){ 
		return (a + b-  1) / b;
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
		new A2().run();
	}
}