import java.io.*;
import java.util.*;

public class B {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt(), m = in.nextInt(), q = in.nextInt();
        int[][] a = new int[n][m];
        int[] t = new int[q];
        int[] r = new int[q], c = new int[q], val =new int[q];
        for (int i = 0; i < q; i++) {
            t[i] = in.nextInt();
            if (t[i] == 3) {
                r[i] = in.nextInt() - 1;
                c[i] = in.nextInt() - 1;
                val[i] = in.nextInt();
            } else {
                val[i] = in.nextInt() - 1;
            }
        }

        for (int i = q - 1; i >= 0; i--) {
            if (t[i] == 3) {
                a[r[i]][c[i]] = val[i];
            } else if (t[i] == 2) {
                int tmp = a[n - 1][val[i]];
                for (int j = n - 1; j > 0; j--) {
                    a[j][val[i]] = a[j - 1][val[i]];
                }
                a[0][val[i]] = tmp;
            } else {
                int tmp = a[val[i]][m - 1];
                for (int j = m - 1; j > 0; j--) {
                    a[val[i]][j] = a[val[i]][j - 1];
                }
                a[val[i]][0] = tmp;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                out.print(a[i][j] + " ");
            }
            out.println();
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
        new B().runIO();
    }
}