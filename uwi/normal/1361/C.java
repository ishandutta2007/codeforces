//package round647;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Map;
import java.util.Queue;

public class C2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[][] ab = new int[n][];
		for(int i = 0;i < n;i++){
			ab[i] = na(2);
		}
		
		int low = -1, high = 21;
		while(high - low > 1){
			int h = high+low>>1;
			if(ok(ab, h)){
				low = h;
			}else{
				high = h;
			}
		}
		out.println(low);
		
		ok2(ab, low);
		List<Integer> all = new ArrayList<>();
		for(Edge e : last){
			if(e.u == (ab[e.id][0]&(1<<low)-1)){
				out.print(2*e.id+1 + " ");
				out.print(2*e.id+2 + " ");
				all.add(2*e.id);
				all.add(2*e.id+1);
			}else{
				out.print(2*e.id+2 + " ");
				out.print(2*e.id+1 + " ");
				all.add(2*e.id+1);
				all.add(2*e.id);
			}
		}
//		for(int i = 0;i < 2*n;i+=2){
//			int j = (i+2*n-1)%(2*n);
//			tr(ab[all.get(i)/2][all.get(i)%2], ab[all.get(j)/2][all.get(j)%2]);
//			assert Integer.numberOfTrailingZeros(
//					ab[all.get(i)/2][all.get(i)%2]
//					^		ab[all.get(j)/2][all.get(j)%2]) >= low;
//		}
		out.println();
	}
	
	List<Edge> last;
	
	boolean ok2(int[][] ab, int h)
	{
		int n = ab.length;
		Map<Integer, Queue<Edge>> g = new HashMap<>();
		for(int i = 0;i < n;i++){
			int f = ab[i][0]&(1<<h)-1;
			int t = ab[i][1]&(1<<h)-1;
			if(!g.containsKey(f))g.put(f, new ArrayDeque<Edge>());
			if(!g.containsKey(t))g.put(t, new ArrayDeque<Edge>());
			Edge e = new Edge(f, t, i);
			g.get(f).add(e);
			g.get(t).add(e);
		}
		List<Edge> les = eulerianPathUndirected(g);
		if(les != null)last = les;
		return les != null;
	}
	
	public static class DJSet {
		public int[] upper;

		public DJSet(int n) {
			upper = new int[n];
			Arrays.fill(upper, -1);
		}

		public int root(int x) {
			return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
		}

		public boolean equiv(int x, int y) {
			return root(x) == root(y);
		}

		public boolean union(int x, int y) {
			x = root(x);
			y = root(y);
			if (x != y) {
				if (upper[y] < upper[x]) {
					int d = x;
					x = y;
					y = d;
				}
				upper[x] += upper[y];
				upper[y] = x;
			}
			return x == y;
		}

		public int count() {
			int ct = 0;
			for (int u : upper)
				if (u < 0)
					ct++;
			return ct;
		}
	}

	
	boolean ok(int[][] ab, int h)
	{
		int n = ab.length;
		DJSet ds = new DJSet(1<<h);
		int[] deg = new int[1<<h];
		for(int i = 0;i < n;i++){
			int f = ab[i][0]&(1<<h)-1;
			int t = ab[i][1]&(1<<h)-1;
			ds.union(f, t);
			deg[f]++;
			deg[t]++;
		}
		int valid = 0;
		for(int i = 0;i < 1<<h;i++){
			if(ds.upper[i] < -1 || ds.upper[i] == -1 && deg[i] >= 1){
				valid++;
			}
			if(deg[i] % 2 != 0){
				return false;
			}
		}
		return valid == 1;
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
	
	public static List<Edge> eulerianPathUndirected(Map<Integer, Queue<Edge>> g)
	{
		int first = -1;
		int odd = 0;
		for(int key : g.keySet()) {
			if(g.get(key).size() % 2 == 1) {
				first = key;
				odd++;
			}
		}
		if(odd > 0)return null;
//		if(odd > 2)return null;
		if(first == -1) {
			for(int key : g.keySet()) first = key;
		}
		int m = 0;
		for(Queue<Edge> es : g.values())m += es.size();
		m /= 2;
		List<Edge> route = new ArrayList<>();
		dfs(first, g, route);
		return route.size() == m ? route : null;
	}
	
	public static class Edge
	{
		int u, v, id;
		boolean alive;
		public Edge(int u, int v, int id) {
			this.u = u;
			this.v = v;
			this.id = id;
			alive = true;
		}
	}
	
	private static void dfs(int cur, Map<Integer, Queue<Edge>> rem, List<Edge> route)
	{
		while(!rem.get(cur).isEmpty()) {
			Edge e = rem.get(cur).poll();
			if(e.alive) {
				e.alive = false;
				if(cur == e.u){
					int d = e.v; e.v = e.u; e.u = d;
				}
				dfs(e.u ^ e.v ^ cur, rem, route);
				route.add(e);
			}
		}
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
	
	public static void main(String[] args) throws Exception { new C2().run(); }
	
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