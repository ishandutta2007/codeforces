import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author xuanquang1999
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt(), k = in.nextInt();
            int c[] = new int[n * k];
            int f[] = new int[n];
            int h[] = new int[k + 1];
            for (int i = 0; i < n * k; ++i)
                c[i] = in.nextInt();
            for (int i = 0; i < n; ++i)
                f[i] = in.nextInt();
            for (int i = 1; i <= k; ++i)
                h[i] = in.nextInt();

            int maxX = 100005;
            int cntCard[] = new int[maxX];
            int cntPlayer[] = new int[maxX];
            for (int i = 0; i < n * k; ++i)
                ++cntCard[c[i]];
            for (int i = 0; i < n; ++i)
                ++cntPlayer[f[i]];

            int ans = 0;
            for (int x = 0; x < maxX; ++x) {
                int dp[][] = new int[cntCard[x] + 1][cntPlayer[x] + 1];
                for (int i = 1; i <= cntCard[x]; ++i) {
                    for (int j = 1; j <= cntPlayer[x]; ++j) {
                        for (int p = 0; p <= Math.min(i, k); ++p) {
                            dp[i][j] = Math.max(dp[i][j], dp[i - p][j - 1] + h[p]);
                        }
                    }
                }
                ans += dp[cntCard[x]][cntPlayer[x]];
            }

            out.println(ans);
        }

    }
}