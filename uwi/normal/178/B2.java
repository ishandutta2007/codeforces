//package abbyy2.hard;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class BM {
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
		// 
		int[] ord = new int[n]; // preorder
		int[] stack = new int[n];
		int[] par = new int[n]; // parent
		int[] depth = new int[n];
		boolean[] ved = new boolean[n];
		int r = 0;
		for(int i = 0;i < n;i++){
			if(!ved[i]){
				stack[0] = i;
				par[i] = -1;
				ved[i] = true;
				int p = 1; // stack pointer
				while(p > 0){
					int cur = stack[p-1];
					ord[r++] = cur;
					p--;
					for(int e : g[cur]){
						if(!ved[e]){
							stack[p++] = e;
							depth[e] = depth[cur]+1;
							par[e] = cur;
							ved[e] = true;
						}
					}
				}
			}
		}
		
		int[] iord = new int[n];
		for(int i = 0;i < n;i++)iord[ord[i]] = i;
		
		int[] ND = new int[n];
		int[] L = new int[n];
		int[] H = new int[n];
		boolean[] br = new boolean[n];
		for(int i = n-1;i >= 0;i--){
			int cur = ord[i];
			if(par[cur] == -1)continue;
			int ll = i;
			int lh = i;
			int pe = -1;
			ND[cur]++;
			for(int e : g[cur]){
				// 
				if(par[cur] == e && pe == -1){
					pe = 1;
					continue;
				}
				
				if(par[e] == cur){
					// L,H
					ll = Math.min(ll, L[e]);
					lh = Math.max(lh, H[e]);
				}else{
					// 
					ll = Math.min(ll, iord[e]);
					lh = Math.max(lh, iord[e]);
				}
			}
			L[cur] = ll;
			H[cur] = lh;
			if(L[cur] == i && H[cur] < i+ND[cur]){
				// 
				br[cur] = true;
			}
			ND[par[cur]] += ND[cur];
		}
		
		int[] nbr = new int[n];
		for(int i = 0;i < n;i++){
			if(br[ord[i]])nbr[ord[i]]++;
			for(int e : g[ord[i]]){
				if(par[e] == ord[i]){
					nbr[e] += nbr[ord[i]];
				}
			}
		}
		
		int[][] sp = sparseParents(par, iord);
		
		int K = ni();
		for(int i = 0;i < K;i++){
			int f = ni()-1, t = ni()-1;
			int l = lca(f, t, sp, depth);
			out.println(nbr[f] + nbr[t] - nbr[l]*2);
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
	 * @param iord
	 * @return
	 */
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
	
	public static int[][] packU(int n, int[] from, int[] to)
	{
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int f : from)p[f]++;
		for(int t : to)p[t]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]];
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
		new BM().run();
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