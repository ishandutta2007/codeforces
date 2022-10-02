//package bubble8;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class A {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		long K = nl();
		int P = ni();
		int n = ni();
		int[] s = na(n);
		for(int i = 0;i < n;i++)s[i] %= P;
		int m = ni();
		long[][] irs = new long[m*2][];
		for(int i = 0;i < m;i++){
			long J = nl();
			int v = ni();
			irs[i*2] = new long[]{J, 1, v%P};
			irs[i*2+1] = new long[]{J-1, 0, v%P};
		}
		if(K == 0){
			out.println(0);
			return;
		}
		if(K == 1){
			out.println(1%P);
			return;
		}
		Arrays.sort(irs, new Comparator<long[]>() {
			public int compare(long[] a, long[] b) {
				return Long.compare(a[0], b[0]);
			}
		});
		m *= 2;
		for(int i = 0;i < m;i++){
			if(irs[i][0]/n > (K-1)/n){
				m = i;
				break;
			}
		}
		
		SegmentTreeArray st = new SegmentTreeArray(s, P);
		long[] base = st.node[1];
		int[][] B = new int[][]{{(int)base[0], (int)base[1]}, {(int)base[2], (int)base[3]}};
		
		long e = 0;
		int[] v = {1%P, 0};
		// 0 1 1 4 2 3
		for(int i = 0;i < m;){
			int j = i;
			for(;j < m && irs[i][0]/n == irs[j][0]/n;)j++;
			if(e < irs[i][0]/n){
				v = pow(B, v, irs[i][0]/n-e, P);
			}
			for(int k = i;k < j;k++){
				st.update((int)(irs[k][0]%n), (int)(irs[k][1]), (int)(irs[k][2]));
			}
			long[] ls = st.sum(0, (int)(Math.min(n, K-1-irs[i][0]/n*n)));
			if(ls != null){
				long nv0 = (v[0]*ls[0]+v[1]*ls[1])%P;
				long nv1 = (v[0]*ls[2]+v[1]*ls[3])%P;
				v[0] = (int)nv0; v[1] = (int)nv1;
			}
			
			e = irs[i][0]/n+1;
			for(int k = i;k < j;k++){
				st.update((int)(irs[k][0]%n), (int)(irs[k][1]), s[(int)((irs[k][0]+1-irs[k][1])%n)]);
			}
			
			i = j;
		}
		if(e < (K-1)/n){
			v = pow(B, v, (K-1)/n-e, P);
		}
		if(e <= (K-1)/n){
			long[] ls = st.sum(0, (int)((K-1)%n));
			if(ls != null){
				long nv0 = (v[0]*ls[0]+v[1]*ls[1])%P;
				long nv1 = (v[0]*ls[2]+v[1]*ls[3])%P;
				v[0] = (int)nv0; v[1] = (int)nv1;
			}
		}
		
		if(!(v[0] >= 0 && v[0] < P))throw new RuntimeException();
		out.println(v[0]);
	}
	
	// A^e*v
	public static int[] pow(int[][] A, int[] v, long e, int mod)
	{
		int[][] MUL = A;
		for(int i = 0;i < v.length;i++)v[i] %= mod;
		for(;e > 0;e>>>=1) {
			if((e&1)==1)v = mul(MUL, v, mod);
			MUL = p2(MUL, mod);
		}
		return v;
	}
	
	
	// int matrix * int vector
	public static int[] mul(int[][] A, int[] v, int mod)
	{
		int m = A.length;
		int n = v.length;
		int[] w = new int[m];
		for(int i = 0;i < m;i++){
			long sum = 0;
			for(int k = 0;k < n;k++){
				sum += (long)A[i][k] * v[k];
				sum %= mod;
			}
			w[i] = (int)sum;
		}
		return w;
	}
	
	// int matrix^2 (cannot ensure negative values)
	public static int[][] p2(int[][] A, int mod)
	{
		int n = A.length;
		int[][] C = new int[n][n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				long sum = 0;
				for(int k = 0;k < n;k++){
					sum += (long)A[i][k] * A[k][j];
					sum %= mod;
				}
				C[i][j] = (int)sum;
			}
		}
		return C;
	}

	
	public static class SegmentTreeArray {
		public int M, H, N;
		public long[][] node;
		public int P;
		
		public SegmentTreeArray(int[] a, int P)
		{
			this.P = P;
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			
			node = new long[M][];
			for(int i = 0;i < N;i++){
				long[] item = new long[]{a[(i+1)%N], a[i], 1, 0};
				node[H+i] = item;
			}
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		private void propagate(int cur)
		{
			node[cur] = prop2(node[2*cur], node[2*cur+1], node[cur]);
		}
		
		private long[] prop2(long[] L, long[] R, long[] C)
		{
			if(L != null && R != null){
				if(C == null)C = new long[4];
				// L[0] L[1]
				// L[2] L[3]
				// R[0] R[1]
				// R[2] R[3]
				C[0] = (R[0]*L[0] + R[1]*L[2])%P;
				C[1] = (R[0]*L[1]+R[1]*L[3])%P;
				C[2] = (R[2]*L[0]+R[3]*L[2])%P;
				C[3] = (R[2]*L[1]+R[3]*L[3])%P;
				
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
			if(C == null)C = new long[4];
			for(int i = 0;i < 4;i++)C[i] = L[i];
			return C;
		}
		
		public void update(int x, int e, int v) {
			node[H+x][e] = v;
			for(int i = H+x>>>1;i >= 1;i>>>=1)propagate(i);
		}
		
		public long[] sum(int l, int r) {
			return l >= r ? null : sum(l, r, 0, H, 1);
		}
		
		protected long[] sum(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return node[cur];
			}else{
				long[] L = null, R = null;
				int mid = cl+cr>>>1;
				if(cl < r && l < mid){
					L = sum(l, r, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					R = sum(l, r, mid, cr, 2*cur+1);
				}
				return prop2(L, R, null);
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
	
	public static void main(String[] args) throws Exception { new A().run(); }
	
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