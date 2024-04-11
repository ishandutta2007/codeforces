//package round391;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class F2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
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

	
	int[] extract(int[] from, int[] to, int[] w, int n, int root)
	{
		DJSet ds = new DJSet(n);
		for(int i = 0;i < from.length;i++){
			ds.union(from[i], to[i]);
		}
		int[] map = new int[n];
		Arrays.fill(map, -1);
		int q = 0;
		for(int i = 0;i < n;i++){
			if(ds.equiv(i, root)){
				map[i] = q++;
			}
		}
		
		int p = 0;
		for(int i = 0;i < from.length;i++){
			if(ds.equiv(from[i], root)){
				from[p] = map[from[i]];
				to[p] = map[to[i]];
				w[p] = w[i];
				p++;
			}
		}
		return new int[]{p, q, map[root]};
	}
	
	void solve()
	{
		int n = ni(), m = ni(), root = ni()-1;
		int[] from = new int[m];
		int[] to = new int[m];
		int[] w = new int[m];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
			w[i] = ni();
		}
		int[] res = extract(from, to, w, n, root);
		m = res[0];
		n = res[1];
		root = res[2];
		from = Arrays.copyOf(from, m);
		to = Arrays.copyOf(to, m);
		w = Arrays.copyOf(w, m);
		
		int[][][] g = packWU(n, from, to, w);
		long[] ds = dijkl(g, root);
		
		int[] xfrom = new int[m];
		int[] xto = new int[m];
		int p = 0;
		for(int i = 0;i < m;i++){
			if(ds[to[i]] == ds[from[i]] + w[i]){
				xfrom[p] = from[i];
				xto[p] = to[i];
				p++;
			}else if(ds[from[i]] == ds[to[i]] + w[i]){
				xfrom[p] = to[i];
				xto[p] = from[i];
				p++;
			}
		}
		int[][] xg = packD(n, xfrom, xto, p);
		int[][] ixg = packD(n, xto, xfrom, p);
		int[] dtpar = buildDominatorTree(xg, ixg, root);
		
		int[][] dg = parentToG(dtpar);
		int[][] pars = parents3(dg, root);
		int[] ord = pars[1];
		int[] des = new int[n];
		for(int i = n-1;i >= 1;i--){
			int cur = ord[i];
			des[cur]++;
			des[dtpar[cur]] += des[cur];
		}
		des[root] = 0;
		out.println(Arrays.stream(des).max().getAsInt());
	}
	// hirenketu
	
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
	
	public static int[] buildDominatorTree(int[][] g, int[][] ig, int root)
	{
		int n = g.length;
		int[] parent = new int[n];
		Arrays.fill(parent, -1);
		// step 1
		int[] preord = new int[n];
		int idgen = sortByPreorder(g, root, preord, parent);
		assert idgen == n;
		int[] semi = new int[n];
		for(int i = 0;i < n;i++)semi[preord[i]] = i;
		
		int[] ancestor = new int[n];
		Arrays.fill(ancestor, -1);
		int[] size = new int[n];
		Arrays.fill(size, 1);
		int[] child = new int[n];
		Arrays.fill(child, -1);
		int[] label = new int[n];
		for(int i = 0;i < n;i++)label[i] = i;
		
		int[] bucketFirst = new int[n];
		Arrays.fill(bucketFirst, -1);
		int[] bucketNext = new int[n];
		Arrays.fill(bucketNext, -1);
		
		int[] dom = new int[n];
		Arrays.fill(dom, -1);
		for(int i = n-1;i >= 1;i--){
			int w = preord[i];
			// step 2
			for(int v : ig[w]){
				semi[w] = Math.min(semi[w], semi[eval(v, ancestor, label, semi)]);
			}
			
			int bf = bucketFirst[preord[semi[w]]];
			bucketNext[w] = bf;
			bucketFirst[preord[semi[w]]] = w;
			link(parent[w], w, ancestor, label, semi, size, child);
			
			for(int v = bucketFirst[parent[w]];v != -1;v = bucketNext[v]){
				int u = eval(v, ancestor, label, semi);
				dom[v] = semi[u] < semi[v] ? u : parent[w];
			}
			bucketFirst[parent[w]] = -1;
		}
		
		// step 4
		for(int i = 1;i < n;i++){
			int w = preord[i];
			if(dom[w] != preord[semi[w]])dom[w] = dom[dom[w]];
		}
		dom[root] = -1;
		return dom;
	}
	
	private static int nn(int[] a, int id)
	{
		return id >= 0 ? a[id] : -1;
	}
	
	private static void link(int v, int w, int[] ancestor, int[] label, int[] semi, int[] size, int[] child)
	{
		int s = w;
		while(semi[label[w]] < nn(semi, nn(label, child[s]))){
			if(size[s] + nn(size, nn(child, child[s])) >= 2*nn(size, child[s])){
				ancestor[child[s]] = s; 
				child[s] = child[child[s]];
			}else{
				size[child[s]] = size[s];
				s = ancestor[s] = child[s];
			}
		}
		label[s] = label[w];
		size[v] = size[v] + size[w];
		if(size[v] < 2*size[w]){
			int d = s; s = child[v]; child[v] = d;
		}
		while(s != -1){
			ancestor[s] = v;
			s = child[s];
		}
	}
	
	private static int eval(int v, int[] ancestor, int[] label, int[] semi)
	{
		if(ancestor[v] == -1)return label[v];
		compress(v, ancestor, label, semi);
		return semi[label[ancestor[v]]] >= semi[label[v]] ? label[v] : label[ancestor[v]];
	}
	
	private static void compress(int v, int[] ancestor, int[] label, int[] semi)
	{
		if(v == -1 || ancestor[v] == -1)return;
		compress(ancestor[v], ancestor, label, semi);
		if(semi[label[ancestor[v]]] < semi[label[v]]){
			label[v] = label[ancestor[v]];
		}
		if(ancestor[ancestor[v]] != -1){
			ancestor[v] = ancestor[ancestor[v]];
		}
	}
	
	private static int sortByPreorder(int[][] g, int root, int[] ord, int[] parent){
		int n = g.length;
		int[] stack = new int[n];
		int[] inds = new int[n];
		boolean[] ved = new boolean[n];
		stack[0] = root;
		int p = 1;
		int r = 0;
		ved[root] = true;
		parent[root] = -1;
		outer:
		while(p > 0){
			int cur = stack[p-1];
			if(inds[p-1] == 0){
				ord[r++] = cur;
			}
			for(int i = inds[p-1];i < g[cur].length;i++){
				int e = g[cur][i];
				if(!ved[e]){
					ved[e] = true;
					inds[p-1] = i+1;
					parent[e] = cur;
					stack[p] = e;
					inds[p] = 0;
					p++;
					continue outer;
				}
			}
			p--;
		}
		return r;
	}
	
	public static int[][] packD(int n, int[] from, int[] to){ return packD(n, from, to, from.length);}
	public static int[][] packD(int n, int[] from, int[] to, int sup)
	{
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int i = 0;i < sup;i++)p[from[i]]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]];
		for(int i = 0;i < sup;i++){
			g[from[i]][--p[from[i]]] = to[i];
		}
		return g;
	}

	
	public static long[] dijkl(int[][][] g, int from)
	{
		int n = g.length;
		long[] td = new long[n];
		
		Arrays.fill(td, Long.MAX_VALUE / 2);
		MinHeapL q = new MinHeapL(n);
		q.add(from, 0);
		td[from] = 0;
		
		while(q.size() > 0){
			int cur = q.argmin();
			q.remove(cur);
			
			for(int[] e : g[cur]){
				int next = e[0];
				long nd = td[cur] + e[1];
				if(nd < td[next]){
					td[next] = nd;
					q.update(next, nd);
				}
			}
		}
		
		return td;
	}
	
	public static class MinHeapL {
		public long[] a;
		public int[] map;
		public int[] imap;
		public int n;
		public int pos;
		public static long INF = Long.MAX_VALUE;
		
		public MinHeapL(int m)
		{
			n = Integer.highestOneBit((m+1)<<1);
			a = new long[n];
			map = new int[n];
			imap = new int[n];
			Arrays.fill(a, INF);
			Arrays.fill(map, -1);
			Arrays.fill(imap, -1);
			pos = 1;
		}
		
		public long add(int ind, long x)
		{
			int ret = imap[ind];
			if(imap[ind] < 0){
				a[pos] = x; map[pos] = ind; imap[ind] = pos;
				pos++;
				up(pos-1);
			}
			return ret != -1 ? a[ret] : x;
		}
		
		public long update(int ind, long x)
		{
			int ret = imap[ind];
			if(imap[ind] < 0){
				a[pos] = x; map[pos] = ind; imap[ind] = pos;
				pos++;
				up(pos-1);
			}else{
				a[ret] = x;
				up(ret);
				down(ret);
			}
			return x;
		}
		
		public long remove(int ind)
		{
			if(pos == 1)return INF;
			if(imap[ind] == -1)return INF;
			
			pos--;
			int rem = imap[ind];
			long ret = a[rem];
			map[rem] = map[pos];
			imap[map[pos]] = rem;
			imap[ind] = -1;
			a[rem] = a[pos];
			a[pos] = INF;
			map[pos] = -1;
			
			up(rem);
			down(rem);
			return ret;
		}
		
		public long min() { return a[1]; }
		public int argmin() { return map[1]; }
		public int size() {	return pos-1; }
		
		private void up(int cur)
		{
			for(int c = cur, p = c>>>1;p >= 1 && a[p] > a[c];c>>>=1, p>>>=1){
				long d = a[p]; a[p] = a[c]; a[c] = d;
				int e = imap[map[p]]; imap[map[p]] = imap[map[c]]; imap[map[c]] = e;
				e = map[p]; map[p] = map[c]; map[c] = e;
			}
		}
		
		private void down(int cur)
		{
			for(int c = cur;2*c < pos;){
				int b = a[2*c] < a[2*c+1] ? 2*c : 2*c+1;
				if(a[b] < a[c]){
					long d = a[c]; a[c] = a[b]; a[b] = d;
					int e = imap[map[c]]; imap[map[c]] = imap[map[b]]; imap[map[b]] = e;
					e = map[c]; map[c] = map[b]; map[b] = e;
					c = b;
				}else{
					break;
				}
			}
		}
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

	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new F2().run(); }
	
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