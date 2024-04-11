import java.util.Arrays;
import java.util.Scanner;

public class balancedteams {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int [] vals = new int[n];
		for(int i=0;i<n;i++) {
			vals[i] = sc.nextInt();
		}
		Arrays.sort(vals);
		int [] balanced = new int[n];
		int counter=0;
		for(int i=0;i<n;i++) {
			int temp = vals[i];
			counter=i;
			while(counter>=0 && temp-vals[counter]<=5) {
			counter--;	
			}
			counter++;
			balanced[i] = counter;
		}
	
		int [][] dp = new int[k+1][n+1];
	for(int j=1;j<k+1;j++) { //row
		for(int i=1;i<n+1;i++) { //col
			int a = i-balanced[i-1]+dp[j-1][balanced[i-1]];
			int b = dp[j][i-1];
			dp[j][i]=Math.max(a,b);
		}
		
	}
//	for(int j=0;j<k+1;j++) {
//		for(int i=0;i<n+1;i++) {
//			System.out.print(dp[j][i]);
//		}
//		System.out.println();
//	}
	System.out.println(dp[k][n]);
		
	}
}