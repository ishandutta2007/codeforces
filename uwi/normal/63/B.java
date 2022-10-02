//package round59;

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
		int k = ni();
		int[] ct = new int[102];
		for(int i = 0;i < n;i++){
			ct[ni()]++;
		}
		
		int cc = 0;
		while(true){
			boolean up = false;
			for(int i = k - 1;i >= 0;i--){
				if(ct[i] > 0){
					ct[i+1]++;
					ct[i]--;
					up = true;
				}
			}
			if(!up)break;
			cc++;
		}
		out.println(cc);
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