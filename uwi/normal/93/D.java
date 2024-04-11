//package round76;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class D2 {
	Scanner in;
	String INPUT = "";
	PrintWriter out;
	
	static int MOD = 1000000007;
	
	void solve()
	{
		int L = ni();
		int R = ni();
		String[] t = {"  ", " B", " R", " W", " Y", "BW", "BY", "RW", "RY", "WB", "WR", "YB", "YR"};
		int m = t.length;
		int[][] M = new int[m+1][m+1];
		for(int i = 0;i < m;i++){
			for(int j = 0;j < m;j++){
				if(t[i].charAt(1) == t[j].charAt(0)){
					M[j][i] = 1;
				}
			}
		}
		M[0][0] = 0;
		M[10][5] = 0;
		M[9][7] = 0;
		for(int i = 0;i <= m;i++) {
			M[m][i] = 1;
		}
		
		int[][][] A = generateP2(M, 30);
		
		int[] v = new int[]{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		int[] gp1 = pow(A, v, R+1);
		int[] gp2 = pow(A, v, L-1+1);
		
		int[] gpq1 = pow(A, v, (R+1)/2+1);
		int[] gpq2 = pow(A, v, L/2+1);
		
		long i2 = inv(2, MOD);
		
		long sum = 0;
		sum += (gp1[m]-gp2[m]-gpq1[m]+gpq2[m])*i2+(gpq1[m]-gpq2[m]);
		sum %= MOD;
		out.println((sum+MOD)%MOD);
	}
	
	public static long inv(long a, int p)
	{
		long ret = 1;
		long mul = a;
		for(long n = p-2;n > 0;n >>>= 1){
			if((n&1)==1)ret = ret * mul % p;
			mul = mul * mul % p;
		}
		return ret;
	}
	
	
	public static int[][][] generateP2(int[][] A, int n)
	{
		int[][][] ret = new int[n+1][][];
		ret[0] = A;
		for(int i = 1;i <= n;i++)ret[i] = p2(ret[i-1]);
		return ret;
	}
	
	public static int[] pow(int[][][] A, int[] v, long e)
	{
		for(int i = 0;e > 0;e>>>=1,i++) {
			if((e&1)==1)v = mul(A[i], v);
		}
		return v;
	}
	
	public static int[][] p2(int[][] A)
	{
		int n = A.length;
		int[][] C = new int[n][n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				long sum = 0;
				for(int k = 0;k < n;k++){
					sum += (long)A[i][k] * A[k][j];
					sum %= MOD;
				}
				C[i][j] = (int)sum;
			}
		}
		return C;
	}
	
	public static int[] mul(int[][] A, int[] v)
	{
		int m = A.length;
		int n = v.length;
		int[] w = new int[m];
		for(int i = 0;i < m;i++){
			long sum = 0;
			for(int k = 0;k < n;k++){
				sum += (long)A[i][k] * v[k];
				sum %= MOD;
			}
			w[i] = (int)sum;
		}
		return w;
	}
	
	void run() throws Exception
	{
		in = oj ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new D2().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}