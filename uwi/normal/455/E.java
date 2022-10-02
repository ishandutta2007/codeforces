//package round260;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		int[] am = new int[n];
		for(int i = 0;i < n;i++){
			am[i] = a[i] * i;
		}
		int[] cum = new int[n+1];
		for(int i = n-1;i >= 0;i--){
			cum[i] = cum[i+1] + a[i];
		}
		for(int i = 0;i < n;i++){
			am[i] += cum[i+1];
		}
		
		// 3a+b+c
		//   4b+c
		//     5c
		int[][] co = new int[n][];
		for(int i = 0;i < n;i++){
			co[i] = new int[]{a[i], am[i]};
		}
		
		SegmentTreeRMQ st = new SegmentTreeRMQ(co);
		int Q = ni();
		
		for(int z = 0;z < Q;z++){
			int r = ni(), c = ni();
			long min = st.min(c-r, c, r-c+1);
			out.println(min-cum[c]);
		}
	}
	
	public static class SegmentTreeRMQ {
		public int M, H, N;
		public long[][] xs;
		public long[][] ys;
		public long[][] slopes;
		public int[] ls;
		public int[] rs;
		
		public int[][] co;
		
		public SegmentTreeRMQ(int[][] co)
		{
			this.co = co;
			N = co.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			ls = new int[M];
			rs = new int[M];
			xs = new long[M][];
			ys = new long[M][];
			slopes = new long[M][];
			for(int i = 0;i < N;i++){
				long[][] xys = make(co, i, i+1);
				xs[H+i] = xys[0];
				ys[H+i] = xys[1];
				slopes[H+i] = xys[2];
				ls[H+i] = i;
				rs[H+i] = i+1;
			}
			for(int i = N;i < H;i++){
				ls[H+i] = rs[H+i] = N;
			}
			
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		private void propagate(int i)
		{
			ls[i] = ls[2*i];
			rs[i] = rs[2*i+1];
			
			Arrays.sort(co, ls[i], rs[i], new Comparator<int[]>() {
				public int compare(int[] a, int[] b) {
					return -(a[0] - b[0]);
				}
			});
			long[][] xys = make(co, ls[i], rs[i]);
			xs[i] = xys[0];
			ys[i] = xys[1];
			slopes[i] = xys[2];
		}
		
		int INF = -1000000;
		
		long[][] make(int[][] co, int L, int R)
		{
			int n = R-L;
			int p = 0;
			long[] xs = new long[n];
			long[] ys = new long[n];
			long[] slopes = new long[n];
			for(int i = L;i < R;i++){
				p = add(p, xs, ys, slopes, co[i][0], co[i][1]);
			}
			return new long[][]{Arrays.copyOf(xs, p), Arrays.copyOf(ys, p), Arrays.copyOf(slopes, p)};
		}
		
		int add(int p, long[] xs, long[] ys, long[] slopes, int slope, int y)
		{
			for(int i = p-1;i >= 0;i--){
				if(y+xs[i]*slope <= ys[i]+xs[i]*slopes[i]){ // x=xs[i]
					p--;
					continue;
				}
				if(slope == slopes[i]){
					if(y >= ys[i]){
						return p;
					}else{
						continue;
					}
				}
				// slope*t+y=ys+slopes*t
				// (slopes-slope)*t=y-ys
				// t=(y-ys)/(slopes-slope)
				long num = y-ys[i];
				long den = slopes[i]-slope;
				long nx = num < 0 ? num/den : (num+den-1)/den;
				xs[p] = nx;
				ys[p] = y;
				slopes[p] = slope;
				p++;
				return p;
			}
			
			xs[p] = INF;
			ys[p] = y;
			slopes[p] = slope;
			p++;
			return p;
		}
		
		long query(long x, long[] xs, long[] ys, long[] slopes)
		{
			int ind = Arrays.binarySearch(xs, x);
			if(ind < 0)ind = -ind-2;
			return slopes[ind]*x + ys[ind];
		}
		
		public long min(int l, int r, long x){ return l >= r ? 0 : min(l, r, x, 0, H, 1);}
		
		private long min(int l, int r, long x, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return query(x, xs[cur], ys[cur], slopes[cur]);
			}else{
				int mid = cl+cr>>>1;
				long ret = Long.MAX_VALUE;
				if(cl < r && l < mid){
					ret = Math.min(ret, min(l, r, x, cl, mid, 2*cur));
				}
				if(mid < r && l < cr){
					ret = Math.min(ret, min(l, r, x, mid, cr, 2*cur+1));
				}
				return ret;
			}
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
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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