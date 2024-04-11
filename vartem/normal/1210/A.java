import java.io.*;
import java.util.*;

public class A {
    int n;
    int[] p;
    int ans = 0;

    void go(int pos) {
        if (pos == n) {
            check();
            return;
        }
        for (int i = 1; i <= 6; i++) {
            p[pos] = i;
            go(pos + 1);
        }
    }

    boolean[][] graph;
    boolean[][] dominos;

    private void check() {
        for (int i = 1;  i <= 6; i++) {
            for (int j = i; j <= 6; j++) {
                dominos[i][j] = true;
            }
        }
        int cur = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (!graph[i][j]) {
                    continue;
                }
                int val1 = Math.min(p[i], p[j]), val2 = Math.max(p[i], p[j]);
                if (dominos[val1][val2]) {
                    cur++;
                    dominos[val1][val2] = false;
                }
            }
        }
        ans = Math.max(ans, cur);
    }

    void solve() {
        n = in.nextInt();
        int m = in.nextInt();
        graph = new boolean[n][n];
        for (int i = 0; i < m; i++) {
            int from = in.nextInt() - 1, to = in.nextInt() - 1;
            graph[from][to] = graph[to][from] = true;
        }
        p = new int[n];
        dominos = new boolean[7][7];
        go(0);
        out.println(ans);
    }

    FastScanner in;
    PrintWriter out;

    void run() {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public boolean hasMoreTokens() {
            while (st == null || !st.hasMoreElements()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                    return false;
                }
                if (line == null) {
                    return false;
                }
                st = new StringTokenizer(line);
            }
            return true;
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

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public int[] nextIntArray(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }

        public long[] nextLongArray(int n) {
            long[] ret = new long[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextLong();
            }
            return ret;
        }
    }


    public static void main(String[] args) throws Exception {
        new A().run();
    }
}