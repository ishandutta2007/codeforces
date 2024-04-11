import java.io.*;
import java.util.*;

public class C {

    FastScanner in;
    PrintWriter out;

    void solve() {
        int n=  in.nextInt(), m = in.nextInt(), k = in.nextInt();
        long[] sum = new long[n + 1];
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + in.nextLong();
        }
        
        long[][] dp = new long[n + 1][k + 1];
        
        for (int i = 1; i <= n; i++) {
            for (int t = 0; t <= k; t++) {
                dp[i][t] = dp[i - 1][t];
                if (t > 0 && i - m >= 0) {
                    dp[i][t] = Math.max(dp[i][t], dp[i - m][t - 1] + sum[i] - sum[i - m]);
                }
            }
        }
        
        out.println(dp[n][k]);
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
        new C().run();
    }
}