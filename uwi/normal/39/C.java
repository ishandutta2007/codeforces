//package school1;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.BitSet;
import java.util.HashMap;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;
import java.util.TreeSet;

public class CX {
	Scanner in;
	PrintWriter out;
//	String INPUT = "4\r\n" + 
//	"1 1\r\n" + 
//	"2 2\r\n" + 
//	"4 1\r\n" + 
//	"5 1";
	String INPUT = "5 5 1 6 2 7 3 8 4 9 5";
	
	void solve()
	{
		int n = ni();
		int[] l = new int[n];
		int[] r = new int[n];
		
		TreeSet<Integer> ts = new TreeSet<Integer>();
		for(int i = 0;i < n;i++) {
			int c = ni();
			int rad = ni();
			l[i] = c-rad;
			r[i] = c+rad;
			ts.add(l[i]);
			ts.add(r[i]);
		}
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		int p = 0;
		for(int k : ts)map.put(k, p++);
		int[][] pre = new int[p][p];
		int[] pp = new int[p];
		for(int i = 0;i < n;i++) {
			l[i] = map.get(l[i]);
			r[i] = map.get(r[i]);
			pre[l[i]][r[i]] = i+1;
			pp[l[i]]++;
		}
		int[][] pa = new int[p][];
		for(int i = 0;i < p;i++) {
			pa[i] = new int[pp[i]];
		}
		for(int i = 0;i < n;i++) {
			pa[l[i]][--pp[l[i]]] = r[i];
		}
		for(int i = 0;i < p;i++) {
			Arrays.sort(pa[i]);
		}
		int[][] dp = new int[p][p];
		
		for(int len = 1;len <= p-1;len++) {
			for(int from = 0;from+len <= p-1;from++) {
				int max = dp[from][from+1] + dp[from+1][from+len];
				for(int e : pa[from]) {
					if(e > from+len) {
						break;
					}else if(e == from+len) {
						max++;
						break;
					}
					max = Math.max(max, dp[from][e] + dp[e][from+len]);
				}
//				max += pre[from][from+len] > 0 ? 1 : 0;
				dp[from][from+len] = max;
			}
		}
		out.println(dp[0][p-1]);
		Queue<Integer> q = new ArrayDeque<Integer>();
		q.add(0*p+p-1);
		BitSet bs = new BitSet();
		while(q.size() > 0) {
			int cur = q.poll();
			int from = cur / p;
			int to = cur % p;
			int v = dp[from][to];
			if(pre[from][to] > 0) {
				bs.set(pre[from][to]);
				v--;
			}
			int mid = from+1;
			for(int e : pa[from]) {
				if(e >= to)break;
				if(v == dp[from][e] + dp[e][to]) {
					mid = e;
					break;
				}
			}
			if(from == mid || mid == to) {
			}else {
				if(mid-from >= 1) {
					q.add(from*p+mid);
				}
				if(to-mid >= 1) {
					q.add(mid*p+to);
				}
			}
		}
		for(int i = bs.nextSetBit(0);i != -1;i = bs.nextSetBit(i+1)){
			out.print(i + " ");
		}
		out.println();
	}
	
	void run() throws Exception
	{
//		int n = 2000;
//		StringBuilder sb = new StringBuilder(n + " ");
//		Random r = new Random();
//		for(int i = 0;i < n;i++){
//			sb.append(r.nextInt(200000) + " ");
//			sb.append(r.nextInt(200000) + " ");
//		}
//		INPUT = sb.toString();
		
		in = oj ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new CX().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}