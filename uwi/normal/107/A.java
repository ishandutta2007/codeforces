//package round83;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Comparator;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "5 3 1 2 10 2 3 20 5 4 5";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		int[] w = new int[m];
		DisjointSet ds = new DisjointSet(n);
		BitSet froms = new BitSet();
		BitSet tos = new BitSet();
		for(int i = 0;i < m;i++){
			from[i] = ni() - 1;
			to[i] = ni() - 1;
			w[i] = ni();
			froms.set(from[i]);
			tos.set(to[i]);
			ds.union(from[i], to[i]);
		}
		
		int[][][] g = packWD(n, from, to, w);
		int[][] cc = new int[n][3];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < 2;j++){
				cc[i][j] = -1;
			}
			cc[i][2] = 9999999;
		}
		for(int i = froms.nextClearBit(0);i < n;i = froms.nextClearBit(i + 1)){
			cc[ds.root(i)][0] = i;
		}
		for(int i = tos.nextClearBit(0);i < n;i = tos.nextClearBit(i + 1)){
			cc[ds.root(i)][1] = i;
		}
		
		for(int i = 0;i < n;i++){
			if(g[i].length > 0){
				int ind = ds.root(i);
				cc[ind][2] = Math.min(cc[ind][2], g[i][0][1]);
			}
		}
		
		Arrays.sort(cc, new Comparator<int[]>(){
			public int compare(int[] a, int[] b)
			{
				return a[1] - b[1];
			}
		});
		
		int ct = 0;
		for(int i = 0;i < n;i++){
			if(cc[i][0] != -1 && cc[i][0] != cc[i][1]){
				ct++;
			}
		}
		out.println(ct);
		for(int i = 0;i < n;i++){
			if(cc[i][0] != -1 && cc[i][0] != cc[i][1]){
				out.printf("%d %d %d\n", cc[i][1]+1, cc[i][0]+1, cc[i][2]);
			}
		}
	}
	
	public static int[][][] packWD(int n, int[] from, int[] to, int[] w)
	{
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for(int f : from)p[f]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]][2];
		for(int i = 0;i < from.length;i++){
			--p[from[i]];
			g[from[i]][p[from[i]]][0] = to[i];
			g[from[i]][p[from[i]]][1] = w[i];
		}
		return g;
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
		new A().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}