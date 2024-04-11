import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class C {

	int gcd(int a, int b) {
		if (a == 0) {
			return b;
		}
		return gcd(b % a, a);
	}
	
	void solve() {
		int n = in.nextInt(), m = in.nextInt();
		
		List<Integer>[] good = new List[m + 1];
		for (int i = 0; i <= m; i++) {
			good[i] = new ArrayList<>();
		}
		boolean[] bad = new boolean[m];
		for (int i = 0; i < n; i++) {
			bad[in.nextInt()] = true;
		}
		
		for (int i = 0; i < m; i++) {
			if (bad[i]) {
				continue;
			}
			good[gcd(i, m)].add(i);
		}
		
		int[] next = new int[m + 1];
		int[] dp = new int[m + 1];
		
		int mmm = m;
		List<Integer> primes = new ArrayList<>();
		for (int i = 2; i <= m; i++) {
			if (mmm % i == 0) {
				primes.add(i);
				while (mmm % i == 0) {
					mmm /= i;
				}
			}
		}
		
		for (int div = m; div >= 1; div--) {
			dp[div] = 0;
			next[div] = m;
			for (int p = 0; p < primes.size(); p++) {
				long newDiv = 1L * div * primes.get(p);
				if (m % newDiv == 0) {
					int newD = (int) newDiv;
					if (dp[newD] > dp[div]) {
						dp[div] = dp[newD];
						next[div] = newD;
					}
				}
			}
			
			dp[div] += good[div].size();
		}
		
		List<Integer> result = new ArrayList<>();
		int cur = 1;
		while (true) {
			result.addAll(good[cur]);
			if (cur == m) {
				break;
			}
			cur = next[cur];
		}
		
		out.println(result.size());
		for (int i = 0; i < result.size(); i++) {
			if (i == 0 ){
				out.print(result.get(i));
			} else {
				out.print(' ');
				int gcd = gcd(result.get(i - 1), result.get(i));
				gcd = gcd(gcd, m);
				int a = result.get(i - 1) / gcd, b = result.get(i) / gcd, mm = m / gcd;
				
				int mul = BigInteger.valueOf(a).modInverse(BigInteger.valueOf(mm)).intValue();
				mul = (int) ((1L * mul * b) % mm);
				out.print(mul);
			}
		}
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
		new C().run();
	}
}