//package rocket2015;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class D2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
//	String INPUT = "50 10\r\n" + 
//			"2 3 LEFT\r\n" + 
//			"4 7 LEFT\r\n" + 
//			"3 10 LEFT\r\n" + 
//			"13 14 LEFT\r\n" + 
//			"1 15 LEFT\r\n" + 
//			"13 20 RIGHT\r\n" + 
//			"23 33 RIGHT\r\n" + 
//			"1 35 LEFT\r\n" + 
//			"23 36 RIGHT\r\n" + 
//			"39 41 RIGHT\r\n" + 
//			"";
//	String INPUT = "3 2 1 2 L 1 3 R";
//	String INPUT = "3 2 1 2 L 1 3 R";
//	String INPUT = "3 2 1 2 R 1 3 L";
//	String INPUT = "4 2\r\n" + 
//			"2 3 RIGHT\r\n" + 
//			"2 4 LEFT";
//	String INPUT = "4 3\r\n" + 
//			"2 3 LEFT\r\n" + 
//			"2 4 RIGHT 3 4 RIGHT";
//	String INPUT = "4 3\r\n" + 
//			"2 3 LEFT\r\n" + 
//			"2 4 RIGHT 3 4 LEFT";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		int[] w = new int[m];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
			if(from[i] >= to[i]){
				out.println("IMPOSSIBLE");
				return;
			}
			w[i] = ns().charAt(0) == 'R' ? 1 : 0;
		}
		int[][][] g = packWD(n, from, to, w);
		for(int i = 0;i < n;i++){
			Arrays.sort(g[i], new Comparator<int[]>() {
				public int compare(int[] a, int[] b) {
					return a[0] - b[0];
				}
			});
			for(int j = 0;j < g[i].length-1;j++){
				if(g[i][j][1] > g[i][j+1][1]){
					out.println("IMPOSSIBLE");
					return;
				}
			}
		}
		
		SegmentTreeRMQ st = new SegmentTreeRMQ(n);
//		int[] reach = new int[n];
		for(int i = 0;i < n;i++){
			int v = i;
			if(g[i].length > 0){
				v = g[i][g[i].length-1][0];
			}
			st.update(i, -v);
		}
		for(int i = n-1;i >= 0;i--){
			st.update(i, st.min(i, -st.min(i, i+1)+1));
		}
		int[] reach = Arrays.copyOfRange(st.st, st.H, st.H+n);
		for(int i = 0;i < n;i++){
			reach[i] = -reach[i];
		}
//		tr("reach", reach);
		
		int[] xfrom = new int[2*n];
		int[] xto = new int[2*n];
//		int[] xfrom = new int[n-1];
//		int[] xto = new int[n-1];
		
		int[] split = new int[n];
		Arrays.fill(split, -1);
		if(!dfs(0, n-1, reach, g, split, st)){
			out.println("IMPOSSIBLE");
			return;
		}
//		tr(split);
		p = 0;
		dfs2(0, n-1, split, xfrom, xto);
//		tr(xfrom);
//		tr(xto);
		if(p != n-1){
			out.println("IMPOSSIBLE");
			return;
		}
		
		int[][] zg = packU(n, xfrom, xto, p);
		int[][] pars = parents3(zg, 0);
		int[] par = pars[0], ord = pars[1], dep = pars[2];
		int[][] spar = logstepParents(par);
		for(int i = 0;i < m;i++){
//			tr(from[i], to[i], w[i]);
			if(w[i] == 0){
				if(to[i] < split[from[i]] && lca2(from[i], to[i], spar, dep) == from[i]){
				}else{
					out.println("IMPOSSIBLE");
					return;
				}
			}else{
				if(split[from[i]] <= to[i] && lca2(from[i], to[i], spar, dep) == from[i]){
				}else{
					out.println("IMPOSSIBLE");
					return;
				}
			}
		}
