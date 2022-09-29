//package round566;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Queue;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		if(n <= 2) {
			out.println(1);
			return;
		}
		int[] from = new int[n - 1];
		int[] to = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			from[i] = ni() - 1;
			to[i] = ni() - 1;
		}
		int[][] g = packU(n, from, to);
		int[][] pars = parents3(g, 0);
		int[] par = pars[0], ord = pars[1], dep = pars[2];
		
		int[] ls = new int[n];
		int p = 0;
		for(int i = 0;i < n;i++) {
			if(g[i].length == 1) {
				ls[p++] = i;
			}
		}
		if(p <= 2) {
			for(int i = 0;i < n;i++) {
				if(g[i].length == 1) {
					out.println(i+1);
					break;
				}
			}
		}else if(go(g, par, ls, dep)) {
		}else {
			int[] diam = diameter(g);
			if(search(diam[1], g))return;
			if(search(diam[2], g))return;
			if(diam[0] % 2 == 0) {
				int[][] spar = logstepParents(par);
				int anc = ancestor(dep[diam[1]] > dep[diam[2]] ? diam[1] : diam[2], diam[0]/2, spar);
				if(search(anc, g))return;
				
				Queue<Integer> q = new ArrayDeque<>();
				q.add(anc);
				int[] ds = new int[n];
				Arrays.fill(ds, Integer.MAX_VALUE);
				ds[anc] = 0;
				
				int[][] degs = new int[2][n+1];
				int[][] which = new int[2][n+1];
				Arrays.fill(degs[0], -1);
				Arrays.fill(degs[1], -1);
				while(!q.isEmpty()) {
					int cur = q.poll();
					if(degs[0][ds[cur]] == -1) {
						degs[0][ds[cur]] = g[cur].length;
						which[0][ds[cur]] = cur;
					}else if(degs[0][ds[cur]] != g[cur].length) {
						degs[1][ds[cur]] = g[cur].length;
						which[1][ds[cur]] = cur;
					}
					for(int e : g[cur]) {
						if(ds[e] > ds[cur] + 1) {
							ds[e] = ds[cur] + 1;
							q.add(e);
						}
					}
				}
				
				int[] mids = new int[0];
				for(int i = 0;i < n;i++) {
					if(degs[1][i] != -1) {
						mids = new int[] {which[0][i], which[1][i]};
						break;
					}
				}
				
				for(int mid : mids) {
					for(int i = 0;i < n;i++) {
						if(g[i].length == 1) {
							if(d(anc, i, spar, dep) == d(anc, mid, spar, dep) + d(mid, i, spar, dep)) {
								if(search(i, g))return;
								break;
							}
						}
					}
				}
			}
			out.println(-1);
		}
	}
	
	int d(int a, int b, int[][] spar, int[] dep)
	{
		int lca = lca2(a, b, spar, dep);
		return dep[a] + dep[b] - 2*dep[lca];
	}
	
	public static int[] diameter(int[][] g)
	{
		int n = g.length;
		int f0 = -1, f1 = -1, d01 = -1;
		int[] q = new int[n];
		boolean[] ved = new boolean[n];
		{
			int qp = 0;
			q[qp++] = 0; ved[0] = true;
			for(int i = 0;i < qp;i++){
				int cur = q[i];
				for(int e : g[cur]){
					if(!ved[e]){
						ved[e] = true;
						q[qp++] = e;
						continue;
					}
				}
			}
			f0 = q[n-1];
		}
		{
			int[] d = new int[n];
			int qp = 0;
			Arrays.fill(ved, false);
			q[qp++] = f0; ved[f0] = true;
			for(int i = 0;i < qp;i++){
				int cur = q[i];
				for(int e : g[cur]){
					if(!ved[e]){
						ved[e] = true;
						q[qp++] = e;
						d[e] = d[cur] + 1;
						continue;
					}
				}
			}
			f1 = q[n-1];
			d01 = d[f1];
		}
		return new int[]{d01, f0, f1};
	}


	boolean go(int[][] g ,int[] par, int[] ls, int[] dep)
	{
		int n = g.length;
		int[][] spar = logstepParents(par);
		int dsum = 0;
		for(int i = 0;i < 3;i++) {
			for(int j = i+1;j < 3;j++) {
				int lca = lca2(ls[i], ls[j], spar, dep);
				dsum += dep[ls[i]] + dep[ls[j]] - dep[lca] * 2;
			}
		}
		assert dsum % 2 == 0;
		dsum /= 2;
		if(dsum % 3 == 0) {
			int u = dsum / 3;
			int am = 0;
			for(int i = 0;i < 3;i++) {
				if(dep[ls[i]] >= dep[ls[am]]) {
					am = i;
				}
			}
			int center = ancestor(ls[am], u, spar);
			if(center >= 0) {
				return search(center, g);
			}
		}
		return false;
	}
	
	boolean search(int center, int[][] g)
	{
		int n = g.length;
		Queue<Integer> q = new ArrayDeque<>();
		q.add(center);
		int[] ds = new int[n];
		Arrays.fill(ds, Integer.MAX_VALUE);
		ds[center] = 0;
		
		int[] degs = new int[n+1];
		Arrays.fill(degs, -1);
		while(!q.isEmpty()) {
			int cur = q.poll();
			if(degs[ds[cur]] == -1) {
				degs[ds[cur]] = g[cur].length;
			}else {
				if(degs[ds[cur]] != g[cur].length) {
					return false;
				}
			}
			for(int e : g[cur]) {
				if(ds[e] > ds[cur] + 1) {
					ds[e] = ds[cur] + 1;
					q.add(e);
				}
			}
		}
//		out.println("find");
		out.println(center+1);
		return true;
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
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
	private byte[] inbuf = new byte[1024];
	public int lenbuf = 0, ptrbuf = 0;
	
	private int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
	
	private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
	private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
	
	private double nd() { return Double.parseDouble(ns()); }
	private char nc() { return (char)skip(); }
	
	private String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	private char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
	
	private char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}
	
	private int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}
	
	private int ni()
	{
		int num = 0, b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private long nl()
	{
		long num = 0;
		int b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}