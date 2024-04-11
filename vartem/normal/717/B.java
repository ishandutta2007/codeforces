import java.io.*;
import java.util.*;

public class B {

    long n, c0, c1;

    public void solve() {
        n = in.nextInt() - 1;
        c0 = in.nextInt();
        c1 = in.nextInt();
        if (c0 > c1) {
            long tmp = c0;
            c0 = c1;
            c1 = tmp;
        }

        if (c0 == 0) {
            out.println(1L * n * (c0 + c1));
            return;
        }

        long left = 0, right = (long) 5e17;

        while (left < right - 1) {
            long mid = (left + right) >>> 1;

            long[] calc = calc(mid);
            if (calc[0] < n) {
                left = mid;
            } else {
                right = mid;
            }
        }
        System.err.println(left);
        long[] calc2 = calc(left);

        long result = calc2[1] + (n - calc2[0]) * (left + 1);
        result += 1L * n * (c0 + c1);
        out.println(result);
    }

    long[] calc(long x) {
        long count = 0, sum = 0;
        for (long j = 0; c1 * j <= x; j++) {
            long maxI = (x - c1 * j) / c0;
            if (j == 0) {
                count += (maxI + 1);
                sum += c0 * maxI * (maxI + 1) / 2;
            } else {
                long curChoose = 1;
                for (long i = 0; i * c0 + j * c1 <= x; i++) {
                    if (i > 0) {
                        curChoose *= (i + j);
                        curChoose /= i;
                    }
                    count += curChoose;
                    sum += curChoose * (i * c0 + j * c1);
                    if (count >= n) {
                        return new long[]{count, sum};
                    }
                }
            }
        }
        return new long[]{count, sum};
    }

    public void run() {
        in = new FastScanner();
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    FastScanner in;
    PrintWriter out;

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(String fileName) {
            try {
                br = new BufferedReader(new FileReader(fileName));
            } catch (FileNotFoundException e) {
            }
        }

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(nextToken());
        }

        long nextLong() {
            return Long.parseLong(nextToken());
        }

        double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }

    public static void main(String[] args) {
        new B().run();
    }
}