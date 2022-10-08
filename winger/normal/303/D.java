import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;

public class CF303D {

    static long modPow(long x, long pow, long mod) {
        long r = 1;
        while (pow > 0) {
            if (pow % 2 == 1) {
                r = r * x % mod;
            }
            pow /= 2;
            x = x * x % mod;
        }
        return r;
    }

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt() + 1;
        int x = in.nextInt() - 1;
        if (n == 2) {
            out.println(x == 1 ? -1 : x);
            return;
        }
        for (int d = 2; d * d <= n; ++d) {
            if (n % d == 0) {
                out.println(-1);
                return;
            }
        }
        ArrayList<Integer> pDivs = new ArrayList<Integer>();
        int m = n - 1;
        for (int d = 2; d * d <= m; ++d) {
            if (m % d == 0) {
                pDivs.add(d);
                while (m % d == 0) {
                    m /= d;
                }
            }
        }
        if (m > 1) {
            pDivs.add(m);
        }
        int b;
        if (n == 2) {
            b = 1;
        } else {
            loop: for (b = 2; ; ++b) {
                for (int p : pDivs) {
                    if (modPow(b, (n - 1) / p, n) == 1) {
                        continue loop;
                    }
                }
                break;
            }
        }
        boolean[] coprime = new boolean[n - 1];
        Arrays.fill(coprime, true);
        for (int p : pDivs) {
            for (int i = 0; i < n - 1; i += p) {
                coprime[i] = false;
            }
        }
        long ans = -1;
        long cur = 1;
        for (int i = 0; i < n - 1; ++i) {
            if (coprime[i]) {
                if (cur <= x) {
                    ans = Math.max(ans, cur + n * ((x - cur) / n));
                }
            }
            cur = cur * b % n;
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