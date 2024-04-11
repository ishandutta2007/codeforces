//package round341;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), Q = ni();
		SegmentTreeMatrix st = new SegmentTreeMatrix(n+1);
		double[] th = new double[n];
//		double[] sc = new double[n];
//		Arrays.fill(sc, 1.);
		for(int i = 0;i < Q;i++){
			int t = ni();
			if(t == 1){
				int y = ni()-1;
				double z = nd();
				st.node[st.H+n-1-y][0][2] += z;
				st.prop(n-1-y);
			}else{
				int y = ni()-1;
				th[y] += nd();
//				th[y] %= 360;
				double q = th[y] / 180 * Math.PI;
				st.node[st.H+n-y][0][0] = 
						st.node[st.H+n-y][1][1] = 
						Math.cos(q);
				st.node[st.H+n-y][0][1] = 
						st.node[st.H+n-y][1][0] = 
						Math.sin(q);
				st.node[st.H+n-y][1][0] = -st.node[st.H+n-y][1][0];
				st.prop(n-y);
			}
			double x = st.node[1][0][2];
			double y = st.node[1][1][2];
			out.printf("%.14f %.14f\n", x, y);
		}
	}
	
	public static class SegmentTreeMatrix {
		public int M, H, N;
		public double[][][] node;
		public int S = 3;
		
		public SegmentTreeMatrix(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			
			node = new double[M][][];
			for(int i = 0;i < N;i++){
				node[H+i] = new double[S][S];
				node[H+i][0][0] = 1.;
				node[H+i][1][1] = 1.;
				node[H+i][2][2] = 1.;
				node[H+i][0][2] = i < N-1 ? 1. : 0.;
			}
			
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		private void propagate(int cur)
		{
			node[cur] = prop2(node[2*cur], node[2*cur+1], node[cur]);
		}
		
		private double[][] prop2(double[][] L, double[][] R, double[][] C)
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
		
		private double[][] prop1(double[][] L, double[][] C)
		{
			if(C == null){
//				C = L; // read only
				C = new double[S][];
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
		
		public void prop(int pos) {
			for(int i = H+pos>>>1;i >= 1;i>>>=1)propagate(i);
		}
		
		public double[] apply(int l, int r, double[] v){
			return apply(l, r, 0, H, 1, v);
		}
		
		protected double[] apply(int l, int r, int cl, int cr, int cur, double[] v)
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
		
		
		public static double[] mul(double[][] A, double[] v)
		{
			int m = A.length;
			int n = v.length;
			double[] w = new double[m];
			for(int i = 0;i < m;i++){
				double sum = 0;
				for(int k = 0;k < n;k++){
					sum += A[i][k] * v[k];
				}
				w[i] = sum;
			}
			return w;
		}
		
		public static double[][] mul(double[][] A, double[][] B, double[][] C)
		{
			int m = A.length;
			int n = A[0].length;
			int o = B[0].length;
			if(C == null)C = new double[m][o];
			for(int i = 0;i < m;i++){
				for(int j = 0;j < o;j++){
					double sum = 0;
					for(int k = 0;k < n;k++){
						sum += (double)A[i][k] * B[k][j];
					}
					C[i][j] = sum;
				}
			}
			return C;
		}
	}	

	
	void run() throws Exception
	{
//		int n = 300000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(n + " ");
//		for (int i = 0; i < n; i++) {
////			sb.append(gen.nextInt(2)+1 + " ");
//			sb.append(2 + " ");
//			sb.append(gen.nextInt(n)+1 + " ");
//			sb.append(gen.nextInt(360)+1 + " ");
//		}
//		INPUT = sb.toString();
		
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