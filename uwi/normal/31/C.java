//package round31;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
import java.util.List;
import java.util.Scanner;

public class C {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "3 3 10 20 30 1 3";
//	private String INPUT = "4 3 10 20 30 1 3 1 39";
//	private String INPUT = "3 1 5 2 6 3 7";
//	private String INPUT = "2 1 4 1 4";
//	private String INPUT = "3 1 4 1 4 5 6";
//	private String INPUT = "3 1 4 1 4 3 6";
	private String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		Pair[] p = new Pair[n];
		for(int i = 0;i < n;i++){
			p[i] = new Pair(ni(), ni(), i);
		}
		
		BitSet[] bss = new BitSet[n];
		for(int i = 0;i < n;i++)bss[i] = new BitSet();
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < i;j++){
				if(intersect(p[i], p[j])){
					bss[i].set(j);
					bss[j].set(i);
				}
			}
		}
		
		int ct2 = 0;
		int ct1 = 0;
		for(int i = 0;i < n;i++){
			if(bss[i].cardinality() >= 2){
				ct2++;
			}else if(bss[i].cardinality() == 1){
				ct1++;
			}
		}
		
		if(ct2 == 0){
			if(ct1 == 2){
				List<Integer> ll = new ArrayList<Integer>();
				for(int i = 0;i < n;i++){
					if(bss[i].cardinality() == 1){
						ll.add(i);
						if(ll.size() == 2)break;
					}
				}
				out.println(2);
				for(int i = 0;i < 2;i++){
					out.print((ll.get(i)+1) + " ");
				}
			}else{
				out.println(n);
				for(int i = 1;i <= n;i++){
					out.print(i + " ");
				}
			}
			out.println();
		}else if(ct2 == 1){
			for(int i = 0;i < n;i++){
				if(bss[i].cardinality() >= 2){
					out.println(1);
					out.println(i + 1);
					break;
				}
			}
		}else{
			out.println(0);
		}
	}
	
	public boolean intersect(Pair a, Pair b)
	{
		return (a.from <= b.from && b.from < a.to) || (b.from <= a.from && a.from < b.to);
	}
	
	public static class Pair
	{
		public int from;
		public int to;
		public int ind;
		public Pair(int from, int to, int ind)
		{
			this.from = from;
			this.to = to;
			this.ind = ind;
		}
	}
	
	public void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new C().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}