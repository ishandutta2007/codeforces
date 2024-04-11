//package round27;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "4 4 2 4 1 2 3 2 1 3 1";
	private String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		int[][] wl = new int[n][n];
		int[] ws = new int[n];
		for(int i = 0;i < n * (n - 1) / 2 - 1;i++){
			int w = ni() - 1;
			int l = ni() - 1;
			ws[w]++;
			wl[w][l] = 1;
			wl[l][w] = -1;
		}
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < i;j++){
				if(wl[i][j] == 0){
					if(ws[i] >= ws[j]){
						out.println((i+1) + " " + (j+1));
					}else{
						out.println((j+1) + " " + (i+1));
					}
					return;
				}
			}
		}
	}
	
	public void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new B().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private void tr(Object... o) { if(INPUT.length() == 0)System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
}