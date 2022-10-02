//package round72;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		long k = in.nextLong();
		
		int[] a = new int[n];
		for(int i = 0;i < n;i++){
			a[i] = ni();
		}
		int[] ord = pairSort2(a);
		
		int cur = 0;
		for(int i = 0;i < n;i++){
			long sup = (long)(a[ord[i]] - cur) * (n-i);
			if(k > sup){
				k -= sup;
				cur = a[ord[i]];
			}else{
				int mod = (int)((k-1) % (n-i))+1;
				boolean last = k > sup - (n-i);
				List<Integer> back = new ArrayList<Integer>();
				List<Integer> front = new ArrayList<Integer>();
				for(int j = 0;j < n;j++){
					if(a[j] > cur){
						if(mod > 0){
							mod--;
							if(a[ord[i]] == a[j] && last){
								continue;
							}else{
								back.add(j+1);
							}
						}else{
							front.add(j+1);
						}
					}
				}
				StringBuilder sb = new StringBuilder();
				for(int f : front)sb.append(f + " ");
				for(int f : back)sb.append(f + " ");
				out.println(sb);
				return;
			}
		}
		out.println(-1);
	}
	
	public static int[] pairSort2(int[] a)
	{
		int n = a.length;
		long[] ind = new long[n];
		for(int i = 0;i < n;i++)ind[i] = (long)a[i]<<32 | i;
		Arrays.sort(ind);
		int[] ret = new int[n];
		for(int i = 0;i < n;i++)ret[i] = (int)ind[i];
		return ret;
	}
	
	
	void run() throws Exception
	{
//		int n = 100000;
//		StringBuilder sb = new StringBuilder(n + " 100000000000 ");
//		Random r = new Random();
//		for(int i = 0;i < n;i++){
//			sb.append(r.nextInt(1000000000) + " ");
//		}
//		INPUT = sb.toString();
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
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}