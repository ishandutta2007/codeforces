//package round213;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Random;
import java.util.Set;

public class D3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		long S = System.currentTimeMillis();
		int n = ni();
		long[] a = new long[n];
		for(int i = 0;i < n;i++){
			a[i] = nl();
		}
		
		a = radixSort(a);
		long[] b = new long[n];
		int[] f = new int[n];
		int q = 0;
		for(int i = 0;i < n;i++){
			if(i == 0 || a[i] != a[i-1]){
				b[q++] = a[i];
			}
			f[q-1]++;
		}
		
		int[] primes = sieveEratosthenes(1000000);
		Random gen = new Random();
		Set<Long> aed = new HashSet<Long>();
		long ret = 1;
		int[] ngdiv = new int[100000];
		int ngp = 0;
		for(;System.currentTimeMillis() - S < 3850;){
			long g;
			if(gen.nextBoolean()){
				int u = gen.nextInt(n);
				int v = gen.nextInt(n);
				g = gcd(a[u], a[v]);
			}else{
				int u = gen.nextInt(q);
				int v = gen.nextInt(q);
				g = gcd(b[u], b[v]);
			}
			if(g <= ret)continue;
			inner:
			for(long d : divisors(g, primes)){
				if(d > ret && System.currentTimeMillis() - S < 3850 && aed.add(d)){
					for(int w = 0;w < ngp;w++){
						if(d % ngdiv[w] == 0)continue inner;
					}
					if(isOK(d, b, f, q)){
						ret = d;
					}else{
						if(d < 100000){
							ngdiv[ngp++] = (int)d;
						}
					}
				}
			}
		}
		out.println(ret);
	}
	
	public static long[] radixSort(long[] f)
	{
		long[] to = new long[f.length];
		{
			int[] b = new int[65537];
			for(int i = 0;i < f.length;i++)b[1+(int)(f[i]&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < f.length;i++)to[b[(int)(f[i]&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		{
			int[] b = new int[65537];
			for(int i = 0;i < f.length;i++)b[1+(int)(f[i]>>>16&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < f.length;i++)to[b[(int)(f[i]>>>16&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		{
			int[] b = new int[65537];
			for(int i = 0;i < f.length;i++)b[1+(int)(f[i]>>>32&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < f.length;i++)to[b[(int)(f[i]>>>32&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		{
			int[] b = new int[65537];
			for(int i = 0;i < f.length;i++)b[1+(int)(f[i]>>>48&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < f.length;i++)to[b[(int)(f[i]>>>48&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		return f;
	}
	
	static boolean isOK(long d, long[] a, int[] f, int q)
	{
		int h = 0;
		for(int i = 0;i < q;i++){
			if(a[i] % d == 0)h += f[i];
		}
		return h*2 >= a.length;
	}
	
	public static long[] divisors(long n, int[] primes)
	{
		long[] div = new long[7000];
		div[0] = 1;
		int r = 1;
		
		for(int p : primes){
			if((long)p * p > n)break;
			int i;
			for(i = 0;n % p == 0;n /= p, i++);
			if(i > 0){
				for(int j = r-1;j >= 0;j--){
					long base = div[j];
					for(int k = 0;k < i;k++){
						base *= p;
						div[r++] = base;
					}
				}
			}
		}
		if(n != 1){
			for(int j = r-1;j >= 0;j--){
				div[r++] = div[j] * n;
			}
		}
		return Arrays.copyOf(div, r);
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
	
	public static long gcd(long a, long b) {
		while (b > 0){
			long c = a;
			a = b;
			b = c % b;
		}
		return a;
	}
	
	
	void run() throws Exception
	{
//		int n = 1000000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for(int i = 0;i < n;i++){
//			sb.append(gen.nextInt(1000000000)*120L + " ");
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new D3().run(); }
	
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