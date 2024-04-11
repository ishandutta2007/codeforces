import java.io.*;
import java.util.*;

public class B {

    FastScanner in;
    PrintWriter out;

    List<Integer>[] graph, revGraph;
    List<Integer> order;
    int[] comp;

    void dfs(int u) {
        comp[u] = 0;
        for (int v : graph[u]) {
            if (comp[v] == -1) {
                dfs(v);
            }
        }
        order.add(u);
    }

    int dfsRev(int u, int c) {
        comp[u] = c;
        int ret = 1;
        for (int v : revGraph[u]) {
            if (comp[v] == -1) {
                ret += dfsRev(v, c);
            }
        }
        return ret;
    }

    void solve() {
        int n = in.nextInt(), m = in.nextInt();
        graph = new List[n];
        revGraph = new List[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
            revGraph[i] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            int from = in.nextInt() - 1, to = in.nextInt() - 1;
            graph[from].add(to);
            revGraph[to].add(from);
        }
        order = new ArrayList<>();

        comp = new int[n];
        Arrays.fill(comp, -1);
        for (int i = 0; i < n; i++) {
            if (comp[i] == -1) {
                dfs(i);
            }
        }

        Arrays.fill(comp, -1);
        int comps = 0;
        int[] sizes = new int[n];
        Collections.reverse(order);
        for (int i : order) {
            if (comp[i] == -1) {
                sizes[comps] = dfsRev(i, comps);
                comps++;
            }
        }

        int ans = 0;
        DSU dsu = new DSU(comps);
        for (int i = 0; i < n; i++) {
            for (int j : graph[i]) {
                dsu.unite(comp[i], comp[j]);
            }
        }
        for (int i = 0; i < comps; i++) {
            int root = dsu.get(i);
            dsu.size[root] += sizes[i];
            if (sizes[i] > 1 && !dsu.add[root]) {
                dsu.add[root] = true;
            }
        }
        
        for (int i = 0; i < comps; i++) {
            if (dsu.get(i) == i) {
                ans += dsu.size[i] - 1;
                if (dsu.add[i]) {
                    ans++;
                }
            }
        }
        out.println(ans);
    }

    class DSU {
        int[] p;
        boolean[] add;
        int[] size;

        public DSU(int n) {
            p = new int[n];
            size = new int[n];
            add = new boolean[n];
            for (int i = 0; i < n; i++) {
                p[i] = i;
            }
        }

        int get(int u) {
            if (p[u] == u) {
                return u;
            }
            return p[u] = get(p[u]);
        }

        boolean unite(int u, int v) {
            u = get(u);
            v = get(v);
            if (u != v) {
                p[v] = u;
            }
            return u != v;
        }
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
        new B().run();
    }
}