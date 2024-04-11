import java.io.*;
import java.util.*;

public class D {

    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        String[] s = new String[n];
        for (int i = 0; i < n; i++) {
            s[i] = in.nextToken().toLowerCase();
        }

        Map<String, Integer> map = new HashMap<>();

        int m = in.nextInt();
        String[] from = new String[m], to = new String[m];
        for (int i = 0; i < m; i++) {
            from[i] = in.nextToken().toLowerCase();
            to[i] = in.nextToken().toLowerCase();
            map.put(from[i], 0);
            map.put(to[i], 0);
        }

        int tmp = 0;
        for (String str : map.keySet()) {
            map.put(str, tmp++);
        }

        String[] all = map.keySet().toArray(new String[map.size()]);

        int[] min = new int[tmp], minR = new int[tmp];
        for (int i = 0; i < all.length; i++) {
            int countR = 0;
            for (char c : all[i].toCharArray()) {
                countR += c == 'r' ? 1 : 0;
            }
            minR[i] = countR;
            min[i] = all[i].length();
        }
        graph = new List[tmp];
        graphRev = new List[tmp];
        for (int i = 0; i < tmp; i++) {
            graph[i] = new ArrayList<>();
            graphRev[i] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            int f = map.get(from[i]), t = map.get(to[i]);
            graph[f].add(t);
            graphRev[t].add(f);
        }

        comp = new int[tmp];
        order = new ArrayList<>();
        for (int i = 0; i < tmp; i++) {
            if (comp[i] == 0) {
                dfs(i);
            }
        }

        Collections.reverse(order);
        Arrays.fill(comp, -1);
        int cs = 0;

        for (int i : order) {
            if (comp[i] == -1) {
                dfsRev(i, cs++);
            }
        }

        int[] minC = new int[cs], minRC = new int[cs];
        Arrays.fill(minRC, Integer.MAX_VALUE);
        for (int i = 0; i < tmp; i++) {
            int c = comp[i];
            if (minRC[c] > minR[i] || (minRC[c] == minR[i] && minC[c] > min[i])) {
                minRC[c] = minR[i];
                minC[c] = min[i];
            }
        }

        Collections.reverse(order);
        for (int i : order) {
            for (int j : graph[i]) {
                int a = comp[i], b = comp[j];
                if (minRC[b] < minRC[a]
                        || (minRC[b] == minRC[a] && minC[b] < minC[a])) {
                    minRC[a] = minRC[b];
                    minC[a] = minC[b];
                }
            }
        }

        long ansR = 0, ans = 0;
        for (String str : s) {
            if (!map.containsKey(str)) {
                ans += str.length();
                for (char c : str.toCharArray()) {
                    ansR += c == 'r' ? 1 : 0;
                }
            } else {
                int id = comp[map.get(str)];
                ansR += minRC[id];
                ans += minC[id];
            }
        }

        out.println(ansR + " " + ans);
    }

    List<Integer>[] graph, graphRev;
    List<Integer> order;
    int[] comp;

    void dfs(int u) {
        comp[u] = 1;
        for (int v : graph[u]) {
            if (comp[v] == 0) {
                dfs(v);
            }
        }
        order.add(u);
    }

    void dfsRev(int u, int c) {
        comp[u] = c;
        for (int v : graphRev[u]) {
            if (comp[v] == -1) {
                dfsRev(v, c);
            }
        }
    }

    class DSU {
        int[] p, minR, min;

        public DSU(int n) {
            p = new int[n];
            minR = new int[n];
            min = new int[n];
        }

        int get(int a) {
            if (p[a] == a) {
                return a;
            }
            return p[a] = get(p[a]);
        }

        void union(int a, int b) {
            a = get(a);
            b = get(b);
            if (a == b) {
                return;
            }

            p[b] = a;
            if (minR[b] < minR[a] || (minR[b] == minR[a] && min[b] < min[a])) {
                minR[a] = minR[b];
                min[a] = min[b];
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