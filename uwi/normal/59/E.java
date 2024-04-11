//package prac;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Queue;

public class R55E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), K = ni();
		long[] es = new long[2*m];
		int[] from = new int[m];
		int[] to = new int[m];
		int p = 0;
		for(int i = 0;i < m;i++){
			int f = ni()-1, t = ni()-1;
			es[p++] = (long)f<<32|t;
			es[p++] = (long)t<<32|f;
			from[i] = f; to[i] = t;
		}
		Arrays.sort(es);
		int[][] g = packU(n, from, to);
		long[] proh = new long[K];
		for(int i = 0;i < K;i++){
			int a = ni()-1, b = ni()-1, c = ni()-1;
			proh[i] = (long)a<<40|(long)b<<20|c;
		}
		Arrays.sort(proh);
		
		int[] prev = new int[2*m+1];
		Arrays.fill(prev, -1);
		int[] d = new int[2*m+1];
		Arrays.fill(d, 9999999);
		Queue<Integer> q = new ArrayDeque<>();
		for(int e : g[0]){
			int id = get(0, e, es);
			d[id] = 0;
			q.add(id);
		}
		while(!q.isEmpty()){
			int cur = q.poll();
			int f = (int)(es[cur]>>>32);
			int t = (int)es[cur];
			if(t == n-1){
				out.println(d[cur] + 1);
				int[] route = new int[d[cur]+2];
				route[d[cur]+1] = t;
				for(int i = d[cur];i >= 0;i--){
					route[i] = (int)(es[cur]>>>32);
					cur = prev[cur];
				}
				for(int x : route){
					out.print((x+1) + " ");
				}
				out.println();
				return;
			}
			for(int e : g[t]){
				long code = (long)f<<40|(long)t<<20|e;
				int eid = get(t, e, es);
				if(d[eid] > d[cur] + 1){
					if(Arrays.binarySearch(proh, code) >= 0)continue;
					d[eid] = d[cur] + 1;
					prev[eid] = cur;
					q.add(eid);
				}
			}
		}
		out.println(-1);
	}
	
	int get(int f, int t, long[] es)
	{
		return Arrays.binarySearch(es, (long)f<<32|t);
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
	
	public static void main(String[] args) throws Exception { new R55E().run(); }
	
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