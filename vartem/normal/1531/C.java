import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.FileReader;
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
        CSimmetrichniiAmfiteatr solver = new CSimmetrichniiAmfiteatr();
        solver.solve(1, in, out);
        out.close();
    }

    static class CSimmetrichniiAmfiteatr {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();
            boolean[][] dp = new boolean[n + 1][n + 1];
            dp[0][0] = true;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dp[i][j]) {
                        dp[i][j + 1] = true;
                        if (i + (2 * j + 1) <= n) {
                            dp[i + (2 * j + 1)][j + 1] = true;
                        }
                    }
                }
            }
            int k = 0;
            while (k <= n && !dp[n][k]) {
                k++;
            }
            if (k > n) {
                out.println(-1);
                return;
            }
            out.println(k);
            char[][] result = new char[k][k];
            for (char[] i : result) {
                Arrays.fill(i, '.');
            }
            int layer = 0;
            while (n > 0) {
                if (k > 0 && dp[n][k - 1]) {
                    k--;
                } else {
                    for (int i = 0; i < k; i++) {
                        result[layer][layer + i] = result[layer + i][layer] = 'o';
                    }
                    layer++;
                    n -= 2 * k - 1;
                    k--;
                }
            }

            for (int i = result.length - 1; i >= 0; i--) {
                out.println(new String(result[i]));
            }
        }

    }

    static class FastScanner {
        public BufferedReader br;
        public StringTokenizer st;

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
                    throw new UnknownError();
                }
                if (line == null) {
                    throw new UnknownError();
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

    }
}