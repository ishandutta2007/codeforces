//package round24;



import java.io.PrintWriter;
import java.io.StringReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Scanner;
import java.util.TreeSet;

public class B {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "3 3 H V W 2 W V 2 H V";
//	private String INPUT = "2 7 Pr S N S Bu D Bu 8 A Pr N J D N Pa S";
	private String INPUT = "";
	int[] ws = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
	
	public void solve()
	{
		int t = ni();
		
		HashMap<String, Info> map = new HashMap<String, Info>();
		for(int i = 0;i < t;i++){
			int n = ni();
			for(int j = 0;j < n;j++){
				String name = in.next();
				if(!map.containsKey(name))map.put(name, new Info(name));
				if(j < 10)map.get(name).score += ws[j];
				map.get(name).places[j]++;
			}
		}
		TreeSet<Info> ts1 = new TreeSet<Info>(new Comp1());
		TreeSet<Info> ts2 = new TreeSet<Info>(new Comp2());
		ts1.addAll(map.values());
		ts2.addAll(map.values());
		
		out.println(ts1.first().name);
		out.println(ts2.first().name);
	}
	
	public static class Info
	{
		public String name;
		public int score;
		public int[] places;
		
		public Info(String name)
		{
			this.name = name;
			score = 0;
			places = new int[50];
		}
	}
	
	public static class Comp1 implements Comparator<Info>
	{
		@Override
		public int compare(Info i1, Info i2) {
			if(i1.score != i2.score)return -(i1.score - i2.score);
			for(int i = 0;i < 50;i++){
				if(i1.places[i] != i2.places[i])return -(i1.places[i] - i2.places[i]);
			}
			return 0;
		}
	}
	
	public static class Comp2 implements Comparator<Info>
	{
		@Override
		public int compare(Info i1, Info i2) {
			if(i1.places[0] != i2.places[0])return -(i1.places[0] - i2.places[0]);
			if(i1.score != i2.score)return -(i1.score - i2.score);
			for(int i = 1;i < 50;i++){
				if(i1.places[i] != i2.places[i])return -(i1.places[i] - i2.places[i]);
			}
			return 0;
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
		new B().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private static void tr(Object... o) { System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
}