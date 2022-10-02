//package round61;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class E {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = new int[n];
		for(int i = 0;i < n;i++){
			a[i] = ni();
		}
		int[] b = new int[n];
		for(int i = 0;i < n;i++){
			b[i] = ni();
		}
		
		BitSet minall = new BitSet();
		{
			long min = 0;
			BitSet mins = new BitSet();
			long cur = 0;
			mins.set(0);
			for(int i = 0;i < n;i++){
				cur += (long)a[i] - (long)b[i];
				if(cur < min){
					min = cur;
					mins.clear();
					mins.set((i+1)%n);
				}else if(cur == min){
					mins.set((i+1)%n);
				}
			}
			minall.or(mins);
		}
		{
			long min = 0;
			BitSet mins = new BitSet();
			long cur = 0;
			mins.set(0);
			for(int i = n-1;i >= 0;i--){
				cur += (long)a[(i+1)%n] - (long)b[i];
				if(cur < min){
					min = cur;
					mins.clear();
					mins.set(i);
				}else if(cur == min){
					mins.set(i);
				}
			}
			minall.or(mins);
		}
		
		out.println(minall.cardinality());
		for(int i = minall.nextSetBit(0);i != -1;i = minall.nextSetBit(i + 1)){
			out.print((i+1) + " ");
		}
		out.println();
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
		new E().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}