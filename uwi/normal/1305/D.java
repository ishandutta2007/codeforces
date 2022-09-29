//package round2020;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.Scanner;

public class D {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] from = new int[n-1];
		int[] to = new int[n-1];
		for(int i = 0;i < n-1;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
		}
		
		int[] label = new int[n];
		for(int i =0;i < n;i++)label[i] = i+1;
		int[][] g = packU(n, from, to);
		
		while(n > 1){
			int[] d0 = ds(0, g);
			int r0 = 0;
			for(int i = 0;i < n;i++){
				if(d0[i] > d0[r0])r0 = i;
			}
			int[] dr0 = ds(r0, g);
			int r1 = 0;
			for(int i = 0;i < n;i++){
				if(dr0[i] > dr0[r1])r1 = i;
			}
			int[] dr1 = ds(r1, g);
			
			out.println("? " + label[r0] + " " + label[r1]);
			out.flush();
			int lca = ni();
			
			for(int i = 0;i < n;i++){
				if(label[i] == lca){
					lca = i;
					break;
				}
			}
			boolean[] alive = new boolean[n];
			Arrays.fill(alive, true);
			for(int e : g[lca]){
				if(dr0[e] < dr0[lca]){
					dfs(e, lca, g, alive);
				}
				if(dr1[e] < dr1[lca]){
					dfs(e, lca, g, alive);
				}
			}
//			tr(dr0, dr1);
//			tr(alive);
			FilterResult fr = filter(alive, g);
			int nn = fr.fg.length;
			int[] nlabel = new int[nn];
			for(int i = 0;i < n;i++){
				if(fr.map[i] == -1)continue;
				nlabel[fr.map[i]] = label[i];
			}
			
			g = fr.fg;
			n = nn;
			label = nlabel;
		}
		
		out.println("! " + label[0]);
		out.flush();
	}
	
	public static FilterResult filter(boolean[] f, int[][] g)
	{
		int n = g.length;
		int[] map = new int[n];
		Arrays.fill(map, -1);
		int p = 0;
		for(int i = 0;i < n;i++){
			if(f[i])map[i] = p++;
		}
		int[][] h = new int[p][];
		int[] temp = new int[p];
		for(int i = 0;i < n;i++){
			if(f[i]){
				int q = 0;
				for(int e : g[i]){
					if(f[e])temp[q++] = map[e];
				}
				h[map[i]] = Arrays.copyOf(temp, q);
			}
		}
		FilterResult ret = new FilterResult();
		ret.map = map;
		ret.fg = h;
		return ret;
	}
	
	public static class FilterResult
	{
		int[][] fg; // filtered graph
		int[] map; // original graph -> filtered graph
	}

	
	void dfs(int cur, int pre, int[][] g, boolean[] alive)
	{
		alive[cur] = false;
		for(int e : g[cur]){
			if(e == pre)continue;
			dfs(e, cur, g, alive);
		}
	}
	
	int[] ds(int from, int[][] g)
	{
		int n = g.length;
		int[] d = new int[n];
		Arrays.fill(d, 999999999);
		d[from] = 0;
		Queue<Integer> q = new ArrayDeque<>();
		q.add(from);
		while(!q.isEmpty()){
			int cur = q.poll();
			for(int e : g[cur]){
				if(d[e] > d[cur] + 1){
					d[e] = d[cur] + 1;
					q.add(e);
				}
			}
		}
		return d;
	}
	
	static int[][] packU(int n, int[] from, int[] to) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for (int f : from)
			p[f]++;
		for (int t : to)
			p[t]++;
		for (int i = 0; i < n; i++)
			g[i] = new int[p[i]];
		for (int i = 0; i < from.length; i++) {
			g[from[i]][--p[from[i]]] = to[i];
			g[to[i]][--p[to[i]]] = from[i];
		}
		return g;
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
		new D().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}