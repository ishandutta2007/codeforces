//package round25;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class C {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "3 0 4 5 4 0 9 5 9 0 2 2 3 8 1 2 1";
//	private String INPUT = "2 0 5 5 0 1 1 2 3";
	private String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		long[][] d = new long[n][n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				d[i][j] = ni();
			}
		}
		
		int k = ni();
		long prevsum = -1;
		for(int s = 0;s < k;s++){
			int a = ni() - 1;
			int b = ni() - 1;
			long c = ni();
			if(prevsum != -1 && c >= d[a][b]){
				out.print(prevsum + " ");
				continue;
			}
			c = Math.min(c, d[a][b]);
			d[a][b] = c;
			d[b][a] = c;
			
//			for(long u = 0;u < n;u++){
//				if(d[u][a] > d[u][b] + c){
//					d[u][a] = d[u][b] + c;
//					d[a][u] = d[u][a];
//				}
//				if(d[u][b] > d[u][a] + c){
//					d[u][b] = d[u][a] + c;
//					d[b][u] = d[u][b];
//				}
//			}
			
			for(int i = 0;i < n;i++){
				for(int j = 0;j < n;j++){
					if(d[i][j] > d[i][a] + d[a][j]){
						d[i][j] = d[i][a] + d[a][j];
						d[j][i] = d[i][j];
					}
				}
			}
			for(int i = 0;i < n;i++){
				for(int j = 0;j < n;j++){
					if(d[i][j] > d[i][b] + d[b][j]){
						d[i][j] = d[i][b] + d[b][j];
						d[j][i] = d[i][j];
					}
				}
			}
			long sum = 0;
			for(int u = 0;u < n;u++){
				for(int v = 0;v < u;v++){
//					long q = Math.min(Math.min(d[u][v], d[u][a] + c + d[b][v]), d[u][b] + c + d[a][v]);
//					d[u][v] = q;
//					d[v][u] = q;
					sum += d[u][v];
				}
			}
			out.print(sum + " ");
			prevsum = sum;
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
		new C().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private static void tr(Object... o) { System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
}