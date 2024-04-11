import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class D {
	Scanner sc = new Scanner(System.in);
	
	int INF = 1 << 29;
	
	void run() {
		int n = sc.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) a[i] = sc.nextInt();
		sort(a);
		int[][] dp = new int[n + 1][711];
		for (int i = 0; i <= n; i++) fill(dp[i], INF);
		dp[0][0] = 0;
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; j--) {
				for (int k = 0; k + a[i] <= 710; k++) {
					int cost = max(0, k + a[i] - 350);
					if (dp[j + 1][k + a[i]] > dp[j][k] + cost) {
						dp[j + 1][k + a[i]] = dp[j][k] + cost;
					}
				}
			}
		}
		for (int i = n; i >= 0; i--) {
			for (int j = 0; j <= 710; j++) if (dp[i][j] < INF) {
				System.out.println(i + " " + dp[i][j]);
				return;
			}
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		new D().run();
	}
}