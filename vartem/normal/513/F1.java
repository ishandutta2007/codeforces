import java.io.*;
import java.util.*;

public class F {

    class Edge {
        int from, to, flow, cap;
        Edge rev;

        public Edge(int from, int to, int cap) {
            super();
            this.from = from;
            this.to = to;
            this.cap = cap;
        }

        @Override
        public String toString() {
            return "Edge [from=" + from + ", to=" + to + ", flow=" + flow
                    + ", cap=" + cap + "]";
        }

    }

    class Graph {
        List<Edge>[] graph;
        int[] start;
        int[] dist;

        public Graph(int n) {
            graph = new List[n];
            for (int i = 0; i < n; i++) {
                graph[i] = new ArrayList<>();
            }
            start = new int[n];
            dist = new int[n];
            queue = new int[n];
        }

        void addEdge(int from, int to, int cap) {
            Edge st = new Edge(from, to, cap);
            Edge rev = new Edge(to, from, 0);
            st.rev = rev;
            rev.rev = st;
            graph[from].add(st);
            graph[to].add(rev);
        }

        int flow() {
            int flow = 0;
            while (bfs()) {
                Arrays.fill(start, 0);
                while (true) {
                    int t = dfs(0, Integer.MAX_VALUE);
                    if (t == 0) {
                        break;
                    } else {
                        flow += t;
                    }
                }
            }
            return flow;
        }

        int dfs(int u, int flow) {
            if (u == graph.length - 1) {
                return flow;
            }
            for (; start[u] < graph[u].size(); start[u]++) {
                Edge e = graph[u].get(start[u]);
                if (e.flow < e.cap && dist[e.to] == dist[u] + 1) {
                    int t = dfs(e.to, Math.min(flow, e.cap - e.flow));
                    if (t > 0) {
                        e.flow += t;
                        e.rev.flow -= t;
                        return t;
                    }
                }
            }
            return 0;
        }

        int[] queue;

        boolean bfs() {
            Arrays.fill(dist, -1);
            dist[0] = 0;
            queue[0] = 0;
            int head = 0, tail = 1;
            while (head < tail) {
                int cur = queue[head++];
                for (int i = 0; i < graph[cur].size(); i++) {
                    Edge e = graph[cur].get(i);
                    if (e.flow < e.cap && dist[e.to] == -1) {
                        dist[e.to] = dist[cur] + 1;
                        queue[tail++] = e.to;
                    }
                }
            }
            return dist[graph.length - 1] != -1;
        }

        public void update(long mid, List<Person> ms, List<Person> fs) {
            for (int i = 0; i < graph.length; i++) {
                for (Edge e : graph[i]) {
                    e.flow = 0;
                }
            }

            for (int i = 0; i < ms.size(); i++) {
                for (Edge e : graph[i + 1]) {
                    if (e.to >= 1 + ms.size()) {
                        int vert1 = ms.get(i).r * m + ms.get(i).c;
                        int vert2 = e.to - 1 - ms.size();

                        if (distRC[vert1][vert2] != INF
                                && 1L * distRC[vert1][vert2] * ms.get(i).t <= mid) {
                            e.cap = 1;
                        } else {
                            e.cap = 0;
                        }
                    }
                }
            }
            
            for (int i = 0; i < fs.size(); i++) {
                for (Edge e : graph[1 + fs.size() + 2 * n * m + i]) {
                    if (e.to < 1 + fs.size() + 2 * n * m) {
                        int vert1 = fs.get(i).r * m + fs.get(i).c;
                        int vert2 = e.to - 1 - fs.size() - n * m;

                        if (distRC[vert1][vert2] != INF
                                && 1L * distRC[vert1][vert2] * fs.get(i).t <= mid) {
                            e.rev.cap = 1;
                        } else {
                            e.rev.cap = 0;
                        }
                    }
                }
            }
        }
    }

    int[] dx = new int[] { 0, 1, 0, -1 };
    int[] dy = new int[] { 1, 0, -1, 0 };
    final int INF = Integer.MAX_VALUE / 3;
    int n, m;
    int[][] distRC;

