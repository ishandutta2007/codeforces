//package intelcc2016.f;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		for(int Q = ni();Q > 0;Q--){
			int x = ni(), y = ni();
			// t = x(mod 2n)
			// t = y(mod 2m)
			long min = Long.MAX_VALUE;
			{
				long crt = crt(2*n, x, 2*m, y);
				if(crt >= 0)min = Math.min(min, crt);
			}
			{
				long crt = crt(2*n, 2*n-x, 2*m, y);
				if(crt >= 0)min = Math.min(min, crt);
			}
			{
				long crt = crt(2*n, 2*n-x, 2*m, 2*m-y);
				if(crt >= 0)min = Math.min(min, crt);
			}
			{
				long crt = crt(2*n, x, 2*m, 2*m-y);
				if(crt >= 0)min = Math.min(min, crt);
			}
			out.println(min == Long.MAX_VALUE ? -1 : min);
		}
	}
	
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
//		long ret = (p * pp % mod * ((n - m) / a) + m) % mod;
		long ret = (mul(mul(p, pp, mod), (n-m)/a, mod)+m)%mod;
		if(ret < 0)ret += mod;
		return ret;
	}
	
	public static long mul(long a, long b, long mod)
	{
		a %= mod; if(a < 0)a += mod;
		b %= mod; if(b < 0)b += mod;
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

	
	void run() throws Exception
	{
//		int n = 100000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		sb.append(n + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append(gen.nextInt(99999)+1 + " ");
//			sb.append(gen.nextInt(99999)+1 + " ");
//		}
//		INPUT = sb.toString();

		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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