//package round4;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Set;

public class G2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), Q = ni();
		int[] par = new int[n];
		par[0] = -1;
		for(int i = 1;i < n;i++){
			par[i] = ni()-1;
		}
		int[] a = na(n);
		int[] b = na(n);
		
		int B = Math.max(1, (int)Math.sqrt(n));
		
		int[][] g = parentToG(par);
		
		int[][] rights = makeRights(g, par, 0);
		int[] iord = rights[1], right = rights[2];
		long[] ws = new long[n+1];
		for(int i = 0;i < n;i++){
			ws[iord[i]] += b[i];
			ws[right[iord[i]]+1] -= b[i];
		}
		for(int i = 0;i < n;i++){
			ws[i+1] += ws[i];
		}
		for(int i = 0;i < n;i++){
			ws[i] = Math.abs(ws[i]);
		}
		
		long[] vs = new long[n+1];
		for(int i = 0;i < n;i++){
			vs[iord[i]] += a[i];
			vs[right[iord[i]]+1] -= a[i];
		}
		for(int i = 0;i < n;i++){
			vs[i+1] += vs[i];
		}
		
		int[][] ords = new int[n/B+1][];
		for(int i = 0;i < n;i+=B){
			long[][] as = new long[B][];
			int p = 0;
			for(int j = i;j < i+B && j < n;j++){
				as[p++] = new long[]{-ws[j], j};
			}
			Arrays.sort(as, 0, p, new Comparator<long[]>() {
				public int compare(long[] a, long[] b) {
					return -Long.compare(a[0], b[0]);
				}
			});
			ords[i/B] = new int[p];
			for(int j = 0;j < p;j++){
				ords[i/B][j] = (int)as[j][1];
			}
		}
		
		StarrySkyTreeL sst = new StarrySkyTreeL(n);
		for(int i = 0;i < n;i++){
			if(vs[i] < 0){
				sst.add(i, i+1, -vs[i]-sst.I);
			}
		}
		
		EnvelopeLinearDeque[][] elds = new EnvelopeLinearDeque[n/B+1][];
		for(int i = 0;i < n;i+=B){
			elds[i/B] = construct(ords[i/B], vs, ws);
		}
		long[] offset = new long[n/B+1];
		
		for(int z = 0;z < Q;z++){
			int t = ni();
			if(t == 1){
				int v = ni()-1;
				int x = ni();
				sst.add(iord[v], right[iord[v]]+1, -x);
				Set<Integer> recs = new HashSet<>();
				while(true){
					int fle = sst.firstle(0, 0);
					if(fle == -1)break;
					sst.add(fle, fle+1, sst.I);
					for(int i = fle/B*B;i < fle/B*B+B && i < n;i++){
						vs[i] += offset[fle/B];
					}
					offset[fle/B] = 0;
					recs.add(fle/B);
				}
				
				int l = iord[v];
				int r = right[iord[v]];
				if(l/B == r/B){
					for(int i = l;i <= r;i++){
						vs[i] += x;
					}
					recs.add(l/B);
				}else{
					for(int i = l;i < l/B*B+B && i < n;i++){
						vs[i] += x;
					}
					for(int i = r/B*B;i <= r;i++){
						vs[i] += x;
					}
					recs.add(l/B);
					recs.add(r/B);
					for(int i = l/B+1;i < r/B;i++){
						offset[i] += x;
					}
				}
				for(int y : recs){
					for(int j = y*B;j < y*B+B && j < n;j++){
						vs[j] += offset[y];
					}
					offset[y] = 0;
					elds[y] = construct(ords[y], vs, ws);
				}
			}else{
				int v = ni()-1;
				int l = iord[v];
				int r = right[iord[v]];
//				tr(l, r, l/B, r/B);
				if(l/B == r/B){
					long max = 0;
					for(int i = l;i <= r;i++){
						max = Math.max(max, Math.abs(offset[i/B] + vs[i]) * ws[i]);
					}
					out.println(max);
				}else{
					long max = 0;
					for(int i = l;i < l/B*B+B && i < n;i++){
						max = Math.max(max, Math.abs(offset[i/B] + vs[i]) * ws[i]);
					}
					for(int i = r/B*B;i <= r;i++){
						max = Math.max(max, Math.abs(offset[i/B] + vs[i]) * ws[i]);
					}
//					long omax = max;
					for(int i = l/B+1;i < r/B;i++){
						max = Math.max(max, -elds[i][0].get(offset[i]));
						max = Math.max(max, -elds[i][1].get(offset[i]));
					}
//					if(omax != max)tr("O");
					out.println(max);
				}
			}
		}
	}
	
	EnvelopeLinearDeque[] construct(int[] ord, long[] vs, long[] ws)
	{
		EnvelopeLinearDeque[] ret = new EnvelopeLinearDeque[2];
		
		{
			int p = 0;
			for(int i : ord){
				if(vs[i] >= 0){
					p++;
				}
			}
			EnvelopeLinearDeque eld = new EnvelopeLinearDeque(p);
			for(int i : ord){
				if(vs[i] >= 0){
					eld.add(-ws[i], -vs[i]*ws[i]);
				}
			}
			ret[0] = eld;
		}
		{
			int p = 0;
			for(int j = ord.length-1;j >= 0;j--){
				if(vs[ord[j]] < 0){
					p++;
				}
			}
			EnvelopeLinearDeque eld = new EnvelopeLinearDeque(p);
			for(int j = ord.length-1;j >= 0;j--){
				int i = ord[j];
				if(vs[i] < 0){
					eld.add(ws[i], vs[i]*ws[i]);
				}
			}
			ret[1] = eld;
		}
		return ret;
	}
	
	public static class StarrySkyTreeL {
		public int M, H, N;
		public long[] st;
		public long[] plus;
		public long I = Long.MAX_VALUE/4; // I+plus<long
		
		public StarrySkyTreeL(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(n-1, 1))<<2;
			H = M>>>1;
			st = new long[M];
			Arrays.fill(st, I);
			plus = new long[H];
		}
		
		// 10
		// -3    -7
		// -3 -1
		
		public StarrySkyTreeL(long[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new long[M];
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
			}
			plus = new long[H];
			Arrays.fill(st, H+N, M, I);
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		private void propagate(int i)
		{
			st[i] = Math.min(st[2*i], st[2*i+1]) + plus[i];
		}
		
		public void add(int l, int r, long v){ if(l < r)add(l, r, v, 0, H, 1); }
		
		private void add(int l, int r, long v, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				if(cur >= H){
					st[cur] += v;
				}else{
					plus[cur] += v;
					propagate(cur);
				}
			}else{
				int mid = cl+cr>>>1;
				if(cl < r && l < mid){
					add(l, r, v, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					add(l, r, v, mid, cr, 2*cur+1);
				}
				propagate(cur);
			}
		}
		
		public long min(int l, int r){ return l >= r ? I : min(l, r, 0, H, 1);}
		
		private long min(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return st[cur];
			}else{
				int mid = cl+cr>>>1;
				long ret = I;
				if(cl < r && l < mid){
					ret = Math.min(ret, min(l, r, cl, mid, 2*cur));
				}
				if(mid < r && l < cr){
					ret = Math.min(ret, min(l, r, mid, cr, 2*cur+1));
				}
				return ret + plus[cur];
			}
		}
		
		public void fall(int i)
		{
			if(i < H){
				if(2*i < H){
					plus[2*i] += plus[i];
					plus[2*i+1] += plus[i];
				}
				st[2*i] += plus[i];
				st[2*i+1] += plus[i];
				plus[i] = 0;
			}
		}
		
		public int firstle(int l, long v) {
			int cur = H+l;
			for(int i = 1, j = Integer.numberOfTrailingZeros(H)-1;i <= cur;j--){
				fall(i);
				i = i*2|cur>>>j&1;
			}
			while(true){
				fall(cur);
				if(st[cur] <= v){
					if(cur < H){
						cur = 2*cur;
					}else{
						return cur-H;
					}
				}else{
					cur++;
					if((cur&cur-1) == 0)return -1;
					cur = cur>>>Integer.numberOfTrailingZeros(cur);
				}
			}
		}
		
		public int lastle(int l, long v) {
			int cur = H+l;
			for(int i = 1, j = Integer.numberOfTrailingZeros(H)-1;i <= cur;j--){
				fall(i);
				i = i*2|cur>>>j&1;
			}
			while(true){
				fall(cur);
				if(st[cur] <= v){
					if(cur < H){
						cur = 2*cur+1;
					}else{
						return cur-H;
					}
				}else{
					if((cur&cur-1) == 0)return -1;
					cur = cur>>>Integer.numberOfTrailingZeros(cur);
					cur--;
				}
			}
		}
		
		public void addx(int l, int r, long v){
			if(l >= r)return;
			while(l != 0){
				int f = l&-l;
				if(l+f > r)break;
				if(f == 1){
					st[(H+l)/f] += v;
				}else{
					plus[(H+l)/f] += v;
				}
				l += f;
			}
			
			while(l < r){
				int f = r&-r;
				if(f == 1){
					st[(H+r)/f-1] += v;
				}else{
					plus[(H+r)/f-1] += v;
				}
				r -= f;
			}
		}
		
		public long minx(int l, int r){
			long lmin = I;
			if(l >= r)return lmin;
			if(l != 0){
				for(int d = 0;H>>>d > 0;d++){
					if(d > 0){
						int id = (H+l-1>>>d);
						lmin += plus[id];
					}
					if(l<<~d<0 && l+(1<<d) <= r){
						long v = st[H+l>>>d];
						if(v < lmin)lmin = v;
						l += 1<<d;
					}
				}
			}
			long rmin = I;
			for(int d = 0;H>>>d > 0;d++){
				if(d > 0 && r < H)rmin += plus[H+r>>>d];
				if(r<<~d<0 && l < r){
					long v = st[(H+r>>>d)-1];
					if(v < rmin)rmin = v;
					r -= 1<<d;
				}
			}
			long min = Math.min(lmin, rmin);
			return min;
		}
		
		public long[] toArray() { return toArray(1, 0, H, new long[H]); }
		
		private long[] toArray(int cur, int l, int r, long[] ret)
		{
			if(r-l == 1){
				ret[cur-H] = st[cur];
			}else{
				toArray(2*cur, l, l+r>>>1, ret);
				toArray(2*cur+1, l+r>>>1, r, ret);
				for(int i = l;i < r;i++)ret[i] += plus[cur];
			}
			return ret;
		}
	}

	
	public static int[] sortByPreorder(int[][] g, int root){
		int n = g.length;
		int[] stack = new int[n];
		int[] ord = new int[n];
		boolean[] ved = new boolean[n];
		stack[0] = root;
		int p = 1;
		int r = 0;
		ved[root] = true;
		while(p > 0){
			int cur = stack[p-1];
			ord[r++] = cur;
			p--;
			for(int e : g[cur]){
				if(!ved[e]){
					ved[e] = true;
					stack[p++] = e;
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
		for(int i = n-1;i >= 1;i--){
			if(right[i] == 0)right[i] = i;
			int p = iord[par[ord[i]]];
			right[p] = Math.max(right[p], right[i]);
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

	
	public static class EnvelopeLinearDeque {
		public long[] slopes, intercepts;
		public int f, b;
		
		public EnvelopeLinearDeque(int n)
		{
			slopes = new long[n];
			intercepts = new long[n];
			f = b = 0;
		}
		
		public long f(long x, int ind)
		{
			return slopes[ind]*x+intercepts[ind];
		}
		
		public double f(double x, int ind)
		{
			return slopes[ind]*x+intercepts[ind];
		}
		
		public long get(long x)
		{
			if(f == 0)return Long.MAX_VALUE / 4;
			while(f-b > 1 && f(x, b) > f(x, b+1))b++;
			return f(x, b);
		}
			
		public void add(long slope, long intercept)
		{
			if(f-b > 0)assert slope <= slopes[f-1];
			if(f-b > 0 && slope == slopes[f-1] && intercept >= intercepts[f-1])return;
			
			while(f-b > 0){
				// sl*x+in = lsl*x+lin
				// (sl-lsl)*x = lin-in
				long num = intercept-intercepts[f-1];
				long den = slopes[f-1] - slope;

				if(f-1-b > 0 && (slopes[f-2]*num+intercepts[f-2]*den) - (slopes[f-1]*num+intercepts[f-1]*den) < 0){
//				if(f-1-b > 0 && f(x, f-2) < f(x, f-1)){
					f--;
				}else{
					break;
				}
			}
			slopes[f] = slope;
			intercepts[f] = intercept;
			f++;
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
	
	public static void main(String[] args) throws Exception { new G2().run(); }
	
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