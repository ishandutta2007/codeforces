//package round329;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int Q = ni();
		int[] from = new int[n - 1];
		int[] to = new int[n - 1];
		long[] w = new long[n-1];
		for (int i = 0; i < n - 1; i++) {
			from[i] = ni() - 1;
			to[i] = ni() - 1;
			w[i] = nl();
		}
		int[][] g = packU(n, from, to, w);
		int[][] pars = parents3(g, 0);
		int[] par = pars[0], ord = pars[1], dep = pars[2];
		long[] pw = new long[n];
//		Arrays.fill(pw, -1);
		for(int i = 0;i < n;i++){
			for(int j = 0;j < g[i].length;j++){
				int e = g[i][j];
				if(par[i] == e){
					pw[i] = wg[i][j];
					break;
				}
			}
		}
		
		int[] clus = decomposeToHeavyLight(g, par, ord);
		int[][] cluspath = clusPaths(clus, ord);
		int[] clusiind = clusIInd(cluspath, n);
		
		int m = cluspath.length;
		SegmentTreeRSQ[] sts = new SegmentTreeRSQ[m];
		for(int i = 0;i < m;i++){
			long[] t = new long[cluspath[i].length];
			for(int j = 0;j < cluspath[i].length;j++){
				t[j] = pw[cluspath[i][j]];
			}
			sts[i] = new SegmentTreeRSQ(t);
		}
		int[][] spar = logstepParents(par);
		
		for(;Q > 0;Q--){
			int t = ni();
			if(t == 1){
				int a = ni()-1, b = ni()-1;
				long y = nl();
				int lca = lca2(a, b, spar, dep);
				
				{
					int x = a, anc = lca;
					int cx = clus[x]; // 
					int ind = clusiind[x]; // 
					while (cx != clus[anc]) {
						y /= sts[cx].prod(0, ind+1);
						int con = par[cluspath[cx][0]];
						ind = clusiind[con];
						cx = clus[con];
					}
					y /= sts[cx].prod(clusiind[anc]+1, ind+1);
				}
				{
					int x = b, anc = lca;
					int cx = clus[x]; // 
					int ind = clusiind[x]; // 
					while (cx != clus[anc]) {
						y /= sts[cx].prod(0, ind+1);
						int con = par[cluspath[cx][0]];
						ind = clusiind[con];
						cx = clus[con];
					}
					y /= sts[cx].prod(clusiind[anc]+1, ind+1);
				}
				out.println(y);
			}else{
				int p = ni()-1;
				long c = nl();
				if(par[from[p]] == to[p]){
					sts[clus[from[p]]].update(clusiind[from[p]], c);
				}else{
					sts[clus[to[p]]].update(clusiind[to[p]], c);
				}
			}
		}
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
	
	
	public static class SegmentTreeRSQ {
		public int M, H, N;
		public long[] st;
		
		public SegmentTreeRSQ(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new long[M];
			Arrays.fill(st, 1);
		}
		
		public SegmentTreeRSQ(long[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new long[M];
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
			}
			for(int i = (M>>1)-1;i >= 1;i--){
				propagate(i);
			}
		}
		
		public void update(int pos, long v)
		{
			st[H+pos] = v;
			for(int i = H+pos>>>1;i >= 1;i >>>= 1){
				propagate(i);
			}
		}
		
		long I = 2000000000000000000L;
		
		private void propagate(int i)
		{
			st[i] = mul(st[2*i], st[2*i+1]);
		}
		
		private long gsum;
		
		public long prod(int l, int r) { 
			gsum = 1;
			prod(l, r, 0, H, 1);
			return gsum;
		}
		
		private long mul(long a, long b)
		{
			double d = (double)a*b;
			if(d <= I){
				return Math.min(I, a*b);
			}else{
				return I;
			}
			
		}
		
		private void prod(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				gsum = mul(gsum, st[cur]);
			}else{
				int mid = cl+cr>>>1;
				if(cl < r && l < mid){
					prod(l, r, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					prod(l, r, mid, cr, 2*cur+1);
				}
			}
		}
	}
	
	long[][] wg;
	
	int[][] packU(int n, int[] from, int[] to, long[] w) {
		int[][] g = new int[n][];
		wg = new long[n][];
		int[] p = new int[n];
		for (int f : from)
			p[f]++;
		for (int t : to)
			p[t]++;
		for (int i = 0; i < n; i++){
			g[i] = new int[p[i]];
			wg[i] = new long[p[i]];
		}
		for (int i = 0; i < from.length; i++) {
			g[from[i]][--p[from[i]]] = to[i];
			wg[from[i]][p[from[i]]] = w[i];
			g[to[i]][--p[to[i]]] = from[i];
			wg[to[i]][p[to[i]]] = w[i];
		}
		return g;
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