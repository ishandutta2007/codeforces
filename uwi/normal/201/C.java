//package round127;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class C {
	InputStream is;
	PrintWriter out;
//	String INPUT = "9 1 2 1 2 2 1 2 1";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = new int[n-1];
		long s = 0;
		for(int i = 0;i < n-1;i++){
			a[i] = ni();
			s += a[i];
		}
		int[] d = new int[n];
		for(int i = 0;i < n;i++){
			d[i] += i-1 >= 0 ? a[i-1] : 0;
			d[i] += i < n-1 ? a[i] : 0;
		}
		
		int[] f = new int[n];
		f[0] = d[0] % 2;
		for(int i = 1;i < n;i++){
			f[i] = (f[i-1] ^ d[i]) & 1;
		}
		
		int[][] dp = new int[n][3];
		if(d[0] % 2 == 1){
			dp[0][2] = 999999;
			dp[0][1] = 0;
			dp[0][0] = 1;
		}else{
			dp[0][2] = 999999;
			dp[0][1] = 999999;
			dp[0][0] = 0;
		}
		for(int i = 1;i < n;i++){
			for(int j = 0;j <= 2;j++){
				if(((f[i]^j)&1)==1){
					if(f[i] == f[i-1] && a[i-1] == 1 && !(i == 1 || i == n-1)){
						dp[i][j] = 999999;
					}else{
						dp[i][j] = dp[i-1][j] + 1;
					}
				}else{
					if(f[i] != f[i-1] && a[i-1] == 1 && !(i == 1 || i == n-1)){
						dp[i][j] = 999999;
					}else{
						dp[i][j] = dp[i-1][j];
					}
				}
				if(j-1 >= 0 && ((f[i]^(j-1))&1)==1 && f[i] != f[i-1]){
					dp[i][j] = Math.min(dp[i][j], dp[i-1][j-1]);
				}
			}
		}
		long ret = s - Math.min(dp[n-1][0], dp[n-1][2]);
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