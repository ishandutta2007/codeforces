//package round63;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class D {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int sx = ni();
		int sy = ni();
		int n = ni();
		int d = ni();
		int[] vx = new int[n];
		int[] vy = new int[n];
		for(int i = 0;i < n;i++){
			vx[i] = ni();
			vy[i] = ni();
		}
		int T = 200;
		boolean[][] dp = new boolean[401][401];
		for(int y = 200;y >= -200;y--){
			for(int x = 200;x >= -200;x--){
				if(x*x+y*y > d*d){
					dp[x+T][y+T] = true;
				}else{
					boolean win = false;
					for(int i = 0;i < n;i++){
						int nx = x+vx[i];
						int ny = y+vy[i];
						if(nx*nx+ny*ny <= d*d){
							if(!dp[nx+T][ny+T]){
								win = true;
								break;
							}
						}
					}
					dp[x+T][y+T] = win;
				}
			}
		}
		
		out.println(dp[sx+T][sy+T] ? "Anton" : "Dasha");
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
		new D().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}