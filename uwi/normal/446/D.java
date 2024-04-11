//package roundFF;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), K = ni();
		int[] trap = na(n);
		int[][] a = new int[n][n];
		int[] deg = new int[n];
		for(int i = 0;i < m;i++){
			int f = ni()-1, t = ni()-1;
			a[f][t]++;
			a[t][f]++;
			deg[f]++;
			deg[t]++;
		}
		double[][] M = new double[n][n];
		for(int i = 0;i < n;i++){
			if(trap[i] == 0){
				for(int j = 0;j < n;j++){
					M[j][i] = (double)a[i][j] / deg[i];
				}
			}
		}
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(i == j){
					M[i][j] = 1 - M[i][j];
				}else{
					M[i][j] = -M[i][j];
				}
			}
		}
		double[][] im = inv(M);
		
		
		double[][] tot = new double[n][];
		
		double[] v = new double[n];
		v[0] = 1;
		tot[0] = mul(im, v);
//		tr(0, tot[0]);
		
		for(int i = 0;i < n;i++){
			if(trap[i] == 1){
				v = new double[n];
				for(int j = 0;j < n;j++){
					v[j] = (double)a[i][j] / deg[i];
				}
				tot[i] = mul(im, v);
//				tr(i, tot[i]);
			}
		}
		
		int u = 0;
		int[] map = new int[n];
		Arrays.fill(map, -1);
		for(int i = 0;i < n;i++){
			if(trap[i] == 1)map[u++] = i;
		}
		double[] V = new double[u];
		for(int i = 0;i < u;i++){
			V[i] = tot[0][map[i]];
		}
		
		double[][] Q = new double[u][u];
		for(int i = 0;i < u;i++){
			double ls = 0;
			for(int j = 0;j < u;j++){
				Q[j][i] = tot[map[i]][map[j]];
				ls += Q[j][i];
			}
			for(int j = 0;j < u;j++){
				Q[j][i] /= ls;
			}
		}
//		tr(Q);
		
		double[] t = pow(Q, V, K-2);
		out.printf("%.12f\n", t[u-1]);
	}
	
	public static double[][] p2(double[][] A)
	{
		int n = A.length;
		double[][] C = new double[n][n];
		for(int i = 0;i < n;i++){
			for(int k = 0;k < n;k++){
				for(int j = 0;j < n;j++){
					C[i][j] += A[i][k] * A[k][j];
				}
			}
		}
		return C;
	}
	
	// A^e*v
	public static double[] pow(double[][] A, double[] v, int m)
	{
		double[][] mu = A;
		double[] r = v;
		for(;m > 0;m>>>=1){
			if((m&1)==1)r = mul(mu, r);
			mu = p2(mu);
		}
		return r;
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
	
	public static double[][] LU(double[][] mat)
	{
		int n = mat.length;
		
		double[][] lu = new double[n][];
		for(int i = 0;i < n;i++){
			lu[i] = Arrays.copyOf(mat[i], n);
		}
		
		for(int i = 0;i < n;i++){
			int z = i;
			for(;z < n && lu[z][i] == 0;z++);
			if(z == n)continue;
			double[] d = lu[z]; lu[z] = lu[i]; lu[i] = d;
			
			for(int j = i+1;j < n;j++){
				lu[j][i] /= lu[i][i];
				for(int k = i+1;k < n;k++){
					lu[j][k] -= lu[j][i] * lu[i][k];
				}
			}
		}
		
		return lu;
	}
	
	public static double[][] invL(double[][] L)
	{
		int n = L.length;
		double[][] il = new double[n][n];
		// row:j, col:i
		for(int i = 0;i < n;i++){
			for(int j = i;j < n;j++){
				double sum = i == j ? 1 : 0;
				for(int k = i;k < j;k++){
					sum -= L[j][k] * il[k][i];
				}
				il[j][i] = sum / L[j][j];
			}
		}
		return il;
	}
	
	public static double[][] invU(double[][] U)
	{
		int n = U.length;
		double[][] iu = new double[n][n];
		// row:j, col:i
		for(int i = 0;i < n;i++){
			for(int j = i;j < n;j++){
				double sum = i == j ? 1 : 0;
				for(int k = i;k < j;k++){
					sum -= U[k][j] * iu[i][k];
				}
				iu[i][j] = sum / U[j][j];
			}
		}
		return iu;
	}
	
	public static double[][] inv(double[][] A)
	{
		int n = A.length;
		double[][] lu = LU(A);
		double[][] iu = invU(lu);
		for(int i = 0;i < n;i++)lu[i][i] = 1.0;
		double[][] il = invL(lu);
		return mul(iu, il);
	}
	
	public static double[][] mul(double[][] A, double[][] B)
	{
		int m = A.length;
		int n = A[0].length;
		int o = B[0].length;
		double[][] C = new double[m][o];
		for(int i = 0;i < m;i++){
			for(int k = 0;k < n;k++){
				for(int j = 0;j < o;j++){
					C[i][j] += A[i][k] * B[k][j];
				}
			}
		}
		return C;
	}
	
	public static double[] solve(double[][] a, double[] c)
	{
		int n = a.length;
		int[] ps = new int[n];
		for(int i = 0;i < n;i++)ps[i] = i;
		
		// Forward Elimination
		for(int i = 0;i < n;i++){
			int pivot = -1;
			int from = -1;
			double amax = 0;
			for(int j = i;j < n;j++){
				if(Math.abs(a[ps[j]][i]) > amax){
					amax = Math.abs(a[ps[j]][i]);
					pivot = ps[j];
					from = j;
				}
			}
			if(pivot == -1)return null;
			int d = ps[i]; ps[i] = ps[from]; ps[from] = d;
			
			for(int j = i+1;j < n;j++){
				a[ps[i]][j] /= a[ps[i]][i];
			}
			c[ps[i]] /= a[ps[i]][i];
			a[ps[i]][i] = 1.0;
			for(int j = i+1;j < n;j++){
				for(int k = i+1;k < n;k++){
					a[ps[j]][k] -= a[ps[j]][i] * a[ps[i]][k];
				}
				c[ps[j]] -= a[ps[j]][i] * c[ps[i]];
				a[ps[j]][i] = 0.0;
			}
			
		}
		
		// Back Substitution
		for(int i = n-1;i >= 0;i--){
			for(int j = i-1;j >= 0;j--){
				c[ps[j]] -= a[ps[j]][i] * c[ps[i]];
			}
		}
		
		double[] ret = new double[n];
		for(int i = 0;i < n;i++){
			ret[i] = c[ps[i]];
		}
		
		return ret;
	}
	
	public static double[] S(double[][] T, double[] v)
	{
		int n = T.length;
		double[][] U = new double[n][n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				U[i][j] = (i == j ? 1 : 0) - T[i][j];
			}
		}
		return solve(U, v);
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
	
	public static void main(String[] args) throws Exception { new D2().run(); }
	
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