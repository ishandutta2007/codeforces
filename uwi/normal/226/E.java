//package round140;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;

public class E3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] par = new int[n];
		
		for(int i = 0;i < n;i++)par[i] = ni()-1;
		int[][] ch = parentToChildren(par);
		int root = -1;
		for(int i = 0;i < n;i++){
			if(par[i] == -1)root = i;
		}
		
		int Q = ni();
		int[] at = new int[n]; // at[]=
		Arrays.fill(at, -1);
		int[] iat = new int[Q]; // iat[]=
		Arrays.fill(iat, -1);
		
		int[][] q = new int[Q][];
		int p = 0;
		for(int i = 0;i < Q;i++){
			int type = ni();
			if(type == 1){
				int to = ni()-1;
				at[to] = i;
				iat[i] = to;
			}else{
				// aby+1k
				int a = ni()-1, b = ni()-1, k = ni(), y = ni();
				q[p] = new int[]{y, i, a, b, k, p};
				p++;
			}
		}
		q = Arrays.copyOf(q, p);
		
		final int S = (int)Math.sqrt(n);
		Arrays.sort(q, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[0]/S != b[0]/S){
					return a[0]-b[0];
				}else{
					return a[1]-b[1];
				}
			}
		});
		
		int[] ord = new int[n];
		sortByPreorder(ch, root, ord, 0, -1);
		int[][] rights = makeRights(ch, par, ord);
		int[] right = rights[1], iord = rights[0];
		int[][] sp = sparseParents(par);
		int[] dep = new int[n];
		for(int i = 0;i < n;i++){
			for(int e : ch[ord[i]]){
				dep[e] = dep[ord[i]] + 1;
			}
		}
		int[] ft = new int[n+1+1];
		for(int i = 0;i < n;i++){
			addFenwick(ft, iord[i], 1);
			addFenwick(ft, right[i]+1, -1);
		}
		
		int l = 0, r = -1;
		boolean[] stand = new boolean[n];
		Arrays.fill(stand, true);
		int[] ret = new int[p];
		for(int i = 0;i < p;i++){
			while(r < q[i][1]){
				r++;
				if(iat[r] != -1){
					addFenwick(ft, iord[iat[r]], -1);
					addFenwick(ft, right[iat[r]]+1, 1);
					stand[iat[r]] = false;
				}
			}
			while(l > q[i][0]){
				l--;
				if(iat[l] != -1){
					addFenwick(ft, iord[iat[l]], -1);
					addFenwick(ft, right[iat[l]]+1, 1);
					stand[iat[l]] = false;
				}
			}
			while(r > q[i][1]){
				if(iat[r] != -1){
					addFenwick(ft, iord[iat[r]], 1);
					addFenwick(ft, right[iat[r]]+1, -1);
					stand[iat[r]] = true;
				}
				r--;
			}
			while(l < q[i][0]){
				if(iat[l] != -1){
					addFenwick(ft, iord[iat[l]], 1);
					addFenwick(ft, right[iat[l]]+1, -1);
					stand[iat[l]] = true;
				}
				l++;
			}
//			tr("phase", i, q[i]);
//			tr("stand", stand);
//			tr("fen", restoreFenwick(ft));
//			tr("ord", ord);
			
			int a = q[i][2], b = q[i][3], K = q[i][4];
			int lca = lca(a, b, sp, dep);
			int half = (par[a] == -1 ? 0 : sumFenwick(ft, iord[par[a]]))
					- (par[lca] == -1 ? 0 : sumFenwick(ft, iord[par[lca]]));
			ret[q[i][5]] = -1;
//			tr("half", half);
			if(K == half && lca != a && lca != b && stand[lca]){
				ret[q[i][5]] = lca+1;
			}else if(K <= half){
				int low = 0, high = dep[a]-dep[lca];
				while(high - low > 1){
					int x = (high+low)/2;
					int mid = ancestor(a, x, sp);
					half = (par[a] == -1 ? 0 : sumFenwick(ft, iord[par[a]]))
							- (par[mid] == -1 ? 0 : sumFenwick(ft, iord[par[mid]]));
					if(K == half && mid != a && mid != lca && stand[mid]){
						ret[q[i][5]] = mid+1;
						break;
					}else if(K <= half){
						high = x;
					}else{
						low = x;
					}
				}
			}else{
				K -= half;
				int low = 0, high = dep[b]-dep[lca];
				while(high - low > 1){
					int x = (high+low)/2;
					int mid = ancestor(b, x, sp);
					half = sumFenwick(ft, iord[mid]) - sumFenwick(ft, iord[lca]);
//					tr(x, mid, half, b, lca);
					if(K == half && mid != b && mid != lca && stand[mid]){
						ret[q[i][5]] = mid+1;
						break;
					}else if(K <= half){
						low = x;
					}else{
						high = x;
					}
				}
			}
		}
		
		for(int i = 0;i < p;i++){
			out.println(ret[i]);
		}
	}
	
	public static int sumFenwick(int[] ft, int i)
	{
		int sum = 0;
		for(i++;i > 0;i -= i&-i)sum += ft[i];
		return sum;
	}
	
	public static void addFenwick(int[] ft, int i, int v)
	{
		if(v == 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i)ft[i] += v;
	}
	
	public static int valFenwick(int[] ft, int i)
	{
		return sumFenwick(ft, i) - sumFenwick(ft, i-1);
	}
	
	public static int[] restoreFenwick(int[] ft)
	{
		int n = ft.length-1;
		int[] ret = new int[n];
		for(int i = 0;i < n;i++)ret[i] = sumFenwick(ft, i);
		for(int i = n-1;i >= 1;i--)ret[i] -= ret[i-1];
		return ret;
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
	
	public static int[][] makeRights(int[][] g, int[] par, int[] ord)
	{
		int n = g.length;
		int[] iord = new int[n];
		for(int i = 0;i < n;i++)iord[ord[i]] = i;
		
		int[] right = new int[n];
		for(int i = n-1;i >= 0;i--){
			int v = i;
			for(int e : g[ord[i]]){
				if(e != par[ord[i]]){
					v = Math.max(v, right[e]);
				}
			}
			right[ord[i]] = v;
		}
		return new int[][]{iord, right};
	}
	
	public static int sortByPreorder(int[][] g, int cur, int[] ord, int pos, int prev)
	{
		ord[pos++] = cur;
		for(int e : g[cur])if(prev != e)pos = sortByPreorder(g, e, ord, pos, cur);
		return pos;
	}
	
	public static int[][] parentToChildren(int[] parent)
	{
		int n = parent.length;
		int[] ct = new int[n];
		for(int i = 0;i < n;i++){
			if(parent[i] >= 0){
				ct[parent[i]]++;
			}
		}
		int[][] ret = new int[n][];
		for(int i = 0;i < n;i++){
			ret[i] = new int[ct[i]];
		}
		for(int i = 0;i < n;i++){
			if(parent[i] >= 0){
				ret[parent[i]][--ct[parent[i]]] = i;
			}
		}
		
		return ret;
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
		new E3().run();
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