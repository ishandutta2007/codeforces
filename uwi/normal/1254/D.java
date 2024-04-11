//package round601;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	// 1505
	void solve()
	{
		int n = ni(), Q = ni();
		int[] from = new int[n - 1];
		int[] to = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			from[i] = ni() - 1;
			to[i] = ni() - 1;
		}
		int[][] g = packU(n, from, to);
		int[][] pars = parents3(g, 0);
		int[] par = pars[0], ord = pars[1], dep = pars[2];
		
		HeavyLightDecomposition hld = new HeavyLightDecomposition(g, par, ord, dep);
		
		int[] des = new int[n];
		Arrays.fill(des, 1);
		for(int i = n-1;i >= 1;i--){
			des[par[ord[i]]] += des[ord[i]];
		}
		long il = invl(n, mod);
		int[][] rights = makeRights(g, par, 0);
		int[] right = rights[2], iord = rights[1];
		
		long[][] fts = new long[hld.m][];
		for(int i = 0;i < hld.m;i++){
			fts[i] = new long[hld.cluspath[i].length+3];
		}
		long[] ftd = new long[n+3];
		long[] full = new long[n];
		
		for(int z = 0;z < Q;z++){
			int t = ni();
			if(t == 1){
				int v = ni()-1;
				long D = ni();
				
				addFenwick(ftd, 0, iord[v], (des[v])*D);
				addFenwick(ftd, right[iord[v]]+1, n, (des[v])*D);
				full[v] += D;
				
				if(hld.clusiind[v]+1 < hld.cluspath[hld.clus[v]].length){
					int hv = hld.cluspath[hld.clus[v]][hld.clusiind[v]+1];
					addFenwick(fts[hld.clus[hv]], hld.clusiind[hv], (n-des[hv]) * D);
				}
			}else{
				int v = ni()-1;
				long ans = 0;
				for(int x = v;x != -1;){
					int cl = hld.clus[x];
					int ind = hld.clusiind[x];
					ans += sumFenwick(fts[cl], ind);
					x = par[hld.cluspath[cl][0]];
					if(x != -1){
						ans += full[x] % mod * (n-des[hld.cluspath[cl][0]]);
						ans %= mod;
					}
				}
				ans += sumFenwick(ftd, iord[v]);
				ans = ans % mod * il + full[v];
				ans %= mod;
				out.println(ans);
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

	
	public static long invl(long a, long mod) {
		long b = mod;
		long p = 1, q = 0;
		while (b > 0) {
			long c = a / b;
			long d;
			d = a;
			a = b;
			b = d % b;
			d = p;
			p = q;
			q = d - c * q;
		}
		return p < 0 ? p + mod : p;
	}

	
	public static final int mod = 998244353;
	
	static long sumFenwick(long[] ft, int l, int r)
	{
		long v = sumFenwick(ft, r-1) - sumFenwick(ft, l-1);
		if(v < 0)v += mod;
		return v;
	}
	
	public static long sumFenwick(long[] ft, int i)
	{
		long sum = 0;
		for(i++;i > 0;i -= i&-i){
			sum += ft[i];
			if(sum >= mod)sum -= mod;
		}
		return sum;
	}
	
	static void addFenwick(long[] ft, int l, int r, long v)
	{
		addFenwick(ft, l, v);
		addFenwick(ft, r, -v);
	}
	
	public static void addFenwick(long[] ft, int i, long v)
	{
		v %= mod;
		if(v < 0)v += mod;
		if(v == 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i){
			ft[i] += v;
			if(ft[i] >= mod)ft[i] -= mod;
		}
	}
	
	public static long[] restoreFenwick(long[] ft)
	{
		int n = ft.length-1;
		long[] ret = new long[n];
		for(int i = 0;i < n;i++)ret[i] = sumFenwick(ft, i);
		for(int i = n-1;i >= 1;i--){
			ret[i] -= ret[i-1];
			if(ret[i] < 0)ret[i] += mod;
		}
		return ret;
	}

	
	public static class HeavyLightDecomposition {
		public int[][] g;
		public int[] clus;
		public int[][] cluspath;
		public int[] clusiind;
		public int[] par, dep;
		public int m;
		
		public HeavyLightDecomposition(int[][] g, int[] par, int[] ord, int[] dep)
		{
			init(g, par, ord, dep);
		}
		
		public void init(int[][] g, int[] par, int[] ord, int[] dep)
		{
			clus = decomposeToHeavyLight(g, par, ord);
			cluspath = clusPaths(clus, ord);
			clusiind = clusIInd(cluspath, g.length);
			this.m = cluspath.length;
			this.par = par;
			this.dep = dep;
			this.g = g;
		}
		
		public static int[] decomposeToHeavyLight(int[][] g, int[] par, int[] ord)
		{
			int n = g.length;
			int[] size = new int[n];
			Arrays.fill(size, 1);
			for(int i = n-1;i > 0;i--)size[par[ord[i]]] += size[ord[i]];
			
			int[] clus = new int[n];
			Arrays.fill(clus, -1);
			int p = 0;
			for(int i = 0;i < n;i++){
				int u = ord[i];
				if(clus[u] == -1)clus[u] = p++;
				// centroid path (not heavy path)
				int argmax = -1;
				for(int v : g[u]){
					if(par[u] != v && (argmax == -1 || size[v] > size[argmax]))argmax = v;
				}
				if(argmax != -1)clus[argmax] = clus[u];
			}
			return clus;
		}
		
		public static int[][] clusPaths(int[] clus, int[] ord)
		{
			int n = clus.length;
			int[] rp = new int[n];
			int sup = 0;
			for(int i = 0;i < n;i++){
				rp[clus[i]]++;
				sup = Math.max(sup, clus[i]);
			}
			sup++;
			
			int[][] row = new int[sup][];
			for(int i = 0;i < sup;i++)row[i] = new int[rp[i]];
			
			for(int i = n-1;i >= 0;i--){
				row[clus[ord[i]]][--rp[clus[ord[i]]]] = ord[i];
			}
			return row;
		}
		
		public static int[] clusIInd(int[][] clusPath, int n)
		{
			int[] iind = new int[n];
			for(int[] path : clusPath){
				for(int i = 0;i < path.length;i++){
					iind[path[i]] = i;
				}
			}
			return iind;
		}
		
		public int lca(int x, int y)
		{
			int rx = cluspath[clus[x]][0];
			int ry = cluspath[clus[y]][0];
			while(clus[x] != clus[y]){
				if(dep[rx] > dep[ry]){
					x = par[rx];
					rx = cluspath[clus[x]][0];
				}else{
					y = par[ry];
					ry = cluspath[clus[y]][0];
				}
			}
			return clusiind[x] > clusiind[y] ? y : x;
		}
		
		public int ancestor(int x, int v)
		{
			while(x != -1){
				if(v <= clusiind[x])return cluspath[clus[x]][clusiind[x]-v];
				v -= clusiind[x]+1;
				x = par[cluspath[clus[x]][0]];
			}
			return x;
		}
		
		// [iord[x], right[x])
		public int[][] makeRights()
		{
			int root = -1;
			int n = g.length;
			for(int i = 0;i < n;i++)if(par[i] == -1)root = i;
			
			int[] ord = new int[n];
			int[] right = new int[n];
			
			int[] curs = new int[n];
			int[] inds = new int[n];
			int sp = 0, p = 0;
			curs[sp++] = root;
			while(sp > 0){
				int cur = curs[sp-1];
				int ind = inds[sp-1];
				inds[sp-1]++;
				if(ind == 0){
					ord[p++] = cur;
					for(int e : g[cur]){
						if(par[cur] == e)continue;
						if(clus[cur] == clus[e]){
							curs[sp] = e;
							inds[sp] = 0;
							sp++;
							break;
						}
					}
				}else if(ind-1 < g[cur].length){
					int e = g[cur][ind-1];
					if(e == par[cur])continue;
					if(clus[cur] == clus[e])continue;
					curs[sp] = e;
					inds[sp] = 0;
					sp++;
				}else{
					right[cur] = p;
					sp--;
				}
			}
			int[] iord = new int[n];
			for(int i = 0;i < n;i++)iord[ord[i]] = i;
			return new int[][]{ord, iord, right};
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
	
	public static void main(String[] args) throws Exception { new D3().run(); }
	
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