//package round69;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] k = new int[n];
		for(int i = 0;i < n;i++){
			k[i] = ni();
		}
		int[] from = new int[n-1];
		int[] to = new int[n-1];
		for(int i = 0;i < n-1;i++){
			from[i] = ni() - 1;
			to[i] = ni() - 1;
		}
		int s = ni() - 1;
		int[][] g = packU(n, from, to);
		
		int[] par = new int[n];
		par[s] = -1;
		depth = new int[n];
		final int[] fd = depth;
		rec(par, g, s, 0);
		
		Integer[] ord = new Integer[n];
		for(int i = 0;i < n;i++)
			ord[i] = i;
		Arrays.sort(ord, new Comparator<Integer>() {
			public int compare(Integer x, Integer y) {
				return -(fd[x] - fd[y]);
			}
		});
		
		long[] sc = new long[n];
		long[] lsc = new long[n];
		for(int o = 0;o < n;o++){
			int cur = ord[o];
			long lef = 0;
			int p = 0;
			for(int c : g[cur]){
				if(par[c] == cur && sc[c] >= 1){
					lsc[p++] = sc[c];
				}
				if(par[c] == cur)lef += k[c];
			}
			Arrays.sort(lsc, 0, p);
//			tr(cur, lsc, lef);
			long st = 0;
			for(int i = p-1;i >= 0 && k[cur] >= (cur == s ? 1 : 2) && lef >= 0;i--){
				st += lsc[i]+2;
				lef--;
				k[cur]--;
			}
			long plus = Math.min(k[cur]-(cur == s ? 0 : 1), lef);
			st += plus*2;
			k[cur] -= plus;
			sc[cur] = st;
		}
//		tr(par);
//		tr(k);
//		tr(sc);
		out.println(sc[s]);
	}
	
	int[] depth;
	
	void rec(int[] par, int[][] g, int cur, int dep)
	{
		depth[cur] = dep;
		for(int nex : g[cur]){
			if(nex != par[cur]){
				par[nex] = cur;
				rec(par, g, nex, dep+1);
			}
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
	
	void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new C().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}