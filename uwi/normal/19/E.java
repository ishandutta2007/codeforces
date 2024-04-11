//package sandbox;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class P19E3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] es = new int[m][];
		for(int i = 0;i < m;i++){
			es[i] = new int[]{ni()-1, ni()-1};
		}
		int S = (int)Math.sqrt(m);
		
		List<Integer> ok = new ArrayList<Integer>();
		outer:
		for(int i = 0;i < m;i+=S){
			DisjointSet ds = new DisjointSet(n);
			for(int j = 0;j < m;j++){
				if(j >= i && j < i+S)continue;
				if(ds.contradict(es[j][0], es[j][1]))continue outer;
				ds.union(es[j][0], es[j][1]);
			}
			boolean[] aped = new boolean[n];
			for(int j = i;j < i+S && j < m;j++){
				aped[es[j][0]] = aped[es[j][1]] = true;
			}
			int[] imap = new int[n];
			int[] map = new int[n];
			int p = 0;
			for(int j = 0;j < n;j++){
				if(aped[j]){
					map[j] = p;
					imap[p++] = j;
				}
			}
			
			DisjointSet dummy = new DisjointSet(p);
			for(int j = 0;j < p;j++){
				for(int k = j+1;k < p;k++){
					if(ds.equiv(imap[j], imap[k])){
						dummy.weakUnion(j, k);
					}
				}
				dummy.color[j] = ds.color[imap[j]];
			}
			
			inner:
			for(int j = i;j < i+S && j < m;j++){
				DisjointSet lds = new DisjointSet(dummy);
//				for(int k = 0;k < p;k++){
//					lds.color[k] = ds.color[imap[k]];
//				}
//				tr(lds.color);
//				tr(lds.upper);
				
				for(int k = i;k < i+S && k < m;k++){
					if(k == j)continue;
					if(lds.contradict(map[es[k][0]], map[es[k][1]]))continue inner;
					lds.union(map[es[k][0]], map[es[k][1]]);
				}
				ok.add(j+1);
			}
		}
		out.println(ok.size());
		for(int v : ok){
			out.print(v + " ");
		}
	}
	
	static int gct = 0;
	
	public static class DisjointSet {
		public int[] upper; // minus:num_element(root) plus:root(normal)
		public boolean[] color;
		public List<List<Integer>> member;
		
		public DisjointSet(int n)
		{
			upper = new int[n];
			Arrays.fill(upper, -1);
			color = new boolean[n];
			member = new ArrayList<List<Integer>>();
			for(int i = 0;i < n;i++){
				List<Integer> L = new ArrayList<Integer>();
				L.add(i);
				member.add(L);
			}
		}
		
		public DisjointSet(DisjointSet ds)
		{
			this.upper = Arrays.copyOf(ds.upper, ds.upper.length);
			this.color = Arrays.copyOf(ds.color, ds.color.length);
			member = new ArrayList<List<Integer>>();
			for(int i = 0;i < ds.member.size();i++){
				member.add(new ArrayList<Integer>(ds.member.get(i)));
			}
//			this.member = new int[ds.member.length][];
//			for(int i = 0;i < this.member.length;i++){
//				if(ds.upper[i] < 0){
//					this.member[i] = Arrays.copyOf(ds.member[i], ds.member[i].length);
//				}
//			}
		}		
		public int root(int x)
		{
			return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
		}
		
		public boolean equiv(int x, int y)
		{
			return root(x) == root(y);
		}
		
		public boolean contradict(int x, int y)
		{
			return root(x) == root(y) && color[x] == color[y];
		}
		
		public boolean union(int x, int y)
		{
			int a = x, b = y;
			x = root(x);
			y = root(y);
			if(x != y) {
				if(upper[y] < upper[x]) {
					int d = x; x = y; y = d;
				}
				if(color[a] == color[b]){
					for(int v : member.get(y))color[v] ^= true;
				}
				member.get(x).addAll(member.get(y));
				upper[x] += upper[y];
				upper[y] = x;
			}
			return x == y;
		}
		
		public boolean weakUnion(int x, int y)
		{
			x = root(x);
			y = root(y);
			if(x != y) {
				if(upper[y] < upper[x]) {
					int d = x; x = y; y = d;
				}
				member.get(x).addAll(member.get(y));
				upper[x] += upper[y];
				upper[y] = x;
			}
			return x == y;
		}
		
		public int count()
		{
			int ct = 0;
			for(int u : upper){
				if(u < 0)ct++;
			}
			return ct;
		}
		
		public int[][] makeUp()
		{
			int n = upper.length;
			int[][] ret = new int[n][];
			int[] rp = new int[n];
			for(int i = 0;i < n;i++){
				if(upper[i] < 0)ret[i] = new int[-upper[i]];
			}
			for(int i = 0;i < n;i++){
				int r = root(i);
				ret[r][rp[r]++] = i;
			}
			return ret;
		}
	}
	
	void run() throws Exception
	{
//		int n = 10000, m = 2000;
////		int n = 10, m = 10;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		for (int i = 0; i < m; i++) {
////			sb.append((i+1) + " ");
////			sb.append((i+1)%n+1 + " ");
//			sb.append(gen.nextInt(n)+1 + " ");
//			sb.append(gen.nextInt(n)+1 + " ");
//		}
////		tr(sb);
////		tr(sb.substring(sb.length()-100));
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new P19E3().run(); }
	
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