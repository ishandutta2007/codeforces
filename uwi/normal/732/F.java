//package round377;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	int[] from;
	
	void solve()
	{
		int n = ni(), m = ni();
		from = new int[m];
		int[] to = new int[m];
		int[] w =  new int[m];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
			w[i] = i;
		}
		int[][][] g = packWU(n, from, to, w);
		int[][] ng = packU(n, from, to);
		int[] clus = decomposeToBECC(g);
		int[][] cg = condense(ng, clus);
		int[] fc = new int[cg.length];
		for(int i = 0;i < n;i++){
			fc[clus[i]]++;
		}
		int u = cg.length;
		int arg = 0;
		for(int i = 0;i < u;i++){
			if(fc[i] > fc[arg])arg = i;
		}
		out.println(fc[arg]);
		int[][] pars = parents3(cg, arg);
		int[] par = pars[0];
		int[][] buc = makeBuckets(clus, u);
		
		dir = new int[m];
		boolean[] ved = new boolean[n];
		boolean[] aed = new boolean[n];
		for(int i = 0;i < u;i++){
			dfs(buc[i][0], -1, clus, g, ved, aed);
		}
		for(int i = 0;i < m;i++){
			if(clus[from[i]] != clus[to[i]]){
				if(par[clus[from[i]]] == clus[to[i]]){
					dir[i] = 1;
				}else{
					dir[i] = -1;
				}
			}
		}
		for(int i = 0;i < m;i++){
			if(dir[i] >= 0){
				out.println((from[i]+1) + " " + (to[i]+1));
			}else{
				out.println((to[i]+1) + " " + (from[i]+1));
			}
		}
	}
	
	public static int[][] makeBuckets(int[] a, int sup)
	{
		int n = a.length;
		int[][] bucket = new int[sup+1][];
		int[] bp = new int[sup+1];
		for(int i = 0;i < n;i++)bp[a[i]]++;
		for(int i = 0;i <= sup;i++)bucket[i] = new int[bp[i]];
		for(int i = n-1;i >= 0;i--)bucket[a[i]][--bp[a[i]]] = i;
		return bucket;
	}

	
	int[] dir;
	
	void dfs(int cur, int pre, int[] clus, int[][][] g, boolean[] ved, boolean[] aed)
	{
		ved[cur] = true;
		for(int[] e : g[cur]){
			if(clus[e[0]] == clus[cur] && e[0] != pre){
				if(aed[e[0]]){
				}else{
					dir[e[1]] = from[e[1]] == e[0] ? 1 : -1;
					if(!ved[e[0]]){
						dfs(e[0], cur, clus, g, ved, aed);
					}
				}
			}
		}
		aed[cur] = true;
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
	
	public static int[][] condense(int[][] g, int[] clus)
	{
		int n = g.length;
		int m = 0;
		for(int i = 0;i < n;i++)m = Math.max(m, clus[i]);
		m++;
		
		int[] cp = new int[m];
		for(int i = 0;i < n;i++){
			cp[clus[i]] += g[i].length;
		}
		int[][] c = new int[m][];
		for(int i = 0;i < m;i++){
			c[i] = new int[cp[i]];
		}
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < g[i].length;j++){
				c[clus[i]][--cp[clus[i]]] = clus[g[i][j]];
			}
		}
		
		for(int i = 0;i < m;i++){
			Arrays.sort(c[i]);
			int jp = 0;
			for(int j = 0;j < c[i].length;j++){
				if((j == 0 || c[i][j] != c[i][j-1]) && c[i][j] != i){
					c[i][jp++] = c[i][j];
				}
			}
			c[i] = Arrays.copyOf(c[i], jp);
		}
		return c;
	}
	
	public static int[] decomposeToBECC(int[][][] g)
	{
		int n = g.length;
		boolean[] visited = new boolean[n];
		int[] ord = new int[n];
		int[] low = new int[n];
		
		int[] ids = new int[n];
		int[] inds = new int[n];
		int[] parct = new int[n];
		int pos = 0;
		for(int i = 0;i < n;i++){
			if(!visited[i]){
				ids[0] = i;
				inds[0] = 0;
				int sp = 1;
				while(sp > 0){
					int cur = ids[sp-1];
					if(inds[sp-1] == 0){
						visited[cur] = true;
						ord[cur] = low[cur] = pos++;
						parct[sp-1] = 0;
					}
					if(inds[sp-1] == g[cur].length){
						if(sp-2 >= 0)low[ids[sp-2]] = Math.min(low[ids[sp-2]], low[cur]);
						sp--;
						continue;
					}
					int next = g[cur][inds[sp-1]][0];
					if(!visited[next]){
						ids[sp] = next;
						inds[sp] = 0;
						inds[sp-1]++;
						sp++;
						continue;
					}else if(sp-2 >= 0 && (next != ids[sp-2] || ++parct[sp-1] >= 2)){
						low[cur] = Math.min(low[cur], ord[next]);
					}
					inds[sp-1]++;
				}
			}
		}
		
		int[] clus = new int[n];
		Arrays.fill(clus, -1);
		int[] q = new int[n];
		int cnum = 0;
		for(int i = 0;i < n;i++){
			if(clus[i] == -1){
				int p = 0;
				q[p++] = i;
				clus[i] = cnum++;
				for(int r = 0;r < p;r++){
					int cur = q[r];
					for(int[] next : g[cur]){
						if(clus[next[0]] == -1){
							clus[next[0]] = ord[cur] < low[next[0]] ? cnum++ : clus[cur];
							q[p++] = next[0];
						}
					}
				}
			}
		}
		return clus;
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