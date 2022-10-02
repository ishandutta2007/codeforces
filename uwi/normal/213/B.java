//package round131;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	int mod = 1000000007;
	
	void solve()
	{
		int n = ni();
		int[] a = new int[10];
		for(int i = 0;i < 10;i++)a[i] = ni();
		
		int[] f = new int[103];
		int[] invf = new int[103];
		f[0] = 1;
		invf[0] = 1;
		for(int i = 1;i <= 102;i++){
			f[i] = (int)((long)f[i-1] * i % mod);
			invf[i] = (int)inv(f[i], mod);
		}
		
		long[][] dp = new long[10][n+1];
		dp[0][0] = 1;
		for(int i = 1;i <= 9;i++){
			for(int j = 0;j <= n;j++){
				for(int k = a[i];j+k <= n;k++){
					dp[i][j+k] = (dp[i][j+k] + dp[i-1][j] * invf[k]) % mod;
				}
			}
		}
		for(int j = 0;j <= n;j++){
			dp[9][j] = dp[9][j] * f[j] % mod;
		}
		tr(dp[9]);
		
		long s = 0;
		for(int j = 1;j <= n;j++){
			for(int k = a[0];k+j <= n;k++){
				// C(k+j-1,k)
				s += dp[9][j]*f[k+j-1]%mod*invf[j-1]%mod*invf[k]%mod;
			}
		}
		out.println(s%mod);
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
		new B().run();
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