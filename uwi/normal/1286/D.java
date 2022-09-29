//package round612;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.PriorityQueue;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		// 2-SAT
		// 
		// ...x....x...x..
		// x
		// LR
		// RR
		// LL
		// xx
		// LRR
		// LLR
		// LLL
		// RRR
		
		// y
		// LR
		
		int n = ni();
		int[] xs = new int[n];
		int[] vs = new int[n];
		int[] ps = new int[n];
		int mod = 998244353;
		long i100 = invl(100, mod);
		for(int i = 0;i < n;i++) {
			xs[i] = ni();
			vs[i] = ni();
			ps[i] = ni();
		}
		
		PriorityQueue<Datum> pq = new PriorityQueue<>((x, y) -> 
			Long.compare(x.num*y.den, y.num*x.den)
		);
		for(int i = 0;i < n-1;i++) {
			pq.add(new Datum(xs[i+1] - xs[i], vs[i+1] + vs[i], i+1, 2));
			if(vs[i] > vs[i+1]) {
				pq.add(new Datum(xs[i+1] - xs[i], vs[i] - vs[i+1], i+1, 3));
			}
			if(vs[i] < vs[i+1]) {
				pq.add(new Datum(xs[i+1] - xs[i], vs[i+1] - vs[i], i+1, 0));
			}
		}
		
		int p0 = (int)((mod+1 - i100 * (ps[0]) % mod) % mod);
		int p1 = (int)(i100 * (ps[0]) % mod);
		SegmentTreeMatrix st = new SegmentTreeMatrix(ps);
		st.node[st.H] = new int[][]{{1, 0}, {0, 1}};
		st.hey(0);
//		int[] res = st.apply(1, n, new int[] {p0, p1});
		long ans = 0;
		while(!pq.isEmpty()) {
			Datum d = pq.poll();
			
			// 2 RL
			// 0 LL
			// 3 RR
			// 1 LR
			
			int[][] node = st.node[st.H+d.ind];
			int[][] temp = new int[2][2];
			temp[d.type&1][d.type>>>1] = node[d.type&1][d.type>>>1];
			st.node[st.H+d.ind] = temp;
			st.hey(d.ind);
			
			int[] res = st.apply(0, st.H, new int[] {p0, p1});
			ans += d.num*invl(d.den, mod)%mod * (res[0] + res[1]);
			ans %= mod;
			
			node[d.type&1][d.type>>>1] = 0;
			st.node[st.H+d.ind] = node;
			st.hey(d.ind);
		}
		
		out.println(ans);
	}
	
	public static class SegmentTreeMatrix {
		public int M, H, N;
		public int[][][] node;
		public static int mod = 998244353;
		public static long BIG = 8L*mod*mod;
		public static int S = 2;
		static long i100 = invl(100, mod);
		
		public SegmentTreeMatrix(int[] h)
		{
			N = h.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			
			node = new int[M][][];
			for(int i = 0;i < N;i++){
				long ip = h[i] * i100 % mod;
				node[H+i] = new int[][] {
					{(int)((mod+1-ip)%mod), (int)((mod+1-ip)%mod)},
					{(int)ip, (int)ip}
				};
			}
			
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		private void propagate(int cur)
		{
			node[cur] = prop2(node[2*cur], node[2*cur+1], node[cur]);
		}
		
		private int[][] prop2(int[][] L, int[][] R, int[][] C)
		{
			if(L != null && R != null){
				C = mul(R, L, C, mod);
				return C;
			}else if(L != null){
				return prop1(L, C);
			}else if(R != null){
				return prop1(R, C);
			}else{
				return null;
			}
		}
		
		private int[][] prop1(int[][] L, int[][] C)
		{
			if(C == null){
//				C = L; // read only
				C = new int[S][];
				for(int i = 0;i < S;i++){
					C[i] = Arrays.copyOf(L[i], S);
				}
			}else{
				for(int i = 0;i < S;i++){
					C[i] = Arrays.copyOf(L[i], S);
				}
			}
			return C;
		}
		
		public void update(int pos, int r, int c, int to) {
			node[H+pos][r][c] = to;
			for(int i = H+pos>>>1;i >= 1;i>>>=1)propagate(i);
		}
		
		public void hey(int pos) {
			for(int i = H+pos>>>1;i >= 1;i>>>=1)propagate(i);
		}
		
		public int[] apply(int l, int r, int[] v){
			return apply(l, r, 0, H, 1, v);
		}
		
		protected int[] apply(int l, int r, int cl, int cr, int cur, int[] v)
		{
			if(l <= cl && cr <= r){
				return mul(node[cur], v, mod);
			}else{
				int mid = cl+cr>>>1;
				if(cl < r && l < mid){
					v = apply(l, r, cl, mid, 2*cur, v);
				}
				if(mid < r && l < cr){
					v = apply(l, r, mid, cr, 2*cur+1, v);
				}
				return v;
			}
		}
		
		
		public static int[] mul(int[][] A, int[] v, int mod)
		{
			int m = A.length;
			int n = v.length;
			int[] w = new int[m];
			for(int i = 0;i < m;i++){
				long sum = 0;
				for(int k = 0;k < n;k++){
					sum += (long)A[i][k] * v[k];
//					if(sum >= BIG)sum -= BIG;
				}
				w[i] = (int)(sum % mod);
			}
			return w;
		}
		
		public static int[][] mul(int[][] A, int[][] B, int[][] C, int mod)
		{
			assert A[0].length == B.length;
			int m = A.length;
			int n = A[0].length;
			int o = B[0].length;
			if(C == null)C = new int[m][o];
			for(int i = 0;i < m;i++){
				for(int j = 0;j < o;j++){
					long sum = 0;
					for(int k = 0;k < n;k++){
						sum += (long)A[i][k] * B[k][j];
//						if(sum >= BIG)sum -= BIG;
					}
					sum %= mod;
					C[i][j] = (int)sum;
				}
			}
			return C;
		}
	}	

	static class Datum
	{
		long num, den;
		int ind;
		int type;
		public Datum(long num, long den, int ind, int type) {
			super();
			this.num = num;
			this.den = den;
			this.ind = ind;
			this.type = type;
		}
	}
	
	public static long invl(long a, long mod) {
		long b = mod;
		long p = 1, q = 0;
		while (b > 0) {
			long c = a / b;
			long d;
			d = a;
			a = b;
			b = d % b;
			d = p;
			p = q;
			q = d - c * q;
		}
		return p < 0 ? p + mod : p;
	}

	
	void run() throws Exception
	{
//		int n = 100000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		int x = -1000000000;
//		for (int i = 0; i < n; i++) {
//			sb.append(x + " ");
//			x += gen.nextInt(4000);
//			sb.append(gen.nextInt(1000001) + " ");
//			sb.append(gen.nextInt(101) + " ");
//		}
//		INPUT = sb.toString();

		
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