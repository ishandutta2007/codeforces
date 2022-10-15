import static java.lang.Math.*;
// import java.math.BigInteger;
import java.io.*;
import java.util.*;

// solution code is in solve()

public class ProblemC {
    final static long mod = 1_000_000_007l;
    final static int maxn = 1_000_007;
    final static long infty = 1_000_000_009l;

    // final static boolean DEBUG = true;
    final static boolean DEBUG = false;

    static class Solver {

        long[] pts;
        int[] A;
        long[][] dp;
        long[][][][] g;

        public void solve() {
            int n = in.gi();
            
            A = new int[n + 1];
            pts = new long[n + 1];
            dp = new long[n + 1][n + 1];
            g = new long[n + 1][2][n + 1][n + 1];

            String cur = in.next();
            for (int j = 1; j <= n; j++) {
                A[j] = (int)cur.charAt(j - 1) - (int)'0';
                pts[j] = in.gl();
            }

            for (int l = 0; l <= n; l++) {
                for (int r = 0; r <= n; r++) {
                    for (int t = 0; t <= n; t++) {
                        for (int b = 0; b < 2; b++) {
                            if (t > r - l + 1) {
                                g[l][b][r][t] = -infty;
                            } else {
                                g[l][b][r][t] = 0l;
                            }
                        }
                    }
                }
            }

            for (int sz = 1; sz <= n; sz++) {
                for (int l = 1; l + sz - 1 <= n; l++) {
                    int r = l + sz - 1;

                    dp[l][r] = 0l;

                    for (int t = l; t < r; t++) {
                        dp[l][r] = max(dp[l][r], dp[l][t] + dp[t + 1][r]);
                    }

                    debug(l, ", ", r, " =1 ", dp[l][r]);


                    for (int t = 1; t <= sz; t++) {
                        for (int b = 0; b < 2; b++) {
                            g[l][b][r][t] = -infty;
                            if (b == A[r]) {
                                g[l][b][r][t] = max(g[l][b][r][t], g[l][b][r - 1][t - 1]);
                            }

                            debug(" h: ", l, ", ", b, ", ", r, ", ", t, " = ", g[l][b][r][t]);

                            for (int q = r; q > l; q--) {
                                g[l][b][r][t] = max(g[l][b][r][t], g[l][b][q - 1][t] + dp[q][r]);
                            }

                            debug(" g: ", l, ", ", b, ", ", r, ", ", t, " = ", g[l][b][r][t]);
                        }

                        int b = A[r];
                        dp[l][r] = max(dp[l][r], pts[t] + g[l][b][r][t]);
                    }

                    if (sz == 1) {
                        dp[l][r] = pts[1];
                    }

                    g[l][0][r][0] = g[l][1][r][0] = dp[l][r];

                    debug(l, ", ", r, " = ", dp[l][r]);
                }
            }

            println(dp[1][n]);
        }   





        PrintWriter out;
        FastInput in;
        Random random_source;

        long modexp(long x, long ex) {
            long ans = 1l;
            for (; ex > 0; ex >>= 1l, x = (x * x) % mod) {
                if ((ex & (1l)) > 0) ans = (ans * x) % mod;
            }
            return ans;
        }

        long gcd(long x, long y) {
            while (y > 0) {
                long t = x % y;
                x = y; y = t;
            }
            return x;
        }

        // Random numbers

        void initRandom(Long x) {
            random_source = new Random(x);
        }

        void initRandom() {
            random_source = new Random(System.currentTimeMillis());
        }

        int rand(int bound) { // [0..bound)
            return random_source.nextInt(bound);
        }

        // Convenience functions

        void debug(Object... obj) {
            if (DEBUG) {
                out.print("# ");
                for (Object o : obj) {
                    out.print(o.toString());
                    out.print(" ");
                }
                out.println("");
                out.flush();
            }
        }

       
        String a2s(Object[] A) {
            return Arrays.toString(A);
        }

        String a2s(int[] A) {
            return Arrays.toString(A);
        }

        String a2s(long[] A) {
            return Arrays.toString(A);
        }


        void flush() {
            out.flush();
        }

        void print(Object... obj) {
            for (Object o : obj) {
                out.print(o.toString());
            }
        }

        void println(Object... obj) {
            for (Object o : obj) {
                out.print(o.toString());
            }
            out.println("");
        } 

        void verify(boolean check) {    // equivalent to assert
            if (!check) {
                throw new RuntimeException("Verification error");
            }
        }

        void reverse(long[] A, int l, int r) {
            int i = l, j = r - 1;
            while (i < j) {
                long t = A[i];
                A[i] = A[j];
                A[j] = t;
                i++; j--;
            }
        }

        void reverse(int[] A, int l, int r) {
            int i = l, j = r - 1;
            while (i < j) {
                int t = A[i];
                A[i] = A[j];
                A[j] = t;
                i++; j--;
            }
        }

        // Measure time 

        long initTime;

        public void startWatch() {
            if (DEBUG) {
                initTime = System.nanoTime();
            }
        }

        public void endWatch() {
            if (DEBUG) {
                long current = System.nanoTime();
                long diff = current - initTime;
                long memory = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
                println("(Time: ", (double)diff / 1e9, ", Memory: ", memory/1000, "K)");            
            }
        }

        // Solver class constructor

        Solver(PrintWriter out, FastInput in) {
            this.out = out; this.in = in;
        }
    }

    public static void main(String args[]) {
        FastInput in = new FastInput(System.in);
        PrintWriter out = new PrintWriter(System.out);
        Solver solver = new Solver(out, in);
        solver.startWatch();
        solver.solve();
        solver.endWatch();
        out.close();
    }
    
    static class FastInput {
        BufferedReader reader;
        StringTokenizer tok;

        public FastInput(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tok = null;
        }

        public String next() {
            while (tok == null || !tok.hasMoreTokens()) {
                try {
                    tok = new StringTokenizer(reader.readLine());
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
            return tok.nextToken();
        }

        public int gi() {
            return Integer.parseInt(next());
        }

        public long gl() {
            return Long.parseLong(next());
        }
    }

    static class Pair<A extends Comparable<A>, B extends Comparable<B>>
            implements Comparable<Pair<A, B>> {
        A F;
        B S;

        Pair(A x, B y) {
            F = x; S = y;
        }

        public boolean equals(Pair<A, B> oth) {
            return this.compareTo(oth) == 0;    
        }

        public int compareTo(Pair<A, B> Q) {
            if (this.F.compareTo(Q.F) == 0) {
                return this.S.compareTo(Q.S);
            } else {
                return this.F.compareTo(Q.F);
            }
        }

        public String toString() {
            return new StringBuilder("{")
                    .append(F.toString())
                    .append(", ")
                    .append(S.toString())
                    .append("}")
                    .toString();
        }
    }

    static class IntPair implements Comparable<IntPair>{
        Integer F;
        Integer S;

        IntPair(Integer x, Integer y) {
            F = x; S = y;
        }

        public boolean equals(IntPair oth) {
            return this.compareTo(oth) == 0;    
        }

        public int compareTo(IntPair Q) {
            if (this.F.compareTo(Q.F) == 0) {
                return this.S.compareTo(Q.S);
            } else {
                return this.F.compareTo(Q.F);
            }
        }

        public String toString() {
            return new StringBuilder("{")
                    .append(F.toString())
                    .append(", ")
                    .append(S.toString())
                    .append("}")
                    .toString();
        }
    }
}