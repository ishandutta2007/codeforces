//package goodbye2016;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
//		int[][] T = {
//				{0, -1, -1, -1},
//				{1, 2, -1, -1},
//				{3, 4, 5, -1},
//				{6, 7, 8, 9}
//		};
//////		for(int i = 0;i < 4;i++){
//////			for(int j = 0;j < 4;j++){
//////				if(T[j][i] != -1){
//////					out.printf("w[%d] = Math.min(w[%d], A[%d] + v[%d]);\n", j, j, T[j][i], i);
//////				}
//////			}
//////		}
//		for(int i = 0;i < 4;i++){
//			for(int j = 0;j < 4;j++){
//				for(int k = 0;k < 4;k++){
//					if(T[k][i] != -1 && T[j][k] != -1){
//						out.printf("C[%d] = Math.min(C[%d], A[%d] + B[%d]);\n", T[j][i], T[j][i], T[j][k], T[k][i]);
//					}
//				}
//			}
//		}
//		if(true)return;
		
		
		int n = ni(), Q = ni();
		char[] s = ns(n);
		s = rev(s);
		int[][] prevs = makeFatNext(s, '0', '9');
		s = rev(s);
		
		SegmentTreeMatrix st = new SegmentTreeMatrix(s);
		for(int z = 0;z < Q;z++){
			int l = ni()-1, r = ni()-1;
			int ilast7 = prevs[7][n-1-r];
			if(n-ilast7 < l){ out.println(-1); continue; }
			int ilast1 = prevs[1][ilast7];
			if(n-ilast1 < l){ out.println(-1); continue; }
			int ilast0 = prevs[0][ilast1];
			if(n-ilast0 < l){ out.println(-1); continue; }
			int ilast2 = prevs[2][ilast0];
			if(n-ilast2 < l){ out.println(-1); continue; }
			
			st.update(n-ilast2, SegmentTreeMatrix.I);
			st.update(n-ilast0, SegmentTreeMatrix.I);
			st.update(n-ilast1, SegmentTreeMatrix.I);
			
			int[] cost = st.apply(l, r+1, new int[]{0, 0, 0, 0});
			int min = SegmentTreeMatrix.XI;
			for(int u : cost){
				min = Math.min(min, u);
			}
			st.update(n-ilast2, 1);
			st.update(n-ilast0, 1);
			st.update(n-ilast1, 1);
			out.println(min);
		}
	}
	
	public static class SegmentTreeMatrix {
		public int M, H, N;
		public int[][] node;
		public static int S = 10;
		static int XI = 100000000;
		static int I = 1000000;
		
		// 0 0
		// 1 0 1 1
		// 2 0 2 1 2 2
		// 3 0 3 1 3 2 3 3
		static final int[] hey = {0,2, 5, 9};
		
		public SegmentTreeMatrix(char[] h)
		{
			N = h.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			
			node = new int[M][];
			for(int i = 0;i < N;i++){
				node[H+i] = new int[S];
				int ind = "2016".indexOf(h[i]);
				if(ind >= 0){
					node[H+i][hey[ind]] = 1;
				}
			}
			
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		private void propagate(int cur)
		{
			node[cur] = prop2(node[2*cur], node[2*cur+1], node[cur]);
		}
		
		private int[] prop2(int[] L, int[] R, int[] C)
		{
			if(L != null && R != null){
				C = mul(R, L, C);
				return C;
			}else if(L != null){
				return prop1(L, C);
			}else if(R != null){
				return prop1(R, C);
			}else{
				return null;
			}
		}
		
		private int[] prop1(int[] L, int[] C)
		{
			if(C == null){
//				C = L; // read only
				C = Arrays.copyOf(L, S);
			}else{
				for(int i = 0;i < S;i++){
					C[i] = L[i];
				}
			}
			return C;
		}
		
		public void update(int pos, int v) {
			for(int i = 0;i < 4;i++){
				if(node[H+pos][hey[i]] != 0){
					node[H+pos][hey[i]] = v;
				}
			}
			for(int i = H+pos>>>1;i >= 1;i>>>=1)propagate(i);
		}
		
		public int[] apply(int l, int r, int[] v){
			return apply(l, r, 0, H, 1, v);
		}
		
		protected int[] apply(int l, int r, int cl, int cr, int cur, int[] v)
		{
			if(l <= cl && cr <= r){
				return mul(node[cur], v);
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
		
		
		public static int[] mul(int[] A, int[] v)
		{
			int[] w = new int[v.length];
			Arrays.fill(w, XI);
			w[0] = Math.min(w[0], A[0] + v[0]);
			w[1] = Math.min(w[1], A[1] + v[0]);
			w[2] = Math.min(w[2], A[3] + v[0]);
			w[3] = Math.min(w[3], A[6] + v[0]);
			w[1] = Math.min(w[1], A[2] + v[1]);
			w[2] = Math.min(w[2], A[4] + v[1]);
			w[3] = Math.min(w[3], A[7] + v[1]);
			w[2] = Math.min(w[2], A[5] + v[2]);
			w[3] = Math.min(w[3], A[8] + v[2]);
			w[3] = Math.min(w[3], A[9] + v[3]);
			return w;
		}
		
		public static int[] mul(int[] A, int[] B, int[] C)
		{
			if(C == null)C = new int[S];
			
			Arrays.fill(C, XI);
			C[0] = Math.min(C[0], A[0] + B[0]);
			C[1] = Math.min(C[1], A[1] + B[0]);
			C[1] = Math.min(C[1], A[2] + B[1]);
			C[3] = Math.min(C[3], A[3] + B[0]);
			C[3] = Math.min(C[3], A[4] + B[1]);
			C[3] = Math.min(C[3], A[5] + B[3]);
			C[6] = Math.min(C[6], A[6] + B[0]);
			C[6] = Math.min(C[6], A[7] + B[1]);
			C[6] = Math.min(C[6], A[8] + B[3]);
			C[6] = Math.min(C[6], A[9] + B[6]);
			C[2] = Math.min(C[2], A[2] + B[2]);
			C[4] = Math.min(C[4], A[4] + B[2]);
			C[4] = Math.min(C[4], A[5] + B[4]);
			C[7] = Math.min(C[7], A[7] + B[2]);
			C[7] = Math.min(C[7], A[8] + B[4]);
			C[7] = Math.min(C[7], A[9] + B[7]);
			C[5] = Math.min(C[5], A[5] + B[5]);
			C[8] = Math.min(C[8], A[8] + B[5]);
			C[8] = Math.min(C[8], A[9] + B[8]);
			C[9] = Math.min(C[9], A[9] + B[9]);
			
			return C;
		}
	}	

	
	
	public static char[] rev(char[] a)
	{
		for(int i = 0, j = a.length-1;i < j;i++,j--){
			char c = a[i]; a[i] = a[j]; a[j] = c;
		}
		return a;
	}
	
	public static int[][] makeFatNext(char[] s, char inf, char sup)
	{
		int n = s.length;
		int[][] next = new int[sup-inf+1][n+1];
		for(int i = 0;i < sup-inf+1;i++)next[i][n] = n+1;
		for(int i = s.length-1;i >= 0;i--){
			for(int j = 0;j < sup-inf+1;j++)next[j][i] = next[j][i+1];
			next[s[i]-inf][i] = i+1;
		}
		return next;
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
	
	public static void main(String[] args) throws Exception { new E3().run(); }
	
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