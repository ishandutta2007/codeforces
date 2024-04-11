//package prac;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class R221D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), Q = ni();
		a = na(n);
		int[] from = new int[n-1];
		int[] to = new int[n-1];
		for(int i = 0;i < n-1;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
		}
		int[][] g = packU(n, from, to);
		int[][] pars = parents3(g, 0);
		int[] par = pars[0], ord = pars[1];
		int[] des = new int[n];
		Arrays.fill(des, 1);
		for(int i = n-1;i >= 1;i--){
			int cur = ord[i];
			des[par[cur]] += des[cur];
		}
		int[][] qs = new int[Q][];
		for(int i = 0;i < Q;i++){
			qs[i] = new int[]{ni()-1, ni(), i};
		}
		bucket = makeBuckets(qs, 0, n);
		ans = new int[Q];
		Arrays.fill(ans, -1);
		ft = new int[100055];
		f = new int[100005];
		addFenwick(ft, O, 100000);
		dfs(0, -1, g, false, des);
		for(int v : ans){
			out.println(v);
		}
	}
	
	int[] a;
	int[][][] bucket;
	int[] ans;
	int[] ft;
	int[] f;
	int O = 100005;
	
	public void dfs(int cur, int pre, int[][] g, boolean preserve, int[] des)
	{
		int big = -1;
		for(int e : g[cur]){
			if(e == pre)continue;
			if(big == -1 || des[e] > des[big]){
				big = e;
			}
		}
		for(int e : g[cur]){
			if(e != pre && e != big)dfs(e, cur, g, false, des);
		}
		if(big != -1)dfs(big, cur, g, true, des);
		
		// only biggest subtree is painted
		
		// paint subtrees
		paint(cur);
		// if processing node pairs, put answer(cur);
		for(int e : g[cur]){
			if(e != pre && e != big){
				// if processing node pairs, put answerdfs(e, cur, g);
				paintdfs(e, cur, g);
			}
		}
		
		// all node is painted
		answer(cur);
		
		// clear subtrees
		if(!preserve)cleardfs(cur, pre, g);
	}
	
	private void answer(int cur)
	{
		for(int[] q : bucket[cur]){
			ans[q[2]] = sumFenwick(ft, O-q[1]);
		}
	}
	
	private void paint(int cur)
	{
		addFenwick(ft, O-f[a[cur]], -1);
		f[a[cur]]++;
		addFenwick(ft, O-f[a[cur]], 1);
	}
	
	private void clear(int cur)
	{
		addFenwick(ft, O-f[a[cur]], -1);
		f[a[cur]]--;
		addFenwick(ft, O-f[a[cur]], 1);
	}
	
	private void paintdfs(int cur, int pre, int[][] g)
	{
		paint(cur);
		for(int e : g[cur])if(e != pre)paintdfs(e, cur, g);
	}
	
	private void cleardfs(int cur, int pre, int[][] g)
	{
		clear(cur);
		for(int e : g[cur])if(e != pre)cleardfs(e, cur, g);
	}
	
	private void answerdfs(int cur, int pre, int[][] g)
	{
		answer(cur);
		for(int e : g[cur])if(e != pre)answerdfs(e, cur, g);
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
	
	
	public static int[][][] makeBuckets(int[][] a, int ind, int sup)
	{
		int n = a.length;
		int[][][] bucket = new int[sup+1][][];
		int[] bp = new int[sup+1];
		for(int i = 0;i < n;i++)bp[a[i][ind]]++;
		for(int i = 0;i <= sup;i++)bucket[i] = new int[bp[i]][];
		for(int i = n-1;i >= 0;i--)bucket[a[i][ind]][--bp[a[i][ind]]] = a[i];
		return bucket;
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
	
	public static void main(String[] args) throws Exception { new R221D().run(); }
	
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