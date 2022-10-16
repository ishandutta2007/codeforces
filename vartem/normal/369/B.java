import java.io.*;
import java.util.*;

public class B {

    public void solve() {
        int n = in.nextInt(), k = in.nextInt();
        in.nextInt();
        in.nextInt();
        int sAll = in.nextInt(), sk = in.nextInt();
        sAll -= sk;
        int[] ans = new int[n];

        for (int i = 0; i < k; i++) {
            int val = (sk * (i + 1) / k) - (sk * i / k);
            ans[k - i - 1] = val;
        }

        for (int i = 0; i < n - k; i++) {
            int val = (sAll * (i + 1) / (n - k)) - (sAll * i / (n - k));
            ans[n - i - 1] = val;
        }

        for (int i = 0; i < n; i++) {
            out.print((ans[i]) + " ");
        }
        out.println();  
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
        new B().run();
    }
}