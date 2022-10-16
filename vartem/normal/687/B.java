import java.io.*;
import java.util.*;

public class B {

    public void solve() {
        int n = in.nextInt(), k = in.nextInt();
        boolean[] have = new boolean[1_000_001];
        for (int i = 0; i < n; i++) {
            have[in.nextInt()] = true;
        }

        for (int i = 2; 1L * i * i <= k; i++) {
            if (k % i == 0) {
                int val = 1;
                while (k % i == 0) {
                    k /= i;
                    val *= i;
                }
                boolean ok = false;
                for (int j = val; j < have.length; j += val) {
                    ok |= have[j];
                }
                if (!ok) {
                    out.println("No");
                    return;
                }
            }
        }

        if (k > 1) {
            int i = k;
            int val = 1;
            while (k % i == 0) {
                k /= i;
                val *= i;
            }
            boolean ok = false;
            for (int j = val; j < have.length; j += val) {
                ok |= have[j];
            }
            if (!ok) {
                out.println("No");
                return;
            }
        }

        out.println("Yes");
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