import java.io.*;
import java.util.*;

public class B {

    public void solve() {
        int n = in.nextInt();
        int d = in.nextInt(), h = in.nextInt();
        if (2 * h < d) {
            out.println(-1);
            return;
        }
        if (d == 1) {
            if (n == 2) {
                out.println("1 2");
            } else {
                out.println(-1);
            }
            return;
        }
        int last = 1;
        for (int i = 0; i < h; i++) {
            out.println(last + " " + (last + 1));
            last++;
        }
        int prebottom = last-  1;

        for (int i = 0; i < d - h; i++) {
            if (i == 0) {
                out.println(1 + " " + (last + 1));
            } else {
                out.println(last + " " + (last + 1));
            }
            last++;
        }
        last++;
        while (last <= n) {
            out.println(prebottom + " " + last);
            last++;
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
        new B().run();
    }
}