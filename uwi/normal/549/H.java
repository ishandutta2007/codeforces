//package loosery;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class H4 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		double a = ni(), b = ni(), c = ni(), d = ni();
		double low = 0, high = 1E9+7;
		for(int rep = 0;rep < 150;rep++){
			double r = (low+high)/2;
			if(ok(a, b, c, d, r)){
				high = r;
			}else{
				low = r;
			}
		}
		
		out.printf("%.15f\n", high);
	}
	
	boolean ok(double a, double b, double c, double d, double x1, double y1, double x2, double y2)
	{
		double[] il = interLines(a, b, c, d, x1, y1, x2, y2);
//		tr(a, b, c, d, x1, y1, x2, y2, il);
		return il != null && il[3] >= 0 && il[3] <= 1;
	}
	
	boolean check(double c, double d, double dx, double dy, double r)
	{
		return 
				ok(c, d, c+dx, d+dy, r, r, -r, r) ||
				ok(c, d, c+dx, d+dy, -r, r, -r, -r) ||
				ok(c, d, c+dx, d+dy, -r, -r, r, -r) ||
				ok(c, d, c+dx, d+dy, r, -r, r, r)
				;
	}
	
	double amin(double[] args)
	{
		Arrays.sort(args);
		for(int i = 0;i < args.length-1;i++){
			if(args[i]+Math.PI < args[i+1])return args[i+1];
		}
		return args[0];
	}
	
	double amax(double[] args)
	{
		Arrays.sort(args);
		for(int i = 0;i < args.length-1;i++){
			if(args[i]+Math.PI < args[i+1])return args[i];
		}
		return args[args.length-1];
	}
	
	double[] arange(double... args)
	{
		Arrays.sort(args);
		for(int i = 0;i < args.length-1;i++){
			if(args[i]+Math.PI < args[i+1])return new double[]{args[i+1], args[i]+2*Math.PI};
		}
		return new double[]{args[0], args[args.length-1]};
	}
	
	boolean inter(double[] a, double[] b)
	{
		return 
				Math.max(a[0], b[0]-Math.PI*2) <= Math.min(a[1], b[1]-Math.PI*2) ||
				Math.max(a[0], b[0]) <= Math.min(a[1], b[1]) ||
				Math.max(a[0], b[0]+Math.PI*2) <= Math.min(a[1], b[1]+Math.PI*2);
	}
	
	double[] range(double a, double b, double r)
	{
		if(b == 0){
			if(Math.abs(a) <= r){
				return new double[]{Double.NEGATIVE_INFINITY, Double.POSITIVE_INFINITY};
			}else{
				return new double[]{Double.POSITIVE_INFINITY, Double.NEGATIVE_INFINITY};
			}
		}
		if(b > 0){
			return new double[]{(-r-a)/b, (r-a)/b};
		}
		return new double[]{(r-a)/b, (-r-a)/b};
	}
	
	boolean ok(double a, double b, double c, double d, double r)
	{
		for(int k = -1;k <= 1;k+=2){
			for(int l = -1;l <= 1;l+=2){
				double[] rx = range(c, r*k-a, r);
				double[] ry = range(d, r*l-b, r);
				if(Math.max(rx[0], ry[0]) <= Math.min(rx[1], ry[1]))return true;
			}
		}
		
		for(int k = -1;k <= 1;k+=2){
			for(int l = -1;l <= 1;l+=2){
				double[] rx = range(a, r*k-c, r);
				double[] ry = range(b, r*l-d, r);
				if(Math.max(rx[0], ry[0]) <= Math.min(rx[1], ry[1]))return true;
			}
		}
		return false;
	}
	
	public static int inArg(double ax, double ay, double bx, double by, double cx, double cy)
	{
		return (int)(Math.signum(ax*cy-ay*cx)-Math.signum(bx*cy-by*cx)-Math.signum(ax*by-ay*bx));
	}
	
	public static double[] interLines(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy)
	{
		double eps = 1E-12;
		double aa = bx - ax;
		double cc = by - ay;
		double bb = cx - dx;
		double dd = cy - dy;
		double xx = cx - ax;
		double yy = cy - ay;
		double det = aa * dd - bb * cc;
		if(Math.abs(det) < eps)return null;
		double t = (dd * xx - bb * yy) / det;
		double u = (-cc * xx + aa * yy) / det;
		return new double[]{ax + (bx - ax) * t, ay + (by - ay) * t, t, u};
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
	
	public static void main(String[] args) throws Exception { new H4().run(); }
	
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