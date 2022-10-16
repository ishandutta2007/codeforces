import java.io.*;
import java.util.*;

public class B {

    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt(), m = in.nextInt(), q = in.nextInt();

        int[][] a = new int[n][m];
        for (int i = 0; i < n; i++) {
            String s = in.nextToken();
            for (int j = 0; j < m; j++) {
                a[i][j] = s.charAt(j) - '0';
            }
        }

        int[][] s = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                s[i][j] = a[i][j];
                if (i > 0) {
                    s[i][j] += s[i - 1][j];
                }
                if (j > 0) {
                    s[i][j] += s[i][j - 1];
                }
                if (i > 0 && j > 0) {
                    s[i][j] -= s[i - 1][j - 1];
                }
            }
        }

        int[][][][] ans = new int[n][m][n][m];
        for (int lenR = 1; lenR <= n; lenR++) {
            for (int lenC = 1; lenC <= m; lenC++) {
                for (int i1 = 0; i1 < n; i1++) {
                    for (int j1 = 0; j1 < m; j1++) {
                        int i2 = i1 + lenR - 1;
                        int j2 = j1 + lenC - 1;
                        if (i2 >= n || j2 >= m) {
                            continue;
                        }

                        ans[i1][j1][i2][j2] = getSum(s, i1, j1, i2, j2) == 0 ? 1
                                : 0;

                        int[] d = new int[4];
                        for (int mask = 1; mask < 1 << 4; mask++) {
                            d[0] = i1;
                            d[1] = j1;
                            d[2] = i2;
                            d[3] = j2;
                            for (int j = 0; j < 4; j++) {
                                if ((mask & (1 << j)) != 0) {
                                    if (j < 2) {
                                        d[j]++;
                                    } else {
                                        d[j]--;
                                    }
                                }
                            }
                            if (d[0] > d[2] || d[1] > d[3]) {
                                continue;
                            }

                            int res = ans[d[0]][d[1]][d[2]][d[3]];
                            if ((Integer.bitCount(mask) & 1) == 1) {
                                ans[i1][j1][i2][j2] += res;
                            } else {
                                ans[i1][j1][i2][j2] -= res;
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i < q; i++) {
            int r1 = in.nextInt() - 1, c1 = in.nextInt() - 1;
            int r2 = in.nextInt() - 1, c2 = in.nextInt() - 1;
            out.println(ans[r1][c1][r2][c2]);
        }
    }

    int getSum(int[][] s, int r1, int c1, int r2, int c2) {
        int res = s[r2][c2];
        if (r1 > 0) {
            res -= s[r1 - 1][c2];
        }
        if (c1 > 0) {
            res -= s[r2][c1 - 1];
        }
        if (r1 > 0 && c1 > 0) {
            res += s[r1 - 1][c1 - 1];
        }
        return res;
    }

    void run() {
        try {
            in = new FastScanner();
            out = new PrintWriter(System.out);
            solve();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextToken());
        }

        public long nextLong() {
            return Long.parseLong(nextToken());
        }

        public double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }

    public static void main(String[] args) {
        new B().run();
    }
}