//package round563;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "1";
	
	
	
	// 1 1 2 4
	// 2 240 151347172
	
	// 2 16 1536 14155776
	
	int[] lpf = enumLowestPrimeFactors(1000005);
	int mod = 1000000007;
	int N;
	
	void solve()
	{
		int n = ni();
		if(n == 1){
			out.println(1);
			return;
		}
		if(n == 3){
			out.println(4);
			return;
		}
		N = n;
		int[] dist = new int[n+1];
		dist[1] = 1;
		int max = 1;
		for(int i = 2;i <= n;i++){
			dist[i] = dist[i/lpf[i]] + 1;
			max = Math.max(max, dist[i]);
		}
		long ans = 0;
		for(int i = 1;i <= n;i++){
			if(dist[i] == max){
				ans += go(i);
			}
		}
		out.println(ans%mod);
	}
	
	long go(int n)
	{
		int[][] f = factorFast(n, lpf);
		if(f.length == 1){
			assert f[0][0] == 2;
			long[] dp = new long[f[0][1]+1];
			dp[f[0][1]] = 1;
			for(int i = 1;i <= N-1;i++){
				long[] ndp = new long[f[0][1]+1];
				for(int j = 0;j <= f[0][1];j++){
					int nj = j-1;
					if(nj >= 0){
						long can = (N>>>nj) - (N>>>nj+1);
						ndp[nj] += dp[j] * can;
						ndp[nj] %= mod;
					}
					ndp[j] += dp[j] * ((N>>>j)-i);
					ndp[j] %= mod;
				}
				dp = ndp;
			}
			return dp[0];
		}
		
		assert f.length == 2;
		assert f[0][0] == 2;
		assert f[1][0] == 3;
		assert f[1][1] == 1;
		long[][] dp = new long[2][f[0][1]+1];
		dp[1][f[0][1]] = 1;
		for(int i = 1;i <= N-1;i++){
			long[][] ndp = new long[2][f[0][1]+1];
			for(int k = 0;k < 2;k++){
				for(int j = 0;j <= f[0][1];j++){
					if(dp[k][j] == 0)continue;
					long pre = 1<<j;
					for(int l = 0;l < k;l++)pre *= 3;
					int nj = j-1;
					if(nj >= 0){
						long nex = pre/2;
						long can = N/nex - N/pre;
						ndp[k][nj] += dp[k][j] * can;
						ndp[k][nj] %= mod;
					}
					int nk = k-1;
					if(nk >= 0){
						long nex = pre/3;
						long can = N/nex - N/pre;
						ndp[nk][j] += dp[k][j] * can;
						ndp[nk][j] %= mod;
					}
					if(N/pre-i >= 0){
						ndp[k][j] += dp[k][j] * (N/pre-i);
						ndp[k][j] %= mod;
					}
				}
			}
			dp = ndp;
		}
		return dp[0][0];
//		dfs(n, f);
	}

	
	public static int[][] enumFIF(int n, int mod) {
		int[] f = new int[n + 1];
		int[] invf = new int[n + 1];
		f[0] = 1;
		for (int i = 1; i <= n; i++) {
			f[i] = (int) ((long) f[i - 1] * i % mod);
		}
		long a = f[n];
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
		invf[n] = (int) (p < 0 ? p + mod : p);
		for (int i = n - 1; i >= 0; i--) {
			invf[i] = (int) ((long) invf[i + 1] * (i + 1) % mod);
		}
		return new int[][] { f, invf };
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
			for (int i = 0; i < tot && primes[i] <= lpf[p] && (tmp = primes[i] * p) <= n; i++) {
				lpf[tmp] = primes[i];
			}
		}
		return lpf;
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
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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