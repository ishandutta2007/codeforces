import java.io.*;
import java.util.*;

public class B {

    FastScanner in;
    PrintWriter out;

    void solve() {
        char[] c = in.nextToken().toCharArray();
        int n = c.length;
        for (int swap = 0; swap < n - 1; swap++) {
            if (c[swap] % 2 == 0 && c[n - 1] > c[swap]) {
                char tmp = c[swap];
                c[swap] = c[n - 1];
                c[n - 1] = tmp;
                out.println(new String(c));
                return;
            }
        }
        
        for (int swap = n - 2; swap >= 0; swap--) {
            if (c[swap] % 2 == 0 && c[n - 1] < c[swap]) {
                char tmp = c[swap];
                c[swap] = c[n - 1];
                c[n - 1] = tmp;
                out.println(new String(c));
                return;
            }
        }
        
        out.println(-1);
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