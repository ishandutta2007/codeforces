import java.io.*;
import java.util.*;

public class D {

    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt(), m = in.nextInt();
        if (m == 1) {
            out.println(n);
            return;
        }
        int[] a = new int[n], b = new int[m];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        for (int i = 0; i < m; i++) {
            b[i] = in.nextInt();
        }
        a = transform(a);
        b = transform(b);

        n = a.length;
        m = b.length;

        int[] p = new int[m];
        for (int i = 1; i < m; i++) {
            int k = p[i - 1];
            while (k > 0 && b[k] != b[i]) {
                k = p[k - 1];
            }
            if (b[k] == b[i]) {
                k++;
            }
            p[i] = k;
        }
        
        int cur = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            while (cur > 0 && a[i] != b[cur]) {
                cur = p[cur - 1];
            }
            if (a[i] == b[cur]) {
                cur++;
            }
            if (cur == m) {
                ans++;
                cur = p[cur - 1];
            }
        }
        out.println(ans);
    }

    private int[] transform(int[] a) {
        int[] b = new int[a.length - 1];
        for (int i = 1; i < a.length; i++) {
            b[i - 1] = a[i] - a[i - 1];
        }
        return b;
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
        new D().run();
    }
}