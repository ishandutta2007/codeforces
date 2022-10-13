import java.util.Arrays;
import java.util.Scanner;

public class officekeys {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int p = sc.nextInt();
		int [] employeePos = new int[n+1];
		for(int i=1;i<n+1;i++) {
			employeePos[i] = sc.nextInt();
		}
		int [] keyPos = new int[k+1];
		for(int i=1;i<k+1;i++) {
			keyPos[i] = sc.nextInt();
		}
		
		Arrays.sort(employeePos);
		Arrays.sort(keyPos);
		int [][] dp = new int[n+1][k+1];
		for(int i=0;i<n+1;i++) { //employee
			for(int j=0;j<k+1;j++) { //key
				if(i>j) {
					dp[i][j] = Integer.MAX_VALUE;
				}
			}
			
		}
		for(int i=1;i<n+1;i++) {
			for(int j=1;j<k+1;j++) {
				int t = Math.abs(employeePos[i]-keyPos[j])+Math.abs(keyPos[j]-p);
				dp[i][j] = Math.max(t,dp[i-1][j-1]);
						dp[i][j] = Math.min(dp[i][j],dp[i][j-1]);
			}
		}
//		for(int i=0;i<n+1;i++) {
//			for(int j=0;j<k+1;j++) {
//				if(dp[i][j] != (int) Math.pow(10,9)) {
//				System.out.print(dp[i][j] + " " );
//				}
//				else {
//					System.out.print(-1 + " " );
//				}
//			}
//			System.out.println();
//		}
		System.out.println(dp[n][k]);
		
	}
}