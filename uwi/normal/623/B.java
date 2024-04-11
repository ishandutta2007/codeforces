//package round342aimtech;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Set;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), a = ni(), b = ni();
		int[] t = na(n);
		long min = Long.MAX_VALUE;
		int[] primes = sieveEratosthenes(100000);
		for(int k = t[0]-1;k <= t[0]+1;k++){
			int[] f = facs(k, primes);
			for(int p : f){
				min = Math.min(min, go(t, a, b, p));
			}
		}
		for(int k = t[n-1]-1;k <= t[n-1]+1;k++){
			int[] f = facs(k, primes);
			for(int p : f){
				min = Math.min(min, go(t, a, b, p));
			}
		}
		out.println(min);
	}
	
	
	
	Set<Integer> ved = new HashSet<>();
	
	long go(int[] t, int a, int b, int d)
	{
		if(d == 1 || !ved.add(d))return Long.MAX_VALUE;
		int n = t.length;
		long I = Long.MAX_VALUE/10;
		long[] cost = new long[n];
		for(int i = 0;i < n;i++){
			int rem = t[i] % d;
			if(rem == 0)continue;
			if(rem == 1 || rem == d-1){
				cost[i] = b;
			}else{
				cost[i] = I;
			}
		}
		long[] prefix = new long[n+1];
		int fi = -1;
		int li = -1;
		for(int i = 0;i < n;i++){
			if(cost[i] == I){
				if(fi == -1)fi = i;
				li = i;
			}
		}
		if(fi == -1)fi = n;
		if(li == -1)li = -1;
		
		for(int i = 0;i < n;i++){
			prefix[i+1] = prefix[i] + cost[i] - a;
		}
		long suf = 0;
		long sufmin = Long.MAX_VALUE;
		for(int i = n-1;i > li;i--){
			suf = suf + cost[i] - a;
			sufmin = Math.min(sufmin, suf);
		}
		long min = sufmin;
		suf = 0;
		sufmin = 0;
		for(int i = n;i > 0;i--){
			if(i <= fi){
				min = Math.min(min, prefix[i] + sufmin);
			}
			if(i-1 >= li+1){
				suf = suf + cost[i-1] - a;
				sufmin = Math.min(sufmin, suf);
			}
		}
		
		return min + (long)n*a;
	}
	
	
	public static int[] facs(int n, int[] primes)
	{
		int[] ret = new int[9];
		int rp = 0;
		for(int p : primes){
			if(p * p > n)break;
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