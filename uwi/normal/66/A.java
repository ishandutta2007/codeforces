//package round61;

import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		BigInteger x = in.nextBigInteger();
		if(x.compareTo(BigInteger.valueOf(-128)) >= 0 && x.compareTo(BigInteger.valueOf(127)) <= 0){
			out.println("byte");
		}else if(x.compareTo(BigInteger.valueOf(-32768)) >= 0 && x.compareTo(BigInteger.valueOf(32767)) <= 0){
			out.println("short");
		}else if(x.compareTo(BigInteger.valueOf(-2147483648L)) >= 0 && x.compareTo(BigInteger.valueOf(2147483647L)) <= 0){
			out.println("int");
		}else if(x.compareTo(new BigInteger("-9223372036854775808")) >= 0 && x.compareTo(new BigInteger("9223372036854775807")) <= 0){
			out.println("long");
		}else{
			out.println("BigInteger");
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
		new A().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}