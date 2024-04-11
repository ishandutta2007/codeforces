//package round24;



import java.io.PrintWriter;
import java.io.StringReader;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "3 1 3 1 1 2 1 3 2 1";
//	private String INPUT = "3 1 3 1 1 2 5 3 2 1";
//	private String INPUT = "3 1 3 1 3 2 1 2 1 1";
	private String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		int[][] road = new int[n][4];
		for(int i = 0;i < n;i++){
			int f = ni() - 1;
			int t = ni() - 1;
			int c = ni();
			if(road[f][1] == 0){
				road[f][0] = t;
				road[f][1] = c;
			}else{
				road[f][2] = t;
				road[f][3] = c;
			}
			if(road[t][1] == 0){
				road[t][0] = f;
				road[t][1] = -c;
			}else{
				road[t][2] = f;
				road[t][3] = -c;
			}
		}
		
		int[] ring = new int[n];
		int pc = 0;
		int mc = 0;
		for(int i = 0, p = 0;p < n;p++){
			ring[p] = i;
			int ind = p > 0 && road[i][0] == ring[p - 1] ? 2 : 0;
			if(road[i][ind+1] > 0){
				pc += road[i][ind+1];
			}else{
				mc -= road[i][ind+1];
			}
			i = road[i][ind];
		}
		out.println(Math.min(pc, mc));
		
//		int[] ring = new int[n];
//		int[] cost = new int[n];
//		for(int i = sink, p = 0;p < n;p++){
//			ring[p] = i;
//			int ind = p > 0 && road[i][0] == ring[p - 1] ? 2 : 0;
//			cost[p] = road[i][ind+1];
//			i = road[i][ind];
//		}
//		
//		int sum = 0;
//		for(int p = 0, q = n-1;p <= q;){
//			int scp = 0, pp = p;
//			for(;pp < n && cost[pp] < 0;pp++)scp -= cost[pp];
//			int scq = 0, qq = q;
//			for(;qq >= 0 && cost[qq] > 0;qq--)scq += cost[qq];
//			
//			if(scp < scq){
//				sum += scp;
//				for(;pp < n && cost[pp] > 0;pp++);
//				p = pp;
//			}else{
//				sum += scq;
//				for(;qq >= 0 && cost[qq] < 0;qq--);
//				q = qq;
//			}
//		}
//		
//		out.println(sum);
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