//package round82;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "5\r\n" +
			"2100 512 150 200\r\n" +
			"2000 2048 240 350\r\n" +
			"2300 1024 200 320\r\n" +
			"2500 2048 80 300\r\n" +
			"2000 512 180 150";
	
	void solve()
	{
		int n = ni();
		int[][] a = new int[n][4];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < 4;j++){
				a[i][j] = ni();
			}
		}
		BitSet dead = new BitSet();
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(i != j){
					if(a[i][0] < a[j][0] && a[i][1] < a[j][1] && a[i][2] < a[j][2]){
						dead.set(i);
					}
				}
			}
		}
		
		int min = 9999999;
		int mini = -1;
		for(int i = dead.nextClearBit(0);i < n;i = dead.nextClearBit(i + 1)){
			if(a[i][3] < min){
				min = a[i][3];
				mini = i;
			}
		}
		out.println(mini+1);
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