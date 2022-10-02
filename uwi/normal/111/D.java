//package round85;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class D {
	Scanner in;
	PrintWriter out;
	String INPUT = "3 2 2";
	int mod = 1000000007;
	
	// 1k^n
	// 2i
	// \sum_i (C(k,i)F(n,i))^2
	// 31
	// |A|<=|A\cup C|=|B|, |B|<=|B\cup C|=|A|
	// |A|=|B|, C\in A\cup B
	// \sum_i (F(n,i)^2)\sum_p=1^i C(k,p)p^{n(m-2)}C(k-p,i-p)C(k-i,i-p)
	// C(k,p)C(k-p,i-p)C(k-i,i-p)
	// =k!/p!(i-p)!(k-2i+p)!(i-p)!
	// F(n,i)ni
	// F(n,i)=i^n-C(i,1)(i-1)^n+C(i,2)(i-2)^n-...
	// O(i)
	// O(k^2)
	// 
	// 
	
	void solve()
	{
		int n = ni();
		int m = ni();
		int K = ni();
		
		int q = Math.max(K, n);
		long[] A = new long[q+1];
		long[] IA = new long[q+1];
		A[0] = 1;
		IA[0] = 1;
		for(int i = 1;i <= q;i++){
			A[i] = A[i-1] * i % mod;
			IA[i] = inv(A[i], mod);
		}
		
		long[] I = new long[1001];
		long[] IM = new long[1001];
		for(int i = 0;i <= 1000;i++){
			I[i] = modpow(i, n, mod);
			IM[i] = modpow(i, n*(m-2), mod);
		}
		
		// F(n,i)=i^n-C(i,1)(i-1)^n+C(i,2)(i-2)^n-...
		long[] F = new long[n+1];
		for(int i = 0;i <= n;i++){
			long val = 0;
			long minus = 1;
			for(int j = i;j >= 0;j--){
				val += I[j] * minus * A[i]%mod*IA[i-j]%mod*IA[j] % mod;
				minus = -minus;
			}
			F[i] = (val%mod+mod)%mod;
		}
		
		if(m == 1){
			out.println(modpow(K, n, mod));
		}else if(m == 2){
			long sum = 0;
			for(int i = 1;i <= Math.min(K, n);i++){
				long cfm = A[K]*IA[i]%mod*IA[K-i]%mod*F[i]%mod;
				sum += cfm*cfm%mod;
			}
			out.println(sum%mod);
		}else{
			long sum = 0;
			// \sum_i (F(n,i)^2)\sum_p=1^i C(k,p)p^{n(m-2)}C(k-p,i-p)C(k-i,i-p)
			// =k!/p!(i-p)!(k-2i+p)!(i-p)!
			for(int i = 1;i <= Math.min(K, n);i++){
				long psum = 0;
				for(int p = 1;p <= i;p++){
					if(K-2*i+p >= 0){
						psum += A[K]*IA[p]%mod*IA[i-p]%mod*IA[i-p]%mod*IA[K-2*i+p]%mod*IM[p]%mod;
					}
				}
				psum%=mod;
				long all = F[i]*F[i]%mod*psum%mod;
				sum += all;
			}
			out.println(sum%mod);
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
		new D().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}