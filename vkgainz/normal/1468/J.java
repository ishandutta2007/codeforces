import java.util.*;
import java.io.*;

public class RoadReform {
    static int n;
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        int t = sc.nextInt();
        while (t-- > 0) {
            n = sc.nextInt();
            int m = sc.nextInt();
            int k = sc.nextInt();
            ArrayList<Edge> edges = new ArrayList<>();
            for (int i = 0; i < m; i++) {
                edges.add(new Edge(sc.nextInt(), sc.nextInt(), sc.nextInt()));
            }
            Collections.sort(edges, Comparator.comparingLong(q -> q.w));
            UF dsu = new UF(n + 1);
            long maxTaken = 0; int start = edges.size();
            for (int i = 0; i < edges.size(); i++) {
                if (edges.get(i).w > k) {
                    start = i; break;
                }
                dsu.union(edges.get(i).x, edges.get(i).y);
                maxTaken = Math.max(maxTaken, edges.get(i).w);
            }
            long ans = Long.MAX_VALUE;
            if (connected(dsu)) {
                ans = Math.min(ans, k - maxTaken);
                if (start != edges.size()) {
                    ans = Math.min(ans, edges.get(start).w - k);
                }
            } else {
                long cur = 0;
                Set<Integer> parents = new HashSet<>();
                for (int i = 1; i <= n; i++) parents.add(dsu.find(i));
                int components = parents.size();
                for (int i = start; i < edges.size(); i++) {
                    int u = edges.get(i).x;
                    int v = edges.get(i).y;
                    if (!dsu.connected(u, v)) {
                        cur += edges.get(i).w - k;
                        --components;
                        dsu.union(u, v);
                    }
                    if (components == 1) break;
                }
                ans = Math.min(ans, cur);
            }
            out.println(ans);

        }
        out.close();
    }

    static class Edge {
        int x; int y; long w;
        Edge(int x, int y, long w) {
            this.x = x; this.y = y; this.w = w;
        }
    }

    static boolean connected(UF dsu) {
        boolean ok = true;
        for (int i = 2; i <= n; i++) ok = ok && (dsu.connected(1, i));
        return ok;
    }



    static void sort(int[] a) {
        ArrayList<Integer> q = new ArrayList<>();
        for (int i : a) q.add(i);
        Collections.sort(q);
        for (int i = 0; i < a.length; i++) a[i] = q.get(i);
    }

    static void sort(long[] a) {
        ArrayList<Long> q = new ArrayList<>();
        for (long i : a) q.add(i);
        Collections.sort(q);
        for (int i = 0; i < a.length; i++) a[i] = q.get(i);
    }

    static class UF {
        private int[] parent;  // parent[i] = parent of i
        private byte[] rank;   // rank[i] = rank of subtree rooted at i (never more than 31)
        private int count;     // number of components
        private int[] size;
        public UF(int n) {
            if (n < 0) throw new IllegalArgumentException();
            count = n;
            parent = new int[n];
            rank = new byte[n];
            size = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                rank[i] = 0;
                size[i] = 1;
            }
        }

        public int find(int p) {
            while (p != parent[p]) {
                parent[p] = parent[parent[p]];    // path compression by halving
                p = parent[p];
            }
            return p;
        }

        public int count() {
            return count;
        }

        public boolean connected(int p, int q) {
            return find(p) == find(q);
        }

        public void union(int p, int q) {
            int rootP = find(p);
            int rootQ = find(q);
            if (rootP == rootQ) return;

            // make root of smaller rank point to root of larger rank
            if (rank[rootP] < rank[rootQ]) {
                parent[rootP] = rootQ;
                size[rootQ] = size[rootQ] + size[rootP];
            }
            else if (rank[rootP] > rank[rootQ]) {
                parent[rootQ] = rootP;
                size[rootP] = size[rootP] + size[rootQ];
            }
            else {
                parent[rootQ] = rootP;
                size[rootP] = size[rootP] + size[rootQ];
                rank[rootP]++;
            }
            count--;
        }
    }


    //-----------MyScanner class for faster input----------
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

}