//package round72;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class D {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int a = ni();
		int b = ni();
		int k = ni();
		for(int i = 2;i * i <= k;i++){
			if(k % i == 0){
				out.println(0);
				return;
			}
		}
		if(k <= 45000){
			seed = new int[5000000];
			mo = new int[5000000];
			seed[0] = 1;
			mo[0] = 1;
			int q = 1;
			for(int p : primes){
				if(p >= k)break;
				int l = q;
				for(int i = 0;i < l;i++){
					long v = (long)seed[i] * p;
					if(v < Integer.MAX_VALUE / k){
						seed[q] = (int)v;
						mo[q] = -mo[i];
						q++;
					}
				}
			}
			seed = Arrays.copyOf(seed, q);
			mo = Arrays.copyOf(mo, q);
		}
		
//		tr(primes.length);
		out.println(count(b, k) - count(a-1, k));
	}
	
	int[] seed;
	int[] mo;
	int[] primes = sieveEratosthenes(50000);
	
	int count(long n, long k)
	{
		if(n < k)return 0;
		if(n < k * k)return 1;
		long q = n / k;
		int ct = 0;
		for(int i = 0;i < seed.length;i++){
			ct += q / seed[i] * mo[i];
		}
		return ct;
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
	
	void run() throws Exception
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
	
	int ni() { return Integer.parseInt(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}