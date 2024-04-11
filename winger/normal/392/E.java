import java.io.*;
import java.util.Arrays;

public class CF392E {

    final static int MINF = -1000000000;

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int[] ws = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            ws[i] = in.nextInt();
        }
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
        }
        int[][] d0 = new int[n][n];
        int[][] d1 = new int[n][n];
        for (int[] ar : d1) {
            Arrays.fill(ar, MINF);
        }
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i < n; ++i) {
                if (len == 1) {
                    d1[i][i] = 0;
                } else {
                    if (i - len + 1 >= 0) {
                        int j = i - len + 1;
                        d1[i][j] = MINF;
                        for (int k = j + 1; k <= i; ++k) {
                            if (a[j] + 1 == a[k] && d1[i][k] != MINF && d0[j + 1][k - 1] != MINF) {
                                d1[i][j] = Math.max(d1[i][j], d1[i][k] + d0[j + 1][k - 1]);
                            }
                        }
                    }
                    if (i + len - 1 < n) {
                        int j = i + len - 1;
                        d1[i][j] = MINF;
                        for (int k = i; k < j; ++k) {
                            if (a[j] + 1 == a[k] && d1[i][k] != MINF && d0[k + 1][j - 1] != MINF) {
                                d1[i][j] = Math.max(d1[i][j], d1[i][k] + d0[k + 1][j - 1]);
                            }
                        }
                    }
                }
            }
            for (int i = 0; i + len <= n; ++i) {
                int j = i + len - 1;
                d0[i][j] = MINF;
                for (int k = i; k < j; ++k) {
                    d0[i][j] = Math.max(d0[i][j], d0[i][k] + d0[k + 1][j]);
                }
                for (int k = i; k <= j; ++k) {
                    if (d1[k][i] != MINF && d1[k][j] != MINF) {
                        d0[i][j] = Math.max(d0[i][j], d1[k][i] + d1[k][j] + ws[2 * a[k] - a[i] - a[j] + 1]);
                    }
                }
            }
        }
        int[] d2 = new int[n + 1];
        d2[0] = 0;
        for (int i = 0; i < n; ++i) {
            d2[i + 1] = Math.max(d2[i + 1], d2[i]);
            for (int j = i; j < n; ++j) {
                d2[j + 1] = Math.max(d2[j + 1], d2[i] + d0[i][j]);
            }
        }
        out.println(d2[n]);
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