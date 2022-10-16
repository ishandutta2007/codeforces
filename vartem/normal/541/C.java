import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class C {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int[] f = new int[n];
		for (int i = 0; i < n; i++) {
			f[i] = in.nextInt() - 1;
		}
		BigInteger ans = BigInteger.ONE, mx = BigInteger.ZERO;

		for (int i = 0; i < n; i++) {
			int[] pos = new int[n];
			Arrays.fill(pos, -1);

			int cur = i;
			for (int j = 0;; j++) {
				if (pos[cur] != -1) {
					int per = j - pos[cur];
					ans = lcm(ans, per);
					mx = mx.max(BigInteger.valueOf(pos[cur]));
					break;
				} else {
					pos[cur] = j;
					cur = f[cur];
				}
			}
		}
		BigInteger ret = ans;
		while (ret.compareTo(mx) < 0) {
			ret = ret.add(ans);
		}
		out.println(ret);
	}

	private BigInteger lcm(BigInteger ans, int pref) {
		if (pref == 0){ 
			return ans;
		}
		BigInteger b = BigInteger.valueOf(pref);
		return ans.divide(ans.gcd(b)).multiply(b);
	}

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
				e.printStackTrace();
			}
		}

		String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new C().run();
	}
}