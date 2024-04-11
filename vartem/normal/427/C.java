import java.io.*;
import java.util.*;

public class C {

    List<Integer>[] graph, graphRev;

    List<Integer> order = new ArrayList<>();
    boolean[] vis;

    void dfs(int u) {
        vis[u] = true;
        for (int v : graph[u]) {
            if (!vis[v]) {
                dfs(v);
            }
        }
        order.add(u);
    }

    int[] comp;

    void dfsRev(int u, int c) {
        comp[u] = c;
        for (int v : graphRev[u]) {
            if (comp[v] == -1) {
                dfsRev(v, c);
            }
        }
    }

    public void solve() {
        int n = in.nextInt();
        graph = new List[n];
        graphRev = new List[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
            graphRev[i] = new ArrayList<>();
        }
        int[] val = new int[n];
        for (int i = 0; i < n; i++) {
            val[i] = in.nextInt();
        }

        int m = in.nextInt();

        for (int i = 0; i < m; i++) {
            int from = in.nextInt() - 1, to = in.nextInt() - 1;
            graph[from].add(to);
            graphRev[to].add(from);
        }

        vis = new boolean[n];
        comp = new int[n];
        Arrays.fill(comp, -1);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i);
            }
        }

        Collections.reverse(order);

        int comps = 0;
        for (int j : order) {
            if (comp[j] == -1) {
                dfsRev(j, comps++);
            }
        }
        
        int[] min = new int[comps], count = new int[comps];
        Arrays.fill(min, Integer.MAX_VALUE);
        
        for (int i = 0; i < n; i++) {
            if (min[comp[i]] > val[i]) {
                min[comp[i]] = val[i];
                count[comp[i]] = 0;
            }
            if (min[comp[i]] == val[i]) {
                count[comp[i]]++;
            }
        }
        
        long mod = (long) (1e9 + 7);
        long sum = 0, cnt = 1;
        for (int i = 0; i < comps; i++) {
            sum += min[i];
            cnt = (1l * cnt * count[i]) % mod;
        }
        out.println(sum + " " + cnt);
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
        new C().run();
    }
}