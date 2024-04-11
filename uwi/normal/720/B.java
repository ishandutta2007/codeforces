//package rcc2016.f;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class B4 {
	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";

	static void solve() {
		int n = ni(), m = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		int[] color = new int[m];
		int[] w = new int[m];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
			color[i] = ni()-1;
			w[i] = i;
		}
		// extract cycles
		int[][][] g = packWU(n, from, to, w);
		BCDatum datum = decomposeToBiconnectedComponents(g);
		
		boolean[] ced = new boolean[m];
		for(int i = 0;i < m;i++)ced[color[i]] = true;
		int all = 0;
		for(int i = 0;i < m;i++){
			if(ced[i])all++;
		}
		
		int[] fm = new int[m];
		int cp = 0;
		for(int i = 0;i < m;i++){
			fm[datum.edgeClus[i]]++;
			cp = Math.max(cp, datum.edgeClus[i]);
		}
		cp++;
		
		// if two cycles have one common color, they are connected.
		// if this graph has a cycle, a cycle is connected to universe.
		DJSet gds = new DJSet(cp+1+m);
		for(int i = 0;i < m;i++){
			if(gds.union(datum.edgeClus[i], cp+1+color[i]) || fm[datum.edgeClus[i]] == 1)gds.union(datum.edgeClus[i], cp);
		}
		
		// # connected component which is not connected to universe.
		boolean[] ved = new boolean[cp+1+m];
		for(int i = 0;i < cp;i++){
			if(gds.equiv(i, cp))continue;
			int root = gds.root(i);
			if(!ved[root]){
				ved[root] = true;
				all--;
			}
		}
		out.println(all);
	}
	
	public static int[][] makeBuckets(int[] a)
	{
		int n = a.length;
		int sup = 0;
		for(int v : a)sup = Math.max(sup, v);
		int[][] bucket = new int[sup+1][];
		int[] bp = new int[sup+1];
		for(int i = 0;i < n;i++)bp[a[i]]++;
		for(int i = 0;i <= sup;i++)bucket[i] = new int[bp[i]];
		for(int i = n-1;i >= 0;i--)bucket[a[i]][--bp[a[i]]] = i;
		return bucket;
	}
	
	// http://www.cs.umd.edu/class/fall2005/cmsc451/biconcomps.pdf
	public static BCDatum decomposeToBiconnectedComponents(int[][][] g)
	{
		int n = g.length;
		int m = 0;
		for(int[][] row : g)m += row.length;
		m /= 2;
		BCDatum d = new BCDatum();
		d.g = g;
		d.gen = 0;
		d.low = new int[n];
		Arrays.fill(d.low, -1);
		d.ord = new int[n];
		Arrays.fill(d.ord, -1);
		d.edgeStack = new int[m];
		d.esp = 0;
		d.edgeClus = new int[m];
		Arrays.fill(d.edgeClus, -1);
		d.visited = new boolean[n];
		d.parente = new int[n];
		d.isArtic = new boolean[n];
		Arrays.fill(d.parente, -1);
		for(int i = 0;i < n;i++){
			if(!d.visited[i])dfsBC(i, d);
		}
		assert d.esp == 0;
		return d;
	}
	
	private static void dfsBC(int cur, BCDatum d)
	{
		d.visited[cur] = true;
		d.low[cur] = d.ord[cur] = d.gen++;
		int dfsch = 0;
		for(int[] e : d.g[cur]){
			if(!d.visited[e[0]]){
				d.edgeStack[d.esp++] = e[1];
				d.parente[e[0]] = e[1];
				dfsch++;
				dfsBC(e[0], d);
				if(d.low[e[0]] >= d.ord[cur]){
					d.isArtic[cur] = true;
					while(d.esp > 0){
						d.edgeClus[d.edgeStack[--d.esp]] = d.ecp;
						if(d.edgeStack[d.esp] == e[1])break;
					}
					d.ecp++;
				}
				d.low[cur] = Math.min(d.low[cur], d.low[e[0]]);
			}else if(d.parente[cur] != e[1] && d.ord[e[0]] < d.ord[cur]){
				// e is a back edge from cur to its ancestor e[0]
				d.edgeStack[d.esp++] = e[1];
				d.low[cur] = Math.min(d.low[cur], d.ord[e[0]]);
			}
		}
		if(d.parente[cur] < 0 && dfsch == 1)d.isArtic[cur] = false; // if root node and degree on dfs tree = 1 then not articulation point.
	}
	
	public static class BCDatum
	{
		public int[][][] g;
		public int[] edgeClus;
		public int ecp;
		public int gen;
		public int[] ord;
		public int[] low;
		public int[] edgeStack;
		public int esp;
		public boolean[] visited;
		public int[] parente;
		public boolean[] isArtic;
	}
	
	public static class DJSet {
		public int[] upper;

		public DJSet(int n) {
			upper = new int[n];
			Arrays.fill(upper, -1);
		}

		public int root(int x) {
			return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
		}

		public boolean equiv(int x, int y) {
			return root(x) == root(y);
		}

		public boolean union(int x, int y) {
			x = root(x);
			y = root(y);
			if (x != y) {
				if (upper[y] < upper[x]) {
					int d = x;
					x = y;
					y = d;
				}
				upper[x] += upper[y];
				upper[y] = x;
			}
			return x == y;
		}

		public int count() {
			int ct = 0;
			for (int u : upper)
				if (u < 0)
					ct++;
			return ct;
		}
	}

	
	public static int[][][] packWU(int n, int[] from, int[] to, int[] w) {
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for (int f : from)
			p[f]++;
		for (int t : to)
			p[t]++;
		for (int i = 0; i < n; i++)
			g[i] = new int[p[i]][2];
		for (int i = 0; i < from.length; i++) {
			--p[from[i]];
			g[from[i]][p[from[i]]][0] = to[i];
			g[from[i]][p[from[i]]][1] = w[i];
			--p[to[i]];
			g[to[i]][p[to[i]]][0] = from[i];
			g[to[i]][p[to[i]]][1] = w[i];
		}
		return g;
	}


	public static void main(String[] args) throws Exception {
		long S = System.currentTimeMillis();
		is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);

		solve();
		out.flush();
		long G = System.currentTimeMillis();
		tr(G - S + "ms");
	}

	private static boolean eof() {
		if (lenbuf == -1)
			return true;
		int lptr = ptrbuf;
		while (lptr < lenbuf)
			if (!isSpaceChar(inbuf[lptr++]))
				return false;

		try {
			is.mark(1000);
			while (true) {
				int b = is.read();
				if (b == -1) {
					is.reset();
					return true;
				} else if (!isSpaceChar(b)) {
					is.reset();
					return false;
				}
			}
		} catch (IOException e) {
			return true;
		}
	}

	private static byte[] inbuf = new byte[1024];
	static int lenbuf = 0, ptrbuf = 0;

	private static int readByte() {
		if (lenbuf == -1)
			throw new InputMismatchException();
		if (ptrbuf >= lenbuf) {
			ptrbuf = 0;
			try {
				lenbuf = is.read(inbuf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (lenbuf <= 0)
				return -1;
		}
		return inbuf[ptrbuf++];
	}

	private static boolean isSpaceChar(int c) {
		return !(c >= 33 && c <= 126);
	}

	private static int skip() {
		int b;
		while ((b = readByte()) != -1 && isSpaceChar(b))
			;
		return b;
	}

	private static double nd() {
		return Double.parseDouble(ns());
	}

	private static char nc() {
		return (char) skip();
	}

	private static String ns() {
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while (!(isSpaceChar(b))) { // when nextLine, (isSpaceChar(b) && b != '
									// ')
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	private static char[] ns(int n) {
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while (p < n && !(isSpaceChar(b))) {
			buf[p++] = (char) b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}

	private static char[][] nm(int n, int m) {
		char[][] map = new char[n][];
		for (int i = 0; i < n; i++)
			map[i] = ns(m);
		return map;
	}

	private static int[] na(int n) {
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = ni();
		return a;
	}

	private static int ni() {
		int num = 0, b;
		boolean minus = false;
		while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
			;
		if (b == '-') {
			minus = true;
			b = readByte();
		}

		while (true) {
			if (b >= '0' && b <= '9') {
				num = num * 10 + (b - '0');
			} else {
				return minus ? -num : num;
			}
			b = readByte();
		}
	}

	private static long nl() {
		long num = 0;
		int b;
		boolean minus = false;
		while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
			;
		if (b == '-') {
			minus = true;
			b = readByte();
		}

		while (true) {
			if (b >= '0' && b <= '9') {
				num = num * 10 + (b - '0');
			} else {
				return minus ? -num : num;
			}
			b = readByte();
		}
	}

	private static void tr(Object... o) {
		if (INPUT.length() != 0)
			System.out.println(Arrays.deepToString(o));
	}
}