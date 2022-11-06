import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    
    static PrintWriter out;
    
    static double EPS = 1e-9;
    static int INF = (int) 1e9;
    static long LINF = (long) 1e18;
    static int MOD = (int) 1e9 + 7;
    static double PI = 2 * Math.acos(0);
    
    static void solve() {
        int n = Input.nextInt();
        int k = Input.nextInt();
        int[][] a = new int[k][n];
        int[][] b = new int[k][n];
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = Input.nextInt() - 1;
                b[i][a[i][j]] = j;
            }
        }
        int[][] f = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                f[i][j] = 1;
                for (int l = 0; l < k; l++) {
                    if (b[l][a[0][j]] < b[l][a[0][i]]) {
                        f[i][j] = 0;
                        break;
                    }
                }
            }
        }
        int[] d = new int[n];
        d[n - 1] = 1;
        int ans = 1;
        for (int i = n - 2; i >= 0; i--) {
            d[i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (f[i][j] == 1) {
                    d[i] = Math.max(d[i], d[j] + 1);
                }
            }
            ans = Math.max(ans, d[i]);
        }
        out.print(ans);
    }
    
    public static void main(String[] args) {
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }
    
    static class SegmentTree {
        int maxn = 100010;
        long[] st = new long[4 * maxn];
        void update(int node, int i, int L, int R, long val) {
            if (i < L || i > R) return;
            if (L == R) {st[node] += val; return;}
            update(node << 1, i, L, (L + R) >> 1, val);
            update((node << 1) + 1, i, ((L + R) >> 1) + 1, R, val);
            st[node] = st[node << 1] + st[(node << 1) + 1];
        }
        
        long query(int node, int l, int r, int L, int R) {
            if (l > R || r < L) return 0;
            if (l <= L && r >= R) return st[node];
            return query(node << 1, l, r, L, (L + R) >> 1) + query((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R);
        }
    }
    
    static class Matrix {
        int maxn = 2;
        int[][] x = new int[maxn][maxn];
        Matrix mul(Matrix A) {
            Matrix res = new Matrix();
            for (int i = 0; i < maxn; i++) {
                for (int k = 0; k < maxn; k++) {
                    for (int j = 0; j < maxn; j++) {
                        res.x[i][j] = (int) ((res.x[i][j] + (long) x[i][k] * A.x[k][j]) % MOD);
                    }
                }
            }
            return res;
        }
        Matrix pow(long k) {
            Matrix res = this, T = this; k--;
            while (k > 0) {
                if ((k & 1) > 0) {
                    res = res.mul(T);
                }
                T = T.mul(T); k >>= 1;
            }
            return res;
        }
    }
    
    static class Pair implements Comparable<Pair> {
        int fi, se;
        Pair(int fi, int se) {
            this.fi = fi;
            this.se = se;
        }
        public int compareTo(Pair oth) {
            if (fi > oth.fi) return +1;
            if (fi < oth.fi) return -1;
            if (se > oth.se) return +1;
            if (se < oth.se) return -1;
            return 0;
        }
    }
    
    static long gcd(long a, long b) {
        long r;
        while (b != 0) {
            r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
    
    static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }
    
    static long fpow(long n, long k, int p) {
        long r = 1;
        for (; k > 0; k >>= 1) {
            if (k % 2 == 1) {
                r = r * n % p;
            }
            n = n * n % p;
        }
        return r;
    }
    
    static class Input {
        static StringTokenizer token = null;
        static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
//      static BufferedReader in;
//      static {
//          try {
//              in = new BufferedReader(new FileReader("in.txt"));
//          } catch (IOException e) {
//          }
//      }

        static int nextInt() {
            return Integer.parseInt(nextString());
        }

        static long nextLong() {
            return Long.parseLong(nextString());
        }

        static double nextDouble() {
            return Double.parseDouble(nextString());
        }

        static String nextString() {
            try {
                while (token == null || !token.hasMoreTokens()) {
                    token = new StringTokenizer(in.readLine());
                }
            } catch (IOException e) {
            }
            return token.nextToken();
        }
    }
}