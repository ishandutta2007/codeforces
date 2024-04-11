//package round310;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), Q = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		DJSet ds = new DJSet(n);
		for (int i = 0; i < m; i++) {
			from[i] = ni() - 1;
			to[i] = ni() - 1;
			ds.union(from[i], to[i]);
		}
		int[][] g = packU(n, from, to);
		int[] bclus = decomposeToBECC(g);
		int[][] cg = collect(g, bclus);
		
		int[][] qs = new int[Q][];
		for(int i = 0;i < Q;i++){
			int x = ni()-1, y = ni()-1;
			if(!ds.equiv(x, y)){
				out.println("No");
				return;
			}
			qs[i] = new int[]{bclus[x], bclus[y]};
		}
		cg = Arrays.copyOf(cg, cg.length+1);
		cg[cg.length-1] = new int[ds.count()];
		int p = 0;
		for(int i = 0;i < n;i++){
			if(ds.upper[i] < 0){
				int c = bclus[i];
				cg[cg.length-1][p++] = c;
				cg[c] = Arrays.copyOf(cg[c], cg[c].length+1);
				cg[c][cg[c].length-1] = cg.length-1;
			}
		}
		
		int u = cg.length;
		int[][] pars = parents3(cg, 0);
		int[] par = pars[0], ord = pars[1], dep = pars[2];
		
		int[][] spar = logstepParents(par);
		int[] clus = decomposeToHeavyLight(cg, par, ord);
		int[][] cluspath = clusPaths(clus, ord);
		int[] clusiind = clusIInd(cluspath, u);
		
		int v = cluspath.length;
		int[][] fo = new int[v][];
		int[][] ba = new int[v][];
		for(int i = 0;i < v;i++){
			fo[i] = new int[cluspath[i].length+1];
			ba[i] = new int[cluspath[i].length+1];
		}
		for(int z = 0;z < Q;z++){
			int x = qs[z][0], y = qs[z][1];
			int lca = lca2(x, y, spar, dep);
			
			{
				int cx = clus[x]; // 
				int indx = clusiind[x]; // 
				while (cx != clus[lca]) {
					ba[cx][0] += 1;
					ba[cx][indx+1] -= 1;
					int con = par[cluspath[cx][0]];
					indx = clusiind[con];
					cx = clus[con];
				}
				ba[cx][clusiind[lca]+1] += 1;
				ba[cx][indx+1] -= 1;
			}
			{
				int cx = clus[y]; // 
				int indx = clusiind[y]; // 
				while (cx != clus[lca]) {
					fo[cx][0] += 1;
					fo[cx][indx+1] -= 1;
					int con = par[cluspath[cx][0]];
					indx = clusiind[con];
					cx = clus[con];
				}
				fo[cx][clusiind[lca]+1] += 1;
				fo[cx][indx+1] -= 1;
			}
		}
		
		for(int i = 0;i < cluspath.length;i++){
			for(int j = 0;j < fo[i].length-1;j++){
				fo[i][j+1] += fo[i][j];
				ba[i][j+1] += ba[i][j];
			}
			for(int j = 0;j < fo[i].length;j++){
				if(fo[i][j] > 0 && ba[i][j] > 0){
					out.println("No");
					return;
				}
			}
		}
		out.println("Yes");
	}
	
	public static class DJSet {
		public int[] upper;

		public DJSet(int n) {
			upper = new int[n];
			Arrays.fill(upper, -1);
		}

		public int root(int x) {
			return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
		}

		public boolean equiv(int x, int y) {
			return root(x) == root(y);
		}

		public boolean union(int x, int y) {
			x = root(x);
			y = root(y);
			if (x != y) {
				if (upper[y] < upper[x]) {
					int d = x;
					x = y;
					y = d;
				}
				upper[x] += upper[y];
				upper[y] = x;
			}
			return x == y;
		}

		public int count() {
			int ct = 0;
			for (int u : upper)
				if (u < 0)
					ct++;
			return ct;
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
				pars[j][i] = pars[j - 1][i] == -1 ? -1
						: pars[j - 1][pars[j - 1][i]];
			}
		}
		return pars;
	}
	
	public static int[] decomposeToHeavyLight(int[][] g, int[] par, int[] ord) {
		int n = g.length;
		int[] size = new int[n];
		Arrays.fill(size, 1);
		for (int i = n - 1; i > 0; i--)
			size[par[ord[i]]] += size[ord[i]];

		int[] clus = new int[n];
		Arrays.fill(clus, -1);
		int p = 0;
		outer: for (int i = 0; i < n; i++) {
			int u = ord[i];
			if (clus[u] == -1)
				clus[u] = p++;
			for (int v : g[u]) {
				if (par[u] != v && size[v] >= size[u] / 2) {
					clus[v] = clus[u];
					continue outer;
				}
			}
			for (int v : g[u]) {
				if (par[u] != v) {
					clus[v] = clus[u];
					break;
				}
			}
		}
		return clus;
	}

	public static int[][] clusPaths(int[] clus, int[] ord) {
		int n = clus.length;
		int[] rp = new int[n];
		int sup = 0;
		for (int i = 0; i < n; i++) {
			rp[clus[i]]++;
			sup = Math.max(sup, clus[i]);
		}
		sup++;

		int[][] row = new int[sup][];
		for (int i = 0; i < sup; i++)
			row[i] = new int[rp[i]];

		for (int i = n - 1; i >= 0; i--) {
			row[clus[ord[i]]][--rp[clus[ord[i]]]] = ord[i];
		}
		return row;
	}

	public static int[] clusIInd(int[][] clusPath, int n) {
		int[] iind = new int[n];
		for (int[] path : clusPath) {
			for (int i = 0; i < path.length; i++) {
				iind[path[i]] = i;
			}
		}
		return iind;
	}

	public static void query(int x, int anc, int[] clus, int[][] cluspath,
			int[] clusiind, int[] par) {
		int cx = clus[x]; // 
		int ind = clusiind[x]; // 
		while (cx != clus[anc]) {
			// TODO cx0~ind
			// st[cx].add(0, ind+1, v);
			int con = par[cluspath[cx][0]];
			ind = clusiind[con];
			cx = clus[con];
		}
		// TODO clusiind[anc]~ind
		// st[cx].add(clusiind[anc], ind+1, v);
	}

	public static int[][] query2(int x, int anc, int y, int[] clus,
			int[][] cluspath, int[] clusiind, int[] par) {
		int[][] stack = new int[60][];
		int sp = 0;

		int cx = clus[x]; // 
		int indx = clusiind[x]; // 
		while (cx != clus[anc]) {
			stack[sp++] = new int[] { cx, indx, 0 };
			int con = par[cluspath[cx][0]];
			indx = clusiind[con];
			cx = clus[con];
		}
		stack[sp++] = new int[] { cx, indx, clusiind[anc] };

		int top = sp;
		int cy = clus[y]; // 
		int indy = clusiind[y]; // 
		while (cy != clus[anc]) {
			stack[sp++] = new int[] { cy, 0, indy };
			int con = par[cluspath[cy][0]];
			indy = clusiind[con];
			cy = clus[con];
		}
		if (clusiind[anc] < indy) {
			stack[sp++] = new int[] { cy, clusiind[anc] + 1, indy };
		}
		for (int p = top, q = sp - 1; p < q; p++, q--) {
			int[] dum = stack[p];
			stack[p] = stack[q];
			stack[q] = dum;
		}
		return Arrays.copyOf(stack, sp);
	}
	
	public static int[] decomposeToBECC(int[][] g)
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
	public static int[][] collect(int[][] g, int[] clus)
	{
		int n = g.length;
		int m = 0;
		for(int i = 0;i < n;i++)m = Math.max(m, clus[i]);
		m++;
		
		int[] cp = new int[m];
		for(int i = 0;i < n;i++){
			cp[clus[i]] += g[i].length;
		}
		int[][] c = new int[m][];
		for(int i = 0;i < m;i++){
			c[i] = new int[cp[i]];
		}
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < g[i].length;j++){
				c[clus[i]][--cp[clus[i]]] = clus[g[i][j]];
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
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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