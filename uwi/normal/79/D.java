//package round71;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class D {
	Scanner in;
	PrintWriter out;
//	String INPUT = "10000 2 2 1 10000 5000 5002";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int k = ni();
		int l = ni();
		BitSet bs = new BitSet();
		for(int i = 0;i < k;i++){
			bs.set(ni()-1);
		}
		
		int[] a = new int[l];
		for(int i = 0;i < l;i++){
			a[i] = ni();
		}
		
		List<Integer> de = new ArrayList<Integer>();
		for(int i = bs.nextSetBit(0);i != -1;i = bs.nextSetBit(i + 1)){
			if(i == 0 || !bs.get(i-1)){
				de.add(i);
			}
			if(i == n - 1 || !bs.get(i+1)){
				de.add(i+1);
			}
		}
		tr(de);
		if(de.size() % 2 != 0){
			out.println(-1);
			return;
		}
		
		int INF = Integer.MAX_VALUE / 3;
		
		int u = de.size();
		int[][] D = new int[u][u];
		for(int i = 0;i < u;i++){
			int[] d = new int[n+1];
			Arrays.fill(d, INF);
			d[de.get(i)] = 0;
			Queue<Integer> q = new ArrayDeque<Integer>();
			q.add(de.get(i));
			while(q.size() > 0){
				int cur = q.poll();
				for(int j = 0;j < l;j++){
					int nex = cur - a[j];
					if(nex >= 0 && d[nex] == INF){
						d[nex] = d[cur] + 1;
						q.add(nex);
					}
					nex = cur + a[j];
					if(nex <= n && d[nex] == INF){
						d[nex] = d[cur] + 1;
						q.add(nex);
					}
				}
			}
			
			for(int j = i+1;j < u;j++){
				D[j][i] = D[i][j] = d[de.get(j)];
			}
		}
		
		int[] dp = new int[1<<u];
		Arrays.fill(dp, INF);
		dp[0] = 0;
		for(int i = 1;i < 1<<u;i++){
			if(Integer.bitCount(i) % 2 == 0){
				int cost = INF;
				for(int j = 0;j < u;j++){
					if(i>>j<<31 < 0){
						for(int o = j+1;o < u;o++){
							if(i>>o<<31 < 0){
								cost = Math.min(cost, dp[i^(1<<j)^(1<<o)] + D[j][o]);
							}
						}
					}
				}
				dp[i] = cost;
			}
		}
		
		if(dp[(1<<u)-1] == INF){
			out.println(-1);
		}else{
			out.println(dp[(1<<u)-1]);
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
		new D().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}