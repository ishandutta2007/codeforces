import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class D {

	FastScanner in;
	PrintWriter out;

	int[] primes;
	boolean[] isPrime;
	int MAX = 1_000_000;

	void prepare() {
		isPrime = new boolean[MAX];
		Arrays.fill(isPrime, true);
		isPrime[0] = isPrime[1] = false;
		int cnt = 0;
		for (int i = 2; i < MAX; i++) {
			if (isPrime[i]) {
				cnt++;
				for (int j = 2 * i; j < MAX; j += i) {
					isPrime[j] = false;
				}
			}
		}
		primes = new int[cnt];
		cnt = 0;
		for (int i = 2; i < MAX; i++) {
			if (isPrime[i]) {
				primes[cnt++] = i;
			}
		}
	}

	int ans = 0;

	boolean isPrime(long a) {
		if (a < MAX) {
			return isPrime[(int) a];
		}
		return BigInteger.valueOf(a).isProbablePrime(10);
	}

	void go(long cur, int lastPrime) {

		if (cur == 1) {
			ans++;
			return;
		}
		for (int pr = lastPrime + 1; pr < primes.length; pr++) {
			long p = primes[pr];
			if (p * p + 1 > cur) {
				break;
			}
			while (p + 1 <= cur) {
				if (cur % (p + 1) == 0) {
					go(cur / (p + 1), pr);
				}
				p *= primes[pr];
			}
		}

		if (isPrime(cur - 1) && (cur - 1 >= primes[lastPrime + 1])) {
			ans++;
		}
	}

	void solve() {
		long a = in.nextLong();
//		long time = System.currentTimeMillis();
		prepare();
		go(a, -1);
		out.println(ans);
//		out.println(System.currentTimeMillis()-  time);
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
		new D().run();
	}
}