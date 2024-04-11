//package round477;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Queue;
import java.util.Random;

public class D3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		Random gen = new Random();
		int n = ni(), m = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
		}
		
		int[][] g = packU(n, from, to);
		
		// straightforward
		int[] d = new int[n];
		int[] prev = new int[n];
		Arrays.fill(prev, -1);
		Arrays.fill(d, 99999999);
		d[n-1] = 0;
		Queue<Integer> q = new ArrayDeque<>();
		q.add(n-1);
		while(!q.isEmpty()){
			int cur = q.poll();
			for(int e : g[cur]){
				if(d[e] > d[cur] + 1){
					d[e] = d[cur] + 1;
					prev[e] = cur;
					q.add(e);
				}
			}
		}
		if(prev[0] != -1){
			if(d[0] <= 4){
				out.println(d[0]);
				for(int cur = 0;cur != n-1;cur = prev[cur]){
					out.print((cur+1) + " ");
				}
				out.println(n);
				return;
			}
		}
		
		for(int i = 0;i < n;i++){
			g[i] = shuffle(g[i], gen);
			Arrays.sort(g[i]);
		}
		
		// 0-a-b
		for(int e : g[0]){
			for(int f : g[e]){
				if(f != 0 && (g[f].length == 0 || g[f][0] != 0)){
//					check(g, 0, e, f, 0, n-1);
					out.println(4);
					out.printf("%d %d %d %d %d\n", 0+1, e+1, f+1, 0+1, n);
					return;
				}
			}
		}
		
//		int[][] h = new int[n][];
//		for(int i = 0;i < n;i++){
//			long[] gi = new long[g[i].length];
//			for(int j = 0;j < g[i].length;j++){
//				gi[j] = (long)(n-g[g[i][j]].length)<<32|g[i][j];
//			}
//			Arrays.sort(gi);
//			h[i] = new int[g[i].length];
//			for(int j = 0;j < g[i].length;j++){
//				h[i][j] = (int)gi[j];
//			}
//		}
		
		for(int e : g[0]){
			for(int f : g[e]){
				if(f == 0)continue;
				int p = 0;
				for(int t : g[f]){
					if(t <= e || t == 0)continue;
					while(p < g[e].length && g[e][p] < t)p++;
					if(p < g[e].length && g[e][p] == t)continue;
//					check(g, 0, e, f, t, e, n-1);
					out.println(5);
					out.printf("%d %d %d %d %d %d\n", 
							1, 
							e+1,
							f+1,
							t+1,
							e+1,
							n
							);
					return;
				}
			}
		}
		
		
		if(prev[0] != -1){
			out.println(d[0]);
			for(int cur = 0;cur != n-1;cur = prev[cur]){
				out.print((cur+1) + " ");
			}
			out.println(n);
			return;
		}
		
		out.println(-1);
		
	}
	
	void check(int[][] g, int... a)
	{
		int m = a.length;
		int n = g.length;
		assert a[0] == 0;
		assert a[m-1] == n-1;
		boolean[][] h = new boolean[n][n];
		for(int i = 0;i < n;i++){
			for(int e : g[i]){
				h[i][e] = true;
			}
		}
		for(int i = 0;i < m-1;i++){
			int f = a[i], t = a[i+1];
			assert h[f][t];
			for(int j = 0;j < n;j++){
				h[f][j] ^= true;
				h[j][f] ^= true;
			}
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
	
	public static int[] shuffle(int[] a, Random gen){ for(int i = 0, n = a.length;i < n;i++){ int ind = gen.nextInt(n-i)+i; int d = a[i]; a[i] = a[ind]; a[ind] = d; } return a; }

	
	void run() throws Exception
	{
//		int n = 300000, m = 750*(750-1)/2;
//		tr(m);
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		for (int i = 0; i < 750; i++) {
//			for(int j = i+1;j < 750;j++){
//				sb.append((i+1) + " " + (j+1) + " ");
//			}
//		}
//		INPUT = sb.toString();
//
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new D3().run(); }
	
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