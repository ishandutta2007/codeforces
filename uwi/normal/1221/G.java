//package educational.round73;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class G2 {
	InputStream is;
	PrintWriter out;
//	String INPUT = "";
//	String INPUT = "";
	String INPUT = "";
	
	void solve()
	{
		// #all-(-#0-#1-#2+#01+#02+#12)
		// 2^n+(1+A+1-B-B)
		// 1 22^#CC=A
		// 011=B
		// 
		int n = ni(), m = ni();
		if(m == 0){
			out.println(0);
			return;
		}
		
		DJSet ds = new DJSet(n);
		long[] lg = new long[n];
		int[] from = new int[m];
		int[] to = new int[m];
		for(int i = 0;i < m;i++){
			int a = ni()-1, b = ni()-1;
			lg[a] |= 1L<<b;
			lg[b] |= 1L<<a;
			from[i] = a; to[i] = b;
			ds.union(a, b);
		}
		int[][] g = packU(n, from, to);
		long ans = 1L<<n;
		
		int z = 0;
		for(int i = 0;i < n;i++){
			if(-ds.upper[i] == 1)z++;
		}
		ans += 2L<<z;
		if(isBipartite(g) != null){
			ans += 1L<<ds.count();
		}
		
		// 64 + 2 + 0 - 22*2 - 2^2 = 
		
		ans -= 2L*(countIS(lg, (1L<<n)-1));
		ans -= 1L<<ds.count();
		out.println(ans);
	}
	
	long countIS(long[] g, long mask)
	{
		if(mask == 0)return 1;
		int max = -1;
		int arg = -1;
		for(long k = mask;k > 0;k &= k-1){
			int q = Long.numberOfTrailingZeros(k);
			if(Long.bitCount(mask&g[q]) > max){
				max = Long.bitCount(mask&g[q]);
				arg = q;
			}
		}
		int p = arg;
		if((mask&~g[p]) == mask){
			return 2L*countIS(g, mask&~(1L<<p));
		}else{
			return 
			countIS(g, mask&~g[p]&~(1L<<p)) +
			countIS(g, mask&~(1L<<p));
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

	
	public static int[] isBipartite(int[][] g)
	{
		int n = g.length;
		int[] color = new int[n];
		int[] q = new int[n];
		for(int i = 0;i < n;i++){
			if(color[i] == 0){
				int p = 0;
				q[p++] = i;
				color[i] = 1;
				for(int r = 0;r < p;r++){
					int cur = q[r];
					for(int e : g[cur]){
						if(color[e] == 0){
							color[e] = -color[cur];
							q[p++] = e;
						}else if(color[e] == color[cur]){
							return null;
						}
					}
				}
			}
		}
		return color;
	}

	
	public static long pow(long a, long n, long mod) {
		//		a %= mod;
		long ret = 1;
		int x = 63 - Long.numberOfLeadingZeros(n);
		for (; x >= 0; x--) {
			ret = ret * ret % mod;
			if (n << 63 - x < 0)
				ret = ret * a % mod;
		}
		return ret;
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
	
	public static void main(String[] args) throws Exception { new G2().run(); }
	
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