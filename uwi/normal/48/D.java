//package round45;

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
		int[] ct = new int[100001];
		int[] a = new int[n];
		for(int i = 0;i < n;i++){
			a[i] = ni();
			ct[a[i]]++;
		}
		int[] nl = makeNextList(a, 100001);
		int[] ret = new int[n];
		
		int p = 1;
		for(int k = 100000;k >= 1;){
			if(ct[k] >= 1){
				for(int i = k;i >= 1;i--){
					if(ct[i] == 0){
						out.println(-1);
						return;
					}
					ct[i]--;
					int ind = mnext[i];
					ret[ind] = p;
					mnext[i] = nl[ind];
				}
				p++;
			}else{
				k--;
			}
		}
		
		out.println(p - 1);
		StringBuilder sb = new StringBuilder();
		for(int i = 0;i < n;i++){
			sb.append(ret[i] + " ");
		}
		out.println(sb.toString().trim());
	}
	
	int[] mnext;
	
	public int[] makeNextList(int[] a, int sup)
	{
		int n = a.length;
		mnext = new int[sup];
		Arrays.fill(mnext, -1);
		int[] next = new int[n];
		for(int i = n - 1;i >= 0;i--){
			next[i] = mnext[a[i]];
			mnext[a[i]] = i;
		}
		return next;
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