//package round375;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class F {
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
		int s = ni()-1, t = ni()-1;
		int degs = ni(), degt = ni();
		
		DJSet ods = new DJSet(n);
		for(int i = 0;i < m;i++){
			ods.union(from[i], to[i]);
		}
		if(ods.count() != 1){
			out.println("No");
			return;
		}
		
		DJSet ds = new DJSet(n);
		for(int i = 0;i < m;i++){
			if(from[i] == s || to[i] == s)continue;
			if(from[i] == t || to[i] == t)continue;
			ds.union(from[i], to[i]);
		}
		
		boolean[] cons = new boolean[n];
		boolean[] cont = new boolean[n];
		for(int i = 0;i < m;i++){
			if(from[i] == s)cons[ds.root(to[i])] = true;
			if(to[i] == s)cons[ds.root(from[i])] = true;
			if(from[i] == t)cont[ds.root(to[i])] = true;
			if(to[i] == t)cont[ds.root(from[i])] = true;
		}
		cons[s] = true;
		cont[t] = true;
		
		int consonly = 0;
		int contonly = 0;
		int common = 0;
		int[] commons = new int[n];
		Arrays.fill(commons, -1);
		for(int i = 0;i < n;i++){
			if(i == s || i == t)continue;
			if(ds.upper[i] >= 0)continue;
			if(cons[i] && !cont[i]){
				consonly++;
			}
			if(!cons[i] && cont[i]){
				contonly++;
			}
			if(cons[i] && cont[i]){
				commons[i] = common++;
			}
		}
		
		boolean st = false;
		for(int i = 0;i < m;i++){
			if(from[i] == s && to[i] == t || from[i] == t && to[i] == s)st = true;
		}
		boolean stcut = false;
		DJSet pds = new DJSet(n);
		for(int i = 0;i < m;i++){
			if(from[i] == s && to[i] == t || from[i] == t && to[i] == s)continue;
			pds.union(from[i], to[i]);
		}
		if(pds.count() != 1){
			stcut = true;
		}
		
		if(degs < consonly+1){
			out.println("No");
			return;
		}
		if(degt < contonly+1){
			out.println("No");
			return;
		}
		if(!st){
			degs -= consonly;
			degt -= contonly;
			if(degs + degt < common + 1){
				out.println("No");
				return;
			}
			
			out.println("Yes");
			
			DJSet lds = new DJSet(n);
			int[] deg = new int[n];
			for(int i = 0;i < m;i++){
				if(from[i] == s || to[i] == s)continue;
				if(from[i] == t || to[i] == t)continue;
				if(!lds.union(from[i], to[i])){
					deg[from[i]]++; deg[to[i]]++;
					out.println((from[i]+1) + " " + (to[i]+1));
				}
			}
			
			boolean[] ok = new boolean[m];
			for(int i = 0;i < m;i++){
				if(from[i] == s && cons[lds.root(to[i])] && cont[lds.root(to[i])] && commons[lds.root(to[i])] < degs){
					ok[i] = true;
				}
				if(to[i] == s && cons[lds.root(from[i])] && cont[lds.root(from[i])] && commons[lds.root(from[i])] < degs){
					ok[i] = true;
				}
				if(from[i] == t && cons[lds.root(to[i])] && cont[lds.root(to[i])] && commons[lds.root(to[i])] >= common - degt){
					ok[i] = true;
				}
				if(to[i] == t && cons[lds.root(from[i])] && cont[lds.root(from[i])] && commons[lds.root(from[i])] >= common - degt){
					ok[i] = true;
				}
			}
			
			for(int i = 0;i < m;i++){
				if(from[i] == s && cons[lds.root(to[i])] && !cont[lds.root(to[i])] && !lds.union(from[i], to[i])){
					deg[from[i]]++; deg[to[i]]++;
					out.println((from[i]+1) + " " + (to[i]+1));
				}
				if(to[i] == s && cons[lds.root(from[i])] && !cont[lds.root(from[i])] && !lds.union(from[i], to[i])){
					deg[from[i]]++; deg[to[i]]++;
					out.println((from[i]+1) + " " + (to[i]+1));
				}
				if(from[i] == t && cont[lds.root(to[i])] && !cons[lds.root(to[i])] && !lds.union(from[i], to[i])){
					deg[from[i]]++; deg[to[i]]++;
					out.println((from[i]+1) + " " + (to[i]+1));
				}
				if(to[i] == t && cont[lds.root(from[i])] && !cons[lds.root(from[i])] && !lds.union(from[i], to[i])){
					deg[from[i]]++; deg[to[i]]++;
					out.println((from[i]+1) + " " + (to[i]+1));
				}
				if(ok[i] && !lds.union(from[i], to[i])){
					deg[from[i]]++; deg[to[i]]++;
					out.println((from[i]+1) + " " + (to[i]+1));
				}
			}
			assert deg[s] <= degs + consonly;
			assert deg[t] <= degt + contonly;
			assert lds.count() == 1;
		}else if(!stcut){
			degs -= consonly;
			degt -= contonly;
			if(degs + degt < common + 1){
				out.println("No");
				return;
			}
			
			out.println("Yes");
			
			DJSet lds = new DJSet(n);
			int[] deg = new int[n];
			for(int i = 0;i < m;i++){
				if(from[i] == s || to[i] == s)continue;
				if(from[i] == t || to[i] == t)continue;
				if(!lds.union(from[i], to[i])){
					deg[from[i]]++; deg[to[i]]++;
					out.println((from[i]+1) + " " + (to[i]+1));
				}
			}
			
			boolean[] ok = new boolean[m];
			for(int i = 0;i < m;i++){
				if(from[i] == s && to[i] == t || from[i] == t && to[i] == s)continue;
				if(from[i] == s && cons[lds.root(to[i])] && cont[lds.root(to[i])] && commons[lds.root(to[i])] < degs){
					ok[i] = true;
				}
				if(to[i] == s && cons[lds.root(from[i])] && cont[lds.root(from[i])] && commons[lds.root(from[i])] < degs){
					ok[i] = true;
				}
				if(from[i] == t && cons[lds.root(to[i])] && cont[lds.root(to[i])] && commons[lds.root(to[i])] >= common - degt){
					ok[i] = true;
				}
				if(to[i] == t && cons[lds.root(from[i])] && cont[lds.root(from[i])] && commons[lds.root(from[i])] >= common - degt){
					ok[i] = true;
				}
			}
			
			for(int i = 0;i < m;i++){
				if(from[i] == s && cons[lds.root(to[i])] && !cont[lds.root(to[i])] && !lds.union(from[i], to[i])){
					deg[from[i]]++; deg[to[i]]++;
					out.println((from[i]+1) + " " + (to[i]+1));
				}
				if(to[i] == s && cons[lds.root(from[i])] && !cont[lds.root(from[i])] && !lds.union(from[i], to[i])){
					deg[from[i]]++; deg[to[i]]++;
					out.println((from[i]+1) + " " + (to[i]+1));
				}
				if(from[i] == t && cont[lds.root(to[i])] && !cons[lds.root(to[i])] && !lds.union(from[i], to[i])){
					deg[from[i]]++; deg[to[i]]++;
					out.println((from[i]+1) + " " + (to[i]+1));
				}
				if(to[i] == t && cont[lds.root(from[i])] && !cons[lds.root(from[i])] && !lds.union(from[i], to[i])){
					deg[from[i]]++; deg[to[i]]++;
					out.println((from[i]+1) + " " + (to[i]+1));
				}
				if(ok[i] && !lds.union(from[i], to[i])){
					deg[from[i]]++; deg[to[i]]++;
					out.println((from[i]+1) + " " + (to[i]+1));
				}
			}
			
			assert deg[s] <= degs + consonly;
			assert deg[t] <= degt + contonly;
			assert lds.count() == 1;
		}else{
			assert common == 0;
			degs -= consonly;
			degt -= contonly;
			if(degs < 1 || degt < 1){
				out.println("No");
				return;
			}
			
			out.println("Yes");
			
			DJSet lds = new DJSet(n);
			int[] deg = new int[n];
			for(int i = 0;i < m;i++){
				if(from[i] == s || to[i] == s)continue;
				if(from[i] == t || to[i] == t)continue;
				if(!lds.union(from[i], to[i])){
					deg[from[i]]++; deg[to[i]]++;
					out.println((from[i]+1) + " " + (to[i]+1));
				}
			}
			
			for(int i = 0;i < m;i++){
				if(from[i] == s && to[i] == t || from[i] == t && to[i] == s){
					lds.union(s, t);
					deg[from[i]]++; deg[to[i]]++;
					out.println((from[i]+1) + " " + (to[i]+1));
				}
				if(from[i] == s && cons[lds.root(to[i])] && !cont[lds.root(to[i])] && !lds.union(from[i], to[i])){
					deg[from[i]]++; deg[to[i]]++;
					out.println((from[i]+1) + " " + (to[i]+1));
				}
				if(to[i] == s && cons[lds.root(from[i])] && !cont[lds.root(from[i])] && !lds.union(from[i], to[i])){
					deg[from[i]]++; deg[to[i]]++;
					out.println((from[i]+1) + " " + (to[i]+1));
				}
				if(from[i] == t && cont[lds.root(to[i])] && !cons[lds.root(to[i])] && !lds.union(from[i], to[i])){
					deg[from[i]]++; deg[to[i]]++;
					out.println((from[i]+1) + " " + (to[i]+1));
				}
				if(to[i] == t && cont[lds.root(from[i])] && !cons[lds.root(from[i])] && !lds.union(from[i], to[i])){
					deg[from[i]]++; deg[to[i]]++;
					out.println((from[i]+1) + " " + (to[i]+1));
				}
			}
			
			assert deg[s] <= degs + consonly;
			assert deg[t] <= degt + contonly;
			assert lds.count() == 1;
			
		}
	}
	
	public static class DJSet {
		public int[] upper;
		
		public DJSet(DJSet ds)
		{
			this.upper = Arrays.copyOf(ds.upper, ds.upper.length);
		}

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
	
	public static void main(String[] args) throws Exception { new F().run(); }
	
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