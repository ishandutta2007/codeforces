//package round635;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		long[] bas = new long[64];
		for(int i = 0;i < n;i++){
			long x = nl();
			int h = 63-Long.numberOfLeadingZeros(x);
			while(x != 0){
				if(bas[h] != 0){
					x ^= bas[h];
					h = 63-Long.numberOfLeadingZeros(x);
				}else{
					bas[h] = x;
				}
			}
		}
		
		long mask = 0;
		for(int i = 0;i < 64;i++){
			if(bas[i] != 0)mask |= 1L<<i;
		}
		
		int h = m/2;
		long[] f = new long[1<<h];
		for(int i = 0;i < 1<<h;i++){
			if((i&mask) == i){
				int x = 0;
				for(int j = 0;j < h;j++){
					if(i<<~j<0)x ^= bas[j];
				}
				f[x]++;
			}
		}
		
		long[][] g = new long[m-h+1][1<<h];
		for(int i = 0;i < 1<<m-h;i++){
			if((i&(mask>>>h)) == i){
				int x = 0;
				int u = 0;
				for(int j = 0;j < m-h;j++){
					if(i<<~j<0){
						x ^= bas[j+h];
						u ^= bas[j+h]>>>h;
					}
				}
				x &= (1<<h)-1;
				g[Long.bitCount(u)][x]++;
			}
		}
		
		int mod = 998244353;
		long last = pow(2, n-Long.bitCount(mask), mod);
		long[] ans = new long[m+1];
		long[] ff = fwht(f, mod);
		long i2 = invl(pow(2, h, mod), mod);
		for(int i = 0;i <= m-h;i++){
			long[] gg = fwht(g[i], mod);
			for(int j = 0;j < f.length;j++){
				gg[j] = gg[j] * ff[j] % mod;
			}
			gg = fwht(gg, mod);
			for(int j = 0;j < gg.length;j++){
				ans[Integer.bitCount(j)+i] += gg[j];
			}
		}
		
		last = last * i2 % mod;
		
		for(int i = 0;i <= m;i++){
			out.print(ans[i] % mod * last % mod + " ");
		}
		out.println();
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

	
	public static long[] fwht(long[] a, int mod)
	{
		int n = a.length;
		assert (n&n-1) == 0;
		a = Arrays.copyOf(a, n);
		for(int w = Integer.numberOfTrailingZeros(n)-1;w >= 0;w--){
			for(int i = 0;i < n;i++){
				if(i<<~w>=0){
					long nal = a[i]+a[i|1<<w];
					long nar = a[i]-a[i|1<<w];
					if(nal >= mod)nal -= mod;
					if(nar < 0)nar += mod;
					a[i] = nal; a[i|1<<w] = nar;
				}
			}
		}
		return a;
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

	
	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E3().run(); }
	
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