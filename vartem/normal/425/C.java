import java.io.*;
import java.util.*;

public class C {

    final int MAX = 100_000 + 1;

    public void solve() {
        int n = in.nextInt(), m = in.nextInt(), s = in.nextInt(), e = in.nextInt();
        int[] a = new int[n], b = new int[m];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        for (int j = 0; j < m; j++) {
            b[j] = in.nextInt();
        }

        int canRemove = s / e;

        final int INF = Integer.MAX_VALUE / 2;
        int[] dp = new int[canRemove + 1];
        Arrays.fill(dp, INF);
        dp[0] = 0;

        int[] count = new int[MAX];
        for (int i = 0; i < m; i++) {
            count[b[i]]++;
        }

        int[][] occs = new int[MAX][];
        for (int i = 0; i < MAX; i++) {
            occs[i] = new int[count[i]];
        }

        Arrays.fill(count, 0);
        for (int i = 0; i < m; i++) {
            occs[b[i]][count[b[i]]++] = i;
        }

        int best = 0;
        for (int i = 0; i < n; i++) {
            int[] occ = occs[a[i]];
            for (int j = dp.length - 2; j >= 0; j--) {
                if (dp[j] == INF) {
                    continue;
                }
                int pos = dp[j];
                
                int left = -1, right = occ.length;
                while (left < right - 1) {
                    int mid = (left + right) >> 1;
                    if (occ[mid] >= pos) {
                        right = mid;
                    } else {
                        left = mid;
                    }
                }
                if (right < occ.length) {
                    dp[j + 1] = Math.min(dp[j + 1], occ[right] + 1);
                }
            }

            for (int j = 0; j < dp.length; j++) {
                if ((i + 1) + dp[j] + j * e <= s) {
                    best = Math.max(best, j);
                }
            }
        }

        out.println(best);
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
        new C().run();
    }
}