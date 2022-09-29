//package round365;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		long K = nl();
		int[] primes = sieveEratosthenes(1000005);
		long[][] F = factor(K, primes);
		
		long[] a = new long[n];
		for(int i = 0;i < n;i++){
			a[i] = nl();
		}
		if(K == 1){
			long min = Long.MAX_VALUE;
			int arg = -1;
			for(int i = 0;i < n;i++){
				if(a[i] < min){
					min = a[i];
					arg = i;
				}
			}
			out.println(1);
			out.println(arg+1);
			return;
		}
		
		int m = 1;
		int[] lim = new int[F.length];
		int p = 0;
		for(long[] e : F){
			m *= (int)(e[1]+1);
			lim[p++] = (int)e[1]+1;
		}
		
		long[][] dp = new long[n+1][m];
		int[][] prev = new int[n+1][m];
		long I = Long.MAX_VALUE / 3 * 2;
		for(int i = 0;i <= n;i++){
			Arrays.fill(dp[i], I);
			Arrays.fill(prev[i], -1);
		}
		dp[0][0] = 0;
		for(int i = 0;i < n;i++){
			int[] es = new int[F.length];
			long v = a[i];
			for(int j = 0;j < F.length;j++){
				for(int k = 0;k < F[j][1];k++){
					if(v % F[j][0] == 0){
						es[j]++;
						v /= F[j][0];
					}else{
						break;
					}
				}
			}
			for(int j = 0;j < m;j++){
				dp[i+1][j] = dp[i][j];
				prev[i+1][j] = j;
			}
			
			int[] h = new int[p];
			int j = 0;
			do{
				int nj = 0;
				for(int q = 0;q < h.length;q++){
					nj = nj * lim[q] + Math.min(lim[q]-1, h[q] + es[q]);
				}
				long nv = dp[i][j] + (1L<<51) + a[i];
				if(nv < dp[i+1][nj]){
					dp[i+1][nj] = nv;
					prev[i+1][nj] = j;
				}
				j++;
			}while(inc(h, lim));
		}
		if(dp[n][m-1] >= I){
			out.println(-1);
		}else{
			out.println(dp[n][m-1]>>>51);
			int he = m-1;
			for(int i = n-1;i >= 0;i--){
				int phe = prev[i+1][he];
				if(phe != he){
					out.print((i+1) + " ");
				}
				he = phe;
			}
			out.println();
		}
	}
	
	public static boolean inc(int[] b, int[] a)
	{
		for(int i = b.length-1;i >= 0;i--){
			if(++b[i] < a[i])return true;
			b[i] = 0;
		}
		return false;
	}
	
	public static long encInc(int[] a, int[] lim)
	{
		long code = 0;
		for(int i = 0;i < a.length;i++){
			code = code * lim[i] + a[i];
		}
		return code;
	}
	
	public static int[] decInc(long code, int[] lim)
	{
		int n = lim.length;
		int[] a = new int[n];
		for(int i = n-1;i >= 0;i--){
			a[i] = (int)(code % lim[i]);
			code /= lim[i];
		}
		return a;
	}

	
	public static long[][] factor(long n, int[] primes) {
		long[][] ret = new long[18][2];
		int rp = 0;
		for (int p : primes) {
			if ((long)p * p > n)
				break;
			int i;
			for (i = 0; n % p == 0; n /= p, i++)
				;
			if (i > 0) {
				ret[rp][0] = p;
				ret[rp][1] = i;
				rp++;
			}
		}
		if (n != 1) {
			ret[rp][0] = n;
			ret[rp][1] = 1;
			rp++;
		}
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
//		int n = 1000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(963761198400L + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append(963761198400L + " ");
//		}
//		INPUT = sb.toString();

		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E2().run(); }
	
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