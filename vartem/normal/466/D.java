import java.io.*;
import java.util.*;

public class D {

    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt(), h = in.nextInt();
        int[] a = new int[n];
        
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        
        final int MOD = (int) (1e9 + 7);
        int[][] dp = new int[n + 1][h + 1];
        
        dp[0][0] = 1;
        
        for (int i = 0; i < n; i++) {
            for (int delta = 0; delta <= h; delta++) {
                if (dp[i][delta] == 0) {
                    continue;
                }
                
                for (int cntOpen = 0; cntOpen <= 1; cntOpen++) {
                    for (int cntClose = 0; cntClose <= 1; cntClose++) {
                        int cur = delta + cntOpen;
                        if (cur + a[i] != h) {
                            continue;
                        }
                        
                        int curOpen = delta + cntOpen;
                        int newDelta = curOpen - cntClose;
                        
                        if (0 <= newDelta && newDelta <= h) {
                            long mul = 1;
                            if (cntClose == 1) {
                                mul = curOpen;
                            }
                            
                            dp[i + 1][newDelta] = (int) ((dp[i + 1][newDelta] + mul * dp[i][delta]) % MOD);
                        }
                    }
                }
            }
        }
        
        out.println(dp[n][0]);
    }

    void run() {
        in = new FastScanner();
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastScanner(String s) {
            try {
                br = new BufferedReader(new FileReader(s));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String nextToken() {
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
            return Integer.parseInt(nextToken());
        }

        long nextLong() {
            return Long.parseLong(nextToken());
        }

        double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }

    public static void main(String[] args) {
        new D().run();
    }
}