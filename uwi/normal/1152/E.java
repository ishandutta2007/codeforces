//package prac;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Map;

public class E554_5 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	class Edge
	{
		int u, v;
		boolean alive;
		public Edge(int u, int v) {
			this.u = u;
			this.v = v;
			alive = true;
		}
	}
	
	void solve()
	{
		int n = ni();
		int[] b = na(n-1);
		int[] c = na(n-1);
		for(int i = 0;i < n-1;i++) {
			if(b[i] > c[i]) {
				out.println(-1);
				return;
			}
		}
		Map<Integer, QE> g = new HashMap<>();
		for(int i = 0;i < n-1;i++) {
			Edge e = new Edge(b[i], c[i]);
			if(!g.containsKey(b[i]))g.put(b[i], new QE(1));
			g.get(b[i]).add(e);
			if(!g.containsKey(c[i]))g.put(c[i], new QE(1));
			g.get(c[i]).add(e);
		}
		List<Integer> route = find(g);
		if(route == null) {
			out.println(-1);
		}else {
			for(int v : route) {
				out.print(v + " ");
			}
			out.println();
		}
	}
	
	public static class QE {
		public Edge[] q;
		protected int pt, ph;
		public QE(int n){ q = new Edge[n]; pt = ph = 0; }
		public void add(Edge x){ 
			if(ph == q.length)q = Arrays.copyOf(q, q.length*2);
			q[ph++] = x; 
		}
		public void clear(){ pt = ph = 0; }
		public Edge poll(){ return q[pt++]; }
		public int size(){ return ph-pt; }
		public boolean isEmpty(){ return ph==pt; }
	}
	
	List<Integer> find(Map<Integer, QE> g)
	{
		int first = -1;
		int odd = 0;
		for(int key : g.keySet()) {
			if(g.get(key).size() % 2 == 1) {
				first = key;
				odd++;
			}
		}
		if(odd > 2)return null;
		if(first == -1) {
			for(int key : g.keySet()) first = key;
		}
		int m = 0;
		for(QE es : g.values())m += es.size();
		m /= 2;
		List<Integer> route = new ArrayList<>();
		dfs(first, g, route);
		return route.size() == m+1 ? route : null;
	}
	
	void dfs(int cur, Map<Integer, QE> rem, List<Integer> route)
	{
		while(!rem.get(cur).isEmpty()) {
			Edge e = rem.get(cur).poll();
			if(e.alive) {
				e.alive = false;
				dfs(e.u ^ e.v ^ cur, rem, route);
			}
		}
		route.add(cur);
	}
	
	void run() throws Exception
	{
//		int n = 100000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for (int i = 0; i < 2*(n-1); i++) {
//			sb.append(1 + " ");
//		}
//		INPUT = sb.toString();

		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E554_5().run(); }
	
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