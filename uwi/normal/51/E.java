//package round48;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class E10 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		long[][] M = new long[n][n];
		for(int i = 0;i < m;i++){
			int f = ni()-1,t = ni()-1;
			M[f][t] = M[t][f] = 1;
		}
		
		long[][] M2 = p2(M);
		long[][] M4 = p2(M2);
		
		long[] diag5 = diag(M4, M);
		long[] diag3 = diag(M2, M);
		
		long tot = 0;
		for(int i = 0;i < n;i++){
			tot += diag5[i];
			tot -= 5*diag3[i];
			int d = -2;
			for(int j = 0;j < n;j++){
				d += M[i][j];
			}
			tot -= 5 * d * diag3[i];
		}
//		tr(tot);
		
		out.println(tot / 10);
	}
	
	// long2
	public static long[][] p2(long[][] A)
	{
		int n = A.length;
		long[][] C = new long[n][n];
		for(int i = 0;i < n;i++){
			for(int j = i;j < n;j++){
				long sum = 0;
				for(int k = 0;k < n;k++){
					sum += A[i][k] * A[k][j];
				}
				C[i][j] = C[j][i] = (int)sum;
			}
		}
		return C;
	}
	
	public static long[] diag(long[][] A, long[][] B)
	{
		int n = A[0].length;
		long[] ret = new long[n];
		for(int i = 0;i < n;i++){
			long row = 0;
			for(int k = 0;k < n;k++){
				row += A[i][k] * B[k][i];
			}
			ret[i] = row;
		}
		return ret;
	}
	
	public static long[][] mul(long[][] A, long[][] B)
	{
		int m = A.length;
		int n = A[0].length;
		int o = B[0].length;
		long[][] C = new long[m][o];
		for(int i = 0;i < m;i++){
			for(int j = 0;j < o;j++){
				long sum = 0;
				for(int k = 0;k < n;k++){
					sum += A[i][k] * B[k][j];
				}
				C[i][j] = sum;
			}
		}
		return C;
	}
	
	void run() throws Exception
	{
//		StringBuilder sb = new StringBuilder();
//		sb.append(700 + " " + (700*699/2) + " ");
//		int n = 700;
//		for(int i = 1;i <= n;i++){
//			for(int j = i+1;j <= n;j++){
//				sb.append(i + " " + j + " ");
//			}
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new E10().run();
	}
	
	public int ni()
	{
		try {
			int num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public long nl()
	{
		try {
			long num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public String ns()
	{
		try{
			int b = 0;
			StringBuilder sb = new StringBuilder();
			while((b = is.read()) != -1 && (b == '\r' || b == '\n' || b == ' '));
			if(b == -1)return "";
			sb.append((char)b);
			while(true){
				b = is.read();
				if(b == -1)return sb.toString();
				if(b == '\r' || b == '\n' || b == ' ')return sb.toString();
				sb.append((char)b);
			}
		} catch (IOException e) {
		}
		return "";
	}
	
	public char[] ns(int n)
	{
		char[] buf = new char[n];
		try{
			int b = 0, p = 0;
			while((b = is.read()) != -1 && (b == ' ' || b == '\r' || b == '\n'));
			if(b == -1)return null;
			buf[p++] = (char)b;
			while(p < n){
				b = is.read();
				if(b == -1 || b == ' ' || b == '\r' || b == '\n')break;
				buf[p++] = (char)b;
			}
			return Arrays.copyOf(buf, p);
		} catch (IOException e) {
		}
		return null;
	}
	
	
	double nd() { return Double.parseDouble(ns()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}