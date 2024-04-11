//package round172;
import java.awt.geom.Line2D;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class A {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		double w = ni(), h = ni();
		double alpha = (double)ni()*Math.PI/180;
		double[][] rect = new double[][]{{-w/2, -h/2}, {w/2, -h/2}, {w/2, h/2}, {-w/2, h/2}};
		double[][] rectr = new double[4][];
		for(int i = 0;i < 4;i++){
			double x = rect[i][0], y = rect[i][1];
			rectr[i] = new double[]{
					x * Math.cos(alpha) + y * Math.sin(alpha),
					-x * Math.sin(alpha) + y * Math.cos(alpha)
			};
		}
		out.printf("%.12f\n", areaPoly(interConvex(rect, rectr)));
	}
	
	public static double areaPoly(double[][] co)
	{
		int n = co.length;
		double s = 0;
		for(int i = 0;i < n - 1;i++){
			s += (co[i][0]*co[i+1][1]-co[i+1][0]*co[i][1]) / 2;
		}
		s += (co[n-1][0]*co[0][1]-co[0][0]*co[n-1][1]) / 2;
		return Math.abs(s);
	}
	
	public static double[] interLines(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy)
	{
		double eps = 1E-9;
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
	
	public static double[][] interConvex(double[][] co1, double[][] co2){
		double EPS = 1E-9;
		int m = co1.length;
		int n = co2.length;
		double[] cx = new double[2*(m+n)];
		double[] cy = new double[2*(m+n)];
		int p = 0;
		for(int i = 0;i < m;i++){
			for(int j = 0;j < n;j++){
				int ni = (i+1)%m;
				int nj = (j+1)%n;
				double[] il = interLines(
						co1[i][0], co1[i][1], co1[ni][0], co1[ni][1],
						co2[j][0], co2[j][1], co2[nj][0], co2[nj][1]
								);
				if(il != null && il[2] > -EPS && il[2] < 1+EPS && il[3] > -EPS && il[3] < 1+EPS){
					cx[p] = il[0];
					cy[p] = il[1];
					p++;
				}
			}
		}
		for(int i = 0;i < m;i++){
			if(isOnIn(co1[i][0], co1[i][1], co2)){
				cx[p] = co1[i][0];
				cy[p] = co1[i][1];
				p++;
			}
		}
		for(int i = 0;i < n;i++){
			if(isOnIn(co2[i][0], co2[i][1], co1)){
				cx[p] = co2[i][0];
				cy[p] = co2[i][1];
				p++;
			}
		}
		
		cx = Arrays.copyOf(cx, p);
		cy = Arrays.copyOf(cy, p);
		convexSort(cx, cy);
		
		double[][] rc = new double[p][];
		for(int i = 0;i < p;i++){
			rc[i] = new double[]{cx[i], cy[i]};
		}
		return rc;
	}
	
	public static void convexSort(double[] sx, double[] sy)
	{
		double gx = 0, gy = 0;
		for(double x : sx)gx += x;
		for(double y : sy)gy += y;
		int n = sx.length;
		gx /= n; gy /= n;
		
		final double[] th = new double[n];
		for(int i = 0;i < n;i++){
			th[i] = Math.atan2(sy[i]-gy, sx[i]-gx);
		}
		Integer[] ord = new Integer[n];
		for(int i = 0;i < n;i++)ord[i] = i;
		Arrays.sort(ord, new Comparator<Integer>(){
			public int compare(Integer a, Integer b){
				return Double.compare(th[a], th[b]);
			}
		});
		
		double[] cx = new double[n];
		double[] cy = new double[n];
		System.arraycopy(sx, 0, cx, 0, n);
		System.arraycopy(sy, 0, cy, 0, n);
		for(int i = 0;i < n;i++){
			sx[i] = cx[ord[i]];
			sy[i] = cy[ord[i]];
		}
	}

	public static boolean isOnIn(double x, double y, double[][] co){
		int n = co.length;
		int cc = Line2D.relativeCCW(co[n-1][0], co[n-1][1], co[0][0], co[0][1], x, y);
		if(cc == 0)return true;
		for(int i = 0;i < n-1;i++){
			int ccc = Line2D.relativeCCW(co[i][0], co[i][1], co[i+1][0], co[i+1][1], x, y);
			if(ccc == 0)return true;
			if(cc != ccc)return false;
		}
		return true;
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
	
	public static void main(String[] args) throws Exception { new A().run(); }
	
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