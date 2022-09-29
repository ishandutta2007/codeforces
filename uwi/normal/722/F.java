//package intelcc2016.elim;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class F2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] a = new int[n][];
		int all = 0;
		for(int i = 0;i < n;i++){
			int L = ni();
			all += L;
			a[i] = na(L);
		}
		
		int[][] ap = new int[all][];
		int p = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < a[i].length;j++){
				ap[p++] = new int[]{a[i][j], i, a[i].length, j};
			}
		}
		assert p == all;
		Arrays.sort(ap, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[0] != b[0])return a[0] - b[0];
				return a[1] - b[1];
			}
		});
		
		int[] ret = new int[m+1];
		long[] dpm = new long[50];
		long[] dpr = new long[50];
		int[] dpfr = new int[50];
		int dpp = 0;
		for(int i = 0;i < all;i++){
			if(i > 0 && (ap[i][0] != ap[i-1][0] || ap[i][1] > ap[i-1][1] + 1)){
				dpp = 0;
			}
			long[] ndpm = new long[50];
			long[] ndpr = new long[50];
			int[] ndpfr = new int[50];
			int lp = 0;
			for(int j = 0;j < dpp;j++){
//				tr(dpm[j], dpr[j], ap[i]);
				long val = crt(dpm[j], dpr[j], ap[i][2], ap[i][3]);
				if(val != -1){
					if(lp >= 1 && mmod == ndpm[lp-1]){
						continue;
					}
					ndpm[lp] = mmod;
					ndpr[lp] = val;
					ndpfr[lp] = dpfr[j];
					lp++;
				}
			}
			{
				if(lp >= 1 && ap[i][2] == ndpm[lp-1]){
				}else{
					ndpm[lp] = ap[i][2];
					ndpr[lp] = ap[i][3];
					ndpfr[lp] = i;
					lp++;
				}
			}
			for(int u = 0;u < lp;u++){
				assert ndpm[u] != 0;
				if(u < lp-1)assert ndpm[u] > ndpm[u+1];
				assert ndpr[u] < ndpm[u];
				if(u < lp-1)assert ndpfr[u] < ndpfr[u+1];
			}
			ret[ap[i][0]] = Math.max(ret[ap[i][0]], i-ndpfr[0]+1);
			dpm = ndpm;
			dpr = ndpr;
			dpfr = ndpfr;
			dpp = lp;
		}
		for(int i = 1;i <= m;i++){
			out.println(ret[i]);
		}
	}
	
	public static int gcd(int a, int b) {
		while (b > 0) {
			int c = a;
			a = b;
			b = c % b;
		}
		return a;
	}
	
	static long mmod;
	
	public static long crt(long p, long m, long q, long n)
	{
		long a = p, b = q;
		long pp = 1, qq = 0;
		while(b > 0){
			long c = a / b;
			long d;
			d = a; a = b; b = d % b;
			d = pp; pp = qq; qq = d - c * qq;
		}
		if((n - m) % a != 0)return -1;
		long mod = p / a * q;
		long qa = q/a;
		long ret = (p * (pp % qa * ((n - m) / a) % qa) + m) % mod;
//		long ret = (p * pp % mod * ((n - m) / a) + m) % mod;
//		long ret = (mul(mul(p, pp, mod), (n-m)/a, mod)+m)%mod;
		if(ret < 0)ret += mod;
		mmod = mod;
		return ret;
	}
	
	public static long mul(long a, long b, long mod)
	{
		if(a >= mod || a < 0)a %= mod;
		if(a < 0)a += mod;
		if(b >= mod || b < 0)b %= mod;
		if(b < 0)b += mod;
		
		long ret = 0;
		int x = 63-Long.numberOfLeadingZeros(b);
		for(;x >= 0;x--){
			ret += ret;
			if(ret >= mod)ret -= mod;
			if(b<<~x<0){
				ret += a;
				if(ret >= mod)ret -= mod;
			}
		}
		return ret;
	}
	
	public static long[] exgcd(long a, long b)
	{
		if(a == 0 || b == 0)return null;
		long p = 1, q = 0, r = 0, s = 1;
		while(b > 0){
			long c = a / b;
			long d;
			d = a; a = b; b = d % b;
			d = p; p = q; q = d - c * q;
			d = r; r = s; s = d - c * s;
		}
		return new long[]{a, p, r};
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
	
	public static void main(String[] args) throws Exception { new F2().run(); }
	
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