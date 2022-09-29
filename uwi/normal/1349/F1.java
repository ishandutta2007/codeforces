//package round641;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class F1 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	// 2:1,1
	// 3:1,4,1
	
	void solve()
	{
		int n = ni();
		long[][] en = new long[n+1][n+1];
		en[1][1] = 1;
		int mod = 998244353;
		for(int i = 2;i <= n;i++){
			for(int j = 1;j <= i;j++){
				en[i][j] = (j * en[i-1][j] + (i-j+1) * en[i-1][j-1]) % mod;
			}
		}
		int[][] fif = enumFIF(100000, mod);
		long[] ans = new long[n];
		for(int i = 0;i < n;i++){
			long c = C(n, i+1, mod, fif) * fif[0][n-(i+1)] % mod;
			for(int j = 0;j <= i;j++){
				ans[j] += en[i+1][j+1] * c;
				ans[j] %= mod;
			}
		}
		for(int i = 0;i < n;i++){
			out.print(ans[i] + " ");
		}
		out.println();
		
//		int n = ni();
//		int[] a = new int[n];
//		for(int i = 0;i < n;i++)a[i] = i;
//		int[] f = new int[n];
//		do{
//			int ct = 0;
//			for(int i = 0;i < n-1;i++){
//				if(a[i] > a[i+1]){
//					ct++;
//				}
//			}
//			f[ct]++;
//		}while(nextPermutation(a));
//		tr(f);
		
//		int[] a = new int[n];
//		int ct = 0;
//		int[] f = new int[n];
//		do{
//			int hit = 0;
//			int ex = 0;
//			for(int i = 0;i < n;i++){
//				ex |= 1<<a[i];
//				for(int j = 0;j < i;j++){
//					if(a[i] - a[j] == 1){
//						hit |= 1<<a[i];
//					}
//				}
//			}
//			if(ex<<~0>=0)continue;
//			ex ^= 1;
//			if(ex == hit && Integer.bitCount(hit+2) == 1){
//				tr(a);
//				for(int v : a){
//					f[v]++;
//				}
//				ct++;
//			}
//		}while(inc(a, n));
//		tr(ct);
//		tr(f);
//		
//		long[] dp = new long[n+2];
//		dp[0] = 1;
//		for(int i = 1;i <= n;i++){
//			long[] ndp = new long[n+2];
//			ndp[0] = 3L * dp[0] + dp[1];
//			for(int j = 1;j <= n;j++){
//				ndp[j] = dp[j-1] + 4L*dp[j] + dp[j+1];
//			}
//			for(int j = 0;j <= n;j++){
//				ndp[j] %= mod;
//			}
//			dp = ndp;
//			tr(dp);
//		}
	}
	
	public static boolean nextPermutation(int[] a) {
		int n = a.length;
		int i;
		for (i = n - 2; i >= 0 && a[i] >= a[i + 1]; i--)
			;
		if (i == -1)
			return false;
		int j;
		for (j = i + 1; j < n && a[i] < a[j]; j++)
			;
		int d = a[i];
		a[i] = a[j - 1];
		a[j - 1] = d;
		for (int p = i + 1, q = n - 1; p < q; p++, q--) {
			d = a[p];
			a[p] = a[q];
			a[q] = d;
		}
		return true;
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
	
	public static long C(int n, int r, int mod, int[][] fif) {
		if (n < 0 || r < 0 || r > n)
			return 0;
		return (long) fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod;
	}


	
	public static boolean inc(int[] a, int base) {
		int n = a.length;
		int i;
		for (i = n - 1; i >= 0 && a[i] == base - 1; i--)
			;
		if (i == -1)
			return false;

		a[i]++;
		Arrays.fill(a, i + 1, n, 0);
		return true;
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
	
	public static void main(String[] args) throws Exception { new F1().run(); }
	
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