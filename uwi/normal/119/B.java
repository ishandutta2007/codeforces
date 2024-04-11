//package round90;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "3 3 1 2 3 2 1 1";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] a = new int[n];
		for(int i = 0;i < n;i++){
			a[i] = ni();
		}
		BitSet used = new BitSet();
		
		double max = 0;
		double min = 999999;
		int q = ni();
		int uct = 0;
		for(int i = 0;i < q;i++){
			double sum = 0;
			for(int j = 0;j < n/m;j++){
				int ind = ni()-1;
				if(j == 0 && !used.get(ind)){
					uct++;
				}
				used.set(ind);
				sum += a[ind];
			}
			sum /= (n/m);
			max = Math.max(max, sum);
			min = Math.min(min, sum);
		}
		
		List<Integer> l = new ArrayList<Integer>();
		for(int i = used.nextClearBit(0);i < n;i = used.nextClearBit(i+1)){
			l.add(a[i]);
		}
		if(l.size() >= n/m && (uct < m || n/m>n-n/m*m)){
			Collections.sort(l);
			{
				double sum = 0;
				for(int i = 0;i < n/m;i++){
					sum += l.get(i);
				}
				sum /= (n/m);
				min = Math.min(min, sum);
			}
			{
				double sum = 0;
				int len = l.size();
				for(int i = 0;i < n/m;i++){
					sum += l.get(len-1-i);
				}
				sum /= (n/m);
				max = Math.max(max, sum);
			}
		}
		out.printf("%.9f %.9f\n", min, max);
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