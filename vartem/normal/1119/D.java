import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Comparator;
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
        DFretsOnFire solver = new DFretsOnFire();
        solver.solve(1, in, out);
        out.close();
    }

    static class DFretsOnFire {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();
            long[] s = in.nextLongArray(n);
            Arrays.sort(s);
            int q = in.nextInt();
            Query[] qs = new Query[q];
            for (int i = 0; i < q; i++) {
                qs[i] = new Query(-in.nextLong() + in.nextLong() + 1, i);
            }
            Arrays.sort(qs, Comparator.comparingLong(t -> t.a));
            long[] ans = new long[q];
            long[] diff = new long[n - 1];
            for (int i = 0; i < n - 1; i++) {
                diff[i] = s[i + 1] - s[i];
            }
            Arrays.sort(diff);

            int j = 0;
            long sum = 0;
            for (int i = 0; i < q; i++) {
                long cur = qs[i].a;
                while (j < diff.length && diff[j] <= cur) {
                    sum += diff[j];
                    j++;
                }
                ans[qs[i].pos] = sum + (n - j) * cur;
            }


            for (int i = 0; i < q; i++) {
                out.println(ans[i]);
            }
        }

        class Query {
            long a;
            int pos;

            public Query(long a, int pos) {
                this.a = a;
                this.pos = pos;
            }

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

        public long nextLong() {
            return Long.parseLong(next());
        }

        public long[] nextLongArray(int n) {
            long[] ret = new long[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextLong();
            }
            return ret;
        }

    }
}