import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt(), a = in.nextInt(), b = in.nextInt();
        int[][] ans = new int[a][b];
        int[] cnt = new int[]{(n + 1) / 2, n / 2};
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                int oddity = (i + j) % 2;
                if (cnt[oddity] > 0) {
                    ans[i][j] = 2 * cnt[oddity] + oddity - 1;
                    cnt[oddity]--;
                }
            }
        }
        if (cnt[0] + cnt[1] > 0) {
            out.println("-1");
        } else {
            for (int i = 0; i < a; i++) {
                for (int j = 0; j < b; j++) {
                    out.print(ans[i][j] + " ");
                }
                out.println();
            }
        }
    }

    void runIO() {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
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
        new A().runIO();
    }
}