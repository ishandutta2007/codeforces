import java.io.*;
import java.util.*;

public class A {

    List<Integer>[] graph;
    int[] comp;
    boolean fail = false;

    void dfs(int u, int c) {
        comp[u] = c;
        for (int t = 0; t < graph[u].size(); t++) {
            int v = graph[u].get(t);
            if (comp[v] == -1) {
                dfs(v, 1 - c);
            } else if (comp[u] == comp[v]) {
                fail = true;
            }
        }
    }

    public void solve() {
        int n = in.nextInt();
        graph = new List[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }

        int m = in.nextInt();
        comp = new int[n];
        Arrays.fill(comp, -1);
        for (int i = 0; i < m; i++) {
            int from = in.nextInt() - 1, to = in.nextInt() - 1;
            graph[from].add(to);
            graph[to].add(from);
        }

        for (int i = 0; i < n; i++) {
            if (comp[i] == -1) {
                dfs(i, 0);
            }
        }
        if (fail) {
            out.println(-1);
            return;
        }

        List<Integer>[] ans = new List[]{new ArrayList<>(), new ArrayList<>()};
        for (int i = 0; i < n; i++) {
            ans[comp[i]].add(i + 1);
        }
        for (int i = 0; i < 2; i++) {
            out.println(ans[i].size());
            for (int j : ans[i]) {
                out.print(j + " ");
            }
            out.println();
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
        new A().run();
    }
}