//package round45;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class E2 {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int h = ni();
		int t = ni();
		int R = ni();
		int S = R + 1;
		int n = ni();
		int[] rhh = new int[n];
		int[] rht = new int[n];
		for(int i = 0;i < n;i++){
			rhh[i] = ni();
			rht[i] = ni();
		}
		
		int m = ni();
		int[] rth = new int[m];
		int[] rtt = new int[m];
		for(int i = 0;i < m;i++){
			rth[i] = ni();
			rtt[i] = ni();
		}
		
		BitSet visited = new BitSet();
		BitSet q = new BitSet();
		BitSet[] ig = new BitSet[S*S]; // 
		q.set(h * S + t);
		int turn = 1;
		// BFS. (h,t)(0,0)
		while(!q.isEmpty()){
			visited.or(q);
			BitSet nq = new BitSet();
			for(int cur = q.nextSetBit(0);cur != -1;cur = q.nextSetBit(cur+1)){
				int hh = cur / S;
				int tt = cur % S;
				for(int i = 0;i < n && i + 1 <= hh;i++){
					int nh = hh - (i + 1) + rhh[i];
					int nt = tt + rht[i];
					if(nh == 0 && nt == 0){
						out.println("Ivan");
						out.println(turn);
						return;
					}
					if(nh + nt <= R){
						if(ig[nh*S+nt] == null)ig[nh*S+nt] = new BitSet();
						ig[nh * S + nt].set(cur);
					}
					if(nh + nt <= R && !visited.get(nh * S + nt)){
						nq.set(nh * S + nt);
					}
				}
				for(int i = 0;i < m && i + 1 <= tt;i++){
					int nh = hh + rth[i];
					int nt = tt - (i + 1) + rtt[i];
					if(nh == 0 && nt == 0){
						out.println("Ivan");
						out.println(turn);
						return;
					}
					if(nh + nt <= R){
						if(ig[nh*S+nt] == null)ig[nh*S+nt] = new BitSet();
						ig[nh * S + nt].set(cur);
					}
					if(nh + nt <= R && !visited.get(nh * S + nt)){
						nq.set(nh * S + nt);
					}
				}
			}
			q = nq;
			
			turn++;
		}
		
		if(ig[h * S + t] != null){
			out.println("Draw");
			return;
		}
		
		// 
		int[] qt = new int[S*S];
		int pp = 0;
		int qq = 0;
		qt[qq++] = h * S + t;
		for(;pp < qq;pp++){
			int cur = qt[pp];
			int hh = cur / S;
			int tt = cur % S;
			for(int i = 0;i < n && i + 1 <= hh;i++){
				int nh = hh - (i + 1) + rhh[i];
				int nt = tt + rht[i];
				if(nh + nt <= R){
					if(ig[nh * S + nt] == null)continue;
					ig[nh * S + nt].clear(cur);
					if(ig[nh * S + nt].isEmpty()){
						ig[nh * S + nt] = null;
						qt[qq++] = nh * S + nt;
					}
				}
			}
			for(int i = 0;i < m && i + 1 <= tt;i++){
				int nh = hh + rth[i];
				int nt = tt - (i + 1) + rtt[i];
				if(nh + nt <= R){
					if(ig[nh * S + nt] == null)continue;
					ig[nh * S + nt].clear(cur);
					if(ig[nh * S + nt].isEmpty()){
						ig[nh * S + nt] = null;
						qt[qq++] = nh * S + nt;
					}
				}
			}
		}
		// Draw
		for(int i = 0;i < S;i++){
			for(int j = 0;i + j < S;j++){
				if(ig[i*S+j] != null && !ig[i*S+j].isEmpty()){
					out.println("Draw");
					return;
				}
			}
		}
		int[] iqt = new int[S*S];
		Arrays.fill(iqt, -1);
		for(int i = 0;i < qq;i++){
			iqt[qt[i]] = i;
		}
		
		// DP. 
		int[] dp = new int[qq];
		dp[0] = 1;
		int max = 1;
		for(int l = 0;l < qq;l++){
			int cur = qt[l];
			int hh = cur / S;
			int tt = cur % S;
			for(int i = 0;i < n && i + 1 <= hh;i++){
				int nh = hh - (i + 1) + rhh[i];
				int nt = tt + rht[i];
				if(nh + nt <= R){
					int j = nh*S+nt;
					dp[iqt[j]] = Math.max(dp[iqt[j]], dp[l] + 1);
				}else{
					max = Math.max(max, dp[l]);
				}
			}
			for(int i = 0;i < m && i + 1 <= tt;i++){
				int nh = hh + rth[i];
				int nt = tt - (i + 1) + rtt[i];
				if(nh + nt <= R){
					int j = nh*S+nt;
					dp[iqt[j]] = Math.max(dp[iqt[j]], dp[l] + 1);
				}else{
					max = Math.max(max, dp[l]);
				}
			}
		}
		out.println("Zmey");
		out.println(max);
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
		new E2().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}