//package round19;


import java.io.PrintWriter;
import java.io.StringReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class A {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "2 a A a-A 2:1";
//	private String INPUT = "4 a b c d a-b 1:1 a-c 2:2 a-d 1:0 b-c 1:0 b-d 0:3 c-d 0:3";
//	private String INPUT = "1 a";
	private String INPUT = "";
	
	public void solve()
	{
		// , , 
		int n = ni();
		HashMap<String, Integer> map = new HashMap<String, Integer>();
		Team[] ts = new Team[n];
		for(int i = 0;i < n;i++){
			String name = in.next();
			map.put(name, i);
			ts[i] = new Team();
			ts[i].name = name;
		}
		
		for(int i = 0;i < n * (n - 1) / 2;i++){
			String card = in.next();
			String[] cs = card.split("-");
			int ia = map.get(cs[0]);
			int ib = map.get(cs[1]);
			
			String score = in.next();
			String[] ss = score.split(":");
			int sa = Integer.parseInt(ss[0]);
			int sb = Integer.parseInt(ss[1]);
			ts[ia].score += sa;
			ts[ib].score += sb;
			ts[ia].miss += sb;
			ts[ib].miss += sa;
			if(sa > sb){
				ts[ia].victory += 3;
			}else if(sa < sb){
				ts[ib].victory += 3;
			}else{
				ts[ia].victory++;
				ts[ib].victory++;
			}
		}
		
		Arrays.sort(ts);
		
		String[] names = new String[n / 2];
		for(int i = 0;i < n / 2;i++){
			names[i] = ts[i].name;
		}
		Arrays.sort(names);
		
		for(int i = 0;i < n / 2;i++){
			out.println(names[i]);
		}
	}
	
	public static class Team implements Comparable<Team>
	{
		public String name;
		public int victory;
		public int score;
		public int miss;
		
		@Override
		public int compareTo(Team t) {
			if(victory != t.victory)return -(victory - t.victory);
			if(score - miss != t.score - t.miss)return -((score - miss) - (t.score - t.miss));
			return -(score - t.score);
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
		new A().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private static void tr(Object... o) { System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
}