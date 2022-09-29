//package ecr89;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), Q = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		int[] ws = new int[m];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
			ws[i] = ni();
		}
		int[][][] g = packWU(n, from, to, ws);
		
		int mod = 1000000007;
		long[] w = new long[n];
		Arrays.fill(w, Long.MIN_VALUE);
		w[0] = 0;
		long asum = 0;
		for(int i = 0;i < 4000 && i < Q;i++){
			long[] nw = new long[n];
			Arrays.fill(nw, Long.MIN_VALUE);
			for(int j = 0;j < n;j++){
				for(int[] e : g[j]){
					nw[e[0]] = Math.max(nw[e[0]], w[j] + e[1]);
				}
			}
			long lmax = 0;
			for(int j = 0;j < n;j++){
				lmax = Math.max(lmax, nw[j]);
			}
			asum += lmax;
			asum %= mod;
			w = nw;
		}
		if(Q <= 4000){
			out.println(asum);
		}else{
			long[][] ss = new long[n][];
			int p = 0;
			for(int i = 0;i < n;i++){
				if(w[i] < 0)continue;
				int lmax = 0;
				for(int[] e : g[i]){
					lmax = Math.max(lmax, e[1]);
				}
				ss[p++] = new long[]{lmax, w[i]};
			}
			ss = Arrays.copyOf(ss, p);
			Arrays.sort(ss, new Comparator<long[]>() {
				public int compare(long[] a, long[] b) {
					return Long.compare(a[0], b[0]);
				}
			});
			EnvelopeLinear el = new EnvelopeLinear(n);
			for(long[] s : ss){
				el.add(-s[0], -s[1]);
			}
			long ans = asum;
			for(int i = 0;i < el.p;i++){
				long l = Math.max(el.xs[i], 1);
				long r = Math.min(i+1 < el.p ? el.xs[i+1] : Long.MAX_VALUE, Q-4000+1);
				if(l <= r){
					ans += -el.slopes[i] * ((r*(r-1)/2 - l*(l-1)/2)%mod);
					ans %= mod;
					ans += -el.intercepts[i] * (r-l);
					ans %= mod;
				}
			}
			if(ans < 0)ans += mod;
			out.println(ans);
		}
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
				long anew = intercepts[i]+xs[i]*slopes[i];
				long old = intercept+xs[i]*slope;
				double danew = intercepts[i]+(double)xs[i]*slopes[i];
				double dold = intercept+(double)xs[i]*slope;
				
				if(p > 1 && (danew - dold > 1e18 || anew - old >= 0)){ // x=xs[i]
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

	
	public static int[][][] packWU(int n, int[] from, int[] to, int[] w) {
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for (int f : from)
			p[f]++;
		for (int t : to)
			p[t]++;
		for (int i = 0; i < n; i++)
			g[i] = new int[p[i]][2];
		for (int i = 0; i < from.length; i++) {
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
	
	public static void main(String[] args) throws Exception { new F().run(); }
	
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