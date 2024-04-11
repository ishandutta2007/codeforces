//package round426;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	static int mod = 1000000007;
	
	// 0418
	
	void solve()
	{
		int n = ni();
		int[] from = new int[n - 1];
		int[] to = new int[n - 1];
		int[] w = new int[n-1];
		int[] color = new int[n-1];
		for (int i = 0; i < n - 1; i++) {
			from[i] = ni() - 1;
			to[i] = ni() - 1;
			w[i] = ni();
			color[i] = ni();
		}
		int[][][] g = packWU(n, from, to, w, color);
		int[][] pars = parents(g, 0);
		int[] par = pars[0], ord = pars[1], dep = pars[2];
		
		int[] cpar = buildCentroidTree(g);
		CentroidTreeDistancePreordersSimple ctdps = dfsTopCTDPS(cpar, g);
		long ans = 1;
		for(int i = 0;i < n;i++){
			long[] u = concatx(ctdps.gds[i]);
			u[0] = 1;
			ans = ans * go(u, concatx(ctdps.gdreds[i]), concatx(ctdps.gdblas[i]));
			ans %= mod;
			long div = 1;
			for(int j = 0;j < ctdps.gds[i].length;j++){
				long res = go(ctdps.gds[i][j], ctdps.gdreds[i][j], ctdps.gdblas[i][j]);
				div = div * res % mod;
			}
			ans = ans * invl(div, mod) % mod;
		}
		out.println(ans);
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

	
	long go(long[] ds, int[] red, int[] black)
	{
//		tr(ds, red, black);
		int n = ds.length;
		long[][] es = new long[n][];
		int maxv = 0, minv = 0;
		for(int i = 0;i < n;i++){
			es[i] = new long[]{2*red[i]-black[i], 2*black[i]-red[i], ds[i]};
			maxv = Math.max(maxv, 2*black[i]-red[i]);
			minv = Math.min(minv, 2*black[i]-red[i]);
		}
		Arrays.sort(es, new Comparator<long[]>() {
			public int compare(long[] a, long[] b) {
				return Long.compare(a[0], b[0]);
			}
		});
		long[] ft = new long[maxv-minv + 5];
		Arrays.fill(ft, 1);
		
		long ans = 1;
		int p = n-1;
		for(int i = 0;i < n;i++){
			while(p >= 0 && es[p][0] + es[i][0] >= 0){
				mulFenwick(ft, maxv-(int)es[p][1], es[p][2]);
				p--;
			}
			ans = ans * prodFenwick(ft, Math.min(ft.length - 2, maxv+(int)es[i][1])) % mod;
		}
//		tr("ans", ans);

		return ans;
	}
	
	public static long prodFenwick(long[] ft, int i)
	{
		long sum = 1;
		for(i++;i > 0;i -= i&-i){
			sum = sum * ft[i] % mod;
		}
		return sum;
	}
	
	public static void mulFenwick(long[] ft, int i, long v)
	{
		v %= mod;
		if(v < 0)v += mod;
		int n = ft.length;
		for(i++;i < n;i += i&-i){
			ft[i] = ft[i] * v % mod;
		}
	}

	
	static long[] concatx(long[]... s)
	{
		int n = 1;
		for(long[] u : s)n += u.length;
		long[] ret = new long[n];
		n = 1;
		for(long[] u : s){
			System.arraycopy(u, 0, ret, n, u.length);
			n += u.length;
		}
		return ret;
	}
	
	static int[] concatx(int[]... s)
	{
		int n = 1;
		for(int[] u : s)n += u.length;
		int[] ret = new int[n];
		n = 1;
		for(int[] u : s){
			System.arraycopy(u, 0, ret, n, u.length);
			n += u.length;
		}
		return ret;
	}
	
	public static class CentroidTreeDistancePreordersSimple
	{
		public int root; // root of centroid tree
		public int[][] ctch; // centroid tree children
		public long[][][] gds; // gds[sep][neckind][i]=(distances subject to separator sep + neckind)
		public int[][][] gdreds; // gds[sep][neckind][i]=(distances subject to separator sep + neckind)
		public int[][][] gdblas; // gds[sep][neckind][i]=(distances subject to separator sep + neckind)
		public int[] dep; // depth of separator in centroid tree
		public int[] neckind; // neck[x]=(y which gds[cpar[x]][y] represents distances of separator x's zone)
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

	
	public CentroidTreeDistancePreordersSimple dfsTopCTDPS(int[] cpar, int[][][] g) {
		int n = g.length;
		int ctroot = -1;
		for(int i = 0;i < n;i++)if(cpar[i] == -1)ctroot = i;
		int[][] ctch = parentToChildren(cpar);
		long I = Long.MAX_VALUE / 2;
		int J = Integer.MAX_VALUE / 2;
		long[] dd = new long[n];
		Arrays.fill(dd, I);
		int[] dredd = new int[n];
		Arrays.fill(dredd, J);
		int[] dblad = new int[n];
		Arrays.fill(dblad, J);
		long[][][] gds = new long[n][][];
		int[][][] gdreds = new int[n][][];
		int[][][] gdblas = new int[n][][];
		int[] gdep = new int[n];
		int[] gneckind = new int[n];
		Arrays.fill(gneckind, -1);
		dfs(ctroot, new boolean[n], 
				new long[n], new long[n][], dd, gds,
				new int[n], new int[n][], dredd, gdreds,
				new int[n], new int[n][], dblad, gdblas,
				new int[n], new int[n], gneckind, gdep, g, ctch, cpar);
		CentroidTreeDistancePreordersSimple ret = new CentroidTreeDistancePreordersSimple();
		ret.gds = gds;
		ret.gdreds = gdreds;
		ret.gdblas = gdblas;
		ret.ctch = ctch;
		ret.dep = gdep;
		ret.neckind = gneckind;
		ret.root = ctroot;
		return ret;
	}
	
	private void dfs(int sep, boolean[] seps, 
			long[] ds, long[][] dss, long[] dd, long[][][] gds,
			int[] dreds, int[][] dredss, int[] dredd, int[][][] gdreds,
			int[] dblas, int[][] dblass, int[] dblad, int[][][] gdblas,
			int[] stack, int[] inds, int[] gneckind, int[] gdep,
			int[][][] g, int[][] ctch, int[] cpar)
	{
		long I = Long.MAX_VALUE / 2;
		int J = Integer.MAX_VALUE / 2;
		seps[sep] = true;
		int neckp = 0;
		for(int[] neck : g[sep]){
			if(seps[neck[0]])continue;
			int sp = 0;
			inds[sp] = 0;
			stack[sp++] = neck[0];
			int gdp = 0;
			dd[neck[0]] = neck[1];
			dredd[neck[0]] = neck[2]^1;
			dblad[neck[0]] = neck[2];
			while(sp > 0){
				int cur = stack[sp-1];
				if(inds[sp-1] == 0){
					if(cpar[cur] == sep)gneckind[cur] = neckp;
					dreds[gdp] = dredd[cur];
					dblas[gdp] = dblad[cur];
					ds[gdp++] = dd[cur];
				}
				if(inds[sp-1] == g[cur].length){
					sp--; 
					dd[cur] = I;
					dredd[cur] = J;
					dblad[cur] = J;
					continue; 
				}
				int[] e = g[cur][inds[sp-1]++];
				if(!seps[e[0]] && dd[e[0]] == I){
					dd[e[0]] = dd[cur] * e[1] % mod;
					dredd[e[0]] = dredd[cur] + (e[2]^1);
					dblad[e[0]] = dblad[cur] + (e[2]);
					stack[sp] = e[0];
					inds[sp] = 0;
					sp++;
				}
			}
			dredss[neckp] = Arrays.copyOf(dreds, gdp);
			dblass[neckp] = Arrays.copyOf(dblas, gdp);
			dss[neckp++] = Arrays.copyOf(ds, gdp);
		}
		gdreds[sep] = Arrays.copyOf(dredss, neckp);
		gdblas[sep] = Arrays.copyOf(dblass, neckp);
		gds[sep] = Arrays.copyOf(dss, neckp);
		
		for(int e : ctch[sep]){
			gdep[e] = gdep[sep] + 1;
			dfs(e, seps, 
					ds, dss, dd, gds,
					dreds, dredss, dredd, gdreds,
					dblas, dblass, dblad, gdblas,
					stack, inds, gneckind, gdep, g, ctch, cpar);
		}
		seps[sep] = false;
	}

	
	public static int[] buildCentroidTree(int[][][] g) {
		int n = g.length;
		int[] ctpar = new int[n];
		Arrays.fill(ctpar, -1);
		buildCentroidTree(g, 0, new boolean[n], new int[n], new int[n], new int[n], ctpar);
		return ctpar;
	}
	
	private static int buildCentroidTree(int[][][] g, int root, boolean[] sed, int[] par, int[] ord, int[] des, int[] ctpar)
	{
		// parent and level-order
		ord[0] = root;
		par[root] = -1;
		int r = 1;
		for(int p = 0;p < r;p++) {
			int cur = ord[p];
			for(int[] nex : g[cur]){
				if(par[cur] != nex[0] && !sed[nex[0]]){
					ord[r++] = nex[0];
					par[nex[0]] = cur;
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
			for(int[] e : g[cur]){
				if(par[cur] != e[0] && !sed[e[0]])des[cur] += des[e[0]];
			}
			if(r-des[cur] <= r/2){
				for(int[] e : g[cur]){
					if(par[cur] != e[0] && !sed[e[0]] && des[e[0]] >= r/2+1)continue outer;
				}
				sep = cur;
				break;
			}
		}
		
		sed[sep] = true;
		for(int[] e : g[sep]){
			if(!sed[e[0]])ctpar[buildCentroidTree(g, e[0], sed, par, ord, des, ctpar)] = sep;
		}
		return sep;
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

	
	public static int[][][] packWU(int n, int[] from, int[] to, int[]... ws){ return packWU(n, from, to, from.length, ws); }
	public static int[][][] packWU(int n, int[] from, int[] to, int sup, int[]... ws)
	{
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for(int i = 0;i < sup;i++)p[from[i]]++;
		for(int i = 0;i < sup;i++)p[to[i]]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]][ws.length+1];
		for(int i = 0;i < sup;i++){
			--p[from[i]];
			g[from[i]][p[from[i]]][0] = to[i];
			for(int j = 0;j < ws.length;j++)g[from[i]][p[from[i]]][j+1] = ws[j][i];
			--p[to[i]];
			g[to[i]][p[to[i]]][0] = from[i];
			for(int j = 0;j < ws.length;j++)g[to[i]][p[to[i]]][j+1] = ws[j][i];
		}
		return g;
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