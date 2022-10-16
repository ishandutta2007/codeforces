import java.io.*;
import java.util.*;

public class B {

    void solve() {
        int n = in.nextInt();
        long[] mask = in.nextLongArray(n);
        int[] a = in.nextIntArray(n);

        boolean[] taken = new boolean[n];
        Arrays.fill(taken, true);
        int[] deg = new int[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((mask[i] & (~mask[j])) != 0) {
                    deg[i]++;
                }
            }
        }
        int size = n;
        while (true) {
            int rem = -1;
            for (int i = 0; i < n; i++) {
                if (taken[i] && (deg[i] == size - 1)) {
                    rem = i;
                    break;
                }
            }
            if (rem == -1) {
                break;
            }

            taken[rem] = false;
            size--;
            for (int i = 0; i < n; i++) {
                if ((mask[i] & (~mask[rem])) != 0) {
                    deg[i]--;
                }
            }
        }
        long sum = 0;
        for (int i = 0; i < n; i++) {
            if (taken[i]) {
                sum += a[i];
            }
        }
        out.println(sum);
    }

    FastScanner in;
    PrintWriter out;

    void run() {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public boolean hasMoreTokens() {
            while (st == null || !st.hasMoreElements()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                    return false;
                }
                if (line == null) {
                    return false;
                }
                st = new StringTokenizer(line);
            }
            return true;
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

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public int[] nextIntArray(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }

        public long[] nextLongArray(int n) {
            long[] ret = new long[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextLong();
            }
            return ret;
        }
    }


    public static void main(String[] args) throws Exception {
        new B().run();
    }
}