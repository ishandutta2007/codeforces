//package prac;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D556_2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), A = ni(), B = ni();
		int[][] es = new int[m][];
		for(int i = 0;i < m;i++) {
			es[i] = new int[] {ni()-1, ni()-1, ni()};
		}
		int[][][] g = packWU(n, es);
		DJSet ds = new DJSet(n);
		for(int i = 0;i < m;i++) {
			if(es[i][2] == A) {
				ds.union(es[i][0], es[i][1]);
			}
		}
		int[] ids = new int[n];
		Arrays.fill(ids, -1);
		int[] cs = new int[18];
		int p = 0;
		for(int i = 0;i < n;i++) {
			if(ds.upper[i] <= -4) {
				ids[i] = p;
				cs[p++] = i;
			}
		}
		cs = Arrays.copyOf(cs, p);
		int[][] dp = new int[n][1<<p];
		int I = Integer.MAX_VALUE / 2;
		for(int i = 0;i < n;i++)Arrays.fill(dp[i], I);
		int x = ids[ds.root(0)];
		
		MinHeap h = new MinHeap(n<<p);
		if(x != -1) {
			dp[0][1<<x] = 0;
			h.add((1<<x)*n+0, 0);
		}else {
			dp[0][0] = 0;
			h.add(0*n+0, 0);
		}
		while(h.size() > 0) {
			int argmin = h.argmin();
			int val = h.min();
			h.remove(argmin);
			int pos = (int)(argmin%n);
			int ptn = (int)(argmin/n);
//			tr(pos, ptn, val);
			
			for(int[] e : g[pos]) {
				if(e[1] == B) {
					if(ds.equiv(pos, e[0]))continue;
					int cind = ids[ds.root(e[0])];
					if(cind != -1 && ptn<<~cind<0)continue;
					
					int nptn = cind == -1 ? ptn : ptn|1<<cind;
					int nd = val + e[1];
					if(nd < dp[e[0]][nptn]) {
						h.update(nptn*n+e[0], dp[e[0]][nptn] = nd);
					}
				}else {
					int nd = val + e[1];
					if(nd < dp[e[0]][ptn]) {
						h.update(ptn*n+e[0], dp[e[0]][ptn] = nd);
					}
				}
			}
		}
		
		for(int j = 0;j < n;j++) {
			long ans = Long.MAX_VALUE;
			for(int i = 0;i < 1<<p;i++) {
				ans = Math.min(ans, dp[j][i]);
			}
			out.print(ans + " ");
		}
		out.println();
	}
	
	public static int[][][] packWU(int n, int[][] es) {
		int[][][] g = new int[n][][];
		if(es.length == 0)return g;
		int[] p = new int[n];
		for (int[] e : es) {
			p[e[0]]++;
			p[e[1]]++;
		}
		int u = es[0].length;
		for (int i = 0; i < n; i++)
			g[i] = new int[p[i]][u-1];
		for(int[] e : es) {
			--p[e[0]];
			for(int j = 0;j < u-1;j++) g[e[0]][p[e[0]]][j] = e[j+1];
			--p[e[1]];
			for(int j = 0;j < u-1;j++) g[e[1]][p[e[1]]][j] = e[j == 0 ? 0 : j+1];
		}
		return g;
	}

	
	public static class MinHeap {
		public int[] a;
		public int[] map;
		public int[] imap;
		public int n;
		public int pos;
		public static int INF = Integer.MAX_VALUE;
		
		public MinHeap(int m)
		{
			n = m+2;
			a = new int[n];
			map = new int[n];
			imap = new int[n];
			Arrays.fill(a, INF);
			Arrays.fill(map, -1);
			Arrays.fill(imap, -1);
			pos = 1;
		}
		
		public int add(int ind, int x)
		{
			int ret = imap[ind];
			if(imap[ind] < 0){
				a[pos] = x; map[pos] = ind; imap[ind] = pos;
				pos++;
				up(pos-1);
			}
			return ret != -1 ? a[ret] : x;
		}
		
		public int update(int ind, int x)
		{
			int ret = imap[ind];
			if(imap[ind] < 0){
				a[pos] = x; map[pos] = ind; imap[ind] = pos;
				pos++;
				up(pos-1);
			}else{
				int o = a[ret];
				a[ret] = x;
				up(ret);
				down(ret);
//				if(a[ret] > o){
//					up(ret);
//				}else{
//					down(ret);
//				}
			}
			return x;
		}
		
		public int remove(int ind)
		{
			if(pos == 1)return INF;
			if(imap[ind] == -1)return INF;
			
			pos--;
			int rem = imap[ind];
			int ret = a[rem];
			map[rem] = map[pos];
			imap[map[pos]] = rem;
			imap[ind] = -1;
			a[rem] = a[pos];
			a[pos] = INF;
			map[pos] = -1;
			
			up(rem);
			down(rem);
			return ret;
		}
		
		public int min() { return a[1]; }
		public int argmin() { return map[1]; }
		public int size() {	return pos-1; }
		
		private void up(int cur)
		{
			for(int c = cur, p = c>>>1;p >= 1 && a[p] > a[c];c>>>=1, p>>>=1){
				int d = a[p]; a[p] = a[c]; a[c] = d;
				int e = imap[map[p]]; imap[map[p]] = imap[map[c]]; imap[map[c]] = e;
				e = map[p]; map[p] = map[c]; map[c] = e;
			}
		}
		
		private void down(int cur)
		{
			for(int c = cur;2*c < pos;){
				int b = a[2*c] < a[2*c+1] ? 2*c : 2*c+1;
				if(a[b] < a[c]){
					int d = a[c]; a[c] = a[b]; a[b] = d;
					int e = imap[map[c]]; imap[map[c]] = imap[map[b]]; imap[map[b]] = e;
					e = map[c]; map[c] = map[b]; map[b] = e;
					c = b;
				}else{
					break;
				}
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
	
	public static void main(String[] args) throws Exception { new D556_2().run(); }
	
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