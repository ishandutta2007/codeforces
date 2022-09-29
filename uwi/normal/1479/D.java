//package round700;
import java.io.*;
import java.util.*;

public class D2 {
	InputStream is;
	FastWriter out;
	String INPUT = "";

	PersistentSegmentTreeRSQSimple pst;
	long[] zob;
	int[] egens;

	void solve()
	{
		int n = ni(), Q = ni();
		int[] a = na(n);
		Random gen = new Random();
		zob = gen.longs(400000).toArray();

		pst = new PersistentSegmentTreeRSQSimple(n+1, 2*n+1);
		egens = new int[n];

		int[] from = new int[n - 1];
		int[] to = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			from[i] = ni() - 1;
			to[i] = ni() - 1;
		}
		int[][] g = packU(n, from, to);

		dfs(0, -1, g, a);

		LCAFast2 lf = LCAFast2.build(g, 0);

		for(int z = 0;z < Q;z++){
			int u = ni()-1, v = ni()-1, l = ni(), r = ni();
			int ut = egens[u];
			int vt = egens[v];
			int lca = lf.lca(u, v);
			if(l <= a[lca] && a[lca] <= r){
//				tr(pst.sum(a[lca], a[lca]+1, ut), pst.sum(a[lca], a[lca]+1, vt));
				if(pst.sum(a[lca], a[lca]+1, ut) == pst.sum(a[lca], a[lca]+1, vt)){
					out.println(a[lca]);
					continue;
				}
				long res = pst.diff(l, a[lca], ut, vt);
				if(res != -1){
					out.println(res);
					continue;
				}
				res = pst.diff(a[lca] + 1, r+1, ut, vt);
				out.println(res);
			}else{
				long res = pst.diff(l, r+1, ut, vt);
				out.println(res);
			}
		}
	}

	public static class LCAFast2 {
		public int n, h;
		public int[][] bigst;
		public int[][] bigind;
		public long[][] smallb;
		public int[] vs, first, deps;

		public int lca(int a, int b)
		{
			return vs[rmqpos(Math.min(first[a], first[b]), Math.max(first[a], first[b]))];
		}

		public int pointOnPath(int a, int b, int dfroma)
		{
			int lca = lca(a, b);
			if(dfroma <= dep(a) - dep(lca)){
				return anc(a, dfroma);
			}
			int dfromb = dep(b) - dep(lca) - (dfroma - (dep(a) - dep(lca)));
			if(dfromb < 0)return -1;

			return anc(b, dfromb);
		}

		public int anc(int a, int d)
		{
			int da = dep(a);
			if(da < d)return -1;
			int danc = da - d;
			int low = 0, high = first[a] + 1;
			while(high - low > 1){
				int h = high+low>>1;
				if(rmqval(h, first[a]) <= danc){
					low = h;
				}else {
					high = h;
				}
			}
			return vs[low];
		}

		public int d(int a, int b)
		{
			return dep(a) + dep(b) - 2 * rmqval(Math.min(first[a], first[b]), Math.max(first[a], first[b]));
		}

		public int dep(int x)
		{
			return deps[first[x]];
		}

		public int rmqpos(int l, int r)
		{
			if(l > r)return -1;
			int cl = l>>>6;
			int cr = r>>>6;
			if(cl == cr){
				return argmax(smallb[l&63][cl], r-l+1) + l;
			}else{
				int min = deps[l] - max(smallb[l&63][cl], 63-(l&63)+1);
				int pos = argmax(smallb[l&63][cl], 63-(l&63)+1) + l;

				{
					int can = deps[r>>>6<<6] - max(smallb[0][cr], (r&63)-0+1);
					if(can < min){
						min = can;
						pos = argmax(smallb[0][cr], (r&63)-0+1) + (r>>>6<<6);
					}
				}

				if(cl+1 <= cr-1){
					int len = (cr-1)-(cl+1)+1;
					int h = 31-Integer.numberOfLeadingZeros(len);
					{
						int can = bigst[h][cl+1];
						if(can < min){
							min = can;
							pos = bigind[h][cl+1];
						}
					}
					{
						int can = bigst[h][cr-1-(1<<h)+1];
						if(can < min){
							min = can;
							pos = bigind[h][cr-1-(1<<h)+1];
						}
					}
				}
				return pos;
			}
		}

		public int rmqval(int l, int r)
		{
			if(l > r)return -1;
			int cl = l>>>6;
			int cr = r>>>6;
			if(cl == cr){
				return deps[l] - max(smallb[l&63][cl], r-l+1);
			}else{
				int min = deps[l] - max(smallb[l&63][cl], 63-(l&63)+1);
				min = Math.min(min, deps[r>>>6<<6] - max(smallb[0][cr], (r&63)-0+1));

				if(cl+1 <= cr-1){
					int len = (cr-1)-(cl+1)+1;
					int h = 31-Integer.numberOfLeadingZeros(len);
					min = Math.min(min, bigst[h][cl+1]);
					min = Math.min(min, bigst[h][cr-1-(1<<h)+1]);
				}
				return min;
			}
		}

		public static LCAFast2 build(int[][] g, int root)
		{
			LCAFast2 ret = new LCAFast2();
			int[][] et = eulerTour(g, root);
			int[] vs = et[0], deps = et[1], first = et[2];
			ret.vs = vs;
			ret.first = first;
			ret.deps = deps;

			int n = deps.length;
			int u = n+63>>>6;
			int h = 31-Integer.numberOfLeadingZeros(u) + 1;
			int[][] bigst = new int[h][];
			int[][] bigind = new int[h][];
			int[] cup = new int[u];
			int[] cupind = new int[u];
			Arrays.fill(cup, Integer.MAX_VALUE);
			for(int i = 0;i < n;i++){
				if(deps[i] < cup[i>>>6]){
					cup[i>>>6] = deps[i];
					cupind[i>>>6] = i;
				}
			}
			bigst[0] = cup;
			bigind[0] = cupind;
			for(int i = 1;i < h;i++){
				bigst[i] = new int[u-(1<<i)+1];
				bigind[i] = new int[u-(1<<i)+1];
				for(int j = 0;j + (1<<i) <= u;j++){
					if(bigst[i-1][j] < bigst[i-1][j+(1<<i-1)]){
						bigst[i][j] = bigst[i-1][j];
						bigind[i][j] = bigind[i-1][j];
					}else{
						bigst[i][j] = bigst[i-1][j+(1<<i-1)];
						bigind[i][j] = bigind[i-1][j+(1<<i-1)];
					}
				}
			}

			long[][] smallb = new long[64][u];
			for(int i = 0;i < u;i++){
				long x = 0;
				for(int j = 0;j < 63 && (i<<6|j+1) < n;j++){
					if(deps[i<<6|j] > deps[i<<6|j+1]){
						x |= 1L<<j;
					}
				}
				long val = 0;
				for(int j = 63;j >= 0;j--){
					val <<= 1;
					if(x<<~j<0){
						val |= 1L;
					}else{
						val &= val - 1;
					}
					smallb[j][i] = val;
				}
				//
				//			for(int j = 0;j < 64;j++){
				//				smallb[j][i] = make(x>>>j);
				//			}
			}

			ret.n = n; ret.h = h;
			ret.bigst = bigst;
			ret.bigind = bigind;
			ret.smallb = smallb;
			return ret;
		}

		public static int[][] eulerTour(int[][] g, int root)
		{
			int n = g.length;
			int[] vs = new int[2*n-1];
			int[] deps = new int[2*n-1];
			int[] first = new int[n];
			Arrays.fill(first, -1);
			int p = 0;

			int[] stack = new int[n];
			int[] inds = new int[n];
			int sp = 0;
			stack[sp++] = root;
			outer:
			while(sp > 0){
				int cur = stack[sp-1], ind = inds[sp-1];
				vs[p] = cur;
				deps[p] = sp-1;
				if(first[cur] == -1)first[cur] = p;
				p++;
				while(ind < g[cur].length){
					int nex = g[cur][ind++];
					if(first[nex] == -1){
						inds[sp-1] = ind;
						stack[sp] = nex;
						inds[sp] = 0;
						sp++;
						continue outer;
					}
				}
				inds[sp-1] = ind;
				if(ind == g[cur].length)sp--;
			}

			return new int[][]{vs, deps, first};
		}

		// TinyRMQ
		public static long make(long x)
		{
			int h = 0;
			int max = 0;
			long ret = 0;
			for(int i = 0;i < 64;i++){
				if(x<<~i<0){
					h++;
				}else{
					h--;
				}
				if(h > max){
					max = h;
					ret |= 1L<<i;
				}
			}
			return ret;
		}

		public static int max(long x, int r)
		{
			assert r > 0;
			return Long.bitCount(x&(1L<<r-1)-1);
		}

		public static int argmax(long x, int r)
		{
			assert r > 0;
			return 64-Long.numberOfLeadingZeros(x&(1L<<r-1)-1);
		}
	}


	void dfs(int cur, int par, int[][] g, int[] a)
	{
		pst.flip(a[cur], zob[a[cur]]);
		egens[cur] = pst.egen-1;
		for(int e : g[cur]){
			if(par == e)continue;
			dfs(e, cur, g, a);
		}
		pst.flip(a[cur], zob[a[cur]]);
	}

	public static int[][] parents(int[][] g, int root) {
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
		return new int[][]{par, q, depth};
	}


	public static int[][] packU(int n, int[] from, int[] to) {
		return packU(n, from, to, from.length);
	}

	public static int[][] packU(int n, int[] from, int[] to, int sup) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for (int i = 0; i < sup; i++) p[from[i]]++;
		for (int i = 0; i < sup; i++) p[to[i]]++;
		for (int i = 0; i < n; i++) g[i] = new int[p[i]];
		for (int i = 0; i < sup; i++) {
			g[from[i]][--p[from[i]]] = to[i];
			g[to[i]][--p[to[i]]] = from[i];
		}
		return g;
	}

	public static class PersistentSegmentTreeRSQSimple {
		public long[] st;
		public int[] len;
		public int[] L;
		public int[] R;
		public int gen;
		public int egen;
		public int H;
		public int[] entries;

		public PersistentSegmentTreeRSQSimple(int n, int q) {
			H = Integer.highestOneBit(Math.max(n-1, 1))<<1;
			int bufsize = (1+Integer.numberOfTrailingZeros(H)) * q + 2*H;

			gen = 0;
			entries = new int[q+1];
			st = new long[bufsize];
			len = new int[bufsize];
			L = new int[bufsize];
			R = new int[bufsize];
			Arrays.fill(L, -1);
			Arrays.fill(R, -1);

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

		public void flip(int x, long v)
		{
			flip(x, v, egen-1);
		}

		public void flip(int x, long v, int eid)
		{
			entries[egen++] = flipdfs(x, v, entries[eid]);
		}

		private int clone(int id)
		{
			int cloned = gen++;
			len[cloned] = len[id];
			L[cloned] = L[id];
			R[cloned] = R[id];
			st[cloned] = st[id];
			return cloned;
		}

		private int flipdfs(int x, long v, int cur)
		{
			assert cur != -1;
			int cloned = clone(cur);
			if(len[cloned] == 1){
				st[cloned] ^= v;
				return cloned;
			}else{
				int h = len[cloned]/2;
				if(x < h){
					L[cloned] = flipdfs(x, v, L[cloned]);
				}else{
					R[cloned] = flipdfs(x-h, v, R[cloned]);
				}
				propagate(cloned);
				return cloned;
			}
		}

		public long sum(int l, int r, int eid)
		{
			return l >= r ? 0L : sumdfs(l, r, entries[eid]);
		}

		private long sumdfs(int l, int r, int cur)
		{
			//			tr(l, r, cur, len[cur]);
			assert cur != -1;
			if(l == 0 && r == len[cur]){
				return st[cur];
			}else{
				int h = len[cur]/2;
				long ret = 0;
				if(l < h)ret = sumdfs(l, Math.min(h, r), L[cur]);
				if(h < r)ret ^= sumdfs(Math.max(l-h, 0), r-h, R[cur]);
				return ret;
			}
		}

		public long diff(int l, int r, int eid, int fid)
		{
			if(l >= r)return -1;
			long res = diffdfs(l, r, entries[eid], entries[fid]);
			return res;
		}

		private long diffdfs(int l, int r, int eid, int fid)
		{
			if(len[eid] == 1){
				return st[eid] != st[fid] ? 0 : -1;
			}
			if(l <= 0 && r >= len[eid] && st[eid] == st[fid])return -1;
//			System.out.println(l + " " + r + " " + st[eid] + " " + st[fid]);

			int h = len[eid]/2;
			if(l < h){
				long res = diffdfs(l, Math.min(h, r), L[eid], L[fid]);
				if(res != -1)return res;
			}
			if(h < r){
				long res = diffdfs(Math.max(l-h, 0), r-h, R[eid], R[fid]);
				if(res != -1){
					return res + h;//
				}
			}
			return -1;
		}

		private void propagate(int cur)
		{
			st[cur] = 0;
			if(L[cur] != -1)st[cur] = st[L[cur]];
			if(R[cur] != -1)st[cur] ^= st[R[cur]];
		}
	}


	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new FastWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new D2().run(); }
	
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

	private int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}

	private long[] nal(int n)
	{
		long[] a = new long[n];
		for(int i = 0;i < n;i++)a[i] = nl();
		return a;
	}

	private char[][] nm(int n, int m) {
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}

	private int[][] nmi(int n, int m) {
		int[][] map = new int[n][];
		for(int i = 0;i < n;i++)map[i] = na(m);
		return map;
	}

	private int ni() { return (int)nl(); }

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

	public static class FastWriter
	{
		private static final int BUF_SIZE = 1<<13;
		private final byte[] buf = new byte[BUF_SIZE];
		private final OutputStream out;
		private int ptr = 0;

		private FastWriter(){out = null;}

		public FastWriter(OutputStream os)
		{
			this.out = os;
		}

		public FastWriter(String path)
		{
			try {
				this.out = new FileOutputStream(path);
			} catch (FileNotFoundException e) {
				throw new RuntimeException("FastWriter");
			}
		}

		public FastWriter write(byte b)
		{
			buf[ptr++] = b;
			if(ptr == BUF_SIZE)innerflush();
			return this;
		}

		public FastWriter write(char c)
		{
			return write((byte)c);
		}

		public FastWriter write(char[] s)
		{
			for(char c : s){
				buf[ptr++] = (byte)c;
				if(ptr == BUF_SIZE)innerflush();
			}
			return this;
		}

		public FastWriter write(String s)
		{
			s.chars().forEach(c -> {
				buf[ptr++] = (byte)c;
				if(ptr == BUF_SIZE)innerflush();
			});
			return this;
		}

		private static int countDigits(int l) {
			if (l >= 1000000000) return 10;
			if (l >= 100000000) return 9;
			if (l >= 10000000) return 8;
			if (l >= 1000000) return 7;
			if (l >= 100000) return 6;
			if (l >= 10000) return 5;
			if (l >= 1000) return 4;
			if (l >= 100) return 3;
			if (l >= 10) return 2;
			return 1;
		}

		public FastWriter write(int x)
		{
			if(x == Integer.MIN_VALUE){
				return write((long)x);
			}
			if(ptr + 12 >= BUF_SIZE)innerflush();
			if(x < 0){
				write((byte)'-');
				x = -x;
			}
			int d = countDigits(x);
			for(int i = ptr + d - 1;i >= ptr;i--){
				buf[i] = (byte)('0'+x%10);
				x /= 10;
			}
			ptr += d;
			return this;
		}

		private static int countDigits(long l) {
			if (l >= 1000000000000000000L) return 19;
			if (l >= 100000000000000000L) return 18;
			if (l >= 10000000000000000L) return 17;
			if (l >= 1000000000000000L) return 16;
			if (l >= 100000000000000L) return 15;
			if (l >= 10000000000000L) return 14;
			if (l >= 1000000000000L) return 13;
			if (l >= 100000000000L) return 12;
			if (l >= 10000000000L) return 11;
			if (l >= 1000000000L) return 10;
			if (l >= 100000000L) return 9;
			if (l >= 10000000L) return 8;
			if (l >= 1000000L) return 7;
			if (l >= 100000L) return 6;
			if (l >= 10000L) return 5;
			if (l >= 1000L) return 4;
			if (l >= 100L) return 3;
			if (l >= 10L) return 2;
			return 1;
		}

		public FastWriter write(long x)
		{
			if(x == Long.MIN_VALUE){
				return write("" + x);
			}
			if(ptr + 21 >= BUF_SIZE)innerflush();
			if(x < 0){
				write((byte)'-');
				x = -x;
			}
			int d = countDigits(x);
			for(int i = ptr + d - 1;i >= ptr;i--){
				buf[i] = (byte)('0'+x%10);
				x /= 10;
			}
			ptr += d;
			return this;
		}

		public FastWriter write(double x, int precision)
		{
			if(x < 0){
				write('-');
				x = -x;
			}
			x += Math.pow(10, -precision)/2;
			//		if(x < 0){ x = 0; }
			write((long)x).write(".");
			x -= (long)x;
			for(int i = 0;i < precision;i++){
				x *= 10;
				write((char)('0'+(int)x));
				x -= (int)x;
			}
			return this;
		}

		public FastWriter writeln(char c){
			return write(c).writeln();
		}

		public FastWriter writeln(int x){
			return write(x).writeln();
		}

		public FastWriter writeln(long x){
			return write(x).writeln();
		}

		public FastWriter writeln(double x, int precision){
			return write(x, precision).writeln();
		}

		public FastWriter write(int... xs)
		{
			boolean first = true;
			for(int x : xs) {
				if (!first) write(' ');
				first = false;
				write(x);
			}
			return this;
		}

		public FastWriter write(long... xs)
		{
			boolean first = true;
			for(long x : xs) {
				if (!first) write(' ');
				first = false;
				write(x);
			}
			return this;
		}

		public FastWriter writeln()
		{
			return write((byte)'\n');
		}

		public FastWriter writeln(int... xs)
		{
			return write(xs).writeln();
		}

		public FastWriter writeln(long... xs)
		{
			return write(xs).writeln();
		}

		public FastWriter writeln(char[] line)
		{
			return write(line).writeln();
		}

		public FastWriter writeln(char[]... map)
		{
			for(char[] line : map)write(line).writeln();
			return this;
		}

		public FastWriter writeln(String s)
		{
			return write(s).writeln();
		}

		private void innerflush()
		{
			try {
				out.write(buf, 0, ptr);
				ptr = 0;
			} catch (IOException e) {
				throw new RuntimeException("innerflush");
			}
		}

		public void flush()
		{
			innerflush();
			try {
				out.flush();
			} catch (IOException e) {
				throw new RuntimeException("flush");
			}
		}

		public FastWriter print(byte b) { return write(b); }
		public FastWriter print(char c) { return write(c); }
		public FastWriter print(char[] s) { return write(s); }
		public FastWriter print(String s) { return write(s); }
		public FastWriter print(int x) { return write(x); }
		public FastWriter print(long x) { return write(x); }
		public FastWriter print(double x, int precision) { return write(x, precision); }
		public FastWriter println(char c){ return writeln(c); }
		public FastWriter println(int x){ return writeln(x); }
		public FastWriter println(long x){ return writeln(x); }
		public FastWriter println(double x, int precision){ return writeln(x, precision); }
		public FastWriter print(int... xs) { return write(xs); }
		public FastWriter print(long... xs) { return write(xs); }
		public FastWriter println(int... xs) { return writeln(xs); }
		public FastWriter println(long... xs) { return writeln(xs); }
		public FastWriter println(char[] line) { return writeln(line); }
		public FastWriter println(char[]... map) { return writeln(map); }
		public FastWriter println(String s) { return writeln(s); }
		public FastWriter println() { return writeln(); }
	}

	public void trnz(int... o)
	{
		for(int i = 0;i < o.length;i++)if(o[i] != 0)System.out.print(i+":"+o[i]+" ");
		System.out.println();
	}

	// print ids which are 1
	public void trt(long... o)
	{
		Queue<Integer> stands = new ArrayDeque<>();
		for(int i = 0;i < o.length;i++){
			for(long x = o[i];x != 0;x &= x-1)stands.add(i<<6|Long.numberOfTrailingZeros(x));
		}
		System.out.println(stands);
	}

	public void tf(boolean... r)
	{
		for(boolean x : r)System.out.print(x?'#':'.');
		System.out.println();
	}

	public void tf(boolean[]... b)
	{
		for(boolean[] r : b) {
			for(boolean x : r)System.out.print(x?'#':'.');
			System.out.println();
		}
		System.out.println();
	}

	public void tf(long[]... b)
	{
		if(INPUT.length() != 0) {
			for (long[] r : b) {
				for (long x : r) {
					for (int i = 0; i < 64; i++) {
						System.out.print(x << ~i < 0 ? '#' : '.');
					}
				}
				System.out.println();
			}
			System.out.println();
		}
	}

	public void tf(long... b)
	{
		if(INPUT.length() != 0) {
			for (long x : b) {
				for (int i = 0; i < 64; i++) {
					System.out.print(x << ~i < 0 ? '#' : '.');
				}
			}
			System.out.println();
		}
	}

	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}