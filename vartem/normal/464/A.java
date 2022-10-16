import java.io.*;
import java.util.*;

public class A {

    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt(), k = in.nextInt();
        char[] c = in.nextToken().toCharArray();
        char max = (char) ('a' + k - 1);

        for (int pos = n - 1; pos >= 0; pos--) {
            char[] d = c.clone();
            char cur = (char) (d[pos] + 1);
            while (cur <= max) {
                if (pos - 1 >= 0 && d[pos - 1] == cur) {
                    cur++;
                    continue;
                }
                if (pos - 2 >= 0 && d[pos - 2] == cur) {
                    cur++;
                    continue;
                }
                
                d[pos] = cur;
                boolean ok = true;
                for (int t = pos + 1; t < n; t++) {
                    cur = 'a';
                    while (cur <= max) {
                        if (t - 1 >= 0 && d[t - 1] == cur) {
                            cur++;
                            continue;
                        }
                        if (t - 2 >= 0 && d[t - 2] == cur) {
                            cur++;
                            continue;
                        }
                        break;
                    }

                    if (cur > max) {
                        ok = false;
                        break;
                    }
                    d[t] = cur;
                }
                
                if (ok) {
                    out.println(new String(d));
                    return;
                }
            }
        }
        out.println("NO");
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