//package round27;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class E {
	private Scanner in;
	private PrintWriter out;
	private String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		int[] primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
		out.println(rec(n, primes, 0, 9999));
	}
	
	public long rec(int n, int[] primes, int pos, int sup)
	{
		if(n == 1)return 1L;
		
		long min = (long)1E18 + 1;
		long mul = primes[pos];
		for(int i = 2;i <= n && i <= sup && mul <= 1E18;i++){
			if(n % i == 0){
				long v = rec(n / i, primes, pos + 1, i);
				if(v > 0){
					if(Math.log10(mul) + Math.log10(v) <= 18){
						min = Math.min(min, mul * v);
					}
				}
			}
			mul *= primes[pos];
		}
		if(min == (long)1E18 + 1)return 0;
		return min;
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
		new E().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private void tr(Object... o) { if(INPUT.length() == 0)System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
}