//package shinkan;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;

public class S {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		for(int i = 0;i < n;i++)a[i]--;
		RollingHashFactory rhf = new RollingHashFactory(2, n+1, new Random());
		
		DynamicRollingHash forward = new DynamicRollingHash(n, rhf);
		DynamicRollingHash backward = new DynamicRollingHash(n, rhf);
		
		for(int i = 0;i < n;i++){
			forward.add(a[i], 1);
			backward.add(n-1-a[i], 1);
			int wing = Math.min(n-1-a[i], a[i]);
//			tr(wing, a[i]-wing, a[i]+wing+1, n-1-(a[i]+wing), n-1-(a[i]-wing)+1);
//			tr(forward.h(a[i]-wing, a[i]+wing+1), backward.h(n-1-(a[i]+wing), n-1-(a[i]-wing)+1));
			if(forward.h(a[i]-wing, a[i]+wing+1) != backward.h(n-1-(a[i]+wing), n-1-(a[i]-wing)+1)){
				out.println("YES");
				return;
			}
		}
		out.println("NO");
	}

	public static class DynamicRollingHash
	{
		public RollingHashFactory rhf;
		public long[][] fts;
		public int n;
		
		public DynamicRollingHash(int n, RollingHashFactory rhf)
		{
			assert rhf.deg <= 2;
			this.n = n;
			this.rhf = rhf;
			fts = new long[this.rhf.deg][n+3];
		}
		
		public void add(int pos, int x)
		{
			for(int i = 0;i < rhf.deg;i++){
				addFenwick(fts[i], pos, rhf.powers[i][n-1-pos]*x, rhf.mods[i]);
			}
		}
		
		public long h(int l, int r) {
			long ret = 0;
			for(int i = 0;i < rhf.deg;i++){
				long v = (sumFenwick(fts[i], r-1, rhf.mods[i]) - sumFenwick(fts[i], l-1, rhf.mods[i])) * rhf.powers[i][l];
				v %= rhf.mods[i];
				if(v < 0)v += rhf.mods[i];
				ret = ret<<32|v;
			}
			return ret;
		}
		
		public static long sumFenwick(long[] ft, int i, int mod)
		{
			long sum = 0;
			for(i++;i > 0;i -= i&-i){
				sum += ft[i];
				if(sum >= mod)sum -= mod;
			}
			return sum;
		}
		
		public static void addFenwick(long[] ft, int i, long v, int mod)
		{
			v %= mod;
			if(v < 0)v += mod;
			if(v == 0)return;
			int n = ft.length;
			for(i++;i < n;i += i&-i){
				ft[i] += v;
				if(ft[i] >= mod)ft[i] -= mod;
			}
		}
	}

	
	public static class RollingHashFactory
	{
		public int[] mods;
		public int[] muls;
		public long[][] powers;
		public int deg;
		
		public RollingHashFactory(int deg, int n, Random gen)
		{
			this.deg = deg;
			mods = new int[deg];
			muls = new int[deg];
			for(int i = 0;i < deg;i++){
				mods[i] = BigInteger.probablePrime(30, gen).intValue();
				muls[i] = BigInteger.probablePrime(30, gen).intValue();
			}
			powers = new long[deg][n+1];
			for(int i = 0;i < deg;i++){
				powers[i][0] = 1;
				for(int j = 1;j <= n;j++){
					powers[i][j] = powers[i][j-1] * muls[i] % mods[i];
				}
			}
		}
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
	
	public static void main(String[] args) throws Exception { new S().run(); }
	
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