import java.io.*;
import java.util.*;

public class B {

    class DSU {
        int n;
        int[] parent;
        int comps;
        DSU(int n) {
            this.n = n;
            parent = new int[n];
            clear();
        }

        void clear() {
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
            comps = n;
        }

        int get(int u) {
            if (parent[u] == u) {
                return u;
            }
            return parent[u] = get(parent[u]);
        }

        boolean unite(int u, int v) {
            u = get(u);
            v = get(v);
            if (u == v) {
                return false;
            }
            parent[u] = v;
            comps--;
            return true;
        }
    }

    public void solve() {
        int n = in.nextInt();
        DSU dsu = new DSU(n);
        int root = -1;
        int[] a = new int[n];
        int[] ans = new int[n];

        for (int i = 0; i < n; i++ ){
            a[i] = in.nextInt() - 1;
            dsu.unite(i, a[i]);
            if (i == a[i] && root == -1) {
                root = i;
            }
        }
        ans = a.clone();

        if (root == -1) {
            dsu.clear();
            for (int i = 0; i < n; i++) {
                if (!dsu.unite(i, a[i])) {
                    ans[i] = i;
                    root = i;
                    break;
                }
            }
        }

        dsu.clear();
        for (int i = 0; i < n; i++) {
            if (i == root) {
                continue;
            }
            if (!dsu.unite(i, a[i])) {
                ans[i] = root;
                dsu.unite(i, ans[i]);
            }
        }

        int diff = 0;
        for (int i = 0; i < n; i++) {
            diff += (a[i] != ans[i]) ? 1 : 0;
        }
        out.println(diff);
        for (int i = 0; i < n; i++) {
            out.print((ans[i] + 1) + " ");
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
        new B().run();
    }
}