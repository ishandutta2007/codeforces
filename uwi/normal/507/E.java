//package round287;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;
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
		int[] w = new int[m];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
			w[i] = i<<1|ni()^1;
		}
		int[][][] g = packWU(n, from, to, w);
		int[] ds = maked(g, 0);
		int[] dt = maked(g, n-1);
		Deque<Integer> q = new ArrayDeque<Integer>();
		q.add(0);
		int[] cost = new int[n];
		int[] prev = new int[n];
		Arrays.fill(cost, 999999999);
		Arrays.fill(prev, -1);
		cost[0] = 0;
		while(!q.isEmpty()){
			int cur = q.poll();
			for(int[] e : g[cur]){
				int c = e[1]&1;
				if(ds[e[0]] == ds[cur] + 1 && dt[e[0]] == dt[cur] - 1 && cost[e[0]] > cost[cur] + c){
					cost[e[0]] = cost[cur] + c;
					prev[e[0]] = cur;
					if(e[1] == 0){
						q.addFirst(e[0]);
					}else{
						q.addLast(e[0]);
					}
				}
			}
		}
		
		int[] use = new int[m];
		for(int i = n-1;i != 0;i = prev[i]){
			for(int[] e : g[i]){
				if(e[0] == prev[i]){
					use[e[1]>>>1] = 1;
				}
			}
		}
		
		int ct = 0;
		for(int i = 0;i < m;i++){
			int c = w[i]&1^1;
			if(use[i] != c){
				ct++;
			}
		}
		
		out.println(ct);
		for(int i = 0;i < m;i++){
			int c = w[i]&1^1;
			if(use[i] != c){
				out.println((from[i]+1) + " " + (to[i]+1) + " " + use[i]);
			}
		}
	}
	
	static int[] maked(int[][][] g, int s)
	{
		int n = g.length;
		int[] d = new int[n];
		Arrays.fill(d, 99999999);
		d[s] = 0;
		Queue<Integer> q = new ArrayDeque<Integer>();
		q.add(s);
		while(!q.isEmpty()){
			int cur = q.poll();
			for(int[] e : g[cur]){
				if(d[e[0]] > d[cur] + 1){
					d[e[0]] = d[cur] + 1;
					q.add(e[0]);
				}
			}
		}
		return d;
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