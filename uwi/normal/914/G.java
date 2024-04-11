//package round458;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class G2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	public static long[] mobiusTransform(long[] f)
	{
		int H = Integer.numberOfTrailingZeros(f.length);
		for(int i = 0;i < H;i++){
			for(int j = 0;j < 1<<H;j++){
				if(j<<~i>=0){
					f[j|1<<i] += f[j];
				}
			}
		}
		return f;
	}
	
	public static long[] inverseMobiusTransform(long[] f)
	{
		int H = Integer.numberOfTrailingZeros(f.length);
		for(int i = 0;i < H;i++){
			for(int j = 0;j < 1<<H;j++){
				if(j<<~i>=0){
					f[j|1<<i] -= f[j];
				}
			}
		}
		return f;
	}
	
	public static long[] zetaTransform(long[] f)
	{
		int H = Integer.numberOfTrailingZeros(f.length);
		for(int i = 0;i < H;i++){
			for(int j = 0;j < 1<<H;j++){
				if(j<<~i>=0){
					f[j] += f[j|1<<i];
				}
			}
		}
		return f;
	}
	
	public static long[] inverseZetaTransform(long[] f)
	{
		int H = Integer.numberOfTrailingZeros(f.length);
		for(int i = 0;i < H;i++){
			for(int j = 0;j < 1<<H;j++){
				if(j<<~i>=0){
					f[j] -= f[j|1<<i];
				}
			}
		}
		return f;
	}
	
	long[] and(long[] a, long[] b, int mod)
	{
		long[] ma = zetaTransform(Arrays.copyOf(a, a.length));
		long[] mb = zetaTransform(Arrays.copyOf(b, b.length));
		for(int i = 0;i < ma.length;i++){
			ma[i] = (ma[i] % mod) * (mb[i] % mod) % mod;
		}
		long[] ret = inverseZetaTransform(ma);
		for(int i = 0;i < ret.length;i++){
			ret[i] %= mod;
			if(ret[i] < 0)ret[i] += mod;
		}
		return ret;
	}
	
	public static long[] disjointOr(long[] a, long[] b)
	{
		long[][] rma = rankedMobiusTransform(a);
		long[][] rmb = rankedMobiusTransform(b);
		long[][] rmc = new long[rma.length][rma[0].length];
		for(int i = 0;i < rma.length;i++){
			for(int j = 0;i+j < rma.length;j++){
				for(int k = 0;k < rma[i].length;k++){
					rmc[i+j][k] += rma[i][k] * rmb[j][k];
				}
			}
		}
		return inverseRankedMobiusTransform(rmc);
	}
	
	public static long[][] rankedMobiusTransform(long[] f)
	{
		int H = Integer.numberOfTrailingZeros(f.length);
		long[][] fhat = new long[H+1][];
		for(int i = 0;i <= H;i++){
			long[] ff = new long[f.length];
			for(int j = 0;j < f.length;j++){
				if(Integer.bitCount(j) == i)ff[j] = f[j];
			}
			fhat[i] = mobiusTransform(ff);
		}
		return fhat;
	}
	
	public static long[] inverseRankedMobiusTransform(long[][] fh)
	{
		int H = fh.length-1;
		long[] f = new long[1<<H];
		for(int i = 0;i <= H;i++){
			long[] ff = inverseMobiusTransform(fh[i]);
			for(int j = 0;j < 1<<H;j++){
				if(Integer.bitCount(j) == i)f[j] = ff[j];
			}
		}
		return f;
	}
	
	void solve()
	{
		int n = ni();
		int mod = 1000000007;
		long[] f = new long[1<<17];
		for(int i = 0;i < n;i++)f[ni()]++;
		
		int m = 1<<17;
		long[] ab = disjointOr(f, f);
		
		long[] g = fwht(f);
		for(int i = 0;i < g.length;i++){
			g[i] = g[i] * g[i];
		}
		g = fwht(g);
		for(int i = 0;i < m;i++){
			g[i] >>>= 17;
		}
//		tr(g);
//		tr(f);
//		tr(ab);
		
		long[] F = new long[m+1];
		F[0] = 0; F[1] = 1;
		for(int i = 2;i <= m;i++){
			F[i] = F[i-1] + F[i-2];
			F[i] %= mod;
		}
		
		for(int i = 0;i < m;i++){
			ab[i] = ab[i] % mod * F[i] % mod;
		}
		for(int i = 0;i < m;i++){
			g[i] = g[i] % mod * F[i] % mod;
		}
		for(int i = 0;i < m;i++){
			f[i] = f[i] * F[i] % mod;
		}
		
		long[] ret = and(and(ab, f, mod), g, mod);
		long ans = 0;
		for(int i = 1;i < 1<<17;i*=2){
			ans += ret[i];
		}
		out.println(ans%mod);
	}
	
	public static long[] fwht(long[] a)
	{
		int n = a.length;
		assert (n&n-1) == 0;
		a = Arrays.copyOf(a, n);
		for(int w = Integer.numberOfTrailingZeros(n)-1;w >= 0;w--){
			for(int i = 0;i < n;i++){
				if(i<<~w>=0){
					long nal = a[i]+a[i|1<<w];
					long nar = a[i]-a[i|1<<w];
					a[i] = nal; a[i|1<<w] = nar;
				}
			}
		}
		return a;
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
	
	public static void main(String[] args) throws Exception { new G2().run(); }
	
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