//package round81;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int k = ni();
		int a = ni();
		int[] lv = new int[n];
		int[] lo = new int[n];
		for(int i = 0;i < n;i++){
			lv[i] = ni();
			lo[i] = ni();
		}
		
		out.printf("%.9f", rec(lv, lo, n, 0, k, a));
	}
	
	double rec(int[] lv, int[] lo, int n, int pos, int k, int a)
	{
		if(pos == n){
			int h = n/2+1;
			double gp = 0;
			for(int i = 0;i < 1<<n;i++){
				if(Integer.bitCount(i) >= h){
					double p = 1.0;
					for(int j = 0;j < n;j++){
						if(i<<31-j<0){
							p *= (double)lo[j] / 100;
						}else{
							p *= (double)(100-lo[j]) / 100;
						}
					}
					gp += p;
				}else{
					double p = 1.0;
					int sl = 0;
					for(int j = 0;j < n;j++){
						if(i<<31-j<0){
							p *= (double)lo[j] / 100;
						}else{
							p *= (double)(100-lo[j]) / 100;
							sl += lv[j];
						}
					}
					gp += p * a/(a+sl);
				}
			}
			return gp;
		}else{
			int o = lo[pos];
			double max = 0;
			for(int i = 0;i <= k && lo[pos] <= 100;i++){
				max = Math.max(max, rec(lv, lo, n, pos+1, k-i, a));
				lo[pos]+=10;
			}
			lo[pos] = o;
			return max;
		}
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
		new B().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}