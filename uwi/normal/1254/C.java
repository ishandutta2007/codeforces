//package round601;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	long S(int a, int b, int c)
	{
		out.println("1 " + (a+1) + " " + (b+1) + " " + (c+1));
		out.flush();
		return nl();
	}
	
	int cp(int a, int b, int c)
	{
		out.println("2 " + ++a + " " + ++b + " " + ++c);
		out.flush();
		return ni();
	}
	
	void solve()
	{
		int n = ni();
		int[] upper = new int[n];
		int[] lower = new int[n];
		int up = 0, lp = 0;
		for(int i = 2;i < n;i++){
			if(cp(0, 1, i) == 1){
				upper[up++] = i;
			}else{
				lower[lp++] = i;
			}
		}
		int[] upp = go(Arrays.copyOf(upper, up), 1, 0);
		int[] lpp = go(Arrays.copyOf(lower, lp), 0, 1);
		out.print("0 ");
		out.print("1 ");
		for(int v : lpp){
			out.print(++v + " ");
		}
		out.print("2 ");
		for(int v : upp){
			out.print(++v + " ");
		}
		out.println();
		out.flush();
	}
	
	//   ***
	// r     l
	int[] go(int[] set, int l, int r)
	{
		int n = set.length;
		if(n == 0)return new int[0];
		long[] ss = new long[n];
		int arg = 0;
		for(int i = 0;i < n;i++){
			ss[i] = S(l, r, set[i]);
			if(ss[i] > ss[arg]){
				arg = i;
			}
		}
		
		int[] upper = new int[n];
		int[] lower = new int[n];
		int up = 0, lp = 0;
		for(int i = 0;i < n;i++){
			if(i == arg)continue;
			if(cp(r, set[arg], set[i]) == 1){
				upper[up++] = i;
			}else{
				lower[lp++] = i;
			}
		}
		long[][] hi = new long[up][];
		for(int i = 0;i < up;i++){
			hi[i] = new long[]{ss[upper[i]], set[upper[i]]};
		}
		Arrays.sort(hi, new Comparator<long[]>() {
			public int compare(long[] a, long[] b) {
				return Long.compare(a[0], b[0]);
			}
		});
		long[][] li = new long[lp][];
		for(int i = 0;i < lp;i++){
			li[i] = new long[]{ss[lower[i]], set[lower[i]]};
		}
		Arrays.sort(li, new Comparator<long[]>() {
			public int compare(long[] a, long[] b) {
				return Long.compare(a[0], b[0]);
			}
		});
		int[] ret = new int[n];
		int rp = 0;
		for(int i = 0;i < lp;i++){
			ret[rp++] = (int)li[i][1];
		}
		ret[rp++] = set[arg];
		for(int i = up-1;i >= 0;i--){
			ret[rp++] = (int)hi[i][1];
		}
		assert rp == ret.length;
		return ret;
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