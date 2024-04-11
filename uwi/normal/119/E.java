//package round90re;
import java.awt.geom.Line2D;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		double[][] co = new double[n][];
		for(int i = 0;i < n;i++){
			co[i] = new double[]{ni(), ni(), ni()};
		}
		for(int i = 0;i < m;i++){
			double[] nor = new double[]{ni(), ni(), ni()};
			double[][] nco = rot(nor, new double[]{0, 0, 1}, co);
			out.printf("%.15f\n", minCircle(nco));
		}
	}
	
	public double minCircle(double[][] co)
	{
		int n = co.length;
		if(n <= 1)return 0;
		
		// 
		double maxd = -1;
		int first = -1;
		for(int i = 0;i < n;i++){
			double d2 = co[i][0]*co[i][0]+co[i][1]*co[i][1];
			if(d2 > maxd){
				maxd = d2;
				first = i;
			}
		}
		
		// 2
		// (tx,ty)(x,y)-(x',y')t
		// (T-M)*L=0
		// t(x*Lx+y*Ly)=mx*Lx+my*Ly
		double mint = 1.01;
		int second = -1;
		double fx = co[first][0], fy = co[first][1];
		for(int i = 0;i < n;i++){
			if(i == first)continue;
			double ox = co[i][0], oy = co[i][1];
			double mx = (fx+ox)/2, my = (fy+oy)/2;
			double t = (mx*(ox-fx)+my*(oy-fy))/(fx*(ox-fx)+fy*(oy-fy));
			if(t < mint){
				mint = t;
				second = i;
			}
		}
		if(second == -1){ // second
			return 0;
		}
		
		boolean[] sed = new boolean[n];
		sed[first] = true;
		sed[second] = true;
		
		// CM
		int third = -1;
		while(true){
			double mx = (co[first][0] + co[second][0])/2;
			double my = (co[first][1] + co[second][1])/2;
			double nr2 = (mx-co[first][0])*(mx-co[first][0])+(my-co[first][1])*(my-co[first][1]);
			double[] ec = null;
			third = -1;
			for(int i = 0;i < n;i++){
				if(sed[i])continue;
//				if(i == first || i == second)continue;
				if((mx-co[i][0])*(mx-co[i][0])+(my-co[i][1])*(my-co[i][1]) <= nr2)continue;
				double[] lec = excircle2(co[first][0], co[first][1], co[second][0], co[second][1], co[i][0], co[i][1]);
				if(ec == null || lec[2] > ec[2]){
					ec = lec;
					third = i;
				}
			}
			if(ec == null)break;
			sed[third] = true;
			if(Line2D.linesIntersect(co[first][0], co[first][1], co[third][0], co[third][1], ec[0], ec[1], co[second][0], co[second][1])){
				second = third;
				continue;
			}
			if(Line2D.linesIntersect(co[second][0], co[second][1], co[third][0], co[third][1], ec[0], ec[1], co[first][0], co[first][1])){
				first = third;
				continue;
			}
			return ec[2];
		}
		return Math.sqrt((co[second][0]-co[first][0])*(co[second][0]-co[first][0])+(co[second][1]-co[first][1])*(co[second][1]-co[first][1]))/2;
	}
	
	public static double[] excircle2(double ax, double ay, double bx, double by, double cx, double cy)
	{
		double A = (bx-cx)*(bx-cx)+(by-cy)*(by-cy);
		double B = (cx-ax)*(cx-ax)+(cy-ay)*(cy-ay);
		double C = (ax-bx)*(ax-bx)+(ay-by)*(ay-by);
		double D = A*(-A+B+C)+B*(A-B+C)+C*(A+B-C);
		double X = (A*(-A+B+C)*ax + B*(A-B+C)*bx + C*(A+B-C)*cx) / D;
		double Y = (A*(-A+B+C)*ay + B*(A-B+C)*by + C*(A+B-C)*cy) / D;
		double R = Math.sqrt((X-ax)*(X-ax)+(Y-ay)*(Y-ay));
//		double R = A*B*C/Math.sqrt((A+B+C)*(-A+B+C)*(A-B+C)*(A+B-C));
		return new double[]{X, Y, R};
	}
	
	public static double[][] rot(double[] from, double[] to, double[][] xs)
	{
		double nfrom = Math.sqrt(from[0]*from[0]+from[1]*from[1]+from[2]*from[2]);
		for(int i = 0;i < 3;i++)from[i] /= nfrom;
		double nto = Math.sqrt(to[0]*to[0]+to[1]*to[1]+to[2]*to[2]);
		for(int i = 0;i < 3;i++)to[i] /= nto;
		double dot = from[0]*to[0]+from[1]*to[1]+from[2]*to[2];
		if(dot >= 1)dot = 1;
		if(dot <= -1)dot = -1;
		double angle = Math.acos(dot);
		if(Math.abs(angle) < 1E-8)return xs;
		
		double[] axis = new double[]{
				from[1]*to[2]-from[2]*to[1],
				from[2]*to[0]-from[0]*to[2],
				from[0]*to[1]-from[1]*to[0]
		};
		double nax = Math.sqrt(axis[0]*axis[0]+axis[1]*axis[1]+axis[2]*axis[2]);
		for(int i = 0;i < 3;i++)axis[i] /= nax;
		
		double[][] ret = new double[xs.length][3];
		
		double ncos = Math.cos(angle);
		double nsin = Math.sin(angle);
		double scos = 1.0 - ncos;
		
		double sxy = axis[0] * axis[1] * scos;
		double syz = axis[1] * axis[2] * scos;
		double sxz = axis[0] * axis[2] * scos;
		double sz = nsin * axis[2];
		double sy = nsin * axis[1];
		double sx = nsin * axis[0];
		
		int p = 0;
		for(double[] x : xs){
			ret[p][0] = (ncos+axis[0]*axis[0]*scos)*x[0] + (-sz+sxy)*x[1]+(sy+sxz)*x[2];
			ret[p][1] = (sz+sxy)*x[0]+(ncos+axis[1]*axis[1]*scos)*x[1]+(-sx+syz)*x[2];
			ret[p][2] = (-sy+sxz)*x[0]+(sx+syz)*x[1]+(ncos+axis[2]*axis[2]*scos)*x[2];
			p++;
		}
		return ret;
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
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}