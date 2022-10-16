import java.io.*;
import java.util.*;

public class Test {

    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        Set<String> have = new HashSet<>();
        for (int i = 0; i < n; i++) {
            String cur = in.nextToken();
            for (int l = 0; l < cur.length(); l++) {
                for (int r = l; r < cur.length(); r++) {
                    have.add(cur.substring(l, r + 1));
                }
            }
        }

        for (char a = 'a'; a <= 'z'; a++) {
            String s = "" + a;
            if (!have.contains(s)) {
                out.println(s);
                return;
            }
        }

        for (char a = 'a'; a <= 'z'; a++) {
            for (char b = 'a'; b <= 'z'; b++) {
                String s = "" + a + b;
                if (!have.contains(s)) {
                    out.println(s);
                    return;
                }
            }
        }

        for (char a = 'a'; a <= 'z'; a++) {
            for (char b = 'a'; b <= 'z'; b++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    String s = "" + a + b + c;
                    if (!have.contains(s)) {
                        out.println(s);
                        return;
                    }
                }
            }
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

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    // TODO Auto-generated catch block
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
        new Test().run();
    }
}