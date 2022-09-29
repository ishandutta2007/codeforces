//package educational.round34;
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

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int K = ni(), n = ni();
		char[][] ss = new char[K][];
		for(int i = 0;i < K;i++){
			ss[i] = ns(n);
		}
		int[] f = null;
		for(int i = 0;i < K;i++){
			int[] lf = new int[26];
			for(char s : ss[i]){
				lf[s-'a']++;
			}
			if(f == null){
				f = lf;
			}else{
				if(!Arrays.equals(f, lf)){
					out.println(-1);
					return;
				}
			}
		}
		
		if(K == 1){
			char d = ss[0][0]; ss[0][0] = ss[0][1];
			ss[0][1] = d;
			out.println(new String(ss[0]));
			return;
		}
		
		int[] can = new int[n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < K;j++){
				if(ss[j][i] != ss[0][i]){
					can[i] = 1;
				}
			}
		}
		int rem = 2;
		for(int i = 0;i < n;i++){
			if(can[i] == 0 && rem > 0){
				rem--;
				can[i] = 1;
			}
		}
		
		
		RollingHashFactory rhf = new RollingHashFactory(2, 3000, new Random());
		long[] hs = new long[n*(n-1)/2];
		{
			RollingHashOneState rhos = new RollingHashOneState(rhf);
			for(int i = 0;i < n;i++){
				rhos.add(ss[0][i]);
			}
			int p = 0;
			for(int i = 0;i < n;i++){
				for(int j = i+1;j < n;j++){
					if(can[i] == 1 && can[j] == 1){
						long b0 = rhos.buf[0] + (ss[0][j] - ss[0][i]) * rhf.powers[0][n-1-i] - (ss[0][j] - ss[0][i]) * rhf.powers[0][n-1-j];
						long b1 = rhos.buf[1] + (ss[0][j] - ss[0][i]) * rhf.powers[1][n-1-i] - (ss[0][j] - ss[0][i]) * rhf.powers[1][n-1-j];
						b0 %= rhf.mods[0];
						if(b0 < 0)b0 += rhf.mods[0];
						b1 %= rhf.mods[1];
						if(b1 < 0)b1 += rhf.mods[1];
						hs[p++] = b0<<32|b1;
					}
				}
			}
			hs = Arrays.copyOf(hs, p);
			Arrays.sort(hs);
			hs = uniq(hs);
		}
		
		int[] hf = new int[hs.length];
		for(int z = 1;z < K;z++){
			RollingHashOneState rhos = new RollingHashOneState(rhf);
			for(int i = 0;i < n;i++){
				rhos.add(ss[z][i]);
			}
			for(int i = 0;i < n;i++){
				for(int j = i+1;j < n;j++){
					if(can[i] == 1 && can[j] == 1){
						long b0 = rhos.buf[0] + (ss[z][j] - ss[z][i]) * rhf.powers[0][n-1-i] - (ss[z][j] - ss[z][i]) * rhf.powers[0][n-1-j];
						long b1 = rhos.buf[1] + (ss[z][j] - ss[z][i]) * rhf.powers[1][n-1-i] - (ss[z][j] - ss[z][i]) * rhf.powers[1][n-1-j];
						b0 %= rhf.mods[0];
						if(b0 < 0)b0 += rhf.mods[0];
						b1 %= rhf.mods[1];
						if(b1 < 0)b1 += rhf.mods[1];
						int ind = Arrays.binarySearch(hs, b0<<32|b1);
						if(ind >= 0 && hf[ind] == z-1){
							hf[ind]++;
						}
					}
				}
			}
		}
		long target = -1;
		for(int i = 0;i < hs.length;i++){
			if(hf[i] == K-1){
				target = hs[i];
				break;
			}
		}
//		tr(hf, target);
		if(target == -1){
			out.println(-1);
			return;
		}
		{
			RollingHashOneState rhos = new RollingHashOneState(rhf);
			for(int i = 0;i < n;i++){
				rhos.add(ss[0][i]);
			}
			for(int i = 0;i < n;i++){
				for(int j = i+1;j < n;j++){
					if(can[i] == 1 && can[j] == 1){
						long b0 = rhos.buf[0] + (ss[0][j] - ss[0][i]) * rhf.powers[0][n-1-i] - (ss[0][j] - ss[0][i]) * rhf.powers[0][n-1-j];
						long b1 = rhos.buf[1] + (ss[0][j] - ss[0][i]) * rhf.powers[1][n-1-i] - (ss[0][j] - ss[0][i]) * rhf.powers[1][n-1-j];
						b0 %= rhf.mods[0];
						if(b0 < 0)b0 += rhf.mods[0];
						b1 %= rhf.mods[1];
						if(b1 < 0)b1 += rhf.mods[1];
						if((b0<<32|b1) == target){
							char d = ss[0][i]; ss[0][i] = ss[0][j];
							ss[0][j] = d;
							out.println(new String(ss[0]));
							return;
						}
					}
				}
			}
		}
		throw new RuntimeException();
	}
	
	public static long[] uniq(long[] a)
	{
		int n = a.length;
		int p = 0;
		for(int i = 0;i < n;i++) {
			if(i == 0 || a[i] != a[i-1])a[p++] = a[i];
		}
		return Arrays.copyOf(a, p);
	}

	
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