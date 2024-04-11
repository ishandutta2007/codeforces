//package round123;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	static int mod = 1000000007;
	
	void solve()
	{
		int n = ni();
		DJSet ds = new DJSet(n);
		int[][][] pl = new int[n][][];
		int[] many = new int[n];
		for(int i = 0;i < n;i++)many[i] = i;
		int s = 0;
		for(int i = 0;i < n;i++){
			int m = ni();
			pl[i] = new int[m][];
			s += m;
			for(int j = 0;j < m;j++){
				int v = ni()-1;
				int x = ni();
				pl[i][j] = new int[]{v, x, many[ds.root(v)]};
				ds.union(i, v);
				many[ds.root(i)] = i;
			}
		}
		
		int[] from = new int[s];
		int[] to = new int[s];
		int[] w = new int[s];
		int p = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < pl[i].length;j++){
				from[p] = pl[i][j][2];
				to[p] = i;
				w[p] = pl[i][j][1];
				p++;
			}
		}
		
		int[][][] g = packWU(n, from, to, w);
		par = new int[g.length];
		Arrays.fill(par, -1);
		int[] iord = new int[n];
		int[] right = new int[n];
		
		long ret = 0;
		for(int i = 0;i < n;i++){
			if(ds.upper[i] < 0){
				parents(g, many[i], -ds.upper[i]);
//				int[] ord = pars[1];
				int[] ord = sortByPreorder(g, many[i], -ds.upper[i]);
				int m = ord.length;
				for(int j = 0;j < m;j++)iord[ord[j]] = j;
				for(int j = ord.length-1;j >= 0;j--){
					int rr = j;
					for(int[] e : g[ord[j]]){
						if(par[ord[j]] != e[0]){
							rr = Math.max(rr, right[e[0]]);
						}
					}
					right[ord[j]] = rr;
				}
				
				long[] ft0 = new long[m+1];
				long[] ft1 = new long[m+1];
				for(int j = ord.length-1;j >= 0;j--){
					int cur = ord[j];
//					Arrays.sort(pl[cur], new Comparator<int[]>() {
//						public int compare(int[] a, int[] b) {
//							return a[2] - b[2];
//						}
//					});
//					Arrays.sort(g[cur], new Comparator<int[]>() {
//						public int compare(int[] a, int[] b) {
//							return a[0] - b[0];
//						}
//					});
					for(int k = 0;k < pl[cur].length;k++){
						int io = iord[pl[cur][k][0]];
						int plus = (int)((sumRangeFenwick(ft0, ft1, io) - sumRangeFenwick(ft0, ft1, io-1) + mod) % mod);
						pl[cur][k][1] = (int)((pl[cur][k][1] + plus) % mod);
//						tr(cur,pl[cur][k][1],pl[cur][k][2], iord[pl[cur][k][2]]);
						ret += pl[cur][k][1];
						addRangeFenwick(ft0, ft1, iord[pl[cur][k][2]], right[pl[cur][k][2]], pl[cur][k][1]);
					}
//					tr(restoreFenwick(ft0, ft1));
				}
			}
		}
		out.println((ret%mod+mod)%mod);
	}
	
	public static int[] sortByPreorder(int[][][] g, int root, int n){
		int[] stack = new int[n];
		int[] ord = new int[n];
		BitSet ved = new BitSet();
		stack[0] = root;
		int p = 1;
		int r = 0;
		ved.set(root);
		while(p > 0){
			int cur = stack[p-1];
			ord[r++] = cur;
			p--;
			for(int[] e : g[cur]){
				if(!ved.get(e[0])){
					stack[p++] = e[0];
					ved.set(e[0]);
				}
			}
		}
		return ord;
	}
	
	int[] par;
	
	public int[][] parents(int[][][] g, int root, int sz) {
		int n = sz;

		int[] q = new int[n];
		q[0] = root;
		for(int p = 0, r = 1;p < r;p++){
			int cur = q[p];
			for(int[] nex : g[cur]){
				if(par[cur] != nex[0]){
					q[r++] = nex[0];
					par[nex[0]] = cur;
				}
			}
		}
		return new int[][] { par, q };
	}
	
	public static int[][][] packWU(int n, int[] from, int[] to, int[] w) {
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for(int f : from)
			p[f]++;
		for(int t : to)
			p[t]++;
		for(int i = 0;i < n;i++)
			g[i] = new int[p[i]][2];
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
	
	public static long sumFenwick(long[] ft, int i)
	{
		long sum = 0;
		for(i++;i > 0;i -= i&-i)sum += ft[i];
		return sum%mod;
	}
	
	public static void addFenwick(long[] ft, int i, long v)
	{
		v %= mod;
		if(v == 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i){
			ft[i] = (ft[i] + v) % mod;
		}
	}
	
	public static int findGFenwick(long[] ft, int v)
	{
		int i = 0;
		int n = ft.length;
		for(int b = Integer.highestOneBit(n);b != 0 && i < n;b >>= 1){
			if(i + b < n){
				int t = i + b;
				if(v >= ft[t]){
					i = t;
					v -= ft[t];
				}
			}
		}
		return v != 0 ? -(i+1) : i-1;
	}
	
	public static long[] restoreFenwick(long[] ft0, long[] ft1)
	{
		int n = ft0.length-1;
		long[] ret = new long[n];
		for(int i = 0;i < n;i++)ret[i] = sumRangeFenwick(ft0, ft1, i);
		for(int i = n-1;i >= 1;i--)ret[i] -= ret[i-1];
		return ret;
	}
	
	public static void addRangeFenwick(long[] ft0, long[] ft1, int i, long v)
	{
		addFenwick(ft1, i+1, -v);
		addFenwick(ft1, 0, v);
		addFenwick(ft0, i+1, v*(i+1));
	}
	
	public static void addRangeFenwick(long[] ft0, long[] ft1, int a, int b, long v)
	{
		if(a <= b){
			addFenwick(ft1, b+1, -v);
			addFenwick(ft0, b+1, v*(b+1));
			addFenwick(ft1, a, v);
			addFenwick(ft0, a, -v*a);
		}
	}
	
	public static long sumRangeFenwick(long[] ft0, long[] ft1, int i)
	{
		return ((long)sumFenwick(ft1, i) * (i+1) + sumFenwick(ft0, i)) % mod;
	}
	
	public static class DJSet { public int[] upper; public DJSet(int n){ upper = new int[n]; Arrays.fill(upper, -1);} public int root(int x){	return upper[x] < 0 ? x : (upper[x] = root(upper[x]));}	public boolean equiv(int x, int y){ return root(x) == root(y);} public void union(int x, int y){ x = root(x);y = root(y);if(x != y) { if(upper[y] < upper[x]) { int d = x; x = y; y = d;	} upper[x] += upper[y]; upper[y] = x;}} public int count(){	int ct = 0;	for(int i = 0;i < upper.length;i++){ if(upper[i] < 0)ct++; } return ct; }}
	
	void run() throws Exception
	{
//		int n = 100000;
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		Random gen = new Random(100);
//		for(int i = 0;i < n;i++){
//			if(i == 0){// || gen.nextDouble() < 0.01){
//				sb.append(0 + " ");
//			}else{
//				sb.append(1 + " " + 1 + " " + 1 + " ");
////				sb.append(1 + " " + (gen.nextInt(i)+1) + " " + gen.nextInt(1000000000) + " ");
//			}
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
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