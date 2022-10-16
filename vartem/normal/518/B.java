import java.io.*;
import java.util.*;

public class B {

    FastScanner in;
    PrintWriter out;

    void solve() {
        String s = in.nextToken(), t = in.nextToken();
        int[][] cnt = count(s), cnt2 = count(t);
        
        int ans1 = 0, ans2 = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 26; j++) {
                int can = Math.min(cnt[i][j], cnt2[i][j]);
                ans1 += can;
                cnt[i][j] -= can;
                cnt2[i][j] -= can;
            }
        }
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 26; j++) {
                int rmn = Math.min(cnt[i][j], cnt2[i ^ 1][j]);
                ans2 += rmn;
                cnt[i][j] -= rmn;
                cnt2[i ^ 1][j] -= rmn;
            }
        }
        
        out.println(ans1 + " " + ans2);
    }

    private int[][] count(String t) {
        int[][] cnt = new int[2][26];
        for (int i = 0; i < t.length(); i++) {
            char c = t.charAt(i);
            if (Character.isLowerCase(c)) {
                cnt[0][c - 'a']++;
            } else {
                cnt[1][c - 'A']++;
            }
        }
        return cnt;
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