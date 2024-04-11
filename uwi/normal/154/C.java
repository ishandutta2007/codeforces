//package prac;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Random;

public class P154C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
		}
		long ret = 0;
		int[][] g = packU(n, from, to);
		int[] temp = new int[n];
		Random gen = new Random();
		RollingHashFactory rhf = new RollingHashFactory(2, 1000005, gen);
		{
			long[] hs = new long[n];
			for(int i = 0;i < n;i++){
				int p = 0;
				for(int j = 0;j < g[i].length;j++){
					temp[p++] = g[i][j];
				}
				temp[p++] = i;
				int[] my = Arrays.copyOf(temp, p);
				my = shuffle(my, gen);
				Arrays.sort(my);
				RollingHashOneState rhos = new RollingHashOneState(rhf);
				for(int j = 0;j < p;j++){
					rhos.add(my[j]+1000000009);
				}
				hs[i] = rhos.queryTwin();
			}
			Arrays.sort(hs);
			int same = 0;
			for(int i = 0;i < n;i++){
				if(i > 0 && hs[i] == hs[i-1]){
					same++;
					ret += same;
				}else{
					same = 0;
				}
			}
		}
		{
			long[] hs = new long[n];
			for(int i = 0;i < n;i++){
				int p = 0;
				for(int j = 0;j < g[i].length;j++){
					temp[p++] = g[i][j];
				}
				int[] my = Arrays.copyOf(temp, p);
				my = shuffle(my, gen);
				Arrays.sort(my);
				RollingHashOneState rhos = new RollingHashOneState(rhf);
				for(int j = 0;j < p;j++){
					rhos.add(my[j]+1000000009);
				}
				hs[i] = rhos.queryTwin();
			}
			Arrays.sort(hs);
			int same = 0;
			for(int i = 0;i < n;i++){
				if(i > 0 && hs[i] == hs[i-1]){
					same++;
					ret += same;
				}else{
					same = 0;
				}
			}
		}
		out.println(ret);
	}
	
	public static int[] shuffle(int[] a, Random gen){ for(int i = 0, n = a.length;i < n;i++){ int ind = gen.nextInt(n-i)+i; int d = a[i]; a[i] = a[ind]; a[ind] = d; } return a; }

	
	public static class RollingHashOneState
	{
		public static boolean DEBUG = false;
		public RollingHashFactory rhf;
		public long[] buf;
		public int p;
		public List<Integer> hist;
		
		public RollingHashOneState(RollingHashFactory rhf)
		{
			buf = new long[rhf.deg];
			this.rhf = rhf;
			this.p = 1;
			if(DEBUG)this.hist = new ArrayList<>();
		}
		
		public void add(int c)
		{
			for(int i = 0;i < rhf.deg;i++)buf[i] = (buf[i]*rhf.muls[i]+c)%rhf.mods[i];
			p++;
			if(DEBUG)hist.add(c);
		}
		
		public void addr(int c)
		{
			for(int i = 0;i < rhf.deg;i++)buf[i] = (buf[i]+rhf.powers[i][p-1]*c)%rhf.mods[i];
			p++;
			if(DEBUG)hist.add(0, c);
		}
		
		public void add(RollingHashOneState h)
		{
			for(int i = 0;i < rhf.deg;i++)buf[i] = (buf[i]*rhf.powers[i][h.p-1]+h.buf[i])%rhf.mods[i];
			p += h.p-1;
			if(DEBUG)hist.addAll(h.hist);
		}
		
		public void addr(RollingHashOneState h)
		{
			for(int i = 0;i < rhf.deg;i++)buf[i] = (buf[i]+rhf.powers[i][p-1]*h.buf[i])%rhf.mods[i];
			p += h.p-1;
			if(DEBUG)hist.addAll(0, h.hist);
		}
		
		public long queryTwin()
		{
			return buf[0]<<32|buf[1];
		}
		
		public static long mergeTwin(RollingHashOneState l, RollingHashOneState r)
		{
			assert l.rhf == r.rhf;
			assert l.rhf.deg == 2;
			long h = 0;
			for(int i = 0;i < l.rhf.deg;i++)h = h<<32 | (l.buf[i]*l.rhf.powers[i][r.p-1]+r.buf[i])%l.rhf.mods[i];
			return h;
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
			assert l > r;
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
	
	static int[][] packU(int n, int[] from, int[] to) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for (int f : from)
			p[f]++;
		for (int t : to)
			p[t]++;
		for (int i = 0; i < n; i++)
			g[i] = new int[p[i]];
		for (int i = 0; i < from.length; i++) {
			g[from[i]][--p[from[i]]] = to[i];
			g[to[i]][--p[to[i]]] = from[i];
		}
		return g;
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
	
	public static void main(String[] args) throws Exception { new P154C().run(); }
	
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