import java.io.*;
import java.util.*;

public class C {

    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        long[] a = new long[n + 1];
        for (int i = 1; i <= n; i++) {
            a[i] = in.nextLong();
            a[i] += a[i - 1];
        }
        
        
        long sum = a[n];
        if (sum % 3 != 0) {
            out.println(0);
            return;
        }
        
        sum /= 3;
        long ans = 0;
        long count = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] == 2 * sum) {
                ans += count;
            }
            if (a[i] == sum) {
                count++;
            }
        }
        out.println(ans);
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
        new C().run();
    }
}