//package educational.round45;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class G4 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		int[] from = new int[n - 1];
		int[] to = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			from[i] = ni() - 1;
			to[i] = ni() - 1;
		}
		int[][] g = packU(n, from, to);
		int[][] pars = parents3(g, 0);
		int[] par = pars[0], ord = pars[1];
		
		int M = 200005;
		long[] anss = new long[M];
		
		long[][] dp = new long[n][];
		long[] temp = new long[n+1];
		for(int i = n-1;i >= 0;i--){
			int cur = ord[i];
			if(g[cur].length == 2 && i > 0){
				int p = 0;
				temp[p++] = (long)a[cur]<<32|1;
				for(int e : g[cur]){
					if(par[cur] != e){
						for(int j = 0;j < dp[e].length;j++){
							long y = dp[e][j];
							temp[p++] = (long)gcd((int)(y>>>32), a[cur])<<32|(int)y;
						}
						dp[e] = null;
					}
				}
				
				for(int j = 1;j < p;j++){
					anss[gcd((int)(temp[0]>>>32), (int)(temp[j]>>>32))] += (long)((int)temp[0])*((int)temp[j])*2;
				}
				p = merge(temp, p);
				dp[cur] = Arrays.copyOf(temp, p);
				anss[a[cur]]+=2;
			}else{
				int p = 0;
				temp[p++] = (long)a[cur]<<32|1;
				for(int e : g[cur]){
					if(par[cur] != e){
						for(int j = 0;j < dp[e].length;j++){
							long y = dp[e][j];
							temp[p++] = dp[e][j] = (long)gcd((int)(y>>>32), a[cur])<<32|(int)y;
						}
						count(dp[e], anss, -1);
						dp[e] = null;
					}
				}
				p = merge(temp, p);
				dp[cur] = Arrays.copyOf(temp, p);
				count(dp[cur], anss, 1);
				anss[a[cur]]++;
			}
		}
		
		for(int i = 1;i <= 200000;i++){
			if(anss[i] > 0){
				assert anss[i] % 2 == 0;
				out.println(i + " " + anss[i]/2);
			}
		}
	}
	
	public static void tul(long... o)
	{
		int n = o.length;
		int[] vals = new int[n]; 
		for(int i = 0;i < n;i++)vals[i] = (int)(o[i]>>>32); System.out.println("U:" + Arrays.toString(vals));
		for(int i = 0;i < n;i++)vals[i] = (int)o[i]; System.out.println("L:" + Arrays.toString(vals));
	}
	
	static void count(long[] ds, long[] anss, int mul)
	{
		for(int i = 0;i < ds.length;i++){
			for(int j = i+1;j < ds.length;j++){
				anss[gcd((int)(ds[i]>>>32), (int)(ds[j]>>>32))] += (long)((int)ds[i])*((int)ds[j])*mul*2;
			}
			anss[(int)(ds[i]>>>32)] += (long)((int)ds[i])*((int)ds[i])*mul;
		}
//		for(long d : ds){
//			for(long e : ds){
//				anss[gcd((int)(d>>>32), (int)(e>>>32))] += ((long)((int)d))*((int)e)*mul;
//			}
//		}
	}
	
	static int[][] gt = gcdtable(1000);
	
	public static int gcd(int a, int b) {
		if(a == 0)return b;
		if(b == 0)return a;
		
		int ashift = Integer.numberOfTrailingZeros(a);
		int bshift = Integer.numberOfTrailingZeros(b);
		a >>>= ashift;
		b >>>= bshift;
		while(b != a){
			if(a > b){
				int t = a; a = b; b = t;
			}
			if(b < gt.length)return gt[(int)a][(int)b]<<Math.min(ashift, bshift);
			b -= a;
			b >>>= Integer.numberOfTrailingZeros(b);
		}
		
		return a<<Math.min(ashift, bshift);
	}
	
	public static int[][] gcdtable(int n)
	{
		int[][] gcd = new int[n+1][n+1];
		for(int i = 1;i <= n;i++){
			gcd[i][i] = i;
			for(int j = i+1;j <= n;j++){
				gcd[j][i] = gcd[i][j] = gcd[i][j-i];
			}
		}
		return gcd;
	}

	
	static int merge(long[] t, int p)
	{
		Arrays.sort(t, 0, p);
		int q = 0;
		for(int i = 0;i < p;i++){
			if(i > 0 && t[i]>>>32 == t[q-1]>>>32){
				t[q-1] += (int)t[i];
			}else{
				t[q++] = t[i];
			}
		}
		return q;
	}
	
	public static int[][] parents3(int[][] g, int root) {
		int n = g.length;
		int[] par = new int[n];
		Arrays.fill(par, -1);

		int[] q = new int[n];
		q[0] = root;
		for (int p = 0, r = 1; p < r; p++) {
			int cur = q[p];
			for (int nex : g[cur]) {
				if (par[cur] != nex) {
					q[r++] = nex;
					par[nex] = cur;
				}
			}
		}
		return new int[][] { par, q};
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

	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new G4().run(); }
	
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