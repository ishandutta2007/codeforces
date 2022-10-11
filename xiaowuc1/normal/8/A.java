import java.io.*;
import java.util.*;
public class A8 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String total = br.readLine();
		String first = br.readLine();
		String second = br.readLine();
		String totalReverse = new StringBuilder(total).reverse().toString();
		boolean f = can(total, first, second);
		boolean r = can(totalReverse, first, second);
		if(f&&r)
			System.out.println("both");
		if(f&&!r)
			System.out.println("forward");
		if(!f&&r)
			System.out.println("backward");
		if(!f&&!r)
			System.out.println("fantasy");
	}
	public static boolean can(String a, String b, String c)		{
		int first = a.indexOf(b);
		int second = a.lastIndexOf(c);
		if(first != -1 && second != -1 && first + b.length() <= second)
			return true;
		return false;
	}
}