//package educational.round11;
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
	
	long max;
	int[] a;
	
	void solve()
	{
		int n = ni();
		a = na(n);
		max = 0;
		go(0, n);
		out.println(max);
	}
	
	void go(int l, int r)
	{
		if(r-l == 1){
			max = Math.max(max, a[l]);
			return;
		}
		if(r-l < 1)return;
		
		int h = l+r>>>1;
		long[][] sip = new long[r-h+1][];
		long[][] sim = new long[r-h+1][];
		int pp = 0, pm = 0;
		long s = 0;
		long s1 = 0;
		for(int i = h;i <= r;i++){
			if(s >= 0){
				sip[pp++] = new long[]{s, s1};
			}else{
				sim[pm++] = new long[]{s, s1};
			}
			if(i < r){
				s += a[i];
				s1 += (long)a[i] * (i-h+1);
			}
		}
		
		Arrays.sort(sip, 0, pp, new Comparator<long[]>() {
			public int compare(long[] a, long[] b) {
				return -Long.compare(a[0], b[0]);
			}
		});
		Arrays.sort(sim, 0, pm, new Comparator<long[]>() {
			public int compare(long[] a, long[] b) {
				return Long.compare(a[0], b[0]);
			}
		});
		
		EnvelopeLinear elp = new EnvelopeLinear(pp);
		EnvelopeLinear elm = new EnvelopeLinear(pm);
		for(int i = 0;i < pp;i++){
			elp.add(sip[i][0], -sip[i][1]);
		}
		for(int i = 0;i < pm;i++){
			elm.add(-sim[i][0], -sim[i][1]);
		}
		
		long[] cum = new long[h-l+1];
		for(int i = 0;i < h-l;i++){
			cum[i+1] = cum[i] + a[i+l];
		}
		
		long c = 0;
		for(int i = h-1, j = 1;i >= l;i--,j++){
			c += cum[h-l]-cum[h-l-j];
			long maxp = elp.query(-j);
			long maxm = elm.query(j);
			long v = c-Math.min(maxp, maxm);
			max = Math.max(max, v);
		}
		
		go(l, h);
		go(h, r);
	}
	
	public static class EnvelopeLinear {
		public static final long INF = -300000;
		
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
		
		public void add(long slope, long intercept)
		{
			for(int i = p-1;i >= 0;i--){
				if(intercept+xs[i]*slope <= intercepts[i]+xs[i]*slopes[i]){ // x=xs[i]
					p--;
					continue;
				}
				if(slope == slopes[i]){
					if(intercept >= intercepts[i]){
						return;
					}else{
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
		
		public long query(long x)
		{
			if(p <= 0)return Long.MAX_VALUE / 5;
			int ind = Arrays.binarySearch(xs, 0, p, x);
			if(ind < 0)ind = -ind-2;
			return slopes[ind]*x + intercepts[ind];
		}
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
	private int lenbuf = 0, ptrbuf = 0;
	
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