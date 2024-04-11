import java.io.*;
import java.util.Arrays;

public class CF392C {

    final static long MOD = 1000000007;

    static long[][] mul(long[][] a, long[][] b) {
        long[][] c = new long[a.length][a.length];
        for (int i = 0; i < a.length; ++i) {
            for (int j = 0; j < a.length; ++j) {
                for (int k = 0; k < a.length; ++k) {
                    c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
                }
            }
        }
        return c;
    }

    static long[][] pow(long[][] a, long pow) {
        long[][] r = new long[a.length][a.length];
        for (int i = 0; i < a.length; ++i) {
            r[i][i] = 1;
        }
        while (pow > 0) {
            if (pow % 2 == 1) {
                r = mul(r, a);
            }
            pow /= 2;
            a = mul(a, a);
        }
        return r;
    }

    public static void solve(Input in, PrintWriter out) throws IOException {
        long n = in.nextLong();
        int k = in.nextInt() + 1;
        long[][] cs = new long[k + 1][k + 1];
        for (int i = 0; i < cs.length; ++i) {
            for (int j = 1; j < i; ++j) {
                cs[i][j] = (cs[i - 1][j - 1] + cs[i - 1][j]) % MOD;
            }
            cs[i][0] = cs[i][i] = 1;
        }
        long[][] a = new long[2 * k + 1][2 * k + 1];
        long[][] b = new long[2 * k + 1][2 * k + 1];
        long[][] c = new long[2 * k + 1][2 * k + 1];
        a[2 * k][2 * k] = b[2 * k][2 * k] = c[2 * k][2 * k] = 1;
        a[2 * k][2 * k - 1] = 1;
        for (int i = 0; i < k; ++i) {
            a[k + i][k + i] = 1;
            b[i][k + i] = 1;
            b[k + i][i] = 1;
            b[k + i][k + i] = 1;
            c[i][i] = 1;
            for (int j = 0; j <= i; ++j) {
                a[i][j] = cs[i][j];
                c[k + i][k + j] = cs[i][j];
            }
        }
        long[][] m = mul(c, mul(b, a));
//        long[] r = new long[2 * k + 1];
//        for (int i = 0; i < k; ++i) {
//            r[k + i] = 1;
//        }
//        r[0] = 1;
//        for (int it = 0; it < n; ++it) {
//            System.err.println(Arrays.toString(r));
//            long[] r1 = new long[2 * k + 1];
//            for (int i = 0; i < 2 * k + 1; ++i) {
//                for (int j = 0; j < 2 * k + 1; ++j) {
//                    r1[i] = (r1[i] + m[i][j] * r[j]) % MOD;
//                }
//            }
//            r = r1;
//        }
//        System.err.println(Arrays.toString(r));
        m = pow(m, n);
        long ans = m[2 * k][0];
        for (int i = 0; i < k; ++i) {
            ans = (ans + m[2 * k][k + i]) % MOD;
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