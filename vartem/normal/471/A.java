import java.io.*;
import java.util.*;

public class A {

    FastScanner in;
    PrintWriter out;

    void solve() {
        int[] a = new int[6];
        for (int i = 0; i < 6; i++) {
            a[i] = in.nextInt();
        }
        Arrays.sort(a);

        for (int i = 0; i < 3; i++) {
            boolean ok = true;
            for (int j = 0; j < 4; j++) {
                ok &= a[i] == a[i + j];
            }
            if (!ok) {
                continue;
            }

            if (i == 0 && a[4] == a[5] || i == 2 && a[0] == a[1]) {
                out.println("Elephant");
            } else {
                out.println("Bear");
            }
            return;
        }
        out.println("Alien");
    }

    void run() {
        in = new FastScanner();
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastScanner(String s) {
            try {
                br = new BufferedReader(new FileReader(s));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
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