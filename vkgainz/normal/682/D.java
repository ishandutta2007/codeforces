import java.util.Scanner;

public class alyonaandstrings {
	public static void main(String [] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int k= sc.nextInt();
		String a = sc.next();
		String b = sc.next();
		int [][] stringDP = new int[n+1][m+1]; //first 
		for(int i=1;i<n+1;i++) {
			for(int j=1;j<m+1;j++) {
				if(a.charAt(i-1) == b.charAt(j-1)) {
					stringDP[i][j] = stringDP[i-1][j-1]+1;
				}
			}
		}
//		for(int i=1;i<n+1;i++) {
//			for(int j=1;j<m+1;j++) {
//				System.out.print(stringDP[i][j] + " ");
//			}
//			System.out.println();
//		}
		System.out.println();
		int [][][] dp = new int[n+1][m+1][k+1];
		for(int x=1;x<k+1;x++) {
			for(int y=1;y<m+1;y++) {
				for(int z=1;z<n+1;z++) {
					
					dp[z][y][x] = stringDP[z][y]+dp[z-stringDP[z][y]][y-stringDP[z][y]][x-1];
					dp[z][y][x] = Math.max(dp[z][y][x],dp[z-1][y][x]);
					dp[z][y][x] = Math.max(dp[z][y][x],dp[z][y-1][x]);
				}
			}
		}
//		for(int i=1;i<n+1;i++) {
//			for(int j=1;j<m+1;j++) {
//				System.out.print(dp[i][j][k] + " ");
//			}
//			System.out.println();
//		}
		System.out.println(dp[n][m][k]);
		

	}


}