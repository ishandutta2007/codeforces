//package round400;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.Random;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] from = new int[m+n];
		int[] to = new int[m+n];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
		}
		for(int i = 0;i < n;i++){
			from[m+i] = i;
			to[m+i] = (i+1)%n;
		}
		int[][] g = packU(n, from, to);
		Random gen = new Random();
		for(int[] row : g){
			row = shuffle(row, gen);
			Arrays.sort(row);
		}
		int[][] re = new int[n][];
		for(int i = 0;i < n;i++){
			re[i] = new int[g[i].length];
			Arrays.fill(re[i], -1);
		}
		long[][] hs = new long[m+1][];
		int id = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < g[i].length;j++){
				if(g[i][j] == (i+n-1)%n)continue; // ccw
				if(re[i][j] == -1){
					re[i][j] = id;
					int pre = i;
					int cur = g[i][j];
					RankingSimple rank = new RankingSimple(3);
					rank.query(-pre);
					rank.query(-cur);
					while(true){
						int preind = Arrays.binarySearch(g[cur], pre);
						preind--;
						if(preind < 0)preind = g[cur].length-1;
						int nex = g[cur][preind];
						assert re[cur][preind] == -1;
						re[cur][preind] = id;
						pre = cur;
						cur = nex;
						rank.query(-cur);
						if(cur == i)break;
					}
					hs[id] = Arrays.copyOf(rank.min, 4);
					hs[id][3] = id;
					assert rank.min[2] != Long.MAX_VALUE;
					id++;
				}
			}
		}
		assert id == m+1;
		
		int[] xfrom = new int[m];
		int[] xto = new int[m];
		int px = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < g[i].length;j++){
				if(i < g[i][j] && re[i][j] != -1){
					int k =g[i][j];
					int iind = Arrays.binarySearch(g[k], i);
					if(re[k][iind] == -1)continue;
					xfrom[px] = re[i][j];
					xto[px] = re[k][iind];
					px++;
				}
			}
		}
		assert px == m;
		
		int[][] xg = packU(m+1, xfrom, xto);
		int[] cpar = buildCentroidTree(xg);
		int root = -1;
		for(int i = 0;i < cpar.length;i++)if(cpar[i] == -1)root = i;
		int[][] xcg = parentToG(cpar);
		int[][] xpars = parents3(xcg, root);
		int[] dep = xpars[2];
		
		Arrays.sort(hs, new Comparator<long[]>() {
			public int compare(long[] a, long[] b) {
				for(int i = 0;i < a.length;i++){
					if(a[i] != b[i])return -Long.compare(a[i], b[i]);
				}
				return 0;
			}
		});
		for(int i = 0;i < m+1;i++){
			out.print(dep[(int)hs[i][3]] + 1 + " ");
		}
		out.println();
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

	
	public static int[] buildCentroidTree(int[][] g) {
		int n = g.length;
		int[] ctpar = new int[n];
		Arrays.fill(ctpar, -1);
		buildCentroidTree(g, 0, new boolean[n], new int[n], new int[n], new int[n], ctpar);
		return ctpar;
	}
	
	private static int buildCentroidTree(int[][] g, int root, boolean[] sed, int[] par, int[] ord, int[] des, int[] ctpar)
	{
		// parent and level-order
		ord[0] = root;
		par[root] = -1;
		int r = 1;
		for(int p = 0;p < r;p++) {
			int cur = ord[p];
			for(int nex : g[cur]){
				if(par[cur] != nex && !sed[nex]){
					ord[r++] = nex;
					par[nex] = cur;
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
			for(int e : g[cur]){
				if(par[cur] != e && !sed[e])des[cur] += des[e];
			}
			if(r-des[cur] <= r/2){
				for(int e : g[cur]){
					if(par[cur] != e && !sed[e] && des[e] >= r/2+1)continue outer;
				}
				sep = cur;
				break;
			}
		}
		
		sed[sep] = true;
		for(int e : g[sep]){
			if(!sed[e])ctpar[buildCentroidTree(g, e, sed, par, ord, des, ctpar)] = sep;
		}
		return sep;
	}

	
	public static class RankingSimple {
		public long[] min;
		public int K;
		
		public RankingSimple(int K)
		{
			this.K = K;
			min = new long[K];
			Arrays.fill(min, Long.MAX_VALUE);
		}
		
		public void query(long v)
		{
			if(v >= min[K-1])return;
			for(int i = 0;i < K;i++){
				if(v < min[i]){
					for(int j = K-2;j >= i;j--){
						min[j+1] = min[j];
					}
					min[i] = v;
					break;
				}
			}
		}
	}

	
	public static int[] shuffle(int[] a, Random gen){ for(int i = 0, n = a.length;i < n;i++){ int ind = gen.nextInt(n-i)+i; int d = a[i]; a[i] = a[ind]; a[ind] = d; } return a; }

	
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