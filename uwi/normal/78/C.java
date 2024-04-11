//package round70;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		Map<Integer, Boolean> win = new HashMap<Integer, Boolean>();
		int n = ni();
		int m = ni();
		int k = ni();
		if(m < k){
			out.println("Marsel");
			return;
		}
		
		List<Integer> divs = new ArrayList<Integer>();
		for(int i = 1;i * i <= m;i++){
			if(m % i == 0){
				divs.add(i);
				if(i*i != m)divs.add(m/i);
			}
		}
		Collections.sort(divs);
		
		for(int d : divs){
			if(d < k){
				win.put(d, true);
			}else{
				win.put(d, false);
				outer:
				for(int i = 1;i * i <= d;i++){
					if(d % i == 0){
						if(i >= k && i != d){
							if((d/i)%2 == 0){
								win.put(d, true);
								break outer;
							}else{
								if(!win.get(i)){
									win.put(d, true);
									break outer;
								}
							}
						}
						if(d/i >= k && d/i != d){
							if(i%2 == 0){
								win.put(d, true);
								break outer;
							}else{
								if(!win.get(d/i)){
									win.put(d, true);
									break outer;
								}
							}
						}
					}
				}
			}
		}
		
		if(n % 2 == 0 || !win.get(m)){
			out.println("Marsel");
		}else{
			out.println("Timur");
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
		new C().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}