//package round458;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E8 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	char[] s;
	LCAByEulerTourWithSparseTable lcam;
	
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
		par = pars[0];
		int[] ord = pars[1];
		
		s = ns(n);
		fvs = new long[n];
		int[] cpar = buildCentroidTree(g);
		lcam = new LCAByEulerTourWithSparseTable(g, 0);
		dfsTopCT(cpar, g);
		
		for(int i = n-1;i >= 1;i--){
			int cur = ord[i];
			fvs[par[cur]] += fvs[cur];
		}
		for(int i = 0;i < n;i++){
			out.print(fvs[i] + " ");
		}
		out.println();
	}
	
	long[] fvs;
	int[] par;
	
	public static int[] buildCentroidTree(int[][] g) {
		int n = g.length;
		int[] ctpar = new int[n];
		Arrays.fill(ctpar, -1);
		buildCentroidTree(g, 0, new boolean[n], new int[n], new int[n], new int[n], ctpar);
		return ctpar;
	}
	
	private static int buildCentroidTree(int[][] g, int root, boolean[] sed, int[] par, int[] ord, int[] des, int[] ctpar)
	{
		// parent and level-order
		ord[0] = root;
		par[root] = -1;
		int r = 1;
		for(int p = 0;p < r;p++) {
			int cur = ord[p];
			for(int nex : g[cur]){
				if(par[cur] != nex && !sed[nex]){
					ord[r++] = nex;
					par[nex] = cur;
				}
			}
		}
		// if(r == 1)return;
		
		// DP and find a separator
		int sep = -1; // always exists
		outer:
		for(int i = r-1;i >= 0;i--){
			int cur = ord[i];
			des[cur] = 1;
			for(int e : g[cur]){
				if(par[cur] != e && !sed[e])des[cur] += des[e];
			}
			if(r-des[cur] <= r/2){
				for(int e : g[cur]){
					if(par[cur] != e && !sed[e] && des[e] >= r/2+1)continue outer;
				}
				sep = cur;
				break;
			}
		}
		
		sed[sep] = true;
		for(int e : g[sep]){
			if(!sed[e])ctpar[buildCentroidTree(g, e, sed, par, ord, des, ctpar)] = sep;
		}
		return sep;
	}
	
	public void dfsTopCT(int[] cpar, int[][] g) {
		int n = g.length;
		int ctroot = -1;
		for(int i = 0;i < n;i++)if(cpar[i] == -1)ctroot = i;
		int[][] ctch = parentToChildren(cpar);
		long I = Long.MAX_VALUE / 2;
		long[] dd = new long[n];
		Arrays.fill(dd, I);
		dfs(ctroot, new boolean[n], new long[n], new long[n][], dd,
				new int[n], new int[n], g, ctch);
	}
	
	public static int[][] parentToChildren(int[] par)
	{
		int n = par.length;
		int[] ct = new int[n];
		for(int i = 0;i < n;i++){
			if(par[i] >= 0){
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
			}
		}
		
		return g;
	}

	
	private void dfs(int sep, boolean[] seps, long[] ds, long[][] dss, long[] dd,
			int[] stack, int[] inds, int[][] g, int[][] ctch)
	{
		long I = Long.MAX_VALUE / 2;
		seps[sep] = true;
		int neckp = 0;
		for(int neck : g[sep]){
			if(seps[neck])continue;
			int sp = 0;
			inds[sp] = 0;
			stack[sp++] = neck;
			int gdp = 0;
			dd[neck] = 1L<<s[neck]-'a'+32|neck;
			while(sp > 0){
				int cur = stack[sp-1];
				if(inds[sp-1] == 0){
					ds[gdp++] = dd[cur];
				}
				if(inds[sp-1] == g[cur].length){
					sp--; 
					dd[cur] = I;
					continue; 
				}
				int e = g[cur][inds[sp-1]++];
				if(!seps[e] && dd[e] == I){
					dd[e] = (dd[cur]>>>32 ^ 1L<<s[e]-'a')<<32|e;
					stack[sp] = e;
					inds[sp] = 0;
					sp++;
				}
			}
			dss[neckp++] = Arrays.copyOf(ds, gdp);
		}
		
		process(sep, Arrays.copyOf(dss, neckp), g);
		
		for(int e : ctch[sep]){
			dfs(e, seps, ds, dss, dd, stack, inds, g, ctch);
		}
		seps[sep] = false;
	}
	
	int[] temp = new int[1<<20];
	
	void process(int sep, long[][] dss, int[][] g)
	{
		for(long[] ds : dss){
			for(long e : ds){
				temp[(int)(e>>>32)]++;
			}
		}
		temp[0]++;
		
		int m = 1;
		for(long[] ds : dss){
			m += ds.length;
		}
		long[] vs = new long[m];
		int p = 0;
		for(long[] ds : dss){
			for(long e : ds){
				vs[p++] = e;
			}
		}
		vs[p++] = 0L<<32|sep;
		f(vs, sep, 1);
		for(long[] ds : dss){
			for(long e : ds){
				temp[(int)(e>>>32)]--;
			}
		}
		temp[0]--;
		
		for(long[] ds : dss){
			for(long e : ds){
				temp[(int)(e>>>32)]++;
			}
			f(ds, sep, -1);
			for(long e : ds){
				temp[(int)(e>>>32)]--;
			}
		}
	}

	void f(long[] vs, int sep, int mul)
	{
//		tr("vs", vs);
		int n = vs.length;
		// x^y^root = 1<<j
		long h = 0;
		for(int i = 0;i < n;i++){
			int fv = 0;
			int v = (int)(vs[i]>>>32^1<<s[sep]-'a');
			fv += temp[v];
			for(int j = 0;j < 20;j++){
				fv += temp[v^1<<j];
			}
			fv++;
			fv *= mul;
			int node = (int)vs[i];
			h += fv;
//			tr("S", node, sep, fv);
			int lca = lcam.lca(node, sep);
			fvs[node] += fv;
			fvs[sep] += fv;
			fvs[lca] -= fv;
			if(par[lca] != -1)fvs[par[lca]] -= fv;
		}
//		tr("h", h);
		fvs[sep] -= h/2;
		if(par[sep] != -1)fvs[par[sep]] += h/2;
	}
	
	public static int[][][] buildP(int[] a)
	{
		int n = a.length;
		int b = 32-Integer.numberOfLeadingZeros(n);
		int[][] ret = new int[b][];
		int[][] pos = new int[b][];
		for(int i = 0, l = 1;i < b;i++, l*=2) {
			if(i == 0) {
				ret[i] = a;
				pos[i] = new int[n];
				for(int j = 0;j < n;j++)pos[i][j] = j;
			}else {
				ret[i] = new int[n-l+1];
				pos[i] = new int[n-l+1];
				for(int j = 0;j < n-l+1;j++) {
					if(ret[i-1][j] < ret[i-1][j+l/2]){
						ret[i][j] = ret[i-1][j];
						pos[i][j] = pos[i-1][j];
					}else{
						ret[i][j] = ret[i-1][j+l/2];
						pos[i][j] = pos[i-1][j+l/2];
					}
				}
			}
		}
		return new int[][][]{ret, pos};
	}
	
	public static int rmqpos(int[][][] st, int a, int b)
	{
		int t = 31-Integer.numberOfLeadingZeros(b-a);
		if(st[0][t][a] < st[0][t][b-(1<<t)]){
			return st[1][t][a];
		}else{
			return st[1][t][b-(1<<t)];
		}
	}

	
	public static class LCAByEulerTourWithSparseTable {
		public EulerTour et;
		public int[][][] st;
		
		public LCAByEulerTourWithSparseTable(int[][] g, int root)
		{
			et = edgedEulerTour(g, root);
			st = buildP(et.deps);
		}
		
		public int lca(int x, int y)
		{
			int lx = et.last[x], ly = et.last[y];
			return et.vs[rmqpos(st, Math.min(lx, ly), Math.max(lx, ly)+1)];
		}
		
		public static EulerTour edgedEulerTour(int[][] g, int root)
		{
			int n = g.length;
			int[] vs = new int[2*n-1];
			int[] deps = new int[2*n-1];
			int[] first = new int[n];
			int[] last = new int[n];
			int p = 0;
			
			int[] stack = new int[n];
			int[] inds = new int[n];
			int[] sdeps = new int[n];
			int sp = 0;
			stack[sp++] = root;
			first[root] = -1;
			last[root] = 2*n-2;
			outer:
			while(sp > 0){
				int cur = stack[sp-1], ind = inds[sp-1], sdep = sdeps[sp-1];
				vs[p] = cur;
				deps[p] = sdep;
				p++;
				while(ind < g[cur].length){
					int nex = g[cur][ind++];
					if(sp-2 >= 0 && nex == stack[sp-2])continue;
					inds[sp-1] = ind;
					stack[sp] = nex;
					inds[sp] = 0;
					sdeps[sp] = sdep+1;
					first[nex] = p-1;
					sp++;
					continue outer;
				}
				inds[sp-1] = ind;
				if(cur != root)last[cur] = p-1;
				sp--;
			}
			
			return new EulerTour(vs, first, last, deps);
		}
		
		public static class EulerTour
		{
			public int[] vs; // vertices
			public int[] first; // first appeared time
			public int[] last; // last appeared time
			public int[] deps;
			
			public EulerTour(int[] vs, int[] f, int[] l, int[] deps) {
				this.vs = vs;
				this.first = f;
				this.last = l;
				this.deps = deps;
			}
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
	
	public static void main(String[] args) throws Exception { new E8().run(); }
	
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