//package round56;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		BitSet bs = new BitSet();
		bs.set(0, n);
		for(int i = 0;i < m;i++){
			in.next();
			in.next();
			boolean dir = in.next().equals("right");
			in.next();
			int t = ni();
			if(dir){
				bs.clear(0, t);
			}else{
				bs.clear(t-1, n);
			}
		}
		int c = bs.cardinality();
		if(c == 0){
			out.println(-1);
		}else{
			out.println(c);
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