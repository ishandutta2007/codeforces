import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        BAlenaIUzkiiHolodilnik solver = new BAlenaIUzkiiHolodilnik();
        solver.solve(1, in, out);
        out.close();
    }

    static class BAlenaIUzkiiHolodilnik {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt(), h = in.nextInt();
            int[] a = in.nextIntArray(n);

            int left = 0, right = n + 1;
            while (left < right - 1) {
                int mid = (left + right) / 2;
                int[] b = Arrays.copyOf(a, mid);

                Arrays.sort(b);
                Utils.reverse(b);
                long sum = 0;
                for (int i = 0; i < b.length; i += 2) {
                    sum += b[i];
                }
                if (sum <= h) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            out.println(left);
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

    static class Utils {
        public static void reverse(int[] a) {
            for (int i = 0, j = a.length - 1; i < j; i++, j--) {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }

    }
}