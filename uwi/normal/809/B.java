//package round415;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class BT {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	boolean get(int x, int y)
	{
		out.println(1 + " " + x + " " + y);
		out.flush();
		String z = in.next();
		return z.equals("TAK");
	}
	
	void solve()
	{
		int n = ni(), K = ni();
		int[] res = go(1, n, 999999, true);
		if(res.length == 2){
			out.println(2 + " " + res[0] + " " + res[1]);
			out.flush();
			return;
		}
		if(res.length == 0)throw new RuntimeException();
		
		int ans1 = res[0];
		if(ans1+1 <= n && check(ans1, ans1+1)){
			out.println(2 + " " + ans1 + " " + (ans1+1));
			out.flush();
			return;
		}
		if(ans1-1 >= 1 && check(ans1-1, ans1)){
			out.println(2 + " " + (ans1-1) + " " + (ans1));
			out.flush();
			return;
		}
		
		res = go(ans1+1, n, ans1+1, true);
		if(res.length == 2){
			out.println(2 + " " + res[0] + " " + res[1]);
			out.flush();
			return;
		}
		if(res.length == 1){
			out.println(2 + " " + ans1 + " " + res[0]);
			out.flush();
			return;
		}
		
		res = go(1, ans1-1, ans1-1, false);
		assert res.length >= 1;
		out.println(2 + " " + ans1 + " " + res[0]);
		out.flush();
	}
	
	boolean check(int u, int v)
	{
		boolean lh = get(u, u+1);
		boolean hl = get(u+1, u);
		if(lh && hl){
			return true;
		}
		return false;
	}
	
	int[] go(int l, int r, int ng, boolean left)
	{
		if(l >= r)return new int[0];
		
		int low = l, high = r;
		while(high - low > 1){
			int h = high+low>>1;
			boolean res = get(h, h+1);
			if(res){
				high = h;
			}else{
				low = h;
			}
		}
		
		assert high - low == 1;
		boolean lh = get(low, high);
		boolean hl = get(high, low);
		if(lh && hl){
			return new int[]{low, high};
		}
		if(lh){
			if(low == ng)return new int[0];
			return new int[]{low};
		}else if(hl){
			if(high == ng)return new int[0];
			return new int[]{high};
		}else{
			throw new RuntimeException();
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
		new BT().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = true;//System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}