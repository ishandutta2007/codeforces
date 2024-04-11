import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class C {
    Scanner sc = new Scanner(System.in);
    
    void run() {
        int n = sc.nextInt();
        double[] ps = new double[n + 1];
        for (int i = 0; i <= n; i++) ps[i] = sc.nextDouble();
        int N = n * 2 + 5;
        double[][] g = new double[N][N];
        for (int s = 0; s < N; s++) {
            fill(g[s], INF);
            for (int t = 0; t < N; t++) if ((t + n - s) % 2 == 0) {
                int x = (t + n - s) / 2;
                if (0 <= x && x <= n) {
                    g[s][t] = -ps[x];
                }
            }
        }
        double res = mmc(g);
        System.out.printf("%.10f%n", -res + 1e-10);
    }
    
    double INF = Double.POSITIVE_INFINITY;
    
    double mmc(double[][] g) {
        int n = g.length;
        double[][] dp = new double[n + 1][n];
        for (int i = 0; i < n; i++) {
            fill(dp[i + 1], INF);
            for (int s = 0; s < n; s++) {
                for (int t = 0; t < n; t++) {
                    dp[i + 1][t] = min(dp[i + 1][t], dp[i][s] + g[s][t]);
                }
            }
        }
        double res = INF;
        for (int i = 0; i < n; i++) if (dp[n][i] < INF) {
            double max = -INF;
            for (int j = 0; j < n; j++) {
                max = max(max, (dp[n][i] - dp[j][i]) / (n - j));
            }
            res = min(res, max);
        }
        return res;
    }
    
    void debug(Object...os) {
        System.err.println(deepToString(os));
    }
    
    public static void main(String[] args) {
        new C().run();
    }
}