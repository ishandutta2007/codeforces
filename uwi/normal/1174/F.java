//package round563;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class F {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] from = new int[n - 1];
		int[] to = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			from[i] = ni() - 1;
			to[i] = ni() - 1;
		}
		int[][] g = packU(n, from, to);
		int[][] pars = parents3(g, 0);
		int[] par = pars[0], ord = pars[1], dep = pars[2];
//		int[][] spar = logstepParents(par);
		
		int cur = 0;
		int d0 = d(cur);
		if(d0 == 0){
			out.println("! " + (cur+1));
			out.flush();
			return;
		}
		
		boolean[] cans = new boolean[n];
		for(int i = 0;i < n;i++){
			if(dep[i] == d0){
				cans[i] = true;
			}
		}
		int[] des = new int[n];
		for(int i = n-1;i >= 0;i--){
			int c = ord[i];
			des[c] += cans[c] ? 1 : 0;
			if(c > 0)des[par[c]] += des[c];
		}
		
		while(true){
			int ncan = 0;
			int who = -1;
			for(int i = 0;i < n;i++){
				if(cans[i]){
					ncan++;
					who = i;
				}
			}
			if(ncan == 1){
				out.println("! " + (who+1));
				out.flush();
				return;
			}
			
			int max = 0;
			int arg = -1;
			while(true){
				max = 0;
				arg = -1;
				for(int e : g[cur]){
					if(par[cur] == e)continue;
					if(des[e] > max){
						max = des[e];
						arg = e;
					}
				}
				if(max == des[cur]){
					cur = arg;
				}else{
					break;
				}
			}
			int pos = arg;
			while(des[pos]*2 > des[cur]){
				max = 0;
				arg = -1;
				for(int e : g[pos]){
					if(par[pos] == e)continue;
					if(des[e] > max){
						max = des[e];
						arg = e;
					}
				}
				pos = arg;
			}
			// pos-cur
			if(dep[pos] - dep[cur] == 1){
				cur = s(cur);
				boolean[] rs = rs(cur, g, par[cur]);
				for(int i = 0;i < n;i++){
					cans[i] &= rs[i];
				}
			}else{
				int d = d(pos);
				if(d == 0){
					out.println("! " + (pos+1));
					out.flush();
					return;
				}
				int[] ds = ds(pos, g);
				for(int i = 0;i < n;i++){
					cans[i] &= ds[i] == d;
				}
			}
			
			des = new int[n];
			for(int i = n-1;i >= 0;i--){
				int c = ord[i];
				des[c] += cans[c] ? 1 : 0;
				if(c > 0)des[par[c]] += des[c];
			}
		}
	}
	
	boolean[] rs(int x, int[][] g, int px)
	{
		int n = g.length;
		boolean[] d = new boolean[n];
		d[x] = true;
		int[] q = new int[n];
		int p = 0;
		q[p++] = x;
		for(int r = 0;r < p;r++){
			int cur = q[r];
			for(int e : g[cur]){
				if(e != px && !d[e]){
					d[e] = true;
					q[p++] = e;
				}
			}
		}
		return d;
	}
	
	int[] ds(int x, int[][] g)
	{
		int n = g.length;
		int[] d = new int[n];
		Arrays.fill(d, 9999999);
		d[x] = 0;
		int[] q = new int[n];
		int p = 0;
		q[p++] = x;
		for(int r = 0;r < p;r++){
			int cur = q[r];
			for(int e : g[cur]){
				if(d[e] > d[cur] + 1){
					d[e] = d[cur] + 1;
					q[p++] = e;
				}
			}
		}
		return d;
	}
	
	int d(int x)
	{
		out.println("d " + (x+1));
		out.flush();
		return ni();
	}
	
	int s(int x)
	{
		out.println("s " + (x+1));
		out.flush();
		return ni()-1;
	}
	
	public static int lca2(int a, int b, int[][] spar, int[] depth) {
		if (depth[a] < depth[b]) {
			b = ancestor(b, depth[b] - depth[a], spar);
		} else if (depth[a] > depth[b]) {
			a = ancestor(a, depth[a] - depth[b], spar);
		}

		if (a == b)
			return a;
		int sa = a, sb = b;
		for (int low = 0, high = depth[a], t = Integer.highestOneBit(high), k = Integer
				.numberOfTrailingZeros(t); t > 0; t >>>= 1, k--) {
			if ((low ^ high) >= t) {
				if (spar[k][sa] != spar[k][sb]) {
					low |= t;
					sa = spar[k][sa];
					sb = spar[k][sb];
				} else {
					high = low | t - 1;
				}
			}
		}
		return spar[0][sa];
	}

	protected static int ancestor(int a, int m, int[][] spar) {
		for (int i = 0; m > 0 && a != -1; m >>>= 1, i++) {
			if ((m & 1) == 1)
				a = spar[i][a];
		}
		return a;
	}

	public static int[][] logstepParents(int[] par) {
		int n = par.length;
		int m = Integer.numberOfTrailingZeros(Integer.highestOneBit(n - 1)) + 1;
		int[][] pars = new int[m][n];
		pars[0] = par;
		for (int j = 1; j < m; j++) {
			for (int i = 0; i < n; i++) {
				pars[j][i] = pars[j - 1][i] == -1 ? -1 : pars[j - 1][pars[j - 1][i]];
			}
		}
		return pars;
	}


	public static int[][] parents3(int[][] g, int root) {
		int n = g.length;
		int[] par = new int[n];
		Arrays.fill(par, -1);

		int[] depth = new int[n];
		depth[0] = 0;

		int[] q = new int[n];
		q[0] = root;
		for (int p = 0, r = 1; p < r; p++) {
			int cur = q[p];
			for (int nex : g[cur]) {
				if (par[cur] != nex) {
					q[r++] = nex;
					par[nex] = cur;
					depth[nex] = depth[cur] + 1;
				}
			}
		}
		return new int[][] { par, q, depth };
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
		new F().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}