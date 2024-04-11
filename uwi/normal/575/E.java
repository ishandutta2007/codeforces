//package bubble8;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	public static double[] circumcircle(double ax, double ay, double bx, double by, double cx, double cy)
	{
		if((bx-ax)*(cy-ay)-(by-ay)*(cx-ax) == 0)return null; // 0
		double D = 2*(ax*(by-cy)+bx*(cy-ay)+cx*(ay-by));
		double X = ((ax*ax+ay*ay)*(by-cy)+(bx*bx+by*by)*(cy-ay)+(cx*cx+cy*cy)*(ay-by))/D;
		double Y = ((ax*ax+ay*ay)*(cx-bx)+(bx*bx+by*by)*(ax-cx)+(cx*cx+cy*cy)*(bx-ax))/D;
		double R = Math.sqrt((X-ax)*(X-ax)+(Y-ay)*(Y-ay));
		return new double[]{X, Y, R};
	}
	
	void solve()
	{
		int n = ni();
		long[][] co = new long[8*n][];
		int p = 0;
		for(int i = 0;i < n;i++){
			int x = ni(), y = ni(), w = ni();
			double[][] lco = new double[][]{
					{x-w, y},
					{x, y-w},
					{x+w, y},
					{x, y+w}
			};
			lco = convexCut(lco, 100000, 0, 0, 0);
			lco = convexCut(lco, 0, 0, 0, 100000);
			lco = convexCut(lco, 0, 100000, 100000, 100000);
			lco = convexCut(lco, 100000, 100000, 100000, 0);
			for(double[] u : lco){
				co[p++] = new long[]{Math.round(u[0]), Math.round(u[1])};
			}
		}
		
		long[][] hull = convexHull(Arrays.copyOf(co, p));
		
		double max = -1;
		int argmax = -1;
		int m = hull.length;
		for(int i = 0;i < hull.length;i++){
			double[] cc = circumcircle(
					hull[i][0], hull[i][1],
					hull[(i+1)%m][0], hull[(i+1)%m][1],
					hull[(i+2)%m][0], hull[(i+2)%m][1]
							);
			if(cc[2] > max){
				max = cc[2];
				argmax = i;
			}
		}
		for(int i = 0;i < 3;i++){
			out.println(hull[(argmax+i)%m][0] + " " + hull[(argmax+i)%m][1]);
		}
	}
	
	public static double[][] convexCut(double[][] c, double ax, double ay, double bx, double by)
	{
		int n = c.length;
		double[] ccw = new double[n];
		int m = 2;
		for(int i = 0;i < n;i++){
			ccw[i] = (c[i][0]-ax)*(by-ay)-(bx-ax)*(c[i][1]-ay);
			if(ccw[i] >= 0)m++;
		}
		
		double[][] ret = new double[m][];
		int p = 0;
		for(int i = 0, j = 1;i < n;i++, j++){
			if(j == n)j = 0;
			if(ccw[i] >= 0){
				ret[p++] = c[i];
			}
			if(ccw[i] * ccw[j] < 0){
				double[] il = interLines(ax, ay, bx, by, c[i][0], c[i][1], c[j][0], c[j][1]);
				if(il != null){
					ret[p++] = new double[]{il[0], il[1]};
				}
			}
		}
		return Arrays.copyOf(ret, p);
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
	
	public static long[][] convexHull(long[][] co)
	{
		int n = co.length;
		if(n <= 1)return co;
		Arrays.sort(co, new Comparator<long[]>(){
			public int compare(long[] a, long[] b){
				if(a[0] != b[0])return Long.compare(a[0], b[0]);
				return Long.compare(a[1], b[1]);
			}
		});
		
		int[] inds = new int[n + 1];
		int p = 0;
		for(int i = 0;i < n;i++){
			if(p >= 1 && co[inds[p-1]][0] == co[i][0] && co[inds[p-1]][1] == co[i][1])continue;
			while(p >= 2 && ccw(co[inds[p-2]], co[inds[p-1]], co[i]) >= 0)p--; // if you need point on line
			inds[p++] = i;
		}
		
		int inf = p + 1;
		for(int i = n - 2;i >= 0;i--){
			if(co[inds[p-1]][0] == co[i][0] && co[inds[p-1]][1] == co[i][1])continue;
			while(p >= inf && ccw(co[inds[p-2]], co[inds[p-1]], co[i]) >= 0)p--; // if you need point on line
			inds[p++] = i;
		}
		
		long[][] ret = new long[p-1][];
		for(int i = 0;i < p-1;i++)ret[i] = co[inds[i]];
		return ret;
	}
	
	public static int ccw(long[] a, long[] b, long[] t) {
		return Long.signum((t[0] - a[0]) * (b[1] - a[1]) - (b[0] - a[0])
				* (t[1] - a[1]));
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
	
	public static void main(String[] args) throws Exception { new E2().run(); }
	
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