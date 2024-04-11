import java.io.*;
import java.util.*;

public class B {

    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt(), m = in.nextInt(), k = in.nextInt();
        int ans = 0;
        int[] a = new int[m + 1];
        for (int i = 0; i <= m; i++) {
            a[i] = in.nextInt();
        }
        
        for (int i = 0; i < m; i++) {
            int diff = Integer.bitCount(a[i] ^ a[m]);
            if (diff <= k) {
                ans++;
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
        new B().run();
    }
}