//package round317;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Comparator;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] qs = new int[m][];
		for(int i = 0;i < m;i++){
			char t = nc();
			if(t == 'U' || t == 'M'){
				qs[i] = new int[]{t, ni()-1, ni()-1};
			}else{
				qs[i] = new int[]{t, ni()-1};
			}
		}
		
		int[] mpar = new int[n+1];
		int[] mtime = new int[n+1];
		Arrays.fill(mpar, -1);
		Arrays.fill(mtime, -1);
		for(int i = 0;i < m;i++){
			if(qs[i][0] == 'M'){
				mpar[qs[i][2]] = qs[i][1];
				mtime[qs[i][2]] = i;
			}
		}
		for(int i = 0;i < n;i++){
			if(mpar[i] == -1)mpar[i] = n;
		}
		int[][][] mgw = parentToG(mpar, mtime);
		for(int i = 0;i < n+1;i++){
			Arrays.sort(mgw[i], new Comparator<int[]>() {
				public int compare(int[] a, int[] b) {
					return -(a[1] - b[1]);
				}
			});
		}
		int[][] mg = new int[n+1][];
		for(int i = 0;i < n+1;i++){
			mg[i] = new int[mgw[i].length];
			for(int j = 0;j < mgw[i].length;j++)mg[i][j] = mgw[i][j][0];
		}
		
		int[][] mrights = makeRights(mg, mpar, n);
		SegmentTreeOverwrite st = new SegmentTreeOverwrite(n+1);
		int[] miord = mrights[1], mright = mrights[2];
		int[] lastReset = new int[m];
		Arrays.fill(lastReset, -1);
		int[] mptr = new int[n+1];
		for(int i = 0;i < n;i++){
			mptr[i] = mg[i].length-1;
		}
		st.update(0, n+1, -1);
		for(int i = 0;i < m;i++){
			if(qs[i][0] == 'M'){
				mptr[qs[i][1]]--;
			}else if(qs[i][0] == 'Z'){
				int y = qs[i][1];
				int L = miord[y];
				int R = mptr[y] == mg[y].length-1 ? L : mright[miord[mg[y][mptr[y]]]];
				st.update(L, R+1, i);
			}else if(qs[i][0] == 'Q'){
				lastReset[i] = st.val(miord[qs[i][1]]);
			}
		}
		
		int[] upar = new int[n+1];
		int[] utime = new int[n+1];
		Arrays.fill(upar, -1);
		Arrays.fill(utime, -1);
		for(int i = 0;i < m;i++){
			if(qs[i][0] == 'U'){
				upar[qs[i][2]] = qs[i][1];
				utime[qs[i][2]] = i;
			}
		}
		for(int i = 0;i < n;i++){
			if(upar[i] == -1)upar[i] = n;
		}
		int[][][] ugw = parentToG(upar, utime);
		for(int i = 0;i < n+1;i++){
			Arrays.sort(ugw[i], new Comparator<int[]>() {
				public int compare(int[] a, int[] b) {
					return -(a[1] - b[1]);
				}
			});
		}
		int[][] ug = new int[n+1][];
		for(int i = 0;i < n+1;i++){
			ug[i] = new int[ugw[i].length];
			for(int j = 0;j < ugw[i].length;j++)ug[i][j] = ugw[i][j][0];
		}
		
		int[][] es = new int[m][];
		int p = 0;
		for(int i = 0;i < m;i++){
			if(lastReset[i] >= 0){
				es[p++] = new int[]{lastReset[i], i};
			}
		}
		Arrays.sort(es, 0, p, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
		
		int[][] urights = makeRights(ug, upar, n);
		int[] uiord = urights[1], uright = urights[2];
		long[] ft = new long[n+2];
		int[] uptr = new int[n+1];
		for(int i = 0;i < n;i++){
			uptr[i] = ug[i].length-1;
		}
		long[] ret = new long[m];
		int pp = 0;
		for(int i = 0;i < m;i++){
			if(qs[i][0] == 'U'){
				uptr[qs[i][1]]--;
			}else if(qs[i][0] == 'A'){
				int y = qs[i][1];
				int L = uiord[y];
				int R = uptr[y] == ug[y].length-1 ? L : uright[uiord[ug[y][uptr[y]]]];
				addFenwick(ft, L, R-L+1);
				addFenwick(ft, R+1, -(R-L+1));
			}else if(qs[i][0] == 'Q'){
				ret[i] += sumFenwick(ft, uiord[qs[i][1]]);
				out.println(ret[i]);
			}
			while(pp < p && es[pp][0] <= i){
				ret[es[pp][1]] -= sumFenwick(ft, uiord[qs[es[pp][1]][1]]);
				pp++;
			}
		}
		
	}
	
	public static long sumFenwick(long[] ft, int i)
	{
		long sum = 0;
		for(i++;i > 0;i -= i&-i)sum += ft[i];
		return sum;
	}
	
	public static void addFenwick(long[] ft, int i, long v)
	{
		if(v == 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i)ft[i] += v;
	}

	
	public static long[] restoreFenwick(long[] ft)
	{
		int n = ft.length-1;
		long[] ret = new long[n];
		for(int i = 0;i < n;i++)ret[i] = sumFenwick(ft, i);
		for(int i = n-1;i >= 1;i--)ret[i] -= ret[i-1];
		return ret;
	}

	public static class SegmentTreeOverwrite {
		public int M, H, N;
		public int[] cover;
		public int I = Integer.MAX_VALUE;
		
		public SegmentTreeOverwrite(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			cover = new int[M];
		}
		
		public void update(int l, int r, int v){ update(l, r, v, 0, H, 1); }
		
		private void update(int l, int r, int v, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				cover[cur] = v;
			}else{
				int mid = cl+cr>>>1;
				if(cover[cur] != I){
					cover[2*cur] = cover[2*cur+1] = cover[cur];
					cover[cur] = I;
				}
				if(cl < r && l < mid){
					update(l, r, v, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					update(l, r, v, mid, cr, 2*cur+1);
				}
			}
		}
		
		public int val(int x) {
			int ret = I;
			for(int i = H+x;i >= 1;i>>>=1){
				if(cover[i] != I)ret = cover[i];
			}
			return ret;
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
	
	public static int[][] parents(int[][] g)
	{
		int n = g.length;
		int[] par = new int[n];
		Arrays.fill(par, -1);

		int[] q = new int[n];
		int r = 0;
		for(int u = 0;u < n;u++){
			if(par[u] == -1){
				q[r++] = u;
				for(int p = r-1;p < r;p++) {
					int cur = q[p];
					for(int nex : g[cur]){
						if(par[cur] != nex){
							q[r++] = nex;
							par[nex] = cur;
						}
					}
				}
			}
		}
		return new int[][] {par, q};
	}

	
	public static int[][][] parentToG(int[] par, int[] time)
	{
		int n = par.length;
		int[] ct = new int[n];
		for(int i = 0;i < n;i++){
			if(par[i] >= 0){
				ct[i]++;
				ct[par[i]]++;
			}
		}
		int[][][] g = new int[n][][];
		for(int i = 0;i < n;i++){
			g[i] = new int[ct[i]][];
		}
		for(int i = 0;i < n;i++){
			if(par[i] >= 0){
				g[par[i]][--ct[par[i]]] = new int[]{i, time[i]};
				g[i][--ct[i]] = new int[]{par[i], -2};
			}
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