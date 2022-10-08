import java.io.*;
import java.math.BigInteger;
import java.util.Arrays;

public class increasing_prefix_ors_3xNTT {

    final static long p = 1000000007;

    static class Value {
        int[] poly;
        long mul;

        public Value(int[] poly, long mul) {
            this.poly = poly;
            this.mul = mul;
        }

        Value mul(Value o) {
            return new Value(Arrays.copyOf(polyMul(substitute(poly, o.mul), o.poly), poly.length), mul * o.mul % p);
        }
    }

    static Value pow(Value x, Value one, long pow) {
        while (pow > 0) {
            if (pow % 2 == 1) {
                one = one.mul(x);
            }
            pow /= 2;
            x = x.mul(x);
        }
        return one;
    }

    public static void solve(Input in, PrintWriter out) throws IOException {
        // d'_j*(k-j)! += d_i*(k-i)! / (j-i)! * 2^i
        long n = in.nextLong();
        int k = in.nextInt();
        if (n > k + 1) {
            out.println(0);
            return;
        }
        int[] poly0 = new int[k + 1];
        int[] poly1 = new int[k + 1];
        for (int i = 1; i <= k; ++i) {
            poly0[i] = (int) (fact[k] * invFact[i] % p);
            poly1[i] = (int) invFact[i];
        }
        Value v = pow(new Value(poly1, 2), new Value(poly0, 1), n - 1);
        long ans = 0;
        for (int i = 0; i <= k; ++i) {
            ans = (ans + v.poly[i] * invFact[k - i]) % p;
        }
        out.println(ans);
    }

    static int max = 30000;
    static long[] fact, invFact, invs;
    static {
        fact = new long[max + 1];
        invFact = new long[max + 1];
        fact[0] = 1;
        invFact[0] = 1;
        invs = new long[max + 1];
        for (int i = 1; i <= max; ++i) {
            invs[i] = i == 1 ? 1 : (int) (p - invs[((int) (p % i))] * (p / i) % p);
            fact[i] = fact[i - 1] * i % p;
            invFact[i] = invFact[i - 1] * invs[i] % p;
        }
    }

    static long modInverse(long x, long mod) {
        return modPow(x, mod - 2, mod);
    }

    static long modPow(long x, long pow, long mod) {
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

    static int[] substitute(int[] a, long c) {
        int[] r = new int[a.length];
        long pow = 1;
        for (int i = 0; i < a.length; ++i) {
            r[i] = (int) (a[i] * pow % p);
            pow = pow * c % p;
        }
        return r;
    }

    static class FFT {
        int[][] tail;
        int[][] omegas;
        final int mod;
        final int LOG = 18;

        int G;

        FFT(int mod, int g) {
            this.mod = mod;
            G = g;
            tail = new int[LOG][];
            omegas = new int[LOG][];
            for (int l = 0; l < LOG; l++) {
                tail[l] = new int[1 << l];
                omegas[l] = new int[1 << l];
                int w = (int)modPow(G, (mod - 1) / (1 << l), mod);

                omegas[l][0] = 1;
                for (int i = 1; i < 1 << l; i++) {
                    tail[l][i] = (tail[l][i >> 1] >> 1) | ((i & 1) << (l - 1));
                    omegas[l][i] = (int) ((1l * omegas[l][i - 1] * w) % mod);
                }
            }
        }

        void doFFT(int[] a, int size, boolean inverse) {
            int l = Integer.numberOfTrailingZeros(size);
            int[] tail = this.tail[l], omegas = this.omegas[l];
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
                        a[i + k] = (u - v + mod);
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
                int inv = (int)modInverse(size, mod);
                for (int i = 0; i < size; i++) {
                    a[i] = (int) ((1L * inv * a[i]) % mod);
                }
            }
        }

        int[] conv(int[] a, int[] b) {
            int size = 1;
            while (size < a.length || size < b.length) {
                size *= 2;
            }
            size *= 2;
            a = Arrays.copyOf(a, size);
            b = Arrays.copyOf(b, size);
            doFFT(a, size, false);
            doFFT(b, size, false);
            for (int i = 0; i < size; ++i) {
                a[i] = (int) (1L * a[i] * b[i] % mod);
            }
            doFFT(a, size, true);
            return a;
        }
    }

    final static int mod1 = 998244353; // G = 3
    final static int mod2 = 1012924417; // G = 5
    final static int mod3 = 1045430273; // G = 3

    final static CRT e = new CRT(mod1, mod2, mod3);
    final static FFT fft1 = new FFT(mod1, 3);
    final static FFT fft2 = new FFT(mod2, 5);
    final static FFT fft3 = new FFT(mod3, 3);

    private static int[] polyMul(int[] a, int[] b) {
        int n = a.length;
        int[] a1 = fft1.conv(a, b);
        int[] a2 = fft2.conv(a, b);
        int[] a3 = fft3.conv(a, b);
        a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = (int) (e.crt(a1[i], a2[i], a3[i]).mod(BigInteger.valueOf(p)).longValue());
        }
        return a;
    }

    static class CRT {
        long[] mods;
        long[][] r;

        public CRT(long... mods) {
            this.mods = mods;
            r = new long[mods.length][mods.length];
            for (int i = 0; i < mods.length; ++i) {
                for (int j = i + 1; j < mods.length; ++j) {
                    r[i][j] = modInverse(mods[i], mods[j]);
                }
            }
        }

        BigInteger crt(long... rs) {
            BigInteger result = BigInteger.ZERO, mult = BigInteger.ONE;
            for (int i = 0; i < rs.length; ++i) {
                for (int j = 0; j < i; ++j) {
                    long cur = (rs[i] - rs[j]) * r[j][i];
                    rs[i] = (int)((cur % mods[i] + mods[i]) % mods[i]);
                }
                result = result.add(mult.multiply(BigInteger.valueOf(rs[i])));
                mult = mult.multiply(BigInteger.valueOf(mods[i]));
            }
            return result;
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