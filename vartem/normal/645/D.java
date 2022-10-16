import java.io.*;
import java.util.*;

public class D {

    List<Integer>[] graph;
    List<Integer> order;
    boolean[] vis;

    void dfs(int u) {
        vis[u] = true;
        for (int t = 0; t < graph[u].size(); t++) {
            int v = graph[u].get(t);
            if (!vis[v]) {
                dfs(v);
            }
        }
        order.add(u);
    }

    public void solve() {
        int n = in.nextInt();
        graph = new List[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        int edges = in.nextInt();
        int[] from = new int[edges], to = new int[edges];
        for (int i = 0; i < edges; i++) {
            from[i] = in.nextInt() - 1;
            to[i] = in.nextInt() - 1;
        }
        boolean[] good = new boolean[n];
        int l = 0, r = edges + 1;
        int[] pos = new int[n];
        vis = new boolean[n];
        while (l + 1 < r) {
            int mid = (l + r) >>> 1;

            for (int i = 0; i < n; i++) {
                graph[i].clear();
            }
            order = new ArrayList<>();
            for (int i = 0; i < mid; i++) {
                graph[from[i]].add(to[i]);
            }
            Arrays.fill(vis, false);
            for (int i = 0; i < n; i++) {
                if (!vis[i]) {
                    dfs(i);
                }
            }
            Collections.reverse(order);
            for (int i = 0; i < n; i++) {
                pos[order.get(i)] = i;
            }
            Arrays.fill(good, false);
            for (int i = 0; i < mid; i++) {
                if (pos[from[i]] + 1 == pos[to[i]]) {
                    good[pos[from[i]]] = true;
                }
            }
            boolean ok = true;
            for (int i = 0; i < n - 1; i++) {
                if (!good[i]) {
                    ok = false;
                }
            }
            if (ok) {
                r = mid;
            } else {
                l = mid;
            }
        }
        if (r == edges + 1) {
            out.println(-1);
        } else {
            out.println(r);
        }

    }

    public void run() {
        in = new FastScanner();
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    FastScanner in;
    PrintWriter out;

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(String fileName) {
            try {
                br = new BufferedReader(new FileReader(fileName));
            } catch (FileNotFoundException e) {
            }
        }

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(nextToken());
        }

        long nextLong() {
            return Long.parseLong(nextToken());
        }

        double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }

    public static void main(String[] args) {
        new D().run();
    }
}