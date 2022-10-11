import java.util.Scanner;

final public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int a[] = new int[n];
		for(int i = 0; i < n; i++){
			a[i] = sc.nextInt();
		}
		long sum[] = new long[n + 1];
		sum[0] = 0;
		for(int i = 1; i <= n; i++)
			sum[i] = sum[i - 1] + a[i - 1];
		double ans = 0.0;
		for(int i = k; i <= n; i++)
			ans += (double)(sum[i] - sum[i - k]);
		System.out.println(ans / (n - k + 1));
	}
}