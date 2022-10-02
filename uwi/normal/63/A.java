//package round59;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		final String[] name = new String[n];
		final String[] job = new String[n];
		for(int i = 0;i < n;i++){
			name[i] = in.next();
			job[i] = in.next();
		}
		
		Integer[] ord = new Integer[n];
		for(int i = 0;i < n;i++)
			ord[i] = i;
		Arrays.sort(ord, new Comparator<Integer>() {
			public int compare(Integer x, Integer y) {
				String jx = job[x];
				String jy = job[y];
				if(!jx.equals(jy)){
					if(jx.equals("rat")){
						return -1;
					}
					if(jy.equals("rat")){
						return 1;
					}
					if(jx.equals("woman") || jx.equals("child")){
						return -1;
					}
					if(jy.equals("woman") || jy.equals("child")){
						return 1;
					}
					if(jx.equals("man")){
						return -1;
					}
					if(jy.equals("man")){
						return 1;
					}
				}
				
				return x - y;
			}
		});
		
		for(int i = 0;i < n;i++){
			out.println(name[ord[i]]);
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
		new A().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}