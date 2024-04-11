import java.io.*;
import java.util.*;

public class D {

    final int MOD = 1_000_000_007;
    final int MAX = 10000;
    
    int[] count1 = new int[2 * MAX + 1], count2 = new int[2 * MAX + 1];
    int[] dp1 = new int[2 * MAX + 1], dp2 = new int[2 * MAX + 1];
    int[] a;
    
    int solve(int l, int r) {
        if (l >= r) {
            return 0;
        }
        int m = (l + r) >> 1;
        int ans = (solve(l, m) + solve(m + 1, r)) % MOD;
        
        doDp(m, l - 1, -1, count1);
        doDp(m + 1, r + 1, 1, count2);
        for (int i = -MAX; i <= MAX; i++) {
            ans += (1L * count1[MAX - i] * count2[MAX + i]) % MOD;
            if (ans >= MOD) {
                ans -= MOD;
            }
        }
        return ans;
    }
    
    private void doDp(int l, int r, int dir, int[] res) {
        Arrays.fill(res, 0);
        int sum = 0;
        Arrays.fill(dp1, MAX - sum, MAX + sum + 1, 0);
        dp1[MAX] = 1;
        for (int i = l; i != r; i += dir) {
            Arrays.fill(dp2, MAX - sum - a[i], MAX + sum + a[i] + 1, 0);
            for (int j = -sum + MAX; j <= sum + MAX; j++) {
                if (dp1[j] != 0) {
                    if ((dp2[j - a[i]] += dp1[j]) >= MOD) {
                        dp2[j - a[i]] -= MOD;
                    }
                    if ((dp2[j + a[i]] += dp1[j]) >= MOD) {
                        dp2[j + a[i]] -= MOD;
                    }
                }
            }
            sum += a[i];
            System.arraycopy(dp2, MAX - sum, dp1, MAX - sum, 2 * sum + 1);
            for (int j = MAX - sum; j <= MAX + sum; j++) {
                if ((res[j] += dp1[j]) >= MOD) {
                    res[j] -= MOD;
                }
            }
        }
    }

    public void solve() {
        int n = in.nextInt();
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        
        out.println(solve(0, n - 1));
    }

    FastScanner in;
    PrintWriter out;

    public void run() {
        try {
            in = new FastScanner();
            out = new PrintWriter(System.out);
            solve();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastScanner(String name) {
            try {
                br = new BufferedReader(new FileReader(name));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextToken());
        }

        public long nextLong() {
            return Long.parseLong(nextToken());
        }

        public double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }

    public static void main(String[] args) {
        new D().run();
    }
}