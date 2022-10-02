//package round73;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Comparator;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class D2 {
	Scanner in;
	PrintWriter out;
//	String INPUT = "2 2 1 5";
//	String INPUT = "6\r\n" +
//			"1 2 2\r\n" +
//			"1 3 2\r\n" +
//			"3 4 2\r\n" +
//			"3 5 2\r\n" +
//			"3 6 2";
	String INPUT = "10\r\n" +
			"6 3 59\r\n" +
			"1 3 85\r\n" +
			"5 1 3\r\n" +
			"7 1 59\r\n" +
			"2 1 59\r\n" +
			"5 4 59\r\n" +
			"9 7 59\r\n" +
			"1 10 59\r\n" +
			"8 3 3";
	
	long max = 0;
	BitSet maxs = new BitSet();
	
	void solve()
	{
		int n = ni();
		int[][] e = new int[n-1][4]; // [from][to][weight][ind]
		for(int i = 0;i < n-1;i++){
			e[i][0] = ni() - 1;
			e[i][1] = ni() - 1;
			e[i][2] = ni();
			e[i][3] = i + 1;
		}
		Arrays.sort(e, new Comparator<int[]>() {
			public int compare(int[] x, int[] y) {
				return x[2] - y[2];
			}
		});
		
		DisjointSet ds = new DisjointSet(n);
		for(int i = 0;i < n-1;){
			int j;
			for(j = i+1;j < n-1 && e[i][2] == e[j][2];j++);
			// [i,j)weight
			// 
			int m = j-i;
			
			TreeMap<Integer, Integer> vmap = new TreeMap<Integer, Integer>();
			int[] F = new int[m]; // [cluster edge]
			int[] T = new int[m]; // [cluster edge]
			for(int k = i;k < j;k++){
				vmap.put(F[k-i] = ds.root(e[k][0]), 0);
				vmap.put(T[k-i] = ds.root(e[k][1]), 0);
			}
			int z = vmap.size(); // num of clusters
			
			int[] ivmap = new int[z];
			int u = 0;
			for(Map.Entry<Integer, Integer> en : vmap.entrySet()){
				en.setValue(u);
				ivmap[u] = en.getKey();
				u++;
			}
			for(int k = i;k < j;k++){
				F[k-i] = vmap.get(F[k-i]);
				T[k-i] = vmap.get(T[k-i]);
			}
			int[][] g = packU(z, F, T);
			
			int[] sums = new int[z];
			int[] alls = new int[z];
			Arrays.fill(sums, -1);
			for(int k = 0;k < z;k++){
				if(sums[k] == -1){
					int all = dfs(ivmap, g, ds, sums, k, -1);
					dfs2(g, alls, all, k, -1);
				}
			}
			
			for(int k = i;k < j;k++){
				long one = Math.min(sums[F[k-i]], sums[T[k-i]]);
				long other = alls[F[k-i]] - one;
				if(max < one * other){
					max = one * other;
					maxs.clear();
				}
				if(max == one * other){
					maxs.set(e[k][3]);
				}
			}
			
			for(int k = i;k < j;k++){
				ds.union(e[k][0], e[k][1]);
			}
			
			i = j;
		}
		
		out.println(max*2 + " " + maxs.cardinality());
		for(int i = maxs.nextSetBit(0);i != -1;i = maxs.nextSetBit(i + 1)){
			out.println(i);
		}
	}
	
	
	static int[][] packU(int n, int[] from, int[] to)
	{
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int f : from)p[f]++;
		for(int t : to)p[t]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]];
		for(int i = 0;i < from.length;i++){
			g[from[i]][--p[from[i]]] = to[i];
			g[to[i]][--p[to[i]]] = from[i];
		}
		return g;
	}
	
	int dfs(int[] ivmap, int[][] g, DisjointSet ds, int[] sums, int cur, int from)
	{
		int sum = -ds.upper[ivmap[cur]];
		for(int t : g[cur]){
			if(t != from){
				sum += dfs(ivmap, g, ds, sums, t, cur);
			}
		}
		return sums[cur] = sum;
	}
	
	void dfs2(int[][] g, int[] alls, int all, int cur, int from)
	{
		alls[cur] = all;
		for(int t : g[cur]){
			if(t != from){
				dfs2(g, alls, all, t, cur);
			}
		}
	}
	
	public static class DisjointSet {
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
		
		public boolean areInSameSet(int x, int y)
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
		new D2().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}