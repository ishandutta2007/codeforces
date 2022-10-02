//package manthan;

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
		int k = ni();
		int[] a = new int[n];
		for(int i = 0;i < n;i++){
			a[i] = ni();
		}
		
		BitSet used = new BitSet();
		int[] ret = new int[n];
		for(int i = 0;i < n;i++){
			for(int j = used.nextClearBit(0);j < n;j = used.nextClearBit(j + 1)){
				if(a[j] == 0){
					ret[i] = j;
					used.set(j);
					for(int l = 0;l <= j-k;l++){
						a[l]--;
					}
					break;
				}
			}
		}
		for(int i = 0;i < n;i++){
			out.print((ret[i]+1) + " ");
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
		new B().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}