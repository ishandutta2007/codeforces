import java.io.*;
import java.util.*;

public class C {

    class Edge {
        int from, to;
        int size;

        public Edge(int from, int to) {
            this.from = from;
            this.to = to;
        }
    }

    List<Edge>[] tree;
    Edge[] first;

    int go(int u, int p) {
        int size = 1;

        for (int t = 0; t < tree[u].size(); t++) {
            Edge e = tree[u].get(t);
            if (e.to == p) {
                continue;
            }
            int sz = go(e.to, u);
            e.size = sz;
            size += sz;
        }
        for (int t = 0; t < tree[u].size(); t++) {
            Edge e = tree[u].get(t);
            if (e.to == p) {
                e.size = tree.length - size;
            }
        }

        return size;
    }

    void mark(int u, int p, Edge m) {
        first[u] = m;

        for (int t = 0; t < tree[u].size(); t++) {
            Edge e = tree[u].get(t);
            if (e.to == p) {
                continue;
            }
            mark(e.to, u, m);
        }
    }

    public void solve() {
        int n = in.nextInt();
        tree = new List[n];
        first = new Edge[n];
        for (int i = 0; i < n; i++) {
            tree[i] = new ArrayList<>();
        }
        for (int i = 0; i < n - 1; i++) {
            int from = in.nextInt() - 1, to = in.nextInt() - 1;
            tree[from].add(new Edge(from, to));
            tree[to].add(new Edge(to, from));
        }

        go(0, -1);

        boolean[] ans = new boolean[n];
        Edge[] max1 = new Edge[n], max2 = new Edge[n];
        for (int i = 0; i < n; i++) {
            for (Edge e : tree[i]) {
                if (max1[i] == null || max1[i].size < e.size) {
                    max2[i] = max1[i];
                    max1[i] = e;
                } else if (max2[i] == null || max2[i].size < e.size) {
                    max2[i] = e;
                }
            }
        }
        List<Integer> cs = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (max1[i].size <= n / 2) {
                cs.add(i);
            }
        }

        for (int c : cs) {
            for (Edge e : tree[c]) {
                mark(e.to, c, e);
            }

            for (int i = 0; i < n; i++) {
                if (max1[i].size <= n / 2) {
                    ans[i] |= true;
                    continue;
                }

                int initSize = max1[i].size;
                Edge best = max1[c];
                if (max1[c] == first[i]) {
                    best = max2[c];
                }
                initSize -= best.size;
                ans[i] |= initSize <= n / 2;
            }
        }

        for (int i = 0; i < n; i++) {
            out.print(ans[i] ? 1 : 0);
            if (i + 1 == n) {
                out.println();
            } else {
                out.print(' ');
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
        new C().run();
    }
}