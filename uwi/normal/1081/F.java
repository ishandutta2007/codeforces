//package avito2018b;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class F {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	int go(int l, int r)
	{
		out.println("? " + (l+1) + " "+ (r+1));
		out.flush();
		return ni();
	}
	
	void solve()
	{
		int n = ni(), t = ni();
		
		if(n == 1){
			out.println("! " + t);
			out.flush();
			return;
		}
		if(n == 2){
			if(t == 2){
				out.println("! 11");
				out.flush();
				return;
			}
			if(t == 0){
				out.println("! 00");
				out.flush();
				return;
			}
			int f = 0;
			int pre = t;
			while(true){
				int h = go(1, 1);
				if((h-pre) % 2 == 0){
					f ^= 1;
				}else{
					f ^= 2;
				}
				pre = h;
				if(f == 2){
					if(h > t){
						out.println("! 10");
					}else{
						out.println("! 01");
					}
					out.flush();
					return;
				}
			}
		}
		
		int[] xs = new int[n+1];
		xs[n] = t;
		for(int d = 2;d <= n-1;d++){
			int r = d-1;
			int l = 0;
			if(n % 2 == d % 2){
				l++;
			}
			if(d % 2 == 1){
				int f = 0;
				int pre = t;
				while(true){
					int h = go(l, r);
					if((pre-h) % 2 == 0){
						// even
						f ^= 2;
					}else{
						f ^= 1;
					}
					pre = h;
					
					// x -> d-x
					// d-x - x = h - t
					// x = (d-(h-t))/2
					if(f == 1){
						int x = (d-(h-t))/2;
						xs[d] = x;
						break;
					}
				}
				while(true){
					int h = go(l, r);
					if((h-pre) % 2 == 0){
						// even
						f ^= 2;
					}else{
						f ^= 1;
					}
					pre = h;
					if(f == 0)break;
				}
			}else{
				int f = 0;
				int pre = t;
				while(true){
					int h = go(l, r);
					if((pre-h) % 2 == 0){
						// even
						f ^= 1;
					}else{
						f ^= 2;
					}
					pre = h;
					
					// x -> d-x
					// d-x - x = h - t
					// x = (d-(h-t))/2
					if(f == 1){
						int x = (d-(h-t))/2;
						xs[d] = x;
						break;
					}
				}
				while(true){
					int h = go(l, r);
					if((h-pre) % 2 == 0){
						// even
						f ^= 1;
					}else{
						f ^= 2;
					}
					pre = h;
					if(f == 0)break;
				}
			}
		}
		
		{
			int r = 1;
			int l = 1;
			if((n-l) % 2 == 0){
				r++;
			}
			int f = 0;
			int pre = t;
			while(true){
				int h = go(l, r);
				if((pre-h+100000) % 2 == (r+1) % 2){
					f ^= 1;
				}else{
					f ^= 2;
				}
				pre = h;
				
				// x -> (n-l)-x
				// d-x - x = h - t
				// x = (d-(h-t))/2
				if(f == 2){
					assert ((n-l)-(h-t)) % 2 == 0;
					int x = ((n-l)-(h-t))/2;
					xs[1] = t-x;
					break;
				}
			}
		}
		
		int[] ans = new int[n];
		for(int i = n-1;i >= 0;i--){
			ans[i] = xs[i+1] - xs[i];
		}
		out.print("! ");
		for(int i = 0;i < n;i++){
			out.print(ans[i]);
		}
		out.println();
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
		new F().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}