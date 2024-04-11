import java.util.*;

public class susbus{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int [] prices = new int[n];
		for (int i=0;i<n;i++) {
			prices[i] = sc.nextInt();
		}
		Arrays.sort(prices);
		int sum = 0;
		for (int i=0;i<m;i++) {
			if (prices[i] <0) {
				sum+=prices[i];
			}
			else {
				break;
			}
		}
		System.out.println(-1*sum);
		
	}
	
}