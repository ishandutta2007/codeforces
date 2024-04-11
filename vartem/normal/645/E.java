import java.io.*;
import java.util.*;

public class E {

    final int MOD = 1_000_000_007;

    public void solve() {
        int n = in.nextInt(), k = in.nextInt();
        char[] c = in.nextToken().toCharArray();

        int[] dp = new int[c.length + n + 1];
        int[] last = new int[k];
        Arrays.fill(last, -1);
        dp[0] = 1;
        for (int i = 1; i <= c.length; i++) {
            int code = c[i - 1] - 'a';
            if (i == 0) {
                dp[i] = 2;
                last[code] = i;
                continue;
            }
            dp[i] = (2 * dp[i - 1]) % MOD;
            if (last[code] != -1) {
                dp[i] = (dp[i] + MOD - dp[last[code] - 1]) % MOD;
            }
            last[code] = i;
        }

        for (int i = c.length + 1; i < dp.length; i++) {
            int code = -1;
            for (int j = 0; j < k; j++) {
                if (code == -1 || last[code] > last[j]) {
                    code = j;
                }
            }

            dp[i] = (2 * dp[i - 1]) % MOD;
            if (last[code] != -1) {
                dp[i] = (dp[i] + MOD - dp[last[code] - 1]) % MOD;
            }
            last[code] = i;
        }
//        System.err.println(Arrays.toString(dp));
        out.println(dp[dp.length - 1]);
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
        new E().run();
    }
}