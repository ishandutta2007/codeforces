//package educational.round049;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class G2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	// 11 2 3 3 3 2 2 3
	
	void solve()
	{
		long m = nl(), x = nl();
		int[] primes = sieveEratosthenes(10000000);
		long[] ds = enumDivisors(m, primes);
		Arrays.sort(ds);
		long[] gf = factor(m, primes);
		
		long ans = 0;
		for(long d : ds){
			long t = totient(d, gf);
			long[] f = factor(t, primes);
			long P = period(x%d, d, f, t);
			assert t % P == 0;
			ans += t / P;
//			tr(d, t, period(x%d, d, f, t));
		}
		out.println(ans);
	}
	
	long period(long x, long d, long[] f, long t)
	{
		if(d > 1e9){
			// x^k=1 (mod d)
			assert powSafe(x, t, d) == 1%d;
			for(long e : f){
				while(t % e == 0 && powSafe(x, t/e, d) == 1%d){
					t /= e;
				}
			}
		}else{
			assert pow(x, t, d) == 1%d;
			for(long e : f){
				while(t % e == 0 && pow(x, t/e, d) == 1%d){
					t /= e;
				}
			}
		}
		return t;
	}
	
	public static long pow(long a, long n, long mod) {
		//		a %= mod;
		long ret = 1;
		int x = 63 - Long.numberOfLeadingZeros(n);
		for (; x >= 0; x--) {
			ret = ret * ret % mod;
			if (n << 63 - x < 0)
				ret = ret * a % mod;
		}
		return ret;
	}

	
	public static long powSafe(long a, long n, long mod)
	{
//		a %= mod;
		long ret = 1; // 1%mod if mod=1,n=0
		int x = 63-Long.numberOfLeadingZeros(n);
		for(;x >= 0;x--){
			ret = mulEx(ret, ret, mod);
			if(n<<~x<0)ret = mulEx(ret, a, mod);
		}
		return ret;
	}
	
	public static long mulEx(long a, long b, long mod)
	{
		if(a >= mod || a < 0)a %= mod;
		if(a < 0)a += mod;
		if(b >= mod || b < 0)b %= mod;
		if(b < 0)b += mod;
		
		long ret = 0;
		int x = 63-Long.numberOfLeadingZeros(b);
		for(;x >= 0;x--){
			ret += ret;
			if(Long.compareUnsigned(ret, mod) >= 0)ret -= mod;
			if(b<<~x<0){
				ret += a;
				if(Long.compareUnsigned(ret, mod) >= 0)ret -= mod;
			}
		}
		return ret;
	}
	
	

	
	public static long totient(long n, long[] primes)
	{
		long ret = n;
		for(long p : primes){
			if((long)p * p > n)break;
			if(n % p == 0){
				ret /= p;
				ret *= p - 1;
			}
			while(n % p == 0)n /= p;
		}
		if(n != 1){
			ret /= n;
			ret *= n - 1;
		}
		return ret;
	}

	
	public static long[] factor(long n, int[] primes)
	{
		long[] ret = new long[20];
		int rp = 0;
		for(int p : primes){
			if((long)p * p > n)break;
			int i;
			for(i = 0;n % p == 0;n /= p, i++);
			if(i > 0){
				ret[rp] = p;
				rp++;
			}
		}
		if(n != 1){
			ret[rp] = n;
			rp++;
		}
		return Arrays.copyOf(ret, rp);
	}

	
	public static long[] enumDivisors(long n, int[] primes)
	{
		int m = 1;
		long[] divs = {1L};
		int t = 1;
		long u = n;
		for(int p : primes){
			if((long)p*p > u)break;
			int e = 0;
			while(u % p == 0){
				u /= p;
				e++;
			}
			if(e > 0){
				divs = Arrays.copyOf(divs, t*(e+1));
				for(int q = t-1;q >= 0;q--){
					long b = divs[q];
					for(int k = 0;k < e;k++){
						b *= p;
//						if((long)b*b <= n)divs[t++] = b;
						divs[t++] = b;
					}
				}
				m *= e+1;
			}
		}
		if(u > 1){
			long p = u;
			int e = 1;
			divs = Arrays.copyOf(divs, t*(e+1));
			for(int q = t-1;q >= 0;q--){
				long b = divs[q];
				for(int k = 0;k < e;k++){
					b *= p;
//					if((long)b*b <= n)divs[t++] = b;
					divs[t++] = b;
				}
			}
			m *= e+1;
		}
		
		return Arrays.copyOf(divs, t);
	}	

	
	public static int[][] factor(int n, int[] primes)
	{
		int[][] ret = new int[9][2];
		int rp = 0;
		for(int p : primes){
			if(p * p > n)break;
			int i;
			for(i = 0;n % p == 0;n /= p, i++);
			if(i > 0){
				ret[rp][0] = p;
				ret[rp][1] = i;
				rp++;
			}
		}
		if(n != 1){
			ret[rp][0] = n;
			ret[rp][1] = 1;
			rp++;
		}
		return Arrays.copyOf(ret, rp);
	}

	
	public static int gcd(int a, int b) {
		while (b > 0) {
			int c = a;
			a = b;
			b = c % b;
		}
		return a;
	}
	
	public static int[] sieveEratosthenes(int n) {
		if (n <= 32) {
			int[] primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
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

		int[] tprimes = { 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
		for (int tp : tprimes) {
			ret[pos++] = tp;
			int[] ptn = new int[tp];
			for (int i = (tp - 3) / 2; i < tp << 5; i += tp)
				ptn[i >> 5] |= 1 << (i & 31);
			for (int j = 0; j < sup; j += tp) {
				for (int i = 0; i < tp && i + j < sup; i++) {
					isnp[j + i] |= ptn[i];
				}
			}
		}

		// 3,5,7
		// 2x+3=n
		int[] magic = { 0, 1, 23, 2, 29, 24, 19, 3, 30, 27, 25, 11, 20, 8, 4, 13, 31, 22, 28, 18, 26, 10, 7, 12, 21, 17,
				9, 6, 16, 5, 15, 14 };
		int h = n / 2;
		for (int i = 0; i < sup; i++) {
			for (int j = ~isnp[i]; j != 0; j &= j - 1) {
				int pp = i << 5 | magic[(j & -j) * 0x076be629 >>> 27];
				int p = 2 * pp + 3;
				if (p > n)
					break;
				ret[pos++] = p;
				if ((long) p * p > n)
					continue;
				for (int q = (p * p - 3) / 2; q <= h; q += p)
					isnp[q >> 5] |= 1 << q;
			}
		}

		return Arrays.copyOf(ret, pos);
	}

	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new G2().run(); }
	
	private byte[] inbuf = new byte[1024];
	public int lenbuf = 0, ptrbuf = 0;
	
	private int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
	
	private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
	private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
	
	private double nd() { return Double.parseDouble(ns()); }
	private char nc() { return (char)skip(); }
	
	private String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	private char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
	
	private char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}
	
	private int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}
	
	private int ni()
	{
		int num = 0, b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private long nl()
	{
		long num = 0;
		int b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}