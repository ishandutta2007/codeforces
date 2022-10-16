import java.io.*;
import java.util.*;

public class SkiBases {

    class Edge {
        int x, y;

        public Edge(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    int[] p;
    int[] cnt;
    int[] r;

    int get(int x) {
        if (p[x] == x)
            return x;
        int t = get(p[x]);
        p[x] = t;
        return p[x];
    }

    void union(int t1, int t2) {
        if (r[t1] == r[t2]) {
            r[t1]++;
        }
        if (r[t1] > r[t2]) {
            p[t2] = t1;
            cnt[t1] += cnt[t2];
        } else {
            p[t1] = t2;
            cnt[t2] += cnt[t1];
        }
    }

    final int modulo = 1000000009;

    int rev(long x) {
        int n = modulo - 2;
        long res = 1;
        while (n > 0) {
            if (n % 2 == 1)
                res = (res * x) % modulo;
            res = (res * res) % modulo;
            n /= 2;
        }
        return (int) (res % modulo);
    }
    
    long f(long a) {
        return ((a % modulo) * ((a + modulo - 1) % modulo) * rev(2)) % modulo;
    }

    void solve() throws Exception {
        int n = nextInt();
        int m = nextInt();
        p = new int[n];
        cnt = new int[n];
        r = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
        long ans = 1;
        for (int i = 0; i < m; i++) {
            int x = nextInt() - 1;
            int y = nextInt() - 1;
            int t1 = get(x);
            int t2 = get(y);
            if (t1 == t2) {
                cnt[t1]++;
                ans = (ans * 2) % modulo;
            } else
                union(t1, t2);
            out.println((ans + modulo - 1) % modulo);
        }
    }

    void run() {
        try {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
            // in = new BufferedReader(new FileReader(filename + ".in"));
            // out = new PrintWriter(filename + ".out");

            solve();

            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    BufferedReader in;
    StringTokenizer st;
    PrintWriter out;
    final String filename = new String("SkiBases").toLowerCase();

    String nextToken() throws Exception {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(in.readLine());
        return st.nextToken();
    }

    int nextInt() throws Exception {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws Exception {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws Exception {
        return Double.parseDouble(nextToken());
    }

    public static void main(String[] args) {
        new SkiBases().run();
    }

}