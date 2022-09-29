//package intelcc2016.f;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class G {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		long[] w = new long[m];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
			w[i] = nl();
		}
		
		DJSet ds = new DJSet(n);
		for(int i = 0;i < m;i++){
			ds.union(from[i], to[i]);
		}
		
		int[] clus = new int[n];
		for(int i = 0;i < n;i++){
			clus[i] = ds.root(i);
		}
		int[] eclus = new int[m];
		for(int i = 0;i < m;i++){
			eclus[i] = ds.root(from[i]);
		}
		
		int[][] buc = makeBuckets(clus, n);
		int[][] ebuc = makeBuckets(eclus, n);
		long ret = 0;
		for(int i = 0;i < n;i++){
			if(ds.upper[i] < 0){
				int[] ns = buc[i];
				int[] es = ebuc[i];
				Arrays.sort(ns);
				int[] ff = new int[es.length];
				int[] tt = new int[es.length];
				long[] ww = new long[es.length];
				for(int j = 0;j < es.length;j++){
					int id = es[j];
					ff[j] = Arrays.binarySearch(ns, from[id]);
					tt[j] = Arrays.binarySearch(ns, to[id]);
					ww[j] = w[id];
				}
				ret += go(ff, tt, ww, ns.length);
			}
		}
		out.println(ret%mod);
	}
	
	public static GraphW packWU(int n, int[] from, int[] to, long[] w)
	{
		int[][] g = new int[n][];
		long[][] wg = new long[n][];
		int[] p = new int[n];
		for(int f : from)p[f]++;
		for(int t : to)p[t]++;
		for(int i = 0;i < n;i++){
			g[i] = new int[p[i]];
			wg[i] = new long[p[i]];
		}
		for(int i = 0;i < from.length;i++){
			--p[from[i]];
			g[from[i]][p[from[i]]] = to[i];
			wg[from[i]][p[from[i]]] = w[i];
			--p[to[i]];
			g[to[i]][p[to[i]]] = from[i];
			wg[to[i]][p[to[i]]] = w[i];
		}
		GraphW gw = new GraphW();
		gw.g = g; gw.wg = wg;
		return gw;
	}
	
	public static class GraphW
	{
		public int[][] g;
		public long[][] wg;
	}
	
	long go(int[] from, int[] to, long[] w, int n)
	{
		int m = from.length;
		DJSet ds = new DJSet(n);
		int[] ff = new int[n-1];
		int[] tt = new int[n-1];
		long[] ww = new long[n-1];
		boolean[] ine = new boolean[m];
		int p = 0;
		for(int i = 0;i < m;i++){
			if(!ds.union(from[i], to[i])){
				ff[p] = from[i]; tt[p] = to[i]; ww[p] = w[i]; p++;
				ine[i] = true;
			}
		}
		assert p == n-1;
		
		GraphW gw = packWU(n, ff, tt, ww);
		int[][] g = gw.g;
		long[][] wg = gw.wg;
		
		int[][] pars = parents3(g, 0);
		int[] par = pars[0];
		int[] ord = pars[1];
		
		long[] dw = new long[n];
		for(int i = 0;i < n;i++){
			int cur = ord[i];
			for(int j = 0;j < g[cur].length;j++){
				int e = g[cur][j];
				if(e != par[cur]){
					dw[e] = dw[cur] ^ wg[cur][j];
				}
			}
		}
		
		long[] bas = new long[64];
		for(int i = 0;i < m;i++){
			if(!ine[i]){
				long x = dw[from[i]] ^ dw[to[i]] ^ w[i];
				int h = 63-Long.numberOfLeadingZeros(x);
				while(x != 0){
					if(bas[h] != 0){
						x ^= bas[h];
						h = 63-Long.numberOfLeadingZeros(x);
					}else{
						bas[h] = x;
					}
				}
			}
		}
		long ret = 0;
		for(int d = 60;d >= 0;d--){
			int b0 = 0, b1 = 0;
			int p0 = 0, p1 = 0;
			for(long b : bas){
				if(b != 0){
					if(b<<~d<0){
						b1++;
					}else{
						b0++;
					}
				}
			}
			for(int i = 0;i < n;i++){
				if(dw[i]<<~d<0){
					p1++;
				}else{
					p0++;
				}
			}
			long ij1 = (long)p1*p0;
			long ij0 = ((long)p0*p0+(long)p1*p1-n)/2;
			ij1 %= mod;
			ij0 %= mod;
			long r0 = pow(p2, b0+Math.max(0, b1-1), mod);
			long r1 = b1 == 0 ? 0 : pow(p2, b0+b1-1, mod);
			ret = ret * 2 + ij0*r1+ij1*r0;
			ret %= mod;
//			tr(d, b0, b1, p0, p1, r0, r1, ret, dw, bas);
		}
		return ret;
	}
	
	int mod = 1000000007;
	long[] p2 = generateP2(2, mod);
	
	public static long[] generateP2(long a, long mod)
	{
		long[] p2 = new long[64];
		p2[0] = a % mod;
		for(int i = 1;i < p2.length;i++)p2[i] = p2[i-1] * p2[i-1] % mod;
		return p2;
	}
	
	public static long pow(long[] p2, long n, long mod)
	{
		long ret = 1; // 1%mod if mod=1,n=0
		for(;n > 0;n &= n-1)ret = ret * p2[Long.numberOfTrailingZeros(n)] % mod;
		return ret;
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

	
	public static int[][] makeBuckets(int[] a, int sup)
	{
		int n = a.length;
		int[][] bucket = new int[sup+1][];
		int[] bp = new int[sup+1];
		for(int i = 0;i < n;i++)bp[a[i]]++;
		for(int i = 0;i <= sup;i++)bucket[i] = new int[bp[i]];
		for(int i = n-1;i >= 0;i--)bucket[a[i]][--bp[a[i]]] = i;
		return bucket;
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
//		int n = 100000, m = 199999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		for (int i = 0; i < m; i++) {
//			sb.append(gen.nextInt(n)+1 + " ");
//			sb.append(gen.nextInt(n)+1 + " ");
//			sb.append(
//					Math.abs(gen.nextLong() % 1000000000000000000L) + " ");
//		}
//		INPUT = sb.toString();

		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new G().run(); }
	
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