    private Graph buildGraph(List<Person> ms, List<Person> fs) {

        int N = 1 + ms.size() + 2 * n * m + fs.size() + 1;
        Graph g = new Graph(N);

        for (int i = 0; i < ms.size(); i++) {
            g.addEdge(0, 1 + i, 1);
        }

        for (int i = 0; i < ms.size(); i++) {
            for (int r = 0; r < n; r++) {
                for (int c = 0; c < m; c++) {
                    int vert1 = ms.get(i).r * m + ms.get(i).c;
                    int vert2 = r * m + c;
                    if (distRC[vert1][vert2] != INF) {
                        g.addEdge(1 + i, 1 + ms.size() + vert2, 1);
                    }
                }
            }
        }
        for (int i = 0; i < n * m; i++) {
            g.addEdge(1 + ms.size() + i, 1 + ms.size() + n * m + i, 1);
        }

        for (int j = 0; j < fs.size(); j++) {
            for (int r = 0; r < n; r++) {
                for (int c = 0; c < m; c++) {
                    int vert1 = fs.get(j).r * m + fs.get(j).c;
                    int vert2 = r * m + c;
                    if (distRC[vert1][vert2] != INF) {
                        g.addEdge(1 + ms.size() + n * m + vert2, 1 + ms.size()
                                + 2 * n * m + j, 1);
                    }
                }
            }
        }

        for (int j = 0; j < fs.size(); j++) {
            g.addEdge(1 + ms.size() + 2 * n * m + j, N - 1, 1);
        }

        return g;
    }

    void solve() {
        n = in.nextInt();
        m = in.nextInt();
        int males = in.nextInt(), females = in.nextInt();
        char[][] field = new char[n][m];
        for (int i = 0; i < n; i++) {
            field[i] = in.next().toCharArray();
        }

        distRC = new int[n * m][n * m];
        for (int i = 0; i < n * m; i++) {
            Arrays.fill(distRC[i], INF);
            distRC[i][i] = 0;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int d = 0; d < 4; d++) {
                    int ni = i + dx[d], nj = j + dy[d];
                    if (0 <= ni && ni < n && 0 <= nj && nj < m
                            && field[i][j] != '#' && field[ni][nj] != '#') {
                        distRC[i * m + j][ni * m + nj] = 1;
                    }
                }
            }
        }
        for (int k = 0; k < distRC.length; k++) {
            for (int i = 0; i < distRC.length; i++) {
                for (int j = 0; j < distRC.length; j++) {
                    distRC[i][j] = Math.min(distRC[i][j], distRC[i][k] + distRC[k][j]);
                }
            }
        }

        Person me = new Person(in.nextInt() - 1, in.nextInt() - 1, in.nextInt());
        List<Person> ms = new ArrayList<>(), fs = new ArrayList<>();
        for (int i = 0; i < males; i++) {
            ms.add(new Person(in.nextInt() - 1, in.nextInt() - 1, in.nextInt()));
        }
        for (int i = 0; i < females; i++) {
            fs.add(new Person(in.nextInt() - 1, in.nextInt() - 1, in.nextInt()));
        }

        if (Math.abs(males - females) != 1) {
            out.println(-1);
            return;
        }
        int all = (males + females + 1) / 2;
        if (males < females) {
            ms.add(me);
        } else {
            fs.add(me);
        }
        
        long MAX = n * m * 1_000_000_000L;
        long left = -1, right = MAX;
        Graph g = buildGraph(ms, fs);
        while (left < right - 1) {
            long mid = (left + right) >>> 1;
            g.update(mid, ms, fs);
            if (g.flow() == all) {
                right = mid;
            } else {
                left = mid;
            }
        }

        if (right == MAX) {
            right = -1;
        }
        out.println(right);
    }

    class Person {
        int r, c, t;

        public Person(int r, int c, int t) {
            super();
            this.r = r;
            this.c = c;
            this.t = t;
        }
    }

    FastScanner in;
    PrintWriter out;

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

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new F().run();

    }
}