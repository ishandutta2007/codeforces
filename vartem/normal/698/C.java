import java.io.*;
import java.util.*;

public class C {

    public void solve() {
        int n = in.nextInt(), k = in.nextInt();
        int nonZero = 0;
        double[] p = new double[n];
        for (int i = 0; i < n; i++) {
            p[i] = in.nextDouble();
            nonZero += p[i] > 0 ? 1 : 0;
        }
        k = Math.min(k, nonZero);

        double[] dp = new double[1 << n];
        dp[0] = 1;
        for (int mask = 0; mask < 1 << n; mask++) {
            double loopP = 0;

            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) != 0) {
                    loopP += p[i];
                }
            }
            if (loopP == 1) {
                continue;
            }

            for (int i =0 ; i < n; i++) {
                if ((mask & (1 << i)) == 0) {
                    dp[mask | (1 << i)] += p[i] * dp[mask] / (1 - loopP);
                }
            }
        }

        double[] result = new double[n];
        for (int mask = 0; mask < 1 << n; mask++) {
            if (Integer.bitCount(mask) == k) {
                for (int i = 0; i < n; i++) {
                    if ((mask & (1 << i)) != 0) {
                        result[i] += dp[mask];
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            out.print(result[i] + " ");
        }
        out.println();
    }

    public void run() {
        in = new FastScanner();
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    FastScanner in;
    PrintWriter out;

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(String fileName) {
            try {
                br = new BufferedReader(new FileReader(fileName));
            } catch (FileNotFoundException e) {
            }
        }

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
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
        new C().run();
    }
}