import java.io.*;
import java.util.Arrays;

public class CF626E {

    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static class Fraction implements Comparable<Fraction> {
        final long a, b;

        Fraction(long a, long b) {
            long g = gcd(Math.abs(a), Math.abs(b));
            this.a = a / g;
            this.b = b / g;
        }

        Fraction add(Fraction o) {
            return new Fraction(a * o.b + o.a * b, b * o.b);
        }

        Fraction sub(Fraction o) {
            return new Fraction(a * o.b - o.a * b, b * o.b);
        }

        Fraction mul(Fraction o) {
            return new Fraction(a * o.a, b * o.b);
        }

        Fraction div(Fraction o) {
            return new Fraction(a * o.b, b * o.a);
        }

        @Override
        public int compareTo(Fraction o) {
            return Long.signum(a * o.b - b * o.a);
        }
    }

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
        }
        Arrays.sort(a);
        long[] pSum = new long[n + 1];
        for (int i = 0; i < n; ++i) {
            pSum[i + 1] = pSum[i] + a[i];
        }
        int besti = n - 1, bestLen = 0;
        Fraction best = new Fraction(0, 1);
        for (int i = n - 1; i >= 0; --i) {
            int l = -1, r = Math.min(n - i - 1, i);
            while (l + 1 < r) {
                int mid = (l + r) / 2;
                Fraction v1 = new Fraction((pSum[n] - pSum[n - mid]) + (pSum[i + 1] - pSum[i - mid]), 2 * mid + 1);
                Fraction v2 = new Fraction((pSum[n] - pSum[n - mid - 1]) + (pSum[i + 1] - pSum[i - mid - 1]), 2 * mid + 3);
                if (v1.compareTo(v2) < 0) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            Fraction v = new Fraction((pSum[n] - pSum[n - r]) + (pSum[i + 1] - pSum[i - r]), 2 * r + 1).sub(new Fraction(a[i], 1));
            if (v.compareTo(best) > 0) {
                besti = i;
                bestLen = r;
                best = v;
            }
        }
//        for (int i = n - 1; i >= 0; --i) {
//            for (int len = 0; len <= i && n - len > i; ++len) {
//                Fraction v = new Fraction((pSum[n] - pSum[n - len]) + (pSum[i + 1] - pSum[i - len]), 2 * len + 1).sub(new Fraction(a[i], 1));
//                if (v.compareTo(best) > 0) {
//                    throw new AssertionError();
//                }
//            }
//        }
        out.println(2 * bestLen + 1);
        for (int i = 0; i <= bestLen; ++i) {
            out.print(a[besti - bestLen + i] + " ");
        }
        for (int i = 0; i < bestLen; ++i) {
            out.print(a[n - bestLen + i] + " ");
        }
    }

    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);

//        Random rnd = new Random();
//        while (rnd != null) {
//            int n = 5;
//            StringBuilder sb = new StringBuilder(n + "\n");
//            for (int i = 0; i < n; ++i) {
//                sb.append(rnd.nextInt(10) + " ");
//            }
//            System.err.println(sb);
//            solve(new Input(sb.toString()), out);
//        }

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