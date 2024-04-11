//package round330;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		int mod = 1000000007;
		int[] lpf = enumLowestPrimeFactors(1000000);
		int[] invs = enumInvs(1000005, mod);
		
		long[] mpp = new long[1000005];
		long[] pmp = new long[1000005];
		for(int i = 2;i < 1000001;i++){
			if(lpf[i] == i){
				mpp[i] = (long)(i-1) * invs[i] % mod;
				pmp[i] = (long)i * invs[i-1] % mod;
			}
		}
		
		long[] prod = new long[n+1];
		prod[0] = 1;
		for(int i = 0;i < n;i++){
			prod[i+1] = prod[i] * a[i] % mod;
		}
		
		int Q = ni();
		long[] ret = new long[Q];
		Arrays.fill(ret, 1);
		int[] prevs = new int[1000005];
		Arrays.fill(prevs, -1);
		int[][] es = new int[n*14+Q][];
		int rp = 0;
		for(int i = 0;i < n;i++){
			int[] f = roughFactorFast(a[i], lpf);
			for(int p : f){
				es[rp++] = new int[]{prevs[p]+1, i-1, -p};
				prevs[p] = i;
			}
		}
		long all = 1;
		for(int i = 0;i < 1000005;i++){
			if(prevs[i] != -1){
				es[rp++] = new int[]{prevs[i]+1, n-1, -i};
				all = all * mpp[i] % mod;
			}
		}
		
		for(int i = 0;i < Q;i++){
			es[rp++] = new int[]{ni()-1, ni()-1, i};
			ret[i] = prod[es[rp-1][1]+1] * invl(prod[es[rp-1][0]], mod) % mod;
		}
		Arrays.sort(es, 0, rp, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[0] != b[0])return a[0] - b[0];
				if(a[1] != b[1])return -(a[1] - b[1]);
				return (a[2] - b[2]);
			}
		});
		
		// 2 3 5 7
		// 1/2*2/3*4/5*6/7
		// 48/210
		// 8/35
		long[] ft = new long[n+3];
		Arrays.fill(ft, 1);
		for(int i = 0;i < rp;i++){
			int[] e = es[i];
			if(e[2] < 0){
				addFenwick(ft, n-e[1], pmp[-e[2]]);
//				tr(-e[2], e, n-e[1], pmp[-e[2]]);
			}else{
//				tr("go", e, e[2], n-e[1], sumFenwick(ft, n-e[1]));
				ret[e[2]] = ret[e[2]] * all % mod * sumFenwick(ft, n-e[1]) % mod;
			}
		}
		for(int i = 0;i < Q;i++){
			out.println(ret[i]);
		}
	}
	
	public static long invl(long a, long mod) {
		long b = mod;
		long p = 1, q = 0;
		while (b > 0) {
			long c = a / b;
			long d;
			d = a;
			a = b;
			b = d % b;
			d = p;
			p = q;
			q = d - c * q;
		}
		return p < 0 ? p + mod : p;
	}
	
	public static final int mod = 1000000007;
	
	public static long sumFenwick(long[] ft, int i)
	{
		long sum = 1;
		for(i++;i > 0;i -= i&-i){
			sum = sum * ft[i] % mod;
		}
		return sum;
	}
	
	public static void addFenwick(long[] ft, int i, long v)
	{
		assert v >= 0 && v < mod;
//		v %= mod;
//		if(v < 0)v += mod;
		if(v == 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i){
			ft[i] = ft[i] * v % mod;
		}
	}
	
	public static long[] restoreFenwick(long[] ft)
	{
		int n = ft.length-1;
		long[] ret = new long[n];
		for(int i = 0;i < n;i++)ret[i] = sumFenwick(ft, i);
		for(int i = n-1;i >= 1;i--){
			ret[i] -= ret[i-1];
			if(ret[i] < 0)ret[i] += mod;
		}
		return ret;
	}
	
	public static int[] roughFactorFast(int n, int[] lpf)
	{
		int[] rf = new int[9];
		int q = 0;
		int pre = -1;
		while(lpf[n] > 0){
			int p = lpf[n];
			if(q == 0 || p != pre){
				rf[q++] = p;
				pre = p;
			}else{
			}
			n /= p;
		}
		return Arrays.copyOf(rf, q);
	}
	
	public static int[] enumInvs(int n, int mod)
	{
		int[] inv = new int[n+1];
		inv[1] = 1;
		for(int i = 2;i <= n;i++){
			inv[i] = (int)(inv[mod%i]*(long)(mod-mod/i)%mod);
		}
		return inv;
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
		int[] magic = { 0, 1, 23, 2, 29, 24, 19, 3, 30, 27, 25, 11, 20, 8, 4,
				13, 31, 22, 28, 18, 26, 10, 7, 12, 21, 17, 9, 6, 16, 5, 15, 14 };
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
	
	public static int[][] factorFast(int n, int[] lpf)
	{
		int[][] f = new int[9][];
		int q = 0;
		while(lpf[n] > 0){
			int p = lpf[n];
			if(q == 0 || p != f[q-1][0]){
				f[q++] = new int[]{p, 1};
			}else{
				f[q-1][1]++;
			}
			n /= p;
		}
		if(n > 1){
			// big prime
			return new int[][]{{n, 1}};
		}
		return Arrays.copyOf(f, q);
	}

	
	public static int[] enumLowestPrimeFactors(int n) {
		int tot = 0;
		int[] lpf = new int[n + 1];
		int u = n + 32;
		double lu = Math.log(u);
		int[] primes = new int[(int) (u / lu + u / lu / lu * 1.5)];
		for (int i = 2; i <= n; i++)
			lpf[i] = i;
		for (int p = 2; p <= n; p++) {
			if (lpf[p] == p)
				primes[tot++] = p;
			int tmp;
			for (int i = 0; i < tot && primes[i] <= lpf[p]
					&& (tmp = primes[i] * p) <= n; i++) {
				lpf[tmp] = primes[i];
			}
		}
		return lpf;
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
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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