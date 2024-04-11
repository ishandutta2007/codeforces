//package round73;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] u = new int[n+1];
		for(int i = 2;i <= n;i++){
			BitSet bs = new BitSet();
			for(int k = 2;k * k <= 2*i;k++){
				if((2*i-k*(k-1))%(2*k) == 0){
					int b = (2*i-k*(k-1))/(2*k);
					if(b >= 1){
						int x = 0;
						for(int l = b;l <= b+k-1;l++){
							x ^= u[l];
						}
						bs.set(x);
					}
				}
			}
			u[i] = bs.nextClearBit(0);
		}
		
		if(u[n] == 0){
			out.println(-1);
		}else{
			int i = n;
			for(int k = 2;k * k <= 2*i;k++){
				if((2*i-k*(k-1))%(2*k) == 0){
					int b = (2*i-k*(k-1))/(2*k);
					if(b >= 1){
						int x = 0;
						for(int l = b;l <= b+k-1;l++){
							x ^= u[l];
						}
						if(x == 0){
							out.println(k);
							return;
						}
					}
				}
			}
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
		new C().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}