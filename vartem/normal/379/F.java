import java.io.*;
import java.util.*;

public class F {
    final int LOG = 21;
    int[][] table;
    int[] depth;

    int up(int v, int d) {
        for (int i = LOG - 1; i >= 0; i--) {
            if (d >= (1 << i)) {
                v = table[i][v];
                d -= 1 << i;
            }
        }
        return v;
    }

    int LCA(int a, int b) {
        a = up(a, Math.max(0, depth[a] - depth[b]));
        b = up(b, Math.max(0, depth[b] - depth[a]));

        if (a == b)
            return a;
        for (int i = LOG - 1; i >= 0; i--) {
            if (table[i][a] != table[i][b]) {
                a = table[i][a];
                b = table[i][b];
            }
        }
        return table[0][a];
    }

    int dist(int a, int b) {
        return depth[a] + depth[b] - 2 * depth[LCA(a, b)];
    }

    public void solve() {
        int q = in.nextInt();
        int n = 4 + 2 * q;

        int[] parent = new int[n];
        depth = new int[n];
        parent[0] = 0;
        parent[1] = parent[2] = parent[3] = 0;
        depth[1] = depth[2] = depth[3] = 1;
        int size = 4;
        for (int i = 0; i < q; i++) {
            int v = in.nextInt() - 1;
            parent[size] = parent[size + 1] = v;
            depth[size] = depth[size + 1] = depth[v] + 1;
            size += 2;
        }

        table = new int[LOG][n];
        table[0] = parent;
        for (int i = 1; i < LOG; i++) {
            for (int j = 0; j < n; j++) {
                table[i][j] = table[i - 1][table[i - 1][j]];
            }
        }

        int u = 1, v = 2, diam = 2;
        size = 4;
        for (int i = 0; i < q; i++) {
            int check = size++;
            {
                int dist1 = dist(u, check), dist2 = dist(v, check);
                if (dist1 >= dist2 && dist1 > diam) {
                    diam = dist1;
                    v = check;
                } else if (dist2 >= dist1 && dist2 > diam) {
                    diam = dist2;
                    u = check;
                }
            }
            check = size++;
            {
                int dist1 = dist(u, check), dist2 = dist(v, check);
                if (dist1 >= dist2 && dist1 > diam) {
                    diam = dist1;
                    v = check;
                } else if (dist2 >= dist1 && dist2 > diam) {
                    diam = dist2;
                    u = check;
                }
            }
            out.println(diam);
        }

    }

    FastScanner in;
    PrintWriter out;

    public void run() {
        try {
            in = new FastScanner();
            out = new PrintWriter(System.out);
            solve();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastScanner(String name) {
            try {
                br = new BufferedReader(new FileReader(name));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
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
        new F().run();
    }
}