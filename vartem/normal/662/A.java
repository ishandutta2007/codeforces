import java.io.*;
import java.util.*;

public class A {

    public void solve() {
        int n = in.nextInt();
        long x = 0;
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            long fst = in.nextLong(), snd = in.nextLong();
            x ^= fst;
            a[i] = fst ^ snd;
        }

        int last = 0;
        for (int bit = 60; bit >= 0; bit--) {
            int pos = -1;
            for (int i = last; i < n; i++) {
                if ((a[i] & (1L << bit)) != 0) {
                    pos = i;
                    break;
                }
            }
            if (pos == -1) {
                continue;
            }

            long tmp = a[last];
            a[last] = a[pos];
            a[pos] = tmp;

            for (int j = 0; j < n; j++) {
                if (j == last) {
                    continue;
                }
                if ((a[j] & (1L << bit)) != 0) {
                    a[j] ^= a[last];
                }
            }
            last++;
        }

        for (int i = 0; i < n; i++) {
            x = Math.min(x, x^a[i]);
        }

        if (x != 0) {
            out.println("1/1");
        } else {
            out.println(((1L << last) - 1) + "/" + (1L << last));
        }
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
        new A().run();
    }
}