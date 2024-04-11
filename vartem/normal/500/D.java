import java.io.*;
import java.util.*;

public class D {

    FastScanner in;
    PrintWriter out;

    class Edge {
        int from, to;
        long coef;
        int weight;

        public Edge(int from, int to, int weight) {
            super();
            this.from = from;
            this.to = to;
            this.weight = weight;
        }

    }

    int[] down;
    List<Edge>[] graph;

    void dfs(int u, int p) {
        down[u] = 1;
        for (int t = 0; t < graph[u].size(); t++) {
            Edge e = graph[u].get(t);
            int to = e.from;
            if (to == u) {
                to = e.to;
            }
            if (to == p) {
                continue;
            }
            dfs(to, u);

            down[u] += down[to];
            e.coef = 1L * down[to] * (graph.length - down[to]);
        }
    }

    void solve() {
        int n = in.nextInt();
        graph = new List[n];
        down = new int[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<Edge>();
        }

        Edge[] edges = new Edge[n - 1];
        for (int i = 0; i < n - 1; i++) {
            edges[i] = new Edge(in.nextInt() - 1, in.nextInt() - 1,
                    in.nextInt());
            graph[edges[i].from].add(edges[i]);
            graph[edges[i].to].add(edges[i]);
        }

        dfs(0, -1);
        
        long sum = 0;
        for (int i = 0; i < n - 1; i++) {
            sum += edges[i].weight * edges[i].coef;
        }
        
        int q = in.nextInt();
        for (int i = 0; i < q; i++) {
            int r = in.nextInt() - 1, w = in.nextInt();
            sum += (w - edges[r].weight) * edges[r].coef;
            edges[r].weight = w;
            
            out.println(3.0 * sum / (1.0 * n * (n - 1) / 2));
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
        new D().run();
    }
}