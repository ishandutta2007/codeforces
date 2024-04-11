import java.io.*;
import java.util.*;

public class B {

    FastScanner in;
    PrintWriter out;

    void solve() {
        long n = in.nextInt(), a = in.nextInt(), b = in.nextInt();
        long best = Long.MAX_VALUE;
        long bestA = -1, bestB = -1;

        for (long newA = a;; newA++) {
            long needB = (6 * n + newA - 1) / newA;
            if (newA * Math.max(b, needB) < best) {
                best = newA * Math.max(b, needB);
                bestA = newA;
                bestB = Math.max(b, needB);
            }
            if (newA > needB) {
                break;
            }
        }

        for (long newB = b;; newB++) {
            long needA = (6 * n + newB - 1) / newB;
            if (newB * Math.max(a, needA) < best) {
                best = newB * Math.max(a, needA);
                bestA = Math.max(a, needA);
                bestB = newB;
            }
            if (newB > needA) {
                break;
            }
        }

        out.println(best);
        out.println(bestA + " " + bestB);
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
        new B().run();
    }
}