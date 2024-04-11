import java.util.Scanner;

public class GasPipeline {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        for (int t = in.nextInt(); t > 0; t--) {
            int n = in.nextInt();
            long a = in.nextLong();
            long b = in.nextLong();
            long[][] dp = new long[2][2];
            dp[0][0] = b;
            dp[0][1] = 1L << 50;
            String road = in.next();
            for (int i = 1; i <= n; i++) {
                int k = i & 1;
                if (road.charAt(i - 1) == '1') {
                    dp[k][0] = 1L << 50;
                    dp[k][1] = dp[1 - k][1] + a + (b << 1);
                } else {
                    dp[k][0] = Math.min(dp[1 - k][0] + a + b, dp[1 - k][1] + (a << 1) + b);
                    dp[k][1] = Math.min(dp[1 - k][0] + (a << 1) + (b << 1), dp[1 - k][1] + a + (b << 1));
                }
            }
            System.out.println(dp[n & 1][0]);
        }
    }
}