//package round143;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
		}
		int[][] g = packU(n, from, to);
		int[][] loops = findLoops(g, 0);
		int[] map = new int[n];
		int[] mul = new int[n];
		Arrays.fill(map, -1);
		Arrays.fill(mul, 1);
		int p = 0;
		for(int[] l : loops){
			for(int x : l){
				map[x] = p;
			}
			mul[p] = 2;
			p++;
		}
		for(int i = 0;i < n;i++){
			if(map[i] == -1){
				map[i] = p++;
			}
		}
		
		int[][] gg = collect(g, map);
		int z = gg.length;
		int[][] pars = parents(gg, 0);
		int[] par = pars[0], ord = pars[1];
		int[] dp = new int[z];
		int[] depth = new int[z];
		for(int i = 0;i < z;i++){
			int cur = ord[i];
			dp[cur] += mul[cur]-1;
			for(int e : gg[cur]){
				if(par[cur] != e){
					dp[e] = dp[cur];
					depth[e] = depth[cur] + 1;
				}
			}
		}
		int[][] sp = sparseParents(par);
		
		int Q = ni();
		for(int i = 0;i < Q;i++){
			int f = map[ni()-1], t = map[ni()-1];
			int lca = lca(f, t, sp, depth);
			out.println(modpow(2, dp[f]+dp[t]-dp[lca]*2+(mul[lca]-1), 1000000007));
		}
	}
	
	public static int lca(int a, int b, int[][] spar, int[] depth)
	{
		if(depth[a] < depth[b]){
			b = ancestor(b, depth[b]-depth[a], spar);
		}else if(depth[a] > depth[b]){
			a = ancestor(a, depth[a]-depth[b], spar);
		}
		
		int low = -1;
		int high = depth[a];
		while(high - low > 1){
			int x = (low + high) / 2;
			if(ancestor(a, x, spar) == ancestor(b, x, spar)){
				high = x;
			}else{
				low = x;
			}
		}
		return ancestor(a, high, spar);
	}
	
	protected static int ancestor(int a, int m, int[][] spar)
	{
		for(int i = 0;m > 0 && a != -1;m>>>=1,i++){
			if(m%2==1)a = spar[i][a];
		}
		return a;
	}
	
	/**
	 * 2^k
	 * @param par
	 * @return
	 */
	public static int[][] sparseParents(int[] par)
	{
		int n = par.length;
		int m = Integer.numberOfTrailingZeros(Integer.highestOneBit(n-1))+1;
		int[][] pars = new int[m][n];
		pars[0] = par;
		for(int j = 1;j < m;j++){
			for(int i = 0;i < n;i++){
				pars[j][i] = pars[j-1][i] == -1 ? -1 : pars[j-1][pars[j-1][i]];
			}
		}
		return pars;
	}
	
	public static long modpow(long a, long n, long mod)
	{
		long ret = 1;
		long mul = a;
		for(;n > 0;n >>>= 1){
			if((n&1)==1){
				ret = (ret * mul) % mod;
			}
			mul = (mul * mul) % mod;
		}
		return ret;
	}
	
	public static int[][] parents(int[][] g, int root)
	{
		int n = g.length;
		int[] par = new int[n];
		Arrays.fill(par, -1);
		
		int[] q = new int[n];
		q[0] = root;
		for(int p = 0, r = 1;p < r;p++) {
			int cur = q[p];
			for(int nex : g[cur]){
				if(par[cur] != nex){
					q[r++] = nex;
					par[nex] = cur;
				}
			}
		}
		return new int[][] {par, q};
	}
	
	static int[][] collect(int[][] g, int[] scc)
	{
		int n = g.length;
		int m = 0;
		for(int i = 0;i < n;i++)m = Math.max(m, scc[i]);
		m++;
		
		int[] cp = new int[m];
		for(int i = 0;i < n;i++){
			cp[scc[i]] += g[i].length;
		}
		int[][] c = new int[m][];
		for(int i = 0;i < m;i++){
			c[i] = new int[cp[i]];
		}
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < g[i].length;j++){
				c[scc[i]][--cp[scc[i]]] = scc[g[i][j]];
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
	
	public static int[][] findLoops(int[][] g, int s)
	{
		int[][] loops = new int[g.length / 3][];
		int lp = 0;
		
		int n = g.length;
		int[] visited = new int[n];
		int[] stack = new int[n];
		int[] istack = new int[n];
		int[] ei = new int[n];
		stack[0] = s;
		int p = 1;
		while(p >= 1){
			int cur = stack[p-1];
			visited[cur] = 1;
			if(ei[cur] < g[cur].length){
				int nex = g[cur][ei[cur]];
				if(visited[nex] == 1 && (p-2 < 0 || nex != stack[p-2])){
					// loop
					loops[lp++] = Arrays.copyOfRange(stack, istack[nex], p);
				}else if(visited[nex] == 0){
					// visit
					istack[nex] = p;
					stack[p++] = nex;
				}
				ei[cur]++;
			}else{
				visited[cur] = 2;
				p--;
			}
		}
		return Arrays.copyOf(loops, lp);
	}
	
	static int[][] packU(int n, int[] from, int[] to) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int f : from)
			p[f]++;
		for(int t : to)
			p[t]++;
		for(int i = 0;i < n;i++)
			g[i] = new int[p[i]];
		for(int i = 0;i < from.length;i++){
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
	
	public static void main(String[] args) throws Exception
	{
		new E().run();
	}
	
	public int ni()
	{
		try {
			int num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public long nl()
	{
		try {
			long num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public String ns()
	{
		try{
			int b = 0;
			StringBuilder sb = new StringBuilder();
			while((b = is.read()) != -1 && (b == '\r' || b == '\n' || b == ' '));
			if(b == -1)return "";
			sb.append((char)b);
			while(true){
				b = is.read();
				if(b == -1)return sb.toString();
				if(b == '\r' || b == '\n' || b == ' ')return sb.toString();
				sb.append((char)b);
			}
		} catch (IOException e) {
		}
		return "";
	}
	
	public char[] ns(int n)
	{
		char[] buf = new char[n];
		try{
			int b = 0, p = 0;
			while((b = is.read()) != -1 && (b == ' ' || b == '\r' || b == '\n'));
			if(b == -1)return null;
			buf[p++] = (char)b;
			while(p < n){
				b = is.read();
				if(b == -1 || b == ' ' || b == '\r' || b == '\n')break;
				buf[p++] = (char)b;
			}
			return Arrays.copyOf(buf, p);
		} catch (IOException e) {
		}
		return null;
	}
	
	
	double nd() { return Double.parseDouble(ns()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}