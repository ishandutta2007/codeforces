//package round53;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	static int[] primes = sieveEratosthenes(100002);
	
	static long MOD = 1000000007;
	
	void solve()
	{
		int n = ni();
		out.println((2*C(2*n-1, n-1)-n)%MOD);
	}
	
	public static int[] sieveEratosthenes(int n)
	{
		int[] ret = new int[(int)(n / Math.log(n)) + (int)(n / (Math.log(n)*Math.log(n))*1.5)  ];
		ret[0] = 2;
		int pos = 1;
		
		// 0:3 1:5
		// 2x+3=n
		BitSet bs = new BitSet(n/2+1);
		int sup = (n - 3) / 2;
		for(int i = bs.nextClearBit(0);i <= sup; i = bs.nextClearBit(i+1)){
			int p = 2 * i + 3;
			ret[pos++] = p;
			for(int j = i + p;j <= sup;j += p){
				bs.set(j);
			}
		}
		
		return Arrays.copyOf(ret, pos);
	}
	
	public static long C(int n, int r)
	{
		if(n < 0 || r < 0 || r > n)return 0;
		if(r > n / 2)r = n - r;
		int[] a = new int[n];
		for(int i = 0;i < r;i++)a[i] = n-i;
		
		for(int p : primes){
			if(p > r)break;
			for(int q = p;q <= r;q *= p){
				int m = n % q;
				for(int i = m, j = 0;j < r / q;i+=q,j++){
					a[i] /= p;
				}
			}
		}
		
		long mul = 1;
		for(int i = 0;i < r;i++){
			mul *= a[i];
			mul %= MOD;
		}
		return mul;
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
		new C().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}