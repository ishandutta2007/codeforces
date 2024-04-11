import java.util.Scanner;

public class C {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0) {
			t--;
			int n = sc.nextInt();
			int k = sc.nextInt();
			String s = sc.next();
			int dp[] = new int[n];
			if(s.charAt(0)=='1') {
				dp[0] = 0;
			}
			else {
				dp[0] = 1;
			}
			int lastOne = -1;
			if(s.charAt(0)=='1') {
				lastOne = 0;
			}
			for(int i=1;i<n;i++) {
				if(s.charAt(i)=='1') {
					if(i>=k+1) {
						dp[i] = dp[i-k-1];
					}
					else {
						dp[i] = 0;
					}
					lastOne = i;
				}
				else {
					if(i>=k+1) {
						if((i-lastOne)>=k+1) {
							dp[i] = Math.max(1+dp[i-k-1],dp[i-1]);
						}
						else {
							dp[i] = dp[i-1];
						}
					}
					else {
						if((i-lastOne)>=k+1) {
							dp[i] = Math.max(dp[i-1],1);
						}
						else {
							dp[i] = dp[i-1];
						}
					}
				}
			}
			System.out.println(dp[n-1]);
		}
	}
}