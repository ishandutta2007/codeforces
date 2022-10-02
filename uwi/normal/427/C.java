//package round244;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Queue;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		int m = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
		}
		int[][] g = packD(n, from, to);
		int[][] ig = packD(n, to, from);
		int[] clus = decomposeToSCCNoRec(g, ig);
		int mc = 0;
		for(int i = 0;i < n;i++){
			mc = Math.max(mc, clus[i]);
		}
		mc++;
		
		int[] minc = new int[mc];
		Arrays.fill(minc, Integer.MAX_VALUE);
		for(int i = 0;i < n;i++){
			minc[clus[i]] = Math.min(minc[clus[i]], a[i]);
		}
		long cost = 0;
		for(int i = 0;i < mc;i++){
			cost += minc[i];
		}
		int[] nums = new int[mc];
		for(int i = 0;i < n;i++){
			if(minc[clus[i]] == a[i])nums[clus[i]]++;
		}
		long num = 1;
		int mod = 1000000007;
		for(int i = 0;i < mc;i++){
			num = num * nums[i] % mod;
		}
		out.println(cost + " " + num);
	}
	
	static int[][] packD(int n, int[] from, int[] to) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int f : from)
			p[f]++;
		for(int i = 0;i < n;i++)
			g[i] = new int[p[i]];
		for(int i = 0;i < from.length;i++){
			g[from[i]][--p[from[i]]] = to[i];
		}
		return g;
	}
	
	public static int[] decomposeToSCCNoRec(int[][] g, int[][] ig)
	{
		int n = g.length;
		boolean[] visited = new boolean[n];
		int[] po = new int[n];
		int pop = 0;
		
		int[] stack = new int[n];
		int[] sinds = new int[n];
		int sp = 0;
		for(int i = 0;i < n;i++){
			if(!visited[i]){
				sinds[sp] = 0;
				stack[sp++] = i;
				while(sp > 0){
					int cur = stack[sp-1];
					visited[cur] = true;
					while(sinds[sp-1] < g[cur].length && visited[g[cur][sinds[sp-1]]])sinds[sp-1]++;
					if(sinds[sp-1] == g[cur].length){
						po[pop++] = cur;
						sp--;
					}else{
						stack[sp] = g[cur][sinds[sp-1]];
						sinds[sp] = 0;
						sp++;
					}
				}
			}
		}
		
		int[] ret = new int[n];
		Arrays.fill(visited, false);
		int clus = 0;
		Queue<Integer> q = new ArrayDeque<Integer>();
		for(int i = n - 1;i >= 0;i--){
			if(!visited[po[i]]){
				q.add(po[i]);
				visited[po[i]] = true;
				while(!q.isEmpty()){
					int cur = q.poll();
					ret[cur] = clus;
					for(int k : ig[cur]){
						if(!visited[k]){
							q.add(k);
							visited[k] = true;
						}
					}
				}
				clus++;
			}
		}
		
		return ret;
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