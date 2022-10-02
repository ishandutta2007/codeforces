//package round84;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		long[] ln = new long[10000];
		ln[0] = 0;
		int p = 1;
		for(int i = 0;i < p;i++){
			if(ln[i]*10+4<=1000000000){
				ln[p++] = ln[i]*10+4;
				ln[p++] = ln[i]*10+7;
			}
		}
		ln[p] = 1000000009;
		
		int pl = ni(), pr = ni(), vl = ni(), vr = ni();
		int k = ni();
		
		long num = 0;
		for(int i = 1;i + k - 1 < p;i++){
			// [ln[i], ln[i+k-1]]
			{
				// [ln[i-1]+1, ln[i]] and [vl,vr]
				long w1 = Math.max(Math.min(ln[i], vr) - Math.max(ln[i-1]+1, vl) + 1, 0);
				// [ln[i+k-1], ln[i+k]-1] and [pl,pr]
				long w2 = Math.max(Math.min(ln[i+k]-1, pr) - Math.max(ln[i+k-1], pl) + 1, 0);
				num += (long)w1 * w2;
			}
			{
				// [ln[i-1]+1, ln[i]] and [pl,pr]
				long w1 = Math.max(Math.min(ln[i], pr) - Math.max(ln[i-1]+1, pl) + 1, 0);
				// [ln[i+k-1], ln[i+k]-1] and [vl,vr]
				long w2 = Math.max(Math.min(ln[i+k]-1, vr) - Math.max(ln[i+k-1], vl) + 1, 0);
				num += (long)w1 * w2;
			}
			if(k == 1 && vl <= ln[i] && ln[i] <= vr && pl <= ln[i] && ln[i] <= pr){
				num--;
			}
		}
		BigDecimal bnum = BigDecimal.valueOf(num);
		BigDecimal bden = BigDecimal.valueOf((long)(pr-pl+1)*(vr-vl+1));
		bnum = bnum.divide(bden, 15, RoundingMode.HALF_EVEN);
		
		out.printf("%.10f\n", bnum.doubleValue());
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