//package yandex2011.r2;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		long l = ni();
		long r = ni();
		long mx = 0;
		for(long i = 1, j = 10;i <= r;i*=10, j*=10){
			if(Math.max(i, l) <= Math.min(j-1, r)){
				if((l <= j/2 && j/2 <= r) || (l <= j/2-1 && j/2-1 <= r)){
					mx = Math.max(mx,j/2*(j-1-j/2));
				}else if(r <= j/2-1){
					mx = Math.max(mx, r*(j-1-r));
				}else if(l >= j/2){
					mx = Math.max(mx, l*(j-1-l));
				}
			}
		}
		out.println(mx);
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