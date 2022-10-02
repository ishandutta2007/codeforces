//package round121;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] from = new int[n-1];
		int[] to = new int[n-1];
		int[] w = new int[n-1];
		for(int i = 0;i < n-1;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
			w[i] = i;
		}
		int[][][] g = packWU(n, from, to, w);
		int[][] pars = parent(g, 0);
		int[] par = pars[0];
		int[] ord = pars[1];
		int[] dep = pars[2];
		int[] iord = new int[n];
		for(int i = 0;i < n;i++)iord[ord[i]] = i;
		int[][] sp = sparseParents(par, iord);
		
		int K = ni();
		int[] sc = new int[n];
		for(int i = 0;i < K;i++){
			int f = ni()-1, t = ni() - 1;
			int lca = lca(f, t, sp, dep);
			
			sc[f]++;
			sc[t]++;
			sc[lca] -= 2;
		}
		
		int[] ret = new int[n-1];
		for(int i = n-1;i >= 0;i--){
			int cur = ord[i];
			int pl = -1;
			for(int[] e : g[cur]){
				if(par[cur] != e[0]){
					sc[cur] += sc[e[0]];
				}else{
					pl = e[1];
				}
			}
			if(pl != -1)ret[pl] = sc[cur];
		}
		for(int i = 0;i < n-1;i++){
			if(i > 0)out.print(" ");
			out.print(ret[i]);
		}
		out.println();
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
	
	public static int[][] sparseParents(int[] par, int[] iord)
	{
		int n = par.length;
		int m = Integer.numberOfTrailingZeros(Integer.highestOneBit(n-1))+1;
		int[][] pars = new int[m][n];
		pars[0] = par;
		for(int j = 1;j < m;j++){
			for(int i = n-1;i >= 0;i--){
				pars[j][iord[i]] = pars[j-1][iord[i]] == -1 ? -1 : pars[j-1][pars[j-1][iord[i]]];
			}
		}
		return pars;
	}
	
	public static int[][] parent(int[][][] g, int root)
	{
		int n = g.length;
		int[] par = new int[n];
		Arrays.fill(par, -1);
		
		int[] q = new int[n];
		q[0] = root;
		int[] dep = new int[n];
		dep[root] = 0;
		for(int p = 0, r = 1;p < r;p++) {
			int cur = q[p];
			for(int[] nex : g[cur]){
				if(par[cur] != nex[0]){
					q[r++] = nex[0];
					dep[nex[0]] = dep[cur] + 1;
					par[nex[0]] = cur;
				}
			}
		}
		return new int[][]{par, q, dep};
	}
	
	public static int[][][] packWU(int n, int[] from, int[] to, int[] w)
	{
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for(int f : from)p[f]++;
		for(int t : to)p[t]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]][2];
		for(int i = 0;i < from.length;i++){
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
	
	public static void main(String[] args) throws Exception
	{
		new C().run();
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