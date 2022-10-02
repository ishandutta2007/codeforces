//package round118;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class D2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int t = ni();
		for(int i = 0;i < t;i++){
			int k = ni();
			long l = nl(), r = nl();
			int p = ni();
			
			if(p == 2 && k % 2 == 1){
				out.println(0);
			}else{
//				long x = 0;
//				if(l >= 33){
//					x = modpow(k, modpow(2, l, p-1) + (33/(p-1)+1)*(p-1), p);
//				}else{
//					x = modpow(k, 1L<<l, p);
//				}
				long x = modpow(k, modpow(2, l, p-1) + (33/(p-1)+1)*(p-1), p);
				
				long sup, y = 0;
				if(x == 1){
					y = modpow(2, r-l+1, p);
				}else{
					sup = (modpow(2, r-l+1, p-1)+p-1-1) % (p-1);
					y = summod(x, sup, p);
				}
				if(k % 2 == 1){
					y = y * modpow(inv(2, p), r-l, p) % p;
				}
				out.println(y);
			}
		}
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
	
	public long summod(long a, long n, long mod)
	{
		long smul = 1;
		long mul = a % mod;
		long ret = 0;
		for(n++;n > 0;n >>>= 1){
			if((n&1)==1){
				ret = (ret * mul + smul) % mod;
			}
			smul = smul * (mul + 1) % mod;
			mul = mul * mul % mod;
		}
		return ret;
	}
	
	public static int gcd(int a, int b) {
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
	
	public static void main(String[] args) throws Exception
	{
		new D2().run();
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