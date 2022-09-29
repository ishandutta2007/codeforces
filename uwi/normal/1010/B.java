//package round499;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
//	Random gen = new Random();
//	int X = gen.nextInt(1000000000)+1;
//	int N = 1;//gen.nextInt(30)+1;
//	int[] u = new int[N];
//	int turn = 0;
//	{
//		INPUT = 1000000000 + " " + N + "\n";
//		for(int i = 0;i < N;i++){
//			u[i] = gen.nextInt(2);
//		}
//	}
	
	int step = 0;
	
	int go(int y)
	{
		if(++step > 60)throw new RuntimeException();
		out.println(y);
		out.flush();
//		if(turn == N)turn = 0;
//		if(u[turn++] == 1){
//			return X > y ? 1 : X < y ? -1 : 0;
//		}else{
//			return X < y ? 1 : X > y ? -1 : 0;
//		}
		return ni();
	}
	
	
	
	void solve()
	{
		int m = ni(), n = ni();
		int[] a = new int[n];
		for(int i = 0;i < n;i++){
			a[i] = go(1);
			if(a[i] == 0){
				return;
			}
		}
		// correct : 1
		int low = 2, high = m;
		for(int i = 0;;i++){
			int h = high+low>>1;
			int res = go(h);
			if(res == 0){
//				tr(X, h);
				return;
			}
			res *= a[i%n];
			if(res == 1){
				low = h+1;
			}else{
				high = h-1;
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
		new B().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}