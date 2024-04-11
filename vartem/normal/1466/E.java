import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        EApollonProtivPana solver = new EApollonProtivPana();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class EApollonProtivPana {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int mod = 1000000007;
            long mod2 = (long) mod * mod;
            long[] count = new long[60];
            int n = in.nextInt();
            long[] a = in.nextLongArray(n);
            for (long s : a) {
                for (int j = 0; j < 60; j++) {
                    if ((s & (1L << j)) != 0) {
                        count[j]++;
                    }
                }
            }
            long ans = 0;
            long[] pow2 = new long[200];
            pow2[0] = 1;
            for (int i = 1; i < 200; i++) {
                pow2[i] = pow2[i - 1] * 2 % mod;
            }

            for (int i = 0; i < n; i++) {
                long sumAnd = 0, sumOr = 0;
                for (int bit = 0; bit < 60; bit++) {
                    if ((a[i] & (1L << bit)) != 0) {
                        sumAnd += pow2[bit] * count[bit];
                        if (sumAnd >= mod2) {
                            sumAnd -= mod2;
                        }
                        sumOr += pow2[bit] * n;
                        if (sumOr >= mod2) {
                            sumOr -= mod2;
                        }
                    } else {
                        sumOr += pow2[bit] * count[bit];
                        if (sumOr >= mod2) {
                            sumOr -= mod2;
                        }
                    }
                }
                sumAnd %= mod;
                sumOr %= mod;
                ans = (ans + sumAnd * sumOr) % mod;
            }
            out.println(ans);
        }

    }

    static class FastScanner {
        public BufferedReader br;
        public StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        public FastScanner(String fileName) {
            try {
                br = new BufferedReader(new FileReader(fileName));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                    throw new UnknownError();
                }
                if (line == null) {
                    throw new UnknownError();
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public long[] nextLongArray(int n) {
            long[] ret = new long[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextLong();
            }
            return ret;
        }

    }
}