//package round485;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	
	boolean[] ans;
	int[] primes = sieveEratosthenes((int)Math.sqrt(1e15));
	
	void solve()
	{
		int t = ni();
		long[][] qs = new long[t][];
		for(int i = 0;i < t;i++){
			qs[i] = new long[]{nl(), nl(), i};
		}
		ans = new boolean[t];
		Arrays.sort(qs, new Comparator<long[]>() {
			public int compare(long[] a, long[] b) {
				return Long.compare(a[1], b[1]);
			}
		});
		
		for(int i = 0;i < t;){
			int j = i;
			while(j < t && qs[i][1] == qs[j][1])j++;
			
			solve(qs[i][1], qs, i, j);
			
			i = j;
		}
		for(boolean v : ans){
			out.println(v ? "YES" : "NO");
		}
	}
	
	void solve(long K, long[][] qs, int l, int r)
	{
		long[] f = facs(K, primes);
		if(f.length == 0){
			for(int i = l;i < r;i++){
				ans[(int)qs[i][2]] = false;
			}
		}else if(f.length == 1){
			for(int i = l;i < r;i++){
				ans[(int)qs[i][2]] = qs[i][0] % K == 0;
			}
		}else if(f.length == 2){
			for(int i = l;i < r;i++){
				ans[(int)qs[i][2]] = representableB(f[0], f[1], qs[i][0]);
			}
		}else{
			long[] res = get(f);
			for(int i = l;i < r;i++){
				ans[(int)qs[i][2]] = res[(int)(qs[i][0]%f[0])] <= qs[i][0]/f[0]; 
			}
		}
	}
	
	// Is there (x,y) which satisfies ax+by=c, x>=0, y>=0?
	boolean representable(long a, long b, long c)
	{
		long[] apr = exgcd(a, b);
		if(c % apr[0] != 0)return false;
		
		long g = apr[0];
		long x = apr[1]*(c/g), y = apr[2]*(c/g);
		// x += b/g, y -= a/g
		if(y < 0){
			long step = (-y+a/g-1) / (a/g);
			x -= step * (b/g); y += step * (a/g);
		}
		if(x < 0){
			long step = (-x+b/g-1) / (b/g);
			x += step * (b/g); y -= step * (a/g);
		}
		return x >= 0 && y >= 0;
	}
	
	boolean representableB(long a, long b, long c)
	{
		long[] apr = exgcd(a, b);
		if(c % apr[0] != 0)return false;
		
		long g = apr[0];
		BigInteger x = BigInteger.valueOf(apr[1]).multiply(BigInteger.valueOf(c/g));
		BigInteger y = BigInteger.valueOf(apr[2]).multiply(BigInteger.valueOf(c/g));
		// x += b/g, y -= a/g
		BigInteger adg = BigInteger.valueOf(a/g);
		BigInteger bdg = BigInteger.valueOf(b/g);
		
		if(y.signum() < 0){
			BigInteger step = y.negate().add(adg).subtract(BigInteger.ONE).divide(adg);
			x = x.subtract(step.multiply(bdg));
			y = y.add(step.multiply(adg));
		}
		if(x.signum() < 0){
			BigInteger step = x.negate().add(bdg).subtract(BigInteger.ONE).divide(bdg);
			x = x.add(step.multiply(bdg));
			y = y.subtract(step.multiply(adg));
		}
		return x.signum() >= 0 && y.signum() >= 0;
	}
	
	public static long[] exgcd(long a, long b)
	{
		if(a == 0 || b == 0)return null;
		int as = Long.signum(a);
		int bs = Long.signum(b);
		a = Math.abs(a); b = Math.abs(b);
		long p = 1, q = 0, r = 0, s = 1;
		while(b > 0){
			long c = a / b;
			long d;
			d = a; a = b; b = d % b;
			d = p; p = q; q = d - c * q;
			d = r; r = s; s = d - c * s;
		}
		return new long[]{a, p * as, r * bs};
	}

	
	long[] get(long[] es)
	{
		assert es.length >= 1;
		Arrays.sort(es);
		int P = (int)es[0];
		
		long[] ds = new long[P];
		Arrays.fill(ds, Long.MAX_VALUE);
		MinHeapL h = new MinHeapL(P);
		h.add(0, 0L);
		ds[0] = 0L;
		while(h.size() > 0){
			int cur = h.argmin();
			long v = h.remove(cur);
			for(long e : es){
				int nex = (int)((cur + e) % P);
				long nv = (cur + e) / P + v;
				if(nv < ds[nex])h.update(nex, ds[nex] = nv);
			}
		}
		return ds;
	}
	
	public static class MinHeapL {
		public long[] a;
		public int[] map;
		public int[] imap;
		public int n;
		public int pos;
		public static long INF = Long.MAX_VALUE;
		
		public MinHeapL(int m)
		{
			n = Integer.highestOneBit((m+1)<<1);
			a = new long[n];
			map = new int[n];
			imap = new int[n];
			Arrays.fill(a, INF);
			Arrays.fill(map, -1);
			Arrays.fill(imap, -1);
			pos = 1;
		}
		
		public long add(int ind, long x)
		{
			int ret = imap[ind];
			if(imap[ind] < 0){
				a[pos] = x; map[pos] = ind; imap[ind] = pos;
				pos++;
				up(pos-1);
			}
			return ret != -1 ? a[ret] : x;
		}
		
		public long update(int ind, long x)
		{
			int ret = imap[ind];
			if(imap[ind] < 0){
				a[pos] = x; map[pos] = ind; imap[ind] = pos;
				pos++;
				up(pos-1);
			}else{
				a[ret] = x;
				up(ret);
				down(ret);
			}
			return x;
		}
		
		public long remove(int ind)
		{
			if(pos == 1)return INF;
			if(imap[ind] == -1)return INF;
			
			pos--;
			int rem = imap[ind];
			long ret = a[rem];
			map[rem] = map[pos];
			imap[map[pos]] = rem;
			imap[ind] = -1;
			a[rem] = a[pos];
			a[pos] = INF;
			map[pos] = -1;
			
			up(rem);
			down(rem);
			return ret;
		}
		
		public long min() { return a[1]; }
		public int argmin() { return map[1]; }
		public int size() {	return pos-1; }
		
		private void up(int cur)
		{
			for(int c = cur, p = c>>>1;p >= 1 && a[p] > a[c];c>>>=1, p>>>=1){
				long d = a[p]; a[p] = a[c]; a[c] = d;
				int e = imap[map[p]]; imap[map[p]] = imap[map[c]]; imap[map[c]] = e;
				e = map[p]; map[p] = map[c]; map[c] = e;
			}
		}
		
		private void down(int cur)
		{
			for(int c = cur;2*c < pos;){
				int b = a[2*c] < a[2*c+1] ? 2*c : 2*c+1;
				if(a[b] < a[c]){
					long d = a[c]; a[c] = a[b]; a[b] = d;
					int e = imap[map[c]]; imap[map[c]] = imap[map[b]]; imap[map[b]] = e;
					e = map[c]; map[c] = map[b]; map[b] = e;
					c = b;
				}else{
					break;
				}
			}
		}
	}
	
	public static long[] facs(long n, int[] primes)
	{
		long[] ret = new long[14];
		int rp = 0;
		for(int p : primes){
			if((long)p * p > n)break;
			int i;
			for(i = 0;n % p == 0;n /= p, i++);
			if(i > 0)ret[rp++] = p;
		}
		if(n != 1)ret[rp++] = n;
		return Arrays.copyOf(ret, rp);
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
	
	
	public static void main(String[] args) throws Exception { new F().run(); }
	
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