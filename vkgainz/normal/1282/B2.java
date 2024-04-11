import java.util.Arrays;
import java.util.Scanner;

public class kforthepriceofone {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		StringBuilder sb = new StringBuilder();
		for(int i=0;i<t;i++) {
			int n = sc.nextInt(); int p = sc.nextInt(); int k = sc.nextInt();
			int [] vals= new int[n]; 
			for(int j=0;j<n;j++) {
				vals[j] = sc.nextInt(); 
			}
			Arrays.sort(vals);
			int [] dp = new int[n+1]; 
			for(int j=1;j<n+1;j++) {
				dp[j] = dp[j-1]+vals[j-1]; 
			if(j>=k) dp[j] = Math.min(dp[j],dp[j-k]+vals[j-1]);
			}
			int ret = n;
			while(ret>=0) {
				if(dp[ret]<=p) {
					sb.append(ret + " ");
					break;
				}
				ret--;
			}
		}
		System.out.println(sb.toString());
	}
}