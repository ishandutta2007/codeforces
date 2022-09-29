//package round434;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] f = new int[2*n];
		for(int i = 0;i < 2*n;i++)f[i] = -1;
		for(int i = 0;i < n;i++){
			f[ni()-1] = ni()-1;
		}
		DJSet ds = new DJSet(2*n);
		boolean[] hasCycle = new boolean[2*n];
		boolean[] c1 = new boolean[2*n];
		for(int i = 0;i < 2*n;i++){
			if(f[i] != -1){
				if(ds.union(i, f[i])){
					hasCycle[i] = true;
					if(i == f[i])c1[i] = true;
				}
			}
		}
		for(int i = 0;i < 2*n;i++){
			if(hasCycle[i]){
				hasCycle[ds.root(i)] = true;
			}
			if(c1[i]){
				c1[ds.root(i)] = true;
			}
		}
		int mod = 1000000007;
		long ans = 1;
		for(int i = 0;i < 2*n;i++){
			if(ds.upper[i] < 0){
				if(ds.upper[i] == -1)hasCycle[i] = true;
				if(hasCycle[i]){
					// cycle
					if(-ds.upper[i] >= 2 && !c1[i]){
						ans = ans * 2 % mod;
					}
				}else{
					// tree
					
				}
			}
		}
		int[] map = new int[2*n];
		Arrays.fill(map, -1);
		int id = 0;
		for(int i = 0;i < 2*n;i++){
			if(!hasCycle[ds.root(i)]){
				map[i] = id++;
			}
		}
		int[] par = new int[id+1];
		par[id] = -1;
		for(int i = 0;i < 2*n;i++){
			if(map[i] == -1)continue;
			par[map[i]] = f[i] == -1 ? id : map[f[i]];
		}
		int[][] g = parentToG(par);
		
		int[][] pars = parents3(g, id);
		int[] ord = pars[1];
		long[][] dp = new long[2][id+1];
		for(int i = id;i >= 0;i--){
			int cur = ord[i];
			if(i == 0){
				for(int j = 0;j < g[cur].length;j++){
					int e = g[cur][j];
					if(par[cur] == e){
					}else{
						ans = ans * dp[0][e] % mod;
					}
				}
				break;
			}
			long[] left = new long[g[cur].length+1];
			long[] right = new long[g[cur].length+1];
			left[0] = 1;
			for(int j = 0;j < g[cur].length;j++){
				int e = g[cur][j];
				if(par[cur] == e){
					left[j+1] = left[j];
				}else{
					left[j+1] = left[j] * dp[1][e] % mod;
				}
			}
			right[g[cur].length] = 1;
			for(int j = g[cur].length-1;j >= 0;j--){
				int e = g[cur][j];
				if(par[cur] == e){
					right[j] = right[j+1];
				}else{
					right[j] = right[j+1] * dp[1][e] % mod;
				}
			}
			
			for(int j = 0;j < g[cur].length;j++){
				int e = g[cur][j];
				if(par[cur] != e){
					dp[0][cur] += left[j] * right[j+1] % mod * dp[0][e];
					dp[0][cur] %= mod;
				}
			}
			dp[0][cur] += left[g[cur].length];
			if(dp[0][cur] >= mod)dp[0][cur] -= mod;
			dp[1][cur] = left[g[cur].length];
		}
		out.println(ans);
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