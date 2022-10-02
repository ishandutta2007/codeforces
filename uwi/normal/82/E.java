//package yandex2011.q2;
import java.awt.geom.Line2D;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class E {
	Scanner in;
	PrintWriter out;
//	String INPUT = "2 2 4\r\n" +
//			"-1 0 1 2";
//	String INPUT = "2 2 4\r\n" +
//			"-1 0\r\n" +
//			"1 2";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		double h = ni();
		double f = ni();
		double[] l = new double[n];
		double[] r = new double[n];
		for(int i = 0;i < n;i++){
			l[i] = ni();
			r[i] = ni();
		}
		
		double S = 0;
		for(int i = 0;i < n;i++){
			S += 2.0*f*(r[i] - l[i])*h/(f-h)*2;
		}
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				double dl = (f+h)/(f-h)*l[i];
				double dr = (f+h)/(f-h)*r[i];
				double ul = (f+h)/(f-h)*l[j];
				double ur = (f+h)/(f-h)*r[j];
				double[][] ip = interPoly(
						new double[]{l[i], dl, dr, r[i]},
						new double[]{h, -h, -h, h},
						new double[]{ul, l[j], r[j], ur},
						new double[]{h, -h, -h, h}
						);
				if(ip[0].length > 0){
					S -= areaPoly(ip[0], ip[1]);
				}
			}
		}
		out.println(S);
	}
	
	public static double areaPoly(double[] x, double[] y)
	{
		int n = x.length;
		double s = 0;
		for(int i = 0;i < n - 1;i++){
			s += (x[i]*y[i+1]-x[i+1]*y[i]) / 2;
		}
		s += (x[n-1]*y[0]-x[0]*y[n-1]) / 2;
		return Math.abs(s);
	}
	
	public boolean isOnIn(double x, double y, double[] px, double[] py)
	{
		int n = px.length;
		int cc = Line2D.relativeCCW(px[n-1], py[n-1], px[0], py[0], x, y);
		if(cc == 0)return true;
		for(int i = 0;i < n-1;i++){
			int ccc = Line2D.relativeCCW(px[i], py[i], px[i+1], py[i+1], x, y);
			if(ccc == 0)return true;
			if(cc != ccc)return false;
		}
		return true;
	}
	
	public void convexSort(double[] sx, double[] sy)
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
				return (int)Math.signum(th[a] - th[b]);
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
	
	public double[][] interPoly(double[] x1, double[] y1, double[] x2, double[] y2)
	{
		int m = x1.length;
		int n = x2.length;
		double[] cx = new double[2*(m+n)];
		double[] cy = new double[2*(m+n)];
		int p = 0;
		for(int i = 0;i < m;i++){
			for(int j = 0;j < n;j++){
				int ni = (i+1)%m;
				int nj = (j+1)%n;
				double[] il = interLines(x1[i], y1[i], x1[ni], y1[ni], x2[j], y2[j], x2[nj], y2[nj]);
				if(il != null && il[2] > -EPS && il[2] < 1+EPS && il[3] > -EPS && il[3] < 1+EPS){
					cx[p] = il[0];
					cy[p] = il[1];
					p++;
				}
			}
		}
		for(int i = 0;i < m;i++){
			if(isOnIn(x1[i], y1[i], x2, y2)){
				cx[p] = x1[i];
				cy[p] = y1[i];
				p++;
			}
		}
		for(int i = 0;i < n;i++){
			if(isOnIn(x2[i], y2[i], x1, y1)){
				cx[p] = x2[i];
				cy[p] = y2[i];
				p++;
			}
		}
		
		cx = Arrays.copyOf(cx, p);
		cy = Arrays.copyOf(cy, p);
		
		convexSort(cx, cy);
		
		return new double[][]{cx, cy};
	}
	
	static double EPS = 1E-9;
	
	public static double[] interLines(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy)
	{
		double aa = bx - ax;
		double cc = by - ay;
		double bb = cx - dx;
		double dd = cy - dy;
		double xx = cx - ax;
		double yy = cy - ay;
		double det = aa * dd - bb * cc;
		if(Math.abs(det) < EPS)return null;
		double t = (dd * xx - bb * yy) / det;
		double u = (-cc * xx + aa * yy) / det;
		return new double[]{ax + (bx - ax) * t, ay + (by - ay) * t, t, u};
	}
	
	void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new E().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}