import java.util.*;
import java.io.*;

public class D {

	int[] pow10 = new int[] { 1, 10, 100, 1000, 10000, 100000 };

	int mod = 1_000_000_007;

	int pow(int a, int b) {
		if (b < 0) {
			return 0;
		}
		int res = 1;
		while (b > 0) {
			if ((b & 1) == 1) {
				res = (int) (1L * res * a % mod);
			}
			a = (int) (1L * a * a % mod);
			b >>>= 1;
		}
		return res;
	}

	int digit(int a, int pos) {
		return a / pow10[pos] % 10;
	}

	int MAX = 1_000_000;

	void solve() {
		int n = in.nextInt();
		long[] sum1 = new long[MAX], sumA = new long[MAX], sumA2 = new long[MAX], sumAB = new long[MAX];
		for (int i = 0; i < n; i++) {
			int val = in.nextInt();
			sum1[val]++;
			sumA[val] += val;
			if (sumA[val] >= mod) {
				sumA[val] -= mod;
			}
			sumA2[val] += 1L * val * val % mod;
			if (sumA2[val] >= mod) {
				sumA2[val] -= mod;
			}
		}
		for (int i = 0; i < MAX; i++) {
			long cntPairs = 1L * sum1[i] * (sum1[i] - 1) / 2 % mod;
			sumAB[i] = 1L * i * i * cntPairs % mod;
		}

		for (int pos = 0; pos < 6; pos++) {
			for (int val = 0; val < 1_000_000; val++) {
				if (digit(val, pos) != 0) {
					continue;
				}
				for (int d = 9; d >= 1; d--) {
					int cur = val + pow10[pos] * d;
					int next = cur - pow10[pos];
					
					sumAB[next] += sumAB[cur];
					if (sumAB[next] >= mod) {
						sumAB[next] -= mod;
					}
					sumAB[next] += (int) (1L * sumA[cur] * sumA[next] % mod);
					if (sumAB[next] >= mod) {
						sumAB[next] -= mod;
					}
					
					sum1[next] += sum1[cur];
					if (sum1[next] >= mod) {
						sum1[next] -= mod;
					}
					sumA[next] += sumA[cur];
					if (sumA[next] >= mod) {
						sumA[next] -= mod;
					}
					sumA2[next] += sumA2[cur];
					if (sumA2[next] >= mod) {
						sumA2[next] -= mod;
					}
				}
			}
		}

		long[] h = new long[MAX];
		for (int i = 0; i < MAX; i++) {
			int cnt = (int) sum1[i];
			h[i] = sumA2[i] * pow(2, cnt - 1) % mod + 2L * sumAB[i] * pow(2, cnt - 2) % mod;
			h[i] %= mod;
		}
		
		for (int pos = 0; pos < 6; pos++) {
			for (int val = 0; val < 1_000_000; val++) {
				if (digit(val, pos) != 0) {
					continue;
				}
				for (int d = 0; d < 9; d++) {
					int cur = val + pow10[pos] * d;
					int next = cur + pow10[pos];
					
					h[cur] -= h[next];
					if (h[cur] < 0) {
						h[cur] += mod;
					}
				}
			}
		}
		
		long result = 0;
		for (int i = 0; i < MAX; i++) {
			result ^= 1L * h[i] * i;
		}

		out.println(result);
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
		new D().run();
	}
}