import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class E {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		Area first = new Area();
		double ret = 0;
		TreeSet<State> set = new TreeSet<State>();
		while(n-- > 0)	{
			StringTokenizer st = new StringTokenizer(br.readLine());
			double[] points = new double[8];
			for(int i = 0; i < 8; i++)	{
				points[i] = Integer.parseInt(st.nextToken());
				if(i%2 == 1)
					set.add(new State(points[i-1], points[i]));
			}
			Area next = new Area(makeArea(points));
			ret += computeArea(next);
			first.add(next);
		}
		ArrayList<State> up = new ArrayList<State>();
		ArrayList<State> dn = new ArrayList<State>();
		for(State curr: set)	{
			while (up.size() > 1 && area(up.get(up.size()-2), up.get(up.size()-1), curr) >= 0) 
				up.remove(up.size()-1);
			while (dn.size() > 1 && area(dn.get(dn.size()-2), dn.get(dn.size()-1), curr) <= 0) 
				dn.remove(dn.size()-1);
			up.add(curr);
			dn.add(curr);
		}
		ArrayList<State> hu = new ArrayList<State>();
		for(State s: dn)	{
			hu.add(s);
		}
		for(int i = up.size() - 2; i >= 1; i--)	{
			hu.add(up.get(i));
		}
		double[] p = new double[hu.size()<<1];
		for(int i = 0; i < hu.size(); i++)	{
			p[2*i] = hu.get(i).x;
			p[2*i+1] = hu.get(i).y;
		}
		Area hull = makeArea(p);
		double total = computeArea(hull);
		hull.exclusiveOr(first);
		double extra = computeArea(hull);
		System.out.println(ret / (total-extra));
	}
	public static double cross(State p, State q)   {
		return p.x*q.y-p.y*q.x;
	}
	public static double area(State a, State b, State c)	{
		return cross(a,b) + cross(b,c) + cross(c,a);
	}
	public static Area makeArea(double[] pts) {
		Path2D.Double p = new Path2D.Double();
		p.moveTo(pts[0], pts[1]);
		for (int i = 2; i < pts.length; i += 2) p.lineTo(pts[i], pts[i+1]);
		p.closePath();
		return new Area(p);        
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
	public static double computeArea(Area area) {
		double totArea = 0;
		PathIterator iter = area.getPathIterator(null);
		ArrayList<Point2D.Double> points = new ArrayList<Point2D.Double>();
		while (!iter.isDone()) {
			double[] buffer = new double[6];
			switch (iter.currentSegment(buffer)) {
			case PathIterator.SEG_MOVETO:
			case PathIterator.SEG_LINETO:
				points.add(new Point2D.Double(buffer[0], buffer[1]));
				break;
			case PathIterator.SEG_CLOSE:
				totArea += computePolygonArea(points);
				points.clear();
				break;
			}
			iter.next();
		}
		return totArea;
	}
	static class State implements Comparable<State> {
		public double x,y;
		public State(double a, double b)	{
			x=a;
			y=b;
		}
		public String toString()		{
			return x + " " + y;
		}
		public int compareTo(State s)	{
			if(y < s.y)
				return -1;
			else if(y > s.y)
				return 1;
			else if(x < s.x)
				return -1;
			else if(x > s.x)
				return 1;
			else
				return 0;
		}
	}
}