import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt(), cl = in.nextInt(), ce = in.nextInt(), v = in.nextInt();

            int[] ladders = in.nextIntArray(cl);
            int[] elevators = in.nextIntArray(ce);

            int q = in.nextInt();
            for (int i = 0; i < q; i++) {
                int x1 = in.nextInt(), y1 = in.nextInt(), x2 = in.nextInt(), y2 = in.nextInt();

                int ans = getAns(cl, ladders, x1, y1, x2, y2, 1);
                ans = Math.min(ans, getAns(ce, elevators, x1, y1, x2, y2, v));
                out.println(ans);
            }
        }

        private int getAns(int cl, int[] ladders, int x1, int y1, int x2, int y2, int v) {
            if (x1 == x2) {
                return Math.abs(y1 - y2);
            }
            int pos = find(y1, ladders);
            int ans = Integer.MAX_VALUE;
            if (pos >= 0) {
                ans = Math.min(ans, use(ladders[pos], v, x1, y1, x2, y2));
            }
            if (pos + 1 < cl) {
                ans = Math.min(ans, use(ladders[pos + 1], v, x1, y1, x2, y2));
            }
            pos = find(y2, ladders);
            if (pos >= 0) {
                ans = Math.min(ans, use(ladders[pos], v, x1, y1, x2, y2));
            }
            if (pos + 1 < cl) {
                ans = Math.min(ans, use(ladders[pos + 1], v, x1, y1, x2, y2));
            }
            return ans;
        }

        private int find(int x1, int[] ladders) {
            int l = -1, r = ladders.length;
            while (l < r - 1) {
                int m = (l + r) / 2;
                if (ladders[m] < x1) {
                    l = m;
                } else {
                    r = m;
                }
            }
            return l;
        }

        private int use(int ladder, int i, int x1, int y1, int x2, int y2) {
            return Math.abs(y1 - ladder) + Math.abs(y2 - ladder) + (Math.abs(x1 - x2) + i - 1) / i;
        }

    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

        public int[] nextIntArray(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }

    }
}