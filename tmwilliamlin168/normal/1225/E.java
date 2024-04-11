import java.io.*;
import java.util.*;
 
import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import static java.util.Comparator.*;
 
public class Main {
    FastScanner in;
    PrintWriter out;
    ArrayList<Integer>[] graph;
    ArrayList<GraphPair>[] weightedGraph;
    long mod = (long) 1e9 + 7; // 998_244_353L || (long) 1e9 + 9
    boolean multitests = false;
 
    private void solve() throws IOException {
        // solveA();
        // solveB();
        //solveB_map();
        // solveC();
        // solveD();
        solveE();
        // solveF();
    }
 
    private void solveA() throws IOException {
        int da = in.nextInt(), db = in.nextInt();
        if (da == db)
            out.println(da + "0 " + db + "1");
        else if (db == da + 1)
            out.println(da + "9 " + db + "0");
        else if (da == 9 && db == 1)
            out.println("9 10");
        else
            out.println(-1);
    }
 
    private void solveB() throws IOException {
        int[] cntr = new int[(int) 1e6 + 1];
        for (int t = in.nextInt(); t-- > 0; ) {
            int n = in.nextInt(), k = in.nextInt(), d = in.nextInt();
            int[] a = in.nextIntArray(n);
 
            int l = 0, r = 0, cnt = 0, ans = n;
            while (l + d <= n) {
                while (r < l + d) {
                    if (cntr[a[r]]++ == 0)
                        cnt++;
                    r++;
                }
                ans = min(ans, cnt);
                if (--cntr[a[l]] == 0)
                    cnt--;
                l++;
            }
            while (l < r) {
                if (--cntr[a[l]] == 0)
                    cnt--;
                l++;
            }
            if (cnt != 0 || l != n)
                ans = 1 / 0;
            out.println(ans);
        }
    }
 
    private void solveB_map() throws IOException {
        int n = in.nextInt(), k = in.nextInt(), d = in.nextInt();
        int[] a = in.nextIntArray(n);
 
        TreeMap<Integer, Integer> map = new TreeMap<>();
        int l = 0, r = 0, ans = n;
        while (l + d <= n) {
            while (r < l + d) {
                map.put(a[r], map.getOrDefault(a[r], 0) + 1);
                r++;
            }
            ans = min(ans, map.size());
            map.put(a[l], map.getOrDefault(a[l], 0) - 1);
            if (map.get(a[l]) == 0)
                map.remove(a[l]);
            l++;
        }
        out.println(ans);
    }
 
    private void solveC() throws IOException {
        long n = in.nextLong(), p = in.nextLong();
        for (int i = 1; i <= 1000; i++) {
            n -= p;
            if (n < 0)
                break;
 
            int cnt = 0;
            for (int c = 1; c <= n; c *= 2)
                if ((n & c) == c)
                    cnt++;
 
            if (i >= cnt && i <= n) {
                out.println(i);
                return;
            }
        }
        out.println(-1);
    }
 
    private void solveD() throws IOException {
        int n = in.nextInt(), k = in.nextInt();
        int[] a = in.nextIntArray(n);
 
        boolean[] isPrime = new boolean[(int) 1e5 + 1];
        fill(isPrime, true);
        ArrayList<Integer> primes = new ArrayList<>();
        for (int i = 2; i * i < isPrime.length; i++)
            if (isPrime[i]) {
                primes.add(i);
                for (int j = i * i; j < isPrime.length; j += i)
                    isPrime[j] = false;
            }
 
        TreeMap<ArrayList<Integer>, Integer> map = new TreeMap<>((o1, o2) -> {
            if (o1.size() != o2.size())
                return Integer.compare(o1.size(), o2.size());
            for (int i = 0; i < o1.size(); i++)
                if ((int) o1.get(i) != o2.get(i))
                    return Integer.compare(o1.get(i), o2.get(i));
            return 0;
        });
 
        long ans = 0;
        for (int i = 0; i < n; i++) {
            ArrayList<Integer> cur = new ArrayList<>();
            for (int p : primes) {
                if (a[i] % p == 0) {
                    int cnt = 0;
                    while (a[i] % p == 0) {
                        a[i] /= p;
                        cnt++;
                    }
                    cnt %= k;
                    if (cnt > 0) {
                        cur.add(p);
                        cur.add(cnt);
                    }
                }
            }
            if (a[i] > 1) {
                cur.add(a[i]);
                cur.add(1);
            }
            ans += map.getOrDefault(cur, 0);
            for (int j = 1; j < cur.size(); j += 2)
                cur.set(j, k - cur.get(j));
            map.put(cur, map.getOrDefault(cur, 0) + 1);
        }
        out.println(ans);
    }
 
