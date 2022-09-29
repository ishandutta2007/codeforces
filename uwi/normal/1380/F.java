//package ecr91;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		char[] s = ns(n);
		int[] is = new int[n];
		for(int i = 0;i < n;i++){
			is[i] = s[i]-'0';
		}
		SegmentTreeMatrix st = new SegmentTreeMatrix(is);
		for(int z = 0;z < m;z++){
			int x = ni()-1, v = ni();
			st.update(x, v);
			int[][] M = st.node[1];
			out.println(M[0][0]);
		}
	}
	
	public static class SegmentTreeMatrix {
		public int M, H, N;
		public int[][][] node;
		public static int mod = 998244353;
		public static long BIG = 8L*mod*mod;
		public static int S = 2;
		
		public SegmentTreeMatrix(int[] h)
		{
			N = h.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			
			node = new int[M][][];
			for(int i = 0;i < N;i++){
				node[H+i] = new int[S][S];
				
				node[H+i][0][0] = h[i]+1;
				node[H+i][0][1] = 8-h[i]+1;
				node[H+i][1][0] = h[i] == 1 ? 1 : 0;
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
		
		public void update(int pos, int v) {
			node[H+pos][0][0] = v+1;
			node[H+pos][0][1] = 8-v+1;
			node[H+pos][1][0] = v == 1 ? 1 : 0;
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