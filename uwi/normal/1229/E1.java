//package round588;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E1 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	int Q;
	
	void solve()
	{
		int n = ni();
		int[][] ps = new int[n][];
		for(int i = 0;i < n;i++){
			ps[i] = na(n);
		}
		
		if(n % 2 == 1){
			n++;
			int[][] nps = new int[n][n];
			nps[n-1][n-1] = 100;
			for(int i = 0;i < n-1;i++){
				for(int j = 0;j < n-1;j++){
					nps[i][j] = ps[i][j];
				}
			}
			ps = nps;
		}
		
		if(n == 6)Q = 20;
		if(n == 4)Q = 6;
		if(n == 2)Q = 2;
		
		long ih = invl(100, mod);
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				ps[i][j] = (int)(ps[i][j] * ih % mod);
			}
		}
		
		int h = n/2;
		long[] l = go(Arrays.copyOfRange(ps, 0, h));
		long[] r = go(Arrays.copyOfRange(ps, h, n));
		long[] nl = new long[l.length];
		for(int i = 0;i < l.length;i++){
			int ii = i;
			for(int j = 0, k = Q-1;j < k;j++,k--){
				if((i>>>j&1) != (i>>>k&1)){
					ii ^= 1<<j|1<<k;
				}
			}
			nl[ii] = l[i];
		}
		l = nl;
		
		long[] zl = zetaTransform(l);
		long[] zr = zetaTransform(r);
		for(int i = 0;i < zl.length;i++){
			zl[i] = zl[i] * zr[i] % mod;
		}
		long[] me = inverseZetaTransform(zl);
		long ans = 0;
		for(int i = 1;i < me.length;i++){
			ans += me[i];
		}
		out.println(ans%mod);
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

	
	public long[] zetaTransform(long[] f)
	{
		int H = Integer.numberOfTrailingZeros(f.length);
		for(int i = 0;i < H;i++){
			for(int j = 0;j < 1<<H;j++){
				if(j<<~i>=0){
					f[j] += f[j|1<<i];
					if(f[j] >= mod)f[j] -= mod;
				}
			}
		}
		return f;
	}
	
	public long[] inverseZetaTransform(long[] f)
	{
		int H = Integer.numberOfTrailingZeros(f.length);
		for(int i = 0;i < H;i++){
			for(int j = 0;j < 1<<H;j++){
				if(j<<~i>=0){
					f[j] -= f[j|1<<i];
					if(f[j] < 0)f[j] += mod;
				}
			}
		}
		return f;
	}

	
	int mod = 1000000007;
	
	long[] go(int[][] ps)
	{
		int h = ps.length;
		int n = ps[0].length;
		long[] l = new long[1<<Q];
		for(int i = 0;i < 1<<h*n;i++){
			long P = 1;
			for(int j = 0;j < h;j++){
				for(int k = 0;k < n;k++){
					if(i<<~(j*n+k)<0){
						P = P * ps[j][k] % mod;
					}else{
						P = P * (mod+1-ps[j][k]) % mod;
					}
				}
			}
			int ptn = 0;
			int p = 0;
			for(int j = 0;j < 1<<n;j++){
				if(Integer.bitCount(j) == h){
					int[] ds = toArray(j);
					int[] ord = ds;
					inner:
					do{
						for(int k = 0;k < h;k++){
							if(i<<~(k*n+ds[k])>=0)continue inner;
						}
						ptn |= 1<<p;
						break;
					}while(nextPermutation(ord));
					p++;
				}
			}
			l[ptn] += P;
			if(l[ptn] >= mod)l[ptn] -= mod;
		}
		return l;
	}
	
	public static int[] toArray(long x)
	{
		int[] ret = new int[5];
		int p = 0;
		for(;x != 0;x &= x-1){
			ret[p++] = Long.numberOfTrailingZeros(x);
		}
		return Arrays.copyOf(ret, p);
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

	
	void run() throws Exception
	{
//		int n = 6, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for (int i = 0; i < n*n; i++) {
//			sb.append(i + " ");
//		}
//		INPUT = sb.toString();

		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E1().run(); }
	
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