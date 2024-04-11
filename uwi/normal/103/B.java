//package round80;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "6 6\r\n" +
			"6 3\r\n" +
			"6 4\r\n" +
			"5 1\r\n" +
			"2 5\r\n" +
			"1 4\r\n" +
			"5 4";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		if(n != m){
			out.println("NO");
			return;
		}
		DisjointSet ds = new DisjointSet(m);
		for(int i = 0;i < m;i++){
			ds.union(ni()-1, ni()-1);
		}
		if(ds.count() == 1){
			out.println("FHTAGN!");
		}else{
			out.println("NO");
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
	
	public class DisjointSet {
		public int[] upper; // minus:num_element(root) plus:root(normal)
		
		public DisjointSet(int n)
		{
			upper = new int[n];
			Arrays.fill(upper, -1);
		}
		
		public int root(int x)
		{
			return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
		}
		
		public boolean equiv(int x, int y)
		{
			return root(x) == root(y);
		}
		
		public void union(int x, int y)
		{
			x = root(x);
			y = root(y);
			if(x != y) {
				if(upper[y] < upper[x]) {
					int d = x; x = y; y = d;
				}
				upper[x] += upper[y];
				upper[y] = x;
			}
		}
		
		public int count()
		{
			int ct = 0;
			for(int i = 0;i < upper.length;i++){
				if(upper[i] < 0)ct++;
			}
			return ct;
		}
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