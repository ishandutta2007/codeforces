//package round152;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		
		double[][] dp = new double[n][];
		double E = 0;
		for(int i = 0;i < n;i++){
			dp[i] = new double[a[i]+1];
			dp[i][a[i]] = 1;
			E += dp[i][0];
		}
		int Q = ni();
		for(int i = 0;i < Q;i++){
			int u = ni()-1, v = ni()-1, k = ni();
			E -= dp[u][0];
			double den = c(a[u], k);
			for(int j = 0;j < dp[u].length;j++){
				double[] num1 = new double[k+1];
				num1[0] = 1;
				for(int l = 1;l <= k;l++){
					num1[l] = num1[l-1] * (j-l+1) / l;
				}
				double[] num2 = new double[k+1];
				num2[k] = 1;
				for(int l = k-1;l >= 1;l--){
					num2[l] = num2[l+1] * (a[u]-j-(k-l)+1) / (k-l);
				}
				
//				double cs = dp[u][j];
				for(int l = 1;l <= k;l++){
					if(j-l >= 0){
//						cs = cs * (j-l+1) / l * (a[u]-j-l+1) / (a[u]-j-k+l) / den;
						dp[u][j-l] += num1[l]*num2[l]/den*dp[u][j];
//						dp[u][j-l] += c(j, l)*c(a[u]-j, k-l)/c(a[u], k)*dp[u][j];
					}
				}
//				dp[u][j-0] = c(j, 0)*c(a[u]-j, k-0)/c(a[u], k)*dp[u][j];
				for(int l = 0;l < k;l++){
					dp[u][j] *= a[u]-j-l;
					dp[u][j] /= a[u]-l;
				}
//				dp[u][j-0] *= c(a[u]-j, k-0)/c(a[u], k);
			}
			E += dp[u][0];
			a[u] -= k;
			a[v] += k;
//			pd(E, 12);
//			out.println();
			out.println(tos(E, 12));
//			out.println(E);
//			out.printf("%.12f\n", E);
		}
	}
	
	static String tos(double x, int n)
	{
		StringBuilder sb = new StringBuilder();
		if(x < 0){
			sb.append("-");
			x = -x;
		}
		sb.append((int)x);
		sb.append(".");
		x -= (int)x;
		for(int i = 0;i < n;i++){
			x *= 10;
			sb.append((int)x);
			x -= (int)x;
		}
		return sb.toString();
	}
	
	double c(int n, int r)
	{
		if(n < 0 || r < 0 || n < r)return 0;
		
		double num = 1;
		double den = 1;
		for(int i = 1;i <= r;i++){
			num *= (n-i+1);
			den *= i;
		}
		return num/den;
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
		new C().run();
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