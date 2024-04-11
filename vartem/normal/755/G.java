import java.util.*;
import java.io.*;

public class G {

	int LOG = 16;
	int len = 1 << LOG;

	final int MOD = 7 * 17 * (1 << 23) + 1;
	int G = 3;

	int pow(int a, int b) {
		int res = 1;
		while (b > 0) {
			if ((b & 1) == 1) {
				res = (int) ((1L * res * a) % MOD);
			}
			a = (int) ((1L * a * a) % MOD);
			b >>= 1;
		}
		return res;
	}

	int[] tail = new int[len], omega = new int[len];

	void FFT(int[] a, boolean inv) {
		for (int i = 0; i < len; i++) {
			if (i < tail[i]) {
				int tmp = a[i];
				a[i] = a[tail[i]];
				a[tail[i]] = tmp;
			}
		}

		for (int len = 2; len <= a.length; len *= 2) {
			for (int i = 0; i < a.length; i += len) {
				int pos = 0;
				for (int j = 0, k = len / 2; k < len; j++, k++) {
					int u = a[i + j], v = (int) ((1L * a[i + k] * omega[pos]) % MOD);

					a[i + j] = u + v;
					if (a[i + j] >= MOD) {
						a[i + j] -= MOD;
					}
					a[i + k] = u - v;
					if (a[i + k] < 0) {
						a[i + k] += MOD;
					}

					if (inv) {
						pos -= a.length / len;
						if (pos < 0) {
							pos += a.length;
						}
					} else {
						pos += a.length / len;
					}
				}
			}
		}
		if (inv) {
			int coef = pow(a.length, MOD - 2);
			for (int i = 0; i < a.length; i++) {
				a[i] = (int) ((1L * a[i] * coef) % MOD);
			}
		}
	}

	void prepare() {
		int om = pow(G, (MOD - 1) / len);
		omega[0] = 1;
		for (int i = 1; i < len; i++) {
			omega[i] = (int) ((1L * omega[i - 1] * om) % MOD);
			tail[i] = ((tail[i >> 1] >> 1) | ((i & 1) << (LOG - 1)));
		}
	}

	int k;

	void trunc(int[] ans) {
		for (int j = k + 1; j < len; j++) {
			ans[j] = 0;
		}
	}

	Map<Integer, int[]> memo = new HashMap<>();
	Map<Integer, int[]> memoFT = new HashMap<>();
	
	int[][] dp;
	
	void fillStupid(int mx) {
		dp = new int[mx + 1][k + 1];
		dp[0][0] = 1;
		for (int i = 1; i <= mx; i++) {
			for (int j = 0; j <= i && j <= k; j++) {
				dp[i][j] = dp[i - 1][j];
				if (i - 1 >= 0 && j > 0) {
					dp[i][j] += dp[i - 1][j - 1];
					dp[i][j] %= MOD;
				}
				if (i - 2 >= 0 && j > 0) {
					dp[i][j] += dp[i - 2][j - 1];
					dp[i][j] %= MOD;
				}
			}
		}
		
		for (int i = 0; i <= mx; i++) {
			dp[i] = Arrays.copyOf(dp[i], len);
		}
	}
	
	int[] stupid(int n) {
		return dp[n];
	}
	
	int[] res = new int[len];

	int[] get(int n) {
		if (memo.containsKey(n)) {
			return memo.get(n);
		}

		int[] result = new int[len];
		if (n <= 8) {
			result = stupid(n);
		} else {
			int size1 = (n + 1) / 2, size2 = n / 2;
			for (int midLeft = 0; midLeft <= 0; midLeft++) {
				for (int midRight = 0; midRight + midLeft <= 0; midRight++) {
					get(size1 - midLeft);
					get(size2 - midRight);

					int[] tmp1 = memoFT.get(size1 - midLeft), tmp2 = memoFT.get(size2 - midRight);
					multiply(res, tmp1, tmp2);

					int add = Math.min(1, midLeft + midRight);
					for (int i = 0; i + add < len; i++) {
						if (i + add < len) {
							result[i + add] += res[i];
							if (result[i + add] >= MOD) {
								result[i + add] -= MOD;
							}
						}
					}
				}
			}
			
			
			for (int midLeft = 1; midLeft <= 1; midLeft++) {
				for (int midRight = 1; midRight + midLeft <= 2; midRight++) {
					get(size1 - midLeft);
					get(size2 - midRight);

					int[] tmp1 = memoFT.get(size1 - midLeft), tmp2 = memoFT.get(size2 - midRight);
					multiply(res, tmp1, tmp2);

					int add = Math.min(1, midLeft + midRight);
					for (int i = 0; i + add < len; i++) {
						if (i + add < len) {
							result[i + add] += res[i];
							if (result[i + add] >= MOD) {
								result[i + add] -= MOD;
							}
						}
					}
				}
			}
		}
		trunc(result);
		memo.put(n, result);
		int[] resultFT = result.clone();
		FFT(resultFT, false);
		memoFT.put(n, resultFT);
		return result;
	}

	void multiply(int[] res, int[] a, int[] b) {
		for (int i = 0; i < len; i++) {
			res[i] = (int) (1L * a[i] * b[i] % MOD);
		}
		FFT(res, true);
	}

	void solve() {
		prepare();
		int n = in.nextInt();
		k = in.nextInt();
		fillStupid(8);
		fast(n, k);
	}

	void print(int[] a) {
		System.err.println(Arrays.toString(Arrays.copyOf(a, 100)));
	}

	void fast(int n, int k) {
		memo = new HashMap<>();
		memoFT = new HashMap<>();
		for (int i = 1; i <= k; i++) {
			long result = 0;
			result += get(n)[i];
			out.print((result % MOD) + " ");
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
		new G().run();
	}
}