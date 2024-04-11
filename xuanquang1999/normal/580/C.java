import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
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
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

    }

    static int n, m, a[], consCat[], dp[], ans;
    static ArrayList<ArrayList<Integer>> graph;

    static void DFS(int u, int p) {
        if (u != 0 && graph.get(u).size() == 1 && dp[u] <= m)
            ++ans;
        for (int v : graph.get(u)) {
            if (v == p)
                continue;
            consCat[v] = (a[v] == 0) ? 0 : (consCat[u] + 1);
            dp[v] = Math.max(dp[u], consCat[v]);
            DFS(v, u);
        }
    }

    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        n = sc.nextInt();
        m = sc.nextInt();

        a = new int[n];
        for (int u = 0; u < n; ++u)
            a[u] = sc.nextInt();

        graph = new ArrayList<>();
        for (int u = 0; u < n; ++u)
            graph.add(new ArrayList<>());
        for (int i = 0; i < n - 1; ++i) {
            int u = sc.nextInt(), v = sc.nextInt();
            --u;
            --v;
            graph.get(u).add(v);
            graph.get(v).add(u);
        }

        consCat = new int[n];
        dp = new int[n];

        dp[0] = consCat[0] = a[0];
        DFS(0, -1);

        System.out.println(ans);
    }
}