//package round62;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
//	String INPUT = "6 "+
//	"1 2 0 5 1 "+
//	"1 3 0 5 1 "+
//	"1 4 0 5 1 "+
//	"1 5 0 5 1 "+
//	"1 6 0 5 1 "+
//	"2 3 0 5 1 "+
//	"2 4 1 5 1 "+
//	"2 5 0 5 1 "+
//	"2 6 0 5 1 "+
//	"3 4 0 5 1 "+
//	"3 5 0 5 1 "+
//	"3 6 0 5 1 "+
//	"4 5 0 5 1 "+
//	"4 6 0 5 1 "+
//	"5 6 0 5 1 ";
	String INPUT = "";
	int[][] l,h,a;
	int n,m;
	
	void solve()
	{
		n = ni();
		m = n*(n-1)/2;
		l = new int[n][n];
		h = new int[n][n];
		a = new int[n][n];
		ff = new int[n][n];
		for(int i = 0;i < m;i++){
			int f = ni() - 1;
			int s = ni() - 1;
			l[f][s] = ni();
			h[f][s] = ni();
			a[f][s] = ni();
		}
		
		rec(0, 1, 0, 0);
		if(minf == 99999999){
			out.println("-1 -1");
		}else{
			out.println(minf + " " + maxc);
		}
	}
	
	int minf = 99999999;
	int maxc = 0;
	int[][] ff;
	
	void rec(int r, int c, int cost, int flow)
	{
		if(c == n - 1){
			int sin = 0;
			if(r == 0){
				sin = l[r][c];
				flow += sin;
			}else{
				for(int i = 0;i <= r-1;i++){
					sin += ff[i][r];
				}
				for(int i = r+1;i <= c-1;i++){
					sin -= ff[r][i];
				}
			}
			if(l[r][c] <= sin && sin <= h[r][c]){
				cost += sin==0 ? 0 : a[r][c]+sin*sin;
				r++;
				c = r+1;
				if(r == n - 2){
					rec(r, c, cost, flow);
					return;
				}else if(r == n - 1){
					if(flow < minf || (flow == minf && cost > maxc)){
						minf = flow;
						maxc = cost;
					}
					return;
				}
			}else{
				return;
			}
		}
		for(int i = l[r][c];i <= h[r][c];i++){
			if(flow+(r==0 ? i : 0) <= minf){
				int nc = cost+(i==0 ? 0 : a[r][c]+i*i);
				int nf = flow+(r==0 ? i : 0);
				ff[r][c] = i;
				rec(r, c+1, nc, nf);
			}
		}
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
		new C().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}