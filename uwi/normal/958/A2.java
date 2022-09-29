//package hel2018;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;

public class A2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		char[][] s = nm(n,m);
		char[][] t = nm(m,n);
		RollingHashFactory rhf = new RollingHashFactory(2, n+1, new Random());
		RollingHash[] h1 = new RollingHash[n];
		RollingHash[] h2 = new RollingHash[m];
		for(int i = 0;i < n;i++){
			h1[i] = new RollingHash(m+1, rhf);
			for(int j = 0;j < m;j++)h1[i].add(s[i][j]);
		}
		for(int i = 0;i < m;i++){
			h2[i] = new RollingHash(n+1, rhf);
			for(int j = 0;j < n;j++)h2[i].add(t[i][j]);
		}
		
		long[] lhs1 = new long[n-m+1];
		for(int i = 0;i < n-m+1;i++){
			long up = 0, low = 0;
			for(int j = 0;j < m;j++){
				long u = h1[i+j].queryTwin(m)>>>32;
				long l = (int)h1[i+j].queryTwin(m);
				up = (up * rhf.powers[0][m] + u) % rhf.mods[0];
				low = (low * rhf.powers[1][m] + l) % rhf.mods[1];
			}
			lhs1[i] = up<<32|low;
		}
		long[] lhs2 = new long[n-m+1];
		for(int i = 0;i < n-m+1;i++){
			long up = 0, low = 0;
			for(int j = 0;j < m;j++){
				long u = h2[j].queryTwin(i, i+m)>>>32;
				long l = (int)h2[j].queryTwin(i, i+m);
				up = (up * rhf.powers[0][m] + u) % rhf.mods[0];
				low = (low * rhf.powers[1][m] + l) % rhf.mods[1];
			}
			lhs2[i] = up<<32|low;
		}
		for(int i = 0;i < n-m+1;i++){
			for(int j = 0;j < n-m+1;j++){
				if(lhs1[i] == lhs2[j]){
					out.println((i+1) + " " + (j+1));
					return;
				}
			}
		}
		throw new RuntimeException();
	}
	
	public static class RollingHash
	{
		public RollingHashFactory rhf;
		public long[][] buf;
		public int p;
		
		public RollingHash(int bufsize, RollingHashFactory rhf)
		{
			buf = new long[rhf.deg][bufsize+1];
			this.rhf = rhf;
			this.p = 1;
		}
		
		public void add(int c)
		{
			for(int i = 0;i < rhf.deg;i++)buf[i][p] = (buf[i][p-1]*rhf.muls[i]+c)%rhf.mods[i];
			p++;
		}
		
		public void addr(int c)
		{
			for(int i = 0;i < rhf.deg;i++)buf[i][p] = (buf[i][p-1]+rhf.powers[i][p-1]*c)%rhf.mods[i];
			p++;
		}
		
		public long queryTwin(int r)
		{
			return buf[0][r]<<32|buf[1][r];
		}
		
		public long queryTwin(int l, int r)
		{
			assert l <= r;
			assert rhf.deg == 2;
			long h = 0;
			for(int i = 0;i < rhf.deg;i++){
				long v = (buf[i][r] - buf[i][l] * rhf.powers[i][r-l]) % rhf.mods[i];
				if(v < 0)v += rhf.mods[i];
				h = h<<32|v;
			}
			return h;
		}
		
		public long[] query(int l, int r)
		{
			assert l > r;
			long[] h = new long[rhf.deg];
			for(int i = 0;i < rhf.deg;i++){
				h[i] = (buf[i][r] - buf[i][l] * rhf.powers[i][r-l]) % rhf.mods[i];
				if(h[i] < 0)h[i] += rhf.mods[i];
			}
			return h;
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
	
	public static void main(String[] args) throws Exception { new A2().run(); }
	
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