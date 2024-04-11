//package round144;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		long m = nl();
		int K = ni();
		
		int mod = 1000000007;
		int[][] C = new int[n+1][n+1];
		for(int i = 0;i <= n;i++){
			C[i][0] = 1;
			for(int j = 1;j <= i;j++){
				C[i][j] = (C[i-1][j] + C[i-1][j-1])%mod;
			}
		}
		long L = m / n+1;
		long S = m / n;
		long[][] dp = new long[n+1][K+1];
		dp[0][0] = 1;
		
		long[] ll = new long[n+1];
		long[] ss = new long[n+1];
		for(int i = 0;i <= n;i++){
			ss[i] = modpow(C[n][i], S, mod);
			ll[i] = ss[i]*C[n][i]%mod;
		}
		
		int i = 0;
		for(;i < m%n;i++){
			for(int j = 0;j <= K;j++){
				for(int k = 0;k <= n && k <= j;k++){
					dp[i+1][j] += dp[i][j-k] * ll[k] % mod;
				}
				dp[i+1][j] %= mod;
			}
		}
		for(;i < n;i++){
			for(int j = 0;j <= K;j++){
				for(int k = 0;k <= n && k <= j;k++){
					dp[i+1][j] += dp[i][j-k] * ss[k] % mod;
				}
				dp[i+1][j] %= mod;
			}
		}
		out.println(dp[n][K]);
	}
	
	
	// int*
	public static int[] mul(int[] A, int[] v, int mod)
	{
		int m = A.length;
		int n = v.length;
		int[] w = new int[m];
		for(int i = 0;i < m;i++){
			long sum = 0;
			for(int k = i;k < n;k++){
				sum += (long)A[k-i] * v[k];
				sum %= mod;
			}
			w[i] = (int)sum;
		}
		return w;
	}
	
	// A^e*v
	public static int[] pow(int[] A, int[] v, long e, int mod)
	{
		int[] MUL = A;
		for(int i = 0;i < v.length;i++)v[i] %= mod;
		for(;e > 0;e>>>=1) {
			if((e&1)==1)v = mul(MUL, v, mod);
			MUL = p2tu(MUL, mod);
		}
		return v;
	}
	
	static int[] p2tu(int[] A, int mod)
	{
		int n = A.length;
		int[] C = new int[n];
		for(int i = 0;i < n;i++){
			long sum = 0;
			for(int j = 0;j <= i;j++){
				sum += (long)A[j] * A[i-j];
				sum %= mod;
			}
			C[i] = (int)sum;
		}
		return C;
	}
	
	public static long modpow(long a, long n, long mod)
	{
		long ret = 1;
		long mul = a;
		for(;n > 0;n >>>= 1){
			if((n&1)==1){
				ret = (ret * mul) % mod;
			}
			mul = (mul * mul) % mod;
		}
		return ret;
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