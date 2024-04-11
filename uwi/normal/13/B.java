//package round13;


import java.io.BufferedOutputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.StringReader;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	private Scanner in;
	private PrintWriter out;
	
	public void solve()
	{
		double[][] p = new double[3][4];
		for(int i = 0;i < 3;i++){
			for(int j = 0;j < 4;j++){
				p[i][j] = in.nextDouble();
			}
		}
		
		double[][] c = new double[3][4];
		
		for(int s = 0;s <= 2;s+=2){
			for(int t = 0;t <= 2;t+=2){
				for(int u = 0;u <= 2;u+=2){
					for(int i = 0;i < 4;i++){
						c[0][i] = p[0][(s+i)%4];
						c[1][i] = p[1][(t+i)%4];
						c[2][i] = p[2][(u+i)%4];
					}
					if(check(c)){
						out.println("YES"); return;
					}
				}
			}
		}
		
		for(int s = 0;s <= 2;s+=2){
			for(int t = 0;t <= 2;t+=2){
				for(int u = 0;u <= 2;u+=2){
					for(int i = 0;i < 4;i++){
						c[0][i] = p[0][(s+i)%4];
						c[1][i] = p[2][(t+i)%4];
						c[2][i] = p[1][(u+i)%4];
					}
					if(check(c)){
						out.println("YES"); return;
					}
				}
			}
		}
		
		for(int s = 0;s <= 2;s+=2){
			for(int t = 0;t <= 2;t+=2){
				for(int u = 0;u <= 2;u+=2){
					for(int i = 0;i < 4;i++){
						c[0][i] = p[1][(s+i)%4];
						c[1][i] = p[2][(t+i)%4];
						c[2][i] = p[0][(u+i)%4];
					}
					if(check(c)){
						out.println("YES"); return;
					}
				}
			}
		}
		
		out.println("NO");
	}
	
	private boolean check(double[][] c)
	{
		if(!(c[0][0] == c[1][0] && c[0][1] == c[1][1]))return false;
		
		double ip = (c[0][2] - c[0][0]) * (c[1][2] - c[1][0]) + (c[0][3] - c[0][1]) * (c[1][3] - c[1][1]);
		double L0 = (c[0][2] - c[0][0]) * (c[0][2] - c[0][0]) + (c[0][3] - c[0][1]) * (c[0][3] - c[0][1]);
		double L1 = (c[1][2] - c[1][0]) * (c[1][2] - c[1][0]) + (c[1][3] - c[1][1]) * (c[1][3] - c[1][1]);
		
		if(!(ip >= 0 && ip * ip < L0 * L1))return false;
		
		{
			double aa = c[0][0] - c[0][2];
			double cc = c[0][1] - c[0][3];
			double bb = -c[2][0] + c[2][2];
			double dd = -c[2][1] + c[2][3];
			double xx = c[2][2] - c[0][2];
			double yy = c[2][3] - c[0][3];
			double det = aa * dd - bb * cc;
			if(det == 0)return false;
			double t = (double)(dd * xx - bb * yy) / det;
			double u = (double)(-cc * xx + aa * yy) / det;
			if(!((u == 0 || u == 1) && t >= 0.2 && t <= 0.8))return false;
		}
		
		{
			double aa = c[1][0] - c[1][2];
			double cc = c[1][1] - c[1][3];
			double bb = -c[2][0] + c[2][2];
			double dd = -c[2][1] + c[2][3];
			double xx = c[2][2] - c[1][2];
			double yy = c[2][3] - c[1][3];
			double det = aa * dd - bb * cc;
			if(det == 0)return false;
			double t = (double)(dd * xx - bb * yy) / det;
			double u = (double)(-cc * xx + aa * yy) / det;
			if(!((u == 0 || u == 1) && t >= 0.2 && t <= 0.8))return false;
		}
		return true;
	}
	
	public void run() throws Exception
	{
//		in = new Scanner(new StringReader("3 4 4 6 0 4 1 5 2 4 0 4 4 0 0 0 6 0 6 2 -4 1 1 0 1 0 0 0 5 0 5 2 -1 1 2 0 1"));
		in = new Scanner(System.in);
		System.setOut(new PrintStream(new BufferedOutputStream(System.out)));
		out = new PrintWriter(System.out);
		
		int n = in.nextInt();
		for(int i = 1;i <= n;i++){
			long t = System.currentTimeMillis();
			solve();
			out.flush();
//			System.err.printf("%04d/%04d %7d%n", i, n, System.currentTimeMillis() - t);
		}
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new B().run();
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