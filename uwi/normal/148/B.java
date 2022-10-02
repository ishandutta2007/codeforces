//package round105;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;

public class B2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int vp = ni(), vd = ni(), t = ni(), f = ni(), c = ni();
		if(vp >= vd){
			out.println(0);
			return;
		}
		double pos = vp*t;
		pos += (double)vp*t*vp / (vd-vp);
		for(int i = 0;;i++){
			if(pos-c >= -1E-10){
				out.println(i);
				break;
			}
			double ext = f + pos / vd;
			pos += ext * vp;
			pos += pos * vp / (vd - vp);
		}
	}
	
	public static class FB implements Comparable<FB> {
		public BigInteger num, den;
		
		public FB(){ this.num = BigInteger.ZERO; this.den = BigInteger.ONE; }
		public FB(long num) { this.num = BigInteger.valueOf(num); this.den = BigInteger.ONE; }
		public FB(long num, long den) { this.num = BigInteger.valueOf(num); this.den = BigInteger.valueOf(den); reduce(); }
		public FB(BigInteger num) {	this.num = num; this.den = BigInteger.ONE;}
		public FB(BigInteger num, BigInteger den) {	this.num = num;	this.den = den;	reduce();}
		
		public FB reduce()
		{
			if(den.signum() == 0) {
			}else if(num.signum() == 0) {
				den = BigInteger.ONE;
			}else {
				if(den.signum() < 0) {
					num = num.negate();
					den = den.negate();
				}
				BigInteger g = num.gcd(den);
				num = num.divide(g);
				den = den.divide(g);
			}
			return this;
		}
		
		public static FB add(FB a, FB b){ return new FB(a.num.multiply(b.den).add(a.den.multiply(b.num)), a.den.multiply(b.den)); }
		public static FB sub(FB a, FB b){ return new FB(a.num.multiply(b.den).subtract(a.den.multiply(b.num)), a.den.multiply(b.den)); }
		public static FB mul(FB a, FB b){ return new FB(a.num.multiply(b.num), a.den.multiply(b.den)); }
		public static FB div(FB a, FB b){ return new FB(a.num.multiply(b.den), a.den.multiply(b.num)); }
		public static FB inv(FB a) { return new FB(a.den, a.num); }
		
		public FB add(FB b){ num = num.multiply(b.den).add(den.multiply(b.num)); den = den.multiply(b.den); return reduce(); }
		public FB sub(FB b){ num = num.multiply(b.den).subtract(den.multiply(b.num)); den = den.multiply(b.den); return reduce(); }
		public FB mul(FB b){ num = num.multiply(b.num); den = den.multiply(b.den); return reduce(); }
		public FB div(FB b){ num = num.multiply(b.den); den = den.multiply(b.num); return reduce(); }
		public FB inv() { BigInteger d = num; num = den; den = d; return reduce(); }
		
		@Override public String toString() { return num.toString() + "/" + den.toString(); }
		
		@Override public int compareTo(FB f) { return num.multiply(f.den).compareTo(f.num.multiply(den)); }
		
		public boolean simpleEquals(FB f) {	return num.equals(f.num) && den.equals(f.den); }

		@Override
		public boolean equals(Object o)
		{
			if(o == null)return false;
			FB f = (FB) o;
			return num.multiply(f.den).equals(f.num.multiply(den));
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
	
	public static void main(String[] args) throws Exception
	{
		new B2().run();
	}
	
	public int ni()
	{
		try {
			int num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public long nl()
	{
		try {
			long num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public String ns()
	{
		try{
			int b = 0;
			StringBuilder sb = new StringBuilder();
			while((b = is.read()) != -1 && (b == '\r' || b == '\n' || b == ' '));
			if(b == -1)return "";
			sb.append((char)b);
			while(true){
				b = is.read();
				if(b == -1)return sb.toString();
				if(b == '\r' || b == '\n' || b == ' ')return sb.toString();
				sb.append((char)b);
			}
		} catch (IOException e) {
		}
		return "";
	}
	
	public char[] ns(int n)
	{
		char[] buf = new char[n];
		try{
			int b = 0, p = 0;
			while((b = is.read()) != -1 && (b == ' ' || b == '\r' || b == '\n'));
			if(b == -1)return null;
			buf[p++] = (char)b;
			while(p < n){
				b = is.read();
				if(b == -1 || b == ' ' || b == '\r' || b == '\n')break;
				buf[p++] = (char)b;
			}
			return Arrays.copyOf(buf, p);
		} catch (IOException e) {
		}
		return null;
	}
	
	
	double nd() { return Double.parseDouble(ns()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}