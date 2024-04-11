//package round670;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class E {
	Scanner in;
	PrintWriter out;
	String INPUT = "";

	int a(int n)
	{
		out.println("A " + n);
		out.flush();
		return ni();
	}

	int b(int n)
	{
		out.println("B " + n);
		out.flush();
		return ni();
	}

	void c(int n)
	{
		out.println("C " + n);
		out.flush();
	}

	void solve()
	{
		int n = ni();
		int[] primes = sieveEratosthenes(n);

		int m = primes.length;
		boolean[] done = new boolean[n+1];
		int b = m;
		int h = m/2;
		while(h <= b-1) {
			for (int i = b - 1; i >= h; i--) {
				b(primes[i]);
				for (int j = primes[i]; j <= n; j += primes[i]) {
					done[j] = true;
				}
			}
			int got = a(1);
			int ex = 0;
			for (int j = 1; j <= n; j++) {
				if (done[j]) continue;
				ex++;
			}
			if (got != ex) {
				for (int i = b - 1; i >= h; i--) {
					if(a(primes[i]) == 1){
						if((long)primes[i] * primes[i] > n){
							int R = n / primes[i];
							for(int j = R;j >= 2;j--){
								if(a(primes[i] * j) == 1){
									c(primes[i]*j);
									return;
								}
							}
							c(primes[i]);
							return;
						}else{
							for(int j = h-1;j >= 0;j--){
								b(primes[j]);
							}
							int ans = 1;
							int rem = n;
							for(int j = i;j >= 0;j--){
								int d = 1;
								for(int q = primes[j];q <= rem;q *= primes[j]){
									if(a(q) == 1){
										ans *= primes[j];
										d = q;
									}else{
										break;
									}
								}
								rem /= d;
							}
							c(ans);
							return;
						}
					}
				}
			}
			b /= 2;
			h /= 2;
		}
		c(1);
	}

	public static int[] enumLowestPrimeFactors(int n)
	{
		int tot = 0;
		int[] lpf = new int[n+1];
		int u = n+32;
		double lu = Math.log(u);
		int[] primes = new int[(int)(u/lu+u/lu/lu*1.5)];
		for(int i = 2;i <= n;i++)lpf[i] = i;
		for(int p = 2;p <= n;p++){
			if(lpf[p] == p)primes[tot++] = p;
			int tmp;
			for(int i = 0;i < tot && primes[i] <= lpf[p] && (tmp = primes[i]*p) <= n;i++){
				lpf[tmp] = primes[i];
			}
		}
		return lpf;
	}

	public static int[] sieveEratosthenes(int n) {
		if (n <= 32) {
			int[] primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
			for (int i = 0; i < primes.length; i++) {
				if (n < primes[i]) {
					return Arrays.copyOf(primes, i);
				}
			}
			return primes;
		}

		int u = n + 32;
		double lu = Math.log(u);
		int[] ret = new int[(int) (u / lu + u / lu / lu * 1.5)];
		ret[0] = 2;
		int pos = 1;

		int[] isnp = new int[(n + 1) / 32 / 2 + 1];
		int sup = (n + 1) / 32 / 2 + 1;

		int[] tprimes = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
		for (int tp : tprimes) {
			ret[pos++] = tp;
			int[] ptn = new int[tp];
			for (int i = (tp - 3) / 2; i < tp << 5; i += tp) ptn[i >> 5] |= 1 << (i & 31);
			for (int j = 0; j < sup; j += tp) {
				for (int i = 0; i < tp && i + j < sup; i++) {
					isnp[j + i] |= ptn[i];
				}
			}
		}

		// 3,5,7
		// 2x+3=n
		int[] magic = {0, 1, 23, 2, 29, 24, 19, 3, 30, 27, 25, 11, 20, 8, 4, 13, 31, 22, 28, 18, 26, 10, 7, 12, 21, 17, 9, 6, 16, 5, 15, 14};
		int h = n / 2;
		for (int i = 0; i < sup; i++) {
			for (int j = ~isnp[i]; j != 0; j &= j - 1) {
				int pp = i << 5 | magic[(j & -j) * 0x076be629 >>> 27];
				int p = 2 * pp + 3;
				if (p > n) break;
				ret[pos++] = p;
				if ((long) p * p > n) continue;
				for (int q = (p * p - 3) / 2; q <= h; q += p) isnp[q >> 5] |= 1 << q;
			}
		}

		return Arrays.copyOf(ret, pos);
	}


	void run() throws Exception
	{
		in = oj ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new E().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}