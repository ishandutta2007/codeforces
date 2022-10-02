//package round24;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class D2 {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "10 10 10 4";
//	private String INPUT = "10 14 5 14";
//	private String INPUT = "2 2 1 1";
//	private String INPUT = "10 3 7 2";
//	private String INPUT = "1 1 1 1";
//	private String INPUT = "1000 1000 1 1";
	private String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		int m = ni();
		int i = ni();
		int j = ni();
		
		double[][] A = new double[m][m];
		double[][] B = new double[m][m];
		if(m == 1){
			A[0][0] = 1.0 / 2;
			B[0][0] = 1.0 / 2;
		}else{
			for(int k = 1;k < m - 1;k++){
				A[k-1][k] = 1.0 / 4;
				A[k+1][k] = 1.0 / 4;
				A[k][k] = 1.0 / 4;
			}
			A[0][0] = 1.0 / 3;
			A[m-1][m-1] = 1.0 / 3;
			A[1][0] = 1.0 / 3;
			A[m - 2][m - 1] = 1.0 / 3;
			A = Mat.sub(Mat.E(m), A); // E-A
	//		System.out.println(Mat.toString(Mat.inv(A))); // (E-A)^-1
			
			for(int k = 1;k < m - 1;k++){
				B[k][k] = 1.0 / 4;
			}
			B[0][0] = 1.0 / 3;
			B[m-1][m-1] = 1.0 / 3;
		}
		double[][] ta = Mat.trigonalArray(A);
		
		double[] p = new double[m];
		p[j-1] = 1.0;
		
		double e = 0.0;
		for(int k = i;k < n;k++){
			tr(k);
//			double[] ev = Mat.solveTrigonal(A, Mat.solveTrigonal(A, p));
			double[] ev = Mat.solveTrigonalArray(ta, Mat.solveTrigonalArray(ta, p));
			for(int l = 0;l < m;l++){
				ev[l] *= B[l][l];
			}
			for(double eve : ev){
				e += eve;
			}
//			e++;
			
//			p = Mat.solveTrigonal(A, p);
			p = Mat.solveTrigonalArray(ta, p);
			for(int l = 0;l < m;l++){
				p[l] *= B[l][l];
			}
		}
		out.printf("%1.9f\n", e);
	}
	
	public void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
	}
	
	public static void main(String[] args) throws Exception
	{
		new D2().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private void tr(Object... o) { if(INPUT.length() > 0)System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
	
	public static class Mat {
		public static double EPS = 1E-13;
		
		public static double[][] copy(double[][] A)
		{
			double[][] ret = new double[A.length][];
			for(int i = 0;i < A.length;i++){
				ret[i] = Arrays.copyOf(A[i], A[i].length);
			}
			return ret;
		}
		
		public static double[] solveTrigonal(double[][] Asrc, double[] vsrc)
		{
			double[][] A = copy(Asrc);
			double[] v = Arrays.copyOf(vsrc, vsrc.length);
			
//			Mat.print(a);
//			tr(Arrays.toString(v));
			int n = A.length;
			for(int i = 0;i < n - 1;i++){
				double r = A[i+1][i] / A[i][i];
				for(int j = i;j <= i + 1;j++){
					A[i+1][j] -= r * A[i][j];
				}
				v[i+1] -= r * v[i];
			}
			for(int i = n - 1;i >= 1;i--){
				double r = A[i-1][i] / A[i][i];
				for(int j = i - 1;j <= i;j++){
					A[i-1][j] -= r * A[i][j];
				}
				v[i-1] -= r * v[i];
			}
			for(int i = 0;i < n;i++){
				v[i] /= A[i][i];
			}
//			Mat.print(a);
			return v;
		}
		
		public static double[] solveTrigonalArray(double[][] a, double[] vsrc)
		{
			double[] v = Arrays.copyOf(vsrc, vsrc.length);
			
			int n = a[0].length;
			for(int i = 0;i < n - 1;i++){
				v[i+1] -= a[0][i] * v[i];
			}
			for(int i = n - 1;i >= 1;i--){
				v[i-1] -= a[1][i] * v[i];
			}
			for(int i = 0;i < n;i++){
				v[i] /= a[2][i];
			}
			return v;
		}
		
		public static double[][] trigonalArray(double[][] Asrc)
		{
			double[][] A = copy(Asrc);
			int n = A.length;
			double[][] ret = new double[3][n];
			
			for(int i = 0;i < n - 1;i++){
				double r = A[i+1][i] / A[i][i];
				for(int j = i;j <= i + 1;j++){
					A[i+1][j] -= r * A[i][j];
				}
				ret[0][i] = r;
			}
			for(int i = n - 1;i >= 1;i--){
				double r = A[i-1][i] / A[i][i];
				for(int j = i - 1;j <= i;j++){
					A[i-1][j] -= r * A[i][j];
				}
				ret[1][i] = r;
			}
			for(int i = 0;i < n;i++){
				ret[2][i] = A[i][i];
			}
			return ret;
		}
		
		public static double[][] mul(double[][] A, double[][] B)
		{
			int m = A.length;
			int n = A[0].length;
			int o = B[0].length;
			double[][] C = new double[m][o];
			for(int i = 0;i < m;i++){
				for(int j = 0;j < o;j++){
					double sum = 0;
					for(int k = 0;k < n;k++){
						sum += A[i][k] * B[k][j];
					}
					C[i][j] = sum;
				}
			}
			return C;
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
		
		public static double[][] trans(double[][] A)
		{
			int m = A.length;
			int n = A[0].length;
			double[][] At = new double[n][m];
			for(int i = 0;i < m;i++){
				for(int j = 0;j < n;j++){
					At[j][i] = A[i][j];
				}
			}
			
			return At;
		}
		
		public static double[][] E(int n)
		{
			double[][] e = new double[n][n];
			for(int i = 0;i < n;i++)e[i][i] = 1.0;
			return e;
		}
		
		public static double[][] add(double[][] A, double[][] B)
		{
			int m = A.length;
			int n = A[0].length;
			double[][] C = new double[m][n];
			for(int i = 0;i < m;i++){
				for(int j = 0;j < n;j++){
					C[i][j] = A[i][j] + B[i][j];
				}
			}
			return C;
		}
		
		public static double[][] sub(double[][] A, double[][] B)
		{
			int m = A.length;
			int n = A[0].length;
			double[][] C = new double[m][n];
			for(int i = 0;i < m;i++){
				for(int j = 0;j < n;j++){
					C[i][j] = A[i][j] - B[i][j];
				}
			}
			return C;
		}
		
		public static String toString(double[][] A)
		{
			StringBuilder sb = new StringBuilder();
			for(double[] row : A){
				sb.append(Arrays.toString(row));
				sb.append('\n');
			}
			return sb.toString();
		}
		
		/**
		 * LU
		 * L1, Ulu
		 * @param mat
		 * @return
		 */
		public static double[][] LU(double[][] mat)
		{
			int n = mat.length;
			
			double[][] lu = new double[n][];
			for(int i = 0;i < n;i++){
				lu[i] = Arrays.copyOf(mat[i], n);
			}
			
			for(int i = 0;i < n;i++){
				for(int j = i+1;j < n;j++){
					if(Math.abs(lu[j][i]) > EPS){
						lu[j][i] /= lu[i][i];
						for(int k = i+1;k < n;k++){
							lu[j][k] -= lu[j][i] * lu[i][k];
						}
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
		
		public static double[] solve(double[][] A, double[] v)
		{
			int n = A.length;
			double[][] lu = LU(A);
			double[][] iu = invU(lu);
			for(int i = 0;i < n;i++)lu[i][i] = 1.0;
			double[][] il = invL(lu);
			return mul(iu, mul(il, v));
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
		
		public static double det(double[][] A)
		{
			double[][] lu = LU(A);
			double ret = 1;
			for(int i = 0;i < lu.length;i++){
				ret *= lu[i][i];
			}
			return ret;
		}
		
		public static void print(double[][] A)
		{
			for(double[] row : A){
				System.out.println(Arrays.toString(row));
			}
		}
	}
}