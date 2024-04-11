import java.io.*;
import java.util.Arrays;

public class CF506A {

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int d = in.nextInt();
        int[] c = new int[30001];
        for (int i = 0; i < n; ++i) {
            c[in.nextInt()]++;
        }
        int[][] din = new int[30001][501];
        for (int[] ar : din) {
            Arrays.fill(ar, -1);
        }
        out.println(c[0] + d(d, d, d, din, c));
    }

    private static int d(int i, int len, int len0, int[][] din, int[] c) {
        if (i >= c.length || len == 0) {
            return 0;
        }
        if (din[i][len - len0 + 250] == -1) {
            int ret = c[i];
            for (int len1 = len - 1; len1 <= len + 1; ++len1) {
                ret = Math.max(ret, c[i] + d(i + len1, len1, len0, din, c));
            }
            din[i][len - len0 + 250] = ret;
        }
        return din[i][len - len0 + 250];
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