//package round257;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int mod = 1000000007;
		int Q = 1000000;
		
		long[] dp = new long[Q+1];
		long[] dp1 = new long[Q+1];
		long[] dp2 = new long[Q+1];
		int[] lpf = enumLowestPrimeFactors(Q);
		for(int i = 1;i <= Q;i++){
			int[] divs = enumDivisorsFast(i, lpf);
			Arrays.sort(divs);
			int[] nums = new int[divs.length];
			for(int j = divs.length-1;j >= 0;j--){
				nums[j] = i/divs[j];
				for(int k = j+1;k < divs.length;k++){
					if(divs[k] % divs[j] == 0)nums[j] -= nums[k];
				}
			}
			long val = 0;
			for(int j = 0;j < divs.length;j++){
				val += (long)nums[j]*divs[j];
			}
			val %= mod;
			
			dp[i] = dp[i-1] + val;
			dp1[i] = dp1[i-1] + val*i;
			dp2[i] = dp2[i-1] + val*i%mod*i;
			dp2[i] %= mod;
			dp1[i] %= mod;
			if(dp[i] >= mod)dp[i] -= mod;
		}
//		tr(dp);
//		tr(dp1);
//		tr(dp2);
		
		for(int T = ni();T >= 1;T--){
			long n = ni(), m = ni();
			if(n > m){
				long d = n; n = m; m = d;
			}
			
			long A = -n*(n+1)*(n+2);
			long B = -6*m*(n*n-3*n-3)+4*n*n*n-12*n*n-7*n+15;
			
			// 180=2^2*3^2*5
			if(A % 2 == 0){A /= 2;}else{B /= 2;}
			if(A % 2 == 0){A /= 2;}else{B /= 2;}
			if(A % 3 == 0){A /= 3;}else{B /= 3;}
			if(A % 3 == 0){A /= 3;}else{B /= 3;}
			if(A % 5 == 0){A /= 5;}else{B /= 5;}
			A %= mod;
			B %= mod;
			
			long ret = A*B%mod;
			ret += 
					2*(n+1)*(m+1)%mod*dp[(int)n] -
					2*((n+1)+(m+1))*dp1[(int)n] +
					2*dp2[(int)n];
			ret %= mod;
			if(ret < 0)ret += mod;
			out.println(ret);
		}
	}
	
	public static int[] enumLowestPrimeFactors(int n)
	{
		int[] a = new int[n+1];
		for(int p = 2;p <= n;p++){
			if(a[p] == 0){
				for(int q = p;q <= n;q+=p)if(a[q] == 0)a[q] = p;
			}
		}
		return a;
	}
	
	public static int[] enumDivisorsFast(int n, int[] lpf)
	{
		int[] divs = {1};
		while(lpf[n] > 0){
			int p = lpf[n];
			int e = 0;
			for(;p == lpf[n];e++, n /= p);
			int olen = divs.length;
			divs = Arrays.copyOf(divs, olen*(e+1));
			for(int i = olen;i < divs.length;i++)divs[i] = divs[i-olen] * p;
		}
		return divs;
	}
	
	public static int gcd(int a, int b) {
		if(a == 0)return b;
		if(b == 0)return a;
		while (b > 0){
			int c = a;
			a = b;
			b = c % b;
		}
		return a;
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
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
	private byte[] inbuf = new byte[1024];
	private int lenbuf = 0, ptrbuf = 0;
	
	private int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
	
	private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
	private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
	
	private double nd() { return Double.parseDouble(ns()); }
	private char nc() { return (char)skip(); }
	
	private String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	private char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
	
	private char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}
	
	private int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}
	
	private int ni()
	{
		int num = 0, b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private long nl()
	{
		long num = 0;
		int b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}