import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;

public class VCFD {

    static int[] a;
    static int[][] edges, rev;
    static ITree[] cache;

    static class Value {
        int maxAdd, maxTotal, total;

        void reset() {
            maxAdd = total = maxTotal = 0;
        }

        void combine(Value o) {
            total += o.total;
            maxTotal += o.maxTotal;
            maxAdd = Math.max(maxAdd, o.maxAdd);
        }
    }

    static class ITree {
        int size;
        Value[] vs;

        ITree(int n) {
            size = 1;
            while (size < n) {
                size *= 2;
            }
            vs = new Value[2 * size - 1];
            for (int i = 0; i < vs.length; ++i) {
                vs[i] = new Value();
            }
        }

        void reset() {
            for (int i = 0; i < vs.length; ++i) {
                vs[i].reset();
            }
        }

        void get(int l, int r, Value v, int i, int cap) {
            get(0, 0, size, l, r, v, i, cap);
        }

        private boolean get(int n, int nl, int nr, int l, int r, Value v, int i, int cap) {
            if (nr <= l || r <= nl) {
                return false;
            }
            if (nl + 1 == nr && vs[n].total == 0) {
                vs[n].combine(dfs(edges[i][nl], rev[i][nl], cap));
            }
            if (l <= nl && nr <= r && vs[n].total > 0) {
                v.combine(vs[n]);
                return true;
            }
            int mid = (nl + nr) / 2;
            boolean full = true;
            full &= get(2 * n + 1, nl, mid, l, r, v, i, cap);
            full &= get(2 * n + 2, mid, nr, l, r, v, i, cap);
            if (vs[n].total == 0 && full) {
                vs[n].combine(vs[2 * n + 1]);
                vs[n].combine(vs[2 * n + 2]);
            }
            return full;
        }
    }

    static Value dfs(int i, int p, int cap) {
        Value v = new Value();
        if (a[i] < cap) {
            v.total = 1;
            return v;
        }
        v.total = 1;
        v.maxTotal = 1;
        if (p == -1) {
            cache[i].get(0, edges[i].length, v, i, cap);
        } else {
            cache[i].get(0, p, v, i, cap);
            cache[i].get(p + 1, edges[i].length, v, i, cap);
        }
        if (v.maxTotal < v.total) {
            v.maxAdd += v.maxTotal;
            v.maxTotal = 0;
        }
        return v;
    }

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int k = in.nextInt();
        a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
//            a[i] = 1000000000;
        }
        ArrayList<Integer>[] edges = new ArrayList[n];
        for (int i = 0; i < n; ++i) {
            edges[i] = new ArrayList<>();
        }
//        Random rnd = new Random();
        for (int i = 0; i < n - 1; ++i) {
            int u = in.nextInt() - 1;
            int v = in.nextInt() - 1;
//            int u = 0;
//            int v = i + 1;
            edges[u].add(v);
            edges[v].add(u);
        }
        VCFD.edges = new int[n][];
        for (int i = 0; i < n; ++i) {
            VCFD.edges[i] = new int[edges[i].size()];
            for (int j = 0; j < edges[i].size(); ++j) {
                VCFD.edges[i][j] = edges[i].get(j);
            }
            Arrays.sort(VCFD.edges[i]);
        }
        rev = new int[n][];
        for (int i = 0; i < n; ++i) {
            rev[i] = new int[VCFD.edges[i].length];
            for (int j = 0; j < VCFD.edges[i].length; ++j) {
                rev[i][j] = Arrays.binarySearch(VCFD.edges[VCFD.edges[i][j]], i);
                if (rev[i][j] < 0) {
                    throw new AssertionError();
                }
            }
        }
        cache = new ITree[n];
        for (int i = 0; i < n; ++i) {
            cache[i] = new ITree(VCFD.edges[i].length);
        }
        int l = 0, r = 1000001;
        loop: while (l + 1 < r) {
            int mid = (l + r) / 2;
            for (int i = 0; i < n; ++i) {
                cache[i].reset();
            }
            for (int i = 0; i < n; ++i) {
                Value v = dfs(i, -1, mid);
                if (v.maxTotal + v.maxAdd >= k) {
                    l = mid;
                    continue loop;
                }
            }
            if (l != mid) r = mid;
        }
//        System.err.println(cnt);
        out.println(l);
    }

    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);
        solve(new Input(new BufferedReader(new InputStreamReader(System.in))), out);
        out.close();
    }

    static class Input {
        BufferedReader in;
        StringBuilder sb = new StringBuilder();

        public Input(BufferedReader in) {
            this.in = in;
        }

        public Input(String s) {
            this.in = new BufferedReader(new StringReader(s));
        }

        public String next() throws IOException {
            sb.setLength(0);
            while (true) {
                int c = in.read();
                if (c == -1) {
                    return null;
                }
                if (" \n\r\t".indexOf(c) == -1) {
                    sb.append((char)c);
                    break;
                }
            }
            while (true) {
                int c = in.read();
                if (c == -1 || " \n\r\t".indexOf(c) != -1) {
                    break;
                }
                sb.append((char)c);
            }
            return sb.toString();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }
}