import java.io.*;
import java.util.*;

public class A {

    public void solve() {
        int n = in.nextInt();
        int[] ans = new int[n];
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt() - 1;
        }

        int[] cnt = new int[n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(cnt, 0);
            int best = 0, max = 0;
            for (int j = i; j < n; j++) {
                cnt[a[j]]++;
                if (cnt[a[j]] > max || (cnt[a[j]] == max && a[j] < best)) {
                    best = a[j];
                    max = cnt[a[j]];
                }
                ans[best]++;
            }
        }
        for (int i = 0; i < n; i++) {
            out.print(ans[i] + " ");
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
        new A().run();
    }
}