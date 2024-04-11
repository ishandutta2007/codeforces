import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        FKoshmarYevklida solver = new FKoshmarYevklida();
        solver.solve(1, in, out);
        out.close();
    }

    static class FKoshmarYevklida {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            DSU dsu = new DSU(m + 1);
            List<Integer> result = new ArrayList<>();
            int basis = 0;
            for (int i = 0; i < n; i++) {
                int k = in.nextInt();
                int a = in.nextInt() - 1, b;
                if (k == 1) {
                    b = m;
                } else {
                    b = in.nextInt() - 1;
                }
                if (dsu.unite(a, b)) {
                    result.add(i);
                    basis++;
                }
            }
//        for (int i = 0; i < m; i++) {
//            if (dsu.parent[i] == i) {
//                if (dsu.minUnit[i] != Integer.MAX_VALUE) {
//                    result.add(dsu.minUnit[i]);
//                    basis++;
//                }
//            }
//        }
//        Collections.sort(result);
            basis = MathUtils.modPow(2, basis, 1000000007);
            out.println(basis + " " + result.size());
            for (int i : result) {
                out.print((i + 1) + " ");
            }
        }

        public class DSU {
            int[] parent;
            int[] rank;
            int[] minUnit;
            public int[] size;
            public int sets;

            public DSU(int n) {
                parent = new int[n];
                rank = new int[n];
                size = new int[n];
                minUnit = new int[n];
                Arrays.fill(minUnit, Integer.MAX_VALUE);
                Arrays.fill(size, 1);
                for (int i = 0; i < n; i++) {
                    parent[i] = i;
                }
                this.sets = n;
            }

            public int get(int v) {
                if (parent[v] == v) {
                    return v;
                }
                return parent[v] = get(parent[v]);
            }

            public boolean unite(int u, int v) {
                u = get(u);
                v = get(v);
                if (u == v) {
                    return false;
                }
                sets--;
                if (rank[u] == rank[v]) {
                    rank[u]++;
                }
                if (rank[u] > rank[v]) {
                    parent[v] = u;
                    size[u] += size[v];
                    minUnit[u] = Math.min(minUnit[u], minUnit[v]);
                } else {
                    parent[u] = v;
                    size[v] += size[u];
                    minUnit[v] = Math.min(minUnit[u], minUnit[v]);
                }
                return true;
            }

        }

    }

    static class FastScanner {
        public BufferedReader br;
        public StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        public FastScanner(String fileName) {
            try {
                br = new BufferedReader(new FileReader(fileName));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                    throw new UnknownError();
                }
                if (line == null) {
                    throw new UnknownError();
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

    }

    static class MathUtils {
        public static int modPow(int a, long b, int mod) {
            while (a < 0) {
                a += mod;
            }
            int res = 1;
            while (b > 0) {
                if ((b & 1) != 0) {
                    res = (int) ((long) res * a % mod);
                }
                a = (int) ((long) a * a % mod);
                b >>>= 1;
            }
            return res;
        }

    }
}