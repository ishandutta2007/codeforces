//package round67;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		String yn = in.next();
		int n = ni();
		final Map<String, Integer> map = new HashMap<String, Integer>();
		for(int i = 0;i < n;i++){
			String X = in.next();
			String verb = in.next();
			int gain;
			String Y;
			if(verb.equals("posted")){
				in.next();
				String ys = in.next();
				Y = ys.substring(0, ys.length() - 2);
				gain = 15;
				in.next();
			}else if(verb.equals("commented")){
				in.next();
				String ys = in.next();
				Y = ys.substring(0, ys.length() - 2);
				gain = 10;
				in.next();
			}else{
				String ys =	in.next();
				Y = ys.substring(0, ys.length() - 2);
				in.next();
				gain = 5;
			}
			if(X.equals(Y))throw new AssertionError();
			if(!map.containsKey(X))map.put(X, 0);
			if(!map.containsKey(Y))map.put(Y, 0);
			if(X.equals(yn))map.put(Y, map.get(Y) + gain);
			if(Y.equals(yn))map.put(X, map.get(X) + gain);
		}
		List<String> keys = new ArrayList<String>(map.keySet());
		Collections.sort(keys, new Comparator<String>(){
			public int compare(String x, String y)
			{
				if(map.get(x) - map.get(y) != 0)return -(map.get(x) - map.get(y));
				return x.compareTo(y);
			}
		});
		
		for(int i = 0;i < keys.size();i++){
			if(!yn.equals(keys.get(i))){
				out.println(keys.get(i));
			}
		}
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
		new B().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}