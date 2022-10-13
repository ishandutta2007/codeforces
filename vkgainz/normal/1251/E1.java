import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class voting {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		StringBuilder sb = new StringBuilder();
		for(int r=0;r<t;r++) {
			int n = sc.nextInt();
			State[] s= new State[n];
			for(int i=0;i<n;i++) {
				s[i] = new State(sc.nextInt(),sc.nextInt());
			}
			Arrays.sort(s, new Comparator<State>() {

				@Override
				public int compare(State o1, State o2) {
					// TODO Auto-generated method stub
					if(o1.v!=o2.v)
					return o1.v-o2.v;
					else return o1.p-o2.p;
				}
				
			});
			long[][] dp = new long[n][n];
			for(int i=0;i<n;i++) {
				for(int j=n-1;j>=0;j--) {
					if(j>=s[i].v || j>=n-1) {
						dp[i][j] = 0;
						continue;
					}
					if(i==0) {
						dp[i][j] = s[i].p;
						continue;
					}
					dp[i][j] = s[i].p+dp[i-1][j+1];
					if(i+j>=s[i].v) {
						dp[i][j] = Math.min(dp[i][j],dp[i-1][j]);
					}
				}
			}
			sb.append(dp[n-1][0] + " ");
			
			
		}
		System.out.println(sb.toString());
	}
	static class State{
		int v; int p;
		public State(int v,int p) {
			this.v = v; this.p = p;
		}
		
	}
}