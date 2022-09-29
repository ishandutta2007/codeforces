//package ecr92;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;

public class G {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), K = ni();
		boolean[] spe = new boolean[n];
		for(int i = 0;i < K;i++){
			spe[ni()-1] = true;
		}
		
		int[] C = na(n);
		int[] W = na(m);
		
		int[] from = new int[m];
		int[] to = new int[m];
		for (int i = 0; i < m; i++) {
			from[i] = ni() - 1;
			to[i] = ni() - 1;
		}
		int[][] g = packU(n, from, to);
		
		int[] clus = decomposeToBECCNoRecOld(g);
		
		int[][] cgz = condense(g, clus);
		int u = cgz.length;
		Map<Long, Integer> wmap = new HashMap<>();
		for(int i = 0;i < m;i++){
			if(clus[from[i]] != clus[to[i]]){
				{
					long key = (long)clus[from[i]]<<32|clus[to[i]];
					wmap.put(key, W[i]);
				}
				{
					long key = (long)clus[to[i]]<<32|clus[from[i]];
					wmap.put(key, W[i]);
				}
			}
		}
		int[] cfrom = new int[u-1];
		int[] cto = new int[u-1];
		int[] cws = new int[u-1];
		int p = 0;
		for(int i = 0;i < u;i++){
			for(int e : cgz[i]){
				if(i < e){
					cfrom[p] = i;
					cto[p] = e;
					cws[p] = wmap.get((long)i<<32|e);
					p++;
				}
			}
		}
		int[][][] cg = packWU(u, cfrom, cto, cws);
		
		long[] CC = new long[u];
		for(int i = 0;i < n;i++){
			CC[clus[i]] += C[i];
		}
		
		boolean[] cspe = new boolean[u];
		for(int i = 0;i < n;i++){
			cspe[clus[i]] |= spe[i];
		}
		
		int[][] ps = parents(cg, 0);
		int[] par = ps[0], ord = ps[1], dep = ps[2];
		gspe = cspe;
		spesum = 0;
		for(boolean cs : cspe){
			if(cs)spesum++;
		}
		gC = CC;
