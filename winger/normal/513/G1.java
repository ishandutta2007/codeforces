import java.io.*;

public class CF513G {

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        long k = in.nextLong();
        int[] p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[in.nextInt() - 1] = i;
        }
        double[][] d = new double[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                d[p[i]][p[j]] = 1.0;
            }
        }
        double pp = 1.0 / (n * (n + 1) / 2.0);
        for (int it = 0; it < k; ++it) {
            double[][] nd = new double[n][n];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int u = 0; u < n; ++u) {
                        for (int v = u; v < n; ++v) {
                            int i1 = u <= i && i <= v ? (u + v - i) : i;
                            int j1 = u <= j && j <= v ? (u + v - j) : j;
                            nd[i1][j1] += d[i][j] * pp;
                        }
                    }
                }
            }
            d = nd;
        }
        double ans = 0.0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                ans += d[i][j];
            }
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