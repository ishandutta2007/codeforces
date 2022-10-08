import java.io.*;

public class CF321D {

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int m = (n + 1) / 2;
        int[][] a = new int[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                a[i][j] = in.nextInt();
            }
        }
        long ans = Long.MIN_VALUE;
        for (int mask = 0; mask < 1 << m; ++mask) {
            long cur = sgn(mask, m - 1) * a[m - 1][m - 1];
            for (int j = 0; j < m - 1; ++j) {
                cur += sgn(mask, j) * (a[m - 1][j] + sgn(mask, m - 1) * a[m - 1][j + m]);
            }
            for (int i = 0; i < m - 1; ++i) {
                long rowMax = Long.MIN_VALUE;
                for (int b = 0; b < 2; ++b) {
                    long rowCur = sgn(b, 0) * (a[i][m - 1] + sgn(mask, m - 1) * a[i + m][m - 1]);
                    for (int j = 0; j < m - 1; ++j) {
                        rowCur += Math.abs(a[i][j] + sgn(b, 0) * a[i][j + m] + sgn(mask, j) * a[i + m][j] + sgn(b, 0) * sgn(mask, j) * sgn(mask, m - 1) * a[i + m][j + m]);
                    }
                    rowMax = Math.max(rowMax, rowCur);
                }
                cur += rowMax;
            }
            ans = Math.max(ans, cur);
        }
        out.println(ans);
    }

    private static int sgn(int mask, int i) {
        return (mask & (1 << i)) != 0 ? -1 : 1;
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