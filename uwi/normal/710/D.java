//package educational.round16;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		long a1 = nl(), b1 = nl(), a2 = nl(), b2 = nl(), L = nl(), R = nl();
		long bb1 = b1;
		bb1 %= a1;
		if(bb1 < 0)bb1 += a1;
		long bb2 = b2;
		bb2 %= a2;
		if(bb2 < 0)bb2 += a2;
		
		BigInteger b = crtx(new long[]{a1, a2}, new long[]{bb1, bb2});
		if(b.signum() < 0){
			out.println(0);
			return;
		}
		// b=a1*K+b1
		BigInteger KK = b.subtract(b(b1)).divide(b(a1));
		BigInteger LL = b.subtract(b(b2)).divide(b(a2));
		long u = a1 * a2 / gcd(a1, a2);
		// KK+(u/a1)t >= 0
		// LL+(u/a2)t >= 0
		// b = a1*KK+b1
		BigInteger BK = ceil(KK.negate(), b(u/a1));//.add(b(u/a1).subtract(BigInteger.ONE)).divide(b(u/a1));
		BigInteger BL = ceil(LL.negate(), b(u/a2));
		BigInteger start = BK.max(BL).multiply(b(u/a1)).add(KK).multiply(b(a1)).add(b(b1));
		// start + u*x
		out.println(count(R, start, u) - count(L-1, start, u));
	}
	
	BigInteger ceil(BigInteger num, BigInteger den)
	{
		if(num.signum() >= 0){
			return num.add(den.subtract(BigInteger.ONE)).divide(den);
		}else{
			return num.divide(den);
		}
	}
	
	long count(long R, BigInteger start, long u)
	{
		if(start.compareTo(b(R)) > 0){
			return 0L;
		}else{
			return b(R).subtract(start).divide(b(u)).add(BigInteger.ONE).longValue();
		}
	}
	
	public static BigInteger b(long x){ return BigInteger.valueOf(x); }
	
	public static BigInteger[] exGCD(BigInteger a, BigInteger b)
	{
		BigInteger p = BigInteger.ONE, q = BigInteger.ZERO, r = BigInteger.ZERO, s = BigInteger.ONE;
		while(b.signum() > 0){
			BigInteger c = a.divide(b);
			BigInteger d;
			d = a; a = b; b = d.mod(b);
			d = p; p = q; q = d.subtract(c.multiply(q));
			d = r; r = s; s = d.subtract(c.multiply(s));
		}
		return new BigInteger[]{a, p, r};
	}
	
	
	public static BigInteger crtx(long[] divs, long[] mods)
	{
		BigInteger div = b(divs[0]), mod = b(mods[0]);
		for(int i = 1;i < divs.length;i++){
			BigInteger[] apr = exGCD(div, b(divs[i]));
			BigInteger mm = b(mods[i]).subtract(mod);
			if(mm.mod(apr[0]).signum() != 0)return b(-1);
			BigInteger da = div.divide(apr[0]);
			BigInteger ndiv = b(divs[i]).multiply(da);
			BigInteger nmod = apr[1].multiply(mm).multiply(da).add(mod).mod(ndiv);
			if(nmod.signum() < 0)nmod = nmod.add(ndiv);
			div = ndiv;
			mod = nmod;
		}
		return mod;
	}
	
	public static long gcd(long a, long b) {
		while (b > 0) {
			long c = a;
			a = b;
			b = c % b;
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
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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