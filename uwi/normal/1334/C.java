//package educational.round85;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		for(int T = ni();T > 0;T--)go();
	}
	
	void go()
	{
		int n = ni();
		long[][] ab = new long[n][];
		for(int i = 0;i < n;i++){
			ab[i] = new long[]{nl(), nl()};
		}
		
		SegmentTree4TupleMaxSum st = new SegmentTree4TupleMaxSum(ab);
		long ans = Long.MAX_VALUE;
		for(int i = 0;i < n;i++){
			ans = Math.min(ans, st.smax(i, i+n));
		}
		out.println(ans);
	}
	
	public class SegmentTree4TupleMaxSum {
		public int M, H, N;
		public long[] cost;
		public long[] lb, rb;
		public long[] la, ra;
		public long[][] ab;
		public long I = Long.MIN_VALUE/2 + 30000;
		public int T = 30;
		
		public SegmentTree4TupleMaxSum(long[][] ab)
		{
			this.ab = ab;
			N = ab.length*2;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			cost = new long[M+T];
			lb = new long[M+T];
			la = new long[M+T];
			ra = new long[M+T];
			rb = new long[M+T];
			for(int i = 0;i < H;i++){
				cost[H+i] = i < N ? ab[i%(N/2)][0] : 0;
				rb[H+i] = lb[H+i] = i < N ? ab[i%(N/2)][1] : 0;
				ra[H+i] = la[H+i] = i < N ? ab[i%(N/2)][0] : 0;
			}
			for(int i = H-1;i >= 1;i--){
				propagate(i);
			}
		}
		
		private void propagate(int i)
		{
			propNC(i, 2*i, 2*i+1);
		}
		
		private void propNC(int p, int l, int r)
		{
			cost[p] = cost[l] + cost[r] - Math.min(la[r], rb[l]);
			la[p] = la[l];
			ra[p] = ra[r];
			lb[p] = lb[l];
			rb[p] = rb[r];
		}
		
		int ggen;
		
		public long smax(int l, int r){ 
			ggen = M;
			int last = smax(l, r, 0, H, 1);
			return last == -1 ? I : cost[last];
		}
		
		private int smax(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return cur;
			}else{
				int mid = cl+cr>>>1;
				int L = -1, R = -1;
				if(cl < r && l < mid){
					L = smax(l, r, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					R = smax(l, r, mid, cr, 2*cur+1);
				}
				if(L == -1)return R;
				if(R == -1)return L;
				propNC(ggen, L, R);
				return ggen++;
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
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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