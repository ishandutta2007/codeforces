//package round569;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		// x-y
		// x-y
		// p1(p2+p3)+p2p3
		//x,y
		// 
		// 2-1
		// (n-a)(n-b)-(n-a-b)^2 + 1path + 1path
		// -a^2-ab+an-b^2+bn
		// -ab
		// 
		// 1DP
		
		int n = ni();
		int[] from = new int[n - 1];
		int[] to = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			from[i] = ni() - 1;
			to[i] = ni() - 1;
		}
		int[][] g = packU(n, from, to);
		if(n == 2){
			out.println(2);
			return;
		}
		
		int root = -1;
		for(int i = 0;i < n;i++){
			if(g[i].length >= 2)root = i;
		}
		
		int[][] pars = parents3(g, root);
		int[] par = pars[0], ord = pars[1], dep = pars[2];
		
		int[] des = new int[n];
		Arrays.fill(des, 1);
		for(int i = n-1;i >= 1;i--){
			des[par[ord[i]]] += des[ord[i]];
		}
		
		long ans = 0;
		long[] dp = new long[n];
		for(int i = n-1;i >= 0;i--){
			int cur = ord[i];
			
			dp[cur] = 0;//des[cur];
			// 1path
			for(int e : g[cur]){
				if(par[cur] == e)continue;
				dp[cur] = Math.max(dp[cur], dp[e] + (long)(des[cur] - des[e]) * des[e]);
			}
			
			// 2path
			// (a+b)(n-a-b)+ab + 1path + 1path
			// -a^2-ab+an-b^2+bn
			
			// 3*3-2^2 = 5
			// 1 2 1
			// 
			
			long[][] si = new long[g[cur].length][];
			int p = 0;
			for(int e : g[cur]){
				if(par[cur] == e)continue;
				si[p++] = new long[]{des[e], dp[e] + (long)des[e]*(n-des[e])};
			}
			si = Arrays.copyOf(si, p);
			Arrays.sort(si, new Comparator<long[]>() {
				public int compare(long[] a, long[] b) {
					return Long.compare(a[0], b[0]);
				}
			});
			EnvelopeLinear eld = new EnvelopeLinear(p);
			for(int j = 0;j < p;j++){
				if(j > 0){
					long val = -eld.min(-si[j][0]) + si[j][1];
					ans = Math.max(ans, val);
				}
				eld.add(-si[j][0], -si[j][1]);
			}
		}
		out.println(ans + (long)n*(n-1)/2);
	}
	
	public static class EnvelopeLinear {
		public static final long INF = Long.MIN_VALUE;
		
		public long[] xs;
		public long[] intercepts, slopes;
		public int p;
		
		public EnvelopeLinear(int n)
		{
			xs = new long[n];
			intercepts = new long[n];
			slopes = new long[n];
			p = 0;
		}
		
		public void clear()
		{
			p = 0;
		}
		
		public void add(long slope, long intercept)
		{
			assert p == 0 || slopes[p-1] >= slope;
			while(p > 0){
				int i = p-1;
				if(p > 1 && intercept+xs[i]*slope <= intercepts[i]+xs[i]*slopes[i]){ // x=xs[i]
					p--;
					continue;
				}
				if(slope == slopes[i]){
					if(intercept >= intercepts[i]){
						return;
					}else{
						p--;
						continue;
					}
				}
				// y=sx+i vs y=Sx+I
				// sx+i=Sx+I
				// x=(i-I)/(S-s)
				long num = intercept-intercepts[i];
				long den = slopes[i]-slope;
				long nx = num < 0 ? num/den : (num+den-1)/den;
				xs[p] = nx;
				intercepts[p] = intercept;
				slopes[p] = slope;
				p++;
				return;
			}
			
			xs[p] = INF;
			intercepts[p] = intercept;
			slopes[p] = slope;
			p++;
		}
		
		public int argmin(int x)
		{
			if(p <= 0)return -1;
			int ind = Arrays.binarySearch(xs, 0, p, x);
			if(ind < 0)ind = -ind-2;
			return ind;
		}
		
		public long min(long x)
		{
			if(p <= 0)return Long.MIN_VALUE;
			int ind = Arrays.binarySearch(xs, 0, p, x);
			if(ind < 0)ind = -ind-2;
			return slopes[ind]*x + intercepts[ind];
		}
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

	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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