//package round111;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] e = new int[m][4];
		for(int i = 0;i < m;i++){
			e[i][0] = ni()-1;
			e[i][1] = ni()-1;
			e[i][2] = ni();
			e[i][3] = i;
		}
		Arrays.sort(e, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[2] - b[2];
			}
		});
		
//		tr(e);
		DJSet ds = new DJSet(n);
		int[] ret = new int[m];
		int prev = 0;
		for(int i = 0;i < m;i++){
			if(i == m-1 || e[i][2] != e[i+1][2]){
				int[] lft = new int[(i-prev+1)*2];
				int[] w = new int[i-prev+1];
				int fp = 0;
				for(int j = prev;j <= i;j++){
					if(!ds.equiv(e[j][0], e[j][1])){
						w[fp/2] = e[j][3];
						ret[e[j][3]] = 1;
						lft[fp++] = ds.root(e[j][0]);
						lft[fp++] = ds.root(e[j][1]);
					}
				}
//				tr("lft", lft);
				lft = shrink(Arrays.copyOf(lft, fp));
				int max = 0;
				for(int lf : lft)max = Math.max(max, lf);
				max++;
				fp /= 2;
				w = Arrays.copyOf(w, fp);
				int[] from = new int[fp];
				int[] to = new int[fp];
				for(int j = 0;j < 2*fp;j+=2){
					from[j/2] = lft[j];
					to[j/2] = lft[j+1];
				}
				if(from.length > 0){
//					tr("from", from);
//					tr("to", to);
//					tr("w", w);
					
					int[][][] mg = packWU(max, from, to, w);
					int[] bs = enumBridges(mg);
//					tr(bs);
					for(int b : bs){
						ret[b] = 2;
					}
				}
				for(int j = prev;j <= i;j++){
					ds.union(e[j][0], e[j][1]);
				}
				prev = i+1;
			}
		}
		
		for(int i = 0;i < m;i++){
			if(ret[i] == 0){
				out.println("none");
			}else if(ret[i] == 1){
				out.println("at least one");
			}else if(ret[i] == 2){
				out.println("any");
			}
		}
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
	
	public static int[] shrink(int[] a)
	{
		int n = a.length;
		long[] b = new long[n];
		for(int i = 0;i < n;i++)b[i] = (long)a[i]<<32|i;
		Arrays.sort(b);
		int[] ret = new int[n];
		int p = 0;
		for(int i = 0;i < n;i++) {
			if(i>0 && (b[i]^b[i-1])>>32!=0)p++;
			ret[(int)b[i]] = p;
		}
		return ret;
	}
	
	public int[] enumBridges(int[][][] g)
	{
		int n = g.length;
		
		// 
		int[] ord = new int[n]; // preorder
		int[] stack = new int[n];
		int[] par = new int[n]; // parent
		boolean[] ved = new boolean[n];
		int r = 0;
		for(int i = 0;i < n;i++){
			if(!ved[i]){
				stack[0] = i;
				par[i] = -1;
				ved[i] = true;
				int p = 1; // stack pointer;
				while(p > 0){
					int cur = stack[p-1];
					ord[r++] = cur;
					p--;
					for(int[] e : g[cur]){
						if(!ved[e[0]]){
							stack[p++] = e[0];
							par[e[0]] = cur;
							ved[e[0]] = true;
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
		int[] bs = new int[n];
		int q = 0;
		for(int i = n-1;i >= 0;i--){
			int cur = ord[i];
			if(par[cur] == -1)continue;
			int ll = i;
			int lh = i;
			int pe = -1;
			ND[cur]++;
			for(int[] e : g[cur]){
				// 
				if(par[cur] == e[0] && pe == -1){
					pe = e[1];
					continue;
				}
				
				if(par[e[0]] == cur){
					// L,H
					ll = Math.min(ll, L[e[0]]);
					lh = Math.max(lh, H[e[0]]);
				}else{
					// 
					ll = Math.min(ll, iord[e[0]]);
					lh = Math.max(lh, iord[e[0]]);
				}
			}
			L[cur] = ll;
			H[cur] = lh;
			if(L[cur] == i && H[cur] < i+ND[cur]){
				// 
				bs[q++] = pe;
			}
			ND[par[cur]] += ND[cur];
		}
		return Arrays.copyOf(bs, q);
	}
	
	public static class DJSet { public int[] upper; public DJSet(int n){ upper = new int[n]; Arrays.fill(upper, -1);} public int root(int x){	return upper[x] < 0 ? x : (upper[x] = root(upper[x]));}	public boolean equiv(int x, int y){ return root(x) == root(y);} public void union(int x, int y){ x = root(x);y = root(y);if(x != y) { if(upper[y] < upper[x]) { int d = x; x = y; y = d;	} upper[x] += upper[y]; upper[y] = x;}} public int count(){	int ct = 0;	for(int i = 0;i < upper.length;i++){ if(upper[i] < 0)ct++; } return ct; }}
	
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
		new D().run();
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