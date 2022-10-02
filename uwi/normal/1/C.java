

import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.StringReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class C {
	private Scanner in;
	private PrintWriter out;
	
	public void solve()
	{
		double ax = in.nextDouble();
		double ay = in.nextDouble();
		double bx = in.nextDouble();
		double by = in.nextDouble();
		double cx = in.nextDouble();
		double cy = in.nextDouble();
		
		
		
		double qx = 2 * (ax - bx);
		double qy = 2 * (ay - by);
		double qr = ax * ax + ay * ay - bx * bx - by * by;
		
		double rx = 2 * (cx - bx);
		double ry = 2 * (cy - by);
		double rr = cx * cx + cy * cy - bx * bx - by * by;
		
		double det = 1 / (qx * ry - qy * rx);
		double ox = det * (ry * qr - qy * rr);
		double oy = det * (-rx * qr + qx * rr);
		
		double at = StrictMath.atan2(ay - oy, ax - ox);
		double bt = StrictMath.atan2(by - oy, bx - ox);
		double ct = StrictMath.atan2(cy - oy, cx - ox);
		double aaa = at - bt;
		double bbb = bt - ct;
		
//		double acx = ax - cx;
//		double acy = ay - cy;
//		double bcx = bx - cx;
//		double bcy = by - cy;
//		double abx = ax - bx;
//		double aby = ay - by;
//		double aaa = 2 * Math.acos((acx * bcx + acy * bcy) / Math.sqrt(acx * acx + acy * acy) / Math.sqrt(bcx * bcx + bcy * bcy));
//		double bbb = 2 * Math.acos((acx * abx + acy * aby) / Math.sqrt(acx * acx + acy * acy) / Math.sqrt(abx * abx + aby * aby));
		
		double T = 0.001;
//		if(Math.abs(ct - at) < T){
//			double d2 = (bx - cx) * (bx - cx) + (by - cy) * (by - cy);
//			out.printf("%1.8f\n", d2 * Math.sqrt(3) / 4);
//			out.flush();
//			return;
//		}
		if(aaa < 0)aaa = -aaa;
		if(bbb < 0)bbb = -bbb;
//		if(aaa < T || bbb < T){
//			double d2 = (ax - cx) * (ax - cx) + (ay - cy) * (ay - cy);
//			out.printf("%1.8f\n", d2 * Math.sqrt(3) / 4);
//			out.flush();
//			return;
//		}
//		if(aaa < bbb){
//			double d = aaa;
//			aaa = bbb;
//			bbb = d;
//		}
//		double nn = 0;
//		while(bbb > T){
//			nn = StrictMath.round(StrictMath.PI * 2 / bbb);
//			if(nn > 100)break;
//			double ccc = aaa;
//			aaa = bbb;
//			bbb = ccc % bbb;
//		}
//		double n = nn > 100 ? 100 : StrictMath.round(StrictMath.PI * 2 / aaa);
		for(int n = 3;n <= 100;n++){
			double theta = 2 * Math.PI / n;
			if(
					Math.abs(aaa / theta - Math.round(aaa / theta)) < T && 
					Math.abs(bbb / theta - Math.round(bbb / theta)) < T
					){
				double r2 = (ax - ox) * (ax - ox) + (ay - oy) * (ay - oy);
				out.printf("%1.6f\n", 0.5 * r2 * StrictMath.sin(StrictMath.PI * 2 / n) * n);
				break;
			}
		}
		
		out.flush();
	}
	
	public void run() throws Exception
	{
//		in = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("input.txt"))));
//		out = new PrintWriter(new FileWriter(new File("output.txt")));
//		in = new Scanner(new StringReader("0 0 1000 1000 0 1000"));
		in = new Scanner(System.in);
//		System.setOut(new PrintStream(new BufferedOutputStream(System.out)));
		out = new PrintWriter(System.out);
		
//		int n = in.nextInt();
		int n = 1;
		for(int i = 1;i <= n;i++){
			long t = System.currentTimeMillis();
			solve();
//			System.err.printf("%04d/%04d %7d%n", i, n, System.currentTimeMillis() - t);
		}
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new C().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private static void tr(Object... o) { System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
	private void tra(int[] a) {System.out.println(Arrays.toString(a));}
	private void tra(int[][] a)
	{
		for(int[] e : a){
			System.out.println(Arrays.toString(e));
		}
	}
	
}