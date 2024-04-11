import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);
	static ArrayList<Long> primes = new ArrayList<>();
	static boolean LOCAL = false;
	static long X = 2L * 3 * 5 * 7 * 11 * 13 * 17 * 19;

	public static void main(String[] args) {
		primes.add(2L);
		for (long i = 3; i < 40000; i += 2) {
			boolean ok = true;
			for (int j = 0; j < primes.size(); j++) {
				long p = primes.get(j);
				if (p * p > i) break;
				if (i % p == 0) {
					ok = false;
					break;
				}
			}
			if (ok) primes.add(i);
		}
		int T = LOCAL ? 1 : sc.nextInt();
		for (int i = 0; i < T; i++) {
			solve();
		}
	}

	static void solve() {
		int qc = 0;
		long X = 1;
		long q = 1;
		ArrayList<Long> cps = new ArrayList<>();
		ArrayList<Long> xps = new ArrayList<>();
		ArrayList<Long> aps = new ArrayList<>();
		ArrayList<Integer> apc = new ArrayList<>();
		for (int i = 0; i < primes.size() && qc < (xps.isEmpty() ? 22 : 21); i++) {
			if (xps.size() >= 2) {
				long q1 = 1;
				long q2 = 1;
				while (q1 * xps.get(0) <= 1000000000) {
					q1 *= xps.get(0);
				}
				while (q2 * xps.get(1) <= 1000000000) {
					q2 *= xps.get(1);
				}
				long res = query(q1 * q2);
				++qc;
				aps.add(xps.get(0));
				int c = 0;
				while (res % xps.get(0) == 0) {
					c++;
					res /= xps.get(0);
				}
				apc.add(c);
				aps.add(xps.get(1));
				c = 0;
				while (res % xps.get(1) == 0) {
					c++;
					res /= xps.get(1);
				}
				apc.add(c);
				xps.remove(0);
				xps.remove(0);
				System.err.println("aps:" + aps);
				System.err.println("apc:" + apc);
				System.err.println("xps:" + xps);
				--i;
				continue;
			}
			long p = primes.get(i);
			if (q >= 1_000_000_000_000_000_000L / p) {
				long res = query(q);
				qc++;
				for (long cp : cps) {
					if (res % cp == 0) {
						xps.add(cp);
						X *= cp;
					}
				}
				System.err.println("X:" + X + " np:" + p);
//				if (X * p * p > 1_000_000_000) {
//					System.err.println("qc:" + qc);
//					break;
//				}
				cps.clear();
				q = p;
				cps.add(p);
			} else {
				q *= p;
				cps.add(p);
			}
		}
		if (!xps.isEmpty() && qc < 22) {
			long q1 = 1;
			while (q1 * xps.get(0) <= 1000000000) {
				q1 *= xps.get(0);
			}
			long q2 = 1;
			if (xps.size() >= 2) {
				while (q2 * xps.get(1) <= 1000000000) {
					q2 *= xps.get(1);
				}
			}
			long res = query(q1 * q2);
			++qc;
			aps.add(xps.get(0));
			int c = 0;
			while (res % xps.get(0) == 0) {
				c++;
				res /= xps.get(0);
			}
			apc.add(c);
			if (xps.size() >= 2) {
				aps.add(xps.get(1));
				c = 0;
				while (res % xps.get(1) == 0) {
					c++;
					res /= xps.get(1);
				}
				apc.add(c);
			}
			System.err.println("aps:" + aps);
			System.err.println("apc:" + apc);
		}
		int ans = 1;
		for (int c : apc) {
			ans *= c + 1;
		}
		answer(ans > 7 ? ans * 2 : ans + 7);
	}

	static long query(long q) {
		System.out.println("? " + q);
		return LOCAL ? BigInteger.valueOf(X).gcd(BigInteger.valueOf(q)).longValue() : sc.nextLong();
	}

	static void answer(long a) {
		System.out.println("! " + a);
	}

}