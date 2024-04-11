import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {
	static FastScanner sc = new FastScanner(System.in);
	static final long MOD = 998244353;

	public static void main(String[] args) {
		long[] fact = new long[1000];
		long[] factInv = new long[fact.length];
		fact[0] = factInv[0] = 1;
		for (int i = 1; i < fact.length; i++) {
			fact[i] = fact[i - 1] * i % MOD;
		}
		factInv[fact.length - 1] = inv(fact[fact.length - 1]);
		for (int i = fact.length - 1; i > 0; i--) {
			factInv[i - 1] = factInv[i] * i % MOD;
		}
		long D = sc.nextLong();
		ArrayList<Long> p = new ArrayList<>();
		ArrayList<Integer> c = new ArrayList<>();
		for (long i = 2; i * i <= D; i++) {
			if (D % i == 0) {
				p.add(i);
				int n = 1;
				D /= i;
				while (D % i == 0) {
					D /= i;
					n++;
				}
				c.add(n);
			}
		}
		if (D != 1) {
			p.add(D);
			c.add(1);
		}
		int Q = sc.nextInt();
		long[] c1 = new long[c.size()];
		long[] c2 = new long[c.size()];
		PrintWriter writer = new PrintWriter(System.out);
		for (int i = 0; i < Q; i++) {
			Arrays.fill(c1, 0);
			Arrays.fill(c2, 0);
			long v = sc.nextLong();
			long u = sc.nextLong();
			if (v == u) {
				writer.println(1);
				continue;
			}
			long vt = v;
			long ut = u;
			long s1 = 1;
			long s2 = 1;
			long upper = 1;
			long lower = 1;
			for (int j = 0; j < p.size(); j++) {
				long prime = p.get(j);
				while (vt % prime == 0) {
					vt /= prime;
					c1[j]++;
				}
				s1 *= (c1[j] + 1);
				while (ut % prime == 0) {
					ut /= prime;
					c2[j]++;
				}
				s2 *= (c2[j] + 1);
				upper *= Math.max(c1[j], c2[j]) + 1;
				lower *= Math.min(c1[j], c2[j]) + 1;
			}
			boolean one = upper == s1 || upper == s2;
			long nl = s1 + s2 - 2 * lower;
			long nu = 2 * upper - s1 - s2;
			long ans = 0;
//			System.err.println(s1 + " " + s2 + " " + lower + " " + upper + " " + nl + " " + nu);
			if (nl <= nu) {
				long ansl = 1;
				long sum1 = 0;
				long sum2 = 0;
				for (int j = 0; j < p.size(); j++) {
					long cc = c1[j] - Math.min(c1[j], c2[j]);
					sum1 += cc;
					ansl *= factInv[(int) cc];
					ansl %= MOD;
					cc = c2[j] - Math.min(c1[j], c2[j]);
					sum2 += cc;
					ansl *= factInv[(int) cc];
					ansl %= MOD;
				}
				ansl *= fact[(int) sum1];
				ansl %= MOD;
				ansl *= fact[(int) sum2];
				ansl %= MOD;
				ans += ansl;
			}
			if (nu <= nl && !one) {
				long ansu = 1;
				long sum1 = 0;
				long sum2 = 0;
				for (int j = 0; j < p.size(); j++) {
					long cc = Math.max(c1[j], c2[j]) - c1[j];
					sum1 += cc;
					ansu *= factInv[(int) cc];
					ansu %= MOD;
					cc = Math.max(c1[j], c2[j]) - c2[j];
					sum2 += cc;
					ansu *= factInv[(int) cc];
					ansu %= MOD;
				}
				ansu *= fact[(int) sum1];
				ansu %= MOD;
				ansu *= fact[(int) sum2];
				ansu %= MOD;
				ans += ansu;
			}
			writer.println(ans);
		}
		writer.flush();
	}

	static long inv(long v) {
		return pow(v, MOD - 2);
	}

	static long pow(long b, long p) {
		if (p == 0) return 1;
		if (p == 1) return b;
		long ret = pow(b, p / 2);
		ret *= ret;
		ret %= MOD;
		if (p % 2 == 1) {
			ret *= b;
			ret %= MOD;
		}
		return ret;
	}

	static class FastScanner {
		Reader input;

		FastScanner() {
			this(System.in);
		}

		FastScanner(InputStream stream) {
			this.input = new BufferedReader(new InputStreamReader(stream));
		}

		int nextInt() {
			return (int) nextLong();
		}

		long nextLong() {
			try {
				int sign = 1;
				int b = input.read();
				while ((b < '0' || '9' < b) && b != '-' && b != '+') {
					b = input.read();
				}
				if (b == '-') {
					sign = -1;
					b = input.read();
				} else if (b == '+') {
					b = input.read();
				}
				long ret = b - '0';
				while (true) {
					b = input.read();
					if (b < '0' || '9' < b) return ret * sign;
					ret *= 10;
					ret += b - '0';
				}
			} catch (IOException e) {
				e.printStackTrace();
				return -1;
			}
		}

		double nextDouble() {
			try {
				double sign = 1;
				int b = input.read();
				while ((b < '0' || '9' < b) && b != '-' && b != '+') {
					b = input.read();
				}
				if (b == '-') {
					sign = -1;
					b = input.read();
				} else if (b == '+') {
					b = input.read();
				}
				double ret = b - '0';
				while (true) {
					b = input.read();
					if (b < '0' || '9' < b) break;
					ret *= 10;
					ret += b - '0';
				}
				if (b != '.') return sign * ret;
				double div = 1;
				b = input.read();
				while ('0' <= b && b <= '9') {
					ret *= 10;
					ret += b - '0';
					div *= 10;
					b = input.read();
				}
				return sign * ret / div;
			} catch (IOException e) {
				e.printStackTrace();
				return Double.NaN;
			}
		}

		char nextChar() {
			try {
				int b = input.read();
				while (Character.isWhitespace(b)) {
					b = input.read();
				}
				return (char) b;
			} catch (IOException e) {
				e.printStackTrace();
				return 0;
			}
		}

		String nextStr() {
			try {
				StringBuilder sb = new StringBuilder();
				int b = input.read();
				while (Character.isWhitespace(b)) {
					b = input.read();
				}
				while (b != -1 && !Character.isWhitespace(b)) {
					sb.append((char) b);
					b = input.read();
				}
				return sb.toString();
			} catch (IOException e) {
				e.printStackTrace();
				return "";
			}
		}

	}
}