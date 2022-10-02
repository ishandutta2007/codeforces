//package memsql.r1;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;
import java.util.Set;
import java.util.TreeSet;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int[] primes = sieveEratosthenes(1000000);
		long n = nl();
		long[][] f = factorX(n, primes);
		Set<Long> set = new TreeSet<Long>();
		for(int i = 0;i <= 62;i++){
			if(n+1 == 1L<<i){
				set.add(n+1);
			}
		}
		for(long d : divisorsF(f)){
			if(d % 2 == 1){
				long k = (d-1)/2;
				long rem = n/d+1-k;
				if(rem > 0 && (rem&rem-1) == 0){
					set.add(rem*d);
				}
			}
		}
		if(set.isEmpty()){
			out.println(-1);
		}else{
			for(long s : set){
				out.println(s);
			}
		}
	}
	
	public static long[] divisorsF(long[][] f)
	{
		int n = 1;
		for(int j = 0;j < f.length;j++){
			n *= (int)(f[j][1]+1);
		}
		long[] divs = new long[n];
		int p = 1;
		divs[0] = 1;
		for(int j = 0;j < f.length;j++){
			for(int q = p-1;q >= 0;q--){
				long b = divs[q];
				for(int k = 0;k < f[j][1];k++){
					b *= f[j][0];
//					if((long)b*b <= n)divs[p++] = b;
					divs[p++] = b;
				}
			}
		}
		return divs;
	}
	
	static long[][] factorX(long n, int[] primes)
	{
		long[][] ret = new long[20][2];
		int rp = 0;
		for(int p : primes){
			if((long)p * p > n)break;
			int i;
			for(i = 0;n % p == 0;n /= p, i++);
			if(i > 0){
				ret[rp][0] = p;
				ret[rp][1] = i;
				rp++;
			}
		}
		if(n == 1)return Arrays.copyOf(ret, rp);
		
		// P^2
		long sq = (long)Math.sqrt(n);
		for(long u = Math.max(2, sq-2);u <= sq+2;u++){
			if(u*u == n){
				ret[rp][0] = u;
				ret[rp][1] = 2;
				rp++;
				return Arrays.copyOf(ret, rp);
			}
		}
		
		// Prime
		if(doMirrorRabin(n)){
			ret[rp][0] = n;
			ret[rp][1] = 1;
			rp++;
			return Arrays.copyOf(ret, rp);
		}
		
		// P*Q
		long f = rho(n);
		if(f == -1)throw new ArithmeticException();
		if(f > n/f)f = n/f;
		ret[rp][0] = f; ret[rp][1] = 1; rp++;
		ret[rp][0] = n/f; ret[rp][1] = 1; rp++;
		return Arrays.copyOf(ret, rp);
	}
	
	public static long mul(long a, long b, long mod)
	{
		a %= mod;
		long ret = 0;
		int x = 63-Long.numberOfLeadingZeros(b);
		for(;x >= 0;x--){
			ret += ret;
			if(ret >= mod)ret -= mod;
			if(b<<63-x<0){
				ret += a;
				if(ret >= mod)ret -= mod;
			}
		}
		return ret;
	}
	
	public static boolean doMirrorRabin(long n)
	{
//		int[] P = {2, 7, 61}; // n<4759123141
		int[] P = {2,3,5,7,11,13,17,19,23}; // n=long
		int s = Long.numberOfTrailingZeros(n-1);
		long d = n-1>>s;
		outer:
		for(int a : P){
			if(a >= n)continue;
			
			long mul = a;
			long ad = 1;
			for(long e = d;e > 0;e>>>=1){
				if((e&1)==1)ad = mul(ad, mul, n);
				mul = mul(mul, mul, n);
			}
			if(ad == 1)continue;
			
			for(int r = 0;r < s;r++){
				if(ad == n-1)continue outer;
				ad = mul(ad, ad, n);
			}
			return false;
		}
		return true;
	}

	static long rho(long n)
	{
		Random gen = new Random();
		for(int u = 0;u < 100;u++){
			long ran = (gen.nextLong()&Long.MAX_VALUE) % n;
			long x = 2, y = 2, d = 1;
			while(d == 1){
				x = (mul(x, x, n)+ran)%n;
				y = (mul(y, y, n)+ran)%n;
				y = (mul(y, y, n)+ran)%n;
				d = gcd(Math.abs(x-y), n);
			}
			if(d < n)return d;
		}
		return -1;
	}
	
	public static long gcd(long a, long b) {
		while (b > 0){
			long c = a;
			a = b;
			b = c % b;
		}
		return a;
	}
	
	
	public static int[] sieveEratosthenes(int n) {
		if(n <= 32){
			int[] primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
			for(int i = 0;i < primes.length;i++){
				if(n < primes[i]){
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

		int[] isp = new int[(n + 1) / 32 / 2 + 1];
		int sup = (n + 1) / 32 / 2 + 1;

		int[] tprimes = { 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
		for(int tp : tprimes){
			ret[pos++] = tp;
			int[] ptn = new int[tp];
			for(int i = (tp - 3) / 2;i < tp << 5;i += tp)
				ptn[i >> 5] |= 1 << (i & 31);
			for(int i = 0;i < tp;i++){
				for(int j = i;j < sup;j += tp)
					isp[j] |= ptn[i];
			}
		}

		// 3,5,7
		// 2x+3=n
		int[] magic = { 0, 1, 23, 2, 29, 24, 19, 3, 30, 27, 25, 11, 20, 8, 4,
				13, 31, 22, 28, 18, 26, 10, 7, 12, 21, 17, 9, 6, 16, 5, 15, 14 };
		int h = n / 2;
		for(int i = 0;i < sup;i++){
			for(int j = ~isp[i];j != 0;j &= j - 1){
				int pp = i << 5 | magic[(j & -j) * 0x076be629 >>> 27];
				int p = 2 * pp + 3;
				if(p > n)
					break;
				ret[pos++] = p;
				for(int q = pp;q <= h;q += p)
					isp[q >> 5] |= 1 << (q & 31);
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
	
	public static void main(String[] args) throws Exception { new B().run(); }
	
	private byte[] inbuf = new byte[1024];
	private int lenbuf = 0, ptrbuf = 0;
	
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