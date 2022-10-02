//package round29;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class C {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "2 1 100 100 2";
//	private String INPUT = "3 3 1 100 2 3 2";
	private String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		Map<Integer, Integer> map2 = new HashMap<Integer, Integer>();
		for(int i = 0;i < n;i++){
			int f = ni();
			int t = ni();
			if(!map.containsKey(f)){
				map.put(f, t);
			}else{
				map2.put(f, t);
			}
			if(!map.containsKey(t)){
				map.put(t, f);
			}else{
				map2.put(t, f);
			}
		}
		
		int h = -1;
		for(int k : map.keySet()){
			if(!map2.containsKey(k)){
				h = k;
				break;
			}
		}
		
		int[] hist = new int[n + 1];
		hist[0] = h;
		hist[1] = map.get(h);
		for(int i = 2;i < n + 1;i++){
			int t1 = map.get(hist[i - 1]);
			int t2 = map2.get(hist[i - 1]);
			
			if(hist[i - 2] == t1){
				hist[i] = t2;
			}else{
				hist[i] = t1;
			}
		}
		StringBuilder sb = new StringBuilder();
		for(int hi : hist){
			sb.append(hi);
			sb.append(' ');
		}
		out.println(sb.toString());
	}
	
	public void run() throws Exception
	{
//		StringBuilder sb = new StringBuilder("100000 ");
//		for(int i = 0;i < 100000;i++){
//			sb.append(i);
//			sb.append(' ');
//			sb.append(i+1);
//			sb.append(' ');
//		}
//		INPUT = sb.toString();
//
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