//		tr(CC);
//		tr(cg);
		Datum[] res = omnidirectionalTreeDP(cg, par, ord);
		
		for(int i = 0;i < n;i++){
			out.print(res[clus[i]].max + " ");
		}
		out.println();
	}
	
	int spesum;
	long[] gC;
	boolean[] gspe;
	
	public class Datum
	{
		int nspe;
		long max; // max prefix
		
		public Datum() {
		}
		
		public Datum(int cur)
		{
			nspe = gspe[cur] ? 1 : 0;
			max = gC[cur];
		}

		@Override
		public String toString() {
			return "Datum [nspe=" + nspe + ", max=" + max + "]";
		}
	}
	
	public Datum zero = new Datum();
	
	public Datum merge(Datum a, Datum b)
	{
		Datum ret = new Datum();
		ret.nspe = a.nspe + b.nspe;
		ret.max = a.max + b.max;
		return ret;
	}
	
	public Datum promote(Datum d, int... e)
	{
		Datum ret = new Datum();
		ret.nspe = d.nspe;
		ret.max = d.nspe > 0 && d.nspe < spesum ? Math.max(0, -e[1] + d.max) : d.max;
		return ret;
	}
	
	public Datum[] omnidirectionalTreeDP(int[][][] g, int[] par, int[] ord) {
		int n = g.length;
		int root = ord[0];
		
		Datum[] dp = new Datum[n];
		
		// up
		for(int i = n-1;i >= 0;i--){
			int cur = ord[i];
			Datum ldp = new Datum(cur);
			for(int[] e : g[cur]){
				if(par[cur] == e[0])continue;
				ldp = merge(ldp, promote(dp[e[0]], e));
			}
			dp[cur] = ldp;
		}
		
		// down
		Datum[] prefix = new Datum[n+1];
		Datum[] fall = new Datum[n];
		fall[root] = zero;
		for(int i = 0;i < n;i++){
			int cur = ord[i];
			prefix[0] = zero;
			Datum suffix = merge(new Datum(cur), fall[cur]);
			for(int j = 0;j < g[cur].length;j++){
				int[] e = g[cur][j];
				prefix[j+1] = par[cur] == e[0] ? prefix[j] : merge(prefix[j], promote(dp[e[0]], e));
			}
			for(int j = 0;j < g[cur].length;j++){
				int[] e = g[cur][g[cur].length-1-j];
				if(par[cur] != e[0]){
					fall[e[0]] = promote(merge(prefix[g[cur].length-1-j], suffix), e);
				}
				suffix = par[cur] == e[0] ? suffix : merge(suffix, promote(dp[e[0]], e));
			}
		}
		
		for(int i = 0;i < n;i++){
			dp[i] = merge(fall[i], dp[i]);
		}
		return dp;
	}
	
	public static int[][] parents(int[][][] g, int root) {
		int n = g.length;
		int[] par = new int[n];
		Arrays.fill(par, -1);
		int[] dw = new int[n];
		int[] pw = new int[n];
		int[] dep = new int[n];

		int[] q = new int[n];
		q[0] = root;
		for (int p = 0, r = 1; p < r; p++) {
			int cur = q[p];
			for (int[] nex : g[cur]) {
				if (par[cur] != nex[0]) {
					q[r++] = nex[0];
					par[nex[0]] = cur;
					dep[nex[0]] = dep[cur] + 1;
					dw[nex[0]] = dw[cur] + nex[1];
					pw[nex[0]] = nex[1];
				}
			}
		}
		return new int[][] { par, q, dep, dw, pw };
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

	
	public static int[][] condense(int[][] g, int[] clus)
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
	
	
	public static int[] decomposeToBECCNoRecOld(int[][] g)
	{
		int n = g.length;
		
		// build spanning forest
		int[] ord = new int[n]; // preorder
		int[] stack = new int[n];
		int[] par = new int[n]; // parent
		boolean[] ved = new boolean[n];
		int r = 0;
		for(int i = 0;i < n;i++){
			if(!ved[i]){
				stack[0] = i;
				par[i] = -1;
				ved[i] = true;
				int p = 1; // stack pointer
				while(p > 0){
					int cur = stack[p-1];
					ord[r++] = cur;
					p--;
					for(int e : g[cur]){
						if(!ved[e]){
							stack[p++] = e;
							par[e] = cur;
							ved[e] = true;
						}
					}
				}
			}
		}
		
		int[] ccstack = new int[n];
		int cp = 0;
		
		int[] iord = new int[n];
		for(int i = 0;i < n;i++)iord[ord[i]] = i;
		
		int[] ND = new int[n];
		int[] L = new int[n];
		int[] H = new int[n];
		int[] clus = new int[n];
		Arrays.fill(clus, -1);
		int clp = 0;
		
		for(int i = n-1;i >= 0;i--){
			int cur = ord[i];
			ccstack[cp++] = i;
			if(par[cur] == -1)continue;
			int ll = i;
			int lh = i;
			int pe = -1;
			ND[cur]++;
			for(int e : g[cur]){
				if(par[cur] == e && pe == -1){
					pe = 0;
					continue;
				}
				
				if(par[e] == cur){
					ll = Math.min(ll, L[e]);
					lh = Math.max(lh, H[e]);
				}else{
					ll = Math.min(ll, iord[e]);
					lh = Math.max(lh, iord[e]);
				}
			}
			L[cur] = ll;
			H[cur] = lh;
			if(L[cur] == i && H[cur] < i+ND[cur]){
				while(cp >= 1 && ccstack[cp-1] >= L[cur] && ccstack[cp-1] <= H[cur]){
					clus[ord[ccstack[--cp]]] = clp;
				}
				clp++;
			}
			ND[par[cur]] += ND[cur];
		}
		
		while(cp >= 1){
			clus[ord[ccstack[--cp]]] = clp;
		}
		
		return clus;
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
	
	public static void main(String[] args) throws Exception { new G().run(); }
	
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