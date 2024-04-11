//package round396;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), Q = ni();
		String[] ss = new String[n];
		Map<String, Integer> map = new HashMap<>();
		for(int i = 0;i < n;i++){
			ss[i] = ns();
			map.put(ss[i], i);
		}
		DJSet ds = new DJSet(n);
		outer:
		for(int i = 0;i < m;i++){
			int rel = ni();
			int aid = map.get(ns());
			int bid = map.get(ns());
			if(rel == 1){
				if(ds.enemy[ds.root(aid)] == ds.root(bid)){
					out.println("NO");
					continue outer;
				}
				int ea = ds.enemy[ds.root(aid)];
				int eb = ds.enemy[ds.root(bid)];
				ds.union(aid, bid);
				if(ea != -1 && eb != -1){
					ds.union(ea, eb);
				}else if(ea == -1 && eb != -1){
					ea = eb;
				}
				if(ea != -1){
					int er = ds.root(ea);
					int r = ds.root(aid);
					ds.enemy[er] = r;
					ds.enemy[r] = er;
				}
			}else{
				if(ds.equiv(aid, bid)){
					out.println("NO");
					continue outer;
				}
				int ea = ds.enemy[ds.root(aid)];
				int eb = ds.enemy[ds.root(bid)];
				if(ea != -1)ds.union(ea, bid);
				if(eb != -1)ds.union(eb, aid);
				int ra = ds.root(aid);
				int rb = ds.root(bid);
				ds.enemy[ra] = rb;
				ds.enemy[rb] = ra;
			}
			out.println("YES");
		}
		for(int i = 0;i < Q;i++){
			int a = map.get(ns());
			int b = map.get(ns());
			if(ds.equiv(a, b)){
				out.println(1);
			}else if(ds.enemy[ds.root(a)] != -1 && ds.equiv(ds.enemy[ds.root(a)], b)){
				out.println(2);
			}else{
				out.println(3);
			}
		}
	}
	
	public static class DJSet {
		public int[] upper;
		public int[] enemy;

		public DJSet(int n) {
			upper = new int[n];
			Arrays.fill(upper, -1);
			enemy = new int[n];
			Arrays.fill(enemy, -1);
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