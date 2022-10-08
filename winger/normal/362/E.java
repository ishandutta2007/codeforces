import java.io.*;
import java.util.Arrays;

public class CF362E {

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int k = in.nextInt();
        int[][] c = new int[n][n];
        boolean[][] e = new boolean[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                c[i][j] = in.nextInt();
                e[i][j] = c[i][j] > 0;
            }
        }
        int ans = 0;
        for (int cap = 1 << 20; cap > 0; cap >>= 1) {
            while (dfs(0, n - 1, c, new boolean[n], cap)) {
                ans += cap;
            }
        }
        while (k > 0) {
            int[] dist = new int[n];
            int[] p = new int[n];
            Arrays.fill(p, -1);
            boolean[] col = new boolean[n];
            Arrays.fill(dist, k + 1);
            dist[0] = 0;
            while (true) {
                int min = -1;
                for (int i = 0; i < n; ++i) {
                    if (!col[i] && (min == -1 || dist[i] < dist[min])) {
                        min = i;
                    }
                }
                if (min == -1 || dist[min] > k) {
                    break;
                }
                col[min] = true;
                for (int i = 0; i < n; ++i) {
                    if (c[min][i] > 0 || e[min][i]) {
                        int d = dist[min] + (c[min][i] > 0 ? 0 : 1);
                        if (dist[i] > d) {
                            dist[i] = d;
                            p[i] = min;
                        }
                    }
                }
            }
            if (dist[n - 1] == 0) {
                throw new AssertionError();
            }
            if (dist[n - 1] > k) {
                break;
            }
            k -= dist[n - 1];
            ans++;
            for (int i = n - 1; i != 0; i = p[i]) {
                if (c[p[i]][i] > 0) {
                    c[p[i]][i]--;
                }
                c[i][p[i]]++;
            }
        }
        out.println(ans);
    }

    private static boolean dfs(int i, int j, int[][] c, boolean[] col, int cap) {
        if (col[i]) {
            return false;
        }
        if (i == j) {
            return true;
        }
        col[i] = true;
        for (int mid = c.length - 1; mid >= 0; --mid) {
            if (c[i][mid] >= cap && dfs(mid, j, c, col, cap)) {
                c[i][mid] -= cap;
                c[mid][i] += cap;
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