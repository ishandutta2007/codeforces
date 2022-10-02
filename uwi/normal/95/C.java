//package round77;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;
import java.util.TreeSet;

public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		int start = ni() - 1;
		int goal = ni() - 1;
		int[] from = new int[m];
		int[] to = new int[m];
		int[] w = new int[m];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
			w[i] = ni();
		}
		int[][] g = packWU(n, from, to, w);
		int[][] taxi = new int[n][2];
		for(int i = 0;i < n;i++){
			taxi[i][0] = ni();
			taxi[i][1] = ni();
		}
		
		int[][] tg = new int[n][n];
		
		for(int i = 0;i < n;i++){
			final long[] td = new long[n];
			Arrays.fill(td, Long.MAX_VALUE / 3);
			TreeSet<Integer> q = new TreeSet<Integer>(new Comparator<Integer>() {
				public int compare(Integer a, Integer b) {
					if(td[a] - td[b] != 0)
						return Long.signum(td[a] - td[b]);
					return a - b;
				}
			});
			q.add(i);
			td[i] = 0;

			while (q.size() > 0){
				int cur = q.pollFirst();

				for(int j = 0;j < g[cur].length;j += 2){
					int next = g[cur][j];
					long nd = td[cur] + g[cur][j + 1];
					if(nd < td[next] && nd <= taxi[i][0]){
						q.remove(next);
						td[next] = nd;
						q.add(next);
					}
				}
			}
			
			for(int j = 0;j < n;j++){
				if(td[j] <= taxi[i][0]){
					tg[i][j] = taxi[i][1];
				}else{
					tg[i][j] = Integer.MAX_VALUE;
				}
			}
			tg[i][i] = 0;
		}
		
		{
			final long[] td = new long[n];
			Arrays.fill(td, Long.MAX_VALUE / 3);
			TreeSet<Integer> q = new TreeSet<Integer>(new Comparator<Integer>() {
				public int compare(Integer a, Integer b) {
					if(td[a] - td[b] != 0)
						return Long.signum(td[a] - td[b]);
					return a - b;
				}
			});
			q.add(start);
			td[start] = 0;

			while (q.size() > 0){
				int cur = q.pollFirst();
				if(cur == goal){
					out.println(td[goal]);
					return;
				}

				for(int j = 0;j < n;j++){
					int next = j;
					if(tg[cur][j] < Integer.MAX_VALUE){
						long nd = td[cur] + tg[cur][j];
						if(nd < td[next]){
							q.remove(next);
							td[next] = nd;
							q.add(next);
						}
					}
				}
			}
			
			out.println(-1);
		}
		
	}
	
	static int[][] packWU(int n, int[] from, int[] to, int[] w)
	{
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int f : from)p[f]+=2;
		for(int t : to)p[t]+=2;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]];
		for(int i = 0;i < from.length;i++){
			g[from[i]][--p[from[i]]] = w[i];
			g[from[i]][--p[from[i]]] = to[i];
			g[to[i]][--p[to[i]]] = w[i];
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
		new C().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}