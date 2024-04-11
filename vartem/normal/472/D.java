import java.io.*;
import java.util.*;

public class D {

    FastScanner in;
    PrintWriter out;

    List<Edge>[] graph;

    class Edge {
        int from, to, cost;

        public Edge(int from, int to, int cost) {
            super();
            this.from = from;
            this.to = to;
            this.cost = cost;
        }

    }

    void solve() {
        int n = in.nextInt();
        int[][] a = new int[n][n];

        graph = new List[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = in.nextInt();
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] != a[j][i]) {
                    out.println("NO");
                    return;
                }
                if (a[i][j] == 0 && i != j) {
                    out.println("NO");
                    return;
                }
            }
        }

        final int INF = Integer.MAX_VALUE / 2;
        int[] min = new int[n];
        int[] vert = new int[n];
        Arrays.fill(min, INF);

        min[0] = 0;
        boolean[] used = new boolean[n];

        for (int IT = 0; IT < n; IT++) {
            int j = -1;
            for (int i = 0; i < n; i++) {
                if (!used[i] && (j == -1 || min[j] > min[i])) {
                    j = i;
                }
            }

            if (j != 0) {
                graph[j].add(new Edge(j, vert[j], min[j]));
                graph[vert[j]].add(new Edge(vert[j], j, min[j]));
            }

            used[j] = true;

            for (int i = 0; i < n; i++) {
                if (!used[i]) {
                    if (a[j][i] < min[i]) {
                        min[i] = a[j][i];
                        vert[i] = j;
                    }
                }
            }

        }

        queue = new int[n];
        dist = new long[n];
        for (int i = 0; i < n; i++) {
            long[] dist = bfs(i);

            for (int j = 0; j < n; j++) {
                if (dist[j] != a[i][j]) {
                    out.println("NO");
                    return;
                }
            }
        }
        out.println("YES");
    }

    class DSU {
        int[] p;

        public DSU(int n) {
            p = new int[n];
            for (int i = 0; i < n; i++) {
                p[i] = i;
            }
        }

        int get(int v) {
            if (v == p[v]) {
                return v;
            }
            return p[v] = get(p[v]);
        }

        boolean union(int a, int b) {
            a = get(a);
            b = get(b);
            if (a == b) {
                return false;
            }
            p[b] = a;
            return true;
        }
    }

    int[] queue;
    long[] dist;

    private long[] bfs(int s) {
        int head = 0, tail = 0;
        Arrays.fill(dist, -1);
        dist[s] = 0;
        queue[tail++] = s;
        while (head < tail) {
            int u = queue[head++];
            for (int t = 0; t < graph[u].size(); t++) {
                Edge v = graph[u].get(t);
                if (dist[v.to] == -1) {
                    dist[v.to] = dist[u] + v.cost;
                    queue[tail++] = v.to;
                }
            }
        }
        return dist;
    }

    void run() {
        in = new FastScanner();
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastScanner(String s) {
            try {
                br = new BufferedReader(new FileReader(s));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
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