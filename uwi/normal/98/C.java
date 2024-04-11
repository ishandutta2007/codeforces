//package round78;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "2 1 2";
	
	void solve()
	{
		double a = ni();
		double b = ni();
		double l = ni();
		if(!check(a, b, 0, l)){
			out.println("My poor head =(");
			return;
		}
		double inf = 0;
		double sup = Math.min(a, Math.min(b, l));
		if(l <= b){
			inf = Math.min(a,sup);
		}
		if(l <= a){
			inf = Math.min(b,sup);
		}
		while(sup - inf > 1E-9){
			double w = (sup+inf)/2;
			if(check(a, b, w, l)){
				inf = w;
			}else{
				sup = w;
			}
		}
		out.printf("%.7f\n", inf);
	}
	
	boolean check(double a, double b, double w, double l)
	{
		return GSM(1E-9, Math.PI/2-1E-9, a, b, w) >= l;
	}
	
	public double GSM(double inf, double sup, double a, double b, double w)
	{
		double tau = (Math.sqrt(5)-1)/2;
		double m1 = inf, m2 = sup;
		double dm1 = Double.NaN, dm2 = Double.NaN;
		while(sup - inf > 1E-9){
			if(Double.isNaN(dm1)){
				m1 = sup + tau * (inf - sup);
				dm1 = f(m1, a, b, w);
			}
			if(Double.isNaN(dm2)){
				m2 = inf + tau * (sup - inf);
				dm2 = f(m2, a, b, w);
			}
			if(dm1 < dm2){
				sup = m2;
				dm2 = dm1;
				m2 = m1;
				dm1 = Double.NaN;
			}else{
				inf = m1;
				dm1 = dm2;
				m1 = m2;
				dm2 = Double.NaN;
			}
		}
		return f(inf, a, b, w);
	}
	
	static double f(double x, double a, double b, double w)
	{
		return (a-w*Math.cos(x)) / Math.sin(x) + (b-w*Math.sin(x)) / Math.cos(x);
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
		new C().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}