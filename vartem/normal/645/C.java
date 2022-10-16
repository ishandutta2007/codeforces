import java.io.*;
import java.util.*;

public class C {

    public void solve() {
        int n = in.nextInt(), k = in.nextInt();
        char[] c = in.nextToken().toCharArray();

        int l = 0, r = n;
        int[] sum = new int[n];
        for (int i = 0; i < n; i++) {
            sum[i] = c[i] == '0' ? 1 : 0;
            if (i > 0) {
                sum[i] += sum[i - 1];
            }
        }
        while (l < r - 1) {
            int m = (l + r) >>> 1;

            boolean ok = false;
            for (int i = 0; i < n; i++) {
                if (c[i] == '1') {
                    continue;
                }
                int s = 0;
                int left = Math.max(0, i - m), right = Math.min(i + m, n - 1);
                s = sum[right];
                if (left > 0) {
                    s -= sum[left - 1];
                }
                if (s >= k + 1) {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                r = m;
            } else {
                l = m;
            }
        }
        out.println(r);
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