//package round26;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.MathContext;
import java.util.Arrays;
import java.util.Scanner;

public class D {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "100000 100000 10";
//	private String INPUT = "0 5 5";
	private String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		int m = ni();
		int k = ni();

		
		if(k + n - m < 0){
			out.println(0);
			return;
		}
		
		// C(8
		// C(1+i,i)*C(6-i,1-i)
		// C(1,0)*C(6,1)+C(2,1)*C(5,0)
		// C(k+i,i)*C(n+m-2k-1+k-i,k-i)
		// 
		// C(M+i,i)*C(N+k-i,k-i)(M+N+1)*k(M,i)-(M+1,i)
		// C(M+N+1+k,k)
		// C(k+n+m-2k-1+1+k,k)=C(m+n,k)
		
		// (m+n)!/(m-1-k)!(n+k+1)!
		// (m+n)!/k!(m+n-k)!
		// ----------------
		// (m+n)!/m!/n!
		// 
		// m!n!/(m-k)!(n+k)!
//		BigInteger den = CX(m + n, n);
//		BigInteger num = CX(m - n - 2 * k - 1, k);
//		tr(m,n,m-1-k,n+k+1);
//		out.printf("%1.8f\n", 1.0 - fact(m).multiply(fact(n)).divide(fact(m-1-k), MathContext.DECIMAL128).divide(fact(n+k+1), MathContext.DECIMAL128).doubleValue());
//		out.printf("%1.8f\n", 1.0 - new BigDecimal(fact(m).multiply(fact(n))).divide(new BigDecimal(fact(m-1-k).multiply(fact(n+k+1))), MathContext.DECIMAL128).doubleValue());
		BigInteger num = BigInteger.ONE;
		BigInteger den = BigInteger.ONE;
		for(int i = 0;i <= k;i++){
			num = num.multiply(bi(m - i));
			den = den.multiply(bi(n + i + 1));
		}
		out.printf("%1.8f\n", 1.0 - new BigDecimal(num).divide(new BigDecimal(den), MathContext.DECIMAL128).doubleValue());
	}
	
	public BigInteger bi(long n){ return BigInteger.valueOf(n); };
	public BigDecimal bd(double n){ return BigDecimal.valueOf(n); };
	
//	public BigInteger C(int n, int k)
//	{
//		if(k > n - k)k = n - k;
//		BigInteger ret = BigInteger.ONE;
//		for(int i = 1;i <= k;i++){
//			ret = ret.multiply(BigInteger.valueOf(n - i + 1));
//			ret = ret.divide(BigInteger.valueOf(i));
//		}
//		return ret;
////		return fact[n].divide(fact[n - k]).divide(fact[k]);
//	}
	
//	public BigInteger fact(int n)
//	{
//		BigInteger ret = BigInteger.ONE;
//		for(int i = 2;i <= n;i++){
//			if(i%1000==0)tr(i);
//			ret = ret.multiply(bi(i));
//		}
//		return ret;
//	}
	public BigDecimal fact(int n)
	{
//		tr(n);
		if(n <= 0)return BigDecimal.ONE;
		if(n <= 1000){
			BigInteger ret = BigInteger.ONE;
			for(int i = 2;i <= n;i++){
				ret = ret.multiply(bi(i));
			}
			return new BigDecimal(ret);
		}
//		return Math.sqrt(2 * Math.PI * n) * Math.pow((double)n / Math.E, n) * (1f + 1f / (12 * n) + 1f / (288L * n * n) - 139f / (51840L * n * n * n));
		return BigDecimal.valueOf(Math.sqrt(2 * Math.PI * n) * (1f + 1f / (12 * n) + 1f / (288L * n * n) - 139f / (51840L * n * n * n))).multiply
		(BigDecimal.valueOf((double)n / Math.E).pow(n, MathContext.DECIMAL128));
	}
	
//	public BigInteger CX(int n, int k)
//	{
//		return fact(n).divide(fact(n - k), MathContext.DECIMAL128).divide(fact(k), MathContext.DECIMAL128).toBigInteger();
//	}
	
	public BigInteger C(int n, int k)
	{
		if(n < 0 || k < 0 || k > n)tr(n, k);
		if(k > n - k)k = n - k;
		if(k == 0)return BigInteger.ONE;
		if(k == 1)return BigInteger.valueOf(n);
		
		int[] num = new int[k];
		int[] den = new int[k];
		for(int i = 0;i < k;i++){
			num[i] = n - k + i + 1;
			den[i] = i + 1;
		}
		for(int p = 2;p <= k;p++){
			if(den[p - 1] > 1){
				int off = (n - k) % p;
				for(int i = p - 1;i < k;i+=p){
					num[i - off] /= den[p-1];
					den[i] /= den[p-1];
				}
			}
		}
		
		BigInteger ret = BigInteger.ONE;
		for(int v : num){
			if(v > 1)ret = ret.multiply(BigInteger.valueOf(v));
		}
		return ret;
	}
	
	public void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new D().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private void tr(Object... o) { if(INPUT.length() > 0)System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
}