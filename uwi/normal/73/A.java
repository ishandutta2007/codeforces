//package round66;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int x = ni();
		int y = ni();
		int z = ni();
		int k = ni();
		
		int inf = 0;
		int sup = 1000001;
		while(sup - inf > 1){
			int mid = (inf+sup) / 2;
			int v = Math.min(x-1, mid) + Math.min(y-1, mid) + Math.min(z-1, mid);
			if(v <= k){
				inf = mid;
			}else{
				sup = mid;
			}
		}
		int infx = inf;
		int infy = inf;
		int infz = inf;
		int vo = Math.min(x-1, infx) + Math.min(y-1, infy) + Math.min(z-1, infz);
		if(vo < k && x-1 > inf){
			infx++;
			vo++;
		}
		if(vo < k && y-1 > inf){
			infy++;
			vo++;
		}
		if(vo < k && z-1 > inf){
			infz++;
			vo++;
		}
		out.println((long)(Math.min(x-1, infx)+1) * (Math.min(y-1, infy)+1) * (Math.min(z-1, infz)+1));
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
		new A().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}