//package over2400;

import java.io.*;
import java.util.*;

public class Round372C2 {
	InputStream is;
	FastWriter out;
	String INPUT = "";

	static long[] tens;
	static long[] itens;
	static int mod;

	public static long[] enumPows(int a, int n, int mod)
	{
		a %= mod;
		long[] pows = new long[n+1];
		pows[0] = 1;
		for(int i = 1;i <= n;i++)pows[i] = pows[i-1] * a % mod;
		return pows;
	}

	public static long invl(long a, long mod) {
		long b = mod;
		long p = 1, q = 0;
		while (b > 0) {
			long c = a / b;
			long d;
			d = a;
			a = b;
			b = d % b;
			d = p;
			p = q;
			q = d - c * q;
		}
		return p < 0 ? p + mod : p;
	}


	void solve()
	{
		int n = ni();
		mod = ni();
		tens = enumPows(10, 100005, mod);
		itens = enumPows((int)invl(10, mod), 100005, mod);

		int[] from = new int[n - 1];
		int[] to = new int[n - 1];
		int[] ws = new int[n-1];
		for (int i = 0; i < n - 1; i++) {
			from[i] = ni();
			to[i] = ni();
			ws[i] = ni();
		}
		int[][][] g = packWU(n, from, to, ws);
		int[] cpar = buildCentroidTree(g);

		ans = 0;
		dfsTopCT(cpar, g);
		out.println(ans - n);
	}

	static class Context
	{
		boolean[] seps; // is separator?
		long[] wt; // [ind] = w between sep and ind
		int[] dt;
		long[] lower;
		long[] upper;
		int[] vs;
		int[][] vss; // [vertices][vertices]
		int[][] ctch;
		int[][][] g;
		int[] stack;
		int[] inds;
		int[] cpar;
	}

	public static Context dfsTopCT(int[] cpar, int[][][] g) {
		int n = g.length;
		int ctroot = -1;
		for(int i = 0;i < n;i++)if(cpar[i] == -1)ctroot = i;

		Context cx = new Context();
		cx.cpar = cpar;
		cx.seps = new boolean[n];
		//		cx.wt = new long[n];
		cx.dt = new int[n];
		cx.lower = new long[n];
		cx.upper = new long[n];
		cx.vs = new int[n];
		cx.vss = new int[n][];
		cx.ctch = parentToChildren(cpar);
		cx.g = g;
		cx.stack = new int[n];
		cx.inds = new int[n];

		dfs(ctroot, cx);
		return cx;
	}

	public static int[][] parentToChildren(int[] par)
	{
		int n = par.length;
		int[] ct = new int[n];
		for(int i = 0;i < n;i++){
			if(par[i] >= 0){
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
			}
		}

		return g;
	}



	private static void dfs(int sep, Context cx)
	{
		cx.seps[sep] = true;
		cx.dt[sep]= 0; //
		cx.lower[sep] = 0;
		cx.upper[sep] = 0;
		for(int[] neck : cx.g[sep]){
			if(cx.seps[neck[0]])continue;
			int subsep = -1;

			int sp = 0;
			cx.inds[sp] = 0;
			//			cx.wt[neck] = w[neck];
			cx.dt[neck[0]] = 1; //
			cx.lower[neck[0]] = neck[1] % mod;
			cx.upper[neck[0]] = neck[1] % mod;
			int vsp = 0;
			cx.stack[sp++] = neck[0];
			while(sp > 0){
				int cur = cx.stack[sp-1];
				if(cx.inds[sp-1] == 0){
					cx.vs[vsp++] = cur;
					if(cx.cpar[cur] == sep)subsep = cur;
				}
				if(cx.inds[sp-1] == cx.g[cur].length){
					sp--;
					continue;
				}
				int[] e = cx.g[cur][cx.inds[sp-1]++];
				if(!cx.seps[e[0]] && !(sp-2 >= 0 && e[0] == cx.stack[sp-2])){
					//					cx.wt[e[0]] = cx.wt[cur] + w[e[0]];
					cx.dt[e[0]] = sp + 1; //
					cx.lower[e[0]] = (cx.lower[cur] * 10 + e[1]) % mod;
					cx.upper[e[0]] = (cx.upper[cur] + e[1] * tens[sp]) % mod;
					cx.stack[sp] = e[0];
					cx.inds[sp] = 0;
					sp++;
				}
			}
			assert subsep != -1;
			cx.vss[subsep] = Arrays.copyOf(cx.vs, vsp);
		}

		process(sep, cx);

		for(int e : cx.ctch[sep])dfs(e, cx);
	}

	static long ans;

	private static void process(int sep, Context cx)
	{
		int m = 1;
		for(int c : cx.ctch[sep]){
			ans -= subprocess(cx.vss[c], cx);
			m += cx.vss[c].length;
		}
		int[] gvs = new int[m];
		gvs[0] = sep;
		int p = 1;
		for(int c : cx.ctch[sep]){
			System.arraycopy(cx.vss[c], 0, gvs, p, cx.vss[c].length);
			p += cx.vss[c].length;
		}
		ans += subprocess(gvs, cx);
	}

