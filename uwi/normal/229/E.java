//package round142;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] a = new int[m][];
		int all = 0;
		for(int i = 0;i < m;i++){
			int L = ni();
			all += L;
			a[i] = new int[L];
			for(int j = 0;j < L;j++){
				a[i][j] = ni();
			}
			Arrays.sort(a[i]);
		}
		
		int[] pr = new int[all];
		int p = 0;
		for(int i = 0;i < m;i++){
			for(int j = 0;j < a[i].length;j++){
				pr[p++] = a[i][j];
			}
		}
		Arrays.sort(pr);
		int tie = pr[all-1-n+1];
		int[][] info = new int[m][3];
		for(int i = 0;i < m;i++){
			info[i][2] = a[i].length;
			for(int j = 0;j < a[i].length;j++){
				if(a[i][j] > tie)info[i][0]++;
				if(a[i][j] == tie)info[i][1]++;
			}
		}
		
		double[][] C = new double[1001][1001];
		for(int i = 0;i <= 1000;i++){
			C[i][0] = 1;
			for(int j = 1;j <= i;j++){
				C[i][j] = C[i-1][j] + C[i-1][j-1];
			}
		}
		
		double[][] dp = new double[m+1][n+1];
		double[][] ep = new double[m+1][n+1];
		dp[0][0] = 1;
		ep[0][0] = 1;
		for(int i = 0;i < m;i++){
			for(int j = 0;j <= n;j++){
				if(dp[i][j] > 0){
					for(int k = info[i][0];k <= info[i][0]+info[i][1] && j+k <= n;k++){
						dp[i+1][j+k] += dp[i][j]*C[info[i][1]][k-info[i][0]]/C[info[i][2]][k];
						ep[i+1][j+k] += ep[i][j];
					}
				}
			}
		}
		
		out.printf("%.9f\n", dp[m][n] / ep[m][n]);
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
	
	public static void main(String[] args) throws Exception
	{
		new E2().run();
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