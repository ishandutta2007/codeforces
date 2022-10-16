import java.io.*;
import java.util.*;

public class A {

    FastScanner in;
    PrintWriter out;
    
    int MAX = 300;

    void solve() {
        int n = in.nextInt(), d = in.nextInt();
        int[] cnt = new int[30001];
        for (int i = 0; i < n; i++) {
            cnt[in.nextInt()]++;
        }

        int[][] dp = new int[30001][2 * MAX + 1];
        for (int[] dd : dp) {
            Arrays.fill(dd, -Integer.MAX_VALUE / 3);
        }
        dp[d][MAX] = cnt[d];

        int best = 0;
        for (int i = d; i <= 30000; i++) {
            for (int step = 1; step < 2 * MAX; step++) {
                best = Math.max(best, dp[i][step]);
                for (int delta = -1; delta <= 1; delta++) {
                    int newStep = step - MAX + d + delta;
                    if (newStep <= 0) {
                        continue;
                    }
                    int next = i + newStep;
                    if (next <= 30000) {
                        dp[next][step + delta] = Math.max(dp[next][step + delta], dp[i][step] + cnt[next]);
                    }
                }
            }
        }
        out.println(best);
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
        new A().run();
    }
}