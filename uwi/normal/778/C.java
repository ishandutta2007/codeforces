//package round402;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n= ni();
		int[] from = new int[n - 1];
		int[] to = new int[n - 1];
		int[] w = new int[n-1];
		int[][] h = new int[n][26];
		for(int i = 0;i < n;i++)Arrays.fill(h[i], -1);
		for (int i = 0; i < n - 1; i++) {
			from[i] = ni() - 1;
			to[i] = ni() - 1;
			w[i] = nc()-'a';
			h[from[i]][w[i]] = to[i];
		}
		int[][][] g = packWD(n, from, to, w);
		int[] des = new int[n];
		int[] deps = new int[n];
		dfsdes(0, -1, g, des, deps, 0);
		int[] vals = new int[n];
		dfs(0, -1, g, true, des, h, vals);
		for(int i = 0;i < n;i++){
			vals[i] += g[i].length;
		}
		int[] sumvals = new int[n];
		for(int i = 0;i < n;i++){
			sumvals[deps[i]] += vals[i];
		}
		int max = -1;
		int argmax = -1;
		for(int d = 0;d < n;d++){
			if(sumvals[d] > max){
				max = sumvals[d];
				argmax = d;
			}
		}
		out.println(n-max);
		out.println(argmax+1);
	}
	
	void dfsdes(int cur, int pre, int[][][] g, int[] des, int[] deps, int dep)
	{
		deps[cur] = dep;
		for(int[] e : g[cur]){
			dfsdes(e[0], cur, g, des, deps, dep+1);
			des[cur] += des[e[0]];
		}
		des[cur]++;
	}
	
	public static void dfs(int cur, int pre, int[][][] g, boolean preserve, int[] des, int[][] h, int[] vals)
	{
		int big = -1;
		for(int[] e : g[cur]){
			if(big == -1 || des[e[0]] > des[big]){
				big = e[0];
			}
		}
		for(int[] e : g[cur]){
			if(e[0] != big)dfs(e[0], cur, g, false, des, h, vals);
		}
		if(big != -1)dfs(big, cur, g, true, des, h, vals);
		
		// only biggest subtree is painted
		
		// paint subtrees
		// if processing node pairs, put answer(cur);
		for(int[] e : g[cur]){
			if(e[0] != big){
				// if processing node pairs, put answerdfs(e, cur, g);
				paintdfs(e[0], cur, big, g, h, vals);
			}
		}
		
		// clear subtrees
		for(int u = g[cur].length-1;u >= 0;u--){
			int[] e = g[cur][u];
			if(e[0] != big){
				// if processing node pairs, put answerdfs(e, cur, g);
				cleardfs(e[0], cur, big, g, h);
			}
		}
	}
	
	private static void paintdfs(int cur, int root, int pcur, int[][][] g, int[][] h, int[] vals)
	{
		for(int[] e : g[cur]){
			if(h[pcur][e[1]] == -1){
				h[pcur][e[1]] = e[0];
			}else{
				vals[root]++;
				paintdfs(e[0], root, h[pcur][e[1]], g, h, vals);
			}
		}
	}
	
	private static void cleardfs(int cur, int root, int pcur, int[][][] g, int[][] h)
	{
		for(int[] e : g[cur]){
			if(h[pcur][e[1]] == e[0]){
				h[pcur][e[1]] = -1;
			}else{
				cleardfs(e[0], root, h[pcur][e[1]], g, h);
			}
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

	public static int[][][] packWD(int n, int[] from, int[] to, int[] w) {
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for (int f : from)
			p[f]++;
		for (int i = 0; i < n; i++)
			g[i] = new int[p[i]][2];
		for (int i = 0; i < from.length; i++) {
			--p[from[i]];
			g[from[i]][p[from[i]]][0] = to[i];
			g[from[i]][p[from[i]]][1] = w[i];
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
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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