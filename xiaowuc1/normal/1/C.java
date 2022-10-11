import java.io.*;
import java.util.*;
public class C1 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		double x1 = Double.parseDouble(st.nextToken());
		double y1 = Double.parseDouble(st.nextToken());
		st = new StringTokenizer(br.readLine());
		double x2 = Double.parseDouble(st.nextToken());
		double y2 = Double.parseDouble(st.nextToken());
		st = new StringTokenizer(br.readLine());
		double x3 = Double.parseDouble(st.nextToken());
		double y3 = Double.parseDouble(st.nextToken());
		double b = y1-y3;
		double a = y2-y1;
		double c = (x2-x3)/2;
		double e = x3-x1;
		double d = x1-x2;
		double f = (y2-y3)/2;
		double t = (c*d-a*f)/(b*d-a*e);
		double xR = (x1+x3)/2 + t * (y1-y3);
		double yR = (y1+y3)/2 + t * (x3-x1);
		x1 -= xR;
		x2 -= xR;
		x3 -= xR;
		y1 -= yR;
		y2 -= yR;
		y3 -= yR;
		double r = dist(0,0,x1,y1);
		double side12 = dist(x1,y1,x2,y2);
		double side13 = dist(x1,y1,x3,y3);
		double side23 = dist(x2,y2,x3,y3);
		double[] angles = new double[3];
		angles[0] = Math.acos(1 - side12*side12/2/r/r);
		angles[1] = Math.acos(1 - side13*side13/2/r/r);
		angles[2] = Math.acos(1 - side23*side23/2/r/r);
		Arrays.sort(angles);
		angles[0] *= 180 / Math.PI;
		angles[1] *= 180 / Math.PI;
		angles[2] *= 180 / Math.PI;
		outer: for(int s = 3; s <= 100; s++)		{
			double test = 360./s;
			for(double x: angles)		{
				double error = x/test;
				double next = Math.round(error);
				if(Math.abs(error-next) > 1e-3)
					continue outer;
			}
			System.out.println(s*r*r/2*Math.sin(2*Math.PI/s));
			break;
		}
	}
	public static double dist(double x1, double y1, double x2, double y2)		{
		double x = x1-x2;
		double y = y1-y2;
		return Math.sqrt(x*x+y*y);
	}
}