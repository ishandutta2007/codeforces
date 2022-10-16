import java.io.*;
import java.util.*;

public class G2 {

    void solve() {
        int n = in.nextInt();
        int k = in.nextInt();
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = in.nextInt() - 1;
        }

        double[][] dp = new double[n][n];
        double[][] tmp = new double[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (p[i] > p[j]) {
                    dp[i][j] = 1;
                }
            }
        }
        int[][][] go = new int[n][n][n];
        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                for (int i = 0; i < n; i++) {
                    if (i < l || i > r) {
                        go[l][r][i] = i;
                    } else {
                        go[l][r][i] = l + r - i;
                    }
                }
            }
        }

        for (int IT = 0; IT < k; IT++) {
            double mul = 1.0 / (n * (n + 1) / 2);
            for (int l = 0; l < n; l++) {
                for (int r = l; r < n; r++) {
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                            tmp[i][j] += mul * dp[go[l][r][i]][go[l][r][j]];
                        }
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dp[i][j] = tmp[i][j];
                    tmp[i][j] = 0;
                }
            }
        }

        double ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans += dp[i][j];
            }
        }
        out.println(ans);
    }

    FastScanner in;
    PrintWriter out;

    void run() {
        in = new FastScanner();
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new G2().run();

    }
}