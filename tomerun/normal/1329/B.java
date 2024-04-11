import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 0; i < T; i++) {
			System.out.println(solve());
		}
	}

	static long solve() {
		long D = sc.nextInt();
		long M = sc.nextInt();
		int len = Long.toString(D, 2).length();
		long[] pow2 = new long[len];
		pow2[0] = 1;
		for (int i = 1; i < len; i++) {
			pow2[i] = pow2[i - 1] * 2 % M;
		}
		pow2[len - 1] = D - (1 << (len - 1)) + 1;
		long[][] dp = new long[len][len];
		long ans = 0;
		for (int i = 0; i < len; i++) {
			dp[0][i] = pow2[i];
			ans += dp[0][i];
		}
		ans %= M;
		for (int i = 1; i < len; i++) {
			for (int j = i; j < len; j++) {
				for (int k = i - 1; k < j; k++) {
					dp[i][j] += dp[i -1][k] * pow2[j];
					dp[i][j] %= M;
				}
				ans += dp[i][j];
			}
		}
		return ans % M;
	}

}