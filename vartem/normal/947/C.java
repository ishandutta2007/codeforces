import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        int MAX = 30 * 300_000 + 1;
        int[][] next = new int[2][MAX];
        int[] count = new int[MAX];
        int states = 1;

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.nextIntArray(n);
            int[] p = in.nextIntArray(n);

            for (int[] i : next) {
                Arrays.fill(i, -1);
            }
            for (int i = 0; i < n; i++) {
                int cur = 0;
                count[cur]++;
                for (int bit = 29; bit >= 0; bit--) {
                    int c = (p[i] >> bit) & 1;
                    if (next[c][cur] == -1) {
                        next[c][cur] = states++;
                    }
                    cur = next[c][cur];
                    count[cur]++;
                }
            }

            for (int i = 0; i < n; i++) {
                int cur = 0;
                int value = 0;
                count[cur]--;
                for (int bit = 29; bit >= 0; bit--) {
                    int c = (a[i] >> bit) & 1;
                    if (next[c][cur] != -1 && count[next[c][cur]] > 0) {
                    } else {
                        c ^= 1;
                    }
                    cur = next[c][cur];
                    count[cur]--;
                    value = (value << 1) | c;
                }
                out.print((a[i] ^ value));
                out.print(' ');
            }
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