//package round561;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class F2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	Map<Long, Integer> duals = new HashMap<>();
	DisjointSetOfList ds = null;
	List<List<Integer>> g = new ArrayList<>();
	List<Set<Integer>> N = new ArrayList<>();
	
	void connect(int x, int y, int color)
	{
		g.get(x).add(y);
		g.get(y).add(x);
		N.get(y).add(ds.root(x));
		N.get(x).add(ds.root(y));
		
		if(duals.containsKey((long)y<<32|color)){
			int dy = duals.get((long)y<<32|color);
			ds.union(x, dy);
		}else{
			duals.put((long)y<<32|color, x);
		}
			
		if(duals.containsKey((long)x<<32|color)){
			int dx = duals.get((long)x<<32|color);
			ds.union(y, dx);
		}else{
			duals.put((long)x<<32|color, y);
		}
	}
	
	void solve()
	{
		int n = ni(), m = ni(), C = ni(), Q = ni();
		ds = new DisjointSetOfList(n);
		ds.g = g;
		ds.N = N;
		for(int i = 0;i < n;i++)g.add(new ArrayList<>());
		for(int i = 0;i < n;i++)N.add(new HashSet<>());
		
		for(int i = 0;i < m;i++){
			int x = ni()-1, y = ni()-1;
			int color = ni();
			connect(x, y, color);
		}
		
		for(int i = 0;i < Q;i++){
			char c = nc();
			if(c == '+'){
				int x = ni()-1, y = ni()-1, color = ni();
				connect(x, y, color);
			}else{
				int x = ni()-1, y = ni()-1;
				out.println(ds.equiv(x, y) || N.get(y).contains(ds.root(x)) ? "Yes" : "No");
			}
		}
	}
	
	public static class DisjointSetOfList {
		public int[] upper;
		public int[] next;
		public int[] last;
		List<List<Integer>> g;
		List<Set<Integer>> N;

		public DisjointSetOfList(int n) {
			upper = new int[n];
			Arrays.fill(upper, -1);
			next = new int[n];
			last = new int[n];
			Arrays.fill(next, -1);
			for(int i = 0;i < n;i++){
				last[i] = i;
			}
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
				for(int z = y;z != -1;z = next[z]){
					for(int e : g.get(z)){
						N.get(e).remove(y);
						N.get(e).add(x);
					}
				}
				
				upper[x] += upper[y];
				upper[y] = x;
				next[last[x]] = y;
				last[x] = last[y];
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

	
	void run() throws Exception
	{
//		int n = 100000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		sb.append(n + " ");
//		sb.append(m + " ");
//		Set<Long> set = new HashSet<>();
//		for (int i = 0; i < m; i++) {
//			while(true){
//				int x = gen.nextInt((int)Math.sqrt(n))+1;
//				int y = gen.nextInt(n)+1;
//				if(x > y){
//					int d = x; x = y; y = d;
//				}
//				if(x == y)continue;
//				if(set.contains((long)x<<32|y))continue;
//				set.add((long)x<<32|y);
//				sb.append(x + " " + y + " " + (gen.nextInt(100000)+1) + "\n");
//				break;
//			}
//		}
//		for (int i = 0; i < m; i++) {
//			int t = gen.nextInt(2);
//			if(t == 0){
//				while(true){
//					int x = gen.nextInt((int)Math.sqrt(n))+1;
//					int y = gen.nextInt(n)+1;
//					if(x > y){
//						int d = x; x = y; y = d;
//					}
//					if(x == y)continue;
//					if(set.contains((long)x<<32|y))continue;
//					set.add((long)x<<32|y);
//					sb.append("+" + " " + x + " " + y + " " + (gen.nextInt(100000)+1) + "\n");
//					break;
//				}
//			}else{
//				while(true){
//					int x = gen.nextInt(n)+1;
//					int y = gen.nextInt(n)+1;
//					if(x == y)continue;
//					sb.append("?" + " " + x + " " + y + "\n");
//					break;
//				}
//			}
//		}
//		INPUT = sb.toString();

		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new F2().run(); }
	
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