//		tr(p);
		dfs3(0, n-1, split);
		
		out.println();
	}
	
	public static class SegmentTreeRMQ {
		public int M, H, N;
		public int[] st;
		
		public SegmentTreeRMQ(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new int[M];
			Arrays.fill(st, 0, M, Integer.MAX_VALUE);
		}
		
		public SegmentTreeRMQ(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new int[M];
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
			}
			Arrays.fill(st, H+N, M, Integer.MAX_VALUE);
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		public void update(int pos, int x)
		{
			st[H+pos] = x;
			for(int i = (H+pos)>>>1;i >= 1;i >>>= 1)propagate(i);
		}
		
		private void propagate(int i)
		{
			st[i] = Math.min(st[2*i], st[2*i+1]);
		}
		
		public int min(int l, int r){ return l >= r ? 0 : min(l, r, 0, H, 1);}
		
		private int min(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return st[cur];
			}else{
				int mid = cl+cr>>>1;
				int ret = Integer.MAX_VALUE;
				if(cl < r && l < mid){
					ret = Math.min(ret, min(l, r, cl, mid, 2*cur));
				}
				if(mid < r && l < cr){
					ret = Math.min(ret, min(l, r, mid, cr, 2*cur+1));
				}
				return ret;
			}
		}
		
		public int firstle(int l, int v) {
			int cur = H+l;
			while(true){
				if(st[cur] <= v){
					if(cur < H){
						cur = 2*cur;
					}else{
						return cur-H;
					}
				}else{
					cur++;
					if((cur&cur-1) == 0)return -1;
					if((cur&1)==0)cur>>>=1;
				}
			}
		}
		
		public int lastle(int l, int v) {
			int cur = H+l;
			while(true){
				if(st[cur] <= v){
					if(cur < H){
						cur = 2*cur+1;
					}else{
						return cur-H;
					}
				}else{
					if((cur&cur-1) == 0)return -1;
					cur--;
					if((cur&1)==1)cur>>>=1;
				}
			}
		}
	}

	
	public static int lca2(int a, int b, int[][] spar, int[] depth) {
		if (depth[a] < depth[b]) {
			b = ancestor(b, depth[b] - depth[a], spar);
		} else if (depth[a] > depth[b]) {
			a = ancestor(a, depth[a] - depth[b], spar);
		}

		if (a == b)
			return a;
		int sa = a, sb = b;
		for (int low = 0, high = depth[a], t = Integer.highestOneBit(high), k = Integer
				.numberOfTrailingZeros(t); t > 0; t >>>= 1, k--) {
			if ((low ^ high) >= t) {
				if (spar[k][sa] != spar[k][sb]) {
					low |= t;
					sa = spar[k][sa];
					sb = spar[k][sb];
				} else {
					high = low | t - 1;
				}
			}
		}
		return spar[0][sa];
	}

	protected static int ancestor(int a, int m, int[][] spar) {
		for (int i = 0; m > 0 && a != -1; m >>>= 1, i++) {
			if ((m & 1) == 1)
				a = spar[i][a];
		}
		return a;
	}

	public static int[][] logstepParents(int[] par) {
		int n = par.length;
		int m = Integer.numberOfTrailingZeros(Integer.highestOneBit(n - 1)) + 1;
		int[][] pars = new int[m][n];
		pars[0] = par;
		for (int j = 1; j < m; j++) {
			for (int i = 0; i < n; i++) {
				pars[j][i] = pars[j - 1][i] == -1 ? -1
						: pars[j - 1][pars[j - 1][i]];
			}
		}
		return pars;
	}
	
	public static int[][] packU(int n, int[] from, int[] to, int sup)
	{
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int i = 0;i < sup;i++)p[from[i]]++;
		for(int i = 0;i < sup;i++)p[to[i]]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]];
		for(int i = 0;i < sup;i++){
			g[from[i]][--p[from[i]]] = to[i];
			g[to[i]][--p[to[i]]] = from[i];
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
	
	int p = 0;
	
	void dfs2(int cur, int r, int[] split, int[] xfrom, int[] xto)
	{
		if(cur >= r)return;
		if(split[cur] == -1){
			return;
		}
		
		if(cur+1 <= r){
			xfrom[p] = cur; xto[p] = cur+1; p++;
		}
		if(split[cur] > cur+1 && split[cur] <= r){
			xfrom[p] = cur; xto[p] = split[cur]; p++;
		}
		dfs2(cur+1, split[cur]-1, split, xfrom, xto);
		dfs2(split[cur], r, split, xfrom, xto);
	}
	
	void dfs3(int cur, int r, int[] split)
	{
		if(cur > r)return;
		if(split[cur] == -1){
			out.print(cur+1 + " ");
			return;
		}
		
		dfs3(cur+1, split[cur]-1, split);
		out.print(cur+1 + " ");
		dfs3(split[cur], r, split);
	}
	
	boolean dfs(int cur, int r, int[] reach, int[][][] g, int[] split, SegmentTreeRMQ st)
	{
//		tr(cur, r, reach, split ,g);
		if(cur >= r)return true;
		
		if(g[cur].length == 0 || g[cur][0][1] == 1){
			// nex=cur+1
			split[cur] = cur+1;
			if(!dfs(cur+1, r, reach, g, split, st))return false;
			return true;
		}
		
		for(int i = 0;i < g[cur].length-1;i++){
			if(g[cur][i][1] < g[cur][i+1][1]){
				// [g[cur][i][0]+1,g[cur][i+1][0]]
				int nex = -st.min(cur+1, g[cur][i][0]+1);
				if(nex < g[cur][i+1][0]){
					split[cur] = nex+1;
					if(!dfs(cur+1, nex, reach, g, split, st))return false;
					if(!dfs(nex+1, r, reach, g, split, st))return false;
					return true;
				}else{
					return false;
				}
			}
		}
		
		int nex = -st.min(cur+1, g[cur][g[cur].length-1][0]+1);
		if(nex <= r){
			split[cur] = nex+1;
			if(!dfs(cur+1, nex, reach, g, split, st))return false;
			if(!dfs(nex+1, r, reach, g, split, st))return false;
			return true;
		}else{
			return false;
		}
	}
	
	public static int[][][] packWD(int n, int[] from, int[] to, int[] w) {
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for (int f : from)
			p[f]++;
		for (int i = 0; i < n; i++)
			g[i] = new int[p[i]][2];
		for (int i = 0; i < from.length; i++) {
			--p[from[i]];
			g[from[i]][p[from[i]]][0] = to[i];
			g[from[i]][p[from[i]]][1] = w[i];
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
	
	public static void main(String[] args) throws Exception { new D2().run(); }
	
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