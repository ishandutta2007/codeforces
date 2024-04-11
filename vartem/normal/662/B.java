import java.io.*;
import java.util.*;

public class B {

    class Edge {
        int from, to, cost;

        public Edge(int from, int to, int cost) {
            this.from = from;
            this.to = to;
            this.cost = cost;
        }
    }

    List<Edge>[] graph;
    int[] vis;
    boolean fail = false;
    List<Integer> verts = new ArrayList<>();

    void dfs(int u, int c) {
        vis[u] = c;
        verts.add(u);
        for (int t = 0; t < graph[u].size(); t++) {
            Edge e = graph[u].get(t);
            int newC = e.cost ^ c;
            if (vis[e.to] == -1) {
                dfs(e.to, newC);
            } else {
                if (newC != vis[e.to]) {
                    fail = true;
                }
            }
        }
    }

    public void solve() {
        int n = in.nextInt(), m = in.nextInt();
        int[] from = new int[m], to = new int[m], col = new int[m];
        for (int i = 0; i < m; i++) {
            from[i] = in.nextInt() - 1;
            to[i] = in.nextInt() - 1;
            col[i] = in.nextToken().charAt(0) == 'B' ? 0 : 1;
        }
        List<Integer> bestAns = null;
        for (int rot = 0; rot < 2; rot++) {
            fail = false;
            graph = new List[n];
            for (int i = 0; i < n; i++) {
                graph[i] = new ArrayList<>();
            }
            for (int i = 0; i < m; i++) {
                graph[from[i]].add(new Edge(from[i], to[i], col[i] ^ rot));
                graph[to[i]].add(new Edge(to[i], from[i], col[i] ^ rot));
            }
            vis = new int[n];
            Arrays.fill(vis, -1);
            List<Integer> curAns = new ArrayList<>();

            for (int i = 0; i < n; i++) {
                if (vis[i] == -1) {
                    verts.clear();
                    dfs(i, 0);
                    int c0 = 0, c1 = 0;
                    for (int j : verts) {
                        if (vis[j] == 0) {
                            c0++;
                        } else {
                            c1++;
                        }
                    }
                    int need = 0;
                    if (c1 < c0) {
                        need = 1;
                    }
                    for (int j : verts) {
                        if (vis[j] == need) {
                            curAns.add(j);
                        }
                    }
                }
            }

            if (!fail && (bestAns == null || bestAns.size() > curAns.size())) {
                bestAns = curAns;
            }
        }

        if (bestAns == null) {
            out.println(-1);
        } else {
            out.println(bestAns.size());
            for (int i : bestAns) {
                out.print((i + 1) + " ");
            }
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
        new B().run();
    }
}