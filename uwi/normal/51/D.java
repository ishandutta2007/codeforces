//package round48;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class D {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		
		if(n == 1){
			out.println(0);
			return;
		}else if(n == 2){
			if(a[0] == 0 && a[1] == 0){
				out.println(0);
			}else{
				out.println(a[0] == 0 ? 1 : 0);
			}
			return;
		}
		
		int ct = 0;
		for(int i = 0;i < n;i++){
			if(a[i] != 0){
				ct++;
			}
		}
		if(ct == 0){
			out.println(0);
			return;
		}
		if(ct == 1){
			if(a[0] == 0){
				out.println(1);
			}else{
				out.println(0);
			}
			return;
		}
		if(ct == 2 && a[0] != 0){
			out.println(1);
			return;
		}
		if(ct <= n - 2){
			out.println(2);
			return;
		}
		
		int last = -1;
		int first = -1;
		int bct = 0;
		for(int i = 1;i < n - 1;i++){
			if(a[i] * a[i] != a[i-1] * a[i+1]){
				bct++;
				last = i;
				if(first == -1)first = i;
			}
		}
		if(bct == 0){
			out.println(0);
		}else if(bct == 1){
			out.println(1);
		}else if(last - first > 2){
			out.println(2);
		}else if(last - first == 1){
			if(a[last] * a[last] == a[first-1] * a[last+1] || a[first] * a[first] == a[last+1] * a[first - 1]){
				out.println(1);
			}else{
				out.println(2);
			}
		}else{
			if(a[last] * a[last] == a[first] * a[last+1] && a[first] * a[first] == a[last] * a[first - 1]){
				out.println(1);
			}else{
				out.println(2);
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
		new D().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}