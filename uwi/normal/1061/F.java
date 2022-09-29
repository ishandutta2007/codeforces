//package round523;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

public class F2 {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	boolean q(int a, int b, int c)
	{
		out.println("? " + (a+1) + " " + (b+1) + " " + (c+1));
		out.flush();
		return in.next().trim().equals("Yes");
	}
	
	void solve()
	{
		int n = ni(), K = ni();
		int D = 0;
		for(int q = 1, s = 0;;D++){
			s += q;
			if(s == n)break;
			q *= K;
		}
		
//		Random gen = new SecureRandom();
		Random gen = new Random(114514);
		List<Integer> ride = null;
		int x, y;
		while(true){
			x = gen.nextInt(n);
			y = gen.nextInt(n);
			if(x == y)continue;
			ride = new ArrayList<>();
			for(int i = 0;i < n;i++){
				if(i == x || i == y)continue;
				if(q(x, i, y))ride.add(i);
			}
			if(ride.size() == 2*D-1){
				break;
			}
		}
		
		for(int r : ride){
			int dep = 0;
			for(int o : ride){
				if(o == r)continue;
				if(q(x, o, r)){
					dep++;
				}
			}
			if(dep == D-1){
				out.println("! " + (r+1));
				out.flush();
				return;
			}
		}
		throw new RuntimeException();
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