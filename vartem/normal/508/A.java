import java.io.*;
import java.util.*;

public class A {

    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt(), m = in.nextInt(), k = in.nextInt();
        boolean[][] a = new boolean[n][m];

        for (int i = 0; i < k; i++) {
            int r = in.nextInt() - 1, c = in.nextInt() - 1;
            a[r][c] = true;

            boolean ok = false;
            for (int r1 = Math.max(0, r - 1); r1 <= r; r1++) {
                for (int c1 = Math.max(0, c - 1); c1 <= c; c1++) {
                    if (r1 + 2 <= n && c1 + 2 <= m) {
                        ok |= a[r1][c1] & a[r1 + 1][c1] & a[r1 + 1][c1 + 1] & a[r1][c1 + 1];
                    }
                }
            }
            if (ok) {
                out.println(i + 1);
                return;
            }
        }

        out.println(0);
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
        new A().run();
    }
}