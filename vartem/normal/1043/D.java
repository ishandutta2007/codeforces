import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            int[][] a = new int[m][];
            for (int i = 0; i < m; i++) {
                a[i] = in.nextIntArray(n);
            }

            int[] max = new int[n];
            for (int i = 0; i < n; i++) {
                max[i] = n - 1;
            }
            int[] pos1 = new int[n], pos2 = new int[n];
            for (int i = 1; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    pos1[a[0][j] - 1] = j;
                    pos2[a[i][j] - 1] = j;
                }

                for (int j = 0; j < n; ) {
                    int cur = pos2[a[0][j] - 1];
                    int k = 0;
                    while (j + k < n && pos2[a[0][j + k] - 1] == cur + k) {
                        k++;
                    }
                    int last = j + k - 1;
                    for (int t = 0; t < k; t++) {
                        max[j + t] = Math.min(max[j + t], last);
                    }
                    j = last + 1;
                }
            }
            long ans = 0;
            for (int i = 0; i < n; i++) {
                ans += Math.max(0, max[i] - i + 1);
            }
            out.println(ans);
        }

    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        public FastScanner(String fileName) {
            try {
                br = new BufferedReader(new FileReader(fileName));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
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