//package round81;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		double k = nd();
		int K = (int)Math.round(k*100);
		
		String[] name = new String[n];
		int[] exp = new int[n];
		for(int i = 0;i < n;i++){
			name[i] = in.next();
			exp[i] = ni();
		}
		String[] add = new String[m];
		for(int i = 0;i < m;i++){
			add[i] = in.next();
		}
		
		TreeMap<String, Integer> tm = new TreeMap<String, Integer>();
		for(int i = 0;i < n;i++){
			if(exp[i] * K / 100 >= 100){
				tm.put(name[i], exp[i]*K/100);
			}
		}
		for(int i = 0;i < m;i++){
			if(!tm.containsKey(add[i])){
				tm.put(add[i], 0);
			}
		}
		
		out.println(tm.size());
		for(Map.Entry<String, Integer> e : tm.entrySet()){
			out.println(e.getKey() + " " + e.getValue());
		}
	}
	
	void run() throws Exception
	{
		in = oj ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new A().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}