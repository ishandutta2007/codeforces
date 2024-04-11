//package round373;
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
		int mod = 1000000007;
		int n = ni(), Q = ni();
		int[] a = na(n);
		SegmentTreeMatrix st = new SegmentTreeMatrix(a);
		for(int i = 0;i < Q;i++){
			int t = ni();
			if(t == 1){
				int l = ni()-1, r = ni()-1, v = ni();
				st.update(l, v);
				st.update(r+1, -v);
			}else{
				int l = ni()-1, r = ni()-1;
				long ret = 
				st.apply(0, r+1, new int[]{1, 0, 0})[2]-
				st.apply(0, l, new int[]{1, 0, 0})[2];
				if(ret < 0)ret += mod;
				out.println(ret);
			}
		}
	}
	
	public static class SegmentTreeMatrix {
		public int M, H, N;
		public int[][][] node;
		public long[] st;
		public static int mod = 1000000007;
		public static long BIG = 8L*mod*mod;
		public static int S = 3;
		
		public static int[][] F = {
				{1, 1},
				{1, 0}
		};
		
		public static int[][] FI = {
				{0, 1},
				{1, mod-1}
		};
		
		int[][] expand(int[][] a)
		{
			int[][] ret = new int[3][3];
			for(int i = 0;i < 2;i++){
				for(int j = 0;j < 2;j++){
					ret[i][j] = a[i][j];
				}
			}
			ret[2][2] = 1;
			ret[2][0] = a[1][0];
			ret[2][1] = a[1][1];
			return ret;
		}
		
		int[][][] XF = generateP2(F, 60);
		int[][][] XFI = generateP2(FI, 60);
		
		public SegmentTreeMatrix(int[] h)
		{
			N = h.length+1;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			
			node = new int[M][][];
			st = new long[M];
			for(int i = 0;i < N;i++){
//				node[H+i] = new int[S][S];
				// TODO
				int c = i == N-1 ? 0 : h[i]-(i == 0 ? 0 : h[i-1]);
				if(c >= 0){
					node[H+i] = expand(pow(XF, c));
				}else{
					node[H+i] = expand(pow(XFI, -c));
				}
				st[H+i] = c;
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
		
		public void update(int pos, int plus) {
			st[H+pos] += plus;
			long c = st[H+pos];
			if(c >= 0){
				node[H+pos] = expand(pow(XF, c));
			}else{
				node[H+pos] = expand(pow(XFI, -c));
			}
			// TODO
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
					if(sum >= BIG)sum -= BIG;
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
						if(sum >= BIG)sum -= BIG;
					}
					sum %= mod;
					C[i][j] = (int)sum;
				}
			}
			return C;
		}
		
		public static int[][] pow(int[][] A, long e)
		{
			int[][] MUL = A;
			int n = A.length;
			int[][] C = new int[n][n];
			for(int i = 0;i < n;i++)C[i][i] = 1;
			for(;e > 0;e>>>=1) {
				if((e&1)==1)C = mul(C, MUL);
				MUL = p2(MUL);
			}
			return C;
		}
		
		public static int[][] p2(int[][] A)
		{
			int n = A.length;
			int[][] C = new int[n][n];
			for(int i = 0;i < n;i++){
				long[] sum = new long[n];
				for(int k = 0;k < n;k++){
					for(int j = 0;j < n;j++){
						sum[j] += (long)A[i][k] * A[k][j];
						if(sum[j] >= BIG)sum[j] -= BIG;
					}
				}
				for(int j = 0;j < n;j++){
					C[i][j] = (int)(sum[j] % mod);
				}
			}
			return C;
		}
		
		public static int[][] mul(int[][] A, int[][] B)
		{
			assert A[0].length == B.length;
			int m = A.length;
			int n = A[0].length;
			int o = B[0].length;
			int[][] C = new int[m][o];
			for(int i = 0;i < m;i++){
				long[] sum = new long[o];
				for(int k = 0;k < n;k++){
					for(int j = 0;j < o;j++){
						sum[j] += (long)A[i][k] * B[k][j];
						if(sum[j] >= BIG)sum[j] -= BIG;
					}
				}
				for(int j = 0;j < o;j++){
					C[i][j] = (int)(sum[j] % mod);
				}
			}
			return C;
		}
		
		// ret[n]=A^(2^n)
		public static int[][][] generateP2(int[][] A, int n)
		{
			int[][][] ret = new int[n+1][][];
			ret[0] = A;
			for(int i = 1;i <= n;i++)ret[i] = p2(ret[i-1]);
			return ret;
		}
		
		// A[0]^e*v
		// A[n]=A[0]^(2^n)
		public static int[][] pow(int[][][] A, long e)
		{
			int n = A[0].length;
			int[][] ret = new int[n][n];
			for(int i = 0;i < n;i++)ret[i][i] = 1;
			for(int i = 0;e > 0;e>>>=1,i++) {
				if((e&1)==1)ret = mul(A[i], ret);
			}
			return ret;
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