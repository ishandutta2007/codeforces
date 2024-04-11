import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.Random;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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
        E solver = new E();
        solver.solve(1, in, out);
        out.close();
    }

    static class E {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            long mod = 1_000_003;
//        long[][] testMatrix = {{-1,2,3}, {4,-2,8}, {2,1,8}};
//        long[][] aa = {{2,1,-1,8}, {-3,-1,2, -11}, {-2,1,2, -3}, {1,1,1,4}};
//        long[] ans2 = new long[3];
//        gaussMod(aa, ans2, mod);
//        System.out.println("Arrays.toString(ans) = " + Arrays.toString(ans2));
//        if(true)
//            return;
            out.println("? 0");
            out.flush();
            int a0 = in.ni();
            if (a0 == -1)
                return;
            if (a0 == 0) {
                out.println("! 0");
                out.flush();
                return;
            }
            int MAX = 30;
            long[][] matrix = new long[MAX][12];
            Random rand = new Random();
            for (int i = 0; i < MAX - 1; i++) {
                long x = rand.nextInt(100_000);
                out.println("? " + x);
                out.flush();
                long res = in.ni();
                if (res == -1)
                    return;
                res = (res + mod - a0) % mod;
                long cur = x;
                for (int j = 0; j < 11; j++) {
                    matrix[i][j] = cur % mod;
                    cur = cur * x % mod;
                }
                matrix[i][11] = res;
            }
            long[] ans = new long[11];
            long[] invs = IntegerUtils.invs((int) mod + 1, mod);
            MatrixUtils.gaussMod(matrix, ans, mod, invs);

//        long[] ans = {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//        System.out.println("ans = " + Arrays.toString(ans));
            for (int x = 1; x < mod; x++) {
                long cur = a0;
                long res = x;
                for (int i = 0; i < 11; i++) {
                    cur = (cur + ans[i] * res) % mod;
                    res = res * x % mod;
                }
                if (cur % mod == 0) {
                    out.println("! " + x);
                    out.flush();
                    return;
                }
            }
            out.println("! -1");
            out.flush();

        }

    }

    static class IntegerUtils {
        public static long[] invs(int n, long p) {
            long[] res = new long[n];
            res[1] = 1;
            for (int i = 2; i < n; i++) {
                res[i] = (p - (p / i) * res[(int) (p % i)] % p) % p;
            }
            return res;
        }

    }

    static class MatrixUtils {
        public static void gaussMod(long[][] a, long[] ans, long mod, long[] invs) {
            int n = a.length;
            int m = a[0].length - 1;
            int[] where = new int[m];
            Arrays.fill(where, -1);
            long tmp = 0;
            for (int col = 0, row = 0; col < m && row < n; ++col) {
                int sel = row;
                for (int i = row; i < n; ++i)
                    if (a[i][col] != 0) {
                        sel = i;
                        break;
                    }
                if (a[sel][col] == 0)
                    continue;
                for (int i = col; i <= m; ++i) {
                    tmp = a[sel][i];
                    a[sel][i] = a[row][i];
                    a[row][i] = tmp;
                }
                where[col] = row;

                for (int i = 0; i < n; ++i)
                    if (i != row) {
                        long c = a[i][col] * invs[(int) a[row][col]] % mod;
                        for (int j = col; j <= m; ++j)
                            a[i][j] = (a[i][j] + mod - a[row][j] * c % mod) % mod;
                    }
                ++row;
            }

            for (int i = 0; i < m; ++i)
                if (where[i] != -1)
                    ans[i] = a[where[i]][m] * invs[(int) a[where[i]][i]] % mod;
        }

    }

    static class FastScanner {
        private BufferedReader in;
        private StringTokenizer st;

        public FastScanner(InputStream stream) {
            in = new BufferedReader(new InputStreamReader(stream));
        }

        public String ns() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    String rl = in.readLine();
                    if (rl == null) {
                        return null;
                    }
                    st = new StringTokenizer(rl);
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return st.nextToken();
        }

        public int ni() {
            return Integer.parseInt(ns());
        }

    }
}