    private void solveE() throws IOException {
        int mod = (int) 1e9 + 7;
        int n = in.nextInt(), m = in.nextInt();
        if (n == 1 && m == 1) {
            out.println(1);
            return;
        }
 
        int[][] map = new int[n][m];
        for (int i = 0; i < n; i++) {
            char[] s = in.next().toCharArray();
            for (int j = 0; j < m; j++) {
                map[i][j] = s[j] == 'R' ? 1 : 0;
            }
        }
 
        int[][] cntDown = new int[n][m];
        for (int j = 0; j < m; j++) {
            for (int i = n - 2; i >= 0; i--) {
                cntDown[i][j] = cntDown[i + 1][j] + map[i + 1][j];
            }
        }
 
        int[][] cntRight = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = m - 2; j >= 0; j--) {
                cntRight[i][j] = cntRight[i][j + 1] + map[i][j + 1];
            }
        }
 
        int[][][] dp = new int[2][n + 1][m + 1];
        dp[0][0][0] = dp[1][0][0] = 1;
        dp[0][0][1] = dp[1][1][0] = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i > 0) {
                    dp[1][i][j] += dp[1][i - 1][j];
                    if (dp[1][i][j] >= mod)
                        dp[1][i][j] -= mod;
                }
                if (j > 0) {
                    dp[0][i][j] += dp[0][i][j - 1];
                    if (dp[0][i][j] >= mod)
                        dp[0][i][j] -= mod;
                }
 
                dp[1][i + 1][j] += dp[0][i][j];
                if (dp[1][i + 1][j] >= mod)
                    dp[1][i + 1][j] -= mod;
                dp[1][n - cntDown[i][j]][j] -= dp[0][i][j];
                if (dp[1][n - cntDown[i][j]][j] < 0)
                    dp[1][n - cntDown[i][j]][j] += mod;
                dp[0][i][j + 1] += dp[1][i][j];
                if (dp[0][i][j + 1] >= mod)
                    dp[0][i][j + 1] -= mod;
                dp[0][i][m - cntRight[i][j]] -= dp[1][i][j];
                if (dp[0][i][m - cntRight[i][j]] < 0)
                    dp[0][i][m - cntRight[i][j]] += mod;
            }
        }
 
        out.println((dp[0][n - 1][m - 1] + dp[1][n - 1][m - 1]) % mod);
    }
 
    private void solveF() throws IOException {
 
    }
 
    void shuffleInt(int[] a) {
        Random random = new Random();
        for (int i = a.length - 1; i > 0; i--) {
            int j = random.nextInt(i + 1);
            int swap = a[j];
            a[j] = a[i];
            a[i] = swap;
        }
    }
 
    void shuffleLong(long[] a) {
        Random random = new Random();
        for (int i = a.length - 1; i > 0; i--) {
            int j = random.nextInt(i + 1);
            long swap = a[j];
            a[j] = a[i];
            a[i] = swap;
        }
    }
 
    void reverseInt(int[] a) {
        for (int i = 0, j = a.length - 1; i < j; i++, j--) {
            int swap = a[i];
            a[i] = a[j];
            a[j] = swap;
        }
    }
 
    void reverseLong(long[] a) {
        for (int i = 0, j = a.length - 1; i < j; i++, j--) {
            long swap = a[i];
            a[i] = a[j];
            a[j] = swap;
        }
    }
 
    int maxInt(int[] a) {
        int max = a[0];
        for (int i = 1; i < a.length; i++)
            if (max < a[i])
                max = a[i];
        return max;
    }
 
    long maxLong(long[] a) {
        long max = a[0];
        for (int i = 1; i < a.length; i++)
            if (max < a[i])
                max = a[i];
        return max;
    }
 
    int minInt(int[] a) {
        int min = a[0];
        for (int i = 1; i < a.length; i++)
            if (min > a[i])
                min = a[i];
        return min;
    }
 
    long minLong(long[] a) {
        long min = a[0];
        for (int i = 1; i < a.length; i++)
            if (min > a[i])
                min = a[i];
        return min;
    }
 
    long sumInt(int[] a) {
        long s = 0;
        for (int i = 0; i < a.length; i++)
            s += a[i];
        return s;
    }
 
    long sumLong(long[] a) {
        long s = 0;
        for (int i = 0; i < a.length; i++)
            s += a[i];
        return s;
    }
 
    long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
 
    long binpowmod(long a, long n) {
        long res = 1;
        a %= mod;
        n %= mod - 1;
        while (n > 0) {
            if (n % 2 == 1)
                res = (res * a) % mod;
            a = (a * a) % mod;
            n /= 2;
        }
        return res;
    }
 
    class GraphPair implements Comparable<GraphPair> {
        int v;
        long w;
 
        GraphPair(int v, long w) {
            this.v = v;
            this.w = w;
        }
 
        public int compareTo(GraphPair o) {
            return w != o.w ? Long.compare(w, o.w) : Integer.compare(v, o.v);
        }
    }
 
    ArrayList<Integer>[] createGraph(int n) throws IOException {
        ArrayList<Integer>[] graph = new ArrayList[n];
        for (int i = 0; i < n; i++)
            graph[i] = new ArrayList<>();
        return graph;
    }
 
    ArrayList<GraphPair>[] createWeightedGraph(int n) throws IOException {
        ArrayList<GraphPair>[] graph = new ArrayList[n];
        for (int i = 0; i < n; i++)
            graph[i] = new ArrayList<>();
        return graph;
    }
 
    class FastScanner {
        StringTokenizer st;
        BufferedReader br;
 
        FastScanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s), 32768);
        }
 
        String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }
 
        boolean hasNext() throws IOException {
            return br.ready() || (st != null && st.hasMoreTokens());
        }
 
        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
 
        int[] nextIntArray(int n) throws IOException {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = in.nextInt();
            return a;
        }
 
        int[][] nextIntTable(int n, int m) throws IOException {
            int[][] a = new int[n][m];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    a[i][j] = in.nextInt();
            return a;
        }
 
        long nextLong() throws IOException {
            return Long.parseLong(next());
        }
 
        long[] nextLongArray(int n) throws IOException {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = in.nextLong();
            return a;
        }
 
        long[][] nextLongTable(int n, int m) throws IOException {
            long[][] a = new long[n][m];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    a[i][j] = in.nextLong();
            return a;
        }
 
        ArrayList<Integer>[] nextGraph(int n, int m, boolean directed) throws IOException {
            ArrayList<Integer>[] graph = createGraph(n);
            for (int i = 0; i < m; i++) {
                int v = in.nextInt() - 1, u = in.nextInt() - 1;
                graph[v].add(u);
                if (!directed)
                    graph[u].add(v);
            }
            return graph;
        }
 
        ArrayList<GraphPair>[] nextWeightedGraph(int n, int m, boolean directed) throws IOException {
            ArrayList<GraphPair>[] graph = createWeightedGraph(n);
            for (int i = 0; i < m; i++) {
                int v = in.nextInt() - 1, u = in.nextInt() - 1;
                long w = in.nextLong();
                graph[v].add(new GraphPair(u, w));
                if (!directed)
                    graph[u].add(new GraphPair(v, w));
            }
            return graph;
        }
 
        double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
 
        String nextLine() throws IOException {
            return br.readLine();
        }
 
        boolean hasNextLine() throws IOException {
            return br.ready();
        }
 
    }
 
    private void run() throws IOException {
        in = new FastScanner(System.in); // new FastScanner(new FileInputStream(".in"));
        out = new PrintWriter(System.out); // new PrintWriter(new FileOutputStream(".out"));
 
        for (int t = multitests ? in.nextInt() : 1; t-- > 0; )
            solve();
 
        out.flush();
        out.close();
    }
 
    public static void main(String[] args) throws IOException {
        new Main().run();
    }
}