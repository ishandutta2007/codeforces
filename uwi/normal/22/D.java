//package round22;


import java.io.PrintWriter;
import java.io.StringReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class D {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "2 0 2 2 5 ";
//	private String INPUT = "6 1 5 1 2 2 3 4 5 5 5 6 5";
//	private String INPUT = "5 0 3 4 2 4 8 8 10 7 7";
	private String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		Segment[] ss = new Segment[n];
		for(int i = 0;i < n;i++){
			ss[i] = new Segment();
			ss[i].a = ni();
			ss[i].b = ni();
			if(ss[i].a > ss[i].b){
				int d = ss[i].b; ss[i].b = ss[i].a; ss[i].a = d;
			}
		}
		Arrays.sort(ss);
		
		ArrayList<Integer> list = new ArrayList<Integer>();
		Segment s = null;
		for(int i = 0;i < n;i++){
			if(s == null){
				s = ss[i];
			}else{
//				tr(ss[i].a, ss[i].b);
				Segment t = s.trans(ss[i]);
				if(t == null){
					list.add(s.b);
					s = ss[i];
				}else{
					s = t;
				}
			}
		}
		if(s != null){
			list.add(s.b);
		}
		
		out.println(list.size());
		for(int i = 0;i < list.size();i++){
			out.print(list.get(i) + " ");
		}
	}
	
	private class Segment implements Comparable<Segment>
	{
		public int a;
		public int b;
		
		public int compareTo(Segment s){
			if(a != s.a)return a - s.a;
			return b - s.b;
		}
		
		public Segment trans(Segment s)
		{
			int aa = Math.max(a, s.a);
			int bb = Math.min(b, s.b);
			if(aa <= bb){
				Segment ret = new Segment();
				ret.a = aa;
				ret.b = bb;
				return ret;
			}else{
				return null;
			}
		}
	}
	
	public void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(new StringReader(INPUT));
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new D().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private static void tr(Object... o) { System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
}