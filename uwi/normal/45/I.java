//package school3;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class I {
	Scanner in;
	PrintWriter out;
//	String INPUT = "13 100 100 100 100 100 100 100 100 100 100 100 100 100 ";
//	String INPUT = "3 0 0 0";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] c = new int[n];
		boolean f0 = true;
		int nm = 0;
		for(int i = 0;i < n;i++){
			c[i] = ni();
			if(c[i] != 0){
				f0 = false;
			}
			if(c[i] < 0){
				nm++;
			}
		}
		
		if(n == 1){
			out.println(c[0]);
			return;
		}
		if(f0){
			out.println(0);
			return;
		}
		
		if(nm % 2 == 0){
			StringBuilder sb = new StringBuilder();
			for(int i = 0;i < n;i++){
				if(c[i] != 0){
					sb.append(c[i] + " ");
				}
			}
			out.println(sb);
		}else{
			int max = -99999;
			int maxi = -1;
			for(int i = 0;i < n;i++){
				if(c[i] < 0){
					if(max < c[i]){
						max = c[i];
						maxi = i;
					}
				}
			}
			StringBuilder sb = new StringBuilder();
			for(int i = 0;i < n;i++){
				if(c[i] != 0 && i != maxi){
					sb.append(c[i] + " ");
				}
			}
			
			if(sb.length() == 0){
				for(int i = 0;i < n;i++){
					if(i != maxi){
						sb.append(c[i] + " ");
					}
				}
			}
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
		new I().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}