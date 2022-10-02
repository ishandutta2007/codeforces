//package round58;

import java.awt.geom.Line2D;
import java.awt.geom.Point2D;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class C3 {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[][] ls = new int[3*n][];
		for(int i = 0;i < n;i++){
			int x1 = ni(), y1 = ni();
			int x2 = ni(), y2 = ni();
			int x3 = ni(), y3 = ni();
			ls[3*i] = new int[]{x1, y1, x2, y2};
			ls[3*i+1] = new int[]{x2, y2, x3, y3};
			ls[3*i+2] = new int[]{x3, y3, x1, y1};
		}
		
		double[][][] cs = new double[3*n][3*n][];
		for(int i = 0;i < 3*n;i++){
			for(int j = 0;j < 3*n;j++){
				if(i != j){
					double[] il = interLines(ls[i][0], ls[i][1], ls[i][2], ls[i][3], ls[j][0], ls[j][1], ls[j][2], ls[j][3]);
					if(il != null && il[2] > -EPS && il[2] < 1+EPS && il[3] > -EPS && il[3] < 1+EPS){
						cs[i][j] = il;
					}
				}
			}
		}
		
		double ret = 0;
		for(int i = 0;i < 3*n;i++){
			final double[] ts = new double[3*n];
			int[] es = new int[3*n];
			int p = 0;
			for(int j = 0;j < 3*n;j++){
				if(cs[i][j] != null){
					ts[p] = cs[i][j][2];
					es[p] = j;
					p++;
				}
			}
			Integer[] ord = new Integer[p];
			for(int j = 0;j < p;j++){
				ord[j] = j;
			}
			Arrays.sort(ord, new Comparator<Integer>(){
				public int compare(Integer x, Integer y)
				{
					return (int)Math.signum(ts[x]-ts[y]);
				}
			});
			
			outer:
			for(int j = 0;j < p-1;j++){
				double[] cur = cs[i][es[ord[j]]];
				double[] nex = cs[i][es[ord[j+1]]];
				double dist = Point2D.distance(cur[0], cur[1], nex[0], nex[1]);
				if(dist > EPS){
					double cx = (cur[0]+nex[0])/2;
					double cy = (cur[1]+nex[1])/2;
					for(int k = 0;k < n;k++){
						if(k != i/3 && isIn(ls, k, cx, cy)){
							continue outer;
						}
					}
					ret += dist;
				}
			}
		}
		out.println(ret);
	}
	
	public boolean isIn(int[][] ls, int k, double cx, double cy)
	{
		int cc = Line2D.relativeCCW(ls[3*k][0], ls[3*k][1], ls[3*k][2], ls[3*k][3], cx, cy);
		if(cc == 0)return false;
		for(int l = 1;l < 3;l++){
			int ccc = Line2D.relativeCCW(ls[3*k+l][0], ls[3*k+l][1], ls[3*k+l][2], ls[3*k+l][3], cx, cy);
			if(cc != ccc)return false;
		}
		return true;
	}
	
	public boolean isIn(double x, double y, int[] px, int[] py)
	{
		int n = px.length;
		int cc = Line2D.relativeCCW(px[n-1], py[n-1], px[0], py[0], x, y);
		if(cc == 0)return false;
		for(int i = 0;i < n-1;i++){
			int ccc = Line2D.relativeCCW(px[i], py[i], px[i+1], py[i+1], x, y);
			if(cc != ccc)return false;
		}
		return true;
	}
	
	
	double EPS = 1E-8;
	public double[] interLines(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy)
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
		new C3().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}