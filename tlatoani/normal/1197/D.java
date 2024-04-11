import java.util.Scanner;

public class YetAnotherSubarrayProblem {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        long k = in.nextLong();
        long[] sums = new long[n + 1];
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + in.nextLong();
        }
        long[] dp = new long[n + 1];
        long answer = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < m && i >= j; j++) {
                dp[i] = Math.max(dp[i], sums[i] - sums[i - j] - k);
            }
            if (i >= m) {
                dp[i] = Math.max(dp[i], dp[i - m] + sums[i] - sums[i - m] - k);
            }
            answer = Math.max(answer, dp[i]);
        }
        System.out.println(answer);
    }
}