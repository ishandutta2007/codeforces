//package round495;
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
		int n = ni(), K = ni();
		int[] from = new int[n-1];
		int[] to = new int[n-1];
		int[] ws = new int[n-1];
		for(int i = 0;i < n-1;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
			ws[i] = ni();
		}
		int[][][] g = packWU(n, from, to, ws);
		
		int[] cs = go(g);
		int[] d0 = ds(cs[0], g);
		int[] d1 = ds(cs[1], g);
		int min = Integer.MAX_VALUE;
		int argmin = -1;
		for(int i = 0;i < n;i++){
			if(d0[i] + d1[i] == d0[cs[1]]){
				int vd = Math.max(d0[i], d1[i]);
				if(vd < min){
					min = vd;
					argmin = i;
				}
			}
		}
		int center = argmin;
		if(g[center].length == 0){
			out.println(0);
			return;
		}
		if(g[center].length == 1){
			assert n == 2;
			if(K == 1){
				out.println(g[center][0][1]);
			}else if(K == 2){
				out.println(0);
			}else{
				throw new RuntimeException();
			}
			return;
		}
		
		int[][] pars = parents(g, center);
		int[] par = pars[0], ord = pars[1], dep = pars[2], pw = pars[4];
		int[] hs = new int[n];
		for(int i = n-1;i >= 1;i--){
			int cur = ord[i];
			hs[par[cur]] = Math.max(hs[par[cur]], hs[cur] + pw[cur]);
		}
		
		Arrays.sort(g[center], new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return -((hs[a[0]]+a[1]) - (hs[b[0]]+b[1]));
			}
		});
		
		
		int[] x0 = go2(center, g[center][0][0], g, hs, pw, par);
		int[] x1 = go2(center, g[center][1][0], g, hs, pw, par);
		int lmax = 0;
		for(int i = 2;i < g[center].length;i++){
			lmax = Math.max(lmax, hs[g[center][i][0]]+g[center][i][1]);
		}
		int ans = Integer.MAX_VALUE;
		for(int i = 0;i < K;i++){
			ans = Math.min(ans, Math.max(lmax, Math.max(x0[i], x1[K-1-i])));
		}
		out.println(ans);
	}
	
	int[] go2(int center, int neck, int[][][] g, int[] hs, int[] pw, int[] par)
	{
		int n = g.length;
		int[] vals = new int[n];
		vals[0] = hs[neck]+pw[neck];
		int cur = neck;
		int uumax = 0;
		for(int u = 1;u < n;u++){
			int lmax = 0;
			int largmax = -1;
			for(int[] e : g[cur]){
				if(par[cur] == e[0])continue;
				if(hs[e[0]] + e[1] > lmax){
					lmax = hs[e[0]] + e[1];
					largmax = e[0];
				}
			}
			vals[u] = Math.max(uumax, lmax);
			
			if(largmax == -1){
				for(int k = u+1;k < n;k++){
					vals[k] = vals[k-1];
				}
				break;
			}
			
			int umax = -1;
			for(int[] e : g[cur]){
				if(par[cur] == e[0])continue;
				if(e[0] == largmax)continue;
				umax = Math.max(umax, hs[e[0]] + e[1]);
			}
			uumax = Math.max(uumax, umax);
			cur = largmax;
		}
		return vals;
	}
	
	int[] ds(int s, int[][][] g)
	{
		int n = g.length;
		int[] q = new int[n];
		int p = 0;
		int[] d = new int[n];
		Arrays.fill(d, Integer.MAX_VALUE);
		d[s] = 0;
		q[p++] = s;
		for(int r = 0;r < p;r++){
			int cur = q[r];
			for(int[] e : g[cur]){
				if(d[e[0]] == Integer.MAX_VALUE){
					d[e[0]] = d[cur] + e[1];
					q[p++] = e[0];
				}
			}
		}
		return d;
	}
	
	int search(int s, int[][][] g)
	{
		int n = g.length;
		int[] q = new int[n];
		int p = 0;
		int[] d = new int[n];
		Arrays.fill(d, Integer.MAX_VALUE);
		d[s] = 0;
		q[p++] = s;
		for(int r = 0;r < p;r++){
			int cur = q[r];
			for(int[] e : g[cur]){
				if(d[e[0]] == Integer.MAX_VALUE){
					d[e[0]] = d[cur] + e[1];
					q[p++] = e[0];
				}
			}
		}
		int maxd = -1, argmax = -1;
		for(int i = 0;i < n;i++){
			if(d[i] > maxd){
				maxd = d[i];
				argmax = i;
			}
		}
		return argmax;
	}
	
	int[] go(int[][][] g)
	{
		int d1 = search(0, g);
		int d2 = search(d1, g);
		return new int[]{d1, d2};
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