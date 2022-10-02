//package round55;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = new int[n];
		BitSet odd = new BitSet();
		for(int i = 0;i < n;i++){
			a[i] = ni();
			if(a[i]%2 == 1){
				odd.set(i);
			}
		}
		if(odd.cardinality() == 0){
			out.println(0);
		}else{
			int sum = 0;
			for(int i = 0;i < n;i++){
				sum += a[i];
			}
			if(odd.cardinality() % 2 == 1){
				out.println(sum);
			}else{
				int min = 999;
				for(int i = odd.nextSetBit(0);i != -1;i = odd.nextSetBit(i + 1)){
					min = Math.min(min, a[i]);
				}
				out.println(sum - min);
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
		new B().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}