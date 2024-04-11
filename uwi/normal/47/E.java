//package round44;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Iterator;
import java.util.Scanner;
import java.util.TreeMap;

public class E2 {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		double V = ni();
		final double[] alpha = new double[n];
		for(int i = 0;i < n;i++){
			alpha[i] = in.nextDouble();
		}
		
		int m = ni();
		double g = 9.8;
		Wall[] w = new Wall[m];
		for(int i = 0;i < m;i++){
			w[i] = new Wall();
			w[i].x = in.nextDouble();
			w[i].y = in.nextDouble();
		}
		
		TreeMap<Double, Integer> ranges = new TreeMap<Double, Integer>();
		ranges.put(0.0, -1);
		
		Arrays.sort(w, new Comparator<Wall>(){
			public int compare(Wall a, Wall b){
				return (int)Math.signum(a.x - b.x);
			}
		});
		for(int i = m - 1;i >= 0;i--){
			double inf1 = 0, sup1 = 0, inf2 = 0, sup2 = 0;
			double a1 = g / 2  * w[i].x * w[i].x / V / V;
			double b1 = -w[i].x;
			double c1 = w[i].y + g / 2  * w[i].x * w[i].x / V / V;
			double D1 = b1 * b1 - 4.0 * a1 * c1;
			if(D1 >= 0){
				inf1 = (-b1 - Math.sqrt(D1)) / (2 * a1);
				sup1 = (-b1 + Math.sqrt(D1)) / (2 * a1);
				inf1 = Math.min(Math.max(inf1, 0), 1);
				sup1 = Math.min(Math.max(sup1, 0), 1);
				// p<=inf, p>=sup
			}
			double a2 = g / 2 * w[i].x * w[i].x / V / V;
			double b2 = -w[i].x;
			double c2 = g / 2 * w[i].x * w[i].x / V / V;
			double D2 = b2 * b2 - 4.0 * a2 * c2;
			if(D2 >= 0){
				inf2 = (-b2 - Math.sqrt(D2)) / (2 * a2);
				sup2 = (-b2 + Math.sqrt(D2)) / (2 * a2);
				// p>=inf, p<=sup
				inf2 = Math.min(Math.max(inf2, 0), 1);
				sup2 = Math.min(Math.max(sup2, 0), 1);
			}
			
			if(D1 >= 0 && D2 >= 0){
				addRange(ranges, inf2, inf1, i);
				if(sup1 < 1)addRange(ranges, sup1, sup2, i);
			}else if(D1 < 0 && D2 >= 0){
				addRange(ranges, inf2, sup2, i);
			}
		}
		
		for(int i = 0;i < n;i++){
			int hit = ranges.floorEntry(Math.tan(alpha[i])).getValue();
			if(hit >= 0){
				double t = w[hit].x / V / Math.cos(alpha[i]);
				double y = V * t * Math.sin(alpha[i]) - g * t * t / 2;
				out.println(w[hit].x + " " + y);
			}else{
				double x = V * V * Math.sin(2 * alpha[i]) / g;
				out.println(x + " 0");
			}
		}
	}
	
	void addRange(TreeMap<Double, Integer> range, double inf, double sup, int ind)
	{
		int supWall = range.floorEntry(sup).getValue();
		
		Iterator<Double> it = range.subMap(inf, sup).keySet().iterator();
		while(it.hasNext()){
			it.next();
			it.remove();
		}
		range.put(inf, ind);
		range.put(sup, supWall);
	}
	
	class Wall
	{
		public double x, y;
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
		new E2().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}