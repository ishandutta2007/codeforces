import java.io.*;
import java.util.*;

public class C {

    FastScanner in;
    PrintWriter out;

    void solve() {
         int n = in.nextInt(), m = in.nextInt(), k = in.nextInt();
         int[] a = new int[n];
         int[] pos = new int[n];
         for (int i = 0; i < n; i++) {
             a[i] = in.nextInt() - 1;
             pos[a[i]] = i;
         }
         
         long ans = 0;
         for (int i = 0; i < m; i++) {
             int cur = in.nextInt() - 1;
             int p = pos[cur];
             ans += p / k + 1;
             
             if (pos[cur] > 0) {
                 int prev = a[p - 1];
                 a[p] = prev;
                 a[p - 1] = cur;
                 pos[prev] = p;
                 pos[cur] = p - 1;
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