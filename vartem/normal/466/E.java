import java.io.*;
import java.util.*;

public class E {

    FastScanner in;
    PrintWriter out;

    List<Integer>[] graph;

    int[] timeIn, timeOut;
    int time;

    void dfs(int u) {
        timeIn[u] = time++;
        for (int t = 0; t < graph[u].size(); t++) {
            dfs(graph[u].get(t));
        }
        timeOut[u] = time - 1;
    }

    void solve() {
        int n = in.nextInt(), m = in.nextInt();

        int[] type = new int[m];
        int[] x = new int[m], y = new int[m];

        List<Integer>[] qs = new List[m];
        int sent = 0;

        boolean[] root = new boolean[n];
        Arrays.fill(root, true);
        
        graph = new List[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            type[i] = in.nextInt();
            if (type[i] == 2) {
                x[i] = in.nextInt() - 1;
                qs[sent++] = new ArrayList<Integer>();
            } else {
                x[i] = in.nextInt() - 1;
                y[i] = in.nextInt() - 1;
                if (type[i] == 3) {
                    qs[y[i]].add(i);
                } else {
                    graph[y[i]].add(x[i]);
                    root[x[i]] = false;
                }
            }
        }

        timeIn = new int[n];
        timeOut = new int[n];
        for (int i = 0; i < n; i++) {
            if (root[i]) {
                dfs(i);
            }
        }

        DSU dsu = new DSU(n);
        boolean[] ans = new boolean[m];
        
        sent = 0;
        for (int i = 0; i < m; i++) {
            if (type[i] == 1) {
                dsu.union(x[i], y[i]);
            } else if (type[i] == 2) {
                for (int q : qs[sent]) {
                    int r1 = dsu.get(x[q]), r2 = dsu.get(x[i]);
                    if (r1 == r2 && isParent(x[q], x[i])) {
                        ans[q] = true;
                    }
                }
                sent++;
            }
        }

        for (int i = 0; i < m; i++) {
            if (type[i] == 3){ 
                out.println(ans[i] ? "YES" : "NO");
            }
        }
    }

    private boolean isParent(int i, int j) {
        return timeIn[i] <= timeIn[j] && timeOut[j] <= timeOut[i];
    }

    class DSU {
        int[] p;

        public DSU(int n) {
            p = new int[n];
            for (int i = 0; i < n; i++) {
                p[i] = i;
            }
        }

        int get(int i) {
            if (p[i] == i) {
                return i;
            }
            return p[i] = get(p[i]);
        }

        void union(int a, int b) {
            a = get(a);
            b = get(b);
            if (a != b) {
                p[b] = a;
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
        new E().run();
    }
}