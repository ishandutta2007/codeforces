//package round362;
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
	
	int[] c;
	int[][] b;
	int[] pb;
	int[] clus;
	int[][] cluspath;
	int[] clusiind;
	StarrySkyTreePosL[] ssts;
	long I = 1000000000L*1000000L;
	int[] par;
	
	void solve()
	{
		int n = ni(), m = ni(), Q = ni();
		int[] from = new int[n - 1];
		int[] to = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			from[i] = ni() - 1;
			to[i] = ni() - 1;
		}
		int[][] g = packU(n, from, to);
		int[][] pars = parents3(g, 0);
		par = pars[0];
		int[] ord = pars[1], dep = pars[2];
		c = na(m);
		for(int i = 0;i < m;i++){
			c[i]--;
		}
		b = makeBuckets(c, n+1);
		pb = new int[n+1];
		
		clus = decomposeToHeavyLight(g, par, ord);
		cluspath = clusPaths(clus, ord);
		clusiind = clusIInd(cluspath, n);
		
		int ncp = cluspath.length;
		ssts = new StarrySkyTreePosL[ncp];
		for(int i = 0;i < ncp;i++){
			ssts[i] = new StarrySkyTreePosL(cluspath[i].length);
			ssts[i].add(0, cluspath[i].length, I);
		}
		for(int i = 0;i < n;i++){
			if(b[i].length > 0){
				int id = b[i][0];
				ssts[clus[i]].add(clusiind[i], clusiind[i]+1, -I+id+1);
				ssts[clus[i]].updatePos(clusiind[i], id);
			}
		}
//		for(int i = 0;i < ncp;i++){
//			tr(ssts[i].toArray());
//		}
		
		int[][] spar = logstepParents(par);
		
		int[] temp = new int[m+1];
