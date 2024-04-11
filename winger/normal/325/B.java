import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF325B {

    //x*(x-1)/2 + (pow2-1)*x
    //x^2+(pow2*2-3)x-2*n=0

    static BigInteger sqrt(BigInteger x) {
        BigInteger l = BigInteger.ZERO;
        BigInteger r = x.add(BigInteger.ONE);
        while (l.compareTo(r.subtract(BigInteger.ONE)) != 0) {
            BigInteger mid = l.add(r).shiftRight(1);
            if (mid.multiply(mid).compareTo(x) <= 0) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l.multiply(l).compareTo(x) == 0 ? l : null;
    }

    public static void solve(Input in, PrintWriter out) throws IOException {
        long n = in.nextLong();
        long pow2 = 1;
        TreeSet<BigInteger> ans = new TreeSet<BigInteger>();
        for (int i = 0; pow2 - 1 <= n; ++i, pow2 *= 2) {
            BigInteger b = bi(pow2 - 1).multiply(bi(2)).subtract(BigInteger.ONE);
            BigInteger c = bi(n).shiftLeft(1).negate();
            BigInteger d2 = b.multiply(b).subtract(bi(4).multiply(c));
            if (d2.signum() < 0) {
                continue;
            }
            BigInteger d = sqrt(d2);
            if (d == null) {
                continue;
            }
            BigInteger x1 = b.negate().subtract(d);
            BigInteger x2 = b.negate().add(d);
            if (x1.signum() > 0 && x1.mod(bi(2)).signum() == 0 && x1.mod(bi(4)).signum() != 0) {
                ans.add(x1.divide(bi(2)).multiply(bi(pow2)));
            }
            if (x2.signum() > 0 && x2.mod(bi(2)).signum() == 0 && x2.mod(bi(4)).signum() != 0) {
                ans.add(x2.divide(bi(2)).multiply(bi(pow2)));
            }
        }
        if (ans.isEmpty()) {
            out.println(-1);
        } else {
            for (BigInteger a : ans) {
                out.println(a);
            }
        }
    }

    private static BigInteger bi(long pow2) {
        return BigInteger.valueOf(pow2);
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