//package round28;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class D4 {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "5 1 1 0 3 1 1 1 2 1 1 2 1 1 1 3 0 2 1 3 0";
//	private String INPUT = "5 1 1 0 3 10 1 2 1 2 2 1 1 10 1 1 2 3 1 3 0";
//	private String INPUT = "1 1 1 0 0";
	private String INPUT = "";
//	private String INPUT = "7 999 999 0 0 1 1 0 2 2 1 0 2 1 1 1 1 2 1 1 1 2 1 2 0 1 1 2 0";
	
	public void solve()
	{
		int n = ni();
		int[] v = new int[n];
		int[] c = new int[n];
		int[] l = new int[n];
		int[] r = new int[n];
		for(int i = 0;i < n;i++){
			v[i] = ni();
			c[i] = ni();
			l[i] = ni();
			r[i] = ni();
		}
		
		int[] hot = new int[200001];
		Arrays.fill(hot, -1);
		int[] previ = new int[n];
		Arrays.fill(previ, -1);
		for(int i = n - 1;i >= 0;i--){
			int s = c[i] + l[i] + r[i];
			if(s <= 200000){
				if(hot[s] > -1){
					previ[i] = hot[s];
				}
				hot[s] = i;
			}
		}
		
		int maxv = -1;
		int[] route = null;
		
		int[] prev = new int[n];
		Arrays.fill(prev, -1);
		
		for(int cap = 0;cap <= 200000;cap++){
			if(hot[cap] == -1)continue;
			
			Map<Integer, Integer> curv = new HashMap<Integer, Integer>();
			Map<Integer, Integer> filled = new HashMap<Integer, Integer>();
			curv.put(0, 0);
			for(int j = hot[cap];j != -1;j = previ[j]){
				if(curv.containsKey(l[j])){
					int nv = curv.get(l[j]) + v[j];
					if(!curv.containsKey(l[j] + c[j]) || nv > curv.get(l[j] + c[j])){
						curv.put(l[j] + c[j], nv);
						filled.put(l[j] + c[j], j);
						Integer vv = filled.get(l[j]);
						prev[j] = vv != null ? vv : -1;
					}
				}
			}

			if(curv.containsKey(cap) && maxv < curv.get(cap)){
				int ct = 0;
				for(int j = filled.get(cap);j != -1;j = prev[j])ct++;
				maxv = curv.get(cap);
				route = new int[ct];
				for(int j = filled.get(cap), p = ct - 1;j != -1;j = prev[j],p--){
					route[p] = j;
				}
			}
		}

		if(route == null){
			out.println(0);
		}else{
			out.println(route.length);
			out.println(join(route, 1));
		}
	}
	
	public void run() throws Exception
	{
//		StringBuilder sb = new StringBuilder("100000 ");
//		for(int i = 0;i < 100000;i++){
//			sb.append(i + " " + (i+1) + " 0 1 ");
//		}
//		INPUT = sb.toString();
		
		long s = System.currentTimeMillis();
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
		long g = System.currentTimeMillis();
//		System.out.println(g -s );
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new D4().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
	private String join(int[] a, int d){
		StringBuilder sb = new StringBuilder();
		for(int v : a){
			sb.append(v+d);
			sb.append(' ');
		}
		return sb.toString();
	}
}