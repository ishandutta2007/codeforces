//package round427;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Queue;

public class F2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] from = new int[n];
		int[] to = new int[n];
		int[] w = new int[n];
		for (int i = 0; i < n; i++) {
			from[i] = ni() - 1;
			to[i] = ni() - 1;
			w[i] = ni();
		}
		int[][] g = packU(n, from, to);
		int[][][] wg = packWU(n, from, to, w);
		int[][] res = split(g);
		int[] next = res[1];
		
		long[] d1 = new long[n];
		long[] d2 = new long[n];
		Arrays.fill(d1, Long.MAX_VALUE / 3);
		Arrays.fill(d2, Long.MAX_VALUE / 3);
		long tdmax = 0;
		long[] offset = new long[n];
		for(int i = 0;i < n;i++){
			if(next[i] != -1){
				long[] dof = dof(i, wg, next, d1, d2);
				tdmax = Math.max(tdmax, dof[0]);
				offset[i] = dof[1];
			}
		}
		int[] cyc = cycle(g, next);
		tr(tdmax, offset);
		
		int[] wout = new int[n];
		for(int i = 0;i < n;i++){
			for(int[] e : wg[i]){
				if(next[i] == e[0]){
					wout[i] = e[1];
				}
			}
		}
		tr(wout);
		
		int m = cyc.length;
		
		long[] os = new long[2*m];
		long[] wos = new long[2*m];
		for(int i = 0;i < m;i++){
			os[i+m] = os[i] = offset[cyc[i%m]];
			wos[i+m] = wos[i] = wout[cyc[(i+m-1)%m]];
		}
		
		SegmentTreeRMQL st = new SegmentTreeRMQL(os, wos);
		long min = Long.MAX_VALUE;
		for(int i = 0;i < m;i++){
			min = Math.min(min, st.min(i, i+m)[3]);
		}
		out.println(Math.max(min, tdmax));
	}
	
	public static class SegmentTreeRMQL {
		public int M, H, N;
		public long[][] st;
		// alllength, prefix, suffix, inner
		
		public SegmentTreeRMQL(long[] o, long[] wo)
		{
			N = o.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new long[M][4];
			for(int i = 0;i < N;i++){
				st[H+i] = new long[]{
						wo[i], wo[i] + o[i], o[i], 0L
				};
			}
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		private void propagate(int i)
		{
			if(st[2*i+1] == null){
				st[i] = st[2*i];
			}else{
				long[] L = st[2*i], R = st[2*i+1];
				st[i] = prop(L, R, st[i]);
			}
		}
		
		private long[] prop(long[] L, long[] R, long[] C)
		{
			if(L == null && R == null)return null;
			if(R == null)return C = Arrays.copyOf(L, 4);
			if(L == null)return C = Arrays.copyOf(R, 4);
			if(C == null) C = new long[4];
			C[0] = L[0] + R[0];
			C[1] = Math.max(L[1], L[0] + R[1]);
			C[2] = Math.max(R[2], R[0] + L[2]);
			C[3] = Math.max(Math.max(L[3], R[3]), L[2] + R[1]);
			return C;
		}
		
		public long[] min(int l, int r){ return l >= r ? null : min(l, r, 0, H, 1);}
		
		private long[] min(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return st[cur];
			}else{
				int mid = cl+cr>>>1;
				long[] L = null, R = null;
				if(cl < r && l < mid){
					L = min(l, r, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					R = min(l, r, mid, cr, 2*cur+1);
				}
				return prop(L, R, null);
			}
		}
	}
	
	public static int[] cycle(int[][] g, int[] next)
	{
		int n = g.length;
		int[] which = new int[n];
		int p = 0;
		for(int i = 0;i < n;i++){
			if(next[i] != -1){
				int u = i;
				while(true){
					which[p++] = u;
					u = next[u];
					if(u == i)break;
				}
				break;
			}
		}
		return Arrays.copyOf(which, p);
	}
	
	long[] dof(int root, int[][][] wg, int[] next, long[] d1, long[] d2)
	{
		long[] x1 = diams(root, root, wg, next, d1);
		tr(root, x1, d1);
		long[] x2 = diams(root, (int)x1[1], wg, next, d2);
		return new long[]{x2[0], x1[0]};
	}
	
	long[] diams(int root, int start, int[][][] wg, int[] next, long[] d)
	{
		Queue<Integer> q = new ArrayDeque<>();
		q.add(start);
		d[start] = 0;
		long max = -1;
		int argmax = -1;
		while(!q.isEmpty()){
			int cur = q.poll();
			if(d[cur] > max){
				max = d[cur];
				argmax = cur;
			}
			for(int[] e : wg[cur]){
				if(next[e[0]] != -1 && e[0] != root)continue;
				if(d[e[0]] > d[cur] + e[1]){
					d[e[0]] = d[cur] + e[1];
					q.add(e[0]);
				}
			}
		}
		return new long[]{max, argmax};
	}
	
	public static int[][] split(int[][] g)
	{
		int n = g.length;
		int[] deg = new int[n];
		int[] par = new int[n];
		Arrays.fill(par, -1);
		for(int i = 0;i < n;i++){
			deg[i] = g[i].length;
		}
		Queue<Integer> q = new ArrayDeque<Integer>();
		for(int i = 0;i < n;i++){
			if(deg[i] == 1){
				q.add(i);
			}
		}
		while(!q.isEmpty()){
			int cur = q.poll();
			deg[cur] = -9999999;
			for(int e : g[cur]){
				deg[e]--;
				if(deg[e] >= 0){
					par[cur] = e;
				}
				if(deg[e] >= 0 && deg[e] <= 1){
					q.add(e);
				}
			}
		}
		boolean[] ved = new boolean[n];
		int[] next = new int[n];
		Arrays.fill(next, -1);
		for(int i = 0;i < n;i++){
			if(!ved[i] && deg[i] == 2){
				ved[i] = true;
				int cur = i;
				outer:
				while(true){
					for(int e : g[cur]){
						if(deg[e] == 2 && !ved[e]){
							next[cur] = e;
							ved[e] = true;
							cur = e;
							continue outer;
						}
					}
					next[cur] = i;
					break;
				}
			}
		}
		
		return new int[][]{par, next};
	}
	
	public static int[] makeOrder(int[][] g, int[] par)
	{
		int n = g.length;
		int[] ord = new int[n];
		int p = 0;
		boolean[] ved = new boolean[n];
		for(int i = 0;i < n;i++){
			if(par[i] == -1){
				ord[p++] = i;
				ved[i] = true;
			}
		}
		for(int r = 0;r < n;r++){
			for(int e : g[ord[r]]){
				if(!ved[e]){
					ved[e] = true;
					ord[p++] = e;
				}
			}
		}
		return ord;
	}
	
	public static int[] makePW(int[][][] wg, int[] par)
	{
		int n = wg.length;
		int[] pw = new int[n];
		Arrays.fill(pw, -1);
		for(int i = 0;i < n;i++){
			for(int[] e : wg[i]){
				if(par[i] == e[0]){
					pw[i] = e[1];
				}
			}
		}
		return pw;
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

	public static int[][] parents(int[][][] g, int root) {
		int n = g.length;
		int[] par = new int[n];
		Arrays.fill(par, -1);
		int[] dw = new int[n];
		int[] pw = new int[n];
		int[] dep = new int[n];

		int[] q = new int[n];
		q[0] = root;
		for (int p = 0, r = 1; p < r; p++) {
			int cur = q[p];
			for (int[] nex : g[cur]) {
				if (par[cur] != nex[0]) {
					q[r++] = nex[0];
					par[nex[0]] = cur;
					dep[nex[0]] = dep[cur] + 1;
					dw[nex[0]] = dw[cur] + nex[1];
					pw[nex[0]] = nex[1];
				}
			}
		}
		return new int[][] { par, q, dep, dw, pw };
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