	private static long subprocess(int[] vs, Context cx)
	{
		LongHashCounterWithoutDeletion up = new LongHashCounterWithoutDeletion();
		Map<Long, Integer> up2 = new HashMap<>();
		for(int v : vs){
			up.plus(cx.upper[v], 1);
			up2.merge(cx.upper[v], 1, Integer::sum);
		}
		long ret = 0;
		for(int v : vs){
			long k = (-cx.lower[v] * itens[cx.dt[v]]) % mod;
			if(k < 0)k += mod;
			ret += up.get(k);
//			System.err.println(up.get(k) + " " + up2.getOrDefault(k, 0) + " " + k);
//			assert up.get(k) == up2.getOrDefault(k, 0);
		}
		return ret;
	}

	public static int[][][] packWU(int n, int[] from, int[] to, int[] w) {
		return packWU(n, from, to, w, from.length);
	}

	public static int[][][] packWU(int n, int[] from, int[] to, int[] w, int sup) {
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for (int i = 0; i < sup; i++) p[from[i]]++;
		for (int i = 0; i < sup; i++) p[to[i]]++;
		for (int i = 0; i < n; i++) g[i] = new int[p[i]][2];
		for (int i = 0; i < sup; i++) {
			--p[from[i]];
			g[from[i]][p[from[i]]][0] = to[i];
			g[from[i]][p[from[i]]][1] = w[i];
			--p[to[i]];
			g[to[i]][p[to[i]]][0] = from[i];
			g[to[i]][p[to[i]]][1] = w[i];
		}
		return g;
	}

	public static class LongHashCounterWithoutDeletion
	{
		int[] first;
		int[] next;
		long[] keys;
		int[] vals;
		int size;
		int scale;

		public LongHashCounterWithoutDeletion(int scale)
		{
			this.scale = scale;
			keys = new long[1<<scale];
			vals = new int[1<<scale];
			first = new int[1<<scale];
			next = new int[1<<scale];
			size = 0;
			Arrays.fill(first, -1);
			Arrays.fill(next, -1);
		}

		public LongHashCounterWithoutDeletion() { this(1); }

		public void rehash()
		{
			scale++;
			keys = Arrays.copyOf(keys, 1<<scale);
			vals = Arrays.copyOf(vals, 1<<scale);
			first = new int[1<<scale];
			next = new int[1<<scale];
			Arrays.fill(first, -1);
			Arrays.fill(next, -1);
			for(int i = 0;i < 1<<scale-1;i++){
				int h = h(keys[i])&(1<<scale)-1;
				next[i] = first[h];
				first[h] = i;
			}
		}

		public boolean put(long key, int val)
		{
			int h = h(key)&(1<<scale)-1;
			int ind = search(h, key);
			if(ind >= keys.length)rehash();
			keys[ind] = key;
			vals[ind] = val;
			if(ind == size){
				h = h(key)&(1<<scale)-1;
				next[ind] = first[h];
				first[h] = ind;
				size++;
				return true;
			}
			return false;
		}

		public boolean plus(long key, int val)
		{
			int h = h(key)&(1<<scale)-1;
			int ind = search(h, key);

			if(ind >= keys.length)rehash();
			keys[ind] = key;
			vals[ind] += val;
			if(ind == size){
				h = h(key)&(1<<scale)-1;
				next[ind] = first[h];
				first[h] = ind;
				size++;
				return true;
			}
			return false;
		}

		public boolean containsKey(long key)
		{
			int h = h(key)&(1<<scale)-1;
			int ind = search(h, key);
			return ind < size;
		}

		public int get(long key)
		{
			int h = h(key)&(1<<scale)-1;
			int ind = search(h, key);
			return ind < size ? vals[ind] : 0;
		}

		private int search(int h, long key)
		{
			for(int f = first[h];f != -1;f = next[f]){
				if(keys[f] == key)return f;
			}
			return size;
		}

		private int h(long x)
		{
			x ^= x>>>33;
			x *= 0xff51afd7ed558ccdL;
			x ^= x>>>33;
			x *= 0xc4ceb9fe1a85ec53L;
			x ^= x>>>33;
			return (int)(x^x>>>32);
		}
	}


	public static int[] buildCentroidTree(int[][][] g) {
		int n = g.length;
		int[] ctpar = new int[n];
		Arrays.fill(ctpar, -1);
		buildCentroidTree(g, 0, new boolean[n], new int[n], new int[n], new int[n], ctpar);
		return ctpar;
	}

	private static int buildCentroidTree(int[][][] g, int root, boolean[] sed, int[] par, int[] ord, int[] des, int[] ctpar)
	{
		// parent and level-order
		ord[0] = root;
		par[root] = -1;
		int r = 1;
		for(int p = 0;p < r;p++) {
			int cur = ord[p];
			for(int[] nex : g[cur]){
				if(par[cur] != nex[0] && !sed[nex[0]]){
					ord[r++] = nex[0];
					par[nex[0]] = cur;
				}
			}
		}
		// if(r == 1)return;

		// DP and find a separator
		int sep = -1; // always exists
		outer:
		for(int i = r-1;i >= 0;i--){
			int cur = ord[i];
			des[cur] = 1;
			for(int[] e : g[cur]){
				if(par[cur] != e[0] && !sed[e[0]])des[cur] += des[e[0]];
			}
			if(r-des[cur] <= r/2){
				for(int[] e : g[cur]){
					if(par[cur] != e[0] && !sed[e[0]] && des[e[0]] >= r/2+1)continue outer;
				}
				sep = cur;
				break;
			}
		}

		sed[sep] = true;
		for(int[] e : g[sep]){
			if(!sed[e[0]])ctpar[buildCentroidTree(g, e[0], sed, par, ord, des, ctpar)] = sep;
		}
		return sep;
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


	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new FastWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new Round372C2().run(); }
	
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