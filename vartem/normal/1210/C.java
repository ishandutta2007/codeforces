import java.io.*;
import java.util.*;

public class C {

    long[] value;
    List<Integer>[] graph;

    public static long gcd(long a, long b) {
        long t;
        while (a != 0) {
            t = b % a;
            b = a;
            a = t;
        }
        return b;
    }

    long ans = 0;
    int mod = 1000000007;

    int LOG = 17;
    int[][] up;
    long[][] gcd;
    int[] depth;

    void go(int u, int p) {
        up[0][u] = p;
        gcd[0][u] = value[u];
        for (int i = 1; i < LOG; i++) {
            int par = up[i - 1][u];
            if (par != -1) {
                up[i][u] = up[i - 1][par];
                gcd[i][u] = gcd(gcd[i - 1][u], gcd[i - 1][par]);
            } else {
                up[i][u] = -1;
                gcd[i][u] = gcd[i - 1][u];
            }
        }

        long curGcd = value[u];
        int lastStart = u;
        while (true) {
            int upVertex = lastStart;
            for (int i = LOG - 1; i >= 0; i--) {
                if (upVertex != -1 && ((curGcd == 0 && gcd[i][upVertex] == 0) || (curGcd != 0 && gcd[i][upVertex] % curGcd == 0))) {
                    upVertex = up[i][upVertex];
                }
            }

            int upDepth = (upVertex == -1) ? -1 : depth[upVertex];
            ans += (depth[lastStart] - upDepth) * curGcd % mod;
            if (upVertex == -1) {
                break;
            }
            lastStart = upVertex;
            curGcd = gcd(curGcd, value[upVertex]);
        }

        for (int v : graph[u]) {
            if (v != p) {
                depth[v] = depth[u] + 1;
                go(v, u);
            }
        }
    }

    void solve() {
        int n = in.nextInt();
        value = in.nextLongArray(n);
        graph = new List[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int i = 0; i < n - 1; i++) {
            int from = in.nextInt() - 1, to = in.nextInt() - 1;
            graph[from].add(to);
            graph[to].add(from);
        }
        up = new int[LOG][n];
        gcd = new long[LOG][n];
        depth = new int[n];
        depth[0] = 0;
        go(0, -1);
        out.println(ans % mod);
    }

    FastScanner in;
    PrintWriter out;

    void run() {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public boolean hasMoreTokens() {
            while (st == null || !st.hasMoreElements()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                    return false;
                }
                if (line == null) {
                    return false;
                }
                st = new StringTokenizer(line);
            }
            return true;
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public int[] nextIntArray(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }

        public long[] nextLongArray(int n) {
            long[] ret = new long[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextLong();
            }
            return ret;
        }
    }


    public static void main(String[] args) throws Exception {
        new C().run();
    }
}