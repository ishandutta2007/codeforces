//package round551;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class E {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	int q(int x1, int y1, int x2, int y2)
	{
		out.println("? " + x1 + " " + y1 + " " + x2 + " " + y2);
		out.flush();
		return ni()&1;
	}
	
	void solve()
	{
		int n = ni();
		int[] rs = new int[n+1];
		int x = 0;
		for(int i = 1;i < n;i++){
			rs[i] = q(i, 1, i, n);
			x ^= rs[i];
		}
		rs[n] = x;
		
		List<int[]> rets = new ArrayList<>();
		for(int i = 1;i <= n;i++){
			if(rs[i] == 1){
				int l = 1, r = n+1;
				while(r-l > 1){
					int h = l+r>>1;
					if(q(i, l, i, h-1) == 1){
						r = h;
					}else{
						l = h;
					}
				}
				rets.add(new int[]{i, l});
			}
		}
		if(rets.size() == 0){
			for(int i = 1;i < n;i++){
				rs[i] = q(1, i, n, i);
				x ^= rs[i];
			}
			rs[n] = x;
			for(int i = 1;i <= n;i++){
				if(rs[i] == 1){
					int l = 1, r = n+1;
					while(r-l > 1){
						int h = l+r>>1;
						if(q(l, i, h-1, i) == 1){
							r = h;
						}else{
							l = h;
						}
					}
					rets.add(new int[]{l, i});
				}
			}
		}
		
		out.println("! " + 
				rets.get(0)[0] + " " + 
				rets.get(0)[1] + " " + 
				rets.get(1)[0] + " " + 
				rets.get(1)[1]);
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
		new E().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}