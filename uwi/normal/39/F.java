//package school1;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class F {
	Scanner in;
	PrintWriter out;
//	String INPUT = "5 3 5 2 3 4 1 2 3 4 5";
//	String INPUT = "1000000000 2 3 2 5 999999995 999999998 999999996";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		int k = ni();
		
		int[] d = new int[m];
		for(int i = 0;i < m;i++){
			d[i] = ni();
		}
		int[] q = new int[k];
		for(int i = 0;i < k;i++){
			q[i] = ni();
		}
		
		int min = Integer.MAX_VALUE;
		int[] mins = new int[m];
		int p = 0;
		for(int i = 0;i < m;i++){
			int sm = 0;
			for(int j = 0;j < k;j++){
				if(q[j] % d[i] == 0){
					sm++;
				}
			}
			if(sm < min){
				min = sm;
				p = 0;
				mins[p++] = i;
			}else if(sm == min){
				mins[p++] = i;
			}
		}
		out.println(p);
		StringBuilder sb = new StringBuilder();
		for(int i = 0;i < p;i++){
			sb.append(mins[i]+1 + " ");
		}
		out.println(sb);
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
		new F().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}