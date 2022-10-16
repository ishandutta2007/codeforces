import java.io.*;
import java.util.*;

public class B {

    public void solve() {
        int n = in.nextInt();
        boolean[] used = new boolean[n];
        int[][] a = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = in.nextInt();
            }
        }

        int[] ans = new int[n];
        for (int num = 1; num <= n; num++) {
            for (int i = 0; i < n; i++) {
                if (!used[i]) {
                    boolean ok =true;
                    for (int j = 0; j < n; j++) {
                        if (j != i && !used[j] && a[i][j] != num) {
                            ok = false;
                        }
                    }
                    if (ok) {
                        ans[i] = num;
                        used[i] = true;
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            out.print(ans[i] + " ");
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
        new B().run();
    }
}