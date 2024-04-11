import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class C2 {

    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        if (n == 1) {
            out.println("YES");
            out.println(1);
            return;
        }
        if (n == 4) {
            out.println("YES");
            out.println(1);
            out.println(3);
            out.println(2);
            out.println(4);
            return;
        }
        
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                out.println("NO");
                return;
            }
        }
        int[] p = new int[n];
        
        p[0] = 1;
        for (int i = 1; i < n - 1; i++) {
            int d1 = BigInteger.valueOf(i).modInverse(BigInteger.valueOf(n)).intValue();
            p[i] = (int) ((1L * d1 * (i + 1)) % n);
        }
        p[n - 1] = n;
        
        out.println("YES");
        for (int i = 0; i < n; i++) {
            out.println(p[i]);
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
        new C2().run();
    }
}