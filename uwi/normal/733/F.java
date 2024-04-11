//package round378;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class FX {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] ws = na(m);
		int[] cs = na(m);
		int[][] es = new int[m][];
		for(int i = 0;i < m;i++){
			es[i] = new int[]{ni()-1, ni()-1, ws[i], cs[i], i};
		}
		int K = ni();
		Arrays.sort(es, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[2] - b[2];
			}
		});
		DJSet ds = new DJSet(n);
		int[] from = new int[n-1];
		int[] to = new int[n-1];
		int[] w = new int[n-1];
		int p = 0;
		long wsum = 0;
		boolean[] intr = new boolean[m];
		for(int i = 0;i < m;i++){
			int[] e = es[i];
			tr(e);
			if(!ds.union(e[0], e[1])){
				from[p] = e[0];
				to[p] = e[1];
				w[p] = -e[2];
				intr[e[4]] = true;
				wsum += e[2];
				p++;
			}
		}
		assert p == n-1;
		Arrays.sort(es, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[4] - b[4];
			}
		});
		
		int[][][] g = packWU(n, from, to, w);
		int[][] pars = parents(g, 0);
		int[] par = pars[0], ord = pars[1], dep = pars[2], pw = pars[4];
		int[][] spar = logstepParents(par);
		int[][] smin = logstepArgmins(spar, pw);
		
		long ret = Long.MAX_VALUE;
		int arg = -1;
		int arg2 = -1;
		for(int i = 0;i < m;i++){
			int[] e = es[i];
			int lca = lca2(e[0], e[1], spar, dep);
			int a0 = argmin(e[0], lca, spar, smin, pw, dep);
			int a1 = argmin(e[1], lca, spar, smin, pw, dep);
			int lmin = Integer.MAX_VALUE;
			int larg = -1;
			if(a0 != -1){
				if(pw[a0] < lmin){
					lmin = pw[a0];
					larg = a0;
				}
			}
			if(a1 != -1){
				if(pw[a1] < lmin){
					lmin = pw[a1];
					larg = a1;
				}
			}
			long val = wsum + lmin + e[2] - K/e[3];
			if(val < ret){
				ret = val;
				arg = i;
				arg2 = larg;
			}
		}
		int arg2par = par[arg2];
		
		out.println(ret);
		out.println((arg+1) + " " + (es[arg][2] - K/es[arg][3]));
		for(int i = 0;i < m;i++){
			if(intr[i] && !(es[i][0] == arg2 && es[i][1] == arg2par) && !(es[i][0] == arg2par && es[i][1] == arg2)){
				out.println((i+1) + " " + es[i][2]);
			}
		}
	}
	
	public static int argmin(int a, int b, int[][] spar, int[][] sargmin, int[] v, int[] dep)
	{
		if(a == b)return -1;
		int cur = a;
		int min = v[a];
		int arg = a;
		for(int i = dep[a] - dep[b], k = 0;i > 0;i /= 2, k++){
			if((i&1)==1){
				int lv = v[sargmin[k][cur]];
				if(lv < min){
					min = lv;
					arg = sargmin[k][cur];
				}
				cur = spar[k][cur];
			}
		}
		return arg;
	}
	
	public static int[][] logstepArgmins(int[][] sp, int[] pw)
	{
		int m = sp.length;
		int n = sp[0].length;
		int[][] mins = new int[m][n];
		for(int i = 0;i < n;i++){
			mins[0][i] = i;
		}
		for(int j = 1;j < m;j++){
			for(int i = 0;i < n;i++){
				if(sp[j-1][i] != -1){
					int lower = mins[j-1][i];
					int upper = mins[j-1][sp[j-1][i]];
					if(upper == -1 || pw[lower] < pw[upper]){
						mins[j][i] = lower;
					}else{
						mins[j][i] = upper;
					}
				}else{
					mins[j][i] = -1;
				}
			}
		}
		return mins;
	}

	
	public static int lca2(int a, int b, int[][] spar, int[] depth) {
		if (depth[a] < depth[b]) {
			b = ancestor(b, depth[b] - depth[a], spar);
		} else if (depth[a] > depth[b]) {
			a = ancestor(a, depth[a] - depth[b], spar);
		}

		if (a == b)
			return a;
		for(int d = 31-Integer.numberOfLeadingZeros(depth[a]);d >= 0;d--){
			if(spar[d][a] != spar[d][b]){
				a = spar[d][a];
				b = spar[d][b];
			}
		}
		return spar[0][a];
	}

	protected static int ancestor(int a, int m, int[][] spar) {
		for(;m > 0 && a != -1;m &= m-1)a = spar[Integer.numberOfTrailingZeros(m)][a];
		return a;
	}
	
	// Is shal ancestor of deep?
	public static boolean isAncestor(int shal, int deep, int[][] spar, int[] dep)
	{
		return dep[shal] <= dep[deep] && ancestor(deep, dep[deep] - dep[shal], spar) == shal;
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
	
	public static void main(String[] args) throws Exception { new FX().run(); }
	
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