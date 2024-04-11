import java.io.*;
import java.util.*;

public class E {

    public void solve() {
        int n = in.nextInt();
        int[] ans = new int[1 << 24];
        for (int i = 0; i < n; i++) {
            int mask=  0;
            for (char c : in.nextToken().toCharArray()) {
                mask |= 1 << (c - 'a');
            }
            ans[((1 << 24) - 1) ^ mask]++;
        }
        for (int len = 2; len <= 1 << 24; len *= 2) {
            for (int i = 0; i < 1 << 24; i += len) {
                for (int j = i, k = i + len / 2 ; k < i + len; j++, k++) {
                    ans[j] += ans[k];
                }
            }
        }
        int xor = 0;
        for (int i = 0; i < 1 << 24; i++) {
            xor ^= (n - ans[i]) * (n - ans[i]);
        }
        out.println(xor);
    }

    FastScanner in;
    PrintWriter out;

    public void run() {
        try {
            in = new FastScanner();
            out = new PrintWriter(System.out);
            solve();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastScanner(String name) {
            try {
                br = new BufferedReader(new FileReader(name));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextToken());
        }

        public long nextLong() {
            return Long.parseLong(nextToken());
        }

        public double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }

    public static void main(String[] args) {
        new E().run();
    }
}