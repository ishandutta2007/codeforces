import java.io.*;

public class CF388D {

    final static long MOD = 1000000007;


    public static void solve(Input in, PrintWriter out) throws IOException {
        long k = in.nextLong();
        if (k == 0) {
            out.println(1);
            return;
        }
        int n = 0;
        while (1L << n <= k) {
            ++n;
        }
        long[] pow2 = new long[n * n + 1];
        pow2[0] = 1;
        for (int i = 1; i < pow2.length; ++i) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }
        long[][][] d = new long[2][n + 1][n + 1];
        d[1][0][0] = 1;
        for (int i = 0; i < n; ++i) {
            long bit = 1L << (n - i - 1);
            boolean set = (k & bit) != 0;
            for (int j = 0; j <= i; ++j) {
                long c0, c1;
                if (j == 0) {
                    c0 = 1;
                    c1 = 0;
                } else {
                    c0 = c1 = pow2[j - 1];
                }
                d[0][i + 1][j] = (d[0][i + 1][j] + d[0][i][j] * (c0 + c1)) % MOD;
                d[0][i + 1][j + 1] = (d[0][i + 1][j + 1] + d[0][i][j]) % MOD;
                if (set) {
                    d[0][i + 1][j] = (d[0][i + 1][j] + d[1][i][j] * c0) % MOD;
                    d[1][i + 1][j] = (d[1][i + 1][j] + d[1][i][j] * c1) % MOD;
                    d[1][i + 1][j + 1] = (d[1][i + 1][j + 1] + d[1][i][j]) % MOD;
                } else {
                    d[1][i + 1][j] = (d[1][i + 1][j] + d[1][i][j] * c0) % MOD;
                }
            }
        }
        long ans = 0;
        for (int i = 0; i <= n; ++i) {
            ans = (ans + d[0][n][i]) % MOD;
            ans = (ans + d[1][n][i]) % MOD;
        }
        out.println(ans);
    }

    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);
        solve(new Input(new BufferedReader(new InputStreamReader(System.in))), out);
        out.close();
    }

    static class Input {
        BufferedReader in;
        StringBuilder sb = new StringBuilder();

        public Input(BufferedReader in) {
            this.in = in;
        }

        public Input(String s) {
            this.in = new BufferedReader(new StringReader(s));
        }

        public String next() throws IOException {
            sb.setLength(0);
            while (true) {
                int c = in.read();
                if (c == -1) {
                    return null;
                }
                if (" \n\r\t".indexOf(c) == -1) {
                    sb.append((char)c);
                    break;
                }
            }
            while (true) {
                int c = in.read();
                if (c == -1 || " \n\r\t".indexOf(c) != -1) {
                    break;
                }
                sb.append((char)c);
            }
            return sb.toString();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }
}