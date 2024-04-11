//package round27;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class A {
	private Scanner in;
	private PrintWriter out;
	private String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		BitSet bs = new BitSet();
		for(int i = 0;i < n;i++){
			bs.set(ni() - 1);
		}
		out.println(bs.nextClearBit(0) + 1);
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
		new A().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private void tr(Object... o) { if(INPUT.length() == 0)System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
}