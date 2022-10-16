import java.io.*;
import java.util.*;

public class C {

    FastScanner in;
    PrintWriter out;
    
    int MAX = 1200;

    void solve() {
        int n = in.nextInt(), t = in.nextInt(), r = in.nextInt();
        
        int[] w = new int[n];
        for (int i = 0; i < n; i++) {
            w[i] = in.nextInt() + 400;
        }
        
        int[] cnt = new int[MAX];
        boolean[] used=  new boolean[MAX];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            while (cnt[w[i]] < r) {
                int pos = w[i];
                while (used[pos]) {
                    pos--;
                }
                if (pos + t - 1 < w[i]) {
                    out.println("-1");
                    return;
                }
                ans++;
                used[pos] = true;
                for (int x = 0; x < t; x++) {
                    cnt[pos + x]++;
                }
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