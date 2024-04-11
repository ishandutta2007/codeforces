//package round86;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "3 5";
	int[] primes;
	
	void solve()
	{
		int N = 300000000;
//		int N = 30000;
		primes = sieveEratosthenes((int)Math.sqrt(N)+1);
		BitSet np = new BitSet();
		int l = ni();
		int r = ni();
		int ct = 0;
		int ll = (l-1+3)/4;
		int rr = (r-1)/4;
		for(int p : primes){
			if(p != 2){
				//4n+1=0(mod p)
				// -4n=1
				int i = (int)inv((-4)%p+p, p);
				if(i <= rr){
					if(4*i+1 != p){
						np.set(i);
					}
					for(int j = i+p;j <= rr;j+=p){
						np.set(j);
					}
				}
			}
			// p^2=4n+1
		}
		np.set(0);
		
		np.clear(0, ll);
//		np.clear(rr+1, m+1);
		ct = rr-ll+1-np.cardinality();
//		for(int i = np.nextClearBit(ll);i <= rr;i = np.nextClearBit(i+1)){
//			ct++;
//		}
		
		if(l <= 2 && r >= 2)ct++;
		out.println(ct);
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
	
	public static int[] sieveEratosthenes(int n)
	{
		int u = n+32;
		double lu = Math.log(u);
		int[] ret = new int[(int)(u/lu+u/lu/lu*1.5)];
		ret[0] = 2;
		int pos = 1;
		
		int[] isp = new int[(n+1)/32/2+1];
		int sup = (n+1)/32/2+1;
		
		int[] tprimes = {3,5,7,11,13,17,19,23,29,31};
		for(int tp : tprimes){
			ret[pos++] = tp;
			int[] ptn = new int[tp];
			for(int i = (tp-3)/2;i < tp<<5;i+=tp)ptn[i>>5] |= 1<<(i&31);
			for(int i = 0;i < tp;i++){
				for(int j = i;j < sup;j += tp)isp[j] |= ptn[i];
			}
		}
		
		// 3,5,7
		// 2x+3=n
		int[] magic = {0, 1, 23, 2, 29, 24, 19, 3, 30, 27, 25, 11, 20, 8, 4, 13, 31, 22, 28, 18, 26, 10, 7, 12, 21, 17, 9, 6, 16, 5, 15, 14};
		int h = n/2;
		for(int i = 0;i < sup;i++){
			for(int j = ~isp[i];j != 0;j &= j-1){
				int pp = i<<5|magic[(j&-j)*0x076be629>>>27];
				int p = 2*pp+3;
				if(p > n)break;
				ret[pos++] = p;
				for(int q = pp;q <= h;q += p)isp[q>>5] |= 1<<(q&31);
			}
		}
		
		return Arrays.copyOf(ret, pos);
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
		new C().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}