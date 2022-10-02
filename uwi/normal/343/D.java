//package round200;
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
		int n = ni();
		int[] from = new int[n-1];
		int[] to = new int[n-1];
		for(int i = 0;i < n-1;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
		}
		int[][] g = packU(n, from, to);
		int[][] pars = parents(g, 0);
		int[] par = pars[0], lvord = pars[1];
		
		int[] clus = decomposeToHeavyLight(g, par, lvord);
		int[][] clusPaths = clusPaths(clus, lvord);
		int[] iind = clusIInd(clusPaths, n);
		
		int[][] rights = makeRights(g, par, 0);
		int[] ord = rights[0], iord = rights[1], right = rights[2];
		
		SegmentTreeOverwrite st1 = new SegmentTreeOverwrite(n);
		SegmentTreeOverwrite[] st0 = new SegmentTreeOverwrite[clusPaths.length];
		for(int i = 0;i < clusPaths.length;i++){
			st0[i] = new SegmentTreeOverwrite(clusPaths[i].length);
		}
		
		int Q = ni();
		for(int i = 0;i < Q;i++){
			int t = ni();
			if(t == 1){
				int x = ni()-1;
				st1.update(iord[x], right[iord[x]]+1, i);
			}else if(t == 2){
				int x = ni()-1;
				int cx = clus[x]; // 
				int ind = iind[x]; // 
				while(cx != clus[0]){
					st0[cx].update(0, ind+1, i);
					int con = par[clusPaths[cx][0]];
					ind = iind[con];
					cx = clus[con];
				}
				st0[cx].update(iind[0], ind+1, i);
			}else if(t == 3){
				int x = ni()-1;
				int z = st0[clus[x]].attack(iind[x]);
				int o = st1.attack(iord[x]);
				if(z == -1 && o == -1){
					out.println(0);
				}else if(z < o){
					out.println(1);
				}else{
					out.println(0);
				}
			}
		}
	}
	
	public static class SegmentTreeOverwrite {
		public int M, H, N;
		public int[] cover;
		
		public SegmentTreeOverwrite(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			cover = new int[M];
			Arrays.fill(cover, -1);
		}
		
		public void update(int l, int r, int v){ update(l, r, v, l, 0, H, 1); }
		
		private void update(int l, int r, int v, int begin, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				cover[cur] = v;
			}else{
				int mid = cl+cr>>>1;
				if(cover[cur] != -1){ // back-propagate
					cover[2*cur] = cover[2*cur+1] = cover[cur];
					cover[cur] = -1;
				}
				if(Math.max(l, cl) < Math.min(r, mid)){
					update(l, r, v, begin, cl, mid, 2*cur);
				}
				if(Math.max(l, mid) < Math.min(r, cr)){
					update(l, r, v, begin, mid, cr, 2*cur+1);
				}
			}
		}
		
		public int attack(int x){ return attack(x, 0, H, 1); }
		
		private int attack(int x, int cl, int cr, int cur)
		{
			if(x == cl && cr-cl == 1){
				return cover[cur];
			}else{
				if(cover[cur] != -1){
					return cover[cur];
				}
				int mid = cl+cr>>>1;
				if(cl <= x && x < mid){
					return attack(x, cl, mid, 2*cur);
				}
				if(mid <= x && x < cr){
					return attack(x, mid, cr, 2*cur+1);
				}
				return -1;
			}
		}
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
	
	public static int[] decomposeToHeavyLight(int[][] g, int[] par, int[] ord)
	{
		int n = g.length;
		int[] size = new int[n];
		Arrays.fill(size, 1);
		for(int i = n-1;i > 0;i--)size[par[ord[i]]] += size[ord[i]];
		
		int[] clus = new int[n];
		Arrays.fill(clus, -1);
		int p = 0;
		outer:
		for(int i = 0;i < n;i++){
			int u = ord[i];
			if(clus[u] == -1)clus[u] = p++;
			for(int v : g[u]){
				if(par[u] != v && size[v] >= size[u]/2){
					clus[v] = clus[u];
					continue outer;
				}
			}
			for(int v : g[u]){
				if(par[u] != v){
					clus[v] = clus[u];
					break;
				}
			}
		}
		return clus;
	}
	
	/**
	 * HL-decompose
	 * @param clus
	 * @param ord
	 * @return
	 * @verified SPOJ-QTREE
	 */
	public static int[][] clusPaths(int[] clus, int[] ord)
	{
		int n = clus.length;
		int[] rp = new int[n];
		int sup = 0;
		for(int i = 0;i < n;i++){
			rp[clus[i]]++;
			sup = Math.max(sup, clus[i]);
		}
		sup++;
		
		int[][] row = new int[sup][];
		for(int i = 0;i < sup;i++)row[i] = new int[rp[i]];
		
		for(int i = n-1;i >= 0;i--){
			row[clus[ord[i]]][--rp[clus[ord[i]]]] = ord[i];
		}
		return row;
	}
	
	/**
	 * clusPath
	 * @param clusPath
	 * @param n
	 * @return
	 * @verified SPOJ-QTREE
	 */
	public static int[] clusIInd(int[][] clusPath, int n)
	{
		int[] iind = new int[n];
		for(int[] path : clusPath){
			for(int i = 0;i < path.length;i++){
				iind[path[i]] = i;
			}
		}
		return iind;
	}
	
	/**
	 * xancx-anc
	 * @param x
	 * @param anc
	 * @param clus
	 * @param clusPath
	 * @param clusIInd
	 * @param par
	 * @verified SPOJ-QTREE
	 */
	public static void query(int x, int anc, int[] clus, int[][] clusPath, int[] clusIInd, int[] par)
	{
		int cx = clus[x]; // 
		int ind = clusIInd[x]; // 
		while(cx != clus[anc]){
			// TODO cx0~ind
			int con = par[clusPath[cx][0]];
			ind = clusIInd[con];
			cx = clus[con];
		}
		// TODO clusIInd[anc]~ind
	}
	
	public static int[][] parents(int[][] g, int root) {
		int n = g.length;
		int[] par = new int[n];
		Arrays.fill(par, -1);

		int[] q = new int[n];
		q[0] = root;
		for(int p = 0, r = 1;p < r;p++){
			int cur = q[p];
			for(int nex : g[cur]){
				if(par[cur] != nex){
					q[r++] = nex;
					par[nex] = cur;
				}
			}
		}
		return new int[][] { par, q };
	}
	
	static int[][] packU(int n, int[] from, int[] to) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int f : from)
			p[f]++;
		for(int t : to)
			p[t]++;
		for(int i = 0;i < n;i++)
			g[i] = new int[p[i]];
		for(int i = 0;i < from.length;i++){
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