//package round453;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Queue;
import java.util.Set;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		long[] v = new long[n];
		for(int i = 0;i < n;i++)v[i] = nl();
		int[] from = new int[m];
		int[] to = new int[m];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
		}
		int[][] g = packU(n, from, to);
		Queue<Integer> q = new ArrayDeque<>();
		int[] color = new int[n];
		color[0] = 1;
		q.add(0);
		int[] vi = null;
		int[] prev = new int[n];
		prev[0] = -1;
		outer:
		while(!q.isEmpty()){
			int cur = q.poll();
			for(int e : g[cur]){
				if(color[e] == 0){
					color[e] = -color[cur];
					prev[e] = cur;
					q.add(e);
				}else if(color[e] == color[cur]){
					vi = new int[]{e, cur};
					break outer;
				}
			}
		}
		
		Set<Long> immune = new HashSet<>();
		if(vi != null){
			for(int x = vi[0];x != 0;x = prev[x]){
				long u = prev[x], o = x;
				long code = (long)Math.min(u, o)<<32|Math.max(u, o);
				immune.add(code);
			}
			for(int x = vi[1];x != 0;x = prev[x]){
				long u = prev[x], o = x;
				long code = (long)Math.min(u, o)<<32|Math.max(u, o);
				immune.add(code);
			}
		}
		
		int[] xfrom = new int[n-1];
		int[] xto = new int[n-1];
		DJSet ds = new DJSet(n);
		int p = 0;
		for(int i = 0;i < m;i++){
			long code = (long)Math.min(from[i], to[i])<<32|Math.max(from[i], to[i]);
			if(immune.contains(code)){
				if(!ds.union(from[i], to[i])){
					xfrom[p] = from[i];
					xto[p] = to[i];
					p++;
				}
			}
		}
		for(int i = 0;i < m;i++){
			if(vi != null && from[i] == vi[0] && to[i] == vi[1])continue;
			if(vi != null && to[i] == vi[0] && from[i] == vi[1])continue;
			if(!ds.union(from[i], to[i])){
				xfrom[p] = from[i];
				xto[p] = to[i];
				p++;
			}
		}
		assert p == n-1;
		int[][] h = packU(n, xfrom, xto);
		int[][] pars = parents3(h, 0);
		
		long[] pw = new long[n];
		int[] tc = new int[n];
		int[] ord = pars[1], par = pars[0];
		for(int i = n-1;i >= 0;i--){
			int cur = ord[i];
			for(int e : h[cur]){
				if(par[cur] == e)continue;
				v[cur] -= pw[e];
				tc[cur] -= tc[e];
			}
			if(vi != null && vi[0] == cur){
				tc[cur]--;
			}
			if(vi != null && vi[1] == cur){
				tc[cur]--;
			}
			pw[cur] = v[cur];
			if(cur == 0 && v[cur] != 0 && tc[cur] == 0){
				out.println("NO");
				assert vi == null;
				return;
			}
		}
		long t = 0;
		if(tc[0] != 0){
			// pw[0]+t*tc[0] = 0
			t = -pw[0] / tc[0];
		}
		out.println("YES");
		for(int i = 0;i < m;i++){
			if(vi != null && from[i] == vi[0] && to[i] == vi[1]){
				out.println(t);
				continue;
			}
			if(vi != null && to[i] == vi[0] && from[i] == vi[1]){
				out.println(t);
				continue;
			}
			if(par[from[i]] == to[i]){
				out.println(pw[from[i]] + tc[from[i]] * t);
				continue;
			}
			if(par[to[i]] == from[i]){
				out.println(pw[to[i]] + tc[to[i]] * t);
				continue;
			}
			out.println(0);
		}
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
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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