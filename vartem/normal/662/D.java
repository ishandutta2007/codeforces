import java.io.*;
import java.util.*;

public class D {

    public void solve() {
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            String s = in.nextToken().substring(4);
            out.println(getAns(s));
        }
    }

    private long getAns(String s) {
        long cur = 1988;
        for (int j = s.length() - 1; j >= 0; j--) {
            long last = 0, pow = 1;
            for (int t = j; t < s.length(); t++) {
                last = last * 10 + s.charAt(t) - '0';
                pow *= 10;
            }

            if (cur % pow < last) {
                cur = (cur / pow) * pow + last;
            } else {
                cur = (cur / pow + 1) * pow + last;
            }
        }
        return cur;
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
        new D().run();
    }
}