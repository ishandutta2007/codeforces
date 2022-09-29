//package round537;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int Q = ni();
		int[] from = new int[n - 1];
		int[] to = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			from[i] = ni() - 1;
			to[i] = ni() - 1;
		}
		int[][] g = packU(n, from, to);
		int[][] pars = parents3(g, 0);
		int[] par = pars[0], ord = pars[1], dep = pars[2];
		
		int[][] spar = logstepParents(par);
		EulerTour et = nodalEulerTour(g, 0);
		
		int mod = 1000000007;
		int[] ft = new int[2*n+5];
		for(int z = 0;z < Q;z++){
			int K = ni(), M = ni(), R = ni()-1;
			int[] qs = na(K);
			for(int i = 0;i < K;i++)qs[i]--;
			
			int[][] qsi = new int[K][];
			for(int i = 0;i < K;i++){
				qsi[i] = new int[]{qs[i], d(qs[i], R, spar, dep)};
			}
			Arrays.sort(qsi, new Comparator<int[]>() {
				public int compare(int[] a, int[] b) {
					return a[1] - b[1];
				}
			});
			for(int i = 0;i < K;i++)qs[i] = qsi[i][0];

			
			long[] dp = new long[M+1];
			dp[0] = 1;
			for(int q : qs){
				int v = num1(q, R, ft, et, spar, dep);
				for(int i = M;i >= v;i--){
					if(i+1 <= M){
						dp[i+1] += dp[i];
						if(dp[i+1] >= mod)dp[i+1] -= mod;
					}
					dp[i] = dp[i] * (i-v) % mod;
				}
				
				addFenwick(ft, et.first[q], 1);
				addFenwick(ft, et.last[q], -1);
			}
			long ans = 0;
			for(int i = 0;i <= M;i++){
				ans += dp[i];
			}
			out.println(ans%mod);
			for(int q : qs){
				addFenwick(ft, et.first[q], -1);
				addFenwick(ft, et.last[q], 1);
			}
		}
	}
	
	static int d(int a, int b, int[][] spar, int[] dep)
	{
		int lca = lca2(a, b, spar, dep);
		return dep[a] + dep[b] - dep[lca]*2;
	}
	
	static int num1(int a, int b, int[] ft, EulerTour et, int[][] spar, int[] dep)
	{
		int lca = lca2(a, b, spar, dep);
		int ret = 
		sumFenwick(ft, et.first[a]) - sumFenwick(ft, et.first[lca]) +
		sumFenwick(ft, et.first[b]) - sumFenwick(ft, et.first[lca]-1);
		return ret;
	}
	
	public static int sumFenwick(int[] ft, int i)
	{
		int sum = 0;
		for(i++;i > 0;i -= i&-i)sum += ft[i];
		return sum;
	}
	
	public static void addFenwick(int[] ft, int i, int v)
	{
		if(v == 0 || i < 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i)ft[i] += v;
	}

	
	public static class EulerTour
	{
		public int[] vs; // vertices
		public int[] first; // first appeared time
		public int[] last; // last appeared time
		
		public EulerTour(int[] vs, int[] f, int[] l) {
			this.vs = vs;
			this.first = f;
			this.last = l;
		}
	}

	
	public static EulerTour nodalEulerTour(int[][] g, int root)
	{
		int n = g.length;
		int[] vs = new int[2*n];
		int[] f = new int[n];
		int[] l = new int[n];
		int p = 0;
		Arrays.fill(f, -1);
		
		int[] stack = new int[n];
		int[] inds = new int[n];
		int sp = 0;
		stack[sp++] = root;
		outer:
		while(sp > 0){
			int cur = stack[sp-1], ind = inds[sp-1];
			if(ind == 0){
				vs[p] = cur;
				f[cur] = p;
				p++;
			}
			while(ind < g[cur].length){
				int nex = g[cur][ind++];
				if(f[nex] == -1){ // child
					inds[sp-1] = ind;
					stack[sp] = nex;
					inds[sp] = 0;
					sp++;
					continue outer;
				}
			}
			inds[sp-1] = ind;
			if(ind == g[cur].length){
				vs[p] = cur;
				l[cur] = p;
				p++;
				sp--;
			}
		}
		
		return new EulerTour(vs, f, l);
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