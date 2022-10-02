//package round37;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Comparator;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
//	String INPUT = "3 1 1 1";
//	String INPUT = "3 1 2 3";
//	String INPUT = "4 2 2 2 2";
//	String INPUT = "3 2 1 2";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		final int[] a = new int[n];
		for(int i = 0;i < n;i++){
			a[i] = ni();
		}
		Integer[] ind = new Integer[n];
		for(int i = 0;i < n;i++)ind[i] = i;
		Arrays.sort(ind, new Comparator<Integer>(){
			public int compare(Integer x, Integer y)
			{
				return a[x] - a[y];
			}
		});
		BitSet bs = new BitSet(1000);
		String[] u = new String[n];
		for(int i = 0;i < n;i++){
			StringBuilder sb = new StringBuilder();
			for(int j = 0;j < a[ind[i]];j++){
				sb.append(bs.get(j) ? '1' : '0');
			}
			u[ind[i]] = sb.toString();
			
			for(int j = a[ind[i]] - 1;j >= 0;j--){
				if(!bs.get(j)){
					bs.set(j);
					break;
				}else{
					bs.clear(j);
					if(j == 0){
						if(i == n - 1 && bs.isEmpty()){
							break;
						}
						out.println("NO");
						return;
					}
				}
			}
//			tr(bs);
		}
		out.println("YES");
		for(int i = 0;i < n;i++){
			out.println(u[i]);
		}
	}
	
	void run() throws Exception
	{
//		StringBuilder sb = new StringBuilder("1000 ");
//		for(int i = 0;i < 1000;i++){
//			sb.append((i+1) + " ");
//		}
//		INPUT = sb.toString();
		
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new C().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
	static String join(int[] a, int d){StringBuilder sb = new StringBuilder();for(int v : a){sb.append(v + d + " ");}return sb.toString();}
}