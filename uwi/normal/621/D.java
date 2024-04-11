//package round341x;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		long x = Math.round(nd()*10);
		long y = Math.round(nd()*10);
		long z = Math.round(nd()*10);
		String[] rep = {
				"x^y^z",
				"x^z^y",
				"(x^y)^z",
				"y^x^z",
				"y^z^x",
				"(y^x)^z",
				"z^x^y",
				"z^y^x",
				"(z^x)^y"
		};
		long[][] s = new long[9][];
		s[0] = new long[]{1, x, y, z};
		s[1] = new long[]{2, x, z, y};
		s[2] = new long[]{3, x, y, z};
		s[3] = new long[]{5, y, x, z};
		s[4] = new long[]{6, y, z, x};
		s[5] = new long[]{7, y, x, z};
		s[6] = new long[]{9, z, x, y};
		s[7] = new long[]{10, z, y, x};
		s[8] = new long[]{11, z, x, y};
		
		int argmax = 0;
		for(int i = 1;i < 9;i++){
			if(argmax % 3 != 2 && i % 3 != 2){
				int cc = comp(
						s[argmax][1], s[argmax][2], s[argmax][3],
						s[i][1], s[i][2], s[i][3]
								);
				if(cc < 0){
					argmax = i;
				}
			}else if(argmax % 3 != 2 && i % 3 == 2){
				int cc = compa(
						s[argmax][1], s[argmax][2], s[argmax][3],
						s[i][1], s[i][2], s[i][3]
								);
				if(cc < 0){
					argmax = i;
				}
			}else if(argmax % 3 == 2 && i % 3 != 2){
				int cc = compa(
						s[i][1], s[i][2], s[i][3],
						s[argmax][1], s[argmax][2], s[argmax][3]
								);
				if(cc > 0){
					argmax = i;
				}
			}else{
				int cc = comp(
						s[argmax][1], s[argmax][2]*s[argmax][3],
						s[i][1], s[i][2]*s[i][3]
								);
				if(cc < 0){
					argmax = i;
				}
			}
		}
		out.println(rep[argmax]);
	}
	
	// (y/10)^(z/10) (z/10)^(y/10)
	int comp(long y, long z)
	{
		if(y == z)return 0;
		double la = z*(Math.log10(y)-1);
		double lb = y*(Math.log10(z)-1);
		if(Math.abs(la-lb) > 1E-8){
			return Double.compare(la, lb);
		}
		// y=20,z=40,..
		return 0;
	}
	
	int comp(long a, long b, long c, long d)
	{
		if(a == c && b == d)return 0;
		if(a == 10 && c == 10)return 0;
		if(a >= 10 && c <= 10)return 1;
		if(a <= 10 && c >= 10)return -1;
		double la = b*(Math.log10(a)-1);
		double lb = d*(Math.log10(c)-1);
		if(Math.abs(la-lb) > 1E-8){
			return Double.compare(la, lb);
		}
		
//		if(a % c == 0 || c % a == 0){
//			
//		}else{
//			tr(a, b, c, d);
//		}
		return 0;
	}
	
	int comp(long a, long b, long c, long d, long e, long f)
	{
		if(a == 10 && d == 10)return 0;
		if(a == d && b == e && c == f)return 0;
		if(a == d){
			int co = comp(b, c);
			if(a < 10)return -co;
			return co;
		}
		if(a <= 10 && d >= 10)return -1;
		if(a >= 10 && d <= 10)return 1;
		if(a > 10 && d > 10){
			double la = c/10.*(Math.log10(b)-1)+Math.log10(Math.log10(a)-1);
			double lb = f/10.*(Math.log10(e)-1)+Math.log10(Math.log10(d)-1);
			if(Math.abs(la-lb) > 1E-8){
				return Double.compare(la, lb);
			}
		}else{
			double la = c/10.*(Math.log10(b)-1)+Math.log10(1-Math.log10(a));
			double lb = f/10.*(Math.log10(e)-1)+Math.log10(1-Math.log10(d));
			if(Math.abs(la-lb) > 1E-8){
				return -Double.compare(la, lb);
			}
		}
		// (a/10)^((b/10)^(c/10))
		// ((b/10)^(c/10))(log a-1)
		// (c/10)(log b-1)+log(log a - 1)
//		tr(a, b, c, d, e, f);
		// not come here
		return 0;
	}
	
	// (a/10)^((b/10)^(c/10))
	// (d/10)^(e/10*f/10)
	// (ef/100)*(log d-1)
	// (log(ef)-2)+log(log d-1)
	int compa(long a, long b, long c, long d, long e, long f)
	{
		if(a == 10 && d == 10)return 0;
//		if(a == d){
//			int co = compa(b, c, e, f);
//			if(a < 10)return -co;
//			return co;
//		}
		if(a <= 10 && d >= 10)return -1;
		if(a >= 10 && d <= 10)return 1;
		if(a > 10 && d > 10){
			double la = c/10.*(Math.log10(b)-1)+Math.log10(Math.log10(a)-1);
			double lb = (Math.log10(e*f)-2)+Math.log10(Math.log10(d)-1);
			if(Math.abs(la-lb) > 1E-8){
				return Double.compare(la, lb);
			}
		}else{
			double la = c/10.*(Math.log10(b)-1)+Math.log10(1-Math.log10(a));
			double lb = (Math.log10(e*f)-2)+Math.log10(1-Math.log10(d));
			if(Math.abs(la-lb) > 1E-8){
				return -Double.compare(la, lb);
			}
		}
		// (a/10)^((b/10)^(c/10))
		// ((b/10)^(c/10))(log a-1)
		// (c/10)(log b-1)+log(log a - 1)
//		tr(a, b, c, d, e, f);
		return 0;
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