//package roundFF;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C3PO {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	static final int mod = 1000000009;
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] a = na(n);
		int[] cum = new int[n+1];
		for(int i = 0;i < n;i++){
			cum[i+1] = cum[i] + a[i];
			if(cum[i+1] >= mod)cum[i+1] -= mod;
		}
		
		int[] F = new int[n+1];
		F[0] = F[1] = 1;
		for(int i = 2;i <= n;i++){
			F[i] = F[i-1] + F[i-2];
			if(F[i] >= mod)F[i] -= mod;
		}
		
		SegmentTreeNode st = new SegmentTreeNode(n+1);
		for(int q = 0;q < m;q++){
			int type = ni();
			if(type == 1){
				int L = ni();
				int R = ni();
				st.node[st.H+L-1][0] += 1;
				st.node[st.H+L-1][2] += 1;
				st.update(L-1);
				st.node[st.H+R][0] -= F[R-L+1];
				st.node[st.H+R][1] -= F[R-L];
				st.node[st.H+R][2] -= F[R-L+1];
				if(st.node[st.H+R][0] < 0){
					st.node[st.H+R][0] += mod;
				}
				if(st.node[st.H+R][1] < 0){
					st.node[st.H+R][1] += mod;
				}
				if(st.node[st.H+R][2] < 0){
					st.node[st.H+R][2] += mod;
				}
				st.update(R);
			}else{
				int L = ni();
				int R = ni();
				long[] rr = st.apply(0, R, new long[]{0, 0, 0, 1});
				long[] ll = st.apply(0, L-1, new long[]{0, 0, 0, 1});
				long ret = (long)rr[2]-ll[2] + cum[R+1-1] - cum[L-1] + 2L*mod;
				ret %= mod;
				out.println(ret);
			}
		}
		
	}
	
	public static long BIG = 8L*mod*mod;
	
	// A^e*v
	public static int[] pow(int[][] A, int[] v, long e, int mod)
	{
		int[][] MUL = A;
		for(int i = 0;i < v.length;i++){
			if(v[i] >= mod)v[i] %= mod;
		}
		for(;e > 0;e>>>=1) {
			if((e&1)==1)v = mul(MUL, v, mod);
			MUL = p2(MUL, mod);
		}
		return v;
	}
	
	// int matrix*int vector
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
	
	// int matrix^2 (be careful about minus value)
	public static int[][] p2(int[][] A, int mod)
	{
		int n = A.length;
		int[][] C = new int[n][n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				long sum = 0;
				for(int k = 0;k < n;k++){
					sum += (long)A[i][k] * A[k][j];
					if(sum >= BIG)sum %= mod;
				}
				C[i][j] = (int)(sum % mod);
			}
		}
		return C;
	}
	
	// A^e
	// O(N^3log N)
	public static int[][] pow(int[][] A, long e, int mod)
	{
		int[][] MUL = A;
		int n = A.length;
		int[][] C = new int[n][n];
		for(int i = 0;i < n;i++)C[i][i] = 1;
		for(;e > 0;e>>>=1) {
			if((e&1)==1)C = mul(C, MUL, mod);
			MUL = p2(MUL, mod);
		}
		return C;
	}
	
	public static int[][] mul(int[][] A, int[][] B, int mod)
	{
		int m = A.length;
		int n = A[0].length;
		int o = B[0].length;
		int[][] C = new int[m][o];
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
	
	public static int[][] mul(int[][] A, int[][] B, int[][] C, int mod)
	{
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
	
	public static class SegmentTreeNode {
		public int M, H, N;
		public long[][] node;
		public int[][][] tmpl;
		
		public SegmentTreeNode(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			
			node = new long[M][4];
			
			tmpl = new int[25][][];
			tmpl[0] = new int[][]{
					{1, 1, 0},
					{1, 0, 0},
					{1, 1, 1}
			};
			for(int i = 1;i <= 24;i++){
				tmpl[i] = p2(tmpl[i-1], mod);
			}
			
			for(int i = 1;i < H+N;i++){
				int d = Integer.numberOfTrailingZeros(H/Integer.highestOneBit(i));
				node[i] = new long[3];
			}
		}
		
		private void propagate(int cur)
		{
			node[cur] = prop2(node[2*cur], node[2*cur+1], node[cur], Integer.numberOfTrailingZeros(H/Integer.highestOneBit(cur)));
		}
		
		private long get(int d, int r, int c, long[] b)
		{
			if(c == 3){
				return r == 3 ? 1 : b[r];
			}else if(r == 3){
				return 0;
			}else{
				return tmpl[d][r][c];
			}
		}
		
		private long[] prop2(long[] L, long[] R, long[] C, int d)
		{
			if(L != null && R != null){
				if(C == null){
					throw new RuntimeException();
				}else{
					for(int i = 0;i < 3;i++){
						for(int j = 3;j < 4;j++){
							long sum = 0;
							for(int k = 0;k < 4;k++){
								sum += (long)get(d-1, i, k, R) * get(d-1, k, j, L);
								if(sum >= BIG)sum -= BIG;
							}
							sum %= mod;
							C[i] = (int)sum;
						}
					}
				}
				return C;
			}else if(L != null){
				return prop1(L, C);
			}else if(R != null){
				return prop1(R, C);
			}else{
				return null;
			}
		}
		
		private long[] prop1(long[] L, long[] C)
		{
			if(C == null){
				throw new RuntimeException();
			}else{
				C = Arrays.copyOf(L, 3);
			}
			return C;
		}
		
		public void update(int pos) {
			for(int i = H+pos>>>1;i >= 1;i>>>=1)propagate(i);
		}
		
		public long[] apply(int l, int r, long[] v){
			return apply(l, r, 0, H, 1, v);
		}
		
		protected long[] apply(int l, int r, int cl, int cr, int cur, long[] v)
		{
			if(l <= cl && cr <= r){
				int d = Integer.numberOfTrailingZeros(H/Integer.highestOneBit(cur));
				long[] ret = new long[4];
				for(int i = 0;i < 4;i++){
					long s = 0;
					for(int j = 0;j < 4;j++){
						s += get(d, i, j, node[cur]) * v[j];
					}
					ret[i] = s%mod;
				}
				return ret;
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
	
	public static void main(String[] args) throws Exception { new C3PO().run(); }
	
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