import java.io.*;
import java.util.*;

public class B {

    public void solve() {
        long a00 = in.nextInt(), a01 = in.nextInt(), a10 = in.nextInt(), a11 = in.nextInt();

        long[] cs0 = getN(a00), cs1 = getN(a11);

        for (long c0 : cs0) {
            for (long c1 : cs1) {
                if (possible(c0, c1, a01, a10)) {
                    char[] result = new char[(int) (c0 + c1)];

                    int pos = 0;
                    while (a10 > c0) {
                        result[pos++] = '1';
                        a10 -= c0;
                        c1--;
                    }

                    for (int i = 0; i < c0 - a10; i++) {
                        result[pos++] = '0';
                    }
                    if (c1 > 0) {
                        result[pos++] = '1';
                        c1--;
                    }
                    for (int i = 0; i < a10; i++) {
                        result[pos++] = '0';
                    }
                    while (c1 > 0) {
                        result[pos++] = '1';
                        c1--;
                    }
                    out.println(new String(result));

                    return;
                }
            }
        }
        fail();
    }

    private boolean possible(long c0, long c1, long a01, long a10) {
        if (c0 < 0 || c1 < 0 || a01 < 0 || a10 < 0) {
            return false;
        }
        if (c0 + c1 <= 0) {
            return false;
        }
        long n = c0 + c1;
        long all = n * (n - 1) / 2;
        all -= c0 * (c0 - 1) / 2;
        all -= c1 * (c1 - 1) / 2;
        if (a01 + a10 != all) {
            return false;
        }
        if (a01 > c0 * c1 || a10 > c0 * c1) {
            return false;
        }
        return true;
    }

    void print(char c, long n) {
        for (int i = 0; i < n; i++) {
            out.print(c);
        }
    }

    private void fail() {
        out.println("Impossible");
        return;
    }

    long[] getN(long x) {
        if (x == 0) {
            return new long[]{0, 1};
        }
        long n = 0;
        while (n * (n - 1) / 2 < x) {
            n++;
        }
        if (n * (n - 1) / 2 == x) {
            return new long[]{n};
        }
        return new long[0];
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