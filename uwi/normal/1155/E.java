//package educational.round63;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class E {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	long f(int x)
	{
		out.println("? " + x);
		out.flush();
		return ni();
	}
	
	void solve()
	{
		long[] ys = new long[11];
		for(int i = 0;i <= 10;i++){
			ys[i] = f(i);
		}
		int mod = 1000003;
		long[] g = guess(mod, ys);
		for(int i = 0;i < mod;i++){
			if(f(i, mod, g) == 0){
				out.println("! " + i);
				out.flush();
				return;
			}
		}
		out.println("! -1");
		out.flush();
	}
	
	public static long f(long x, long mod, long[] f)
	{
		long ret = 0;
		for(int i = f.length-1;i >= 0;i--)ret = (ret * x + f[i]) % mod;
		return ret;
	}

	
	public static long[] guess(long mod, long... y)
	{
		int n = y.length;
		long[] dp = new long[n+1];
		dp[0] = 1;
		// (x-x0)(x-x1)...(x-x{n-1})
		for(int i = 0;i < n;i++){
			for(int j = i;j >= 0;j--){
				dp[j+1] += dp[j];
				if(dp[j+1] >= mod)dp[j+1] -= mod;
				dp[j] = dp[j]*-i%mod;
				if(dp[j] < 0)dp[j] += mod;
			}
		}
		
		long[] f = new long[n+1];
		f[0] = 1;
		for(int i = 1;i <= n;i++)f[i] = f[i-1] * i % mod;
		
		long[] ret = new long[n];
		for(int i = 0;i < n;i++){
			long den = f[i]*f[n-1-i]%mod; // (-1)^(n-1-i)*i!*(n-1-i)!
			if(((i^n-1)&1) == 1){
				den = mod - den;
			}
			long iden = invl(den, mod) * y[i] % mod;
			
			long minus = 0;
			for(int j = n-1;j >= 0;j--){
				minus = (dp[j+1] + minus * i) % mod;
				ret[j] = (ret[j] + minus*iden)%mod;
			}
		}
		return ret;
	}
	
	public static long invl(long a, long mod) {
		long b = mod;
		long p = 1, q = 0;
		while (b > 0) {
			long c = a / b;
			long d;
			d = a;
			a = b;
			b = d % b;
			d = p;
			p = q;
			q = d - c * q;
		}
		return p < 0 ? p + mod : p;
	}

	
	void run() throws Exception
	{
		in = oj ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new E().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}