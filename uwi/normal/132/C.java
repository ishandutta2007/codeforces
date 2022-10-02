//package round96;
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
		char[] com = ns(100);
		int n = com.length;
		int m = ni();
		int[][][][] dp = new int[n+1][m+1][2][2]; // +- max min
		for(int i = 0;i <= n;i++){
			for(int j = 0;j <= m;j++){
				for(int k = 0;k < 2;k++){
					dp[i][j][k][0] = -99999;
					dp[i][j][k][1] = 99999;
				}
			}
		}
		
		dp[0][0][0][0] = 0;
		dp[0][0][0][1] = 0;
		dp[0][0][1][0] = 0;
		dp[0][0][1][1] = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j <= m;j++){
				for(int k = 0;k < 2;k++){
					// no change
					if(com[i] == 'F'){
						for(int l = j;l <= m;l+=2){
							dp[i+1][l][k][0] = Math.max(dp[i+1][l][k][0], dp[i][j][k][0] + (k == 0 ? 1 : -1));
							dp[i+1][l][k][1] = Math.min(dp[i+1][l][k][1], dp[i][j][k][1] + (k == 0 ? 1 : -1));
						}
					}else{
						for(int l = j;l <= m;l+=2){
							dp[i+1][l][1-k][0] = Math.max(dp[i+1][l][1-k][0], dp[i][j][k][0]);
							dp[i+1][l][1-k][1] = Math.min(dp[i+1][l][1-k][1], dp[i][j][k][1]);
						}
					}
					// change
					if(j < m){
						if(com[i] == 'F'){
							for(int l = j+1;l <= m;l+=2){
								dp[i+1][l][1-k][0] = Math.max(dp[i+1][l][1-k][0], dp[i][j][k][0]);
								dp[i+1][l][1-k][1] = Math.min(dp[i+1][l][1-k][1], dp[i][j][k][1]);
							}
						}else{
							for(int l = j+1;l <= m;l+=2){
								dp[i+1][l][k][0] = Math.max(dp[i+1][l][k][0], dp[i][j][k][0] + (k == 0 ? 1 : -1));
								dp[i+1][l][k][1] = Math.min(dp[i+1][l][k][1], dp[i][j][k][1] + (k == 0 ? 1 : -1));
							}
						}
					}
				}
			}
		}
		
		int max = 0;
		for(int j = m;j >= 0;j-=2){
			for(int k = 0;k < 2;k++){
				for(int l = 0;l < 2;l++){
					if(Math.abs(dp[n][m][k][l]) < 1000){
						max = Math.max(max, Math.abs(dp[n][m][k][l]));
					}
				}
			}
		}
		out.println(max);
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