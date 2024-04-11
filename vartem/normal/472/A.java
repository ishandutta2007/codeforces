import java.io.*;
import java.util.*;

public class A {

    FastScanner in;
    PrintWriter out;

    boolean[] prime;
    final int MAX = 2000000;

    void solve() {
        prime = new boolean[MAX];
        Arrays.fill(prime, true);

        for (int i = 2; i < MAX; i++) {
            if (prime[i]) {
                for (int j = 2 * i; j < MAX; j += i) {
                    prime[j] = false;
                }
            }
        }

        int n = in.nextInt();
        for (int i = 2;; i++) {
            int j = n - i;
            if (!prime[i] && !prime[j]) {
                out.println(i + " " + j);
                return;
            }
        }
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