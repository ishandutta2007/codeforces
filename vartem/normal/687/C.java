import java.io.*;
import java.util.*;

public class C {

    public void solve() {
        int n = in.nextInt(), k = in.nextInt();
        int[] c = new int[n];
        for (int i = 0; i < n; i++) {
            c[i] = in.nextInt();
        }

        boolean[][] dp = new boolean[k + 1][k + 1];
        boolean[][] newDp = new boolean[k + 1][k + 1];
        dp[0][0] = true;

        for (int val : c) {

            for (int i = 0; i <= k; i++) {
                for (int j = 0; j <= k; j++) {
                    if (dp[i][j]) {
                        newDp[i][j] = true;
                        if (i + val <= k) {
                            newDp[i + val][j] = newDp[i + val][j + val] = true;
                        }
                    }
                }
            }


            for (int i = 0; i <= k; i++ ){
                for (int j = 0; j <= k; j++) {
                    dp[i][j] = newDp[i][j];
                    newDp[i][j] = false;
                }
            }
        }

        List<Integer> result = new ArrayList<>();
        for (int i = 0; i <= k; i++) {
            if (dp[k][i]) {
                result.add(i);
            }
        }
        out.println(result.size());
        for (int i : result) {
            out.print(i + " ");
        }
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