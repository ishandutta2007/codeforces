import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;

public class CF494D {

    final static long mod = 1000000007;

    static class Edge {
        int b;
        long len;

        public Edge(int b, long len) {
            this.b = b;
            this.len = len;
        }
    }

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        edges = new ArrayList[n];
        for (int i = 0; i < n; ++i) {
            edges[i] = new ArrayList<>();
        }
        for (int i = 0; i < n - 1; ++i) {
            int u = in.nextInt() - 1;
            int v = in.nextInt() - 1;
            long len = in.nextLong();
            edges[u].add(new Edge(v, len));
            edges[v].add(new Edge(u, len));
        }
        depth = new long[n];
        count = new long[n];
        sumLen = new long[n];
        sumLen2 = new long[n];
        dfs(0, -1);
        totalSumLen = new long[n];
        totalSumLen2 = new long[n];
        dfs2(0, -1, 0, 0, 0);
        int qs = in.nextInt();
        int[] qu = new int[qs];
        int[] qv = new int[qs];
        qw = new int[qs];
        qi = new ArrayList[n];
        for (int i = 0; i < n; ++i) {
            qi[i] = new ArrayList<>();
        }
        for (int i = 0; i < qs; ++i) {
            qu[i] = in.nextInt() - 1;
            qv[i] = in.nextInt() - 1;
            qi[qu[i]].add(i);
            qi[qv[i]].add(i);
        }
        p = new int[n];
        r = new int[n];
        root = new int[n];
        prev = new int[qs];
        for (int i = 0; i < n; ++i) {
            root[i] = p[i] = i;
        }
        Arrays.fill(prev, -1);
        qdfs(0, -1);
        for (int i = 0; i < qs; ++i) {
            long dist = (depth[qu[i]] + depth[qv[i]] + 2 * (mod - depth[qw[i]])) % mod;
            if (qw[i] == qv[i]) {
                long shiftedCount = (n + mod - count[qv[i]]) % mod;
                long shiftedSumLen = (totalSumLen[qv[i]] + mod - sumLen[qv[i]]) % mod;
                long shiftedSumLen2 = (totalSumLen2[qv[i]] + mod - sumLen2[qv[i]] + shiftedCount * (dist * dist % mod) + 2 * shiftedSumLen * dist) % mod;
                out.println((totalSumLen2[qu[i]] + 2 * (mod - shiftedSumLen2)) % mod);
            } else {
                long shiftedCount = (count[qv[i]]) % mod;
                long shiftedSumLen = (sumLen[qv[i]]) % mod;
                long shiftedSumLen2 = (sumLen2[qv[i]] + shiftedCount * (dist * dist % mod) + 2 * shiftedSumLen * dist) % mod;
                out.println((2 * shiftedSumLen2 + mod - totalSumLen2[qu[i]]) % mod);
            }
        }
//        out.println(10L * 1000000000 % mod * 1000000000 % mod);
//        out.println(1000000005L * 1000000000 % mod * 1000000000 % mod);
//        out.println(1000000002L * 1000000000 % mod * 1000000000 % mod);
//        out.println(23L * 1000000000 % mod * 1000000000 % mod);
//        out.println(1000000002L * 1000000000 % mod * 1000000000 % mod);
    }

    static ArrayList<Edge>[] edges;
    static long[] depth, count, sumLen, sumLen2, totalSumLen, totalSumLen2;
    static int[] qw;
    static ArrayList<Integer>[] qi;
    static int[] p, r, root, prev;

    private static void qdfs(int i, int p) {
        for (int q : qi[i]) {
            if (prev[q] == -1) {
                prev[q] = i;
            } else {
                qw[q] = root[get(prev[q])];
            }
        }
        for (Edge e : edges[i]) {
            if (e.b != p) {
                qdfs(e.b, i);
                root[unite(i, e.b)] = i;
            }
        }
    }

    static int get(int i) {
        if (p[i] != i) {
            p[i] = get(p[i]);
        }
        return p[i];
    }

    static int unite(int i, int j) {
        i = get(i);
        j = get(j);
        if (i == j) {
            throw new AssertionError();
        }
        if (r[i] < r[j]) {
            p[i] = j;
        } else {
            p[j] = i;
        }
        if (r[i] == r[j]) {
            r[i]++;
        }
        return p[i];
    }

    private static void dfs(int i, int p) {
        count[i] = 1;
        for (Edge e : edges[i]) {
            if (e.b != p) {
                depth[e.b] = (depth[i] + e.len) % mod;
                dfs(e.b, i);
                count[i] = (count[i] + count[e.b]) % mod;
                sumLen[i] = (sumLen[i] + sumLen[e.b] + count[e.b] * e.len) % mod;
                sumLen2[i] = (sumLen2[i] + sumLen2[e.b] + count[e.b] * (e.len * e.len % mod) + 2 * sumLen[e.b] * e.len) % mod;
            }
        }
    }

    static void dfs2(int i, int p, long countUp, long sumLenUp, long sumLen2Up) {
        totalSumLen[i] = (sumLenUp + sumLen[i]) % mod;
        totalSumLen2[i] = (sumLen2Up + sumLen2[i]) % mod;
        countUp = (countUp + count[i]) % mod;
        sumLenUp = (sumLenUp + sumLen[i]) % mod;
        sumLen2Up = (sumLen2Up + sumLen2[i]) % mod;
        for (Edge e : edges[i]) {
            if (e.b != p) {
                long countUp1 = (countUp + mod - count[e.b]) % mod;
                long sumLenUp1 = (sumLenUp + (mod - sumLen[e.b]) + (mod - count[e.b]) * e.len) % mod;
                long sumLen2Up1 = (sumLen2Up + (mod - sumLen2[e.b]) + (mod - count[e.b]) * (e.len * e.len % mod) + 2 * (mod - sumLen[e.b]) * e.len) % mod;
                long countUp2 = countUp1;
                long sumLenUp2 = (sumLenUp1 + countUp1 * e.len) % mod;
                long sumLen2Up2 = (sumLen2Up1 + countUp1 * (e.len * e.len % mod) + 2 * sumLenUp1 * e.len) % mod;
                dfs2(e.b, i, countUp2, sumLenUp2, sumLen2Up2);
            }
        }
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