import java.io.*;
import java.util.*;

public class D {

    FastScanner in;
    PrintWriter out;

    int SQRT = 200;

    void solve() {
        int n = in.nextInt(), m = in.nextInt();
        Edge[] edges = new Edge[m];
        int[] deg = new int[n];
        for (int i = 0; i < m; i++) {
            edges[i] = new Edge(in.nextInt() - 1, in.nextInt() - 1,
                    in.nextInt());
            deg[edges[i].from]++;
            deg[edges[i].to]++;
        }
        Arrays.sort(edges);

        int[][] graph = new int[n][];
        int[][] col = new int[n][];
        for (int i = 0; i < n; i++) {
            graph[i] = new int[deg[i]];
            col[i] = new int[deg[i]];
        }
        Arrays.fill(deg, 0);
        for (int i = 0; i < m; i++) {
            int fr = edges[i].from, to = edges[i].to;
            graph[fr][deg[fr]] = to;
            col[fr][deg[fr]++] = edges[i].col;

            graph[to][deg[to]] = fr;
            col[to][deg[to]++] = edges[i].col;
        }
        int[] begin = new int[n];

        int qs = in.nextInt();
        Map<Long, Integer> qId = new HashMap<Long, Integer>();
        int[] q1 = new int[qs], q2 = new int[qs];
        int[] unique1 = new int[qs], unique2 = new int[qs];
        int uniqs = 0;
        for (int i = 0; i < qs; i++) {
            q1[i] = in.nextInt() - 1;
            q2[i] = in.nextInt() - 1;
            if (q1[i] > q2[i]) {
                int tmp = q1[i];
                q1[i] = q2[i];
                q2[i] = tmp;
            }

            long hash = 1L * q1[i] * n + q2[i];
            if (qId.containsKey(hash)) {
                continue;
            } else {
                qId.put(hash, uniqs);
                unique1[uniqs] = q1[i];
                unique2[uniqs] = q2[i];
                uniqs++;
            }
        }

        long[] keys = new long[uniqs];
        int[] ids = new int[uniqs];
        {
            int tmp = 0;
            for (long l : qId.keySet()) {
                keys[tmp++] = l;
            }
            Arrays.sort(keys);
            for (int i = 0; i < uniqs; i++) {
                ids[i] = qId.get(keys[i]);
            }
        }

        int[] result = new int[uniqs];

        DSU dsu = new DSU(n);
        int[] all = new int[2 * SQRT];
        int[] queue = new int[2 * SQRT];

        int[] lastColor = new int[n];

        for (int l = 0; l < m;) {
            int r = l;
            int curCol = edges[l].col;
            while (r < m && edges[r].col == curCol) {
                r++;
            }

            int size = r - l;
            if (size < SQRT) {
                int ptr = 0;
                for (int t = l; t < r; t++) {
                    all[ptr++] = edges[t].from;
                    all[ptr++] = edges[t].to;
                }
                Arrays.sort(all, 0, ptr);

                for (int ll = 0; ll < ptr; ll++) {
                    if (ll > 0 && all[ll] == all[ll - 1]) {
                        continue;
                    }
                    int start = all[ll];
                    if (lastColor[start] == curCol) {
                        continue;
                    }

                    int head = 0, tail = 0;
                    queue[tail++] = start;
                    lastColor[start] = curCol;

                    while (head < tail) {
                        int cur = queue[head++];
                        int beg = begin[cur];

                        int[] curG = graph[cur], curC = col[cur];
                        while (beg < curC.length && curC[beg] == curCol) {
                            int nxt = curG[beg++];
                            if (lastColor[nxt] < curCol) {
                                lastColor[nxt] = curCol;
                                queue[tail++] = nxt;
                            }
                        }
                    }

                    for (int fst = 0; fst < tail; fst++) {
                        int v1 = queue[fst];
                        for (int snd = fst + 1; snd < tail; snd++) {
                            int v2 = queue[snd];
                            long hash;
                            if (v1 < v2) {
                                hash = 1L * v1 * n + v2;
                            } else {
                                hash = 1L * v2 * n + v1;
                            }
                            
                            int left = -1, right = uniqs;
                            while (left < right - 1) {
                                int mid = (left + right) >>> 1;
                                if (hash >= keys[mid]) {
                                    left = mid;
                                } else {
                                    right = mid;
                                }
                            }
                            if (left >= 0 && keys[left] == hash) {
                                result[ids[left]]++;
                            }
                        }
                    }
                }

            } else {
                dsu.clear();
                for (int t = l; t < r; t++) {
                    dsu.unite(edges[t].from, edges[t].to);
                }

                for (int i = 0; i < uniqs; i++) {
                    if (dsu.get(unique1[i]) == dsu.get(unique2[i])) {
                        result[i]++;
                    }
                }
            }

            for (int t = l; t < r; t++) {
                begin[edges[t].from]++;
                begin[edges[t].to]++;
            }
            l = r;
        }

        for (int i = 0; i < qs; i++) {
            long hash = 1L * q1[i] * n + q2[i];
            out.println(result[qId.get(hash)]);
        }
    }

    static class Edge implements Comparable<Edge> {
        int from, to, col;

        public Edge(int from, int to, int col) {
            this.from = from;
            this.to = to;
            this.col = col;
        }

        @Override
        public int compareTo(Edge o) {
            return col - o.col;
        }

        @Override
        public String toString() {
            return "Edge [from=" + from + ", to=" + to + ", col=" + col + "]";
        }
        
        
    }

    static class DSU {
        int[] p, r;

        public DSU(int n) {
            p = new int[n];
            r = new int[n];
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

        void clear() {
            Arrays.fill(r, 0);
            for (int i = 0; i < p.length; i++) {
                p[i] = i;
            }
        }

        void unite(int u, int v) {
            u = get(u);
            v = get(v);
            if (u == v) {
                return;
            }

            if (r[u] == r[v]) {
                r[u]++;
            }
            if (r[u] > r[v]) {
                p[u] = v;
            } else {
                p[v] = u;
            }
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