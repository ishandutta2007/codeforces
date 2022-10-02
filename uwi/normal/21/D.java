//package round21;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class D2 {
	Scanner in;
	PrintWriter out;
//	String INPUT = "4 3 1 2 3 1 3 4 2 4 3";
//	String INPUT = "4 4 1 2 3 1 3 4 3 2 3 3 4 1";
//	String INPUT = "3 4 1 2 1 2 3 1 3 1 1 1 2 1";
	String INPUT = "";
	
	int INF = Integer.MAX_VALUE / 2;
	
	void solve()
	{
		int n = ni();
		int m = ni();
		int[][] d = new int[n][n];
		for(int[] r : d)Arrays.fill(r, INF);
		int[] touch = new int[n];
		int s = 0;
		for(int i = 0;i < m;i++){
			int f = ni() - 1;
			int t = ni() - 1;
			int w = ni();
			d[f][t] = Math.min(d[f][t], w);
			d[t][f] = d[f][t];
			touch[f]++;
			touch[t]++;
			s += w;
		}
		
		for(int k = 0;k < n;k++){
			for(int i = 0;i < n;i++){
				for(int j = 0;j < n;j++){
					if(d[i][j] > d[i][k] + d[k][j]){
						d[i][j] = d[i][k] + d[k][j];
					}
				}
			}
		}
		
		int left = 0;
		for(int i = 0;i < n;i++){
			if(i >= 1 && touch[i] > 0 && d[0][i] == INF){
				out.println(-1);
				return;
			}
			if(touch[i] % 2 == 1){
				left++;
			}
		}
		
//		tr(s);
//		tr(touch);
		out.println(rec(touch, d, n, 0, left) + s);
	}
	
	int rec(int[] touch, int[][] d, int n, int p, int left)
	{
		if(left == 0)return 0;
		int min = INF;
		for(int i = p;i < n;i++){
			if(touch[i] % 2 == 1){
				touch[i]--;
				for(int j = i + 1;j < n;j++){
					if(touch[j] % 2 == 1){
						touch[j]--;
//						long v = left == 2 ? d[j][0] : 0;
						int v = d[i][j] + rec(touch, d, n, i + 1, left - 2);
//						tr(v);
						min = Math.min(min, v);
						touch[j]++;
					}
				}
				touch[i]++;
			}
		}
//		if(min == INF)return INF;
		return min;
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
		new D2().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
	static String join(int[] a, int d){StringBuilder sb = new StringBuilder();for(int v : a){sb.append(v + d + " ");}return sb.toString();}
}