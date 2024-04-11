import java.io.*;
import java.util.*;

public class C {

    public void solve() {
        int n = in.nextInt();
        long k = in.nextInt();
        long[] a = new long[n + 1];
        for (int i = 0; i <= n; i++) {
            a[i] = in.nextLong();
        }

        long cur = 0;
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            cur += a[i];
            if (cur % 2 != 0 || i == n) {
                long tmp = 0;
                for (int j = n; j >= i; j--) {
                    tmp = tmp * 2 + a[j];
                    if (Math.abs(tmp) > 1e15) {
                        break;
                    }
                }
                if (Math.abs(tmp) > 1e15) {
                    break;
                }
                cur += tmp - a[i];
                for (int j = i; j >= 0; j--) {
//                    System.err.println(cur + " " + a[j]);
                    if (Math.abs(cur) > 1e15) {
                        break;
                    }
                    if (Math.abs(a[j] - cur) <= k && cur != 0) {
                        if (a[j] == cur && j == n) {

                        } else {
                            ans++;
                        }
                    }
                    cur *= 2;
                }
                break;
            } else {
                cur /= 2;
            }
        }
        out.println(ans);
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
        new C().run();
    }
}