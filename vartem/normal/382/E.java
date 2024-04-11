import java.io.*;
import java.util.*;

public class EWA {

    final long MOD = 1_000_000_007;

    public void solve() {
        int n = in.nextInt(), k = in.nextInt();
        if (k * 2 > n) {
            out.println(0);
            return;
        }
        long[][] dp1 = new long[n + 1][k + 1], dp2 = new long[n + 1][k + 1];
        dp1[1][0] = 1;
        
        long[][] choose = new long[n + 1][n + 1];
        choose[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            choose[i][0] = 1;
            for (int j = 1; j <= n; j++) {
                choose[i][j] = (choose[i - 1][j - 1] + choose[i - 1][j]) % MOD;
            }
        }
        
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= k; j++) {

                // 1 child
                dp1[i][j] += dp2[i - 1][j] * (i - 1);
                dp1[i][j] %= MOD;
                if (j > 0) {
                    dp2[i][j] += dp1[i - 1][j - 1] * (i - 1);
                    dp2[i][j] %= MOD;
                }

                // 2 children
                for (int size1 = 1; size1 < (i - 1) - size1; size1++) {
                    for (int match1 = 0; match1 <= j; match1++) {
                        long add = dp2[size1][match1] * dp2[i - 1 - size1][j - match1] % MOD;
                        dp1[i][j] += (add * choose[i - 1][size1]) % MOD * size1 * (i - 1 - size1);
                        dp1[i][j] %= MOD;
                    }
                }
                for (int size1 = 1; size1 < (i - 1) - size1; size1++) {
                    for (int match1 = 0; match1 <= j - 1; match1++) {
                        long add = (dp1[size1][match1] * dp1[i - 1 - size1][j - 1 - match1]
                                + dp1[size1][match1] * dp2[i - 1 - size1][j - 1 - match1]
                                + dp2[size1][match1] * dp1[i - 1 - size1][j - 1 - match1]) % MOD;
                        dp2[i][j] += (add * choose[i - 1][size1]) % MOD * size1 * (i - 1 - size1);
                        dp2[i][j] %= MOD;
                    }
                }
                
                // 2 children of equal size
                if ((i - 1) % 2 == 0) {
                    int size1 = (i - 1) / 2;
                    
                    for (int match1 = 0; match1 < j - match1; match1++ ){
                        long add = dp2[size1][match1] * dp2[size1][j - match1] % MOD;
                        dp1[i][j] += (add * choose[i - 1][size1]) % MOD * size1 * (i - 1 - size1);
                        dp1[i][j] %= MOD;
                    }
                    if (j % 2 == 0) {
                        int match1 = j / 2;
                        long add = (dp2[size1][match1] * (dp2[size1][match1] - 1) / 2) % MOD;
                        dp1[i][j] += (add * choose[i - 1][size1]) % MOD * size1 * (i - 1 - size1);
                        dp1[i][j] %= MOD;
                        
                        add = dp2[size1][match1];
                        add = (add * (i - 1) * (i - 2) / 2) % MOD;
                        add = (add * choose[i - 3][size1 - 1]) % MOD;
                        dp1[i][j] += add;
                        dp1[i][j] %= MOD;
                    }
                    
                    for (int match1 = 0; match1 < j - 1 - match1; match1++) {
                        long add = (dp1[size1][match1] * dp1[size1][j - 1 - match1]
                                + dp1[size1][match1] * dp2[size1][j - 1 - match1]
                                + dp2[size1][match1] * dp1[size1][j - 1 - match1]) % MOD;
                        dp2[i][j] += (add * choose[i - 1][size1]) % MOD * size1 * (i - 1 - size1);
                        dp2[i][j] %= MOD;
                    }
                    
                    if ((j - 1) % 2 == 0) {
                        int match1 = (j - 1) / 2;
                        long add = (dp1[size1][match1] * dp2[size1][match1]) % MOD;
                        dp2[i][j] += (add * choose[i - 1][size1]) % MOD * size1 * (i - 1 - size1);
                        dp2[i][j] %= MOD;
                        
                        add = (dp1[size1][match1] * (dp1[size1][match1] - 1) / 2) % MOD;
                        dp2[i][j] += (add * choose[i - 1][size1]) % MOD * size1 * (i - 1 - size1);
                        dp2[i][j] %= MOD;
                        
                        add = dp1[size1][match1];
                        add = (add * (i - 1) * (i - 2) / 2) % MOD;
                        add = (add * choose[i - 3][size1 - 1]) % MOD;
                        dp2[i][j] += add;
                        dp2[i][j] %= MOD;
                    }
                }
            }
        }

        out.println((dp1[n][k] + dp2[n][k]) % MOD);
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
        new EWA().run();
    }
}