import java.io.*;
import java.util.*;

public class D {

    List<Integer>[] graph;

    long[][] dp;

    void go(int u, int p) {
        long max1 = -1, max2 = -1;
        dp[u][0] = dp[u][1] = Integer.MAX_VALUE;
        long sum = 0;
        long min1 = Integer.MAX_VALUE, min2 = Integer.MAX_VALUE;
        int child1 = -1, child2 = -1;
        for (int t = 0; t < graph[u].size(); t++) {
            int v = graph[u].get(t);
            if (v == p) {
                continue;
            }
            go(v, u);
            long val = dp[v][1] - Math.min(dp[v][0], dp[v][1]);
            if (val < min1) {
                min2 = min1;
                child2 = child1;
                min1 = val;
                child1 = v;
            } else if (val < min2) {
                min2 = val;
                child2 = v;
            }
            sum += Math.min(dp[v][0], dp[v][1]);
        }

        if (child2 != -1) {
            dp[u][0] = Math.min(dp[u][0], sum + min1 + min2 - 1);
        }

        dp[u][1] = Math.min(dp[u][1], sum + 1);
        for (int t = 0; t < graph[u].size(); t++) {
            int v = graph[u].get(t);
            if (v == p) {
                continue;
            }

            dp[u][1] = Math.min(dp[u][1], sum - Math.min(dp[v][0], dp[v][1]) + dp[v][1]);
        }
    }

    public void solve() {
        int n = in.nextInt();
        long x = in.nextInt(), y = in.nextInt();
        graph = new List[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < n - 1; i++) {
            int a = in.nextInt() - 1, b = in.nextInt() - 1;
            graph[a].add(b);
            graph[b].add(a);
        }

        if (n == 2) {
            out.println(x);
            return;
        }
        if (n == 3) {
            out.println(Math.min(x + y, x + x));
            return;
        }
        int maxDeg = 0;
        for (int i = 0; i < n; i++) {
            maxDeg = Math.max(maxDeg, graph[i].size());
        }
        if (maxDeg == n - 1) {
            out.println(Math.min(x + y * (n - 2), x * 2 + y * (n - 3)));
            return;
        }
        if (y < x) {
            out.println((n - 1) * y);
            return;
        }
        dp = new long[n][2];
        go(0, -1);

        long num = n - Math.min(dp[0][0], dp[0][1]);
        out.println(x * num + y * (n - 1 - num));
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
        new D().run();
    }
}