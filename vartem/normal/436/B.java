import java.io.*;
import java.util.*;

public class B {

    public void solve() {
        int n = in.nextInt(), m = in.nextInt(), k = in.nextInt();
        char[][] field = new char[n][];
        for (int i = 0; i < n; i++) {
            field[i] = in.nextToken().toCharArray();
        }

        int[] ans = new int[m];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (field[i][j] == '.') {
                    continue;
                }

                if (field[i][j] == 'D') {
                    continue;
                }

                if (field[i][j] == 'U') {
                    if (i % 2 == 0) {
                        ans[j]++;
                    }
                }

                if (field[i][j] == 'R') {
                    if (i + j < m) {
                        ans[i + j]++;
                    }
                }
                if (field[i][j] == 'L') {
                    if (j - i >= 0) {
                        ans[j - i]++;
                    }
                }
            }
        }

        for (int i = 0; i < m; i++) {
            out.print(ans[i] + " ");
        }
        out.println();
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
        new B().run();
    }
}