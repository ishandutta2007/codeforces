//package round299;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), Q = ni();
		int[] F = new int[n];
		SegmentTreeSeqMaxSum.F = F;
		for(int i = 1;i < n;i++)F[i] = ni();
		int[] from = new int[n-1];
		int[] to = new int[n-1];
		int[][] es = new int[n-1+Q][];
		for(int i = 0;i < n-1;i++){
			from[i] = ni()-1; to[i] = ni()-1;
			es[i] = new int[]{from[i], to[i], ni()};
		}
		int[][] g = packU(n, from, to);
		int[][] pars = parents3(g, 0);
		int[] par = pars[0], ord = pars[1], dep = pars[2];
		int[][] spar = logstepParents(par);
		int[] clus = decomposeToHeavyLight(g, par, ord);
		int[][] cluspath = clusPaths(clus, ord);
		int[] clusiind = clusIInd(cluspath, n);
		int m = cluspath.length;
		
		SegmentTreeSeqMaxSum[] sts = new SegmentTreeSeqMaxSum[m];
		for(int i = 0;i < m;i++){
			int u = cluspath[i].length;
			sts[i] = new SegmentTreeSeqMaxSum(u);
		}
		for(int i = 0;i < Q;i++){
			es[i+n-1] = new int[]{ni()-1, ni()-1, ni(), i};
		}
		Arrays.sort(es, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[2] != b[2])return -(a[2] - b[2]);
				return a.length - b.length;
			}
		});
		
		int[] rets = new int[Q];
		for(int[] e : es){
//			tr("E", e);
			if(e.length == 3){
				int f = e[0], t = e[1];
				if(par[f] != t){
					int d = t; t = f; f = d;
				}
//				tr("up", clus[f], clusiind[f]);
				sts[clus[f]].update(clusiind[f]);
			}else{
				int x = e[0], y = e[1], id = e[3];
				int lca = lca2(x, y, spar, dep);
				int[][] qs = query2(x, lca, y, clus, cluspath, clusiind, par);
//				tr("qs", qs);
				int[] ret = null;
				for(int[] q : qs){
					int l = q[1], r = q[2];
					if(l <= r){
						int[] res = sts[q[0]].smax(l, r+1);
//						tr(q[0], l, r+1, res);
						if(ret == null){
							ret = res;
						}else{
							ret = SegmentTreeSeqMaxSum.propNC(new int[3], ret, res);
						}
					}else if(l > r){
						int[] res = sts[q[0]].smax(r, l+1);
						int u = res[0]; res[0] = res[2]; res[2] = u;
						if(ret == null){
							ret = res;
						}else{
							ret = SegmentTreeSeqMaxSum.propNC(new int[3], ret, res);
						}
					}
				}
				if(ret == null){
					rets[id] = 0;
				}else if(ret[1] == SegmentTreeSeqMaxSum.I){
					rets[id] = F[ret[0]];
				}else{
					rets[id] = ret[1] + F[ret[0]] + F[ret[2]];
				}
			}
		}
		for(int i = 0;i < Q;i++){
			out.println(rets[i]);
		}
	}
	
	public static class SegmentTreeSeqMaxSum {
		public static int[] F;
		public int M, H, N;
		public int[][] st; // [, , ]
		public static int I = Integer.MIN_VALUE/2 + 30000;
		
//		public SegmentTreeSeqMaxSum(int[] a)
//		{
//			N = a.length;
//			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
//			H = M>>>1;
//			st = new long[M][4];
//			for(int i = 0;i < H;i++){
//				long v = i < N ? a[i] : I;
//				Arrays.fill(st[H+i], v);
//			}
//			for(int i = H-1;i >= 1;i--){
//				propagate(i);
//			}
//		}
		
		public SegmentTreeSeqMaxSum(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new int[M][3];
			for(int i = 0;i < H;i++){
				st[H+i] = new int[]{0, 0, 0};
			}
			for(int i = H-1;i >= 1;i--){
				propagate(i);
			}
		}
		
		
		private void propagate(int i)
		{
			int[] P = st[i], L = st[2*i], R = st[2*i+1];
			propNC(P, L, R);
		}
		
		public static int[] propNC(int[] P, int[] L, int[] R)
		{
			if(L[1] == I && R[1] == I){
				P[0] = L[0] + R[0];
				P[1] = I;
				P[2] = L[2] + R[2];
			}else if(L[1] == I){
				P[0] = L[0] + R[0];
				P[1] = R[1];
				P[2] = R[2];
			}else if(R[1] == I){
				P[0] = L[0];
				P[1] = L[1];
				P[2] = L[2] + R[2];
			}else{
				P[0] = L[0];
				P[1] = L[1] + R[1] + F[L[2] + R[0]];
				P[2] = R[2];
			}
			return P;
		}
		
		public void update(int pos)
		{
			st[H+pos][0] = 1;
			st[H+pos][1] = I;
			st[H+pos][2] = 1;
			for(int x = H+pos>>>1;x != 0;x>>>=1){
				propNC(st[x], st[2*x], st[2*x+1]);
			}
		}
		
		public int[] smax(int l, int r){ return smax(l, r, 0, H, 1); }
		
		private int[] smax(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return Arrays.copyOf(st[cur], st[cur].length);
			}else{
				int mid = cl+cr>>>1;
				int[] L = null, R = null;
				if(cl < r && l < mid){
					L = smax(l, r, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					R = smax(l, r, mid, cr, 2*cur+1);
				}
				if(L != null && R != null){
					return propNC(new int[3], L, R);
				}
				return L != null ? L : R;
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

	public int[][] query2(int x, int anc, int y, int[] clus,
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
		if(indx > clusiind[anc])stack[sp++] = new int[] { cx, indx, clusiind[anc]+1 };
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