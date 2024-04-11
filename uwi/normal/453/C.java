//package round259;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
		}
		int[][] g = packU(n, from, to);
		int[] parity = na(n);
//		int[] prt = Arrays.copyOf(parity, n);
		
		int one = -1;
		for(int i = 0;i < n;i++){
			if(parity[i] == 1){
				one = i;
			}
		}
		if(one == -1){
			out.println(0);
			return;
		}
		DJSet ds = new DJSet(n);
		for(int i = 0;i < m;i++){
			ds.union(from[i], to[i]);
		}
		for(int i = 0;i < n;i++){
			if(parity[i] == 1){
				if(!ds.equiv(i, one)){
					out.println(-1);
					return;
				}
			}
		}
		
		boolean[] ved = new boolean[n];
		List<Integer> hist = new ArrayList<Integer>();
		dfs(one, -1, ved, g, parity, hist);
//		tr(hist);
//		if(hist.size() > 4*n){
//			throw new RuntimeException("OUT! " + n);
//		}
//		for(int h : hist){
//			prt[h] ^= 1;
//		}
//		outer:
//		for(int i = 0;i < hist.size()-1;i++){
//			for(int e : g[hist.get(i)]){
//				if(e == hist.get(i+1)){
//					continue outer;
//				}
//			}
//			throw new RuntimeException("NOT CONNECTED");
//		}
//		for(int v : prt){
//			if(v != 0){
//				throw new RuntimeException(Arrays.toString(prt));
//			}
//		}
		
		out.println(hist.size());
		for(int i = 0;i < hist.size();i++){
			out.print(hist.get(i)+1);
			out.print(" ");
		}
		out.println();
	}
	
	void dfs(int cur, int pre, boolean[] ved, int[][] g, int[] parity, List<Integer> hist)
	{
		ved[cur] = true;
		boolean leaf = true;
		for(int e : g[cur]){
			if(!ved[e]){
				leaf = false;
			}
		}
		parity[cur] ^= 1;
		hist.add(cur);
		
		for(int e : g[cur]){
			if(!ved[e]){
				dfs(e, cur, ved, g, parity, hist);
				parity[cur] ^= 1;
				hist.add(cur);
			}
		}
		if(parity[cur] == 1){
			if(pre != -1){
				hist.add(pre);
				hist.add(cur);
				parity[cur] ^= 1;
				parity[pre] ^= 1;
			}else{
				hist.remove(hist.size()-1);
			}
		}
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
			if(x != y){
				if(upper[y] < upper[x]){
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
			for(int u : upper)
				if(u < 0)
					ct++;
			return ct;
		}
	}
	
	static int[][] packU(int n, int[] from, int[] to) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int f : from)
			p[f]++;
		for(int t : to)
			p[t]++;
		for(int i = 0;i < n;i++)
			g[i] = new int[p[i]];
		for(int i = 0;i < from.length;i++){
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