//package round130;
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
		int n = ni();
		int[] par = new int[n];
		for(int i = 0;i < n;i++)par[i] = ni()-1;
		
		int[][] ch = parentToChildren(par);
		
		int[] ord = new int[n];
		int[] dep = new int[n];
		int p = 0;
		for(int i = 0;i < n;i++){
			if(par[i] == -1){
				ord[p++] = i;
			}
		}
		
		int prev = 0;
		int[] st = new int[n+1];
		for(int r = 0;r < n;r++){
			if(dep[ord[r]] > prev){
				st[dep[ord[r]]] = r;
				prev = dep[ord[r]];
			}
			for(int c : ch[ord[r]]){
				ord[p++] = c;
				dep[c] = dep[ord[r]] + 1;
			}
		}
		st[++prev] = n;
//		tr(st);
//		tr(dep);
		
		int[] iord = new int[n];
		for(int i = 0;i < n;i++){
			iord[ord[i]] = i;
		}
		int[][] sp = sparseParents(par, iord);
		
		int Q = ni();
		for(int l = 0;l < Q;l++){
			if(l > 0)out.print(" ");
			int v = ni()-1, q = ni();
			int a = ancestor(v, q, sp);
			if(a == -1){
				out.print(0);
			}else{
				int L = 0, R = 0;
				{
					int low = st[dep[v]]-1;
					int high = iord[v];
					while(high - low > 1){
						int x = (high + low) / 2;
						int lca = ancestor(ord[x], q, sp);
//						int lca = lca(iord[x], v, sp, dep);
						if(lca != a){
							low = x;
						}else{
							high = x;
						}
					}
					L = high;
				}
				{
					int low = iord[v];
					int high = st[dep[v]+1];
//					tr(low, high);
					while(high - low > 1){
						int x = (high + low) / 2;
//						int lca = lca(iord[x], v, sp, dep);
						int lca = ancestor(ord[x], q, sp);
//						if(lca == -1 || dep[lca] < dep[v]-q){
						if(lca != a){
							high = x;
						}else{
							low = x;
						}
					}
					R = high;
				}
//				tr(L, R);
				out.print(R-L-1);
			}
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