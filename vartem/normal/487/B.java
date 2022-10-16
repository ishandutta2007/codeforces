import java.io.*;
import java.util.*;

public class B {

    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt(), s = in.nextInt(), l = in.nextInt();
        int LOG = 20;

        int[][] min = new int[LOG][n + 1], max = new int[LOG][n + 1];
        int[][] dp = new int[LOG][n + 1];

        int INF = Integer.MAX_VALUE / 2;
        for (int i = 0; i < LOG; i++) {
            Arrays.fill(dp[i], INF);
            Arrays.fill(min[i], INF);
            Arrays.fill(max[i], INF);

            dp[i][0] = 0;
            min[i][0] = -INF;
            max[i][0] = INF;
        }

        for (int i = 1; i <= n; i++) {
            int curA = in.nextInt();

            min[0][i] = max[0][i] = curA;

            for (int j = 1; j < LOG; j++) {
                int prev = Math.max(i - (1 << (j - 1)), 0);
                min[j][i] = Math.min(min[j - 1][i], min[j - 1][prev]);
                max[j][i] = Math.max(max[j - 1][i], max[j - 1][prev]);
            }

            int cur = i;
            int curMax = curA, curMin = curA;
            for (int j = LOG - 1; j >= 0; j--) {
                if (Math.max(curMax, max[j][cur])
                        - Math.min(min[j][cur], curMin) <= s) {
                    curMax = Math.max(curMax, max[j][cur]);
                    curMin = Math.min(curMin, min[j][cur]);
                    cur -= 1 << j;
                }
            }

            cur--;
            int start = i - l;
            for (int j = LOG - 1; j >= 0; j--) {
                if (start - (1 << j) >= cur) {
                    dp[0][i] = Math.min(dp[0][i], dp[j][start] + 1);
                    start -= 1 << j;
                }
            }

            for (int j = 1; j < LOG; j++) {
                int prev = Math.max(i - (1 << (j - 1)), 0);
                dp[j][i] = Math.min(dp[j - 1][i], dp[j - 1][prev]);
            }
        }

        if (dp[0][n] == INF) {
            out.println(-1);
        } else {
            out.println(dp[0][n]);
        }
    }

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

        public FastScanner(String s) {
            try {
                br = new BufferedReader(new FileReader(s));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(nextToken());
        }

        long nextLong() {
            return Long.parseLong(nextToken());
        }

        double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }

    public static void main(String[] args) {
        new B().run();
    }
}