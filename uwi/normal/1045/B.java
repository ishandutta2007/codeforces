//package bubble11;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Random;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), mod = ni();
		int[] a = na(n);
		int[] b = new int[n];
		for(int i = 0;i < n;i++){
			b[i] = (a[0] + a[i]) % mod;
		}
		
		RollingHashFactory rhf = new RollingHashFactory(2, 2*n+3, new Random(1));
		RollingHash rh = new RollingHash(2*n+3, rhf);
		for(int i = 0;i < n;i++){
			rh.add(a[i]);
		}
		for(int i = 0;i < n;i++){
			rh.add(a[i]+mod);
		}
		RollingHash rhr = new RollingHash(3*n+3, rhf);
		for(int i = 0;i < n;i++){
			rhr.add(a[n-1-i]+mod);
		}
		for(int i = 0;i < n;i++){
			rhr.add(a[n-1-i]);
		}
		for(int i = 0;i < n;i++){
			rhr.add(a[n-1-i]);
		}
		
		long[] M = new long[2];
		for(int j = 0;j < 2;j++){
			for(int i = 0;i < n;i++){
				M[j] = M[j] * rhf.muls[j] + 1;
				M[j] %= rhf.mods[j];
			}
		}
//		tr(a);
//		tr(M);
		
		List<Integer> anss = new ArrayList<>();
		long[] A = rh.query(0, 0+n);
		for(int i = 0;i < n;i++){
			// (i-n,i], [i,i+n)
			long[] B = rhr.query(n-1-(i+n)+n, n-1-i+n);
			long s = a[0] + mod + a[i];
//			tr(A, B,s*M[0]-B[0], s, M[0]);
			if(
					(A[0] - (s * M[0] - B[0])) % rhf.mods[0] == 0 &&
					(A[1] - (s * M[1] - B[1])) % rhf.mods[1] == 0
					){
				anss.add(b[i]);
			}
		}
		out.println(anss.size());
		Collections.sort(anss);
		for(int x : anss){
			out.print(x + " ");
		}
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
			assert l <= r;
			long[] h = new long[rhf.deg];
			for(int i = 0;i < rhf.deg;i++){
				h[i] = (buf[i][r] - buf[i][l] * rhf.powers[i][r-l]) % rhf.mods[i];
				if(h[i] < 0)h[i] += rhf.mods[i];
			}
			return h;
		}
		
		public static long add(long a, long b, int w, RollingHashFactory rhf)
		{
			assert rhf.deg == 2;
			long high = ((a>>>32) * rhf.powers[0][w] + (b>>>32)) % rhf.mods[0];
			long low = ((long)(int)a * rhf.powers[1][w] + (int)b) % rhf.mods[1];
			return high<<32|low;
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
			muls[0] = 100;
			mods[0] = 1000000007;
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
	
	public static void main(String[] args) throws Exception { new B().run(); }
	
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