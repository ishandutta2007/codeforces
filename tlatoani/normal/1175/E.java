import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class MinimalSegmentCover2 {

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(tokenizer.nextToken());
        int m = Integer.parseInt(tokenizer.nextToken());
        int[][] dp = new int[500001][20];
        for (int i = 0; i <= 500000; i++) {
            dp[i][0] = -1;
        }
        for (int i = 0; i < n; i++) {
            tokenizer = new StringTokenizer(in.readLine());
            int l = Integer.parseInt(tokenizer.nextToken());
            int r = Integer.parseInt(tokenizer.nextToken());
            dp[l][0] = Math.max(dp[l][0], r);
        }
        for (int i = 1; i <= 500000; i++) {
            if (dp[i - 1][0] >= i) {
                dp[i][0] = Math.max(dp[i][0], dp[i - 1][0]);
            }
        }
        for (int i = 500000; i >= 0; i--) {
            if (dp[i][0] != -1) {
                for (int k = 1; k < 20; k++) {
                    dp[i][k] = dp[dp[i][k - 1]][k - 1];
                }
            }
        }
        for (int i = 0; i < m; i++) {
            tokenizer = new StringTokenizer(in.readLine());
            int l = Integer.parseInt(tokenizer.nextToken());
            int r = Integer.parseInt(tokenizer.nextToken());
            if (dp[l][0] == -1 || dp[l][19] < r) {
                System.out.println(-1);
                continue;
            }
            int amt = 0;
            for (int k = 19; k >= 0; k--) {
                if (dp[l][k] < r) {
                    amt += 1 << k;
                    l = dp[l][k];
                }
            }
            amt++;
            System.out.println(amt);
        }
    }
}