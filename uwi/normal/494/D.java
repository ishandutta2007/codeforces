//package round282;
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
	static int mod = 1000000007;
	
	void solve()
	{
		int n = ni();
		int[] from = new int[n-1];
		int[] to = new int[n-1];
		int[] w = new int[n-1];
		for(int i = 0;i < n-1;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
			w[i] = ni();
		}
		
		int[][][] g = packWU(n, from, to, w);
		int[][] pars = parents(g, 0);
		int[] par = pars[0];
		int[] ord = pars[1];
		int[] dep = pars[2];
		int[] dw = pars[3];
		long[] s2 = new long[n];
		long[] s1 = new long[n];
		long[] s0 = new long[n]; // count
		for(int i = n-1;i >= 0;i--){
			int cur = ord[i];
			s0[cur]++;
			for(int[] e : g[cur]){
				if(par[cur] != e[0]){
					s0[cur] += s0[e[0]];
					s1[cur] += s1[e[0]] + e[1] * s0[e[0]];
					s1[cur] %= mod;
					s2[cur] += s2[e[0]] + 2L * e[1] * s1[e[0]] + (long)e[1] * e[1] % mod * s0[e[0]];
					s2[cur] %= mod;
				}
			}
		}
		long[] s2u = new long[n];
		long[] s1u = new long[n];
		long[] s0u = new long[n]; // count
		Arrays.fill(s0u, 1);
		for(int i = 0;i < n;i++){
			int cur = ord[i];
			for(int[] e : g[cur]){
				if(par[cur] != e[0]){
					s0u[e[0]] += s0u[cur] + s0[cur] - 1 - s0[e[0]];
					long count = s0u[cur] + s0[cur] - 1 - s0[e[0]];
					s1u[e[0]] += s1u[cur] + s1[cur] - (s1[e[0]] + e[1] * s0[e[0]]) + count * e[1];
					s1u[e[0]] %= mod;
					if(s1u[e[0]] < 0)s1u[e[0]] += mod;
					s2u[e[0]] += s2u[cur] + s2[cur] - (s2[e[0]] + 2L * e[1] * s1[e[0]] + (long)e[1] * e[1] % mod * s0[e[0]]) % mod
							+ 2L * e[1] * ((s1u[cur] + s1[cur] - (s1[e[0]] + e[1] * s0[e[0]])) % mod)
							+ (long)e[1]*e[1]%mod * count;
					s2u[e[0]] %= mod;
					if(s2u[e[0]] < 0)s2u[e[0]] += mod;
				}
			}
		}
//		tr(s0);
//		tr(s1);
//		tr(s2);
//		tr(s0u);
//		tr(s1u);
//		tr(s2u);
		int[][] spar = logstepParents(par);
		
		for(int Q = ni();Q >= 1;Q--){
			int u = ni()-1, v = ni()-1;
			int lca = lca2(u, v, spar, dep);
			if(lca != v){
				long plus = dw[u] + dw[v] - 2L * dw[lca];
				while(plus < 0)plus += mod;
				while(plus >= mod)plus -= mod;
				long vu = (s2[v] + 2L * plus * s1[v] + plus * plus % mod * s0[v]) % mod;
				long ret = vu - (s2u[u] + s2[u] - vu);
				ret %= mod;
				if(ret < 0)ret += mod;
				out.println(ret);
			}else{
				long plus = dw[u] - dw[v];
				if(plus < 0)plus += mod;
				long vu = (s2u[v] + 2L * plus * s1u[v] + plus * plus % mod * (s0u[v]-1)) % mod;
				long ret = (s2u[u] + s2[u] - vu) - vu;
				ret %= mod;
				if(ret < 0)ret += mod;
				out.println(ret);
			}
		}
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
				pars[j][i] = pars[j - 1][i] == -1 ? -1
						: pars[j - 1][pars[j - 1][i]];
			}
		}
		return pars;
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
	
	public static int[][] parents(int[][][] g, int root)
	{
		int n = g.length;
		int[] par = new int[n];
		Arrays.fill(par, -1);
		int[] dw = new int[n];
		int[] pw = new int[n];
		int[] dep = new int[n];
		
		int[] q = new int[n];
		q[0] = root;
		for(int p = 0, r = 1;p < r;p++) {
			int cur = q[p];
			for(int[] nex : g[cur]){
				if(par[cur] != nex[0]){
					q[r++] = nex[0];
					par[nex[0]] = cur;
					dep[nex[0]] = dep[cur] + 1;
					dw[nex[0]] = dw[cur] + nex[1];
					if(dw[nex[0]] >= mod)dw[nex[0]] -= mod;
					pw[nex[0]] = nex[1];
				}
			}
		}
		return new int[][] {par, q, dep, dw, pw};
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