//package educational.round02;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.MathContext;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D2B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
//	String INPUT = "0 0 1000000000 999999999 0 1";
	
	void solve()
	{
		long x1 = ni(), y1 = ni(), r1 = ni();
		long x2 = ni(), y2 = ni(), r2 = ni();
//		double d = Point2D.distance(x1, y1, x2, y2);
		out.printf("%.14f\n", areaCircleInter(r1, r2, (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
	}
	
	public double areaCircleInter(long r1, long r2, long d2)
	{
		double d = Math.sqrt(d2);
		if(d == 0)return Math.PI*Math.min(r1,r2)*Math.min(r1,r2);
		if(d >= r1 + r2){
			return 0;
		}else if(d >= Math.abs(r1-r2)){
			BigDecimal bd = sqrt(d2);
			double o1 = f(r1*r1+d2-r2*r2, 2*r1, d, bd);
			double o2 = f(r2*r2+d2-r1*r1, 2*r2, d, bd);
			return 
					o1*r1*r1 +
					o2*r2*r2;
//			return t1*r1*r1+t2*r2*r2-r1*r1/2*Math.sin(2*t1)-r2*r2/2*Math.sin(2*t2);
		}else{
			double r = Math.min(r1, r2);
			return Math.PI*r*r;
		}
	}
	
	BigDecimal sqrt(long x)
	{
		BigDecimal X = BigDecimal.valueOf(x);
		BigDecimal S = X;
		MathContext mc = new MathContext(100);
		for(int rep = 0;rep < 100;rep++){
			S = S.subtract(S.multiply(S, mc).subtract(X).divide(BigDecimal.valueOf(2).multiply(S), mc));
		}
		return S;
	}
	
	double f(long num, long den, double d, BigDecimal bd)
	{
		double eps = 1E-6;
		if(1-(double)num/den/d < eps){
			MathContext mc = new MathContext(100);
			double val = BigDecimal.ONE.subtract(BigDecimal.valueOf(num).divide(BigDecimal.valueOf(den), mc).divide(bd, mc)).doubleValue();
			double ret = 0;
//			ret -= 3*Math.pow(num/den, 3.5)/64/Math.sqrt(2);
//			ret -= 5*Math.pow(num/den, 3.5)/448/Math.sqrt(2);
			ret += Math.sqrt(2)*Math.pow(val, 2.5)/5;
			ret += 4./3*Math.sqrt(2)*Math.pow(val, 1.5);
//			tr(num, den);
			return ret;
		}else{
			double u = (double)num/den/d;
			if(u < -1)u = -1;
			if(u > 1)u = 1;
			double a = Math.acos(u);
			return a-u*Math.sqrt(1-u*u);
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
	
	public static void main(String[] args) throws Exception { new D2B().run(); }
	
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