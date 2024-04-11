//package yandex2011.q2;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class D {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = new int[n];
		for(int i = 0;i < n;i++){
			a[i] = ni();
		}
		
		long[][] dp = new long[(n+1)/2][n]; // phase left
		int[][] prev = new int[(n+1)/2][n];
		int[][][] use = new int[(n+1)/2][n][2];
		for(int i = 0;i < (n+1)/2;i++){
			Arrays.fill(dp[i], Integer.MAX_VALUE);
		}
		dp[0][0] = 0;
		long last = Integer.MAX_VALUE;
		int lastj = -1;
		for(int i = 0;i < (n+1)/2;i++){
			for(int j = 0;j < n;j++){
				if(2*i+1 >= n){
					long v = dp[i][j] + a[j];
					if(last > v){
						last = v;
						lastj = j;
					}
				}else if(2*i+2 >= n){
					long v = dp[i][j] + Math.max(a[j], a[2*i+1]);
					if(last > v){
						last = v;
						lastj = j;
					}
				}else{
					{
						long v = dp[i][j] + Math.max(a[2*i+1], a[2*i+2]);
						if(dp[i+1][j] > v){
							dp[i+1][j] = v;
							prev[i+1][j] = j;
							use[i+1][j][0] = 2*i+1+1;
							use[i+1][j][1] = 2*i+2+1;
						}
					}
					{
						long v = dp[i][j] + Math.max(a[j], a[2*i+2]);
						if(dp[i+1][2*i+1] > v){
							dp[i+1][2*i+1] = v;
							prev[i+1][2*i+1] = j;
							use[i+1][2*i+1][0] = j+1;
							use[i+1][2*i+1][1] = 2*i+2+1;
						}
					}
					{
						long v = dp[i][j] + Math.max(a[j], a[2*i+1]);
						if(dp[i+1][2*i+2] > v){
							dp[i+1][2*i+2] = v;
							prev[i+1][2*i+2] = j;
							use[i+1][2*i+2][0] = j+1;
							use[i+1][2*i+2][1] = 2*i+1+1;
						}
					}
				}
			}
		}
		out.println(last);
		
		List<String> l = new ArrayList<String>();
		int cur = 0;
		int pos = 0;
		if(n % 2 == 0){
			l.add((lastj+1) + " " + n);
		}else{
			l.add(Integer.toString(lastj+1));
		}
		cur = lastj;
		pos = (n-1)/2;
		while(pos >= 1){
			l.add(use[pos][cur][0] + " " + use[pos][cur][1]);
			cur = prev[pos][cur];
			pos--;
		}
		for(int i = l.size() - 1;i >= 0;i--){
			out.println(l.get(i));
		}
	}
	
	void run() throws Exception
	{
//		int n = 999;
//		StringBuilder sb = new StringBuilder(n + " ");
//		Random r = new Random();
//		for(int i = 0;i < n;i++){
//			sb.append(r.nextInt(1000000) + " ");
//		}
//		INPUT = sb.toString();
//
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