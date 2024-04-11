//package round462;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.List;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		int[] b = na(n);
		int[] from = new int[n - 1];
		int[] to = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			from[i] = ni() - 1;
			to[i] = ni() - 1;
		}
		int[][] g = packU(n, from, to);
		int[][] pars = parents3(g, 0);
		int[] par = pars[0], ord = pars[1], dep = pars[2];
		
		DoubledEnvelopeLinear[] dels = new DoubledEnvelopeLinear[n];
		long[] anss = new long[n];
		for(int i = n-1;i >= 0;i--){
			int cur = ord[i];
			long min = Long.MAX_VALUE;
			for(int e : g[cur]){
				if(par[cur] == e)continue;
				min = Math.min(min, dels[e].min(a[cur]));
			}
			anss[cur] = min == Long.MAX_VALUE ? 0 : min;
			
			DoubledEnvelopeLinear del = new DoubledEnvelopeLinear(2*n+5);
			del.add(b[cur], anss[cur]);
			for(int e : g[cur]){
				if(par[cur] == e)continue;
				del = merge(del, dels[e]);
			}
			dels[cur] = del;
		}
		for(int i = 0;i < n;i++){
			out.print(anss[i] + " ");
		}
	}
	
	DoubledEnvelopeLinear merge(DoubledEnvelopeLinear a, DoubledEnvelopeLinear b)
	{
		if(a.phase < b.phase){
			DoubledEnvelopeLinear d = a; a = b; b = d;
		}
		// a <- b
		for(EnvelopeLinear el : b.els){
			if(el == null)continue;
			for(int i = 0;i < el.p;i++){
				a.add(el.slopes[i], el.intercepts[i]);
			}
		}
		return a;
	}
	
	public static class DoubledEnvelopeLinear {
		public EnvelopeLinear[] els;
		public List<List<long[]>> buf;
		public int phase;
		public int H;
		
		public DoubledEnvelopeLinear(int n) {
			H = 32-Integer.numberOfLeadingZeros(n);
			els = new EnvelopeLinear[H];
			buf = new ArrayList<>();
			for(int i = 0;i < H;i++)buf.add(new ArrayList<>());
			phase = 0;
		}
		
		public void add(long slope, long intercept)
		{
			long[] info = new long[]{slope, intercept};
			for(int p = ~phase&(1<<H)-1;p != 0;p &= p-1){
				int d = Integer.numberOfTrailingZeros(p);
				buf.get(d).add(info);//[phase&(1<<d)-1] = info;
				if(phase+1<<~d<0)compile(d);
			}
			phase++;
		}
		
//		public int argmin(int x)
//		{
//			long min = Long.MAX_VALUE;
//			int argmin = Integer.MAX_VALUE;
//			for(int p = phase;p != 0;p &= p-1){
//				int d = Integer.numberOfTrailingZeros(p);
//				long val = els[d].min(x);
//				if(val < min){
//					min = val;
//					argmin = els[d].argmin(x);
//				}
//			}
//			return argmin;
//		}
		
		public long min(long x)
		{
			long ret = Long.MAX_VALUE;
			for(int p = phase;p != 0;p &= p-1){
				int d = Integer.numberOfTrailingZeros(p);
				if(els[d] == null)continue;
				ret = Math.min(ret, els[d].min(x));
			}
			return ret;
		}
		
		private void compile(int dep)
		{
			Collections.sort(buf.get(dep), new Comparator<long[]>() {
				public int compare(long[] a, long[] b) {
					return -Long.signum(a[0] - b[0]);
				}
			});

			EnvelopeLinear el = new EnvelopeLinear(1<<dep);
			for(long[] info : buf.get(dep))el.add(info[0], info[1]);
			buf.get(dep).clear();
			els[dep] = el;
		}
	}
	
	
	
//	public static class EnvelopeLinear {
//		public static final long INF = Long.MIN_VALUE;
//		
//		public List<Long> xs;
//		public List<Long> intercepts, slopes;
//		
//		public EnvelopeLinear()
//		{
//			xs = new ArrayList<>();
//			intercepts = new ArrayList<>();
//			slopes = new ArrayList<>();
//		}
//		
//		static EnvelopeLinear merge(EnvelopeLinear a, EnvelopeLinear b)
//		{
//			
//		}
//		
//		public void clear()
//		{
//			xs.clear();
//			intercepts.clear();
//			slopes.clear();
//		}
//		
//		public void add(long slope, long intercept)
//		{
//			assert xs.size() == 0 || slopes.get(slopes.size()-1) >= slope;
//			while(xs.size() > 0){
//				int i = xs.size()-1;
//				if(i > 0 && intercept+xs.get(i)*slope <= intercepts.get(i)+xs.get(i)*slopes.get(i)){ // x=xs[i]
//					xs.remove(i);
//					continue;
//				}
//				if(slope == slopes.get(i)){
//					if(intercept >= intercepts.get(i)){
//						return;
//					}else{
//						xs.remove(i);
//						continue;
//					}
//				}
//				// y=sx+i vs y=Sx+I
//				// sx+i=Sx+I
//				// x=(i-I)/(S-s)
//				long num = intercept-intercepts.get(i);
//				long den = slopes.get(i)-slope;
//				long nx = num < 0 ? num/den : (num+den-1)/den;
//				xs.add(nx);
//				intercepts.add(intercept);
//				slopes.add(slope);
//				return;
//			}
//			xs.add(INF);
//			intercepts.add(intercept);
//			slopes.add(slope);
//		}
//		
////		public int argmin(int x)
////		{
////			if(p <= 0)return -1;
////			int ind = Arrays.binarySearch(xs, 0, p, x);
////			if(ind < 0)ind = -ind-2;
////			return ind;
////		}
//		
//		public long min(long x)
//		{
//			if(xs.size() <= 0)return Long.MIN_VALUE;
//			int ind = Collections.binarySearch(xs, x);
//			if(ind < 0)ind = -ind-2;
//			return slopes.get(ind)*x + intercepts.get(ind);
//		}
//	}
	
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
				if(p > 1){
					boolean jud = false;
					if(
							Math.abs(intercepts[i]+xs[i]*slopes[i]) < 8000000000000000000L &&
							
							Math.abs(intercept+xs[i]*slope) <=  8000000000000000000L ){
						jud = 					intercept+xs[i]*slope <= intercepts[i]+xs[i]*slopes[i];
					}else{
						jud = 					intercept+(double)xs[i]*slope <= intercepts[i]+(double)xs[i]*slopes[i];
						
					}
					if(jud){
						p--;
						continue;
					}
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