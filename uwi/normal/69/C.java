//package round63;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
//	String INPUT = "2 3 2 5\r\n" +
//			"desolator\r\n" +
//			"refresher\r\n" +
//			"perseverance\r\n" +
//			"vanguard: desolator 1, refresher 1\r\n" +
//			"maelstorm: perseverance 2\r\n" +
//			"1 desolator\r\n" +
//			"2 perseverance\r\n" +
//			"1 refresher\r\n" +
//			"2 desolator\r\n" +
//			"2 perseverance";
	
	void solve()
	{
		int k = ni();
		int n = ni();
		int m = ni();
		int q = ni();
		Map<String, Integer> ai = new HashMap<String, Integer>();
		String[] basic = new String[n];
		for(int i = 0;i < n;i++){
			String b = in.next();
			ai.put(b, i);
			basic[i] = b;
		}
		Art[] as = new Art[m];
		in.nextLine();
		for(int i = 0;i < m;i++){
			String line = in.nextLine();
			int ind = line.indexOf(':');
			String prod = line.substring(0, ind);
			int[] map = new int[n];
			for(String com : line.substring(ind+1).split(", ")){
				String[] sp = com.trim().split(" ");
				map[ai.get(sp[0])] = Integer.parseInt(sp[1]);
			}
			as[i] = new Art();
			as[i].prod = prod;
			as[i].com = map;
		}
		
		List<TreeMap<String, Integer>> res = new ArrayList<TreeMap<String, Integer>>();
		for(int i = 0;i < k;i++){
			res.add(new TreeMap<String, Integer>());
		}
		
		int[][] pu = new int[k][n];
		for(int i = 0;i < q;i++){
			int a = ni() - 1;
			String c = in.next();
			pu[a][ai.get(c)]++;
			
			for(int j = 0;j < m;j++){
				int min = 99999999;
				for(int l = 0;l < n;l++){
					if(as[j].com[l] > 0){
						min = Math.min(min, pu[a][l] / as[j].com[l]);
					}
				}
				if(min > 0){
					for(int l = 0;l < n;l++){
						pu[a][l] -= min * as[j].com[l];
					}
					if(!res.get(a).containsKey(as[j].prod)){
						res.get(a).put(as[j].prod, 0);
					}
					res.get(a).put(as[j].prod, res.get(a).get(as[j].prod)+min);
					break;
				}
			}
		}
		
		for(int i = 0;i < k;i++){
			for(int l = 0;l < n;l++){
				if(pu[i][l] > 0){
					res.get(i).put(basic[l], pu[i][l]);
				}
			}
			out.println(res.get(i).size());
			for(Map.Entry<String, Integer> e : res.get(i).entrySet()){
				out.println(e.getKey() + " " + e.getValue());
			}
		}
	}
	
	class Art
	{
		public String prod;
		public int[] com;
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
		new C().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}