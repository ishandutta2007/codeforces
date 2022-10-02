//package round97;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "1000000 1000000000";
//	String INPUT = "2 139";
//	String INPUT = "2 139";
	int mod = 1000000007;
	
	long[] PS = new long[1000002];
	long[] IPS = new long[1000002];
	long[] KE = new long[1000002];
	long[] KE2 = new long[1000020];
	
	void solve()
	{
		int k = ni(), w = ni();
		long sum = 0;
		PS[0] = 1;
		IPS[0] = 1;
		KE[0] = modpow(k, w, mod);
		KE2[0] = modpow(k, w+4, mod);
		long ik = inv(k, mod);
		for(int i = 1;i <= k+1;i++){
			PS[i] = PS[i-1]*(k-i+1)%mod;
			IPS[i] = IPS[i-1]*inv(k-i+1, mod)%mod;
			KE[i] = KE[i-1] * k % mod;
		}
		for(int i = 1;i <= k+19;i++){
			KE2[i] = KE2[i-1] * ik % mod;
		}
		gw = w;
		for(int l = w+1;l <= w+k;l++){
			long v = (val(k, w, l) - val(k, w+1, l)) % mod;
			sum += v;
//			tr(l, v);
		}
		out.println((sum%mod+mod)%mod);
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
	
	int gw;
	
	// k=2,W=2,L=3
	// 8
	
	int gct = 0;
	// 
	// OXO
	long val(long k, long W, long L)
	{
		if(W >= L)return 0;
		// head
		// tail
		// 2W-L+2=W+2-(L-W)
		long ret;
		if(W > L+1-W){
//			ret = modpow(k, L, mod) - modpow(k, L-2*(L-W+1), mod) * modpow(P(k, L-W+1), 2, mod)%mod;
			ret = KE[(int)(L-gw)] - KE2[(int)(gw+4-(L-2*(L-W+1)))] * modpow(P(k, L-W+1), 2, mod)%mod;
		}else{
			long p = k-(L-2*(W-1)) < W-1 ? 0 : P(k, (L-2*(W-1))+(W-1))*invP(k, L-2*(W-1))%mod;
//			ret = modpow(k, L, mod) - P(k,L-2*(W-1))*modpow(p, 2, mod)%mod;
			ret = KE[(int)(L-gw)] - P(k,L-2*(W-1))*modpow(p, 2, mod)%mod;
		}
		
		return (int)((ret%mod+mod)%mod);
	}
	
	long P(long n, long r)
	{
		if(r > n)return 0;
		return PS[(int)r];
	}
	
	long invP(long n, long r)
	{
		if(r > n)return 0;
		return IPS[(int)r];
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
		new E2().run();
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