//package round139;
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
		int n = ni(), m = ni(), x = ni(), y = ni();
		char[][] b = new char[n][];
		for(int i = 0;i < n;i++){
			b[i] = ns(m);
		}
		
		int I = 1000001;
		int[][][] dp = new int[m+1][m+1][2];
		for(int i = 0;i <= m;i++){
			for(int j = 0;j <= m;j++){
				dp[i][j][0] = dp[i][j][1] = I;
			}
		}
		int[] nt = new int[m];
		for(int i = 0;i < m;i++){
			for(int j = 0;j < n;j++){
				if(b[j][i] == '#'){
					nt[i]++;
				}
			}
		}
		
		dp[0][0][0] = 0;
		dp[0][0][1] = 0;
		for(int j = 0;j < m;j++){
			for(int i = 0;i <= m;i++){
				if(i >= x && i <= y){
					dp[j+1][1][0] = Math.min(dp[j+1][1][0], dp[j][i][1]+nt[j]);
					dp[j+1][1][1] = Math.min(dp[j+1][1][1], dp[j][i][0]+n-nt[j]);
				}
				if(i+1 <= m){
					dp[j+1][i+1][1] = Math.min(dp[j+1][i+1][1], dp[j][i][1]+n-nt[j]);
					dp[j+1][i+1][0] = Math.min(dp[j+1][i+1][0], dp[j][i][0]+nt[j]);
				}
			}
		}
		
		int ret = Integer.MAX_VALUE;
		for(int i = x;i <= y;i++){
			if(i <= m){
				ret = Math.min(ret, dp[m][i][0]);
				ret = Math.min(ret, dp[m][i][1]);
			}
		}
		out.println(ret);
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