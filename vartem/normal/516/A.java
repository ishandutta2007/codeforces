import java.io.*;
import java.util.*;

public class A {

    FastScanner in;
    PrintWriter out;

    String best = "";

    void solve() {
        int n = in.nextInt();
        String s = in.nextToken();
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int k = s.charAt(i) - '0';
            if (k == 2 || k == 3 || k == 5 || k == 7) {
                ans.add(k);
            } else if (k == 4) {
                ans.add(2);
                ans.add(2);
                ans.add(3);
            } else if (k == 6) {
                ans.add(5);
                ans.add(3);
            } else if (k == 8) {
                ans.add(7);
                ans.add(2);
                ans.add(2);
                ans.add(2);
            } else if (k == 9) {
                ans.add(7);
                ans.add(3);
                ans.add(3);
                ans.add(2);
            }
        }
        Collections.sort(ans);
        Collections.reverse(ans);
        for (int i : ans) {
            out.print(i);
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
        new A().run();
    }
}