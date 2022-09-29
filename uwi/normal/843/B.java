//package aim.r4;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;
import java.util.SplittableRandom;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	int[] get(int ind)
	{
		out.println("? " + (ind+1));
		out.flush();
		return new int[]{ni(), ni()-1};
	}
	
	void solve()
	{
		int n = ni(), s = ni()-1, x = ni();
		SplittableRandom gen = new SplittableRandom();
		int best = s;
		int[] g = get(s);
		int bestval = g[0];
		int bnext = g[1];
		if(x <= bestval){
			out.println("! " + bestval);
			out.flush();
			return;
		}
		BitSet ved = new BitSet();
		ved.set(best);
		for(int i = 0;i < 990 && i < n-1;i++){
			while(true){
				int id = gen.nextInt(n);
				if(!ved.get(id)){
					int[] t = get(id);
					ved.set(id);
					if(t[0] <= x && bestval < t[0]){
						bestval = t[0];
						best = id;
						bnext = t[1];
					}
					break;
				}
			}
		}
		while(bestval < x){
			if(best < 0){
				out.println("! -1");
				out.flush();
				return;
			}
			int[] t = get(best);
			best = t[1];
			bestval = t[0];
		}
		out.println("! " + bestval);
		out.flush();
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