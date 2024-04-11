import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
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
        TaskE2 solver = new TaskE2();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE2 {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int t = in.nextInt();
            while (t-- > 0) {
                int n = in.nextInt(), m = in.nextInt();
                int[][] a = new int[m][n];
                int[] bestMask = new int[1 << n];
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        a[j][i] = in.nextInt();
                    }
                }
                int[] dp = new int[1 << n];
                for (int i = 0; i < m; i++) {
                    int[] array = a[i];
                    for (int j = 0; j < n; j++) {
                        int val = array[j];
                        for (int mask = 0; mask < 1 << n; mask++) {
                            if ((mask & (1 << j)) == 0) {
                                dp[mask | (1 << j)] = Math.max(dp[mask | (1 << j)], dp[mask] + val);
                            }
                        }
                    }
                    for (int mask = 0; mask < 1 << n; mask++) {
                        int best = 0;
                        int cur = mask;
                        for (int j = 0; j < n; j++) {
                            best = Math.max(best, dp[cur]);
                            cur = (cur >> 1) | ((cur & 1) << (n - 1));
                        }
                        for (int j = 0; j < n; j++) {
                            dp[cur] = best;
                            cur = (cur >> 1) | ((cur & 1) << (n - 1));
                        }
                    }
                }
                out.println(dp[(1 << n) - 1]);
            }
        }

    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        public FastScanner(String fileName) {
            try {
                br = new BufferedReader(new FileReader(fileName));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
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

    }
}