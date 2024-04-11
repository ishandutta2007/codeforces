//package round286;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.Random;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		int[] w = new int[m];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
			w[i] = ni();
		}
		int[][][] g = packWU(n, from, to, w);
		for(int[][] row : g){
			Arrays.sort(row, new Comparator<int[]>() {
				public int compare(int[] a, int[] b) {
					return a[1] - b[1];
				}
			});
		}
		
		int s = (int)Math.sqrt(m);
		int r = 0;
		int[] majors = new int[n];
		boolean[] major = new boolean[n];
		for(int i = 0;i < n;i++){
			if(g[i].length >= s){
				major[i] = true;
				majors[r++] = i;
			}
		}
		majors = Arrays.copyOf(majors, r);
		int[][] mm = new int[r][r];
		for(int i = 0;i < r;i++){
			Arrays.fill(mm[i], -1);
		}
		
		int[][] es = new int[m][];
		for(int i = 0;i < m;i++){
			es[i] = new int[]{from[i], to[i], w[i]};
		}
		Arrays.sort(es, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[2] - b[2];
			}
		});
		
		DJSet[] dss = new DJSet[100002];
		int[][] maps = new int[100002][];
		Random gen = new Random();
		for(int i = 0;i < m;){
			int j = i;
			for(;j < m && es[i][2] == es[j][2];j++);
			int y = es[i][2];
			
			int[] ap = new int[2*(j-i)];
			int p = 0;
			for(int k = i;k < j;k++){
				int x = gen.nextInt(2);
				ap[p++] = es[k][0^x];
				ap[p++] = es[k][1^x];
			}
			Arrays.sort(ap);
			
			int q = 0;
			for(int k = 0;k < 2*(j-i);k++){
				if(k == 0 || ap[k] != ap[k-1]){
					ap[q++] = ap[k];
				}
			}
			maps[y] = Arrays.copyOf(ap, q);
			
			DJSet ds = new DJSet(q);
			for(int k = i;k < j;k++){
				int f = Arrays.binarySearch(ap, 0, q, es[k][0]);
				int t = Arrays.binarySearch(ap, 0, q, es[k][1]);
				ds.union(f, t);
			}
			dss[y] = ds;
			
			i = j;
		}
		
		for(int i = 0;i < r;i++){
			for(int j = i+1;j < r;j++){
				
			}
		}
		
		for(int Q = ni();Q >= 1;Q--){
			int f = ni()-1, t = ni()-1;
			if(g[t].length < g[f].length){
				int d = f; f = t; t = d;
			}
			if(major[f] && major[t]){
				int v = mm[Arrays.binarySearch(majors, f)][Arrays.binarySearch(majors, t)];
				if(v != -1){
					out.println(v);
					continue;
				}
			}
			
			int prev = -1;
			int ct = 0;
			for(int[] e : g[f]){
				if(e[1] != prev){
					prev = e[1];
					
					int indt = Arrays.binarySearch(maps[e[1]], t);
					if(indt < 0)continue;
					int indf = Arrays.binarySearch(maps[e[1]], f);
					if(dss[e[1]].equiv(indf, indt)){
						ct++;
					}
				}
			}
			if(major[f] && major[t]){
				mm[Arrays.binarySearch(majors, f)][Arrays.binarySearch(majors, t)] = ct;
			}
			out.println(ct);
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
	
	public static int[][][] packWU(int n, int[] from, int[] to, int[] w) {
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for (int f : from)
			p[f]++;
		for (int t : to)
			p[t]++;
		for (int i = 0; i < n; i++)
			g[i] = new int[p[i]][2];
		for (int i = 0; i < from.length; i++) {
			--p[from[i]];
			g[from[i]][p[from[i]]][0] = to[i];
			g[from[i]][p[from[i]]][1] = w[i];
			--p[to[i]];
			g[to[i]][p[to[i]]][0] = from[i];
			g[to[i]][p[to[i]]][1] = w[i];
		}
		return g;
	}
	
	void run() throws Exception
	{
		int n = 100000, m = 99999;
		Random gen = new Random();
		StringBuilder sb = new StringBuilder();
		sb.append(n + " ");
		sb.append(n-1 + " ");
		for (int i = 0; i < n-1; i++) {
			sb.append(1 + " ");
			sb.append(2 + " ");
			sb.append((i+1) + " ");
		}
		sb.append(m + " ");
		for (int i = 0; i < m; i++) {
			sb.append(1 + " ");
			sb.append(2 + " ");
//			sb.append(gen.nextInt(n)+1 + " ");
//			sb.append(gen.nextInt(n)+1 + " ");
		}
		INPUT = sb.toString();
		
//		int n = 100000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(n-1 + " ");
//		for (int i = 0; i < n-1; i++) {
//			sb.append((i+1) + " ");
//			sb.append((i+2) + " ");
//			sb.append((i+1) + " ");
//		}
//		sb.append(m + " ");
//		for (int i = 0; i < m; i++) {
//			sb.append(gen.nextInt(n)+1 + " ");
//			sb.append(gen.nextInt(n)+1 + " ");
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
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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