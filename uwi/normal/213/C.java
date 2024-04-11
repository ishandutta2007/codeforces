//package round131;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class C3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[][] a = new int[n][n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				a[i][j] = ni();
			}
		}
		
		int[][][] dp = new int[2][n][n];
		int cur = 1, pre = 0;
		for(int i = 0;i < n;i++){
			Arrays.fill(dp[0][i], -99999999);
		}
		dp[0][0][0] = a[0][0];
		for(int i = 1;i <= 2*n-2;i++,cur^=1,pre^=1){
			for(int j = 0;j < n;j++){
				Arrays.fill(dp[cur][j], -99999999);
			}
			int u = Math.min(i,n-1);
			int w = Math.min(i-1,n-1);
			for(int j = Math.max(i-(n-1), 0);j <= u;j++){
				for(int k = j;k <= u;k++){
					int v = -99999999;
					if(j-1 >= 0)v = Math.max(v, dp[pre][j-1][k-1]);
					if(j-1 >= 0 && k <= w)v = Math.max(v, dp[pre][j-1][k]);
					if(j <= k-1)v = Math.max(v, dp[pre][j][k-1]);
					if(k <= w)v = Math.max(v, dp[pre][j][k]);
					if(j == k){
						dp[cur][j][k] = v + a[j][i-j];
					}else{
						dp[cur][j][k] = v + a[j][i-j] + a[k][i-k];
					}
				}
			}
//			tr(dp[cur]);
		}
		out.println(dp[pre][n-1][n-1]);
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
		new C3().run();
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