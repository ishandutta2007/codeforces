import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;

public class CF513F {

    static class P {
        int x, y;
        long t;

        public P(int x, int y, long t) {
            this.x = x;
            this.y = y;
            this.t = t;
        }
    }

    static final long INF = 1000000000000000000L;

    static final int[] dx = {-1, 1, 0, 0};
    static final int[] dy = {0, 0, -1, 1};

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int m = in.nextInt();
        int n1 = in.nextInt();
        int n2 = in.nextInt();
        char[][] f = new char[n][];
        for (int i = 0; i < n; ++i) {
            f[i] = in.next().toCharArray();
        }
        int[][] df = new int[n * m][n * m];
        for (int x0 = 0; x0 < n; ++x0) {
            for (int y0 = 0; y0 < m; ++y0) {
                int[] dd = df[x0 * m + y0];
                Arrays.fill(dd, -1);
                if (f[x0][y0] == '#') {
                    continue;
                }
                int[] q = new int[n * m];
                int qe = 0;
                dd[x0 * m + y0] = 0;
                q[qe++] = x0 * m + y0;
                for (int qs = 0; qs < qe; ++qs) {
                    int x = q[qs] / m;
                    int y = q[qs] % m;
                    for (int dir = 0; dir < 4; ++dir) {
                        int xx = x + dx[dir];
                        int yy = y + dy[dir];
                        if (0 <= xx && xx < n && 0 <= yy && yy < m && f[xx][yy] != '#' && dd[xx * m + yy] == -1) {
                            dd[xx * m + yy] = dd[x * m + y] + 1;
                            q[qe++] = xx * m + yy;
                        }
                    }
                }
            }
        }
        ArrayList<P> n1s = new ArrayList<>();
        ArrayList<P> n2s = new ArrayList<>();
        (n1 < n2 ? n1s : n2s).add(new P(in.nextInt() - 1, in.nextInt() - 1, in.nextInt()));
        for (int i = 0; i < n1; ++i) {
            n1s.add(new P(in.nextInt() - 1, in.nextInt() - 1, in.nextInt()));
        }
        for (int i = 0; i < n2; ++i) {
            n2s.add(new P(in.nextInt() - 1, in.nextInt() - 1, in.nextInt()));
        }
        n1 = n1s.size();
        n2 = n2s.size();
        if (n1 != n2) {
            out.println("-1");
            return;
        }
        long l = -2, r = INF;
        boolean[][] g = new boolean[n1 + n2 + 2 * n * m + 2][n1 + n2 + 2 * n * m + 2];
        loop: while (l + 1 < r) {
            for (boolean[] ar : g) {
                Arrays.fill(ar, false);
            }
            long mid = (l + r) / 2;
            int s = n1 + n2 + 2 * n * m;
            int t = n1 + n2 + 2 * n * m + 1;
            for (int i = 0; i < n1; ++i) {
                g[s][i] = true;
                P p = n1s.get(i);
                for (int j = 0; j < n * m; ++j) {
                    if (df[p.x * m + p.y][j] != -1 && df[p.x * m + p.y][j] * p.t <= mid) {
                        g[i][n1 + j] = true;
                    }
                }
            }
            for (int j = 0; j < n * m; ++j) {
                g[n1 + j][n1 + n * m + j] = true;
            }
            for (int i = 0; i < n2; ++i) {
                g[n1 + 2 * n * m + i][t] = true;
                P p = n2s.get(i);
                for (int j = 0; j < n * m; ++j) {
                    if (df[p.x * m + p.y][j] != -1 && df[p.x * m + p.y][j] * p.t <= mid) {
                        g[n1 + n * m + j][n1 + 2 * n * m + i] = true;
                    }
                }
            }
            boolean[] col = new boolean[g.length];
            for (int it = 0; it < n1; ++it) {
                if (!dfs(it, t, g, col)) {
                    l = mid;
                    continue loop;
                }
                Arrays.fill(col, false);
            }
            r = mid;
        }
        out.println(r == INF ? -1 : r);
    }

    private static boolean dfs(int s, int t, boolean[][] g, boolean[] col) {
        if (s == t) {
            return true;
        }
        if (col[s]) {
            return false;
        }
        col[s] = true;
        for (int i = g.length - 1; i >= 0; --i) {
            if (g[s][i] && dfs(i, t, g, col)) {
                g[s][i] = false;
                g[i][s] = true;
                return true;
            }
        }
        return false;
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