//		tr("SSTS");
//		for(int o = 0;o < ncp;o++){
//			tr(ssts[o].toArray());
//		}
		for(int z = 0;z < Q;z++){
			int t = ni();
			if(t == 1){
				int v = ni()-1, u = ni()-1, K = ni();
				int lca = lca2(v, u, spar, dep);
				int tp = 0;
				while(K > 0){
					long[] minv = argmin(v, lca);
					long[] minu = argmin(u, lca);
					if(minv[1] == -1 && minu[1] == -1)break;
					if(minv[0] < minu[0] || minv[0] == minu[0] && minv[1] < minu[1]){
						temp[tp++] = (int)minv[1];
						replace((int)minv[1]);
					}else{
						temp[tp++] = (int)minu[1];
						replace((int)minu[1]);
					}
					K--;
				}
				out.print(tp);
				for(int i = 0;i < tp;i++){
					out.print(" " + (temp[i]+1));
				}
				out.println();
				out.flush();
			}else{
				// add to subtree
				int v = ni()-1, K = ni();
				ssts[clus[v]].add(clusiind[v], cluspath[clus[v]].length, K);
//				tr("SSTS");
//				for(int o = 0;o < ncp;o++){
//					tr(ssts[o].toArray());
//				}
			}
		}
	}
	
	int[] heads = new int[20];
	int[] tails = new int[20];
	int[] cluss = new int[20];
	
	long[] argmin(int v, int anc)
	{
//		tr("argmin", v, anc);
		int ep = 0;
		int cur = v;
		while(true){
//			tr(cur, anc, clus[cur], clus[anc]);
			tails[ep] = cur;
			cluss[ep] = clus[cur];
			if(clus[cur] == clus[anc]){
				heads[ep] = anc;
				ep++;
				break;
			}
			int head = cluspath[clus[cur]][0];
			heads[ep] = head;
			cur = par[head];
			ep++;
		}
//		tr(Arrays.copyOf(tails, ep));
//		tr(Arrays.copyOf(heads, ep));
//		tr(Arrays.copyOf(cluss, ep));
		long min = I-2;
		long argmin = -1;
		long lplus = 0;
		for(int i = ep-1;i >= 0;i--){
			long[] lmin = ssts[cluss[i]].minpos(clusiind[heads[i]], clusiind[tails[i]]+1);
			lmin[0] += lplus;
//			int where = cluspath[cluss[i]][(int)lmin[1]];
//			lmin[1] = b[where][pb[where]];
//			tr("lmin, lplus", lmin, lplus);
			if(lmin[0] < min || lmin[0] == min && lmin[1] < argmin){
				min = lmin[0];
				argmin = lmin[1];
			}
			long tval = pb[tails[i]] < b[tails[i]].length ?
					b[tails[i]][pb[tails[i]]] + 1 :
						I;
			
			lplus += ssts[cluss[i]].min(clusiind[tails[i]], clusiind[tails[i]]+1) - tval;
		}
//		tr("MIN", min, argmin);
		return new long[]{min, argmin};
	}
	
	int id(int clus, int x)
	{
		int where = cluspath[clus][x];
		return b[where][pb[where]];
	}
	
	void replace(int x)
	{
		int at = c[x];
		if(++pb[at] == b[at].length){
			long curv = ssts[clus[at]].min(clusiind[at], clusiind[at]+1);
			ssts[clus[at]].add(clusiind[at], clusiind[at]+1, I-(x+1));
		}else{
			ssts[clus[at]].add(clusiind[at], clusiind[at]+1, b[at][pb[at]] - x);
			ssts[clus[at]].updatePos(clusiind[at], b[at][pb[at]]);
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
				pars[j][i] = pars[j - 1][i] == -1 ? -1 : pars[j - 1][pars[j - 1][i]];
			}
		}
		return pars;
	}

	
	public static class StarrySkyTreePosL {
		public int M, H, N;
		public long[] st;
		public long[] plus;
		public int[] pos;
		public long I = Long.MAX_VALUE/4; // I+plus<int
		
		public StarrySkyTreePosL(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(n-1, 1))<<2;
			H = M>>>1;
			st = new long[M];
			plus = new long[H];
			pos = new int[M];
			for(int i = M-1;i >= H;i--)pos[i] = i-H;
			for(int i = H-1;i >= 0;i--)propagate(i);
		}
		
		public StarrySkyTreePosL(long[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new long[M];
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
			}
			plus = new long[H];
			Arrays.fill(st, H+N, M, I);
			pos = new int[M];
			for(int i = M-1;i >= H;i--)pos[i] = i-H;
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		private void propagate(int i)
		{
			if(st[2*i] < st[2*i+1] || st[2*i] == st[2*i+1] && pos[2*i] < pos[2*i+1]){
				st[i] = st[2*i] + plus[i];
				pos[i] = pos[2*i];
			}else{
				st[i] = st[2*i+1] + plus[i];
				pos[i] = pos[2*i+1];
			}
		}
		
		public void updatePos(int x, int v)
		{
			pos[H+x] = v;
			for(int i = H+x>>>1;i >= 1;i>>>=1){
				propagate(i);
			}
		}
		
		public void add(int l, int r, long v){ if(l < r)add(l, r, v, 0, H, 1); }
		
		private void add(int l, int r, long v, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				if(cur >= H){
					st[cur] += v;
				}else{
					plus[cur] += v;
					propagate(cur);
				}
			}else{
				int mid = cl+cr>>>1;
				if(cl < r && l < mid){
					add(l, r, v, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					add(l, r, v, mid, cr, 2*cur+1);
				}
				propagate(cur);
			}
		}
		
		public long min(int l, int r){ return l >= r ? I : min(l, r, 0, H, 1);}
		
		private long min(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return st[cur];
			}else{
				int mid = cl+cr>>>1;
				long ret = I;
				if(cl < r && l < mid){
					ret = Math.min(ret, min(l, r, cl, mid, 2*cur));
				}
				if(mid < r && l < cr){
					ret = Math.min(ret, min(l, r, mid, cr, 2*cur+1));
				}
				return ret + plus[cur];
			}
		}
		
		public long[] minpos(int l, int r){ return l >= r ? null : minpos(l, r, 0, H, 1);}
		
		private long[] minpos(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return new long[]{st[cur], pos[cur]};
			}else{
				int mid = cl+cr>>>1;
				long[] L = null, R = null;
				if(cl < r && l < mid){
					L = minpos(l, r, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					R = minpos(l, r, mid, cr, 2*cur+1);
				}
				if(L == null && R == null)return null;
				if(R == null){
					L[0] += plus[cur];
					return L;
				}
				if(L == null){
					R[0] += plus[cur];
					return R;
				}
				if(L[0] < R[0] || L[0] == R[0] && L[1] < R[1]){
					L[0] += plus[cur];
					return L;
				}else{
					R[0] += plus[cur];
					return R;
				}
			}
		}
		
		public void fall(int i)
		{
			if(i < H){
				if(2*i < H){
					plus[2*i] += plus[i];
					plus[2*i+1] += plus[i];
				}
				st[2*i] += plus[i];
				st[2*i+1] += plus[i];
				plus[i] = 0;
			}
		}
		
		public int firstle(int l, long v) {
			if(l >= H)return -1;
			int cur = H+l;
			for(int i = 1, j = Integer.numberOfTrailingZeros(H)-1;i <= cur;j--){
				fall(i);
				i = i*2 + (cur>>>j&1);
			}
			while(true){
				fall(cur);
				if(st[cur] <= v){
					if(cur < H){
						cur = 2*cur;
					}else{
						return cur-H;
					}
				}else{
					cur++;
					if((cur&cur-1) == 0)return -1;
					cur = cur>>>Integer.numberOfTrailingZeros(cur);
				}
			}
		}
		
		public int lastle(int l, long v) {
			if(l < 0)return -1;
			int cur = H+l;
			for(int i = 1, j = Integer.numberOfTrailingZeros(H)-1;i <= cur;j--){
				fall(i);
				i = i*2 + (cur>>>j&1);
			}
			while(true){
				fall(cur);
				if(st[cur] <= v){
					if(cur < H){
						cur = 2*cur+1;
					}else{
						return cur-H;
					}
				}else{
					if((cur&cur-1) == 0)return -1;
					cur = cur>>>Integer.numberOfTrailingZeros(cur);
					cur--;
				}
			}
		}		
		public long[] toArray() { return toArray(1, 0, H, new long[H]); }
		
		private long[] toArray(int cur, int l, int r, long[] ret)
		{
			if(r-l == 1){
				ret[cur-H] = st[cur];
			}else{
				toArray(2*cur, l, l+r>>>1, ret);
				toArray(2*cur+1, l+r>>>1, r, ret);
				for(int i = l;i < r;i++)ret[i] += plus[cur];
			}
			return ret;
		}
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

	public static void query(int x, int anc, int[] clus, int[][] cluspath, int[] clusiind, int[] par) {
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

	public static int[][] query2(int x, int anc, int y, int[] clus, int[][] cluspath, int[] clusiind, int[] par) {
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

	
	public static int[][] makeBuckets(int[] a, int sup)
	{
		int n = a.length;
		int[][] bucket = new int[sup+1][];
		int[] bp = new int[sup+1];
		for(int i = 0;i < n;i++)bp[a[i]]++;
		for(int i = 0;i <= sup;i++)bucket[i] = new int[bp[i]];
		for(int i = n-1;i >= 0;i--)bucket[a[i]][--bp[a[i]]] = i;
		return bucket;
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