//package round673;
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
		int n = ni(), m = ni(), Q = ni();
		int[] a = na(n);
		int[] from = new int[m];
		int[] to = new int[m];
		boolean[] remain = new boolean[m];
		for(int i = 0;i < m;i++) {
			from[i] = ni()-1;
			to[i] = ni()-1;
		}
		Arrays.fill(remain, true);
		
		
		int[][] qs = new int[Q][];
		for(int i = 0;i < Q;i++) {
			qs[i] = new int[] {ni(), ni()-1};
			if(qs[i][0] == 2) {
				remain[qs[i][1]] = false;
			}
		}
		
		int gen = n;
		int[] par = new int[2*n];
		Arrays.fill(par, -1);
		DJSet ds = new DJSet(n);
		for(int i = 0;i < m;i++) {
			if(remain[i]) {
				if(!ds.equiv(from[i], to[i])) {
					int f = ds.tr[ds.root(from[i])];
					int t = ds.tr[ds.root(to[i])];
					ds.union(from[i], to[i]);
					par[f] = gen;
					par[t] = gen;
					ds.tr[ds.root(from[i])] = gen;
					gen++;
				}
			}
		}
		
		int[] time = new int[2*n];
		Arrays.fill(time, Q);
		for(int i = Q-1;i >= 0;i--) {
			if(qs[i][0] == 2) {
				int ind = qs[i][1];
				if(!ds.equiv(from[ind], to[ind])) {
					int f = ds.tr[ds.root(from[ind])];
					int t = ds.tr[ds.root(to[ind])];
					ds.union(from[ind], to[ind]);
					par[f] = gen;
					par[t] = gen;
					ds.tr[ds.root(from[ind])] = gen;
					time[gen] = i;
					gen++;
				}
			}
		}
		
		time[2*n-1] = -1;
		for(int i = 0;i < 2*n-1;i++) {
			if(par[i] == -1) {
				par[i] = 2*n-1;
			}
		}
		
		int[][] g = parentToG(par);
		int[][] rights = makeRights(g, par, 2*n-1);
		int[] iord = rights[1], right = rights[2];
		int[][] spar = logstepParents(par);
		
		int[] b = new int[2*n];
		for(int i = 0;i < n;i++) {
			b[iord[i]] = -a[i];
		}
		SegmentTreeRMQPos st = new SegmentTreeRMQPos(b);
		for(int i = 0;i < Q;i++) {
			int[] q = qs[i];
			if(q[0] == 1) {
				int v = q[1];
				for(int d = spar.length-1;d >= 0;d--) {
					int anc = spar[d][v];
					if(anc == -1)continue;
					if(time[anc] < i)continue;
					v = anc;
				}
				int[] vp = st.min(iord[v], right[iord[v]]);
				out.println(-vp[0]);
				st.update(vp[1], 0);
			}
		}
	}
	
	public static class SegmentTreeRMQPos {
		public int M, H, N, B;
		public int[] st;
		public int[] pos;
		
		public SegmentTreeRMQPos(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(n, 1))<<2;
			H = M>>>1;
			B = Integer.numberOfTrailingZeros(H);
			st = new int[M];
			pos = new int[M];
			for(int i = M-1;i >= H;i--)pos[i] = i-H;
			for(int i = H-1;i >= 0;i--){
				pos[i] = pos[2*i];
			}
		}
		
		public SegmentTreeRMQPos(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N, 1))<<2;
			H = M>>>1;
			B = Integer.numberOfTrailingZeros(H);
			st = new int[M];
			pos = new int[M];
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
				pos[H+i] = i;
			}
			Arrays.fill(st, H+N, M, Integer.MAX_VALUE);
			for(int i = (M>>1)-1;i >= 1;i--)propagate(i);
		}
		
		public void update(int p, int x)
		{
			st[H+p] = x;
			for(int i = (H+p)>>>1;i >= 1;i >>>= 1)propagate(i);
		}
		
		private void propagate(int i)
		{
			if(st[i*2] <= st[i*2+1]){
				st[i] = st[i*2];
				pos[i] = pos[i*2];
			}else{
				st[i] = st[i*2+1];
				pos[i] = pos[i*2+1];
			}
		}
		
		public int[] min(int f, int t) { return min(f, t, B); }
		
		public int[] min(int f, int t, int b)
		{
			if(f>>b<<b==f && t+1>>b<<b==t+1){
				return new int[]{st[(H|f)>>b], pos[(H|f)>>b]};
			}
			
			b--;
			if((f^t)<<31-b<0){
				int w = t>>b<<b;
				int[] l = min(f, w-1, b);
				int[] r = min(w, t, b);
				return l[0] <= r[0] ? l : r;
			}else{
				return min(f, t, b);
			}
		}
	}

	
	public static int[] sortByPreorder(int[][] g, int root){
		int n = g.length;
		int[] stack = new int[n];
		int[] ord = new int[n];
		boolean[] ved = new boolean[n];
		stack[0] = root;
		int p = 1;
		int r = 0;
		ved[root] = true;
		while(p > 0){
			int cur = stack[p-1];
			ord[r++] = cur;
			p--;
			for(int e : g[cur]){
				if(!ved[e]){
					ved[e] = true;
					stack[p++] = e;
				}
			}
		}
		return ord;
	}
	
	public static int[][] makeRights(int[][] g, int[] par, int root)
	{
		int n = g.length;
		int[] ord = sortByPreorder(g, root);
		int[] iord = new int[n];
		for(int i = 0;i < n;i++)iord[ord[i]] = i;
		
		int[] right = new int[n];
		for(int i = n-1;i >= 1;i--){
			if(right[i] == 0)right[i] = i;
			int p = iord[par[ord[i]]];
			right[p] = Math.max(right[p], right[i]);
		}
		return new int[][]{ord, iord, right};
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
	
	public static int[][] parentToG(int[] par)
	{
		int n = par.length;
		int[] ct = new int[n];
		for(int i = 0;i < n;i++){
			if(par[i] >= 0){
				ct[i]++;
				ct[par[i]]++;
			}
		}
		int[][] g = new int[n][];
		for(int i = 0;i < n;i++){
			g[i] = new int[ct[i]];
		}
		for(int i = 0;i < n;i++){
			if(par[i] >= 0){
				g[par[i]][--ct[par[i]]] = i;
				g[i][--ct[i]] = par[i];
			}
		}
		return g;
	}

	
	public static class DJSet {
		public int[] upper;
		public int[] tr;

		public DJSet(int n) {
			upper = new int[n];
			Arrays.fill(upper, -1);
			tr = new int[n];
			for(int i = 0;i < n;i++) tr[i] = i;
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