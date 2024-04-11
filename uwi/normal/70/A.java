//package round64;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	int MOD = 1000003;
	
	void solve()
	{
		int n = ni();
		if(n == 1){
			out.println(1);
		}else{
			out.println(modpow(3, n-1, MOD));
		}
	}
//		if(n == 0){
//			out.println(0);
//			return;
//		}
//
//		long ret = modpow(2, 2*n, MOD) - f(n);
//		int p = 1;
//		for(int i = n-1;i >= 1;i--){
//			ret -= (f(i) * p) % MOD;
//			p = (p * 3) % MOD;
//		}
//
//		out.println((ret % MOD + MOD) % MOD);
//	}
//
//	long f(int n)
//	{
//		return modpow(2, 2*n-1,MOD)+modpow(2, n-1,MOD);
//	}
	
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
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new A().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}