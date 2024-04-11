import java.io.*;
import java.util.Arrays;

public class CF321E {

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int k = in.nextInt();
        int[][] s = new int[n + 1][n + 1];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                s[i + 1][j + 1] = in.nextInt() + s[i][j + 1] + s[i + 1][j] - s[i][j];
            }
        }
        int[][] cost = new int[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                cost[i][j] = (s[j + 1][j + 1] + s[i][i] - s[i][j + 1] - s[j + 1][i]) / 2;
            }
        }
        int[] d = new int[n + 1];
        Arrays.fill(d, 1000000000);
        d[0] = 0;
        int[] d1 = new int[n + 1];
        for (int it = 0; it < k; ++it) {
            rec(d, d1, cost, it + 1, n + 1, it, n + 1);
            int[] tmp = d;
            d = d1;
            d1 = tmp;
        }
        out.println(d[n]);
    }

    private static void rec(int[] d, int[] d1, int[][] cost, int l, int r, int pl, int pr) {
        if (l == r) {
            return;
        }
        int mid = (l + r) / 2;
        d1[mid] = 1000000000;
        int opt = -1;
        for (int i = pl; i < pr && i < mid; ++i) {
            if (d1[mid] > d[i] + cost[i][mid - 1]) {
                d1[mid] = d[i] + cost[i][mid - 1];
                opt = i;
            }
        }
        if (opt == -1) {
            throw new AssertionError();
        }
        rec(d, d1, cost, l, mid, pl, opt + 1);
        rec(d, d1, cost, mid + 1, r, opt, pr);
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