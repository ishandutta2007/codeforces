import java.util.Scanner;

public class multimarbles {
	public static void main(String[] args) {
		Scanner sc = new Scanner (System.in);
		int n = sc.nextInt();
		int [] dp=new int[n];
		dp[0] = 1;
		if(n==1) {
			System.out.println(1);
			return;
		}
		dp[1] = 2;
		for(int i=2;i<n;i++) {
			dp[i] = dp[i-1]+dp[i-2]+1;
			dp[i]%=(int) (Math.pow(10,9)+7);
		}
		System.out.println((dp[n-1]+dp[n-2])%(int) (Math.pow(10,9)+7));
	}
}