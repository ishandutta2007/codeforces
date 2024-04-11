import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt(), k = in.nextInt();
            long[] a = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextLong();
            }
            long[] sum = new long[n + 1];
            for (int i = 1; i <= n; i++) {
                sum[i] = sum[i - 1] + a[i - 1];
            }

            long ans = 0;
            for (int bit = 60; bit >= 0; bit--) {

                long mask = ans | (1L << bit);
                boolean[][] dp = new boolean[n + 1][k + 1];
                dp[0][0] = true;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < k; j++) {
                        if (!dp[i][j]) {
                            continue;
                        }
                        for (int t = i + 1; t <= n; t++) {
                            long s = sum[t] - sum[i];
                            if ((s & mask) == mask) {
                                dp[t][j + 1] = true;
                            }
                        }
                    }
                }
                if (dp[n][k]) {
                    ans |= (1L << bit);
                }
            }
            out.println(ans);
        }

    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}