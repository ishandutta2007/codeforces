import java.io.*;
import java.util.*;

public class A {

    public void solve() {
        int n = in.nextInt() + 1;
        int[] a = new int[n];
        for (int i = 0; i < n - 1; i++) {
            a[i] = in.nextInt();
        }

        int[][] dp = new int[n + 1][3];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                dp[i + 1][0] = Math.max(dp[i + 1][0], dp[i][j]);
                if ((a[i] & 1) != 0 && j != 1) {
                    dp[i + 1][1] = Math.max(dp[i + 1][1], dp[i][j] + 1);
                }
                if ((a[i] & 2) != 0 && j != 2) {
                    dp[i + 1][2] = Math.max(dp[i + 1][2], dp[i][j] + 1);
                }
            }
        }

        out.println(n - 1 - dp[n][0]);
    }

    public void run() {
        in = new FastScanner();
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    FastScanner in;
    PrintWriter out;

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(String fileName) {
            try {
                br = new BufferedReader(new FileReader(fileName));
            } catch (FileNotFoundException e) {
            }
        }

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
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
        new A().run();
    }
}