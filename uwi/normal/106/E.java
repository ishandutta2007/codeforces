//package round82;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class E2 {
	Scanner in;
	PrintWriter out;
	String INPUT = "5\r\n" +
			"5 0 0\r\n" +
			"-5 0 0\r\n" +
			"0 3 4\r\n" +
			"4 -3 0\r\n" +
			"2 2 -2";
	
	void solve()
	{
		int n = ni();
		double[][] co = new double[n][4];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < 3;j++){
				co[i][j] = ni();
			}
		}
		
		double x = 0, y = 0, z = 0;
		double move = 0.5;
		while(move > 1E-8){
			for(int t = 0;t < 300;t++){
				double max = -1;
				int maxk = -1;
				for(int i = 0;i < n;i++){
					double d = Math.sqrt((x-co[i][0])*(x-co[i][0])+(y-co[i][1])*(y-co[i][1])+(z-co[i][2])*(z-co[i][2]));
					if(d > max){
						max = d;
						maxk = i;
					}
				}
				
				x += (co[maxk][0] - x) * move;
				y += (co[maxk][1] - y) * move;
				z += (co[maxk][2] - z) * move;
			}
			move /= 2;
		}
		out.printf("%.9f %.9f %.9f\n", x, y, z);
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
		new E2().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}