import java.io.*;
import java.util.Arrays;

public class CF626F {

    final static long mod = 1000000007;

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int k = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
        }
        Arrays.sort(a);
        long[][] d = new long[n + 1][k + 1];
        d[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            long[][] d1 = new long[n + 1][k + 1];
            int delta = i == 0 ? 0 : a[i] - a[i - 1];
            for (int c = 0; c <= n; ++c) {
                for (int s = 0; s + c * delta <= k; ++s) {
                    if (c > 0) {
                        d1[c - 1][s + c * delta] = (d1[c - 1][s + c * delta] + c * d[c][s]) % mod;
                    }
                    d1[c][s + c * delta] = (d1[c][s + c * delta] + (c + 1) * d[c][s]) % mod;
                    if (c < n) {
                        d1[c + 1][s + c * delta] = (d1[c + 1][s + c * delta] + d[c][s]) % mod;
                    }
                }
            }
            d = d1;
//            System.err.println(Arrays.deepToString(d));
        }
        long ans = 0;
        for (int i = 0; i <= k; ++i) {
            ans = (ans + d[0][i]) % mod;
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