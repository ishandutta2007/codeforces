import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.FileReader;
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
        DSostavlenieRezyume solver = new DSostavlenieRezyume();
        solver.solve(1, in, out);
        out.close();
    }

    static class DSostavlenieRezyume {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();
            long k = in.nextLong();
            int[] a = in.nextIntArray(n);

            long left = (long) -4e18, right = (long) (4e18 + 1);
            while (left < right - 1) {
                long mid = (left + right) / 2;

                long take = 0;
                for (int i = 0; i < n; i++) {
                    if (a[i] <= mid) {
                        continue;
                    }
                    take += get(a[i], mid);
                }
                if (take > k) {
                    left = mid;
                } else {
                    right = mid;
                }
            }

            long rem = k;
            long[] b = new long[n];

            for (int i = 0; i < n; i++) {
                if (a[i] <= right) {
                    continue;
                }
                b[i] = get(a[i], right);
                rem -= b[i];
            }
            right--;
            for (int i = 0; i < n; i++) {
                if (a[i] <= right) {
                    continue;
                }
                long newTake = get(a[i], right);
                if (newTake > b[i] && rem > 0) {
                    if (newTake > b[i] + 1) {
                        throw new AssertionError();
                    }
                    rem--;
                    b[i] = newTake;
                }
            }
            for (long i : b) {
                out.print(i + " ");
            }
            out.println();
        }

        private long get(int ai, long mid) {
            if (1 + mid - ai > 0) {
                return 0;
            }
            double d = 9 - 12.0 * (1 + mid - ai);
            double res = (-3 + Math.sqrt(d)) / 6;
            long longRes = (long) res;
            while (3 * (longRes + 1) * (longRes + 2) + 1 + mid - ai <= 0) {
                longRes++;
            }
            while (longRes > 0 && 3 * (longRes + 1) * (longRes) + 1 + mid - ai > 0) {
                longRes--;
            }
            return Math.min(longRes, ai);
        }

    }

    static class FastScanner {
        public BufferedReader br;
        public StringTokenizer st;

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

        public int[] nextIntArray(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }

    }
}