import java.io.*;
import java.util.*;

public class E {

    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int[] l = new int[n], r = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = in.nextInt();
            r[i] = in.nextInt();
        }
        
        boolean[][] dp = new boolean[n + 1][n  + 1];
        int[][] ins = new int[n][n];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i][j] = true;
            }
        }
        
        for (int len = 1; len <= n; len++) {
            for (int i = 0, j = len - 1; j < n; i++, j++) {
                for (int inside = 0; inside < len; inside++) {
                    int dist = 2 * inside + 1;
                    if (l[i] <= dist && dist <= r[i]) {
                        if (dp[i + 1][i + inside] && dp[i + inside + 1][j]) {
                            dp[i][j] = true;
                            ins[i][j] = inside;
                            break;
                        }
                    }
                }
            }
        }
        
        if (!dp[0][n - 1]) {
            out.println("IMPOSSIBLE");
            return;
        }
        
        restore(ins, 0, n - 1);
    }

    private void restore(int[][] ins, int i, int j) {
        if (i > j) {
            return;
        }
        out.print("(");
        restore(ins, i + 1, i + ins[i][j]);
        out.print(")");
        restore(ins, i + ins[i][j] + 1, j);
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
        new E().run();
    }
}