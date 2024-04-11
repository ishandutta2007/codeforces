import java.util.Scanner;

public class PieRules {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int [] vals = new int[n];
		for(int i=0;i<n;i++) {
			vals[i] = sc.nextInt();
		}
		int [] prefix =new int[n];
		prefix[n-1] = vals[n-1];
		for(int i=n-2;i>=0;i--) {
			prefix[i] = prefix[i+1]+vals[i];
		}
		int [] dp = new int[n];
		dp[n-1] = prefix[n-1];
		for(int i=n-2;i>=0;i--) {
			dp[i] = Math.max(dp[i+1],vals[i]+prefix[i+1]-dp[i+1]);
		}
//		for(int i=0;i<n;i++) {
//			System.out.println(dp[i]);
//		}
		System.out.println(prefix[0]-dp[0] + " " + dp[0]);
	}
}