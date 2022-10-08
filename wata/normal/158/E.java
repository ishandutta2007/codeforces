import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class E {
	Scanner sc = new Scanner(System.in);
	
	int T = 86400;
	
	void run() {
		int n = sc.nextInt(), k = sc.nextInt();
		if (n == k) {
			System.out.println(T);
			return;
		}
		int[] t = new int[n], d = new int[n];
		for (int i = 0; i < n; i++) {
			t[i] = sc.nextInt();
			d[i] = sc.nextInt();
		}
		int[] dp = new int[n + 1];
		fill(dp, Integer.MAX_VALUE);
		dp[0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = i; j >= 0; j--) {
				int p = (dp[j] > t[i] ? dp[j] : t[i]) + d[i];
				if (dp[j + 1] > p) {
					dp[j + 1] = p;
				}
			}
		}
		int res = t[k] - 1;
		for (int j = 0; j <= n; j++) {
			int p = (j + k < n) ? t[j + k] : (T + 1);
			if (res < p - dp[j]) {
				res = p - dp[j];
			}
		}
		System.out.println(res);
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		new E().run();
	}
}