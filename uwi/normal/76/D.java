//package ausoi;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class D {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		BigInteger a = in.nextBigInteger();
		BigInteger b = in.nextBigInteger();
		if(a.compareTo(b) < 0){
			out.println(-1);
		}else if(a.subtract(b).testBit(0)){
			out.println(-1);
		}else{
			BigInteger x = a.subtract(b).shiftRight(1);
			BigInteger y = b.xor(x);
			if(x.add(y).equals(a)){
				out.println(x + " " + y);
			}else{
				out.println(-1);
			}
		}
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
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}