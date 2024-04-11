//package manthan2018;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Queue;
import java.util.Random;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), K = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
		}
		int[][] g = packU(n, from, to);
		Random gen = new Random();
		for(int i = 0;i < n;i++){
			shuffle(g[i], gen);
			Arrays.sort(g[i]);
		}
		int[] deg = new int[n];
		for(int i = 0;i < n;i++)deg[i] = g[i].length;
		
		boolean[][] con = new boolean[n][];
		for(int i = 0;i < n;i++){
			con[i] = new boolean[g[i].length];
			Arrays.fill(con[i], true);
		}
		
		
		Queue<Integer> q = new ArrayDeque<>();
		for(int i = 0;i < n;i++)q.add(i);
		
		int non = n;
		boolean[] on = new boolean[n];
		Arrays.fill(on, true);
		while(!q.isEmpty()){
			int cur = q.poll();
			if(on[cur] && deg[cur] < K){
				on[cur] = false;
				non--;
				for(int j = 0;j < g[cur].length;j++){
					int e = g[cur][j];
					if(!con[cur][j])continue;
					con[cur][Arrays.binarySearch(g[cur], e)] = false;
					con[e][Arrays.binarySearch(g[e], cur)] = false;
					deg[e]--;
					q.add(e);
				}
			}
		}
		
		int[] anss = new int[m];
		for(int i = m-1;i >= 0;i--){
			anss[i] = non;
			int f = from[i], t = to[i];
			if(!con[f][Arrays.binarySearch(g[f], t)])continue;
			deg[f]--;
			deg[t]--;
			con[f][Arrays.binarySearch(g[f], t)] = false;
			con[t][Arrays.binarySearch(g[t], f)] = false;
			q.add(f);
			q.add(t);
			
			while(!q.isEmpty()){
				int cur = q.poll();
				if(on[cur] && deg[cur] < K){
					on[cur] = false;
					non--;
					for(int j = 0;j < g[cur].length;j++){
						int e = g[cur][j];
						if(!con[cur][j])continue;
						con[cur][Arrays.binarySearch(g[cur], e)] = false;
						con[e][Arrays.binarySearch(g[e], cur)] = false;
						deg[e]--;
						q.add(e);
					}
				}
			}
		}
		
		for(int v : anss){
			out.println(v);
		}
	}
	
	public static int[] shuffle(int[] a, Random gen){ for(int i = 0, n = a.length;i < n;i++){ int ind = gen.nextInt(n-i)+i; int d = a[i]; a[i] = a[ind]; a[ind] = d; } return a; }

	
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
	
	public static void main(String[] args) throws Exception { new E2().run(); }
	
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