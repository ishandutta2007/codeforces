import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;
import java.util.ArrayList;

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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt(), q = in.nextInt();
            int[] l = new int[q], r = new int[q], x = new int[q];
            List<Integer>[] qs = Utils.listArray(n);
            for (int i = 0; i < q; i++) {
                l[i] = in.nextInt() - 1;
                r[i] = in.nextInt() - 1;
                x[i] = in.nextInt();
                qs[l[i]].add(i);
            }

            boolean[] can = new boolean[n + 1];
            int[] maxRight = new int[n + 1];
            Arrays.fill(maxRight, -1);
            maxRight[0] = n;
            for (int pos = 0; pos < n; pos++) {
                for (int query : qs[pos]) {
                    int right = r[query], val = x[query];

                    for (int i = n; i >= val; i--) {
                        int nval = Math.min(maxRight[i - val], right);
                        if (maxRight[i] < nval) {
                            maxRight[i] = nval;
                        }
                    }
                }
                for (int j = 1; j <= n; j++) {
                    if (maxRight[j] >= pos) {
                        can[j] = true;
                    }
                }
            }


            int count = 0;
            for (int i = 1; i <= n; i++) {
                if (can[i]) {
                    count++;
                }
            }
            out.println(count);
            for (int i = 1; i <= n; i++) {
                if (can[i]) {
                    out.print(i + " ");
                }
            }
            out.println();
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

    }

    static class Utils {
        public static <T> List<T>[] listArray(int size) {
            List<T>[] result = new List[size];
            for (int i = 0; i < size; i++) {
                result[i] = new ArrayList<>();
            }
            return result;
        }

    }
}