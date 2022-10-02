//package round49;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class D {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = new int[n];
		int[] b = new int[n];
		for(int i = 0;i < n;i++){
			a[i] = ni();
		}
		for(int i = 0;i < n;i++){
			b[i] = ni();
		}
		
		List<Integer> ord = new ArrayList<Integer>();
		for(int i = 0;i < n;i++){
			int j;
			for(j = i;j < n && b[j] != a[i];j++);
			for(int k = j - 1;k >= i;k--){
				ord.add(k+1);
				int d = b[k]; b[k] = b[k+1]; b[k+1] = d;
			}
		}
		
		out.println(ord.size());
		for(int x : ord){
			out.println(x + " " + (x+1));
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
		new D().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}