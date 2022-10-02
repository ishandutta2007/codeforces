//package round76;
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
		long n = nl();
		int k = ni();
		int[] a = new int[k];
		for(int i = 0;i < k;i++)a[i] = ni();
		Arrays.sort(a);
		if(a[0] == 1){
			out.println(0);
		}else{
			for(int p = 0, q = a.length-1;p < q;p++,q--) {
				int d = a[p]; a[p] = a[q]; a[q] = d;
			}
			for(int i = 0;i < 101;i++) {
				Arrays.fill(cache[i], -1);
			}
			out.println(rec(n, a, 0));
		}
//		tr(gct);
	}
	
	int M = 50000;
	long[][] cache = new long[101][M];
	int gct = 0;
	
	long rec(long n, int[] a, int pos)
	{
		if(n == 0)return 0;
		if(n < M && cache[pos][(int)n] != -1) {
			return cache[pos][(int)n];
		}
		long s = n;
		for(int i = a.length-1;i >= pos;i--){
			if(a[i] > n)break;
			s -= rec(n/a[i], a, i+1);
		}
		if(n < M) {
			cache[pos][(int)n] = s;
		}
		return s;
	}
	
	public static int[] sieveEratosthenes(int n) {
		int[] ret = new int[(int) (n / Math.log(n))
				+ (int) (n / (Math.log(n) * Math.log(n)) * 1.5)];
		ret[0] = 2;
		int pos = 1;

		// 0:3 1:5
		// 2x+3=n
		BitSet bs = new BitSet(n / 2 + 1);
		int sup = (n - 3) / 2;
		for(int i = bs.nextClearBit(0);i <= sup;i = bs.nextClearBit(i + 1)){
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
//		int[] primes = sieveEratosthenes(10000);
//		StringBuilder sb = new StringBuilder("10000000000000 100");
//		sb.append(" ");
//		for(int i = 0;i < 100;i++){
//			sb.append(primes[i] + " ");
//		}
//		tr(primes[99]);
//		INPUT = sb.toString();
//		
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