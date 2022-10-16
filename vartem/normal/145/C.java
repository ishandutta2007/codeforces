import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.Map.Entry;

public class C {

	final String filename = new String("C").toLowerCase();

	boolean isLucky(int g) {
		while (g > 0) {
			int m = g % 10;
			if (m != 4 && m != 7)
				return false;
			g /= 10;
		}
		return true;
	}
	long mod = 1000000007;
	BigInteger bigmod = BigInteger.valueOf(mod);
	long[] fact;
	
	long choose(int n, int k) {
		long num = fact[n];
		long denom = (fact[k] * fact[n - k]) % mod;
		long res = (num * BigInteger.valueOf(denom).modInverse(bigmod).longValue()) % mod;
		return res;
	}
	
	void solve() throws Exception {
		int n = nextInt();
		int k = nextInt();
		Map<Integer, Integer> tm = new HashMap<Integer, Integer>();
		int[] a = new int[n];
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
			if (isLucky(a[i])) {
				if (!tm.containsKey(a[i]))
					tm.put(a[i], 0);
				tm.put(a[i], tm.get(a[i]) + 1);
			} else {
				cnt++;
			}
		}
		fact = new long[cnt + 1];
		fact[0] = 1;
		for (int i = 1; i <= cnt; i++) {
			fact[i] = (fact[i - 1] * (long) i) % mod;
		}
		long[] choose = new long[cnt + 1];
		for (int i = 0; i <= cnt; i++) {
			choose[i] = choose(cnt, i);
		}
		int s = tm.size();
		long[] res = new long[s + 1];
		res[0] = 1;
		for (Entry<Integer, Integer> e : tm.entrySet()) {
			long val = e.getValue();
			long[] newres = new long[s + 1];
			newres[0] = 1;
			for (int i = 1; i <= s; i++) {
				newres[i] = (res[i] + res[i - 1] * val) % mod;
			}
			res = newres;
		}
		
		long ans = 0;
		for (int i = 0; i <= s && i <= k; i++) {
			if (cnt < k - i) {
				continue;
			}
			long tmp = res[i];
			tmp *= choose[k - i];
			tmp %= mod;
			ans = (ans + tmp) % mod;
		}
		out.println(ans);
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			//			in = new BufferedReader(new FileReader("input.txt"));
			//			out = new PrintWriter("output.txt");

			solve();

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
		new C().run();
	}

}