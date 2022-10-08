import java.io.*;
import java.util.Random;

public class CF506E {

    final static int MOD = 10007;

    static int[][] mul(int[][] a, int[][] b) {
        int[][] c = new int[a.length][a.length];
        for (int i = 0; i < a.length; ++i) {
            for (int j = i; j < a.length; ++j) {
                long sum = 0;
                for (int k = i; k <= j; ++k) {
                    sum += a[i][k] * b[k][j];
                }
                c[i][j] = (int) (sum % MOD);
            }
        }
        return c;
    }

    static int[][] pow(int[][] a, long pow) {
        int[][] r = new int[a.length][a.length];
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

    public static void solve(Input in, PrintWriter out) throws IOException {
        String s = in.next();
        int n = s.length();
        int k = n + in.nextInt();
        int ans = solveFast(s, k);
        out.println(ans);
    }

    private static int solveFast(String s, int k) {
        int n = s.length();
        int[][][] d = new int[n + 1][n + 1][n + 1];
        d[0][n][0] = 1;
        for (int len = n; len > 0; --len) {
            for (int i = 0; i + len <= n; ++i) {
                for (int u = 0; u <= n; ++u) {
                    if (d[i][i + len][u] != 0) {
                        if (s.charAt(i) == s.charAt(i + len - 1)) {
                            d[i + 1][i + len - 1][u + 1] = (d[i + 1][i + len - 1][u + 1] + d[i][i + len][u]) % MOD;
                        } else {
                            d[i + 1][i + len][u] = (d[i + 1][i + len][u] + d[i][i + len][u]) % MOD;
                            d[i][i + len - 1][u] = (d[i][i + len - 1][u] + d[i][i + len][u]) % MOD;
                        }
                    }
                }
            }
        }
        int[][] d1 = new int[n + 1][n + 1];
        int[][] d2 = new int[n + 1][n + 1];
        for (int i = 0; i < n; ++i) {
            for (int u = 0; 2 * u <= n; ++u) {
                d1[u][n - 2 * u] += d[i][i][u];
                if (2 * u <= n - 1) {
                    d2[u][n - 2 * u - 1] += d[i][i + 1][u];
                }
            }
        }
        int ans = 0;
        int[][] a0 = new int[501][501];
        for (int i = 0; i < 100; ++i) {
            a0[i][i] = 25;
            a0[i][i + 1] = 1;
            if (i + 1 == 100) {
                a0[i][300] = 1;
            }
        }
        for (int i = 100; i < 300; ++i) {
            a0[i][i] = 24;
            if (i + 1 != 300) {
                a0[i][i + 1] = 1;
            }
            a0[i][200 + i + 1] = 1;
        }
        for (int i = 300; i <= 500; ++i) {
            a0[i][i] = 26;
        }
        int[][] a0low = pow(a0, k / 2);
        int[][] a0high = k % 2 == 1 ? mul(a0low, a0) : a0low;
        for (int u = 0; u <= n; ++u) {
            for (int v = 0; v <= n; ++v) {
                if (d1[u][v] != 0) { // aa
                    d1[u][v] %= MOD;
                    int cur = a0low[100 - u][300 + v];
                    if (k % 2 == 1) {
                        cur = cur * 26 % MOD;
                    }
                    ans = (ans + d1[u][v] * cur) % MOD;
//                    System.err.println("d1: " + u + " " + v + " " + d1[u][v] + " " + cur);
                }
                if (d2[u][v] != 0) { // a
                    d2[u][v] %= MOD;
                    int cur = a0high[100 - u - 1][300 + v];
                    ans = (ans + d2[u][v] * cur) % MOD;
//                    System.err.println("d2: " + u + " " + v + " " + d2[u][v] + " " + cur);
                }
            }
        }
        return ans;
    }

    private static int solveSlow(String s, int k) {
        int n = s.length();
        int[][] d = new int[n + 1][n + 1];
        d[0][n] = 1;
        for (int it = 0; it < k / 2; ++it) {
            int[][] d1 = new int[n + 1][n + 1];
            for (int len = n; len > 0; --len) {
                for (int i = 0; i + len <= n; ++i) {
                    if (d[i][i + len] != 0) {
                        if (s.charAt(i) == s.charAt(i + len - 1)) {
                            d1[Math.min(i + 1, i + len - 1)][i + len - 1] = (d1[Math.min(i + 1, i + len - 1)][i + len - 1] + d[i][i + len]) % MOD;
                            d1[i][i + len] = (d1[i][i + len] + d[i][i + len] * 25) % MOD;
                        } else {
                            d1[i + 1][i + len] = (d1[i + 1][i + len] + d[i][i + len]) % MOD;
                            d1[i][i + len - 1] = (d1[i][i + len - 1] + d[i][i + len]) % MOD;
                            d1[i][i + len] = (d1[i][i + len] + d[i][i + len] * 24) % MOD;
                        }
                    }
                }
            }
            for (int i = 0; i <= n; ++i) {
                d1[i][i] = (d1[i][i] + d[i][i] * 26) % MOD;
            }
            d = d1;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (k % 2 == 0) {
                ans += d[i][i];
            } else {
                ans += d[i][i] * 26 + d[i][i + 1];
            }
        }
        return ans % MOD;
    }

    /*
0 78
0 76
6624 57
8739 55
0 123
0 93
0 99
1871 122
6968 75
8247 1
0 79
3404 10
0 19
0 85
4715 23
8609 1
1910 86
721 113
4055 12
659 82
0 115
0 53
944 57
9422 11


     */

    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);
        Random rnd = new Random(42);
//        while (rnd != null) {
//            int n = 50;
//            StringBuilder sb = new StringBuilder();
//            for (int i = 0; i < n; ++i) {
//                sb.append((char)('a' + rnd.nextInt(26)));
//            }
//            int k = rnd.nextInt(100) + n;
//            int ans1 = solveSlow(sb.toString(), k);
//            int ans2 = solveFast(sb.toString(), k);
//            if (ans1 != ans2) {
//                System.err.println(sb + " " + k);
//                System.err.println(ans1 + " " + ans2);
//                throw new AssertionError();
//            }
////            sb.append("\n");
////            sb.append(rnd.nextInt(100));
////            solve(new Input(sb.toString()), out);
////            return;
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