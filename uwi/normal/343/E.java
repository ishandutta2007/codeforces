//package round200;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		int[] w = new int[m];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
			w[i] = ni();
		}
		
		int[][][] g = packWU(n, from, to, w);
		int[][] ps = buildGomoryHuTreeSimple(g);
		int[] par = ps[0];
		int[] pw = ps[1];
		
		int[][] es = new int[n-1][];
		int p = 0;
		for(int i = 0;i < n;i++){
			if(par[i] != -1){
				es[p++] = new int[]{i, par[i], pw[i]};
			}
		}
		
		Arrays.sort(es, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[2] - b[2];
			}
		});
		
		int[][] ords = new int[n][];
		for(int i = 0;i < n;i++)ords[i] = new int[]{i+1};
		
		DJSet ds = new DJSet(n);
		int ret = 0;
		for(int i = n-2;i >= 0;i--){
			int l = es[i][0], r = es[i][1];
			int[] lo = ords[ds.root(l)], ro = ords[ds.root(r)];
			int[] merged = Arrays.copyOf(lo, lo.length + ro.length);
			System.arraycopy(ro, 0, merged, lo.length, ro.length);
			ds.union(l, r);
			ret += es[i][2];
			ords[ds.root(l)] = merged;
		}
		out.println(ret);
		int[] last = ords[ds.root(0)];
		for(int i = 0;i < n;i++){
			if(i > 0)out.print(" ");
			out.print(last[i]);
		}
		out.println();
	}
	
	public static int[][] buildGomoryHuTreeSimple(int[][][] g)
	{
		int n = g.length;
		int[] par = new int[n];
		par[0] = -1;
		int[] pw = new int[n];
		int[][][] pre = prepare(g);
		int[][] ig = pre[0];
		int[][] gind = pre[1];
		int[][] igind = pre[2];
		int[] d = new int[n];
		int[] fq = new int[n];
		
		for(int i = 1;i < n;i++){
			Flow flow = maximumFlowDinicRecycling(g, i, par[i], ig, gind, igind, d, fq);
			int[] mincut = mincut(flow, i, g);
			for(int j : mincut){
				if(j > i && par[j] == par[i])par[j] = i;
			}
			pw[i] = (int)flow.maximum;
		}
		return new int[][]{par, pw};
	}
	
	public static class DJSet { public int[] upper; public DJSet(int n){ upper = new int[n]; Arrays.fill(upper, -1);} public int root(int x){	return upper[x] < 0 ? x : (upper[x] = root(upper[x]));}	public boolean equiv(int x, int y){ return root(x) == root(y);} public boolean union(int x, int y){ x = root(x);y = root(y);if(x != y) { if(upper[y] < upper[x]) { int d = x; x = y; y = d;	} upper[x] += upper[y]; upper[y] = x;} return x == y;} public int count(){ int ct = 0; for(int u : upper)if(u < 0)ct++; return ct; }}
	
	public static int[][][] packWU(int n, int[] from, int[] to, int[] w) {
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for(int f : from)
			p[f]++;
		for(int t : to)
			p[t]++;
		for(int i = 0;i < n;i++)
			g[i] = new int[p[i]][2];
		for(int i = 0;i < from.length;i++){
			--p[from[i]];
			g[from[i]][p[from[i]]][0] = to[i];
			g[from[i]][p[from[i]]][1] = w[i];
			--p[to[i]];
			g[to[i]][p[to[i]]][0] = from[i];
			g[to[i]][p[to[i]]][1] = w[i];
		}
		return g;
	}
	
	public static int[][][] prepare(int[][][] g){
		int n = g.length;
		// unweighted invgraph
		int[] p = new int[n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < g[i].length;j++)p[g[i][j][0]]++;
		}
		int[][] ig = new int[n][];
		for(int i = 0;i < n;i++)ig[i] = new int[p[i]];
		for(int i = n-1;i >= 0;i--){
			for(int j = 0;j < g[i].length;j++){
				ig[g[i][j][0]][--p[g[i][j][0]]] = i;
			}
		}
		
		int[][] gind = new int[n][];
		for(int i = 0;i < n;i++)gind[i] = new int[g[i].length];
		int[] gp = new int[n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < g[i].length;j++)gind[i][j] = gp[g[i][j][0]]++;
		}
		
		int[][] igind = new int[n][];
		for(int i = 0;i < n;i++)igind[i] = new int[ig[i].length];
		int[] igp = new int[n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < ig[i].length;j++)igind[i][j] = igp[ig[i][j]]++;
		}
		
		return new int[][][]{ig, gind, igind};
	}
	
	static int[] mincut(Flow flow, int src, int[][][] g)
	{
		int n = g.length;
		int[] q = new int[n];
		boolean[] ved = new boolean[n];
		int p = 0;
		q[p++] = src;
		ved[src] = true;
		for(int r = 0;r < p;r++){
			int cur = q[r];
			for(int i = 0;i < flow.F[cur].length;i++){
				if(flow.F[cur][i] < g[cur][i][1] && !ved[g[cur][i][0]]){
					ved[g[cur][i][0]] = true;
					q[p++] = g[cur][i][0];
				}
			}
		}
		return Arrays.copyOf(q, p);
	}
	
	static class Flow
	{
		long maximum;
		int[][] F;
		
		public Flow(long maximum, int[][] f) {
			this.maximum = maximum;
			F = f;
		}
	}
	
	public static Flow maximumFlowDinicRecycling(int[][][] g, int source, int sink, int[][] ig, int[][] gind, int[][] igind, int[] d, int[] q)
	{
		int n = g.length;
		
		int[][] F = new int[n][];
		for(int i = 0;i < n;i++)F[i] = new int[g[i].length];
		
		int[][] iF = new int[n][];
		for(int i = 0;i < n;i++)iF[i] = new int[ig[i].length];
		
		long ret = 0;
		while(true){
			Arrays.fill(d, -1);
			q[0] = source;
			int r = 1;
			d[source] = 0;
			
			for(int v = 0;v < r;v++){
				int cur = q[v];
				// plus flow
				for(int i = 0;i < g[cur].length;i++){
					int[] ne = g[cur][i];
					int nex = ne[0], w = ne[1];
					if(d[nex] == -1 && w - F[cur][i] > 0) {
						q[r++] = nex;
						d[nex] = d[cur] + 1;
					}
				}
				// minus flow
				for(int i = 0;i < ig[cur].length;i++){
					int nex = ig[cur][i];
					if(d[nex] == -1 && -iF[cur][i] > 0) {
						q[r++] = nex;
						d[nex] = d[cur] + 1;
					}
				}
			}
			if(d[sink] == -1)break;
			int[] sp = new int[n];
			int[] isp = new int[n];
			for(int i = 0;i < n;i++)sp[i] = g[i].length - 1;
			for(int i = 0;i < n;i++)isp[i] = ig[i].length - 1;
			int delta;
			while((delta = dfsDinic(d, g, ig, sp, isp, F, iF, gind, igind, source, sink, Integer.MAX_VALUE)) > 0){
				ret += delta;
			}
		}
		
		return new Flow(ret, F);
	}
	
	private static int dfsDinic(int[] d, int[][][] g, int[][] ig, int[] sp, int[] isp, int[][] F, int[][] iF, int[][] gind, int[][] igind, int cur, int sink, int min)
	{
		if(cur == sink){
			return min;
		}else{
			int left = min;
			for(int i = sp[cur];i >= 0;i--){
				int[] ne = g[cur][i];
				int nex = ne[0], w = ne[1];
				if(d[nex] == d[cur]+1 && w-F[cur][i] > 0){
					int fl = dfsDinic(d, g, ig, sp, isp, F, iF, gind, igind, nex, sink, Math.min(left, w-F[cur][i]));
					if(fl > 0){
						left -= fl;
						F[cur][i] += fl;
						iF[nex][gind[cur][i]] -= fl;
						if(left == 0){
							sp[cur] = i;
							return min;
						}
					}
				}
			}
			sp[cur] = -1;
			for(int i = isp[cur];i >= 0;i--){
				int nex = ig[cur][i];
				if(d[nex] == d[cur]+1 && -iF[cur][i] > 0){
					int fl = dfsDinic(d, g, ig, sp, isp, F, iF, gind, igind, nex, sink, Math.min(left, -iF[cur][i]));
					if(fl > 0){
						iF[cur][i] += fl;
						F[nex][igind[cur][i]] -= fl;
						left -= fl;
						if(left == 0){
							isp[cur] = i;
							return min;
						}
					}
				}
			}
			isp[cur] = -1;
			return min-left;
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
	
	public static void main(String[] args) throws Exception { new E2().run(); }
	
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