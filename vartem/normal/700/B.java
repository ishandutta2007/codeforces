import java.io.*;
import java.util.*;

public class B {

    List<Integer>[] tree;
    boolean[] uni;
    int[] size;
    long ans = 0;
    int k;

    void dfs(int u, int p) {
        size[u] = uni[u] ? 1 : 0;
        for (int t = 0; t < tree[u].size(); t++) {
            int v = tree[u].get(t);
            if (v == p) {
                continue;
            }
            dfs(v, u);
            ans += Math.min(size[v], 2 * k - size[v]);
            size[u] += size[v];
        }
    }


    public void solve() {
        int n = in.nextInt();
        k = in.nextInt();
        tree = new List[n];
        uni = new boolean[n];
        for (int i = 0; i < n; i++) {
            tree[i] = new ArrayList<>();
        }
        size = new int[n];
        for (int i = 0; i < 2 * k; i++) {
            uni[in.nextInt() - 1] = true;
        }
        for (int i = 0; i < n - 1; i++) {
            int u = in.nextInt() - 1, v = in.nextInt() - 1;
            tree[u].add(v);
            tree[v].add(u);
        }

        dfs(0, -1);
        out.println(ans);
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
        new B().run();
    }
}