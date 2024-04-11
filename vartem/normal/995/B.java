import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.nextIntArray(2 * n);
            int ans = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    List<Integer> pos1 = new ArrayList<>(), pos2 = new ArrayList<>();
                    for (int k = 0; k < a.length; k++) {
                        if (a[k] == i + 1) {
                            pos1.add(k);
                        }
                        if (a[k] == j + 1) {
                            pos2.add(k);
                        }
                    }

                    if (pos1.get(1) < pos2.get(0) || pos2.get(1) < pos1.get(0)) {
                        ans += 0;
                    } else if (Math.min(pos1.get(1), pos2.get(1)) - Math.max(pos1.get(0), pos2.get(0)) == Math.min(pos1.get(1) - pos1.get(0), pos2.get(1) - pos2.get(0))) {
                        ans += 2;
                    } else {
                        ans += 1;
                    }
                }
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