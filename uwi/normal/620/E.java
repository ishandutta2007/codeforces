//package educational.round06;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), Q = ni();
		int[] cs = na(n);
		int[] from = new int[n - 1];
		int[] to = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			from[i] = ni() - 1;
			to[i] = ni() - 1;
		}
		int[][] g = packU(n, from, to);
		int[][] pars = parents3(g, 0);
		int[] par = pars[0], ord = pars[1], dep = pars[2];
		int[][] rights = makeRights(g, par, 0);
		int[] iord = rights[1], right = rights[2];
		int[] ucs = new int[n];
		for(int i = 0;i < n;i++){
			ucs[iord[i]] = cs[i];
		}
		
		SegmentTreeOverwriteDistinct st = new SegmentTreeOverwriteDistinct(ucs);
		for(int z = 0;z < Q;z++){
			int t = ni();
			if(t == 1){
				int v = ni()-1, c = ni();
				st.update(iord[v], right[iord[v]]+1, c);
			}else{
				int v = ni()-1;
				out.println(Long.bitCount(st.set(iord[v], right[iord[v]]+1)));
			}
		}
	}
	
	public static class SegmentTreeOverwriteDistinct {
		public int M, H, N;
		public long[] cover;
		public long[] st;
		
		public SegmentTreeOverwriteDistinct(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			cover = new long[H];
			st = new long[M];
			for(int i = 0;i < N;i++){
				st[H+i] = 1L<<a[i];
			}
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		private void propagate(int i)
		{
			st[i] = cover[i] != 0 ? cover[i] : st[2*i]|st[2*i+1];
		}
		
		public void update(int l, int r, int v){ update(l, r, v, 0, H, 1); }
		
		private void update(int l, int r, int v, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				if(cur < H){
					st[cur] = cover[cur] = 1L<<v;
				}else{
					st[cur] = 1L<<v;
				}
			}else{
				int mid = cl+cr>>>1;
				if(cover[cur] != 0){ // back-propagate
					if(2*cur < H){
						cover[2*cur] = cover[2*cur+1] = cover[cur];
						propagate(2*cur);
						propagate(2*cur+1);
					}else{
						st[2*cur] = st[2*cur+1] = cover[cur];
					}
					cover[cur] = 0;
				}
				if(cl < r && l < mid){
					update(l, r, v, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					update(l, r, v, mid, cr, 2*cur+1);
				}
				propagate(cur);
			}
		}
		
		public long set(int l, int r) { return l < r ? set(l, r, 0, H, 1) : 0;};
		
		private long set(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return st[cur];
			}else{
				if(cover[cur] != 0){ // back-propagate
					return cover[cur];
				}
				int mid = cl+cr>>>1;
				long ret = 0;
				if(cl < r && l < mid){
					ret |= set(l, r, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					ret |= set(l, r, mid, cr, 2*cur+1);
				}
				return ret;
			}
		}
		
		public long[] restore()
		{
			long[] u = new long[H];
			int co = 1;
			for(int i = M-1, j = H;i >= 1;i--){
				if(cover[i] != 0){
					Arrays.fill(u, (i-j)*co, (i-j+1)*co, cover[i]);
				}
				if(i == j){
					j /= 2;
					co *= 2;
				}
			}
			return u;
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
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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