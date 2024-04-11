//package round47;

import java.awt.geom.Line2D;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		double[] x = new double[n];
		double[] y = new double[n];
		for(int i = 0;i < n;i++){
			x[i] = ni();
			y[i] = ni();
		}
		
		double[] xx = new double[4*n];
		double[] yy = new double[4*n];
		for(int i = 0;i < n;i++){
			xx[4*i] = x[i]-1; yy[4*i] = y[i];
			xx[4*i+1] = x[i]+1; yy[4*i+1] = y[i];
			xx[4*i+2] = x[i]; yy[4*i+2] = y[i]-1;
			xx[4*i+3] = x[i]; yy[4*i+3] = y[i]+1;
		}
		int[] ch = convexHull(xx, yy);
		
		int m = ch.length;
		double d = 0;
		for(int i = 0;i < ch.length - 1;i++){
			d += dist(xx[ch[i]], yy[ch[i]], xx[ch[i+1]], yy[ch[i+1]]);
		}
		d += dist(xx[ch[m-1]], yy[ch[m-1]], xx[ch[0]], yy[ch[0]]);
		out.println((int)d);
	}
	
	double dist(double ax, double ay, double bx, double by)
	{
		double dx = Math.abs(ax - bx);
		double dy = Math.abs(ay - by);
		double max = Math.max(dx, dy);
		return max;
	}
	
	public int[] convexHull(final double[] x, final double[] y)
	{
		int n = x.length;
		Integer[] ord = new Integer[n];
		for(int i = 0;i < n;i++)ord[i] = i;
		Arrays.sort(ord, new Comparator<Integer>(){
			public int compare(Integer a, Integer b){
				if(x[a] != x[b])return x[a] < x[b] ? -1 : 1;
				if(y[a] != y[b])return y[a] < y[b] ? -1 : 1;
				return 0;
			}
		});
		
		int[] ret = new int[n + 1];
		int p = 0;
		for(int i = 0;i < n;i++){
			if(p >= 1 && x[ret[p-1]] == x[ord[i]] && y[ret[p-1]] == y[ord[i]])continue;
			while(p >= 2 && Line2D.relativeCCW(
					x[ret[p-2]], y[ret[p-2]],
					x[ret[p-1]], y[ret[p-1]],
					x[ord[i]], y[ord[i]]) == 1)p--;
			ret[p++] = ord[i];
		}
		
		int inf = p + 1;
		for(int i = n - 2;i >= 0;i--){
			if(x[ret[p-1]] == x[ord[i]] && y[ret[p-1]] == y[ord[i]])continue;
			while(p >= inf && Line2D.relativeCCW(
					x[ret[p-2]], y[ret[p-2]],
					x[ret[p-1]], y[ret[p-1]],
					x[ord[i]], y[ord[i]]) == 1)p--;
			ret[p++] = ord[i];
		}
		
		return Arrays.copyOf(ret, p - 1);
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
		new C().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}