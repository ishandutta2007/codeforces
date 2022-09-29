//package round411;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), Q = ni();
		int[] from = new int[n];
		int[] to = new int[n];
		DJSet ds = new DJSet(n);
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
			ds.union(from[i], to[i]);
		}
		
		int p = m;
		for(int i = 0;i < n;i++){
			if(ds.upper[i] < 0){
				from[p] = i;
				to[p] = n;
				p++;
			}
		}
		int[][] g = packU(n+1, from, to);
		int[][] pars = parents3(g, n);
		int[] par = pars[0], ord = pars[1], dep = pars[2];
		int[][] spar = logstepParents(par);
		
		ds = new DJSet(n);
		int[] da = new int[n];
		int[] db = new int[n];
		for(int i = 0;i < n;i++)da[i] = i;
		for(int i = 0;i < n;i++)db[i] = i;
		int[] as = new int[2];
		int[] bs = new int[2];
		for(int i = 0;i < m;i++){
			as[0] = da[ds.root(from[i])];
			bs[0] = db[ds.root(from[i])];
			as[1] = da[ds.root(to[i])];
			bs[1] = db[ds.root(to[i])];
			int max = -1;
			int aa = -1, ab = -1;
			for(int la : as){
				for(int lb : bs){
					int d = d(la, lb, spar, dep);
					if(d > max){
						max = d;
						aa = la; ab = lb;
					}
				}
			}
			ds.union(from[i], to[i]);
			da[ds.root(from[i])] = aa;
			db[ds.root(from[i])] = ab;
		}
		int[][] df = new int[n][];
		for(int i = 0;i < n;i++){
			if(ds.upper[i] < 0){
				df[i] = new int[-ds.upper[i]];
			}
		}
		
		for(int i = 0;i < n;i++){
			int root = ds.root(i);
			int d = Math.max(d(i, da[root], spar, dep), d(i, db[root], spar, dep));
			df[root][d]++;
		}
		long[][] wdf = new long[n][];
		for(int i = 0;i < n;i++){
			if(df[i] != null){
				wdf[i] = new long[df[i].length+1];
				for(int j = 0;j < df[i].length;j++){
					wdf[i][j+1] = wdf[i][j] + (long)j*df[i][j];
				}
			}
		}
		int[][] cdf = new int[n][];
		for(int i = 0;i < n;i++){
			if(df[i] != null){
				cdf[i] = new int[df[i].length+1];
				for(int j = 0;j < df[i].length;j++){
					cdf[i][j+1] = cdf[i][j] + df[i][j];
				}
			}
		}
//		for(int i = 0;i < n;i++){
//			if(df[i] != null){
//				tr(i);
//				tr(df[i]);
//				tr(cdf[i]);
//				tr(wdf[i]);
//			}
//		}
		
		Map<Long, Double> cache = new HashMap<>();
		for(int z = 0;z < Q;z++){
			int x = ni()-1, y = ni()-1;
			if(ds.equiv(x, y)){
				out.println(-1);
			}else{
				int rx = ds.root(x);
				int ry = ds.root(y);
				if(df[rx].length > df[ry].length){
					int d = rx; rx = ry; ry = d;
				}
				long code = (long)rx<<32|ry;
				if(!cache.containsKey(code)){
					int dmax = Math.max(
							d(da[rx], db[rx], spar, dep), 
							d(da[ry], db[ry], spar, dep)
									);
					long num = 0;
					for(int j = 0;j < df[rx].length;j++){
						int k = dmax - j - 1;
//						tr(j, k, dmax);
//						tr(num);
						if(k < df[ry].length){
							num += 
							df[rx][j] * (wdf[ry][wdf[ry].length-1] - (k >= 0 ? wdf[ry][k] : 0)
									 + (long)(j+1) * (cdf[ry][cdf[ry].length-1] - (k >= 0 ? cdf[ry][k] : 0))
									 );
						}
//						tr(num);
						if(k >= 0){
							num += (long)cdf[ry][Math.min(k, cdf[ry].length-1)] * df[rx][j] * dmax;
						}
//						tr(num);
					}
					double E = num / (double)ds.upper[rx] / (double)ds.upper[ry];
					cache.put(code, E);
				}
				out.printf("%.14f\n", cache.get(code));
			}
		}
	}
	
	int d(int x, int y, int[][] spar, int[] dep)
	{
		int lca = lca2(x, y, spar, dep);
		return dep[x] + dep[y] - 2*dep[lca];
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