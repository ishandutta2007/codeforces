//package round60;

import java.awt.geom.QuadCurve2D;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		double[] x = new double[n+1];
		double[] y = new double[n+1];
		double[] z = new double[n+1];
		for(int i = 0;i < n+1;i++){
			x[i] = ni();
			y[i] = ni();
			z[i] = ni();
		}
		double vp = ni();
		double vs = ni();
		double hx = ni();
		double hy = ni();
		double hz = ni();
		
		double ped = 0;
		for(int i = 0;i < n;i++){
			double dx = x[i+1] - x[i];
			double dy = y[i+1] - y[i];
			double dz = z[i+1] - z[i];
			double d = Math.sqrt(
				(x[i+1] - x[i])*(x[i+1] - x[i]) +
				(y[i+1] - y[i])*(y[i+1] - y[i]) +
				(z[i+1] - z[i])*(z[i+1] - z[i])
				);
			double te = d / vs;
			double bx = dx/d * -ped*vs + x[i];
			double by = dy/d * -ped*vs + y[i];
			double bz = dz/d * -ped*vs + z[i];
			
			double vsx = dx / d * vs;
			double vsy = dy / d * vs;
			double vsz = dz / d * vs;
			
			double inn = -2*((hx-bx)*vsx+(hy-by)*vsy+(hz-bz)*vsz);
			double[] ret = new double[3];
			double[] qua = new double[]{di(hx,hy,hz,bx,by,bz), inn, vs*vs-vp*vp};
//			tr("b", bx, by, bz);
//			tr("vs", vsx, vsy, vsz);
//			tr(qua);
			int q = QuadCurve2D.solveQuadratic(qua, ret);
			if(q > 1)Arrays.sort(ret, 0, q);
			for(int j = 0;j < q;j++){
				if(ret[j] >= ped - EPS && ret[j] <= ped + te + EPS){
					out.println("YES");
					out.println(ret[j]);
					out.println(
							(bx + vsx * ret[j]) + " " +
							(by + vsy * ret[j]) + " " +
							(bz + vsz * ret[j])
							               );
					return;
				}
			}
			ped += te;
		}
		out.println("NO");
	}
	
	double EPS = 1E-7;
		
	double di(double ax, double ay, double az, double bx, double by, double bz)
	{
		return
				(ax-bx)*(ax-bx)+
				(ay-by)*(ay-by)+
				(az-bz)*(az-bz)
				;
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
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}