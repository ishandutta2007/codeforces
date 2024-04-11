//package round78;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class B2 {
	Scanner in;
	PrintWriter out;
	String INPUT = "3";
	
	void solve()
	{
		long n = nl();
		int plus = 0;
		while(n%2==0){
			n>>>=1;
			plus++;
		}
		if(n == 1){
			out.println(plus + "/1");
			return;
		}
		
		// 1/n
		long cur = 1;
		int cycle = 1;
		BitSet bs = new BitSet();
		while(true){
			cur = cur * 2;
			if(cur >= n){
				cur -= n;
				bs.set(cycle);
				if(cur == 1)break;
			}
			cycle++;
		}
		// S=b/2^b+(b+c)/2^(b+c)+...
		// (1/2^c)S=b/2^(b+c)+..
		// (1-1/2^c)S=b/2^b+c/2^(b+c)+..
		// S=(b/2^b+c/2^(b+c)/(1-1/2^c))/(1-1/2^c)
		// =(b(2^c-1)+c)*2^c/(2^b*(2^c-1)^2)*n
		BigInteger num = BigInteger.ZERO;
		BigInteger c2 = BigInteger.ONE.shiftLeft(cycle);
		BigInteger c21 = c2.subtract(BigInteger.ONE);
		BigInteger den = c21.multiply(c21);
		for(int b = bs.nextSetBit(0);b != -1;b = bs.nextSetBit(b + 1)){
			num = num.add(bi(b).multiply(c21).add(bi(cycle)).shiftLeft(cycle-b));
		}
		num = num.multiply(bi(n));
		BigInteger g = num.gcd(den);
		num = num.divide(g);
		den = den.divide(g);
		num = num.add(den.multiply(bi(plus)));
		out.println(num + "/" + den);
	}
	
	BigInteger bi(long n)
	{
		return BigInteger.valueOf(n);
	}
	
	public static long gcd(long a, long b) {
		while (b > 0){
			long c = a;
			a = b;
			b = c % b;
		}
		return a;
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
		new B2().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}