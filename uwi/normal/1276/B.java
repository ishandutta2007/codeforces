//package round606;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		for(int T = ni();T > 0;T--){
			go();
		}
	}
	
	void go()
	{
		int n = ni(), m = ni();
		int a = ni()-1, b = ni()-1;
		int[] from = new int[m];
		int[] to = new int[m];
		int[] ws = new int[m];
		for (int i = 0; i < m; i++) {
			from[i] = ni() - 1;
			to[i] = ni() - 1;
			ws[i] = i;
		}
		int[][][] g = packWU(n, from, to, ws);
		BCDatum bcd = decomposeToBiconnectedComponents(g);
		
		int[][] bg = buildBlockCutTree(bcd);
		
		int u = bg.length;
		int[] ind = new int[n];
		Arrays.fill(ind, -1);
		int gen = bcd.ecp;
		for(int i = 0;i < n;i++){
			if(bcd.isArtic[i]){
				ind[i] = gen++;
			}
		}
		
		boolean[] done = new boolean[n];
		int[] cf = new int[n];
		for(int i = 0;i < m;i++){
//			tr(from[i], to[i], bcd.edgeClus[0]);
			if(!bcd.isArtic[from[i]] && !done[from[i]]){
				cf[bcd.edgeClus[i]]++;
				done[from[i]] = true;
			}
			if(!bcd.isArtic[to[i]] && !done[to[i]]){
				cf[bcd.edgeClus[i]]++;
				done[to[i]] = true;
			}
		}
		
		if(bcd.isArtic[a] && bcd.isArtic[b]){
			int[][] pars = parents3(bg, ind[a]);
			int[] par = pars[0], ord = pars[1], dep = pars[2];
			
			int[] des = new int[u];
			for(int i = u-1;i >= 0;i--){
				int cur = ord[i];
				if(cur < bcd.ecp){
					des[cur] += cf[cur];
				}else{
					des[cur]++;
				}
				if(i > 0)des[par[cur]] += des[cur];
			}
			
			int q = ind[b];
			for(;dep[q] > 1;q = par[q]);
			
			out.println((long)(des[ind[a]] - des[q] - 1) * (des[ind[b]]-1));
		}else{
			out.println(0);
		}
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

	
	public static int[][][] packWU(int n, int[] from, int[] to, int[] w) {
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for (int f : from)
			p[f]++;
		for (int t : to)
			p[t]++;
		for (int i = 0; i < n; i++)
			g[i] = new int[p[i]][2];
		for (int i = 0; i < from.length; i++) {
			--p[from[i]];
			g[from[i]][p[from[i]]][0] = to[i];
			g[from[i]][p[from[i]]][1] = w[i];
			--p[to[i]];
			g[to[i]][p[to[i]]][0] = from[i];
			g[to[i]][p[to[i]]][1] = w[i];
		}
		return g;
	}

	
	public static BCDatum decomposeToBiconnectedComponents(int[][][] g)
	{
		int n = g.length;
		int m = 0;
		for(int[][] row : g)m += row.length;
		m /= 2;
		BCDatum d = new BCDatum();
		d.g = g;
		d.gen = 0;
		d.low = new int[n];
		Arrays.fill(d.low, -1);
		d.ord = new int[n];
		Arrays.fill(d.ord, -1);
		d.edgeStack = new int[m];
		d.esp = 0;
		d.edgeClus = new int[m];
		Arrays.fill(d.edgeClus, -1);
		d.visited = new boolean[n];
		d.parente = new int[n];
		d.isArtic = new boolean[n];
		Arrays.fill(d.parente, -1);
		for(int i = 0;i < n;i++){
			if(!d.visited[i])dfsBC(i, d);
		}
		assert d.esp == 0;
		return d;
	}
	
	private static void dfsBC(int cur, BCDatum d)
	{
		d.visited[cur] = true;
		d.low[cur] = d.ord[cur] = d.gen++;
		int dfsch = 0;
		for(int[] e : d.g[cur]){
			if(!d.visited[e[0]]){
				d.edgeStack[d.esp++] = e[1];
				d.parente[e[0]] = e[1];
				dfsch++;
				dfsBC(e[0], d);
				if(d.low[e[0]] >= d.ord[cur]){
					d.isArtic[cur] = true;
					while(d.esp > 0){
						d.edgeClus[d.edgeStack[--d.esp]] = d.ecp;
						if(d.edgeStack[d.esp] == e[1])break;
					}
					d.ecp++;
				}
				d.low[cur] = Math.min(d.low[cur], d.low[e[0]]);
			}else if(d.parente[cur] != e[1] && d.ord[e[0]] < d.ord[cur]){
				// e is a back edge from cur to its ancestor e[0]
				d.edgeStack[d.esp++] = e[1];
				d.low[cur] = Math.min(d.low[cur], d.ord[e[0]]);
			}
		}
		if(d.parente[cur] < 0 && dfsch == 1)d.isArtic[cur] = false; // if root node and degree on dfs tree = 1 then not articulation point.
	}
	
	public static class BCDatum
	{
		public int[][][] g;
		public int[] edgeClus;
		public int ecp;
		public int gen;
		public int[] ord;
		public int[] low;
		public int[] edgeStack;
		public int esp;
		public boolean[] visited;
		public int[] parente;
		public boolean[] isArtic;
	}
	
	public static int[][] buildBlockCutTree(BCDatum dat)
	{
		int n = dat.g.length;
		int m = dat.ecp;
		int[] artics = new int[n];
		Arrays.fill(artics, -1);
		int q = 0;
		for(int i = 0;i < n;i++){
			if(dat.isArtic[i]){
				artics[i] = q++;
			}
		}
		int ne = 0;
		for(int i = 0;i < n;i++){
			ne = Math.max(dat.g[i].length, ne);
		}
		
		int[] from = new int[q+m-1];
		int[] to = new int[q+m-1];
		// m+q
		int p = 0;
		int[] temp = new int[ne];
		for(int i = 0;i < n;i++){
			if(dat.isArtic[i]){
				int lp = 0;
				for(int[] e : dat.g[i]){
					temp[lp++] = dat.edgeClus[e[1]];
				}
				assert lp >= 2;
				Arrays.sort(temp, 0, lp);
				for(int j = 0;j < lp;j++){
					if(j == 0 || temp[j] != temp[j-1]){
						from[p] = m+artics[i]; to[p] = temp[j]; p++;
					}
				}
			}
		}
		assert p == from.length;
		return packU(q+m, from, to);
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
	
	public static void main(String[] args) throws Exception { new B().run(); }
	
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