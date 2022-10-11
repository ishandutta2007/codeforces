import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*; 
import java.util.*;
import java.util.regex.*;
/*
	  br = new BufferedReader(new FileReader("input.txt"));
	  pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
	  br = new BufferedReader(new InputStreamReader(System.in));
	  pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
 */


public class Main {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++){
			int n = readInt();
			int[] x = new int[n];
			int[] y = new int[n];
			double[] pts = new double[2*n];
			int index = 0;
			for(int i = 0; i < n; i++) {
				x[i] = readInt();
				y[i] = readInt();
				pts[index++] = x[i];
				pts[index++] = y[i];
			}
			readInt();
			readInt();
			Area area = makeArea(pts);
			int ret = 0;
			for(int k = 0; k < n; k++) {
				int l = (k+1)%n;
				double xx = x[l];
				double yy = y[l];
				if(x[l] > x[k]) {
					xx += 0.5;
				}
				if(x[l] < x[k]) {
					xx -= 0.5;
				}
				if(y[l] > y[k]) {
					yy += 0.5;
				}
				if(y[l] < y[k]) {
					yy -= 0.5;
				}
				if(area.contains(xx, yy)) {
					ret++;
				}
			}
			pw.println(ret);
		}
		exitImmediately();
	}

	public static Area makeArea(double[] pts) {
		Path2D.Double p = new Path2D.Double();
		p.moveTo(pts[0], pts[1]);
		for (int i = 2; i < pts.length; i += 2) p.lineTo(pts[i], pts[i+1]);
		p.closePath();
		return new Area(p);
	}

	public static double computePolygonArea(double[] x, double[] y)	{
		double ret = 0;
		for(int i = 0; i < x.length; i++)	{
			int j = (i+1);
			if(j >= x.length)
				j -= x.length;
			ret += x[i] * y[j] - x[j] * y[i];
		}
		return ret/2;
	}

	public static double computePolygonArea(ArrayList<Point2D.Double> points) {
		Point2D.Double[] pts = points.toArray(new Point2D.Double[points.size()]);
		double area = 0;
		for (int i = 0; i < pts.length; i++){
			int j = (i+1) % pts.length;
			area += pts[i].x * pts[j].y - pts[j].x * pts[i].y;
		}
		return Math.abs(area)/2;
	}
	public static double computeArea(Area a) {
		double ret = 0;
		PathIterator iter = a.getPathIterator(null);
		double[] buffer = new double[6];
		ArrayList<Double> ps = new ArrayList<Double>();
		while (!iter.isDone()) {
			switch (iter.currentSegment(buffer)) {
			case PathIterator.SEG_MOVETO:
			case PathIterator.SEG_LINETO:
				ps.add(buffer[0]);
				ps.add(buffer[1]);
				break;
			case PathIterator.SEG_CLOSE:
				ps.add(ps.get(0));
				ps.add(ps.get(1));
				Double[] qs = ps.toArray(new Double[0]);
				for (int i = 0; i + 2 < ps.size(); i += 2) {
					ret -= qs[i] * qs[i + 3] - qs[i + 1] * qs[i + 2];
				}
				ps.clear();
				break;
			}
			iter.next();
		}
		return ret/2;
	}

	public static double[] computeCentroid(double[] x, double[] y)	{
		double xx = 0;
		double yy = 0;
		for(int i = 0; i < x.length; i++)	{
			int j = i+1;
			if(j >= x.length)	{
				j -= x.length;
			}
			xx += (x[i] + x[j])*(x[i]*y[j]-x[j]*y[i]);
			yy += (y[i] + y[j])*(x[i]*y[j]-x[j]*y[i]);
		}
		double A = computePolygonArea(x,y);
		return new double[]{xx/(6*A),yy/(6*A)};
	}


	private static void exitImmediately() {
		pw.close();
		System.exit(0);
	}

	private static long readLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	private static double readDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	private static int readInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	private static String nextLine() throws IOException  {
		if(!br.ready()) {
			exitImmediately();
		}
		st = null;
		return br.readLine();
	}

	private static String nextToken() throws IOException  {
		while(st == null || !st.hasMoreTokens())  {
			if(!br.ready()) {
				exitImmediately();
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}