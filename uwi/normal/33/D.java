//package round33;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class D {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "2 1 2 0 0 3 3 2 0 0 1 2 2 1";
//	private String INPUT = "2 3 1 0 0 4 4 1 0 0 2 0 0 3 0 0 1 1";
	private String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		int m = ni();
		int k = ni();
		BitSet[] inc = new BitSet[n];
		int[] r = new int[m];
		int[] cx = new int[m];
		int[] cy = new int[m];
		
		int[] kx = new int[n];
		int[] ky = new int[n];
		for(int i = 0;i < n;i++){
			kx[i] = ni();
			ky[i] = ni();
		}
		for(int i = 0;i < m;i++){
			r[i] = ni();
			cx[i] = ni();
			cy[i] = ni();
		}
		
		for(int i = 0;i < n;i++){
			inc[i] = makeBS(r, cx, cy, kx[i], ky[i]);
		}
		
		BitSet base = new BitSet();
		for(int i = 0;i < k;i++){
			int a = ni() - 1;
			int b = ni() - 1;
			base.clear();
			base.or(inc[a]);
			base.xor(inc[b]);
			out.println(base.cardinality());
		}
	}
	
	public BitSet makeBS(int[] r, int[] cx, int[] cy, int x, int y)
	{
		int m = r.length;
		BitSet bs = new BitSet(m);
		for(int i = 0;i < m;i++){
			if(
			(long)(x - cx[i]) * (long)(x - cx[i]) +
			(long)(y - cy[i]) * (long)(y - cy[i]) < (long)r[i] * (long)r[i]){
				bs.set(i);
			}
		}
		return bs;
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
		new D().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}