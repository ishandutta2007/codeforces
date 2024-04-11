//package round339;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
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
		int[] par = pars[0], ord = pars[1], dep = pars[2];
		
		int[] clus = decomposeToHeavyLight(g, par, ord);
		int[][] cluspath = clusPaths(clus, ord);
		int[] clusiind = clusIInd(cluspath, n);
		
		int m = cluspath.length;
		int[][] fts = new int[m][];
		for(int i = 0;i < m;i++){
			fts[i] = new int[cluspath[i].length+2];
		}
		
		LST touched = new LST(m+3);
		boolean[] imp = new boolean[n];
		int[] minus = new int[m];
		
		int[] histft = new int[400005];
		int[] histpos = new int[400005];
		int[] histval = new int[400005];
		
		int hp = 0;
		outer:
		for(int Q = ni();Q > 0;Q--){
			int K = ni();
			int[] a = na(K);
			if(K == 1){
				out.println(0);
				continue;
			}
			for(int i = 0;i < K;i++){
				a[i]--;
				imp[a[i]] = true;
			}
			for(int i = 0;i < K;i++){
				if(par[a[i]] != -1 && imp[par[a[i]]]){
					out.println(-1);
					for(int j = 0;j < K;j++){
						imp[a[j]] = false;
					}
					continue outer;
				}
			}
			
			for(int i = 0;i < K;i++){
				int x = a[i];
				int cx = clus[x]; // 
				int ind = clusiind[x]; // 
				while (true) {
					touched.set(cx);
					addFenwick(fts[cx], 0, 1);
					addFenwick(fts[cx], ind+1, -1);
					histft[hp] = cx; histpos[hp] = ind; histval[hp] = 1; hp++;
					int con = par[cluspath[cx][0]];
					if(con == -1)break;
					ind = clusiind[con];
					cx = clus[con];
				}
			}
//			for(int i = 0;i < m;i++){
//				tr(cluspath[i], restoreFenwick(fts[i]));
//			}
			
			int put = 0;
			
			while(true){
				int cl = touched.prev(m);
				if(cl == -1)break;
				touched.unset(cl);
				
				while(sumFenwick(fts[cl], 0) >= 2){
					int low = 0, high = cluspath[cl].length;
					while(high - low > 1){
						int h = high+low>>>1;
						int s = sumFenwick(fts[cl], h);
						if(s >= 2){
							low = h;
						}else{
							high = h;
						}
					}
					int val = sumFenwick(fts[cl], low);
					if(imp[cluspath[cl][low]]){
						put += val-1;
						val--;
					}else{
						put++;
					}
					addFenwick(fts[cl], 0, -val);
					addFenwick(fts[cl], low+1, val);
					histft[hp] = cl; histpos[hp] = low; histval[hp] = -val; hp++;
					minus[cl] += val;
				}
				
				int pa = par[cluspath[cl][0]];
				if(pa != -1){
					addFenwick(fts[clus[pa]], 0, -minus[cl]);
					addFenwick(fts[clus[pa]], clusiind[pa]+1, minus[cl]);
					histft[hp] = clus[pa]; histpos[hp] = clusiind[pa]; histval[hp] = -minus[cl]; hp++;
					minus[clus[pa]] += minus[cl];
				}
				minus[cl] = 0;
			}
			
			out.println(put);
			
			for(int i = 0;i < K;i++){
				imp[a[i]] = false;
			}
			for(int i = 0;i < hp;i++){
				addFenwick(fts[histft[i]], 0, -histval[i]);
				addFenwick(fts[histft[i]], histpos[i]+1, histval[i]);
			}
			hp = 0;
		}
	}
	
	public static class LST {
		public long[][] set;
		public int n;
//		public int size;
		
		public LST(int n) {
			this.n = n;
			int d = 1;
			for(int m = n;m > 1;m>>>=6, d++);
			
			set = new long[d][];
			for(int i = 0, m = n>>>6;i < d;i++, m>>>=6){
				set[i] = new long[m+1];
			}
//			size = 0;
		}
		
		// [0,r)
		public LST setRange(int r)
		{
			for(int i = 0;i < set.length;i++, r=r+63>>>6){
				for(int j = 0;j < r>>>6;j++){
					set[i][j] = -1L;
				}
				if((r&63) != 0)set[i][r>>>6] |= (1L<<r)-1;
			}
			return this;
		}
		
		// [0,r)
		public LST unsetRange(int r)
		{
			if(r >= 0){
				for(int i = 0;i < set.length;i++, r=r+63>>>6){
					for(int j = 0;j < r+63>>>6;j++){
						set[i][j] = 0;
					}
					if((r&63) != 0)set[i][r>>>6] &= ~((1L<<r)-1);
				}
			}
			return this;
		}
		
		public LST set(int pos)
		{
			if(pos >= 0 && pos < n){
//				if(!get(pos))size++;
				for(int i = 0;i < set.length;i++, pos>>>=6){
					set[i][pos>>>6] |= 1L<<pos;
				}
			}
			return this;
		}
		
		public LST unset(int pos)
		{
			if(pos >= 0 && pos < n){
//				if(get(pos))size--;
				for(int i = 0;i < set.length && (i == 0 || set[i-1][pos] == 0L);i++, pos>>>=6){
					set[i][pos>>>6] &= ~(1L<<pos);
				}
			}
			return this;
		}
		
		public boolean get(int pos)
		{
			return pos >= 0 && pos < n && set[0][pos>>>6]<<~pos<0;
		}
		
		public int prev(int pos)
		{
			for(int i = 0;i < set.length && pos >= 0;i++, pos>>>=6, pos--){
				int pre = prev(set[i][pos>>>6], pos&63);
				if(pre != -1){
					pos = pos>>>6<<6|pre;
					while(i > 0)pos = pos<<6|63-Long.numberOfLeadingZeros(set[--i][pos]);
					return pos;
				}
			}
			return -1;
		}
		
		public int next(int pos)
		{
			for(int i = 0;i < set.length && pos>>>6 < set[i].length;i++, pos>>>=6, pos++){
				int nex = next(set[i][pos>>>6], pos&63);
				if(nex != -1){
					pos = pos>>>6<<6|nex;
					while(i > 0)pos = pos<<6|Long.numberOfTrailingZeros(set[--i][pos]);
					return pos;
				}
			}
			return -1;
		}
		
		private static int prev(long set, int n)
		{
			long h = Long.highestOneBit(set<<~n);
			if(h == 0L)return -1;
			return Long.numberOfTrailingZeros(h)-(63-n);
		}
		
		private static int next(long set, int n)
		{
			long h = Long.lowestOneBit(set>>>n);
			if(h == 0L)return -1;
			return Long.numberOfTrailingZeros(h)+n;
		}
		
		@Override
		public String toString()
		{
			List<Integer> list = new ArrayList<Integer>();
			for(int pos = next(0);pos != -1;pos = next(pos+1)){
				list.add(pos);
			}
			return list.toString();
		}
	}
	
	public static int sumFenwick(int[] ft, int i) {
		int sum = 0;
		for (i++; i > 0; i -= i & -i)
			sum += ft[i];
		return sum;
	}

	public static void addFenwick(int[] ft, int i, int v) {
		if (v == 0 || i < 0)
			return;
		int n = ft.length;
		for (i++; i < n; i += i & -i)
			ft[i] += v;
	}

	public static int findGFenwick(int[] ft, int v) {
		int i = 0;
		int n = ft.length;
		for (int b = Integer.highestOneBit(n); b != 0 && i < n; b >>= 1) {
			if (i + b < n) {
				int t = i + b;
				if (v >= ft[t]) {
					i = t;
					v -= ft[t];
				}
			}
		}
		return v != 0 ? -(i + 1) : i - 1;
	}

	public static int valFenwick(int[] ft, int i) {
		return sumFenwick(ft, i) - sumFenwick(ft, i - 1);
	}

	public static int[] restoreFenwick(int[] ft) {
		int n = ft.length - 1;
		int[] ret = new int[n];
		for (int i = 0; i < n; i++)
			ret[i] = sumFenwick(ft, i);
		for (int i = n - 1; i >= 1; i--)
			ret[i] -= ret[i - 1];
		return ret;
	}

	public static int before(int[] ft, int x) {
		int u = sumFenwick(ft, x - 1);
		if (u == 0)
			return -1;
		return findGFenwick(ft, u - 1) + 1;
	}

	public static int after(int[] ft, int x) {
		int u = sumFenwick(ft, x);
		int f = findGFenwick(ft, u);
		if (f + 1 >= ft.length - 1)
			return -1;
		return f + 1;
	}

	public static int[] buildFenwick(int[] a) {
		int n = a.length;
		int[] ft = new int[n + 1];
		System.arraycopy(a, 0, ft, 1, n);
		for (int k = 2, h = 1; k <= n; k *= 2, h *= 2) {
			for (int i = k; i <= n; i += k) {
				ft[i] += ft[i - h];
			}
		}
		return ft;
	}

	public static int[] buildFenwick(int n, int v) {
		int[] ft = new int[n + 1];
		Arrays.fill(ft, 1, n + 1, v);
		for (int k = 2, h = 1; k <= n; k *= 2, h *= 2) {
			for (int i = k; i <= n; i += k) {
				ft[i] += ft[i - h];
			}
		}
		return ft;
	}
	
	public static int[] decomposeToHeavyLight(int[][] g, int[] par, int[] ord) {
		int n = g.length;
		int[] size = new int[n];
		Arrays.fill(size, 1);
		for (int i = n - 1; i > 0; i--)
			size[par[ord[i]]] += size[ord[i]];

		int[] clus = new int[n];
		Arrays.fill(clus, -1);
		int p = 0;
		outer: for (int i = 0; i < n; i++) {
			int u = ord[i];
			if (clus[u] == -1)
				clus[u] = p++;
			for (int v : g[u]) {
				if (par[u] != v && size[v] >= size[u] / 2) {
					clus[v] = clus[u];
					continue outer;
				}
			}
			for (int v : g[u]) {
				if (par[u] != v) {
					clus[v] = clus[u];
					break;
				}
			}
		}
		return clus;
	}

	public static int[][] clusPaths(int[] clus, int[] ord) {
		int n = clus.length;
		int[] rp = new int[n];
		int sup = 0;
		for (int i = 0; i < n; i++) {
			rp[clus[i]]++;
			sup = Math.max(sup, clus[i]);
		}
		sup++;

		int[][] row = new int[sup][];
		for (int i = 0; i < sup; i++)
			row[i] = new int[rp[i]];

		for (int i = n - 1; i >= 0; i--) {
			row[clus[ord[i]]][--rp[clus[ord[i]]]] = ord[i];
		}
		return row;
	}

	public static int[] clusIInd(int[][] clusPath, int n) {
		int[] iind = new int[n];
		for (int[] path : clusPath) {
			for (int i = 0; i < path.length; i++) {
				iind[path[i]] = i;
			}
		}
		return iind;
	}

	public static int[][] query2(int x, int anc, int y, int[] clus,
			int[][] cluspath, int[] clusiind, int[] par) {
		int[][] stack = new int[60][];
		int sp = 0;

		int cx = clus[x]; // 
		int indx = clusiind[x]; // 
		while (cx != clus[anc]) {
			stack[sp++] = new int[] { cx, indx, 0 };
			int con = par[cluspath[cx][0]];
			indx = clusiind[con];
			cx = clus[con];
		}
		stack[sp++] = new int[] { cx, indx, clusiind[anc] };

		int top = sp;
		int cy = clus[y]; // 
		int indy = clusiind[y]; // 
		while (cy != clus[anc]) {
			stack[sp++] = new int[] { cy, 0, indy };
			int con = par[cluspath[cy][0]];
			indy = clusiind[con];
			cy = clus[con];
		}
		if (clusiind[anc] < indy) {
			stack[sp++] = new int[] { cy, clusiind[anc] + 1, indy };
		}
		for (int p = top, q = sp - 1; p < q; p++, q--) {
			int[] dum = stack[p];
			stack[p] = stack[q];
			stack[q] = dum;
		}
		return Arrays.copyOf(stack, sp);
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