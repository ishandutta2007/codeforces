import java.io.*;
import java.util.*;

public class C2 {

    public void solve() {
        int n = in.nextInt(), m = in.nextInt(), k = in.nextInt(), w = in.nextInt();

        char[][][] fields = new char[k][n][m];
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                fields[i][j] = in.nextToken().toCharArray();
            }
        }

        DSU dsu = new DSU(k);
        int cost = 0;
        int comps = k;
        
        graph = new List[k];
        for (int i =0 ; i < k; i++) {
            graph[i] = new ArrayList<>();
        }
        
        List<Edge> edges = new ArrayList<>();
        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                int dist = dist(fields[i], fields[j]);
                if (dist * w < n * m) {
                    edges.add(new Edge(i, j, dist));
                }
            }
        }
        Collections.sort(edges);
        for (int i =0 ; i < edges.size(); i++) {
            Edge e = edges.get(i);
            if (dsu.union(e.from, e.to)) {
                cost += e.cost;
                graph[e.from].add(e.to);
                graph[e.to].add(e.from);
                comps--;
            }
        }
        
        out.println(cost * w + comps * n * m);
        used = new boolean[k];
        for (int i = 0; i < k; i++) {
            if (!used[i]) {
                out.println((i + 1) + " 0");
                go(i);
            }
        }
    }
    
    class Edge implements Comparable<Edge> {
        int from, to, cost;

        public Edge(int from, int to, int cost) {
            super();
            this.from = from;
            this.to = to;
            this.cost = cost;
        }
        
        @Override
        public int compareTo(Edge o) {
            return Integer.compare(cost, o.cost);
        }
    }
    
    void go(int u) {
        used[u] = true;
        for (int v : graph[u]) {
            if (!used[v]) {
                out.println((v + 1) + " " + (u + 1));
                go(v);
            }
        }
    }
        
    boolean[] used;
    List<Integer>[] graph;

    class DSU {
        int[] parent, rank;

        public DSU(int n) {
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int get(int u) {
            if (parent[u] == u) {
                return u;
            }
            return parent[u] = get(parent[u]);
        }

        boolean union(int a, int b) {
            a = get(a);
            b = get(b);
            if (a == b) {
                return false;
            }
            if (rank[a] == rank[b]) {
                rank[a]++;
            }
            if (rank[a] > rank[b]) {
                parent[b] = a;
            } else {
                parent[a] = b;
            }
            return true;
        }
    }

    private int dist(char[][] a, char[][] b) {
        int n = a.length, m = a[0].length;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            char[] c1 = a[i], c2 = b[i];
            for (int j = 0; j < m; j++) {
                ans += c1[j] != c2[j] ? 1 : 0;
            }
        }
        return ans;
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
        new C2().run();
    }
}