import java.io.*;
import java.util.HashSet;

public class CF498C {

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = new int[n];
        HashSet<Integer> divs = new HashSet<>();
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
            int x = a[i];
            for (int d = 2; d * d <= x; ++d) {
                while (x % d == 0) {
                    divs.add(d);
                    x /= d;
                }
            }
            if (x > 1) {
                divs.add(x);
            }
        }
        int[][] g0 = new int[n + 2][n + 2];
        int s = n;
        int t = n + 1;
        for (int i = 0; i < m; ++i) {
            int u = in.nextInt() - 1;
            int v = in.nextInt() - 1;
            if (u % 2 == 1) {
                int tmp = u;
                u = v;
                v = tmp;
            }
            g0[u][v] = 100;
        }
        int ans = 0;
        for (int d : divs) {
            int[][] g = new int[n + 2][];
            for (int i = 0; i < n + 2; ++i) {
                g[i] = g0[i].clone();
            }
            for (int i = 0; i < n; ++i) {
                int x = a[i];
                int v = 0;
                while (x % d == 0) {
                    x /= d;
                    v++;
                }
                if (i % 2 == 0) {
                    g[s][i] = v;
                } else {
                    g[i][t] = v;
                }
            }
            while (dfs(s, t, g, new boolean[n + 2])) {
                ans++;
            }
        }
        out.println(ans);
    }

    private static boolean dfs(int s, int t, int[][] g, boolean[] col) {
        if (s == t) {
            return true;
        }
        if (col[s]) {
            return false;
        }
        col[s] = true;
        for (int i = g.length - 1; i >= 0; --i) {
            if (g[s][i] > 0 && dfs(i, t, g, col)) {
                g[s][i]--;
                g[i][s]++;
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