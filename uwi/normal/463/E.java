//package round264;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int Q = 2000000;
		int[] lpf = enumLowestPrimeFactors(Q);
		int n = ni(), q = ni();
		int[] a = na(n);
		int[][] fs = new int[n][];
		for(int i = 0;i < n;i++){
			fs[i] = factorSeqFast(a[i], lpf);
		}
		
		int[] from = new int[n-1];
		int[] to = new int[n-1];
		for(int i = 0;i < n-1;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
		}
		int[] last = new int[Q+1];
		int[] anc = new int[n];
		Arrays.fill(last, -2);
		
		int[][] g = packU(n, from, to);
		int[][] pars = parents3(g, 0);
		int[] par = pars[0], dep = pars[2];
		dfs(0, last, fs, g, par, anc, dep);
		for(int i = 0;i <= Q;i++){
			if(last[i] != -2)throw new RuntimeException();
		}
		
		for(int z = 0;z < q;z++){
			int t = ni();
			if(t == 1){
				int x = ni()-1;
				out.println(anc[x]);
			}else{
				int v = ni()-1;
				int w = ni();
				fs[v] = factorSeqFast(w, lpf);
				dfs(0, last, fs, g, par, anc, dep);
			}
		}
	}
	
	void dfs(int cur, int[] last, int[][] fs, int[][] g, int[] par, int[] anc, int[] dep)
	{
		int[] f = fs[cur];
		int[] old = new int[f.length];
		int max = -2;
		for(int i = 0;i < f.length;i++){
			int v = f[i];
			if(last[v] != cur && last[v] != -2){
				if(max == -2){
					max = last[v];
				}else{
					if(dep[max] < dep[last[v]]){
						max = last[v];
					}
				}
			}
			old[i] = last[v];
			last[v] = cur;
		}
		anc[cur] = max+1;
		
		for(int e : g[cur]){
			if(par[cur] != e){
				dfs(e, last, fs, g, par, anc, dep);
			}
		}
		for(int i = f.length-1;i >= 0;i--){
			int v = f[i];
			last[v] = old[i];
		}
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
	
	public static int[] enumLowestPrimeFactors(int n)
	{
		int[] a = new int[n+1];
		for(int p = 2;p <= n;p++){
			if(a[p] == 0){
				for(int q = p;q <= n;q+=p)if(a[q] == 0)a[q] = p;
			}
		}
		return a;
	}
	
	public static int[] factorSeqFast(int n, int[] lpf)
	{
		int[] seq = new int[26];
		int p = 0;
		while(n > 1){
			if(p == 0 || seq[p-1] != lpf[n]){
				seq[p++] = lpf[n];
			}
			n /= lpf[n];
		}
		return Arrays.copyOf(seq, p);
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