import java.util.Scanner;

public class almostidentitypermutations {
	public static void main(String[] args) {
		Scanner sc =new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		long [][] dp = new long[k+1][n+1];
		for(int i=0;i<k+1;i++) {
			dp[i][i] = factorial(i);
		}
	
		
		for(int j=2;j<n+1;j++) {
			dp[1][j] = 1;
		}
		for(int j=3;j<n+1;j++) {
			for(int i=2;i<k+1;i++) {
				if(i==j) {
					break;
				}
				dp[i][j] = dp[i-1][j]+choose(j,i)*derangement(i);
			}
		}
		System.out.println(dp[k][n]);
	}
	
	static long choose(int a,int b) {
		long prod = 1;
		for(int x=a;x>a-b;x--) {
			prod*=x;
		}
		return prod/factorial(b);
	}
	static long derangement(int i) {
		if(i==1) {
			return 0;
		}
		else if(i==2) {
			return 1;
		}
		else if(i==3) {
			return 2;
		}
		else {
			return 9;
		}
	}
	 static long factorial(int n) 
	    { 
	        long res = 1, i; 
	        for (i=2; i<=n; i++) 
	            res *= i; 
	        return res; 
	    } 
}