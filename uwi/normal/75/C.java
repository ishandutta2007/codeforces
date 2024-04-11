//package round67;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int a = ni();
		int b = ni();
		int g = gcd(a, b);
		List<Integer> ds = new ArrayList<Integer>();
		for(int p = 1;p * p <= g;p++){
			if(g % p == 0){
				ds.add(p);
				if(p * p != g)ds.add(g / p);
			}
		}
		Collections.sort(ds);
		
		int n = ni();
		for(int i = 0;i < n;i++){
			int l = ni();
			int h = ni();
			int ind = Collections.binarySearch(ds, h);
			if(ind < 0)ind = -ind - 2;
			if(ind < 0 || ds.get(ind) < l){
				out.println(-1);
			}else{
				out.println(ds.get(ind));
			}
		}
	}
	
	public static int gcd(int a, int b) {
		while (b > 0){
			int c = a;
			a = b;
			b = c % b;
		}
		return a;
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