import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class CF273D {

    final static int mod = 1000000007;

    static int[][] sum(int[][] a) {
        int n = a.length;
        int m = a[0].length;
        int[][] r = new int[n + 1][m + 1];
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                r[i][j] = (r[i - 1][j] + r[i][j - 1]) % mod;
                r[i][j] = (r[i][j] + a[i - 1][j - 1]) % mod;
                r[i][j] = (r[i][j] + mod - r[i - 1][j - 1]) % mod;
            }
        }
        return r;
    }

    private static int[][] clone(int[][] a) {
        int n = a.length;
        int m = a[0].length;
        int[][] r = new int[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                r[i][j] = a[i][j];
            }
        }
        return r;
    }

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int m = in.nextInt();
        int[][] d00 = new int[m][m];
        int[][] d01 = new int[m][m];
        int[][] d10 = new int[m][m];
        int[][] d11 = new int[m][m];
        int ans = 0;
        for (int it = 0; it <= n; ++it) {
            int[][] s00 = sum(d00);
            int[][] s01 = sum(d01);
            int[][] s10 = sum(d10);
            int[][] s11 = sum(d11);
//            int[][] s00 = clone(d00);
//            int[][] s01 = clone(d01);
//            int[][] s10 = clone(d10);
//            int[][] s11 = clone(d11);
            for (int u = 0; u < m; ++u) {
                for (int v = u; v < m; ++v) {
                    ans = (ans + d00[u][v]) % mod;
                    ans = (ans + d01[u][v]) % mod;
                    ans = (ans + d10[u][v]) % mod;
                    ans = (ans + d11[u][v]) % mod;
                }
            }
//            System.err.println(Arrays.deepToString(d00));
//            System.err.println(Arrays.deepToString(d01));
//            System.err.println(Arrays.deepToString(d10));
//            System.err.println(Arrays.deepToString(d11));
            for (int u = 0; u < m; ++u) {
                for (int v = u; v < m; ++v) {
                    d00[u][v] = d01[u][v] = d10[u][v] = d11[u][v] = 0;

                    d00[u][v] = (d00[u][v] + sum(s00, u, m - 1, u, v)) % mod;
//                    for (int u1 = u; u1 < m; ++u1) {
//                        for (int v1 = u1; v1 <= v; ++v1) {
//                            d00[u][v] = (d00[u][v] + s00[u1][v1]) % mod;
//                        }
//                    }

                    d01[u][v] = (d01[u][v] + sum(s00, u, v, v + 1, m - 1)) % mod;
//                    for (int u1 = u; u1 <= v; ++u1) {
//                        for (int v1 = v + 1; v1 < m; ++v1) {
//                            d01[u][v] = (d01[u][v] + s00[u1][v1]) % mod;
//                        }
//                    }
                    d01[u][v] = (d01[u][v] + sum(s01, u, v, v, m - 1)) % mod;
//                    for (int u1 = u; u1 <= v; ++u1) {
//                        for (int v1 = v; v1 < m; ++v1) {
//                            d01[u][v] = (d01[u][v] + s01[u1][v1]) % mod;
//                        }
//                    }

                    d10[u][v] = (d10[u][v] + sum(s00, 0, u - 1, u, v)) % mod;
//                    for (int u1 = 0; u1 < u; ++u1) {
//                        for (int v1 = u; v1 <= v; ++v1) {
//                            d10[u][v] = (d10[u][v] + s00[u1][v1]) % mod;
//                        }
//                    }
                    d10[u][v] = (d10[u][v] + sum(s10, 0, u, u, v)) % mod;
//                    for (int u1 = 0; u1 <= u; ++u1) {
//                        for (int v1 = u; v1 <= v; ++v1) {
//                            d10[u][v] = (d10[u][v] + s10[u1][v1]) % mod;
//                        }
//                    }

                    d11[u][v] = (d11[u][v] + sum(s00, 0, u - 1, v + 1, m - 1)) % mod;
//                    for (int u1 = 0; u1 < u; ++u1) {
//                        for (int v1 = v + 1; v1 < m; ++v1) {
//                            d11[u][v] = (d11[u][v] + s00[u1][v1]) % mod;
//                        }
//                    }
                    d11[u][v] = (d11[u][v] + sum(s01, 0, u - 1, v, m - 1)) % mod;
//                    for (int u1 = 0; u1 < u; ++u1) {
//                        for (int v1 = v; v1 < m; ++v1) {
//                            d11[u][v] = (d11[u][v] + s01[u1][v1]) % mod;
//                        }
//                    }
                    d11[u][v] = (d11[u][v] + sum(s10, 0, u, v + 1, m - 1)) % mod;
//                    for (int u1 = 0; u1 <= u; ++u1) {
//                        for (int v1 = v + 1; v1 < m; ++v1) {
//                            d11[u][v] = (d11[u][v] + s10[u1][v1]) % mod;
//                        }
//                    }
                    d11[u][v] = (d11[u][v] + sum(s11, 0, u, v, m - 1)) % mod;
//                    for (int u1 = 0; u1 <= u; ++u1) {
//                        for (int v1 = v; v1 < m; ++v1) {
//                            d11[u][v] = (d11[u][v] + s11[u1][v1]) % mod;
//                        }
//                    }
                    d00[u][v] = (d00[u][v] + 1) % mod;
                }
            }
        }
        out.println(ans);
    }

    private static int sum(int[][] s, int i1, int i2, int j1, int j2) {
        int r = s[i2 + 1][j2 + 1];
        r = (r + mod - s[i2 + 1][j1]) % mod;
        r = (r + mod - s[i1][j2 + 1]) % mod;
        r = (r + s[i1][j1]) % mod;
        return r;
    }

    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);
        solve(new Input(new BufferedReader(new InputStreamReader(System.in))), out);
        out.close();
    }

    static class Input {
        BufferedReader in;
        StringTokenizer st;

        public Input(BufferedReader in) {
            this.in = in;
            eat("");
        }

        public Input(String s) {
            this.in = new BufferedReader(new StringReader(s));
        }

        public void eat(String str) {
            st = new StringTokenizer(str);
        }

        public String next() throws IOException {
            while (!st.hasMoreTokens()) {
                String line = in.readLine();
                if (line == null) {
                    return null;
                }
                eat(line);
            }
            return st.nextToken();
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