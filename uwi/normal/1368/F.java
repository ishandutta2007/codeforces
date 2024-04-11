//package global8;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class F2 {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		if(n <= 3){
			out.println(0);
			out.flush();
			return;
		}
		int max = -1;
		int arg = -1;
		for(int h = 1;h <= n-1;h++){
			int got = n/(h+1)*h;
			int rem = n%(h+1);
			if(rem > 1){
				got += rem-1;
			}
			got -= h;
			if(got > max){
				max = got;
				arg = h;
			}
		}
		boolean[] ideal = new boolean[n];
		for(int i = 0;i < n;i++){
			if(i % (arg+1) < arg){
				ideal[i] = true;
			}
		}
		ideal[n-1] = false;
		
		int ct = 0;
		for(int i = 0;i < n;i++){
			if(ideal[i]){
				ct++;
			}
		}
		assert ct == max + arg;
		
		boolean[] ped = new boolean[n];
		while(true){
			List<Integer> all = new ArrayList<>();
			for(int i = 0;i < n;i++){
				if(ideal[i] != ped[i]){
					all.add(i);
				}
				ped[i] = ideal[i];
			}
			if(all.size() <= arg)break;
			
			out.print(all.size());
			for(int v : all){
				out.print(" " + (v+1));
			}
			out.println();
			out.flush();
			
			int m = ni()-1;
			for(int i = 0;i < all.size();i++){
				ped[(m+i)%n] = false;
			}
		}
		
		out.println(0);
		out.flush();
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
		new F2().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}