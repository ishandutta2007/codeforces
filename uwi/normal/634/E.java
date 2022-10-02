//package prac;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class EVCVC_E3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] a = na(n);
		int[] from = new int[n-1];
		int[] to = new int[n-1];
		for(int i = 0;i < n-1;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
		}
		int[][] g = packU(n, from, to);
		int[][] pars = parents3(g, 0);
		int[] par = pars[0], ord = pars[1], dep = pars[2];
		int[] des = new int[n];
		for(int i = n-1;i >= 0;i--){
			int cur = ord[i];
			des[cur]++;
			if(i > 0)des[par[cur]] += des[cur];
		}
		
		int low = -1, high = 1000005;
		outer:
		while(high - low > 1){
			int h = high+low>>>1;
			if(ok(g, par, ord, m, h, des, a)){
				low = h;
			}else{
				high = h;
			}
		}
		out.println(low);
	}
	
	public static class Maxima
	{
		public int[][] max;
		public int[][] argmax;
		
		public Maxima(int d, int n, int ini)
		{
			max = new int[d][n];
			argmax = new int[d][n];
			for(int i = 0;i < d;i++){
				Arrays.fill(max[i], ini);
				Arrays.fill(argmax[i], -1);
			}
		}
		
		public void add(int x, int label, int val)
		{
			int d = max.length;
			for(int i = 0;i < d;i++){
				if(val > max[i][x]){
					for(int j = d-1;j >= i+1;j--){
						max[j][x] = max[j-1][x];
						argmax[j][x] = argmax[j-1][x];
					}
					max[i][x] = val;
					argmax[i][x] = label;
					break;
				}
			}
		}
		
		public int not(int x, int label)
		{
			int d = max.length;
			for(int i = 0;i < d;i++){
				if(argmax[i][x] == label)continue;
				return max[i][x];
			}
			throw new RuntimeException();
		}
	}
	
	boolean ok(int[][] g, int[] par, int[] ord, int m, int h, int[] des, int[] a)
	{
		int n = g.length;
		int[] dp = new int[n];
		Maxima frag = new Maxima(2, n, 0);
		
		for(int i = n-1;i >= 0;i--){
			int cur = ord[i];
			if(a[cur] < h){
				dp[cur] = 0;
				continue;
			}
			for(int e : g[cur]){
				if(par[cur] == e)continue;
				if(dp[e] < des[e]){
					frag.add(cur, e, dp[e]);
				}else{
					dp[cur] += dp[e];
				}
			}
			dp[cur] += frag.max[0][cur];
			dp[cur]++;
		}
//		tr(h, dp, frag.max[0]);
		for(int i = 0;i < n;i++){
			int cur = ord[i];
			for(int e : g[cur]){
				if(par[cur] == e)continue;
				if(a[e] < h)continue;
				int uv = dp[cur];
				uv -= frag.max[0][cur];
				uv += frag.not(cur, e);
				
				if(dp[e] == des[e]){
					uv -= dp[e];
				}
				dp[e] -= frag.max[0][e];
				
				if(uv < n-des[e]){
					frag.add(e, cur, uv);
				}else{
					dp[e] += uv;
				}
				
				dp[e] += frag.max[0][e];
			}
		}
//		tr(h, dp, m, frag.max[0]);
		for(int i = 0;i < n;i++){
			if(dp[i] >= m)return true;
		}
		return false;
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
	
	public static void main(String[] args) throws Exception { new EVCVC_E3().run(); }
	
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