//package yandex2011.q2;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		long n = ni() - 1;
		String[] name = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
		for(long i = 5, j = 1;;i *= 2, j *= 2){
			if(n < i){
				out.println(name[(int)(n / j) % 5]);
				return;
			}
			n -= i;
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
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}