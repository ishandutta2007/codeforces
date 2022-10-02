//package round66;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class E {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int x = ni();
		int[] a = new int[n];
		for(int i = 0;i < n;i++){
			a[i] = ni();
		}
		if(x == 2){
			out.println(0);
			return;
		}
		if(n == 0){
			out.println(-1);
			return;
		}
		Arrays.sort(a);
		if(a[0] == 1){
			out.println(1);
		}else if(x >= 2000000){
			out.println(-1);
		}else{
			int[] primes = sieveEratosthenes(x-1);
			int i, j;
			for(i = 0, j = 0;i < n && j < primes.length && primes[j] <= x-1;){
				if(a[i] == primes[j]){
					i++;
					j++;
				}else if(a[i] > primes[j]){
					out.println(-1);
					return;
				}else{
					i++;
				}
			}
			if(j == primes.length || primes[j] > x-1){
				out.println(j);
			}else{
				out.println(-1);
			}
		}
	}
	
	public static int[] sieveEratosthenes(int n)
	{
		int[] ret = new int[(int)(n / Math.log(n)) + (int)(n / (Math.log(n)*Math.log(n))*1.5)+100  ];
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
		new E().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}