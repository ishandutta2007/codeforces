//package school1;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B2 {
	Scanner in;
	PrintWriter out;
//	String INPUT = "10 -2 1 1 3 2 3 4 -10 -2 5";
//	String INPUT = "3 -1 -2 -3";
//	String INPUT = "3 2 3 4";
//	String INPUT = "3 1 1 1";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = new int[n];
		for(int i = 0;i < n;i++){
			a[i] = ni();
		}
		
		int[] prev = new int[n];
		Arrays.fill(prev, -1);
		int max = 0;
		int maxi = -1;
		for(int i = 0;i < n;i++){
			if(a[i] >= 2){
				for(int j = i;j >= 0;j--){
					if(a[j] == a[i] - 1 && (a[j] == 1 || prev[j] != -1)){
						prev[i] = j;
						if(max < a[i]){
							max = a[i];
							maxi = i;
						}
						break;
					}
				}
			}else{
				if(a[i] == 1 && max == 0){
					max = 1;
					maxi = i;
				}
			}
		}
		
		out.println(max);
		if(maxi == -1){
		}else{
			StringBuilder sb = new StringBuilder();
			for(int i = maxi;i != -1;i = prev[i]){
				sb.insert(0, " " + (2001 + i));
			}
			sb.deleteCharAt(0);
			out.println(sb);
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
		new B2().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}