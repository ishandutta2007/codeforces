//package yandex2011.q2;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Queue;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		final int[] pr = new int[n];
		for(int i = 0;i < n;i++)pr[i] = ni();
		int[] from = new int[n-1];
		int[] to = new int[n-1];
		int[] cap = new int[n-1];
		for(int i = 0;i < n-1;i++){
			from[i] = ni() - 1;
			to[i] = ni() - 1;
			cap[i] = ni();
		}
		int[][] wg = packWU(n, from, to, cap);
		int[][] g = packU(n, from, to);
		int[] par = parents(g, 0);
		int[] wn = new int[n];
		for(int i = 1;i < n;i++){
			for(int j = 0;j < wg[i].length;j+=2){
				if(wg[i][j] == par[i]){
					wn[i] = wg[i][j+1];
					break;
				}
			}
		}
		
		Integer[] ord = new Integer[n];
		for(int i = 0;i < n;i++)
			ord[i] = i;
		Arrays.sort(ord, new Comparator<Integer>() {
			public int compare(Integer x, Integer y) {
				return pr[x] - pr[y];
			}
		});
		
		int[] days = new int[n];
		int[][] ride = new int[n][n]; // city, days
		for(int i = 0;i < n;i++){
			int d = 0;
			for(int c = ord[i];c != 0;c = par[c], d++){
				while(ride[c][d] == wn[c]){
					d++;
				}
				ride[c][d]++;
			}
			days[ord[i]] = d;
		}
		
		for(int i = 0;i < n;i++){
			out.print(days[i] + " ");
		}
		out.println();
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
	
	public static int[] parents(int[][] g, int root)
	{
		int n = g.length;
		int[] par = new int[n];
		Arrays.fill(par, -1);
		
		Queue<Integer> q = new ArrayDeque<Integer>();
		q.add(root);
		while(q.size() > 0){
			int cur = q.poll();
			for(int nex : g[cur]){
				if(par[cur] != nex){
					q.add(nex);
					par[nex] = cur;
				}
			}
		}
		return par;
	}
	
	void run() throws Exception
	{
//		int n = 5000;
//		StringBuilder sb = new StringBuilder(n + " ");
//		Random r = new Random();
//		for(int i = 0;i < n;i++){
//			sb.append(r.nextInt(10000000) + " ");
//		}
//		for(int i = 0;i < n-1;i++){
//			sb.append((i+1) + " " + (i+2) + " 1 ");
//		}
//		INPUT = sb.toString();
		
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