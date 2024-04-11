import java.io.*;
import java.util.*;

public class A {

    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int MAX = 200_000;
        int[] count = new int[MAX + 1];
        
        long[] dp = new long[MAX + 1];
        
        for (int i = 0; i < n; i++) {
            count[in.nextInt()]++;
        }
        
        dp[0] = 0;
        
        for (int i = 1; i <= MAX; i++) {
            dp[i] = dp[i - 1];
            if (i - 2 >= 0) {
                dp[i] = Math.max(dp[i], dp[i - 2] + 1L * count[i - 1] * (i - 1));
            }
        }
        
        out.println(dp[MAX]);
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

        FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (line == null)
                    return null;
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new A().run();
    }
}