import java.io.*;
import java.util.*;

public class B {

    FastScanner in;
    PrintWriter out;

    long MOD = (long) (1e9 + 7);

    void solve() {
        String s = in.nextToken(), t = in.nextToken();
        int[] p = pref(t);

        long[] dp = new long[s.length() + 1];
        long[] sum = new long[s.length() + 1];
        long[] sum2 = new long[s.length() + 1];
        dp[0] = sum[0] = sum2[0] = 1;

        int lastOcc = -1;
        int cur = 0;
        for (int pos = 0; pos < s.length(); pos++) {
            while (cur > 0 && s.charAt(pos) != t.charAt(cur)) {
                cur = p[cur - 1];
            }
            if (s.charAt(pos) == t.charAt(cur)) {
                cur++;
            }

            if (cur == t.length()) {
                lastOcc = pos - t.length() + 1;
                cur = p[cur - 1];
            }

            if (lastOcc >= 0) {
                dp[pos + 1] = sum2[lastOcc];
            }
            sum[pos + 1] = sum[pos] + dp[pos + 1];
            if (sum[pos + 1] >= MOD) {
                sum[pos + 1] -= MOD;
            }
            sum2[pos + 1] = sum2[pos] + sum[pos + 1];
            if (sum2[pos + 1] >= MOD) {
                sum2[pos + 1] -= MOD;
            }
        }

        out.println((sum[s.length()] + MOD - 1) % MOD);
    }

    int[] pref(String s) {
        int n = s.length();
        int[] p = new int[n];
        for (int i = 1; i < n; i++) {
            int k = p[i - 1];
            while (k > 0 && s.charAt(k) != s.charAt(i)) {
                k = p[k - 1];
            }
            if (s.charAt(k) == s.charAt(i)) {
                k++;
            }
            p[i] = k;
        }
        return p;
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