//package round88;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "4 1 10000\r\n" + 
			"3 3 2 2\r\n" + 
			"2 4 1 3\r\n" + 
			"1 2 2 4\r\n" + 
			"2 3 3 5\r\n" + 
			"1 3 3 4";
	
	void solve()
	{
		long n = nl();
		int m = ni();
		long mod = nl();
		
		for(int i = 0;i < m;i++){
			long l = nl() - 1;
			long r = nl() - 1;
			long u = nl() - 1;
			long v = nl() - 1;
			long[] res = rec(l, r, u, v, n, mod);
			out.println((res[0] + res[1]) % mod);
		}
	}
	
	long[] rec(long l, long r, long u, long v, long n, long mod)
	{
		if(u > v || n == 0)return new long[]{0L, 0L};
//		tr(l, r, u, v, n);
		if(l == 0 && r == n-1){
			long low = Math.max(u, 0);
			long high = Math.min(v, n-1);
			if(low > high)return new long[]{0L, 0L};
			long hh = high%2 == 0 ? ((high/2)%mod)*((high+1)%mod)%mod : (high%mod)*((high+1)/2%mod)%mod;
			long ll = low%2 == 0 ? ((low/2)%mod)*((low-1)%mod)%mod : (low%mod)*((low-1)/2%mod)%mod;
//			tr(l, r, low, high, ll, hh);
			return new long[]{((hh-ll)%mod+mod)%mod, (high-low+1)%mod};
		}
		
		long mid = (n+1)/2;
		long[] ret = new long[2];
		if(l <= mid-1){
			if(u == v && u % 2 == 1){
			}else{
				long[] res = rec(l, Math.min(mid-1, r), (u+1)/2, v/2, mid, mod);
				ret[0] += res[0]*2%mod;
				ret[1] += res[1];
			}
		}
		if(r >= mid){
			if(u == v && u % 2 == 0){
			}else{
				long[] res = rec(Math.max(mid, l)-mid, r-mid, u/2, (v-1)/2, n-mid, mod);
				ret[0] += (res[0]*2+res[1])%mod;
				ret[1] += res[1];
			}
		}
//		tr(ret);
		ret[0] %= mod;
		ret[1] %= mod;
		return ret;
	}
	
	void run() throws Exception
	{
//		int n = 100000;
//		StringBuilder sb = new StringBuilder("1000000000000000000 100000 1000000000 ");
//		Random r = new Random();
//		for(int i = 0;i < 2*n;i++){
//			long a = Math.abs(r.nextLong() % 1000000000000000000L);
//			long b = Math.abs(r.nextLong() % 1000000000000000000L);
//			if(a > b){
//				long d = a; a = b; b = d;
//			}
//			a++; b++;
//			sb.append(a + " " + b + " ");
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
	
	public String nline()
	{
		try{
			int b = 0;
			StringBuilder sb = new StringBuilder();
			while((b = is.read()) != -1 && (b == '\r' || b == '\n'));
			if(b == -1)return "";
			sb.append((char)b);
			while(true){
				b = is.read();
				if(b == -1)return sb.toString();
				if(b == '\r' || b == '\n')return sb.toString();
				sb.append((char)b);
			}
		} catch (IOException e) {
		}
		return "";
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
	
	double nd() { return Double.parseDouble(ns()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}