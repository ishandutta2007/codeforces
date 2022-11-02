import java.util.*;
import java.math.*;
import java.io.*;

public class Main{
	static String s[] = new String[33];
	public static void main(String args[]) throws IOException {
		//BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int tux, foo, bar, baz, quz, pur;
		bar = 0; baz = 0; foo = 0; quz = 1;
		tux = in.nextInt();
		for(; tux > 0; tux--){
			pur = in.nextInt();
			foo += pur; bar++;
			if(foo * quz >= bar * baz){
				baz = foo;
				quz = bar;
			}
			
		}
		double ans = (double)baz;
		ans /= (double)quz;
		out.println(ans);
		out.flush();
	}
}