import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
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
        FSbalansirovannieRaspolozheniyaDomino solver = new FSbalansirovannieRaspolozheniyaDomino();
        solver.solve(1, in, out);
        out.close();
    }

    static class FSbalansirovannieRaspolozheniyaDomino {
        int mod = 998244353;

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int h = in.nextInt(), w = in.nextInt(), n = in.nextInt();
            boolean[] r = new boolean[h], c = new boolean[w];
            for (int i = 0; i < 2 * n; i++) {
                r[in.nextInt() - 1] = true;
                c[in.nextInt() - 1] = true;
            }
            int freeR = 0, freeC = 0;
            for (int i = 0; i < h; i++) {
                if (!r[i]) {
                    freeR++;
                }
            }
            for (int i = 0; i < w; i++) {
                if (!c[i]) {
                    freeC++;
                }
            }
            Combinations combinations = new Combinations(7201, mod);
            int[] a = calc(r), b = calc(c);
            int[][] choose = MathUtils.choose(3600 + 1, 3600 + 1, mod);
            long ans = 0;
            for (int twos = 0; twos < a.length; twos++) {
                for (int ones = 0; ones < b.length; ones++) {
                    int free1 = freeR - twos * 2;
                    int free2 = freeC - ones * 2;
                    if (free1 < ones || free2 < twos) {
                        continue;
                    }

                    long add = (long) a[twos] * b[ones] % mod;
                    add = add * choose[free1][ones] % mod;
                    add = add * choose[free2][twos] % mod;
                    add = add * combinations.fact[twos] % mod;
                    add = add * combinations.fact[ones] % mod;
                    ans += add;
                }
            }
            out.println(ans % mod);
        }

        private int[] calc(boolean[] banned) {
            int twos = banned.length / 2;
            int[][] dp = new int[banned.length + 1][twos + 1];
            dp[0][0] = 1;
            for (int i = 0; i < banned.length; i++) {
                int[] cur = dp[i];
                if (i + 1 < banned.length && !banned[i] && !banned[i + 1]) {
                    int[] next = dp[i + 2];
                    for (int j = 0; j < twos; j++) {
                        next[j + 1] += cur[j];
                        if (next[j + 1] >= mod) {
                            next[j + 1] -= mod;
                        }
                    }
                }
                {
                    int[] next = dp[i + 1];
                    for (int j = 0; j <= twos; j++) {
                        next[j] += cur[j];
                        if (next[j] >= mod) {
                            next[j] -= mod;
                        }
                    }
                }
            }
            return dp[banned.length];
        }

    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

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
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

    }

    static class Combinations {
        public final int max;
        public final int mod;
        public int[] inv;
        public int[] fact;
        public int[] invFact;

        public Combinations(int max, int mod) {
            this.max = max;
            this.mod = mod;
            inv = MathUtils.inverses(max, mod);
            fact = new int[max];
            invFact = new int[max];
            fact[0] = invFact[0] = 1;
            for (int i = 1; i < max; i++) {
                fact[i] = (int) ((long) fact[i - 1] * i % mod);
                invFact[i] = (int) ((long) invFact[i - 1] * inv[i] % mod);
            }
        }

    }

    static class MathUtils {
        public static int[][] choose(int n, int m, int mod) {
            int[][] choose = new int[n][m];
            for (int i = 0; i < n; i++) {
                choose[i][0] = 1;
                for (int j = 1; j < m && j <= i; j++) {
                    choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
                    if (choose[i][j] >= mod) {
                        choose[i][j] -= mod;
                    }
                }
            }
            return choose;
        }

        public static int[] inverses(int size, int mod) {
            int[] inv = new int[size];
            inv[1] = 1;
            for (int i = 2; i < inv.length; i++) {
                inv[i] = (int) ((long) (mod - mod / i) * inv[mod % i] % mod);
            }
            return inv;
        }

    }
}