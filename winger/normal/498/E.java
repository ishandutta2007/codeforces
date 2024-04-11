import java.io.*;

public class CF498E {

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

    static long[][] mat(int n) {
        long[][] r = new long[1 << n][1 << n];
        for (int mask0 = 0; mask0 < 1 << n; ++mask0) {
            for (int mask1 = 0; mask1 < 1 << n; mask1 += 2) {
                for (int mask2 = 0; mask2 < 1 << n; ++mask2) {
                    int mask = mask0 | mask1 | (mask1 >> 1) | mask2;
                    if ((mask & ((1 << n) - 1)) == ((1 << n) - 1)) {
                        r[mask0][mask2]++;
                    }
                }
            }
        }
        return r;
    }

    public static void solve(Input in, PrintWriter out) throws IOException {
        long[] v = new long[1];
        v[0] = 1;
        for (int h = 1; h <= 7; ++h) {
            int w = in.nextInt();
            if (w != 0) {
                long[][] a = pow(mat(h), w);
                long[] v1 = new long[1 << h];
                for (int i = 0; i < v.length; ++i) {
                    for (int j = 0; j < v1.length; ++j) {
                        v1[j] = (v1[j] + v[i] * a[i][j]) % MOD;
                    }
                }
                v = v1;
            }
        }
        out.println(v[0]);
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