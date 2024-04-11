//package round383;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D7 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	int Z = 22;
	
	void solve()
	{
		int n = ni();
		int[] from = new int[n-1];
		int[] to =new int[n-1];
		int[] w = new int[n-1];
		for(int i = 0;i < n-1;i++){
			from[i] = i+1;
			to[i] = ni()-1;
			w[i] = nc()-'a';
		}
		int[][][] g = packWU(n, from, to, w);
		int[][] pars = parents(g, 0);
		int[] par = pars[0], ord = pars[1];
		dep = pars[2];
		int[] des = new int[n];
		for(int i = n-1;i >= 0;i--){
			int cur = ord[i];
			des[cur]++;
			if(i > 0)des[par[cur]] += des[cur];
		}
		ans = new int[n];
		maxdeps = new int[1<<Z];
		Arrays.fill(maxdeps, SMALL);
		dfs(0, -1, 0, g, true, des);
		for(int v : ans){
			out.print(v + " ");
		}
		out.println();
	}
	
	int SMALL = -999999;
	
	int[] ans;
	int[] maxdeps;
	int[] dep;
	int root;
	
	private void answer(int cur, int x)
	{
		ans[root] = Math.max(ans[root], maxdeps[x] + dep[cur] - dep[root]*2);
		for(int i = 0;i < Z;i++){
			ans[root] = Math.max(ans[root], maxdeps[x^1<<i] + dep[cur] - dep[root]*2);
		}
	}
	
	private void paint(int cur, int x)
	{
		maxdeps[x] = Math.max(maxdeps[x], dep[cur]);
	}
	
	private void clear(int cur, int x)
	{
		maxdeps[x] = SMALL;
	}
	
	public void dfs(int cur, int pre, int x, int[][][] g, boolean preserve, int[] des)
	{
		int big = -1;
		int bigw = -1;
		for(int[] e : g[cur]){
			if(e[0] == pre)continue;
			if(big == -1 || des[e[0]] > des[big]){
				big = e[0];
				bigw = e[1];
			}
		}
		for(int[] e : g[cur]){
			if(e[0] != pre && e[0] != big)dfs(e[0], cur, x^1<<e[1], g, false, des);
		}
		if(big != -1)dfs(big, cur, x^1<<bigw, g, true, des);
		
		// only biggest subtree is painted
		
		// paint subtrees
		
		// if processing node pairs, put answer(cur);
		root = cur;
		answer(cur, x);
		paint(cur, x);
		// if processing node pairs, put answer(cur);
		for(int[] e : g[cur]){
			if(e[0] != pre){
				ans[cur] = Math.max(ans[cur], ans[e[0]]);
			}
		}
		for(int[] e : g[cur]){
			if(e[0] != pre && e[0] != big){
				// if processing node pairs, put answerdfs(e, cur, g);
				answerdfs(e[0], cur, x^1<<e[1], g);
				paintdfs(e[0], cur, x^1<<e[1], g);
			}
		}
		
		// all node is painted
//		answer(cur);
		
		if(!preserve)cleardfs(cur, pre, x, g);
	}
	
	private void paintdfs(int cur, int pre, int x, int[][][] g)
	{
		paint(cur, x);
		for(int[] e : g[cur])if(e[0] != pre)paintdfs(e[0], cur, x^1<<e[1], g);
	}
	
	private void cleardfs(int cur, int pre, int x, int[][][] g)
	{
		clear(cur, x);
		for(int[] e : g[cur])if(e[0] != pre)cleardfs(e[0], cur, x^1<<e[1], g);
	}
	
	private void answerdfs(int cur, int pre, int x, int[][][] g)
	{
		answer(cur, x);
		for(int[] e : g[cur])if(e[0] != pre)answerdfs(e[0], cur, x^1<<e[1], g);
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
		
		Thread t = new Thread(null, null, "~", Runtime.getRuntime().maxMemory()){
			@Override
			public void run() {
				long s = System.currentTimeMillis();
				solve();
				out.flush();
				if(!INPUT.isEmpty())tr(System.currentTimeMillis()-s+"ms");
			}
		};
		t.start();
		t.join();
		
//		long s = System.currentTimeMillis();
//		solve();
//		out.flush();
//		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new D7().run(); }
	
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