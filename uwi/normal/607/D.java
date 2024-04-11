//package round336;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int v0 = ni(), Q = ni();
		int[][] qs = new int[Q][];
		int[] par = new int[Q+1];
		par[0] = -1;
		int p = 1;
		int[] vs = new int[Q+1];
		vs[0] = v0;
		for(int i = 0;i < Q;i++){
			int t = ni();
			if(t == 1){
				qs[i] = new int[]{t, ni()-1, ni(), p};
				vs[p] = qs[i][2];
				par[p] = qs[i][1];
				p++;
			}else{
				qs[i] = new int[]{t, ni()-1};
			}
		}
		int[][] g = parentToG(Arrays.copyOf(par, p));
		int[][] rights = makeRights(g, Arrays.copyOf(par, p), 0);
		int[] ord = rights[0], iord = rights[1], right = rights[2];
		
		int mod = 1000000007;
		SegmentTreeRSQ st = new SegmentTreeRSQ(p);
		st.update(0, v0);
		int[] pmuls = new int[p];
		Arrays.fill(pmuls, 1);
		for(int i = 0;i < Q;i++){
			int[] q = qs[i];
			if(q[0] == 1){
				long pmul = pmuls[q[1]];
				pmuls[q[1]]++;
				long curmul = st.sum(iord[q[1]], iord[q[1]]+1) * invl(vs[q[1]], mod) % mod;
				st.update(iord[q[3]], curmul*vs[q[3]]%mod);
				st.mul(iord[q[1]], right[iord[q[1]]]+1, (pmul+1)*invl(pmul, mod)%mod);
			}else{
				int x = q[1];
				long pcurmul = 1L;
				if(par[x] != -1){
					pcurmul = st.sum(iord[par[x]], iord[par[x]]+1) * invl(vs[par[x]], mod) % mod;
				}
				out.println(st.sum(iord[q[1]], right[iord[q[1]]]+1) * invl(pcurmul, mod)% mod);
			}
		}
	}
	
	public static long invl(long a, long mod) {
		long b = mod;
		long p = 1, q = 0;
		while (b > 0) {
			long c = a / b;
			long d;
			d = a;
			a = b;
			b = d % b;
			d = p;
			p = q;
			q = d - c * q;
		}
		return p < 0 ? p + mod : p;
	}
	
	public static int[] sortByPreorder(int[][] g, int root){
		int n = g.length;
		int[] stack = new int[n];
		int[] ord = new int[n];
		BitSet ved = new BitSet();
		stack[0] = root;
		int p = 1;
		int r = 0;
		ved.set(root);
		while(p > 0){
			int cur = stack[p-1];
			ord[r++] = cur;
			p--;
			for(int e : g[cur]){
				if(!ved.get(e)){
					stack[p++] = e;
					ved.set(e);
				}
			}
		}
		return ord;
	}
	
	public static int[][] makeRights(int[][] g, int[] par, int root)
	{
		int n = g.length;
		int[] ord = sortByPreorder(g, root);
		int[] iord = new int[n];
		for(int i = 0;i < n;i++)iord[ord[i]] = i;
		
		int[] right = new int[n];
		for(int i = n-1;i >= 0;i--){
			int v = i;
			for(int e : g[ord[i]]){
				if(e != par[ord[i]]){
					v = Math.max(v, right[iord[e]]);
				}
			}
			right[i] = v;
		}
		return new int[][]{ord, iord, right};
	}
	

	
	public static class SegmentTreeRSQ {
		public int M, H, N;
		public long[] st;
		public long[] mult;
		public static int mod = 1000000007;
		
		public SegmentTreeRSQ(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new long[M];
			mult = new long[H];
			Arrays.fill(mult, -1);
		}
		
		public SegmentTreeRSQ(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new long[M];
			mult = new long[H];
			Arrays.fill(mult, 1L);
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
			}
			for(int i = (M>>1)-1;i >= 1;i--){
				propagate(i);
			}
		}
		
		public void update(int pos, long v)
		{
			updatedfs(H+pos>>>1);
			st[H+pos] = v;
			for(int i = H+pos>>>1;i >= 1;i>>>=1)propagate(i);
		}
		
		void updatedfs(int cur)
		{
			if(cur > 1)updatedfs(cur>>>1);
			if(2*cur >= H){
				st[2*cur] = st[2*cur] * mult[cur] % mod;
				st[2*cur+1] = st[2*cur+1] * mult[cur] % mod;
			}else{
				mult[2*cur] = mult[2*cur] * mult[cur] % mod;
				mult[2*cur+1] = mult[2*cur+1] * mult[cur] % mod;
				propagate(2*cur);
				propagate(2*cur+1);
			}
			mult[cur] = 1L;
		}
		
		private void propagate(int i)
		{
//			int count = H/Integer.highestOneBit(i);
			st[i] = (st[2*i]+st[2*i+1])*mult[i]%mod;
		}
		
		public void mul(int l, int r, long v) { 
			if(l < r)mul(l, r, v, 0, H, 1); }
//		private void tr(Object... o) { System.out.println(Arrays.deepToString(o)); }
		
		
		private void mul(int l, int r, long v, int cl, int cr, int cur)
		{
			if(cur >= H){
				st[cur] = st[cur] * v % mod;
			}else if(l <= cl && cr <= r){
				mult[cur] = mult[cur] * v % mod;
				propagate(cur);
			}else{
				int mid = cl+cr>>>1;
				if(cl < r && l < mid){
					mul(l, r, v, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					mul(l, r, v, mid, cr, 2*cur+1);
				}
				propagate(cur);
			}
		}
		
		public long sum(int l, int r) { 
			return sum(l, r, 0, H, 1);
		}
		
		private long sum(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return st[cur];
			}else{
				int mid = cl+cr>>>1;
				long ret = 0;
				if(cl < r && l < mid){
					ret += sum(l, r, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					ret += sum(l, r, mid, cr, 2*cur+1);
				}
				return ret * mult[cur] % mod;
			}
		}
	}

	
	public static int[][] parentToG(int[] par)
	{
		int n = par.length;
		int[] ct = new int[n];
		for(int i = 0;i < n;i++){
			if(par[i] >= 0){
				ct[i]++;
				ct[par[i]]++;
			}
		}
		int[][] g = new int[n][];
		for(int i = 0;i < n;i++){
			g[i] = new int[ct[i]];
		}
		for(int i = 0;i < n;i++){
			if(par[i] >= 0){
				g[par[i]][--ct[par[i]]] = i;
				g[i][--ct[i]] = par[i];
			}
		}
		return g;
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