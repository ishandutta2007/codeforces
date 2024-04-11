//package round74;
import java.awt.geom.QuadCurve2D;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class D {
	Scanner in;
	PrintWriter out;
	String INPUT = "0 0 0 1 0 0 5\r\n" +
			"2\r\n" +
			"10 8 0 2 2\r\n" +
			"0 -3 0\r\n" +
			"2 2 0\r\n" +
			"20 0 0 4 3\r\n" +
			"2 4 0\r\n" +
			"-4 3 0\r\n" +
			"1 -5 0";
//	String INPUT = "30 30 2 1 2 1 20\r\n" +
//			"3\r\n" +
//			"0 0 40 5 1\r\n" +
//			"1 4 4\r\n" +
//			"-10 -40 -5 7 0\r\n" +
//			"100 200 95 8 1\r\n" +
//			"-10 0 0";
	
	void solve()
	{
		double[] DSX = new double[3];
		for(int i = 0;i < 3;i++)DSX[i] = ni();
		double[] DSV = new double[3];
		for(int i = 0;i < 3;i++)DSV[i] = ni();
		double DSR = ni();
		
		// 
		int n = ni();
		double mint = Double.MAX_VALUE;
		for(int i = 0;i < n;i++){
			double[] MX = new double[3];
			for(int j = 0;j < 3;j++)MX[j] = ni();
			double MR = ni();
			mint = checkDSM(mint, DSX, DSV, DSR, MX, MR);
			int m = ni();
			double[] SX = new double[3];
			for(int j = 0;j < m;j++){
				for(int k = 0;k < 3;k++)SX[k] = ni();
				mint = checkDSS(mint, DSX, DSV, DSR, MX, SX);
			}
		}
		if(mint == Double.MAX_VALUE){
			out.println(-1);
		}else{
			out.printf("%1.10f\n", mint);
		}
	}
	
	double checkDSM(double mint, double[] DSX, double[] DSV, double DSR, double[] MX, double MR)
	{
		double V2 = DSV[0]*DSV[0]+DSV[1]*DSV[1]+DSV[2]*DSV[2];
		double[] XM = new double[3];
		for(int i = 0;i < 3;i++){
			XM[i] = DSX[i] - MX[i];
		}
		double XMV = XM[0]*DSV[0]+XM[1]*DSV[1]+XM[2]*DSV[2];
		double XM2 = XM[0]*XM[0]+XM[1]*XM[1]+XM[2]*XM[2];
		double RR2 = (DSR+MR)*(DSR+MR);
		
		double A = V2;
		double B = XMV;
		double C = XM2-RR2;
		if(B*B-A*C >= 0){
			double sq = Math.sqrt(B*B-A*C);
			if(-B-sq >= 0){
				mint = Math.min(mint, (-B-sq)/A);
			}else if(-B+sq >= 0){
				mint = Math.min(mint, (-B+sq)/A);
			}
		}
		return mint;
	}
	
	double checkDSS(double mint, double[] DSX, double[] DSV, double DSR, double[] MX, double[] SX)
	{
		double V2 = DSV[0]*DSV[0]+DSV[1]*DSV[1]+DSV[2]*DSV[2];
		double U2 = SX[0]*SX[0]+SX[1]*SX[1]+SX[2]*SX[2];
		double UV = SX[0]*DSV[0]+SX[1]*DSV[1]+SX[2]*DSV[2];
		double[] XM = new double[3];
		for(int i = 0;i < 3;i++){
			XM[i] = DSX[i] - MX[i];
		}
		double XMV = XM[0]*DSV[0]+XM[1]*DSV[1]+XM[2]*DSV[2];
		double XM2 = XM[0]*XM[0]+XM[1]*XM[1]+XM[2]*XM[2];
		double R2 = DSR*DSR;
		double XMU = XM[0]*SX[0]+XM[1]*SX[1]+XM[2]*SX[2];
		
		double A = V2;
		double a = UV;
		double b = -XMV;
		double c = a*a-A*U2;
		double d = 2*a*b+2*XMU*A;
		double e = b*b-A*(XM2-R2);
		double[] res = new double[3];
		int Z = QuadCurve2D.solveQuadratic(new double[]{e,d,c}, res);
		for(int i = 0;i < Z;i++){
			if(res[i] >= 0 && res[i] <= 1){
				double p = res[i];
				if(a*p+b >= 0)mint = Math.min(mint, (a*p+b)/A);
			}
		}
		
		double f = 4*c*c-4*a*a*c;
		double g = 4*c*d-4*a*a*d;
		double h = d*d-4*a*a*e;
		Z = QuadCurve2D.solveQuadratic(new double[]{h,g,f}, res);
		for(int i = 0;i < Z;i++){
			if(res[i] >= 0 && res[i] <= 1){
				double p = res[i];
				double D = c*p*p+d*p+e;
				if(D >= 0){
					double Q = (a*p+b-Math.sqrt(D))/A;
					if(Q >= 0){
						mint = Math.min(mint, Q);
					}
				}
			}
		}
		
		for(double p = 0;p <= 1;p++){
			double D = c*p*p+d*p+e;
			if(D >= 0){
				double Q = (a*p+b-Math.sqrt(D))/A;
				if(Q >= 0){
					mint = Math.min(mint, Q);
				}
			}
		}
		return mint;
	}
	
	void run() throws Exception
	{
		in = oj ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new D().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}