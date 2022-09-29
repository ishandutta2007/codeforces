//package educational.round47;
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
	
	int[] dep;
	SegmentTreeRMQPos st;
	
	void solve()
	{
		int n = ni();
		int[] from = new int[n - 1];
		int[] to = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			from[i] = ni() - 1;
			to[i] = ni() - 1;
		}
		int[][] g = packU(n, from, to);
		int[][] pars = parents3(g, 0);
		int[] par = pars[0], ord = pars[1];
		dep = pars[2];
		
		st = new SegmentTreeRMQPos(n+2);
		
		int[] des = new int[n];
		Arrays.fill(des, 1);
		for(int i = n-1;i >= 1;i--){
			des[par[ord[i]]] += des[ord[i]];
		}
		anss = new int[n];
		dfs(0, -1, g, true, des);
		for(int v : anss){
			out.println(v);
		}
	}
	
	int[] anss;
	
	private void answer(int cur)
	{
		int argmin = st.pos[1];
		anss[cur] = argmin - dep[cur];
	}
	
	private void paint(int cur)
	{
		st.add(dep[cur], -1);
	}
	
	private void clear(int cur)
	{
		st.add(dep[cur], 1);
	}
	
	public void dfs(int cur, int pre, int[][] g, boolean preserve, int[] des)
	{
		int big = -1;
		for(int e : g[cur]){
			if(e == pre)continue;
			if(big == -1 || des[e] > des[big]){
				big = e;
			}
		}
		for(int e : g[cur]){
			if(e != pre && e != big)dfs(e, cur, g, false, des);
		}
		if(big != -1)dfs(big, cur, g, true, des);
		
		// only biggest subtree is painted
		
		// paint subtrees
		// if processing node pairs, put answer(cur);
		paint(cur);
		for(int e : g[cur]){
			if(e != pre && e != big){
				// if processing node pairs, put answerdfs(e, cur, g);
				paintdfs(e, cur, g);
			}
		}
		
		// all node is painted
		answer(cur);
		
		// clear subtrees
		if(!preserve)cleardfs(cur, pre, g);
	}
	
	private void paintdfs(int cur, int pre, int[][] g)
	{
		paint(cur);
		for(int e : g[cur])if(e != pre)paintdfs(e, cur, g);
	}
	
	private void cleardfs(int cur, int pre, int[][] g)
	{
		clear(cur);
		for(int e : g[cur])if(e != pre)cleardfs(e, cur, g);
	}
	
	private void answerdfs(int cur, int pre, int[][] g)
	{
		answer(cur);
		for(int e : g[cur])if(e != pre)answerdfs(e, cur, g);
	}
	
	public static class SegmentTreeRMQPos {
		public int M, H, N;
		public int[] st;
		public int[] pos;
		
		public SegmentTreeRMQPos(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new int[M];
			pos = new int[M];
			for(int i = 0;i < N;i++)pos[H+i] = i;
			Arrays.fill(st, 0, M, 0);
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		public SegmentTreeRMQPos(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new int[M];
			pos = new int[M];
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
				pos[H+i] = i;
			}
			Arrays.fill(st, H+N, M, Integer.MAX_VALUE);
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		public void add(int pos, int x)
		{
			st[H+pos] += x;
			for(int i = (H+pos)>>>1;i >= 1;i >>>= 1)propagate(i);
		}
		
		private void propagate(int i)
		{
			if(st[2*i] <= st[2*i+1]){
				st[i] = st[2*i];
				pos[i] = pos[2*i];
			}else{
				st[i] = st[2*i+1];
				pos[i] = pos[2*i+1];
			}
		}
		
		public int minpos;
		public int minval;
		
		public int minx(int l, int r){
			minval = Integer.MAX_VALUE;
			minpos = -1;
			if(l >= r)return minval;
			while(l != 0){
				int f = l&-l;
				if(l+f > r)break;
				int v = st[(H+l)/f];
				if(v < minval || v == minval && pos[(H+l)/f] < minpos){
					minval = v;
					minpos = pos[(H+l)/f];
				}
				l += f;
			}
			
			while(l < r){
				int f = r&-r;
				int v = st[(H+r)/f-1];
				if(v < minval || v == minval && pos[(H+r)/f-1] < minpos){
					minval = v;
					minpos = pos[(H+r)/f-1];
				}
				r -= f;
			}
			return minval;
		}
		
		public int min(int l, int r){ 
			minpos = -1;
			minval = Integer.MAX_VALUE;
			min(l, r, 0, H, 1);
			return minval;
		}
		
		private void min(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				if(st[cur] < minval){
					minval = st[cur];
					minpos = pos[cur];
				}
			}else{
				int mid = cl+cr>>>1;
				if(cl < r && l < mid)min(l, r, cl, mid, 2*cur);
				if(mid < r && l < cr)min(l, r, mid, cr, 2*cur+1);
			}
		}
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
		
		Thread t = new Thread(null, null, "~", Runtime.getRuntime().maxMemory()){
			@Override
			public void run() {
				long s = System.currentTimeMillis();
				solve();
				out.flush();
				if(!INPUT.isEmpty())tr(System.currentTimeMillis()-s+"ms");
			}
		};
		t.start();
		t.join();
		
//		long s = System.currentTimeMillis();
//		solve();
//		out.flush();
//		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new F().run(); }
	
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