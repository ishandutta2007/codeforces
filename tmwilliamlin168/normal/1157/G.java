// package cf1157;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.InputMismatchException;

public class CFG {
    private static final String INPUT = "3 3\n" +
            "0 0 0\n" +
            "1 0 1\n" +
            "1 1 0\n";
    private static final int MOD = 1_000_000_007;

    private PrintWriter out;
    private FastScanner sc;

    public static void main(String[] args) {
        new CFG().run();
    }

    public void run() {
        sc = new FastScanner(oj ? System.in : new ByteArrayInputStream(INPUT.getBytes()));
        out = new PrintWriter(System.out);

        long s = System.currentTimeMillis();
        solve();
        out.flush();
        tr(System.currentTimeMillis() - s + "ms");
    }

    public void solve() {
        int n = sc.nextInt();
        int m = sc.nextInt();
        boolean[][] a = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = sc.nextInt() == 1;
            }
        }

        for (int M = 0; M < 2; M++) {
            for (int L = 0; L <= m; L++) { //zeros
                int[] ans1 = new int[n];
                int[] ans2 = new int[m];
                boolean cur = L != m;
                boolean[][] ca = Arrays.stream(a).map(line -> line.clone()).toArray(it -> a.clone());
                if (M == 1) {
                    ans1[0] = 1;
                    for (int j = 0; j < m; j++) {
                        ca[0][j] = !ca[0][j];
                    }
                }
                for (int i = 0; i < m; i++) {
                    if (i < L == ca[0][i]) {
                        ans2[i] = 1;
                        for (int j = 0; j < n; j++) {
                            ca[j][i] = !ca[j][i];
                        }
                    }
                }

                for (int i = 1; i < n; i++) {
                    if (cur == !ca[i][0]) {
                        ans1[i] = 1;
                        for (int j = 0; j < m; j++) {
                            cur |= ca[i][j] = !ca[i][j];
                        }
                    }
                }
                if (ok(ca)) {
                    System.out.println("YES");
                    for (int i : ans1) System.out.print(i);
                    System.out.println();
                    for (int i : ans2) System.out.print(i);
                    System.out.println();
                    return;
                }
            }
        }

        System.out.println("NO");
    }

    boolean ok(boolean[][] a) {
        boolean prev = false;
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[i].length; j++) {
                if (!a[i][j] && prev) return false;
                prev = a[i][j];
            }
        }
        return true;
    }

    //********************************************************************************************
    //********************************************************************************************
    //********************************************************************************************

    /**
     * If searched element doesn't exist, returns index of first element which is bigger than searched value.<br>
     * If searched element is bigger than any array element function returns first index after last element.<br>
     * If searched element is lower than any array element function returns index of first element.<br>
     * If there are many values equals searched value function returns first occurrence.<br>
     */
    private static int lowerBound(long[] arr, long key) {
        int lo = 0;
        int hi = arr.length - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (key <= arr[mid]) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return arr[lo] < key ? lo + 1 : lo;
    }

    /**
     * Returns index of first element which is grater than searched value.
     * If searched element is bigger than any array element, returns first index after last element.
     */
    private static int upperBound(long[] arr, long key) {
        int lo = 0;
        int hi = arr.length - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (key >= arr[mid]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return arr[lo] <= key ? lo + 1 : lo;
    }

    private static int ceil(double d) {
        int ret = (int) d;
        return ret == d ? ret : ret + 1;
    }

    private static int round(double d) {
        return (int) (d + 0.5);
    }

    private static int gcd(int a, int b) {
        BigInteger b1 = BigInteger.valueOf(a);
        BigInteger b2 = BigInteger.valueOf(b);
        BigInteger gcd = b1.gcd(b2);
        return gcd.intValue();
    }

    private static long gcd(long a, long b) {
        BigInteger b1 = BigInteger.valueOf(a);
        BigInteger b2 = BigInteger.valueOf(b);
        BigInteger gcd = b1.gcd(b2);
        return gcd.longValue();
    }

    private int[] readIntArray(int n) {
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = sc.nextInt();
        }
        return res;
    }

    private long[] readLongArray(int n) {
        long[] res = new long[n];
        for (int i = 0; i < n; i++) {
            res[i] = sc.nextLong();
        }
        return res;
    }

    @SuppressWarnings("unused")
    static class FastScanner {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        FastScanner(InputStream stream) {
            this.stream = stream;
        }

        int read() {
            if (numChars == -1)
                throw new InputMismatchException();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) return -1;
            }
            return buf[curChar++];
        }

        boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        boolean isEndline(int c) {
            return c == '\n' || c == '\r' || c == -1;
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public String next() {
            int c = read();
            while (isSpaceChar(c)) c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public String nextLine() {
            int c = read();
            while (isEndline(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isEndline(c));
            return res.toString();
        }

    }

    private boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    private void tr(Object... o) {
        if (!oj) System.out.println(Arrays.deepToString(o));
    }
}