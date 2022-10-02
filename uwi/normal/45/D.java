//package school3;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Comparator;
import java.util.Scanner;

public class D3 {
	Scanner in;
	PrintWriter out;
//	String INPUT = "3 1 2 2 3 3 4";
//	String INPUT = "2 1 3 1 3";
//	String INPUT = "4 1 2 3 4 1 2 1 3";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		final int[] l = new int[n];
		final int[] r = new int[n];
		for(int i = 0;i < n;i++){
			l[i] = ni();
			r[i] = ni();
		}
		
		Integer[] ind = new Integer[n];
		for(int i = 0;i < n;i++)ind[i] = i;
		Arrays.sort(ind, new Comparator<Integer>(){
			public int compare(Integer x, Integer y)
			{
				return r[x] - r[y];
			}
		});
		
		int[] day = new int[n];
		BitSet filled = new BitSet();
		for(int i = 0;i < n;i++){
			int f = filled.nextClearBit(l[ind[i]]);
			filled.set(f);
			day[ind[i]] = f;
		}
		
		for(int x : day){
			out.print(x + " ");
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
		new D3().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}