//package round129;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), K = ni();
		int mod = 1000000007;
		char[] str = ns(n);
		
		int[] b = new int[n];
		{
			int[] dp = new int[n+1];
			dp[0] = 1;
			int sum = 1;
			int ep = 0;
			for(int i = 1;i <= n;i++){
				if(str[i-1] == 'B'){
				}else if(str[i-1] == 'W'){
					dp[i] = sum;
					for(int j = ep;j < i;j++){
						dp[j] = 0;
					}
					ep = i;
				}else{
					dp[i] = sum;
					sum = sum * 2 % mod;
				}
				if(i-K >= 0){
					b[i-1] = dp[i-K];
					sum = (sum + mod - dp[i-K]) % mod;
					dp[i-K] = 0;
				}
			}
		}
		
		int[] w = new int[n];
		{
			int[] dp = new int[n+1];
			dp[0] = 1;
			int sum = 1;
			int ep = 0;
			for(int i = 1;i <= n;i++){
				if(str[n-i] == 'W'){
				}else if(str[n-i] == 'B'){
					dp[i] = sum;
					for(int j = ep;j < i;j++){
						dp[j] = 0;
					}
					ep = i;
				}else{
					dp[i] = sum;
					sum = sum * 2 % mod;
				}
				if(i-K >= 0){
					w[n-i] = dp[i-K];
					sum = (sum + mod - dp[i-K]) % mod;
					dp[i-K] = 0;
				}
			}
		}
		
		int[] ws = new int[n+1];
		for(int i = n-1;i >= 0;i--){
			ws[i] = (ws[i+1] + w[i]) % mod;
		}
		
		long im = inv(2, mod);
		long[] tf = new long[n+1];
		long[] tb = new long[n+1];
		int two = 1;
		tf[0] = 1;
		tb[n] = 1;
		for(int i = 0;i < n;i++){
			tf[i+1] = str[i] == 'X' ? tf[i] * im % mod : tf[i];
			tb[n-1-i] = str[n-1-i] == 'X' ? tb[n-i] * im % mod : tb[n-i];
			if(str[i] == 'X')two = two * 2 % mod;
		}
		long wsum = 0;
		for(int i = 0;i < n;i++){
			b[i] = (int)(b[i] * tf[i+1] % mod);
			w[i] = (int)(w[i] * tb[i] % mod);
			wsum += w[i];
		}
		wsum %= mod;
		
		long ret = 0;
		for(int i = 0;i < n;i++){
			wsum = (wsum + mod - w[i]) % mod;
			ret += wsum * b[i] % mod * two % mod;
		}
		out.println(ret % mod);
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
//		int n = 1000000;
//		Random gen = new Random();
//		int K = gen.nextInt(10)+1;
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(K + " ");
//		for(int i = 0;i < n;i++){
//			sb.append("XBW".charAt(gen.nextInt(3)));
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
		new D().run();
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