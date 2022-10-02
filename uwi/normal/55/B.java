//package round51;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
//	String INPUT = "1000 1000 1000 1000 * * *";
	
	void solve()
	{
		long[] a = new long[4];
		for(int i = 0;i < 4;i++)a[i] = ni();
		char[] o = new char[3];
		for(int i = 0;i < 3;i++)o[i] = in.next().charAt(0);
		List<List<Long>> ll = new ArrayList<List<Long>>();
		List<Long> list = new ArrayList<Long>();
		list.add(a[0]);
		list.add(a[1]);
		list.add(a[2]);
		list.add(a[3]);
		ll.add(list);
		
		for(int i = 0;i < 3;i++){
			List<List<Long>> nll = new ArrayList<List<Long>>();
			for(List<Long> cur : ll){
				for(int j = 0;j < 4 - i;j++){
					for(int k = j + 1;k < 4 - i;k++){
						List<Long> nx = new ArrayList<Long>();
						long r = calc(cur, j, k, o[i]);
						nx.add(r);
						for(int l = 0;l < cur.size();l++){
							if(l != j && l != k){
								nx.add(cur.get(l));
							}
						}
						nll.add(nx);
					}
				}
			}
			ll = nll;
		}
		
		long min = Long.MAX_VALUE;
		for(List<Long> c : ll){
			min = Math.min(min, c.get(0));
		}
		out.println(min);
	}
	
	long calc(List<Long> cur, int j, int k, char o)
	{
		if(o == '+'){
			return cur.get(j) + cur.get(k);
		}else{
			return cur.get(j) * cur.get(k);
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
		new B().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}