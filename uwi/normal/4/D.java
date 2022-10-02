//package round4;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class D {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	static class Datum implements Comparable<Datum> {
		public int w;
		public int h;
		public int ind;

		public Datum(int w, int h, int ind) {
			this.w = w;
			this.h = h;
			this.ind = ind;
		}

		public int compareTo(Datum o) {
			return w - o.w;
		}

		public String toString() {
			return "(" + w + "," + h + ")";
		}
	}
	
	void solve()
	{
		int n = ni();
		int cw = ni();
		int ch = ni();
		Datum[] e = new Datum[n];
		for(int i = 0;i < n;i++){
			e[i] = new Datum(ni(), ni(), i);
		}
		Arrays.sort(e);
		
		int[] dp = new int[n+1];
		int[] prev = new int[n+1];
		prev[0] = -1;
		for(int i = 1;i <= n;i++){
			int max = (e[i-1].w > cw && e[i-1].h > ch ? 1 : 0);
			int p = -1;
			for(int j = 1;j < i;j++){
				if(e[i-1].w > e[j-1].w && e[i-1].h > e[j-1].h){
					if(dp[j] > 0 && max < dp[j] + 1){
						max = dp[j] + 1;
						p = j;
					}
				}
			}
			dp[i] = max;
			prev[i] = p;
		}
		
		int gm = 0;
		int gi = -1;
		for(int i = 1;i <= n;i++){
			if(gm < dp[i]){
				gm = dp[i];
				gi = i;
			}
		}
		
		if(gm == 0){
			out.println(0);
		}else{
			List<Integer> l = new ArrayList<Integer>();
			for(int i = gi;i != -1;i = prev[i]){
				if(i != -1)l.add(e[i-1].ind+1);
			}
			out.println(gm);
			if(gm != l.size()){
				throw new AssertionError();
			}
			Collections.reverse(l);
			for(int u : l){
				out.print(u + " ");
			}
			out.println();
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