//package round327;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		// sqrt((X-wx*t)^2+(Y-wy*t)^2)<=vt
		// t^2(wx^2+wy^2-v^2)-t(2*X*wx+2*Y*wy)+X^2+Y^2 <= 0
		double sx = nd(), sy = nd(), tx = nd(), ty = nd();
		ty -= sy;
		tx -= sx;
		double v = nd(), time = nd();
		double w1x = nd(), w1y = nd();
		double w2x = nd(), w2y = nd();
		{
			double A = w1x*w1x+w1y*w1y-v*v;
			double B = -2*tx*w1x-2*ty*w1y;
			double C = tx*tx+ty*ty;
			
			double[] sols = solveQuad(A, B, C);
			double reach = sols[sols.length-1];
			if(reach <= time){
				out.printf("%.12f\n", reach);
				return;
			}
		}
		tx = tx - w1x * time + w2x * time;
		ty = ty - w1y * time + w2y * time;
		double A = w2x*w2x+w2y*w2y-v*v;
		double B = -2*tx*w2x-2*ty*w2y;
		double C = tx*tx+ty*ty;
		double[] sols = solveQuad(A, B, C);
		double reach = sols[sols.length-1];
		out.printf("%.12f\n", reach);
	}
	
	public static double[] solveQuad(double A, double B, double C)
	{
		if(A == 0){
			if(B == 0){
				return C == 0 ? null : new double[0];
			}else{
				return new double[]{-C/B};
			}
		}
		
		double EPS = 1E-10;
		double D = B*B-4*A*C;
		if(D < -EPS){
			return new double[0];
		}else if(D < EPS){
			return new double[]{-B/(2*A)};
		}else{
			double sq = Math.sqrt(D);
			if(A > 0){
				return new double[]{(-B-sq)/(2*A), (-B+sq)/(2*A)};
			}else{
				return new double[]{(-B+sq)/(2*A), (-B-sq)/(2*A)};
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