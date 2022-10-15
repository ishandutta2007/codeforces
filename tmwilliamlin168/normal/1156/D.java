import java.io.BufferedReader;
// import java.io.FileInputStream;
// import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

import static java.lang.Math.abs;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.util.Arrays.fill;
import static java.util.Arrays.sort;

public class Main {
    FastScanner in;
    PrintWriter out;

    class Pair {
        int v, c;

        Pair(int v, int c) {
            this.v = v;
            this.c = c;
        }
    }

    ArrayList<Pair>[] graph;
    long[][][] up, down;
    long ans;

    void dfs(int v, int p, int c) {
        if (p != -1) {
            if (c == 0) {
                up[0][0][v] += up[0][0][p] + down[0][0][p] + 1;
                up[1][0][v] += up[1][0][p] + down[1][0][p] + up[1][1][p] + down[1][1][p];
                ans += up[0][0][v] * 2 + up[1][0][v];
            } else if (c == 1) {
                up[1][1][v] += up[1][1][p] + down[1][1][p] + 1;
                up[0][1][v] += up[0][1][p] + down[0][1][p] + up[0][0][p] + down[0][0][p];
                ans += up[1][1][v] * 2 + up[0][1][v];
            } else
                c = 1 / 0;
        }

        for (Pair P : graph[v]) {
            if (P.v != p) {
                dfs(P.v, v, P.c);
                if (P.c == 0) {
                    down[0][0][v] += down[0][0][P.v] + 1;
                    down[1][0][v] += down[1][0][P.v] + down[1][1][P.v];
                } else if (P.c == 1) {
                    down[1][1][v] += down[1][1][P.v] + 1;
                    down[0][1][v] += down[0][1][P.v] + down[0][0][P.v];
                } else
                    c = 1 / 0;
            }
        }
    }

    private void solve() throws IOException {
        int n = in.nextInt();
        graph = new ArrayList[n];
        for (int i = 0; i < n; i++)
            graph[i] = new ArrayList<>();

        for (int i = 0; i < n - 1; i++) {
            int x = in.nextInt() - 1, y = in.nextInt() - 1, c = in.nextInt();
            graph[x].add(new Pair(y, c));
            graph[y].add(new Pair(x, c));
        }

        up = new long[2][2][n];
        down = new long[2][2][n];
        ans = 0;
        dfs(0, -1, -1);
        out.println(ans);
    }

    class FastScanner {
        StringTokenizer st;
        BufferedReader br;

        FastScanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
        }

        String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        boolean hasNext() throws IOException {
            return br.ready() || (st != null && st.hasMoreTokens());
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        String nextLine() throws IOException {
            return br.readLine();
        }

        boolean hasNextLine() throws IOException {
            return br.ready();
        }
    }

    private void run() throws IOException {
        in = new FastScanner(System.in); // new FastScanner(new FileInputStream("input.txt"));
        out = new PrintWriter(System.out); // new PrintWriter(new FileOutputStream("output.txt"));

        solve();

        out.flush();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }
}