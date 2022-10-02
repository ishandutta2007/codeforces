//package bayan2014.warmup;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
		}
		int[][] g = packU(n, from, to);
		
		int[] clus = decomposeToBC(g);
		int[][] cg = collect(g, clus);
		
		int u = cg.length;
		int[] w = new int[u];
		for(int i = 0;i < n;i++){
			w[clus[i]]++;
		}
		
		long ret = 0;
		int[][] pars = parents3(cg, 0);
		int[] par = pars[0], ord = pars[1];
		int[] des = new int[u];
		for(int i = u-1;i >= 0;i--){
			int cur = ord[i];
			des[cur] += w[cur];
			if(i > 0)des[par[cur]] += des[cur];
		}
		for(int i = u-1;i >= 0;i--){
			int cur = ord[i];
			int maxdes = n-des[cur];
			for(int e : cg[cur]){
				if(par[cur] != e){
					maxdes = Math.max(maxdes, des[e]);
				}
			}
			if(maxdes <= n/2){
				ret = Math.max(ret, go(cur, cg, w, n));
			}
		}
		out.println(ret);
	}
	
	long go(int root, int[][] cg, int[] w, int n)
	{
		int u = cg.length;
		int[][] pars = parents3(cg, root);
		int[] par = pars[0], ord = pars[1];
		int[] des = new int[u];
		for(int i = u-1;i >= 0;i--){
			int cur = ord[i];
			des[cur] += w[cur];
			if(i > 0)des[par[cur]] += des[cur];
		}
		
		int[] dess = new int[cg[root].length];
		int p = 0;
		for(int e : cg[root]){
			dess[p++] = des[e];
		}
		Arrays.sort(dess);
		
		int U = (n-w[root])/2;
		int V = (U>>>6)+1;
		long[] dp = new long[V];
		dp[0] = 1;
		for(int i = 0;i < p;){
			int j = i;
			for(;j < p && dess[j] == dess[i];j++);
			int count = j-i;
			for(int d = 1;count > 0;d<<=1){
				int e = Math.min(d, count);
				count -= e;
				int leap = e*dess[i];
				for(int k = V-1-(leap>>>6);k >= 0;k--){
					if((leap&63) != 0 && k+(leap>>>6)+1 < V)dp[k+(leap>>>6)+1] |= dp[k]>>>-leap;
					dp[k+(leap>>>6)] |= dp[k]<<leap;
				}
			}
			
			i = j;
		}
		
		long lret = 0;
		for(int i = 0;i < u;i++){
			lret += (long)w[i]*w[i];
			if(i != root){
				lret += (long)(des[i]-w[i])*w[i];
			}
		}
		
		lret += (long)w[root] * (n-w[root]); // from or to root
		dp[V-1] &= (1L<<U+1)-1;
		for(int i = V-1;i >= 0;i--){
			if(dp[i] != 0){
				int x = 63-Long.numberOfLeadingZeros(dp[i])+(i<<6);
				lret += (long)x * (n-w[root]-x);
				break;
			}
		}
		return lret;
	}
	
	public static String tobs(long x, int d)
	{
		char[] ret = new char[d];
		for(int i = 0;i < d;i++)ret[i] = (char)('0'+(x>>>i&1));
		return new String(ret);
	}
	
	static int[][] collect(int[][] g, int[] scc)
	{
		int n = g.length;
		int m = 0;
		for(int i = 0;i < n;i++)m = Math.max(m, scc[i]);
		m++;
		
		int[] cp = new int[m];
		for(int i = 0;i < n;i++){
			cp[scc[i]] += g[i].length;
		}
		int[][] c = new int[m][];
		for(int i = 0;i < m;i++){
			c[i] = new int[cp[i]];
		}
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < g[i].length;j++){
				c[scc[i]][--cp[scc[i]]] = scc[g[i][j]];
			}
		}
		
		for(int i = 0;i < m;i++){
			Arrays.sort(c[i]);
			int jp = 0;
			for(int j = 0;j < c[i].length;j++){
				if((j == 0 || c[i][j] != c[i][j-1]) && c[i][j] != i){
					c[i][jp++] = c[i][j];
				}
			}
			c[i] = Arrays.copyOf(c[i], jp);
		}
		return c;
	}
	
	public int[] decomposeToBC(int[][] g)
	{
		int n = g.length;
		boolean[] visited = new boolean[n];
		int[] ord = new int[n];
		int[] low = new int[n];
		
		int[] ids = new int[n];
		int[] inds = new int[n];
		int[] parct = new int[n];
		int pos = 0;
		for(int i = 0;i < n;i++){
			if(!visited[i]){
				ids[0] = i;
				inds[0] = 0;
				int sp = 1;
				while(sp > 0){
					int cur = ids[sp-1];
					if(inds[sp-1] == 0){
						visited[cur] = true;
						ord[cur] = low[cur] = pos++;
						parct[sp-1] = 0;
					}
					if(inds[sp-1] == g[cur].length){
						if(sp-2 >= 0)low[ids[sp-2]] = Math.min(low[ids[sp-2]], low[cur]);
						sp--;
						continue;
					}
					int next = g[cur][inds[sp-1]];
					if(!visited[next]){
						ids[sp] = next;
						inds[sp] = 0;
						inds[sp-1]++;
						sp++;
						continue;
					}else if(sp-2 >= 0 && (next != ids[sp-2] || ++parct[sp-1] >= 2)){
						low[cur] = Math.min(low[cur], ord[next]);
					}
					inds[sp-1]++;
				}
			}
		}
		
		int[] clus = new int[n];
		Arrays.fill(clus, -1);
		int[] q = new int[n];
		int cnum = 0;
		for(int i = 0;i < n;i++){
			if(clus[i] == -1){
				int p = 0;
				q[p++] = i;
				clus[i] = cnum++;
				for(int r = 0;r < p;r++){
					int cur = q[r];
					for(int next : g[cur]){
						if(clus[next] == -1){
							clus[next] = ord[cur] < low[next] ? cnum++ : clus[cur];
							q[p++] = next;
						}
					}
				}
			}
		}
		return clus;
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
	
	public static void main(String[] args) throws Exception { new E2().run(); }
	
	private byte[] inbuf = new byte[1024];
	private int lenbuf = 0, ptrbuf = 0;
	
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