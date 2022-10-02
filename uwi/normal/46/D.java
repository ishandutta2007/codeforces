//package round43;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeSet;

public class D {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int l = ni();
		int b = ni();
		int f = ni();
		int n = ni();
		int[][] req = new int[n][2];
		
		TreeSet<Integer> ts = new TreeSet<Integer>();
		for(int i = 0;i < n;i++){
			int r = ni();
			int a = ni();
			if(r == 1){
				if(ts.size() == 0){
					if(a <= l){
						ts.add(0);
						ts.add(a);
						out.println(0);
						req[i][0] = 0;
						req[i][1] = a;
						continue;
					}else{
						out.println(-1);
						continue;
					}
				}
				
				int pr = 0;
				int q = 0;
				boolean ins = false;
				for(int x : ts){
					if(q % 2 == 0){
						if(pr == 0){
							if(x >= a + f){
								ts.add(0);
								ts.add(a);
								out.println(0);
								req[i][0] = 0;
								req[i][1] = a;
								ins = true;
								break;
							}
						}else{
							if(x - pr >= a + b + f){
								ts.add(pr + b);
								ts.add(pr + b + a);
								req[i][0] = pr + b;
								req[i][1] = pr + b + a;
								out.println(pr + b);
								ins = true;
								break;
							}
						}
					}else{
						pr = x;
					}
					q++;
				}
				if(!ins && l - pr >= a + b){
					ts.add(pr + b);
					ts.add(pr + b + a);
					req[i][0] = pr + b;
					req[i][1] = pr + b + a;
					out.println(pr + b);
					ins = true;
				}
				if(!ins){
					out.println(-1);
				}
			}else{
				ts.remove(req[a - 1][0]);
				ts.remove(req[a - 1][1]);
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
	void tr(Object... o) { System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}