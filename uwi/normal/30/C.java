//package round30;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "1 0 0 0 0.5";
//	private String INPUT = "2 0 0 0 0.6 5 0 5 0.7";
//	private String INPUT = "3 0 0 0 0.6 4 0 4 0.85 2 0 5 0.8";
//	private String INPUT = "2 1000 1000 1000000000 0.15 -1000 -1000 500000000 0.1";
//	private String INPUT = "2 2 0 1 0.5 0 3 5 0.4";
	private String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		Target[] ts = new Target[n];
		for(int i = 0;i < n;i++){
			ts[i] = new Target();
			ts[i].x = ni();
			ts[i].y = ni();
			ts[i].t = ni();
			ts[i].p = in.nextDouble();
		}
		Arrays.sort(ts);
		
		double maxp = 0;
		double[] p = new double[n];
		for(int i = 0;i < n;i++){
			double curmax = 0;
//			if(ts[i].t * ts[i].t == ts[i].x * ts[i].x + ts[i].y * ts[i].y){
//				curmax = 0;
//			}
			
			for(int j = 0;j < i;j++){
				if(p[j] != -1 && (ts[i].t - ts[j].t) * (ts[i].t - ts[j].t) >= (ts[i].x - ts[j].x) * (ts[i].x - ts[j].x) + (ts[i].y - ts[j].y) * (ts[i].y - ts[j].y)){
					curmax = Math.max(curmax, p[j]);
				}
			}
			if(curmax == -1){
				p[i] = -1;
			}else{
				p[i] = curmax + ts[i].p;
				maxp = Math.max(maxp, p[i]);
			}
		}
		
		out.println(maxp);
	}
	
	public static class Target implements Comparable<Target>
	{
		public long x, y, t;
		public double p;
		
		@Override
		public int compareTo(Target o) {
			return Long.signum(this.t - o.t);
		}
	}
	
	public void run() throws Exception
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
	
	private int ni() { return Integer.parseInt(in.next()); }
	private void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}