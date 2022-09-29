//package round669;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Queue;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		int[] ws = new int[m];
		for(int i = 0;i < m;i++) {
			from[i] = ni()-1;
			to[i] = ni()-1;
			ws[i] = ni();
		}
		int[][][] g = packWD(n, to, from, ws);
		int[][][] fg = packWD(n, from, to, ws);
		int[] color = new int[n];
		boolean[] ved = new boolean[n];
		Arrays.fill(color, -1);
		Queue<Integer> q = new ArrayDeque<>();
		q.add(n-1);
		color[n-1] = 0;
		ved[n-1] = true;
		while(!q.isEmpty()) {
			int cur = q.poll();
			for(int[] e : g[cur]) {
				if(color[e[0]] == -1) {
					color[e[0]] = e[1]^1;
				}else if(color[e[0]] == e[1] && !ved[e[0]]) {
					ved[e[0]] = true;
					q.add(e[0]);
				}
			}
		}
		for(int i = 0;i < n;i++) {
			if(color[i] == -1) {
				color[i] = 0;
			}
		}
		int route = bfs3(fg, color, 0, n-1);
		out.println(route);
		for(int v : color) {
			out.print(v);
		}
		out.println();
	}
	
	public static int bfs3(int[][][] g, int[] color, int s, int t)
	{
		int n = g.length;
		Queue<Integer> q = new ArrayDeque<>();
		int[] ds = new int[n];
		Arrays.fill(ds, Integer.MAX_VALUE / 2);
		q.add(s);
		ds[s] = 0;
		while(!q.isEmpty()){
			int cur = q.poll();
			for(int[] e : g[cur]){
				if(ds[e[0]] > ds[cur] + 1 && color[cur] == e[1]){
					ds[e[0]] = ds[cur] + 1;
					q.add(e[0]);
				}
			}
		}
		return ds[t] >= Integer.MAX_VALUE / 3 ? -1 : ds[t];
	}
	
	public static int[] bfs3(int[][] g, int s, int t)
	{
		int n = g.length;
		Queue<Integer> q = new ArrayDeque<>();
		int[] ds = new int[n];
		Arrays.fill(ds, Integer.MAX_VALUE / 2);
		q.add(s);
		ds[s] = 0;
		while(!q.isEmpty()){
			int cur = q.poll();
			for(int e : g[cur]){
				if(ds[e] > ds[cur] + 1){
					ds[e] = ds[cur] + 1;
					q.add(e);
				}
			}
		}
		if(ds[t] >= Integer.MAX_VALUE / 3)return null;
		int[] route = new int[ds[t]+1];
		int cur = t;
		outer:
		while(true) {
			route[ds[cur]] = cur;
			if(cur == s)break;
			for(int e : g[cur]) {
				if(ds[e] == ds[cur] - 1) {
					cur = e;
					continue outer;
				}
			}
			throw new RuntimeException();
		}
		return route;
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