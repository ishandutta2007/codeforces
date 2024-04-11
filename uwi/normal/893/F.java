//package educational.round33;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.List;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), root = ni()-1;
		int[] a = na(n);
		int[] from = new int[n - 1];
		int[] to = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			from[i] = ni() - 1;
			to[i] = ni() - 1;
		}
		int[][] g = packU(n, from, to);
		int[][] pars = parents3(g, root);
		int[] par = pars[0], ord = pars[1], dep = pars[2];
		
		int[][] ai = new int[n][];
		for(int i = 0;i < n;i++){
			ai[i] = new int[]{dep[i], a[i], i};
		}
		Arrays.sort(ai, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[0] != b[0])return a[0] - b[0];
				return a[1] - b[1];
			}
		});

		HeavyLightDecomposition hld = new HeavyLightDecomposition(g, par, ord, dep);
//		SegmentTreeOverwrite[] sts = new SegmentTreeOverwrite[hld.m];
		PersistentSegmentTreeOverwrite[] psts = new PersistentSegmentTreeOverwrite[hld.m];
		for(int i = 0;i < hld.m;i++){
//			sts[i] = new SegmentTreeOverwrite(hld.cluspath[i].length);
			psts[i] = new PersistentSegmentTreeOverwrite(hld.cluspath[i].length, 1);
		}
		
		// entries
		L[] times = new L[hld.m];
		L[] vals = new L[hld.m];
		for(int i = 0;i < hld.m;i++)times[i] = new L(1);
		for(int i = 0;i < hld.m;i++)vals[i] = new L(1);
		LST touched = new LST(hld.m);
		int maxdep = ai[ai.length-1][0];
		int pdep = 0;
		for(int[] v : ai){
			if(v[0] != pdep){
				for(int x = touched.next(0);x != -1;touched.unset(x), x = touched.next(0)){
					times[x].add(pdep);
					vals[x].add(psts[x].egen-1);
				}
				pdep = v[0];
			}
			for(int x = v[2];x != -1;){
				int cx = hld.clus[x];
				int l = 0;
				int r = hld.clusiind[x];
				
				if(psts[cx].get(l) > v[1]){
//					tr(cx, 0, r+1, v[1]);
					psts[cx].update(0, r+1, v[1]);
					touched.set(cx);
				}else{
					int low = 0, high = r+1;
					while(high - low > 1){
						int h = high+low>>1;
						if(psts[cx].get(h) > v[1]){
							high = h;
						}else{
							low = h;
						}
					}
//					tr(cx, high, r+1, v[1]);
					touched.set(cx);
					psts[cx].update(high, r+1, v[1]);
					break;
				}
//				if(sts[cx].get(l) > v[1]){
//					sts[cx].update(0, r+1, v[1]);
//				}else{
//					int low = 0, high = r+1;
//					while(high - low > 1){
//						int h = high+low>>1;
//						if(sts[cx].get(h) > v[1]){
//							high = h;
//						}else{
//							low = h;
//						}
//					}
//					sts[cx].update(high, r+1, v[1]);
//					break;
//				}
				x = par[hld.cluspath[cx][0]];
			}
			
		}
		for(int x = touched.next(0);x != -1;touched.unset(x), x = touched.next(0)){
			times[x].add(pdep);
			vals[x].add(psts[x].egen-1);
		}
		
		int last = 0;
		for(int Q = ni();Q > 0;Q--){
			int x = (ni() + last) % n;
			int K = (ni() + last) % n;
			int ind = hld.clusiind[x];
			int clus = hld.clus[x];
			int ent = vals[clus].a[upperBound(times[clus].a, 0, times[clus].p, dep[x]+K)];
			out.println(last = (int)psts[clus].get(ind, ent));
		}
	}
	
	public static int upperBound(int[] a, int v){ return upperBound(a, 0, a.length, v); }
	public static int upperBound(int[] a, int l, int r, int v)
	{
		int low = l-1, high = r;
		while(high-low > 1){
			int h = high+low>>>1;
			if(a[h] <= v){
				low = h;
			}else{
				high = h;
			}
		}
		return low;
	}

	
	public static class L {
		public int[] a;
		public int p = 0;
		
		public L(int n) { a = new int[n]; }
		public L add(int n)
		{
			if(p >= a.length)a = Arrays.copyOf(a, a.length*3/2+1);
			a[p++] = n;
			return this;
		}
		public int size() { return p; }
		public L clear() { p = 0; return this; }
		public int[] toArray() { return Arrays.copyOf(a, p); }
		@Override
		public String toString() {return Arrays.toString(toArray());}
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

	
	public static class SegmentTreeOverwrite {
		public int M, H, N;
		public long[] cover;
		public long I = Long.MAX_VALUE;
		
		public SegmentTreeOverwrite(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			cover = new long[M];
			Arrays.fill(cover, I);
			for(int i = H-1;i >= 1;i--){
				propagate(i);
			}
		}
		
		private void propagate(int i){}
		
		public void update(int l, int r, long v){ update(l, r, v, 0, H, 1); }
		
		private void update(int l, int r, long v, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				cover[cur] = v;
				propagate(cur);
			}else{
				int mid = cl+cr>>>1;
				if(cover[cur] != I){ // back-propagate
					cover[2*cur] = cover[2*cur+1] = cover[cur];
					cover[cur] = I;
					propagate(2*cur);
					propagate(2*cur+1);
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
		
		public long get(int x){ 
			long val = I;
			for(int i = H+x;i >= 1;i>>>=1){
				if(cover[i] != I)val = cover[i];
			}
			return val;
		}
	}

	
	public static class HeavyLightDecomposition {
		public int[][] g;
		public int[] clus;
		public int[][] cluspath;
		public int[] clusiind;
		public int[] par, dep;
		public int m;
		
		public HeavyLightDecomposition(int[][] g, int[] par, int[] ord, int[] dep)
		{
			init(g, par, ord, dep);
		}
		
		public void init(int[][] g, int[] par, int[] ord, int[] dep)
		{
			clus = decomposeToHeavyLight(g, par, ord);
			cluspath = clusPaths(clus, ord);
			clusiind = clusIInd(cluspath, g.length);
			this.m = cluspath.length;
			this.par = par;
			this.dep = dep;
			this.g = g;
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
			for(int i = 0;i < n;i++){
				int u = ord[i];
				if(clus[u] == -1)clus[u] = p++;
				// centroid path (not heavy path)
				int argmax = -1;
				for(int v : g[u]){
					if(par[u] != v && (argmax == -1 || size[v] > size[argmax]))argmax = v;
				}
				if(argmax != -1)clus[argmax] = clus[u];
			}
			return clus;
		}
		
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
		
		public int lca(int x, int y)
		{
			int rx = cluspath[clus[x]][0];
			int ry = cluspath[clus[y]][0];
			while(clus[x] != clus[y]){
				if(dep[rx] > dep[ry]){
					x = par[rx];
					rx = cluspath[clus[x]][0];
				}else{
					y = par[ry];
					ry = cluspath[clus[y]][0];
				}
			}
			return clusiind[x] > clusiind[y] ? y : x;
		}
		
		public int ancestor(int x, int v)
		{
			while(x != -1){
				if(v <= clusiind[x])return cluspath[clus[x]][clusiind[x]-v];
				v -= clusiind[x]+1;
				x = par[cluspath[clus[x]][0]];
			}
			return x;
		}
		
		// NOT VERIFIED
		// [iord[x], right[x])
		public int[][] makeRights()
		{
			int root = -1;
			int n = g.length;
			for(int i = 0;i < n;i++)if(par[i] == -1)root = i;
			
			int[] ord = new int[n];
			int[] right = new int[n];
			
			int[] curs = new int[n];
			int[] inds = new int[n];
			int sp = 0, p = 0;
			curs[sp++] = root;
			while(sp > 0){
				int cur = curs[sp-1];
				int ind = inds[sp-1];
				inds[sp-1]++;
				if(ind == 0){
					ord[p++] = cur;
					for(int e : g[cur]){
						if(par[cur] == e)continue;
						if(clus[cur] == clus[e]){
							curs[sp] = e;
							inds[sp] = 0;
							sp++;
							break;
						}
					}
				}else if(ind-1 < g[cur].length){
					int e = g[cur][ind-1];
					if(e == par[cur])continue;
					if(clus[cur] == clus[e])continue;
					curs[sp] = e;
					inds[sp] = 0;
					sp++;
				}else{
					right[cur] = p;
					sp--;
				}
			}
			int[] iord = new int[n];
			for(int i = 0;i < n;i++)iord[ord[i]] = i;
			return new int[][]{ord, iord, right};
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

	
	public static class PersistentSegmentTreeOverwrite {
		public long[] cover;
		public int[] len;
		public int[] L;
		public int[] R;
		public int gen;
		public int egen;
		public int H;
		public int[] entries;
		public long I = Long.MAX_VALUE;
		public int bufsize;
		
		public PersistentSegmentTreeOverwrite(int n, int q) {
			H = Integer.highestOneBit(Math.max(n-1, 1))<<1;
			bufsize = 2*H + 1;
			
			gen = 0;
			entries = new int[q+1];
			cover = new long[bufsize];
			len = new int[bufsize];
			L = new int[bufsize];
			R = new int[bufsize];
			Arrays.fill(L, -1);
			Arrays.fill(R, -1);
			Arrays.fill(cover, I);
			
			egen = 0;
			entries[egen++] = make(0, H);
		}
		
		private int make(int l, int r)
		{
			int id = gen++;
			len[id] = r-l;
			if(r-l > 1){
				L[id] = make(l, l+r>>>1);
				R[id] = make(l+r>>>1, r);
			}
			return id;
		}
		
		private int clone(int id)
		{
			if(id == -1)return -1;
			// fall
//			if(cover[id] != I && len[id] > 1){
//				if(L[id] != -1)cover[L[id]] = cover[id];
//				if(R[id] != -1)cover[R[id]] = cover[id];
//				cover[id] = I;
//			}
			if(gen == bufsize){
				len = Arrays.copyOf(len, bufsize*2);
				L = Arrays.copyOf(L, bufsize*2);
				R = Arrays.copyOf(R, bufsize*2);
				cover = Arrays.copyOf(cover, bufsize*2);
				Arrays.fill(L, bufsize, bufsize*2, -1);
				Arrays.fill(R, bufsize, bufsize*2, -1);
				Arrays.fill(cover, bufsize, bufsize*2, I);
				bufsize *= 2;
			}
			
			int cloned = gen++;
			len[cloned] = len[id];
			L[cloned] = L[id];
			R[cloned] = R[id];
			cover[cloned] = cover[id];
			return cloned;
		}
		
		public void update(int l, int r, long v)
		{
			update(l, r, v, egen-1);
		}
		
		public void update(int l, int r, long v, int eid)
		{
			if(egen == entries.length){
				entries = Arrays.copyOf(entries, entries.length*2);
			}
			entries[egen++] = updatedfs(l, r, v, entries[eid], false);
//			System.out.println(egen);
//			System.out.println(Arrays.toString(len));
//			System.out.println(Arrays.toString(L));
//			System.out.println(Arrays.toString(R));
//			System.out.println(Arrays.toString(cover));
//			System.out.println(Arrays.toString(entries));
		}
		
		private int updatedfs(int l, int r, long v, int cur, boolean already)
		{
			assert cur != -1;
			int cloned = already ? cur : clone(cur);
			
//			System.err.println(len[cloned] + " " + cloned + " " + cur + " " + l + " " + r);
			if(l <= 0 && len[cloned] <= r){
				cover[cloned] = v;
				return cloned;
			}else{
				int h = len[cloned]/2;
				boolean alr = false;
				if(cover[cloned] != I){
					int res = clone(L[cloned]);
					L[cloned] = res;
					res = clone(R[cloned]);
					R[cloned] = res;
					if(L[cloned] != -1)cover[L[cloned]] = cover[cloned];
					if(R[cloned] != -1)cover[R[cloned]] = cover[cloned];
					cover[cloned] = I;
					alr = true;
				}
				
				// [0, h), [l, r)
				if(l < h && 0 < r){
					int res = updatedfs(l, r, v, L[cloned], alr);
					L[cloned] = res; 
				}
				if(l < len[cloned] && h < r){
					int res = updatedfs(l-h, r-h, v, R[cloned], alr);
					R[cloned] = res; 
				}
				propagate(cloned);
				return cloned;
			}
		}
		
		public long get(int x){ 
			return get(x, egen-1);
		}
		
		public long get(int x, int eid){ 
			return getdfs(x, entries[eid]);
		}
		
		private long getdfs(int x, int cur)
		{
//			if(cur == -1)return I;
			if(cover[cur] != I || len[cur] == 1)return cover[cur];
			int h = len[cur]/2;
			if(x < h)return getdfs(x, L[cur]);
			return getdfs(x - h, R[cur]);
		}
		
		private void propagate(int cur)
		{
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