import java.io.*;
import java.util.*;

public class E {

    FastScanner in;
    PrintWriter out;

    List<Edge>[] graph;

    class Edge {
        int from, to, id;

        public Edge(int from, int to, int id) {
            super();
            this.from = from;
            this.to = to;
            this.id = id;
        }
    }

    int[] comp;
    int[] inTime, ret;

    int time = 0;

    int[] color;

    void dfs(int u, int parent) {
        inTime[u] = ret[u] = time++;
        color[u] = 1;
        
        for (Edge e : graph[u]) {
            if (e.id == parent) {
                continue;
            }
            if (color[e.to] == 0) {
                dfs(e.to, e.id);
                ret[u] = Math.min(ret[u], ret[e.to]);
            }
            if (color[e.to] == 1) {
                ret[u] = Math.min(ret[u], inTime[e.to]);
            }
            if (ret[e.to] > inTime[u]) {
                bridge[e.id] = true;
            }
        }
        
        color[u] = 2;
    }

    void dfsColor(int u, int col) {
        color[u] = col;
        for (Edge e : graph[u]) {
            if (bridge[e.id]) {
                continue;
            }
            if (color[e.to] == -1) {
                dfsColor(e.to, col);
            }
        }
    }

    boolean[] bridge;

    void solve() {
        int n = in.nextInt(), m = in.nextInt();
        graph = new List[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        int[] from = new int[m], to = new int[m];

        for (int i = 0; i < m; i++) {
            from[i] = in.nextInt() - 1;
            to[i] = in.nextInt() - 1;
            graph[from[i]].add(new Edge(from[i], to[i], i));
            graph[to[i]].add(new Edge(to[i], from[i], i));
        }

        comp = new int[n];
        inTime = new int[n];
        ret = new int[n];
        bridge = new boolean[m];
        color = new int[n];
        dfs(0, -1);

        color = new int[n];
        int cls = 0;
        Arrays.fill(color, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                dfsColor(i, cls++);
            }
        }

        int k = cls;
        newGraph = new List[k];
        for (int i = 0; i < k; i++) {
            newGraph[i] = new ArrayList<>();
        }

        size = new int[k];
        for (int i = 0; i < n; i++) {
            size[color[i]]++;
        }
        
        subtree = new int[k];
        long result = 0;

        for (int i = 0; i < k; i++) {
            result += 1L * size[i] * size[i];
        }

        for (int i = 0; i < m; i++) {
            if (bridge[i]) {
                int c1 = color[from[i]], c2 = color[to[i]];
                newGraph[c1].add(c2);
                newGraph[c2].add(c1);
            }
        }

        dfsSize(0, -1);

        int centroid = 0;
        int par = -1;

        while (true) {
            int mx = -1, vert = -1;
            for (int i : newGraph[centroid]) {
                if (i == par) {
                    continue;
                }

                if (subtree[i] > mx) {
                    mx = subtree[i];
                    vert = i;
                }
            }

            if (mx > n / 2) {
                par = centroid;
                centroid = vert;
            } else {
                break;
            }
        }

        subtree = new int[k];
        dfsSize(centroid, -1);

        for (int v : newGraph[centroid]) {
            dfsCount(v, centroid, 0);
        }
        result += sameSubTree;


        result += 1L * size[centroid] * (n - size[centroid]);
        int sum = n - size[centroid];
        boolean[] can = new boolean[sum + 1];
        
        can[0] = true;
        for (int i : newGraph[centroid]) {
            int w = subtree[i];
            for (int t = sum; t >= w; t--) {
                can[t] |= can[t - w];
            }
        }
        
        long mx = 0;
        for (int i = 0; i <= sum; i++) {
            if (can[i]) {
                mx = Math.max(mx, 1L * i * (sum - i));
            }
        }
        result += mx;
        out.println(result);
    }

    private void dfsCount(int u, int par, int sum) {
        sameSubTree += 1L * sum * size[u];
        for (int v : newGraph[u]) {
            if (v != par) {
                dfsCount(v, u, sum + size[u]);
            }
        }
    }

    long sameSubTree = 0;

    private void dfsSize(int u, int p) {
        subtree[u] = size[u];
        for (int v : newGraph[u]) {
            if (v != p) {
                dfsSize(v, u);
                subtree[u] += subtree[v];
            }
        }
    }

    List<Integer>[] newGraph;
    int[] size;
    int[] subtree;

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
        new E().run();
    }
}