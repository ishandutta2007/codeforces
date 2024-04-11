//package round371;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class BT {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	
	int q(int r1, int c1, int r2, int c2)
	{
		out.printf("? %d %d %d %d\n", r1+1, c1+1, r2+1, c2+1);
		out.flush();
		return ni();
	}
	
	void e(int r1, int c1, int r2, int c2, int r3, int c3, int r4, int c4)
	{
		out.printf("! %d %d %d %d %d %d %d %d\n", 
				r1+1, c1+1, r2+1, c2+1,
				r3+1, c3+1, r4+1, c4+1
				);
		out.flush();
	}
	
	void solve()
	{
		int n = ni();
		int cu = -1, cv = -1;
		{
			int low = -1, high = n-1;
			while(high - low > 1){
				int h = high+low>>1;
				if(q(0, 0, n-1, h) >= 2){
					high = h;
				}else{
					low = h;
				}
			}
			cu = high;
		}
		{
			int low = -1, high = n-1;
			while(high - low > 1){
				int h = high+low>>1;
				if(q(0, 0, n-1, h) >= 1){
					high = h;
				}else{
					low = h;
				}
			}
			cv = high;
		}
		
		int du = -1, dv = -1;
		{
			int low = 0, high = n;
			while(high - low > 1){
				int h = high+low>>1;
				if(q(0, h, n-1, n-1) >= 2){
					low = h;
				}else{
					high = h;
				}
			}
			du = low;
		}
		{
			int low = 0, high = n;
			while(high - low > 1){
				int h = high+low>>1;
				if(q(0, h, n-1, n-1) >= 1){
					low = h;
				}else{
					high = h;
				}
			}
			dv= low;
		}
		
		int eu = -1, ev = -1;
		{
			int low = -1, high = n-1;
			while(high - low > 1){
				int h = high+low>>1;
				if(q(0, 0, h, n-1) >= 2){
					high = h;
				}else{
					low = h;
				}
			}
			eu = high;
		}
		{
			int low = -1, high = n-1;
			while(high - low > 1){
				int h = high+low>>1;
				if(q(0, 0, h, n-1) >= 1){
					high = h;
				}else{
					low = h;
				}
			}
			ev = high;
		}
		
		int fu = -1, fv = -1;
		{
			int low = 0, high = n;
			while(high - low > 1){
				int h = high+low>>1;
				if(q(h, 0, n-1, n-1) >= 2){
					low = h;
				}else{
					high = h;
				}
			}
			fu = low;
		}
		{
			int low = 0, high = n;
			while(high - low > 1){
				int h = high+low>>1;
				if(q(h, 0, n-1, n-1) >= 1){
					low = h;
				}else{
					high = h;
				}
			}
			fv= low;
		}
		
		// cv <= cu
		// du <= dv
		int[][][] canc = {
				{{du, cu}, {dv, cv}},
				{{du, cv}, {dv, cu}}
		};
		int[][][] canr = {
				{{fu, eu}, {fv, ev}},
				{{fu, ev}, {fv, eu}}
		};
		for(int[][] cr : canr){
			if(cr[0][0] > cr[0][1])continue;
			if(cr[1][0] > cr[1][1])continue;
			for(int[][] cc : canc){
				if(cc[0][0] > cc[0][1])continue;
				if(cc[1][0] > cc[1][1])continue;
				for(int z = 0;z < 2;z++){
					if(
							q(cr[0][0], cc[0^z][0], cr[0][1], cc[0^z][1]) == 1 &&
							q(cr[1][0], cc[1^z][0], cr[1][1], cc[1^z][1]) == 1){
						e(cr[0][0], cc[0^z][0], cr[0][1], cc[0^z][1], cr[1][0], cc[1^z][0], cr[1][1], cc[1^z][1]);
						return;
					}
				}
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
		new BT().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}