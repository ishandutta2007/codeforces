import java.io.*;
import java.util.Arrays;

public class cf438E {

    static class FFT {
        static int[][] tail;
        static int[][] omegas;
        final static int LOG = 20;

        final static int G = 3;

        static void doFFT(int[] a, boolean inverse) {
            int zz = a.length;
            while (zz > 0 && a[zz - 1] == 0) {
                --zz;
            }
            int size = a.length;
            int l = Integer.numberOfTrailingZeros(size);
            int[] tail = FFT.tail[l], omegas = FFT.omegas[l];
            for (int i = 0; i < size; i++) {
                if (i < tail[i]) {
                    int tmp = a[i];
                    a[i] = a[tail[i]];
                    a[tail[i]] = tmp;
                }
            }
            for (int len = 2; len <= size; len *= 2) {
                int add = size / len;
                for (int i = 0; i < size; i += len) {
                    int pos = 0;
                    for (int j = 0, k = len / 2; k < len; j++, k++) {
                        int u = a[i + j], v = (int) ((1l * a[i + k] * omegas[pos]) % mod);
                        a[i + j] = (u + v);
                        a[i + k] = (int) (u - v + mod);
                        if (a[i + j] >= mod) {
                            a[i + j] -= mod;
                        }
                        if (a[i + k] >= mod) {
                            a[i + k] -= mod;
                        }

                        if (inverse) {
                            pos -= add;
                            if (pos < 0) {
                                pos += size;
                            }
                        } else {
                            pos += add;
                        }
                    }
                }
            }
            if (inverse) {
                int inv = (int)modPow(size, mod - 2);
                for (int i = 0; i < size; i++) {
                    a[i] = (int) ((1l * inv * a[i]) % mod);
                }
            }
        }

        static void prepare() {
            tail = new int[LOG][];
            omegas = new int[LOG][];
            for (int l = 0; l < LOG; l++) {
                tail[l] = new int[1 << l];
                omegas[l] = new int[1 << l];
                int w = (int)modPow(G, (mod - 1) / (1 << l));

                omegas[l][0] = 1;
                for (int i = 1; i < 1 << l; i++) {
                    tail[l][i] = (tail[l][i >> 1] >> 1) | ((i & 1) << (l - 1));
                    omegas[l][i] = (int) ((1l * omegas[l][i - 1] * w) % mod);
                }
            }
        }
    }

    static {
        FFT.prepare();
    }

    final static long mod = 998244353;

    static long modPow(long x, long pow) {
        long r = 1;
        while (pow > 0) {
            if (pow % 2 == 1) {
                r = (r * x) % mod;
            }
            pow /= 2;
            x = (x * x) % mod;
        }
        return r;
    }

    static int[] inv(int[] p) {
        int[] g = new int[] {(int) modPow(p[0], mod - 2)};
        while (g.length < p.length) {
            int[] fg = Arrays.copyOf(g, g.length * 4);
            FFT.doFFT(fg, false);
            int[] ff = new int[g.length * 4];
            System.arraycopy(p, 0, ff, 0, Math.min(p.length, g.length * 2));
            FFT.doFFT(ff, false);
            for (int i = 0; i < fg.length; ++i) {
                fg[i] = (int) (1L * fg[i] * fg[i] % mod * ff[i] % mod);
            }
            FFT.doFFT(fg, true);
            int[] g1 = Arrays.copyOf(fg, g.length * 2);
            for (int i = 0; i < g.length; ++i) {
                g1[i] = (int) ((2 * g[i] + mod - g1[i]) % mod);
            }
            for (int i = g.length; i < g1.length; ++i) {
                g1[i] = (int) ((mod - g1[i]) % mod);
            }
            g = g1;
        }
        return g;
    }

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] c = new int[m + 1];
        for (int i = 0; i < n; ++i) {
            int x = in.nextInt();
            if (x <= m) {
                c[x]++;
            }
        }
        int[] f = new int[] {1};
        int[] d = new int[] {(int) (mod - 1)}; //(2*c*f - 1)-1/d=0
        while (f.length <= m) {
            int k = f.length;
            int[] ff = Arrays.copyOf(f, 8 * k);
            FFT.doFFT(ff, false);
            int[] cf = new int[8 * k];
            System.arraycopy(c, 0, cf, 0, Math.min(c.length, 2 * k));
            FFT.doFFT(cf, false);
            int[] df = Arrays.copyOf(d, 8 * k);
            FFT.doFFT(df, false);
            for (int i = 0; i < 8 * k; ++i) {
                long nom = (1L * ff[i] * ff[i] % mod * cf[i] + mod - ff[i] + 1) % mod;
                ff[i] = (int) ((ff[i] + mod - nom * df[i] % mod) % mod);
            }
            FFT.doFFT(ff, true);
            f = Arrays.copyOf(ff, 2 * k);

            for (int i = 2 * k; i < 8 * k; ++i) {
                ff[i] = 0;
            }
            FFT.doFFT(ff, false);
            for (int i = 0; i < 8 * k; ++i) {
                long di = (2L * ff[i] * cf[i] + mod - 1) % mod;
                df[i] = (int) ((2 * df[i] + mod - 1L * df[i] * df[i] % mod * di % mod) % mod);
            }
            FFT.doFFT(df, true);
            d = Arrays.copyOf(df, 2 * k);
        }
        for (int i = 1; i <= m; ++i) {
            out.println(f[i]);
        }
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