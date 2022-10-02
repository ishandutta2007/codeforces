//package round52;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
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
		
		if(orig(a)){
			out.println("0 0");
			return;
		}
		
		int[] d = new int[n-1];
		for(int i = 0;i < n-1;i++){
			d[i] = a[i+1] - a[i];
		}
		for(int i = 0;i < n-1;i++){
			if(d[i] == -1){
				int j;
				for(j = i+1;j < n-1 && d[j] == -1;j++);
				for(int p = i, q = j;p < q;p++,q--){
					int x = a[p]; a[p] = a[q]; a[q] = x;
				}
				if(orig(a)){
					out.println((i+1) + " " + (j+1));
					return;
				}
				for(int p = i, q = j;p < q;p++,q--){
					int x = a[p]; a[p] = a[q]; a[q] = x;
				}
				break;
			}
		}
		out.println("0 0");
	}
	
	boolean orig(int[] a)
	{
		for(int i = 0;i < a.length;i++){
			if(a[i] != i + 1)return false;
		}
		return true;
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